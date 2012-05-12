#ifndef DOWNLOADDIALOG_H
#define DOWNLOADDIALOG_H

#include <QtGui/QDialog>
#include <QNetworkReply>
#include "statusdialog.h"

class QLineEdit;
class QHBoxLayout;
class QGridLayout;
class QLabel;
class QPushButton;
class QNetworkAccessManager;

class QProgressBar;
class QTableWidget;
class CStatusDialog;

class CDownloadDialog : public QDialog
{
    Q_OBJECT
    
public:
    CDownloadDialog(QWidget *parent = 0);
    ~CDownloadDialog();
    void initUI();
    void setConnections();

public slots:

    void startDownload();
    void processReply(QNetworkReply *downloadReply);
    void pauseDownload(QNetworkReply *currentNetworkReply);
    void resumeDownload(QNetworkReply *networkReply);
    void stopDownload(QNetworkReply *currentNetworkReply);

private:

    /// This will get the File name alone (with the path info stripped) from the QNetworkReply
    QString fileNameFromReply(QNetworkReply *networkReply);
    QString fileNameFromURL(QUrl url);

    QLabel *m_URLLabel;
    QLineEdit *m_URLLineEdit;
    QHBoxLayout *m_URLHBoxLayout;

    QPushButton *m_StartDownloadPushButton;

    QGridLayout *m_DialogLayout;

    QNetworkAccessManager *m_NetAccessManager;
    QString m_DownloadDirectory;
    int m_DownloadIndex; /// Indicates the Index of the Download operation

    QTableWidget *m_DownloadStatusTableWidget;

    QMap<QNetworkReply*,CStatusDialog*> m_NetworkReplyStatusDialogMap; /// Network reply (@ the time of get) and its CStatusDialog

};

#endif // DOWNLOADDIALOG_H
