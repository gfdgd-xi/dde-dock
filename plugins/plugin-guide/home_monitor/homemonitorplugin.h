// SPDX-FileCopyrightText: 2018 - 2023 UnionTech Software Technology Co., Ltd.
//
// SPDX-License-Identifier: LGPL-3.0-or-later

#ifndef HOMEMONITORPLUGIN_H
#define HOMEMONITORPLUGIN_H

#include "informationwidget.h"

#include <QObject>

#include <dde-dock/pluginsiteminterface.h>

class HomeMonitorPlugin : public QObject, PluginsItemInterface
{
    Q_OBJECT
    Q_INTERFACES(PluginsItemInterface)
    Q_PLUGIN_METADATA(IID "com.deepin.dock.PluginsItemInterface" FILE "home_monitor.json")

public:
    explicit HomeMonitorPlugin(QObject *parent = nullptr);

    const QString pluginDisplayName() const override;
    const QString pluginName() const override;
    void init(PluginProxyInterface *proxyInter) override;

    QWidget *itemWidget(const QString &itemKey) override;
    QWidget *itemTipsWidget(const QString &itemKey) override;
    QWidget *itemPopupApplet(const QString &itemKey) override;

    bool pluginIsAllowDisable() override;
    bool pluginIsDisable() override;
    void pluginStateSwitched() override;

    const QString itemContextMenu(const QString &itemKey) override;
    void invokedMenuItem(const QString &itemKey, const QString &menuId, const bool checked) override;

    QIcon icon(const DockPart &) override;
    PluginMode status() const override;
    QString description() const override;

    QIcon icon(const DockPart &dockPart, int themeType) override;
    PluginFlags flags() const override;

private:
    InformationWidget *m_pluginWidget;
    QLabel *m_tipsWidget;
    QLabel *m_appletWidget;
};

#endif // HOMEMONITORPLUGIN_H
