/*
 * This file was generated by qdbusxml2cpp version 0.7
 * Command line was: qdbusxml2cpp -N -m -i generic-types.h -p nm-device-bondinterface /space/kde/src/git/extragear/libs/libnm-qt/dbus/introspection/nm-device-bond.xml
 *
 * qdbusxml2cpp is Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies).
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#ifndef NM-DEVICE-BONDINTERFACE_H
#define NM-DEVICE-BONDINTERFACE_H

#include <QtCore/QObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include <QtDBus/QtDBus>
#include "generic-types.h"

/*
 * Proxy class for interface org.freedesktop.NetworkManager.Device.Bond
 */
class OrgFreedesktopNetworkManagerDeviceBondInterface: public QDBusAbstractInterface
{
    Q_OBJECT
public:
    static inline const char *staticInterfaceName()
    { return "org.freedesktop.NetworkManager.Device.Bond"; }

public:
    OrgFreedesktopNetworkManagerDeviceBondInterface(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent = 0);

    ~OrgFreedesktopNetworkManagerDeviceBondInterface();

    Q_PROPERTY(bool Carrier READ carrier)
    inline bool carrier() const
    { return qvariant_cast< bool >(property("Carrier")); }

    Q_PROPERTY(QString HwAddress READ hwAddress)
    inline QString hwAddress() const
    { return qvariant_cast< QString >(property("HwAddress")); }

    Q_PROPERTY(QList<QDBusObjectPath> Slaves READ slaves)
    inline QList<QDBusObjectPath> slaves() const
    { return qvariant_cast< QList<QDBusObjectPath> >(property("Slaves")); }

public Q_SLOTS: // METHODS
Q_SIGNALS: // SIGNALS
    void PropertiesChanged(const QVariantMap &properties);
};

#endif
