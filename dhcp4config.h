/*
Copyright 2011 Lamarque V. Souza <lamarque@kde.org>

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

#ifndef NMQT_DHCP4CONFIG_H
#define NMQT_DHCP4CONFIG_H

#include "generic-types.h"

#include "QtNetworkManager-export.h"

#include <QtCore/QStringList>

namespace NetworkManager
{
class Dhcp4ConfigPrivate;

class NMQT_EXPORT Dhcp4Config: public QObject
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(Dhcp4Config)
public:
    explicit Dhcp4Config(const QString & path, QObject * owner);
    ~Dhcp4Config();

    QString path() const;

    QVariantMap options() const;

    QString optionValue(const QString &key) const;

Q_SIGNALS:
    void optionsChanged(const QVariantMap &);

protected Q_SLOTS:
    void dhcp4PropertiesChanged(const QVariantMap &);

private:
    Dhcp4ConfigPrivate * d_ptr;
};
} // namespace NetworkManager

#endif // NMQT_DHCP4CONFIG_H
