/********************************************************************************
** Form generated from reading ui file 'pluginManager.ui'
**
** Created: Sun Nov 22 16:05:09 2009
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_PLUGINMANAGER_H
#define UI_PLUGINMANAGER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_PluginManager
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *installedPluginsLabel;
    QLineEdit *searchLine;
    QListWidget *installedPluginsList;
    QHBoxLayout *horizontalLayout;
    QPushButton *installButton;
    QPushButton *uninstallButton;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *okButton;

    void setupUi(QDialog *PluginManager)
    {
        if (PluginManager->objectName().isEmpty())
            PluginManager->setObjectName(QString::fromUtf8("PluginManager"));
        PluginManager->resize(451, 543);
        gridLayout_2 = new QGridLayout(PluginManager);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        installedPluginsLabel = new QLabel(PluginManager);
        installedPluginsLabel->setObjectName(QString::fromUtf8("installedPluginsLabel"));

        gridLayout->addWidget(installedPluginsLabel, 0, 0, 1, 1);

        searchLine = new QLineEdit(PluginManager);
        searchLine->setObjectName(QString::fromUtf8("searchLine"));
        searchLine->setReadOnly(false);

        gridLayout->addWidget(searchLine, 1, 0, 1, 1);

        installedPluginsList = new QListWidget(PluginManager);
        installedPluginsList->setObjectName(QString::fromUtf8("installedPluginsList"));
        installedPluginsList->setMinimumSize(QSize(430, 420));

        gridLayout->addWidget(installedPluginsList, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        installButton = new QPushButton(PluginManager);
        installButton->setObjectName(QString::fromUtf8("installButton"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(installButton->sizePolicy().hasHeightForWidth());
        installButton->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(installButton);

        uninstallButton = new QPushButton(PluginManager);
        uninstallButton->setObjectName(QString::fromUtf8("uninstallButton"));
        sizePolicy.setHeightForWidth(uninstallButton->sizePolicy().hasHeightForWidth());
        uninstallButton->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(uninstallButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okButton = new QDialogButtonBox(PluginManager);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        sizePolicy.setHeightForWidth(okButton->sizePolicy().hasHeightForWidth());
        okButton->setSizePolicy(sizePolicy);
        okButton->setStandardButtons(QDialogButtonBox::Ok);

        horizontalLayout->addWidget(okButton);


        gridLayout->addLayout(horizontalLayout, 3, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        QWidget::setTabOrder(searchLine, installedPluginsList);
        QWidget::setTabOrder(installedPluginsList, installButton);
        QWidget::setTabOrder(installButton, uninstallButton);
        QWidget::setTabOrder(uninstallButton, okButton);

        retranslateUi(PluginManager);
        QObject::connect(okButton, SIGNAL(clicked(QAbstractButton*)), PluginManager, SLOT(close()));

        QMetaObject::connectSlotsByName(PluginManager);
    } // setupUi

    void retranslateUi(QDialog *PluginManager)
    {
        PluginManager->setWindowTitle(QApplication::translate("PluginManager", "Plugins Manager", 0, QApplication::UnicodeUTF8));
        installedPluginsLabel->setText(QApplication::translate("PluginManager", "Installed Plugins:", 0, QApplication::UnicodeUTF8));
        searchLine->setText(QString());
        installButton->setText(QApplication::translate("PluginManager", "Install Plugin", 0, QApplication::UnicodeUTF8));
        uninstallButton->setText(QApplication::translate("PluginManager", "Uninstall Plugin", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(PluginManager);
    } // retranslateUi

};

namespace Ui {
    class PluginManager: public Ui_PluginManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLUGINMANAGER_H
