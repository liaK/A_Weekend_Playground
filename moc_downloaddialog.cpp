/****************************************************************************
** Meta object code from reading C++ file 'downloaddialog.h'
**
** Created: Wed May 9 19:34:51 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "downloaddialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'downloaddialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CDownloadDialog[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x0a,
      47,   33,   16,   16, 0x0a,
      96,   76,   16,   16, 0x0a,
     139,  126,   16,   16, 0x0a,
     170,   76,   16,   16, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CDownloadDialog[] = {
    "CDownloadDialog\0\0startDownload()\0"
    "downloadReply\0processReply(QNetworkReply*)\0"
    "currentNetworkReply\0pauseDownload(QNetworkReply*)\0"
    "networkReply\0resumeDownload(QNetworkReply*)\0"
    "stopDownload(QNetworkReply*)\0"
};

const QMetaObject CDownloadDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CDownloadDialog,
      qt_meta_data_CDownloadDialog, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CDownloadDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CDownloadDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CDownloadDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CDownloadDialog))
        return static_cast<void*>(const_cast< CDownloadDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int CDownloadDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: startDownload(); break;
        case 1: processReply((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 2: pauseDownload((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 3: resumeDownload((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 4: stopDownload((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
