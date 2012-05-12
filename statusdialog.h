#ifndef STATUSDIALOG_H
#define STATUSDIALOG_H

#include <QDialog>
class QLabel;
class QProgressBar;
class QPushButton;
class QPushButton;
class QHBoxLayout;
class QNetworkReply;
class QGridLayout;
class QTableWidget;

class CStatusDialog : public QDialog
{
    Q_OBJECT
public:
    explicit CStatusDialog(QWidget *parent = 0);
    ~CStatusDialog();
    void addDownloadStatus(QNetworkReply *currentNetworkReply);
    void setNetworkReply(QNetworkReply *resumedNetworkReply);

    /// will be used while pausing and resuming where readBytes is the already downloaded bytes.
    void setReadBytes(int readBytes);

signals:
    
    void pauseDownload(QNetworkReply *downloadToBePaused);
    void resumeDownload(QNetworkReply *downloadToBeResumed);
    void stopDownload(QNetworkReply *downloadToBeStopped);

public slots:
    
    void updateStatus(qint64 readBytes,qint64 totalBytes);

    /// Will send the appropriate Network Reply in the pauseDownload(QNetworkReply*) signal.
    void onPauseDownload();
    void onStopDownload();

private:

    QLabel *m_ProgressBarLabel;
    QProgressBar *m_ProgressBar;
    QHBoxLayout *m_ProgressBarHBoxLayout;

    QPushButton *m_PauseResumePushButton;
    QPushButton *m_StopDownloadPushButton;
    QHBoxLayout *m_PauseStopButtonsHBoxLayout;

    QGridLayout *m_DialogLayout;

    QNetworkReply *m_NetworkReply;

    int m_ReadBytes;
};

#endif // STATUSDIALOG_H
