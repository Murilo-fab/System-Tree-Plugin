#include <QVBoxLayout>
#include <QtPlugin>
#include "SystemTree.h"
#include "PluginServices.h"

using namespace cubepluginapi;
using namespace systemtreeplugin;

SystemTree::SystemTree()
{

}

bool SystemTree::cubeOpened(PluginServices* service)
{
    this->service = service;

    widget_ = new QWidget();
    qlabel_ = new QLabel( "System Tree" );
    QVBoxLayout* layout = new QVBoxLayout();
    widget_->setLayout( layout );
    layout->addWidget( qlabel_ );
    service->addTab( SYSTEM, this );

    QList<TreeItem* > SystemTreeList = service->getTreeItems( SYSTEM );
    const TreeItem* root = getTreeRoot(SystemTreeList);

    QJsonObject JSON = toJSON(root);
    QJsonDocument jsonDoc(JSON);
    QString jsonString = jsonDoc.toJson(QJsonDocument::Indented);

    qlabel_->setText(jsonString);

    return true;
}
void SystemTree::cubeColsed()
{
    delete widget_;
}

void SystemTree::version( int& major, int& minor, int& bugfix ) const
{
    major  = 1;
    minor  = 0;
    bugfix = 0;
}

QString SystemTree::name() const
{
    return "System Tree";
}

QString SystemTree::getHelpText() const
{
    return "";
}

QWidget* SystemTree::widget() {
    return widget_;
}

QString SystemTree::label() const{
    return "System Tree Plugin";
}

const TreeItem* SystemTree::getTreeRoot( QList<TreeItem* > treeList) {
    const TreeItem* root = nullptr;
    
    for (const TreeItem* item : treeList) {
        if (item->isTopLevelItem() == true) {
            root = item;
            break;
        }
    }

    return root;
}

QJsonObject SystemTree::toJSON( const TreeItem* item ) {
    QJsonObject node;
    node["name"] = item->getName();
    
    if (!item->isLeaf()) {
        QJsonArray children;
        
        for (const TreeItem* child : item->getChildren()) {
            children.append(toJSON(child));
        }
        
        node["children"] = children;
    }
    
    return node;
}