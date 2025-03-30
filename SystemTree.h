#ifndef SystemTree_H
#define SystemTree_H

#include <QtGui>
#include <QLabel>
#include "PluginServices.h"
#include "CubePlugin.h"
#include "TabInterface.h"
#include <QString>
#include <QJsonObject>

namespace systemtreeplugin
{
class SystemTree: public QObject, public cubepluginapi::CubePlugin, cubepluginapi::TabInterface
{
    Q_OBJECT
    Q_INTERFACES( cubepluginapi::CubePlugin )
    Q_PLUGIN_METADATA( IID "SystemTreePlugin" )

public:
    SystemTree();

    virtual bool cubeOpened( cubepluginapi::PluginServices* service );
    virtual void cubeColsed();

    virtual QString name() const;
    virtual void version( int& major, int& minor, int& bugfix ) const;
    virtual QString getHelpText() const;

    virtual QString label() const;
    virtual QWidget* widget();
    
    virtual const cubepluginapi::TreeItem* getTreeRoot( QList<cubepluginapi::TreeItem* > treeList);
    virtual QJsonObject toJSON( const cubepluginapi::TreeItem* item );


private slots:

private:
    QWidget*                       widget_;
    QLabel*                        qlabel_;
    cubepluginapi::PluginServices* service;

};
    
} // namespace systemtreeplugin

#endif