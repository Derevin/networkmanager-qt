/*
 * This file was generated by qdbusxml2cpp version 0.7
 * Command line was: qdbusxml2cpp -N -m -i generic-types.h -p nm-vpn-connectioninterface /space/kde/src/git/extragear/libs/libnm-qt/dbus/introspection/nm-vpn-connection.xml
 *
 * qdbusxml2cpp is Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies).
 *
 * This is an auto-generated file.
 * This file may have been hand-edited. Look for HAND-EDIT comments
 * before re-generating it.
 */

#include "nm-vpn-connectioninterface.h"

/*
 * Implementation of interface class OrgFreedesktopNetworkManagerVPNConnectionInterface
 */

OrgFreedesktopNetworkManagerVPNConnectionInterface::OrgFreedesktopNetworkManagerVPNConnectionInterface(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent)
    : QDBusAbstractInterface(service, path, staticInterfaceName(), connection, parent)
{
}

OrgFreedesktopNetworkManagerVPNConnectionInterface::~OrgFreedesktopNetworkManagerVPNConnectionInterface()
{
}


#include "nm-vpn-connectioninterface.moc"
