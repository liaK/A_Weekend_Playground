#include "downloaddialog.h"
#include <QHBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QGridLayout>
#include <QPushButton>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QMessageBox>
#include <QDebug>
#include <QFile>
#include <QTableWidget>

#include "statusdialog.h"

CDownloadDialog::CDownloadDialog(QWidget *parent)
    : QDialog(parent),m_NetAccessManager(0),m_DownloadDirectory("/home/yudhi/kali/Qt_Works/TempDir"),m_DownloadIndex(-1)
{
    initUI();
    setConnections();
}

void CDownloadDialog::initUI()
{
    m_URLLabel = new QLabel("Enter the URL here :");
    m_URLLineEdit = new QLineEdit();
    m_URLHBoxLayout = new QHBoxLayout();
    m_URLHBoxLayout->addWidget(m_URLLabel);
    m_URLHBoxLayout->addWidget(m_URLLineEdit);

    m_StartDownloadPushButton = new QPushButton("Start Download");

    m_DownloadStatusTableWidget = new QTableWidget(0,1);
    m_DownloadStatusTableWidget->resizeRowsToContents();
    m_DownloadStatusTableWidget->setColumnWidth(0,570);

    m_DialogLayout = new QGridLayout(this);
    m_DialogLayout->addLayout(m_URLHBoxLayout,0,0,1,1);
    m_DialogLayout->addWidget(m_StartDownloadPushButton,1,0,1,1,Qt::AlignCenter);
    m_DialogLayout->addWidget(m_DownloadStatusTableWidget,3,0);

    setFixedWidth(600);
}

void CDownloadDialog::setConnections()
{
    QObject::connect(m_StartDownloadPushButton,SIGNAL(clicked()),this,SLOT(startDownload()));
}

void CDownloadDialog::startDownload()
{
    /// Sanity Check
    QString enteredURL = m_URLLineEdit->text();
    if((!enteredURL.contains("http://")))
    {
        QMessageBox::critical(this,"Download Error","Invalid URL.",QMessageBox::Ok);
        return;
    }

    QString fileName = fileNameFromURL(QUrl(enteredURL));
    if(QFile::exists(m_DownloadDirectory+fileName))
    {
        QFile::remove(m_DownloadDirectory+fileName);
    }

    if(!m_NetAccessManager)
    {
        m_NetAccessManager = new QNetworkAccessManager(this);
        QObject::connect(m_NetAccessManager,SIGNAL(finished(QNetworkReply*)),SLOT(processReply(QNetworkReply*)));
    }

    QNetworkReply *currentNetworkReply = m_NetAccessManager->get(QNetworkRequest(QUrl(enteredURL)));
    CStatusDialog *downloadStatusDialog = new CStatusDialog(this);

    m_NetworkReplyStatusDialogMap.insert(currentNetworkReply,downloadStatusDialog);

    ++m_DownloadIndex;
    downloadStatusDialog->addDownloadStatus(currentNetworkReply);
    m_DownloadStatusTableWidget->insertRow(m_DownloadIndex);
    m_DownloadStatusTableWidget->setCellWidget(m_DownloadIndex,0,downloadStatusDialog);
    m_DownloadStatusTableWidget->setRowHeight(m_DownloadIndex, 50);

    QObject::connect(downloadStatusDialog,SIGNAL(pauseDownload(QNetworkReply*)),this,SLOT(pauseDownload(QNetworkReply*)));
    QObject::connect(downloadStatusDialog,SIGNAL(resumeDownload(QNetworkReply*)),this,SLOT(resumeDownload(QNetworkReply*)));
    QObject::connect(downloadStatusDialog,SIGNAL(stopDownload(QNetworkReply*)),this,SLOT(stopDownload(QNetworkReply*)));
}

void CDownloadDialog::processReply(QNetworkReply *downloadReply)
{
    if(downloadReply->error() == QNetworkReply::NoError)
    {
        QString allContents = downloadReply->readAll();
        QString fileName = fileNameFromReply(downloadReply);

        QFile downloadedFile(m_DownloadDirectory+fileName);
        if(downloadedFile.open(QIODevice::Append))
        {
            downloadedFile.write(allContents.toAscii().data());
        }
        downloadedFile.close();
        QMessageBox::information(this,"Download Completed",fileName + " has been downloaded.",QMessageBox::Ok);
    }
    else
    {
        qDebug()<<"The Error occured in downloading is - "<<downloadReply->error();
    }
}

void CDownloadDialog::pauseDownload(QNetworkReply *currentNetworkReply)
{
    QString allContents = currentNetworkReply->readAll();
    currentNetworkReply->close();

    QString fileName = fileNameFromReply(currentNetworkReply);
    QFile downloadedFile(m_DownloadDirectory+fileName);
    if(downloadedFile.open(QIODevice::WriteOnly))
    {
        downloadedFile.write(allContents.toAscii().data());
    }
    downloadedFile.close();

}

QString CDownloadDialog::fileNameFromReply(QNetworkReply *networkReply)
{
//    QString urlFileName = networkReply->url().path();
//    int urlFileNameIndex = urlFileName.lastIndexOf("/");
//    int urlFileChars = urlFileName.count();

    /// To get just the file name alone from the entire URL.
     return fileNameFromURL(networkReply->url());

}

QString CDownloadDialog::fileNameFromURL(QUrl url)
{
    QString urlFileName = url.path();
    int urlFileNameIndex = urlFileName.lastIndexOf("/");
    int urlFileChars = urlFileName.count();

    /// To get just the file name alone from the entire URL.
     return urlFileName.mid(urlFileNameIndex,(urlFileChars-urlFileNameIndex));

}

void CDownloadDialog::resumeDownload(QNetworkReply *networkReply)
{
    QString pausedFileName = fileNameFromReply(networkReply);
    QFile pausedFile(m_DownloadDirectory + pausedFileName);
    int bytesDownloadedBefore =  pausedFile.size();

    QNetworkRequest lResumeRequest(networkReply->url());
    QByteArray httpHeaderByteArray = "bytes=" + QByteArray::number(bytesDownloadedBefore) + "-";
    lResumeRequest.setRawHeader("Range",httpHeaderByteArray);

    CStatusDialog *pausedStatusDialog = m_NetworkReplyStatusDialogMap.value(networkReply);
    QNetworkReply *newNetworkReply = m_NetAccessManager->get(lResumeRequest);
    pausedStatusDialog->setReadBytes(bytesDownloadedBefore);
    pausedStatusDialog->setNetworkReply(newNetworkReply);
}

void CDownloadDialog::stopDownload(QNetworkReply *currentNetworkReply)
{
    QString fileName = fileNameFromReply(currentNetworkReply).remove("/");
    currentNetworkReply->close();
    QMessageBox::warning(this,"Download Stopped",fileName + " stopped from downloading.",QMessageBox::Ok);
}

CDownloadDialog::~CDownloadDialog()
{
    
}
