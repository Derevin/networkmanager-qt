/*
    Copyright 2008,2010 Will Stephenson <wstephenson@kde.org>
    Copyright 2013 Jan Grulich <jgrulich@redhat.com>

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) version 3, or any
    later version accepted by the membership of KDE e.V. (or its
    successor approved by the membership of KDE e.V.), which shall
    act as a proxy defined in Section 6 of version 3 of the license.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef NETWORKMANAGERQT_NETWORKMANAGER_P_H
#define NETWORKMANAGERQT_NETWORKMANAGER_P_H

#include <QDBusServiceWatcher>
#include <QMap>

#include "dbus/nm-managerinterface.h"
#include "device.h"
#include "activeconnection.h"

#include "manager.h"

namespace NetworkManager
{

class Device;
class ActiveConnection;

class NetworkManagerPrivate : public NetworkManager::Notifier
{
    Q_OBJECT
public:
    static const QString DBUS_SERVICE;
    static const QString DBUS_DAEMON_PATH;
    static const QString DBUS_SETTINGS_PATH;
    static const QString FDO_DBUS_PROPERTIES;

    NetworkManagerPrivate();
    ~NetworkManagerPrivate();
    QDBusServiceWatcher watcher;
    OrgFreedesktopNetworkManagerInterface iface;
    NetworkManager::Status nmState;
    Connectivity m_connectivity;
    bool m_isNetworkingEnabled;
#if !NM_CHECK_VERSION(1, 2, 0)
    bool m_isWimaxEnabled;
    bool m_isWimaxHardwareEnabled;
#endif
    bool m_isWirelessEnabled;
    bool m_isWirelessHardwareEnabled;
    bool m_isWwanEnabled;
    bool m_isWwanHardwareEnabled;
    QString m_activatingConnection;
    QString m_primaryConnection;
#if NM_CHECK_VERSION(1, 0, 0)
    NetworkManager::ConnectionSettings::ConnectionType m_primaryConnectionType;
#endif
    QString m_version;
    // to store NetworkManager's version.
    int m_x;
    int m_y;
    int m_z;
    void parseVersion(const QString &version);
    int compareVersion(const QString &version);
    int compareVersion(const int x, const int y, const int z) const;

    QMap<QString, ActiveConnection::Ptr> m_activeConnections;
    ActiveConnection::Ptr findRegisteredActiveConnection(const QString &);
    // manage device children
    Device::Ptr findRegisteredNetworkInterface(const QString &uni);
    Device::Ptr createNetworkInterface(const QString &uni);
    QMap<QString, Device::Ptr> networkInterfaceMap;
    // for frontend to call
    QString version() const;
    NetworkManager::Status status() const;
    Device::List networkInterfaces();
    Device::Ptr findNetworkInterface(const QString &uni);
    Device::Ptr findDeviceByIpIface(const QString &iface);
    bool isNetworkingEnabled() const;
    bool isWirelessEnabled() const;
    bool isWirelessHardwareEnabled() const;
    bool isWwanEnabled() const;
    bool isWwanHardwareEnabled() const;
#if !NM_CHECK_VERSION(1, 2, 0)
    bool isWimaxEnabled() const;
    bool isWimaxHardwareEnabled() const;
#endif
    QDBusPendingReply<QDBusObjectPath> activateConnection(const QString &connectionUni, const QString &interfaceUni, const QString &connectionParameter);
    QDBusPendingReply<QDBusObjectPath, QDBusObjectPath> addAndActivateConnection(const NMVariantMapMap &connection, const QString &interfaceUni, const QString &connectionParameter);
    QDBusPendingReply<> deactivateConnection(const QString &activeConnection);
    ActiveConnection::List activeConnections();
    QStringList activeConnectionsPaths() const;
    QDBusPendingReply<QString, QString> getLogging();
    void setNetworkingEnabled(bool enabled);
    void setWirelessEnabled(bool enabled);
    void setWwanEnabled(bool enabled);
#if !NM_CHECK_VERSION(1, 2, 0)
    void setWimaxEnabled(bool enabled);
#endif
    void sleep(bool sleep);
    void setLogging(NetworkManager::LogLevel, NetworkManager::LogDomains);
    NMStringMap permissions();
    Connectivity connectivity() const;
    QDBusPendingReply<uint> checkConnectivity();
    ActiveConnection::Ptr primaryConnection();
    ActiveConnection::Ptr activatingConnection();
#if NM_CHECK_VERSION(1, 0, 0)
    NetworkManager::ConnectionSettings::ConnectionType primaryConnectionType();
#endif
#if NM_CHECK_VERSION(0, 9, 10)
    bool isStartingUp() const;
#endif
protected Q_SLOTS:
    void init();
    void onDeviceAdded(const QDBusObjectPath &state);
    void onDeviceRemoved(const QDBusObjectPath &state);
    void propertiesChanged(const QVariantMap &changedProperties);
    void daemonRegistered();
    void daemonUnregistered();
private:
    void connectivityChanged(uint connectivity);
    void stateChanged(uint state);
    static NetworkManager::Connectivity convertConnectivity(uint connectivity);
    static NetworkManager::Status convertNMState(uint state);

};
}
#endif
