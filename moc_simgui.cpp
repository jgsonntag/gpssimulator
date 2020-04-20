/****************************************************************************
** Simgui meta object code from reading C++ file 'simgui.h'
**
** Created: Fri Oct 4 11:43:56 2013
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "simgui.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *Simgui::className() const
{
    return "Simgui";
}

QMetaObject *Simgui::metaObj = 0;
static QMetaObjectCleanUp cleanUp_Simgui( "Simgui", &Simgui::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString Simgui::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "Simgui", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString Simgui::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "Simgui", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* Simgui::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QVBox::staticMetaObject();
    static const QUMethod slot_0 = {"about", 0, 0 };
    static const QUMethod slot_1 = {"update", 0, 0 };
    static const QUParameter param_slot_2[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_2 = {"intervalChanged", 1, param_slot_2 };
    static const QMetaData slot_tbl[] = {
	{ "about()", &slot_0, QMetaData::Private },
	{ "update()", &slot_1, QMetaData::Private },
	{ "intervalChanged(int)", &slot_2, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"Simgui", parentObject,
	slot_tbl, 3,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_Simgui.setMetaObject( metaObj );
    return metaObj;
}

void* Simgui::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "Simgui" ) )
	return this;
    return QVBox::qt_cast( clname );
}

bool Simgui::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: about(); break;
    case 1: update(); break;
    case 2: intervalChanged((int)static_QUType_int.get(_o+1)); break;
    default:
	return QVBox::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool Simgui::qt_emit( int _id, QUObject* _o )
{
    return QVBox::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool Simgui::qt_property( int id, int f, QVariant* v)
{
    return QVBox::qt_property( id, f, v);
}

bool Simgui::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
