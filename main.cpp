#include <QtGui/QApplication>
#include "downloaddialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CDownloadDialog w;
    w.show();
    
    return a.exec();
}
