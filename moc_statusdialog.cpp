/****************************************************************************
** Meta object code from reading C++ file 'statusdialog.h'
**
** Created: Wed May 9 19:34:52 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "statusdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'statusdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CStatusDialog[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      34,   15,   14,   14, 0x05,
      84,   64,   14,   14, 0x05,
     135,  115,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
     185,  164,   14,   14, 0x0a,
     213,   14,   14,   14, 0x0a,
     231,   14,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CStatusDialog[] = {
    "CStatusDialog\0\0downloadToBePaused\0"
    "pauseDownload(QNetworkReply*)\0"
    "downloadToBeResumed\0resumeDownload(QNetworkReply*)\0"
    "downloadToBeStopped\0stopDownload(QNetworkReply*)\0"
    "readBytes,totalBytes\0updateStatus(qint64,qint64)\0"
    "onPauseDownload()\0onStopDownload()\0"
};

const QMetaObject CStatusDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CStatusDialog,
      qt_meta_data_CStatusDialog, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CStatusDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CStatusDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CStatusDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CStatusDialog))
        return static_cast<void*>(const_cast< CStatusDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int CStatusDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: pauseDownload((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 1: resumeDownload((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 2: stopDownload((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 3: updateStatus((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 4: onPauseDownload(); break;
        case 5: onStopDownload(); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void CStatusDialog::pauseDownload(QNetworkReply * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CStatusDialog::resumeDownload(QNetworkReply * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CStatusDialog::stopDownload(QNetworkReply * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
