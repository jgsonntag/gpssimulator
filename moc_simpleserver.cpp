/****************************************************************************
** SimpleServer meta object code from reading C++ file 'simpleserver.h'
**
** Created: Fri Oct 4 11:43:56 2013
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "simpleserver.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *SimpleServer::className() const
{
    return "SimpleServer";
}

QMetaObject *SimpleServer::metaObj = 0;
static QMetaObjectCleanUp cleanUp_SimpleServer( "SimpleServer", &SimpleServer::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString SimpleServer::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "SimpleServer", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString SimpleServer::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "SimpleServer", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* SimpleServer::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QServerSocket::staticMetaObject();
    static const QUMethod slot_0 = {"slotDisConnect", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "slotDisConnect()", &slot_0, QMetaData::Private }
    };
    static const QUMethod signal_0 = {"newConnect", 0, 0 };
    static const QUParameter param_signal_1[] = {
	{ "text", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_1 = {"sendToClient", 1, param_signal_1 };
    static const QUMethod signal_2 = {"disConnect", 0, 0 };
    static const QMetaData signal_tbl[] = {
	{ "newConnect()", &signal_0, QMetaData::Public },
	{ "sendToClient(QString)", &signal_1, QMetaData::Public },
	{ "disConnect()", &signal_2, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"SimpleServer", parentObject,
	slot_tbl, 1,
	signal_tbl, 3,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_SimpleServer.setMetaObject( metaObj );
    return metaObj;
}

void* SimpleServer::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "SimpleServer" ) )
	return this;
    return QServerSocket::qt_cast( clname );
}

// SIGNAL newConnect
void SimpleServer::newConnect()
{
    activate_signal( staticMetaObject()->signalOffset() + 0 );
}

// SIGNAL sendToClient
void SimpleServer::sendToClient( QString t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 1, t0 );
}

// SIGNAL disConnect
void SimpleServer::disConnect()
{
    activate_signal( staticMetaObject()->signalOffset() + 2 );
}

bool SimpleServer::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: slotDisConnect(); break;
    default:
	return QServerSocket::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool SimpleServer::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: newConnect(); break;
    case 1: sendToClient((QString)static_QUType_QString.get(_o+1)); break;
    case 2: disConnect(); break;
    default:
	return QServerSocket::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool SimpleServer::qt_property( int id, int f, QVariant* v)
{
    return QServerSocket::qt_property( id, f, v);
}

bool SimpleServer::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
