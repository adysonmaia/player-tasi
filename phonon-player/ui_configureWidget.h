/********************************************************************************
** Form generated from reading ui file 'configureWidget.ui'
**
** Created: Sun Nov 22 16:05:09 2009
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_CONFIGUREWIDGET_H
#define UI_CONFIGUREWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTreeWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConfigureWidget
{
public:
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label;
    QTreeWidget *scanFolderTree;
    QSpacerItem *horizontalSpacer;
    QPushButton *scanButton;
    QSpacerItem *horizontalSpacer_2;
    QFrame *line;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QDialogButtonBox *okButton;

    void setupUi(QWidget *ConfigureWidget)
    {
        if (ConfigureWidget->objectName().isEmpty())
            ConfigureWidget->setObjectName(QString::fromUtf8("ConfigureWidget"));
        ConfigureWidget->resize(699, 437);
        gridLayout_3 = new QGridLayout(ConfigureWidget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        groupBox = new QGroupBox(ConfigureWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 3);

        scanFolderTree = new QTreeWidget(groupBox);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        scanFolderTree->setHeaderItem(__qtreewidgetitem);
        scanFolderTree->setObjectName(QString::fromUtf8("scanFolderTree"));
        scanFolderTree->setMinimumSize(QSize(620, 230));
        scanFolderTree->header()->setVisible(false);

        gridLayout->addWidget(scanFolderTree, 1, 0, 1, 3);

        horizontalSpacer = new QSpacerItem(276, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 0, 1, 1);

        scanButton = new QPushButton(groupBox);
        scanButton->setObjectName(QString::fromUtf8("scanButton"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scanButton->sizePolicy().hasHeightForWidth());
        scanButton->setSizePolicy(sizePolicy);

        gridLayout->addWidget(scanButton, 2, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(275, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 2, 1, 1);


        gridLayout_2->addWidget(groupBox, 0, 0, 1, 1);

        line = new QFrame(ConfigureWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_3 = new QSpacerItem(528, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        okButton = new QDialogButtonBox(ConfigureWidget);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        sizePolicy.setHeightForWidth(okButton->sizePolicy().hasHeightForWidth());
        okButton->setSizePolicy(sizePolicy);
        okButton->setOrientation(Qt::Horizontal);
        okButton->setStandardButtons(QDialogButtonBox::Ok);

        horizontalLayout->addWidget(okButton);


        gridLayout_2->addLayout(horizontalLayout, 2, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 1);


        retranslateUi(ConfigureWidget);
        QObject::connect(okButton, SIGNAL(clicked(QAbstractButton*)), ConfigureWidget, SLOT(close()));

        QMetaObject::connectSlotsByName(ConfigureWidget);
    } // setupUi

    void retranslateUi(QWidget *ConfigureWidget)
    {
        ConfigureWidget->setWindowTitle(QApplication::translate("ConfigureWidget", "Configure Player", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("ConfigureWidget", "Collection Folders", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ConfigureWidget", "Choose the folders that you want to be added to your collection:", 0, QApplication::UnicodeUTF8));
        scanButton->setText(QApplication::translate("ConfigureWidget", "Scan Folders", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(ConfigureWidget);
    } // retranslateUi

};

namespace Ui {
    class ConfigureWidget: public Ui_ConfigureWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGUREWIDGET_H
