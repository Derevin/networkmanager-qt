/*
 * This file was generated by qdbusxml2cpp version 0.7
 * Command line was: qdbusxml2cpp -N -m -i generic-types.h -p nm-device-adslinterface /home/jgrulich/projects/libnm-qt/dbus/introspection/nm-device-adsl.xml
 *
 * qdbusxml2cpp is Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies).
 *
 * This is an auto-generated file.
 * This file may have been hand-edited. Look for HAND-EDIT comments
 * before re-generating it.
 */

#include "nm-device-adslinterface.h"

/*
 * Implementation of interface class OrgFreedesktopNetworkManagerDeviceAdslInterface
 */

OrgFreedesktopNetworkManagerDeviceAdslInterface::OrgFreedesktopNetworkManagerDeviceAdslInterface(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent)
    : QDBusAbstractInterface(service, path, staticInterfaceName(), connection, parent)
{
}

OrgFreedesktopNetworkManagerDeviceAdslInterface::~OrgFreedesktopNetworkManagerDeviceAdslInterface()
{
}


#include "nm-device-adslinterface.moc"
