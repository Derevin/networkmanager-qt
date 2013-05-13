/*
 * This file was generated by qdbusxml2cpp version 0.7
 * Command line was: qdbusxml2cpp -N -m -i generic-types.h -p nm-wimax-nspinterface /space/kde/src/git/extragear/libs/libnm-qt/dbus/introspection/nm-wimax-nsp.xml
 *
 * qdbusxml2cpp is Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies).
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#ifndef NM-WIMAX-NSPINTERFACE_H
#define NM-WIMAX-NSPINTERFACE_H

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
 * Proxy class for interface org.freedesktop.NetworkManager.WiMax.Nsp
 */
class OrgFreedesktopNetworkManagerWiMaxNspInterface: public QDBusAbstractInterface
{
    Q_OBJECT
public:
    static inline const char *staticInterfaceName()
    { return "org.freedesktop.NetworkManager.WiMax.Nsp"; }

public:
    OrgFreedesktopNetworkManagerWiMaxNspInterface(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent = 0);

    ~OrgFreedesktopNetworkManagerWiMaxNspInterface();

    Q_PROPERTY(QString Name READ name)
    inline QString name() const
    { return qvariant_cast< QString >(property("Name")); }

    Q_PROPERTY(uint NetworkType READ networkType)
    inline uint networkType() const
    { return qvariant_cast< uint >(property("NetworkType")); }

    Q_PROPERTY(uint SignalQuality READ signalQuality)
    inline uint signalQuality() const
    { return qvariant_cast< uint >(property("SignalQuality")); }

public Q_SLOTS: // METHODS
Q_SIGNALS: // SIGNALS
    void PropertiesChanged(const QVariantMap &properties);
};

#endif
