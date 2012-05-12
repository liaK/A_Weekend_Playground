#include "statusdialog.h"
#include <QLabel>
#include <QProgressBar>
#include <QPushButton>
#include <QNetworkReply>
#include <QHBoxLayout>
#include <QTableWidget>
#include <QMessageBox>

CStatusDialog::CStatusDialog(QWidget *parent) :
    QDialog(parent),m_NetworkReply(0),m_ReadBytes(0)
{
    m_DialogLayout = new QGridLayout(this);
//    m_DownloadProgressTableWidget = new QTableWidget(0,1);
}

void CStatusDialog::addDownloadStatus(QNetworkReply *currentNetworkReply)
{
    m_NetworkReply = currentNetworkReply;

    m_ProgressBarLabel = new QLabel(currentNetworkReply->url().path());
    m_ProgressBar = new QProgressBar();
    m_ProgressBar->setMinimum(0);
    m_PauseResumePushButton = new QPushButton("Pause");
    m_StopDownloadPushButton = new QPushButton("Stop");

    m_ProgressBarHBoxLayout = new QHBoxLayout();
    m_ProgressBarHBoxLayout->addWidget(m_ProgressBarLabel);
    m_ProgressBarHBoxLayout->addWidget(m_ProgressBar);
    m_ProgressBarHBoxLayout->addWidget(m_PauseResumePushButton);
    m_ProgressBarHBoxLayout->addWidget(m_StopDownloadPushButton);

//    m_DownloadProgressTableWidget->insertRow(m_DownloadIndex);
//    m_DownloadProgressTableWidget->setCellWidget(m_DownloadIndex,1,);

    m_DialogLayout->addLayout(m_ProgressBarHBoxLayout,0,0,1,1);
    QObject::connect(currentNetworkReply,SIGNAL(downloadProgress(qint64,qint64)),this,SLOT(updateStatus(qint64,qint64)));
    QObject::connect(m_PauseResumePushButton,SIGNAL(clicked()),this,SLOT(onPauseDownload()));
    QObject::connect(m_StopDownloadPushButton,SIGNAL(clicked()),this,SLOT(onStopDownload()));
}

void CStatusDialog::updateStatus(qint64 readBytes, qint64 totalBytes)
{
    m_ProgressBar->setMaximum(m_ReadBytes + totalBytes);
    m_ProgressBar->setValue(m_ReadBytes + readBytes);
}

void CStatusDialog::onPauseDownload()
{
    if(m_PauseResumePushButton->text() == "Pause")
    {
        m_PauseResumePushButton->setText("Resume");
        emit pauseDownload(m_NetworkReply);
    }
    else
    {
        m_PauseResumePushButton->setText("Pause");
        emit resumeDownload(m_NetworkReply);
    }
}

void CStatusDialog::onStopDownload()
{
    emit stopDownload(m_NetworkReply);
}

void CStatusDialog::setNetworkReply(QNetworkReply *resumedNetworkReply)
{
    delete m_NetworkReply;
    m_NetworkReply = resumedNetworkReply;
    QObject::connect(m_NetworkReply,SIGNAL(downloadProgress(qint64,qint64)),this,SLOT(updateStatus(qint64,qint64)));
}

void CStatusDialog::setReadBytes(int readBytes)
{
    m_ReadBytes = readBytes;
}

CStatusDialog::~CStatusDialog()
{
    delete m_NetworkReply;
}

