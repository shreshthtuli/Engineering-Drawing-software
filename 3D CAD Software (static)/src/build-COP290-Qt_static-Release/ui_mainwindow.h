/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "myglwidget.h"
#include "orthofront.h"
#include "orthoside.h"
#include "orthotop.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionImport_Ortho;
    QAction *actionImport_3D_Model;
    QAction *actionExport_Ortho;
    QAction *actionExport_3D_Model;
    QAction *action3D_to_Orthp;
    QAction *actionImport;
    QAction *actionExport;
    QAction *action3D_Model;
    QAction *actionOrthographic_projection;
    QAction *action3D_Model_2;
    QAction *actionOrthograhic_projection;
    QAction *actionCapture_snapshot;
    QAction *actionSave;
    QAction *action3D_Model_3;
    QAction *actionOrthographic_Projections;
    QAction *actionIsometric_View;
    QAction *actionPerspective_View;
    QAction *actionSectional_View;
    QAction *actionOrthographic_Projection;
    QAction *actionComplete_Model;
    QAction *actionComplete_Model_2;
    QAction *actionComplete_Model_3;
    QAction *actionAbout_this_software;
    QAction *actionAbout_Qt;
    QAction *actionExit;
    QAction *actionChange_background_color;
    QAction *actionDocumentation;
    QAction *actionContact_developers;
    QAction *actionSolid_View;
    QAction *actionWireframe_View;
    QAction *actionCreate_new_wireframe;
    QAction *actionAdd_on_wireframe;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_4;
    QLabel *RotateObject;
    QHBoxLayout *theta;
    QLabel *theta_2;
    QSlider *thataSlider;
    QLabel *valTheta;
    QHBoxLayout *alpha;
    QLabel *alpha_2;
    QSlider *alphaSlider;
    QLabel *valAlpha;
    QHBoxLayout *beta;
    QLabel *beta_2;
    QSlider *betaSlider;
    QLabel *valBeta;
    QVBoxLayout *verticalLayout_3;
    QFrame *line_4;
    QLabel *TranslateObject;
    QHBoxLayout *X;
    QLabel *X_2;
    QSlider *XSlider;
    QLabel *valX;
    QHBoxLayout *Y;
    QLabel *Y_2;
    QSlider *YSlider;
    QLabel *valY;
    QHBoxLayout *Z;
    QLabel *Z_2;
    QSlider *ZSlider;
    QLabel *valZ;
    QVBoxLayout *verticalLayout_5;
    QFrame *line_3;
    QLabel *SacleObject;
    QHBoxLayout *horizontalLayout_2;
    QLabel *ScaleFactor;
    QDoubleSpinBox *ScaleVal;
    QFrame *line_5;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QLabel *xcurr;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_2;
    QLabel *ycurr;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QLabel *zcurr;
    QLabel *initial;
    QFrame *line_6;
    QLabel *label_8;
    QLabel *label_6;
    QLabel *label_5;
    QLabel *label_7;
    QCheckBox *checkBox;
    QSpacerItem *verticalSpacer;
    QPushButton *UpdateModel;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton;
    QPushButton *AboutQt;
    QPushButton *quitButton;
    QLabel *Developed;
    QLabel *names;
    QFrame *line;
    QFrame *OpenGLFrame;
    QVBoxLayout *verticalLayout_11;
    MyGLWidget *widget_4;
    QFrame *line_9;
    QHBoxLayout *horizontalLayout_11;
    QVBoxLayout *verticalLayout_12;
    QLabel *label_17;
    OrthoFront *frontortho;
    QFrame *line_7;
    QVBoxLayout *verticalLayout_13;
    QLabel *label_18;
    OrthoTop *toportho;
    QFrame *line_8;
    QVBoxLayout *verticalLayout_14;
    QLabel *label_19;
    OrthoSide *sideortho;
    QFrame *line_2;
    QVBoxLayout *verticalLayout_6;
    QLabel *x;
    QLabel *xRotVal;
    QSlider *xSlider;
    QVBoxLayout *verticalLayout_7;
    QLabel *y;
    QLabel *yRotVal;
    QSlider *ySlider;
    QVBoxLayout *verticalLayout_8;
    QLabel *z;
    QLabel *zRotVal;
    QSlider *zSlider;
    QVBoxLayout *verticalLayout_15;
    QLabel *zoom;
    QLabel *zoomval;
    QSlider *zoomslider;
    QToolBar *mainToolBar;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuOpen_File;
    QMenu *menuSave_As;
    QMenu *menuCovert;
    QMenu *menuView;
    QMenu *menuAbout;
    QMenu *menuPreferences;
    QMenu *menuHelp;
    QMenu *menuView_3D;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1500, 800);
        actionImport_Ortho = new QAction(MainWindow);
        actionImport_Ortho->setObjectName(QStringLiteral("actionImport_Ortho"));
        actionImport_3D_Model = new QAction(MainWindow);
        actionImport_3D_Model->setObjectName(QStringLiteral("actionImport_3D_Model"));
        actionExport_Ortho = new QAction(MainWindow);
        actionExport_Ortho->setObjectName(QStringLiteral("actionExport_Ortho"));
        actionExport_3D_Model = new QAction(MainWindow);
        actionExport_3D_Model->setObjectName(QStringLiteral("actionExport_3D_Model"));
        action3D_to_Orthp = new QAction(MainWindow);
        action3D_to_Orthp->setObjectName(QStringLiteral("action3D_to_Orthp"));
        actionImport = new QAction(MainWindow);
        actionImport->setObjectName(QStringLiteral("actionImport"));
        actionExport = new QAction(MainWindow);
        actionExport->setObjectName(QStringLiteral("actionExport"));
        action3D_Model = new QAction(MainWindow);
        action3D_Model->setObjectName(QStringLiteral("action3D_Model"));
        actionOrthographic_projection = new QAction(MainWindow);
        actionOrthographic_projection->setObjectName(QStringLiteral("actionOrthographic_projection"));
        action3D_Model_2 = new QAction(MainWindow);
        action3D_Model_2->setObjectName(QStringLiteral("action3D_Model_2"));
        actionOrthograhic_projection = new QAction(MainWindow);
        actionOrthograhic_projection->setObjectName(QStringLiteral("actionOrthograhic_projection"));
        actionCapture_snapshot = new QAction(MainWindow);
        actionCapture_snapshot->setObjectName(QStringLiteral("actionCapture_snapshot"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        action3D_Model_3 = new QAction(MainWindow);
        action3D_Model_3->setObjectName(QStringLiteral("action3D_Model_3"));
        actionOrthographic_Projections = new QAction(MainWindow);
        actionOrthographic_Projections->setObjectName(QStringLiteral("actionOrthographic_Projections"));
        actionIsometric_View = new QAction(MainWindow);
        actionIsometric_View->setObjectName(QStringLiteral("actionIsometric_View"));
        actionPerspective_View = new QAction(MainWindow);
        actionPerspective_View->setObjectName(QStringLiteral("actionPerspective_View"));
        actionSectional_View = new QAction(MainWindow);
        actionSectional_View->setObjectName(QStringLiteral("actionSectional_View"));
        actionOrthographic_Projection = new QAction(MainWindow);
        actionOrthographic_Projection->setObjectName(QStringLiteral("actionOrthographic_Projection"));
        actionComplete_Model = new QAction(MainWindow);
        actionComplete_Model->setObjectName(QStringLiteral("actionComplete_Model"));
        actionComplete_Model_2 = new QAction(MainWindow);
        actionComplete_Model_2->setObjectName(QStringLiteral("actionComplete_Model_2"));
        actionComplete_Model_3 = new QAction(MainWindow);
        actionComplete_Model_3->setObjectName(QStringLiteral("actionComplete_Model_3"));
        actionAbout_this_software = new QAction(MainWindow);
        actionAbout_this_software->setObjectName(QStringLiteral("actionAbout_this_software"));
        actionAbout_Qt = new QAction(MainWindow);
        actionAbout_Qt->setObjectName(QStringLiteral("actionAbout_Qt"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionChange_background_color = new QAction(MainWindow);
        actionChange_background_color->setObjectName(QStringLiteral("actionChange_background_color"));
        actionDocumentation = new QAction(MainWindow);
        actionDocumentation->setObjectName(QStringLiteral("actionDocumentation"));
        actionContact_developers = new QAction(MainWindow);
        actionContact_developers->setObjectName(QStringLiteral("actionContact_developers"));
        actionSolid_View = new QAction(MainWindow);
        actionSolid_View->setObjectName(QStringLiteral("actionSolid_View"));
        actionWireframe_View = new QAction(MainWindow);
        actionWireframe_View->setObjectName(QStringLiteral("actionWireframe_View"));
        actionCreate_new_wireframe = new QAction(MainWindow);
        actionCreate_new_wireframe->setObjectName(QStringLiteral("actionCreate_new_wireframe"));
        actionAdd_on_wireframe = new QAction(MainWindow);
        actionAdd_on_wireframe->setObjectName(QStringLiteral("actionAdd_on_wireframe"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        RotateObject = new QLabel(centralWidget);
        RotateObject->setObjectName(QStringLiteral("RotateObject"));

        verticalLayout_4->addWidget(RotateObject);

        theta = new QHBoxLayout();
        theta->setSpacing(6);
        theta->setObjectName(QStringLiteral("theta"));
        theta_2 = new QLabel(centralWidget);
        theta_2->setObjectName(QStringLiteral("theta_2"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(100);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(theta_2->sizePolicy().hasHeightForWidth());
        theta_2->setSizePolicy(sizePolicy);
        theta_2->setMinimumSize(QSize(50, 0));

        theta->addWidget(theta_2);

        thataSlider = new QSlider(centralWidget);
        thataSlider->setObjectName(QStringLiteral("thataSlider"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(thataSlider->sizePolicy().hasHeightForWidth());
        thataSlider->setSizePolicy(sizePolicy1);
        thataSlider->setMinimumSize(QSize(180, 0));
        thataSlider->setMaximum(360);
        thataSlider->setSingleStep(1);
        thataSlider->setOrientation(Qt::Horizontal);

        theta->addWidget(thataSlider);

        valTheta = new QLabel(centralWidget);
        valTheta->setObjectName(QStringLiteral("valTheta"));

        theta->addWidget(valTheta);


        verticalLayout_4->addLayout(theta);

        alpha = new QHBoxLayout();
        alpha->setSpacing(6);
        alpha->setObjectName(QStringLiteral("alpha"));
        alpha_2 = new QLabel(centralWidget);
        alpha_2->setObjectName(QStringLiteral("alpha_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(alpha_2->sizePolicy().hasHeightForWidth());
        alpha_2->setSizePolicy(sizePolicy2);
        alpha_2->setMinimumSize(QSize(50, 0));

        alpha->addWidget(alpha_2);

        alphaSlider = new QSlider(centralWidget);
        alphaSlider->setObjectName(QStringLiteral("alphaSlider"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(alphaSlider->sizePolicy().hasHeightForWidth());
        alphaSlider->setSizePolicy(sizePolicy3);
        alphaSlider->setMinimumSize(QSize(180, 0));
        alphaSlider->setMaximum(180);
        alphaSlider->setOrientation(Qt::Horizontal);

        alpha->addWidget(alphaSlider);

        valAlpha = new QLabel(centralWidget);
        valAlpha->setObjectName(QStringLiteral("valAlpha"));

        alpha->addWidget(valAlpha);


        verticalLayout_4->addLayout(alpha);

        beta = new QHBoxLayout();
        beta->setSpacing(6);
        beta->setObjectName(QStringLiteral("beta"));
        beta_2 = new QLabel(centralWidget);
        beta_2->setObjectName(QStringLiteral("beta_2"));
        sizePolicy2.setHeightForWidth(beta_2->sizePolicy().hasHeightForWidth());
        beta_2->setSizePolicy(sizePolicy2);
        beta_2->setMinimumSize(QSize(50, 0));

        beta->addWidget(beta_2);

        betaSlider = new QSlider(centralWidget);
        betaSlider->setObjectName(QStringLiteral("betaSlider"));
        sizePolicy3.setHeightForWidth(betaSlider->sizePolicy().hasHeightForWidth());
        betaSlider->setSizePolicy(sizePolicy3);
        betaSlider->setMinimumSize(QSize(180, 0));
        betaSlider->setMaximum(360);
        betaSlider->setOrientation(Qt::Horizontal);

        beta->addWidget(betaSlider);

        valBeta = new QLabel(centralWidget);
        valBeta->setObjectName(QStringLiteral("valBeta"));

        beta->addWidget(valBeta);


        verticalLayout_4->addLayout(beta);


        verticalLayout->addLayout(verticalLayout_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        line_4 = new QFrame(centralWidget);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line_4);

        TranslateObject = new QLabel(centralWidget);
        TranslateObject->setObjectName(QStringLiteral("TranslateObject"));

        verticalLayout_3->addWidget(TranslateObject);

        X = new QHBoxLayout();
        X->setSpacing(6);
        X->setObjectName(QStringLiteral("X"));
        X_2 = new QLabel(centralWidget);
        X_2->setObjectName(QStringLiteral("X_2"));
        sizePolicy2.setHeightForWidth(X_2->sizePolicy().hasHeightForWidth());
        X_2->setSizePolicy(sizePolicy2);
        X_2->setMinimumSize(QSize(50, 0));

        X->addWidget(X_2);

        XSlider = new QSlider(centralWidget);
        XSlider->setObjectName(QStringLiteral("XSlider"));
        sizePolicy3.setHeightForWidth(XSlider->sizePolicy().hasHeightForWidth());
        XSlider->setSizePolicy(sizePolicy3);
        XSlider->setMinimumSize(QSize(180, 0));
        XSlider->setMinimum(-10);
        XSlider->setMaximum(10);
        XSlider->setPageStep(1);
        XSlider->setOrientation(Qt::Horizontal);

        X->addWidget(XSlider);

        valX = new QLabel(centralWidget);
        valX->setObjectName(QStringLiteral("valX"));

        X->addWidget(valX);


        verticalLayout_3->addLayout(X);

        Y = new QHBoxLayout();
        Y->setSpacing(6);
        Y->setObjectName(QStringLiteral("Y"));
        Y_2 = new QLabel(centralWidget);
        Y_2->setObjectName(QStringLiteral("Y_2"));
        sizePolicy2.setHeightForWidth(Y_2->sizePolicy().hasHeightForWidth());
        Y_2->setSizePolicy(sizePolicy2);
        Y_2->setMinimumSize(QSize(50, 0));

        Y->addWidget(Y_2);

        YSlider = new QSlider(centralWidget);
        YSlider->setObjectName(QStringLiteral("YSlider"));
        sizePolicy3.setHeightForWidth(YSlider->sizePolicy().hasHeightForWidth());
        YSlider->setSizePolicy(sizePolicy3);
        YSlider->setMinimumSize(QSize(180, 0));
        YSlider->setMinimum(-10);
        YSlider->setMaximum(10);
        YSlider->setPageStep(1);
        YSlider->setOrientation(Qt::Horizontal);

        Y->addWidget(YSlider);

        valY = new QLabel(centralWidget);
        valY->setObjectName(QStringLiteral("valY"));

        Y->addWidget(valY);


        verticalLayout_3->addLayout(Y);

        Z = new QHBoxLayout();
        Z->setSpacing(6);
        Z->setObjectName(QStringLiteral("Z"));
        Z_2 = new QLabel(centralWidget);
        Z_2->setObjectName(QStringLiteral("Z_2"));
        sizePolicy2.setHeightForWidth(Z_2->sizePolicy().hasHeightForWidth());
        Z_2->setSizePolicy(sizePolicy2);
        Z_2->setMinimumSize(QSize(50, 0));

        Z->addWidget(Z_2);

        ZSlider = new QSlider(centralWidget);
        ZSlider->setObjectName(QStringLiteral("ZSlider"));
        sizePolicy3.setHeightForWidth(ZSlider->sizePolicy().hasHeightForWidth());
        ZSlider->setSizePolicy(sizePolicy3);
        ZSlider->setMinimumSize(QSize(180, 0));
        ZSlider->setMinimum(-10);
        ZSlider->setMaximum(10);
        ZSlider->setPageStep(1);
        ZSlider->setOrientation(Qt::Horizontal);

        Z->addWidget(ZSlider);

        valZ = new QLabel(centralWidget);
        valZ->setObjectName(QStringLiteral("valZ"));

        Z->addWidget(valZ);


        verticalLayout_3->addLayout(Z);


        verticalLayout->addLayout(verticalLayout_3);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(line_3);

        SacleObject = new QLabel(centralWidget);
        SacleObject->setObjectName(QStringLiteral("SacleObject"));

        verticalLayout_5->addWidget(SacleObject);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        ScaleFactor = new QLabel(centralWidget);
        ScaleFactor->setObjectName(QStringLiteral("ScaleFactor"));

        horizontalLayout_2->addWidget(ScaleFactor);

        ScaleVal = new QDoubleSpinBox(centralWidget);
        ScaleVal->setObjectName(QStringLiteral("ScaleVal"));
        ScaleVal->setSingleStep(0.01);

        horizontalLayout_2->addWidget(ScaleVal);


        verticalLayout_5->addLayout(horizontalLayout_2);


        verticalLayout->addLayout(verticalLayout_5);

        line_5 = new QFrame(centralWidget);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_5);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout->addWidget(label_4);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_4->addWidget(label);

        xcurr = new QLabel(centralWidget);
        xcurr->setObjectName(QStringLiteral("xcurr"));

        horizontalLayout_4->addWidget(xcurr);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_6->addWidget(label_2);

        ycurr = new QLabel(centralWidget);
        ycurr->setObjectName(QStringLiteral("ycurr"));

        horizontalLayout_6->addWidget(ycurr);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_5->addWidget(label_3);

        zcurr = new QLabel(centralWidget);
        zcurr->setObjectName(QStringLiteral("zcurr"));

        horizontalLayout_5->addWidget(zcurr);


        verticalLayout->addLayout(horizontalLayout_5);

        initial = new QLabel(centralWidget);
        initial->setObjectName(QStringLiteral("initial"));

        verticalLayout->addWidget(initial);

        line_6 = new QFrame(centralWidget);
        line_6->setObjectName(QStringLiteral("line_6"));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_6);

        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        verticalLayout->addWidget(label_8);

        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout->addWidget(label_6);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout->addWidget(label_5);

        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout->addWidget(label_7);

        checkBox = new QCheckBox(centralWidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        verticalLayout->addWidget(checkBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        UpdateModel = new QPushButton(centralWidget);
        UpdateModel->setObjectName(QStringLiteral("UpdateModel"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(UpdateModel->sizePolicy().hasHeightForWidth());
        UpdateModel->setSizePolicy(sizePolicy4);
        UpdateModel->setMinimumSize(QSize(220, 0));

        verticalLayout->addWidget(UpdateModel);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_3->addWidget(pushButton);

        AboutQt = new QPushButton(centralWidget);
        AboutQt->setObjectName(QStringLiteral("AboutQt"));

        horizontalLayout_3->addWidget(AboutQt);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(verticalLayout);

        quitButton = new QPushButton(centralWidget);
        quitButton->setObjectName(QStringLiteral("quitButton"));

        verticalLayout_2->addWidget(quitButton);

        Developed = new QLabel(centralWidget);
        Developed->setObjectName(QStringLiteral("Developed"));

        verticalLayout_2->addWidget(Developed);

        names = new QLabel(centralWidget);
        names->setObjectName(QStringLiteral("names"));

        verticalLayout_2->addWidget(names);


        horizontalLayout->addLayout(verticalLayout_2);

        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line);

        OpenGLFrame = new QFrame(centralWidget);
        OpenGLFrame->setObjectName(QStringLiteral("OpenGLFrame"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(OpenGLFrame->sizePolicy().hasHeightForWidth());
        OpenGLFrame->setSizePolicy(sizePolicy5);
        OpenGLFrame->setFrameShape(QFrame::StyledPanel);
        OpenGLFrame->setFrameShadow(QFrame::Raised);
        verticalLayout_11 = new QVBoxLayout(OpenGLFrame);
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setContentsMargins(11, 11, 11, 11);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        widget_4 = new MyGLWidget(OpenGLFrame);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        sizePolicy5.setHeightForWidth(widget_4->sizePolicy().hasHeightForWidth());
        widget_4->setSizePolicy(sizePolicy5);
        widget_4->setCursor(QCursor(Qt::CrossCursor));
        widget_4->setMouseTracking(true);

        verticalLayout_11->addWidget(widget_4);

        line_9 = new QFrame(OpenGLFrame);
        line_9->setObjectName(QStringLiteral("line_9"));
        line_9->setFrameShape(QFrame::HLine);
        line_9->setFrameShadow(QFrame::Sunken);

        verticalLayout_11->addWidget(line_9);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        label_17 = new QLabel(OpenGLFrame);
        label_17->setObjectName(QStringLiteral("label_17"));
        sizePolicy4.setHeightForWidth(label_17->sizePolicy().hasHeightForWidth());
        label_17->setSizePolicy(sizePolicy4);

        verticalLayout_12->addWidget(label_17);

        frontortho = new OrthoFront(OpenGLFrame);
        frontortho->setObjectName(QStringLiteral("frontortho"));
        QSizePolicy sizePolicy6(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(frontortho->sizePolicy().hasHeightForWidth());
        frontortho->setSizePolicy(sizePolicy6);
        frontortho->setMaximumSize(QSize(16777215, 300));

        verticalLayout_12->addWidget(frontortho);


        horizontalLayout_11->addLayout(verticalLayout_12);

        line_7 = new QFrame(OpenGLFrame);
        line_7->setObjectName(QStringLiteral("line_7"));
        sizePolicy3.setHeightForWidth(line_7->sizePolicy().hasHeightForWidth());
        line_7->setSizePolicy(sizePolicy3);
        line_7->setMaximumSize(QSize(16777215, 300));
        line_7->setFrameShape(QFrame::VLine);
        line_7->setFrameShadow(QFrame::Sunken);

        horizontalLayout_11->addWidget(line_7);

        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setSpacing(6);
        verticalLayout_13->setObjectName(QStringLiteral("verticalLayout_13"));
        label_18 = new QLabel(OpenGLFrame);
        label_18->setObjectName(QStringLiteral("label_18"));
        sizePolicy4.setHeightForWidth(label_18->sizePolicy().hasHeightForWidth());
        label_18->setSizePolicy(sizePolicy4);

        verticalLayout_13->addWidget(label_18);

        toportho = new OrthoTop(OpenGLFrame);
        toportho->setObjectName(QStringLiteral("toportho"));
        sizePolicy6.setHeightForWidth(toportho->sizePolicy().hasHeightForWidth());
        toportho->setSizePolicy(sizePolicy6);
        toportho->setMaximumSize(QSize(16777215, 300));

        verticalLayout_13->addWidget(toportho);


        horizontalLayout_11->addLayout(verticalLayout_13);

        line_8 = new QFrame(OpenGLFrame);
        line_8->setObjectName(QStringLiteral("line_8"));
        line_8->setMaximumSize(QSize(16777215, 300));
        line_8->setFrameShape(QFrame::VLine);
        line_8->setFrameShadow(QFrame::Sunken);

        horizontalLayout_11->addWidget(line_8);

        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setSpacing(6);
        verticalLayout_14->setObjectName(QStringLiteral("verticalLayout_14"));
        label_19 = new QLabel(OpenGLFrame);
        label_19->setObjectName(QStringLiteral("label_19"));
        sizePolicy4.setHeightForWidth(label_19->sizePolicy().hasHeightForWidth());
        label_19->setSizePolicy(sizePolicy4);

        verticalLayout_14->addWidget(label_19);

        sideortho = new OrthoSide(OpenGLFrame);
        sideortho->setObjectName(QStringLiteral("sideortho"));
        sizePolicy6.setHeightForWidth(sideortho->sizePolicy().hasHeightForWidth());
        sideortho->setSizePolicy(sizePolicy6);
        sideortho->setMaximumSize(QSize(16777215, 300));

        verticalLayout_14->addWidget(sideortho);


        horizontalLayout_11->addLayout(verticalLayout_14);


        verticalLayout_11->addLayout(horizontalLayout_11);


        horizontalLayout->addWidget(OpenGLFrame);

        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_2);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        x = new QLabel(centralWidget);
        x->setObjectName(QStringLiteral("x"));

        verticalLayout_6->addWidget(x);

        xRotVal = new QLabel(centralWidget);
        xRotVal->setObjectName(QStringLiteral("xRotVal"));

        verticalLayout_6->addWidget(xRotVal);

        xSlider = new QSlider(centralWidget);
        xSlider->setObjectName(QStringLiteral("xSlider"));
        QSizePolicy sizePolicy7(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy7.setHorizontalStretch(4);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(xSlider->sizePolicy().hasHeightForWidth());
        xSlider->setSizePolicy(sizePolicy7);
        xSlider->setLayoutDirection(Qt::RightToLeft);
        xSlider->setMaximum(360);
        xSlider->setOrientation(Qt::Vertical);

        verticalLayout_6->addWidget(xSlider);


        horizontalLayout->addLayout(verticalLayout_6);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        y = new QLabel(centralWidget);
        y->setObjectName(QStringLiteral("y"));

        verticalLayout_7->addWidget(y);

        yRotVal = new QLabel(centralWidget);
        yRotVal->setObjectName(QStringLiteral("yRotVal"));

        verticalLayout_7->addWidget(yRotVal);

        ySlider = new QSlider(centralWidget);
        ySlider->setObjectName(QStringLiteral("ySlider"));
        ySlider->setMaximum(360);
        ySlider->setOrientation(Qt::Vertical);

        verticalLayout_7->addWidget(ySlider);


        horizontalLayout->addLayout(verticalLayout_7);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        z = new QLabel(centralWidget);
        z->setObjectName(QStringLiteral("z"));

        verticalLayout_8->addWidget(z);

        zRotVal = new QLabel(centralWidget);
        zRotVal->setObjectName(QStringLiteral("zRotVal"));

        verticalLayout_8->addWidget(zRotVal);

        zSlider = new QSlider(centralWidget);
        zSlider->setObjectName(QStringLiteral("zSlider"));
        zSlider->setMaximum(360);
        zSlider->setOrientation(Qt::Vertical);

        verticalLayout_8->addWidget(zSlider);


        horizontalLayout->addLayout(verticalLayout_8);

        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setSpacing(6);
        verticalLayout_15->setObjectName(QStringLiteral("verticalLayout_15"));
        zoom = new QLabel(centralWidget);
        zoom->setObjectName(QStringLiteral("zoom"));

        verticalLayout_15->addWidget(zoom);

        zoomval = new QLabel(centralWidget);
        zoomval->setObjectName(QStringLiteral("zoomval"));

        verticalLayout_15->addWidget(zoomval);

        zoomslider = new QSlider(centralWidget);
        zoomslider->setObjectName(QStringLiteral("zoomslider"));
        zoomslider->setMaximum(1000);
        zoomslider->setValue(1);
        zoomslider->setOrientation(Qt::Vertical);

        verticalLayout_15->addWidget(zoomslider);


        horizontalLayout->addLayout(verticalLayout_15);

        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1500, 26));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuOpen_File = new QMenu(menuFile);
        menuOpen_File->setObjectName(QStringLiteral("menuOpen_File"));
        menuSave_As = new QMenu(menuFile);
        menuSave_As->setObjectName(QStringLiteral("menuSave_As"));
        menuCovert = new QMenu(menuBar);
        menuCovert->setObjectName(QStringLiteral("menuCovert"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QStringLiteral("menuView"));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QStringLiteral("menuAbout"));
        menuPreferences = new QMenu(menuBar);
        menuPreferences->setObjectName(QStringLiteral("menuPreferences"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        menuView_3D = new QMenu(menuBar);
        menuView_3D->setObjectName(QStringLiteral("menuView_3D"));
        MainWindow->setMenuBar(menuBar);
        QWidget::setTabOrder(alphaSlider, betaSlider);
        QWidget::setTabOrder(betaSlider, XSlider);
        QWidget::setTabOrder(XSlider, YSlider);
        QWidget::setTabOrder(YSlider, ZSlider);
        QWidget::setTabOrder(ZSlider, ScaleVal);
        QWidget::setTabOrder(ScaleVal, pushButton);
        QWidget::setTabOrder(pushButton, AboutQt);
        QWidget::setTabOrder(AboutQt, quitButton);

        mainToolBar->addSeparator();
        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuCovert->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuView_3D->menuAction());
        menuBar->addAction(menuPreferences->menuAction());
        menuBar->addAction(menuAbout->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionCreate_new_wireframe);
        menuFile->addAction(actionAdd_on_wireframe);
        menuFile->addAction(menuOpen_File->menuAction());
        menuFile->addAction(actionCapture_snapshot);
        menuFile->addAction(menuSave_As->menuAction());
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuOpen_File->addAction(action3D_Model_2);
        menuOpen_File->addAction(actionOrthograhic_projection);
        menuSave_As->addAction(action3D_Model_3);
        menuSave_As->addAction(actionOrthographic_Projection);
        menuCovert->addAction(action3D_to_Orthp);
        menuCovert->addAction(actionOrthographic_Projections);
        menuView->addAction(actionIsometric_View);
        menuView->addAction(actionPerspective_View);
        menuAbout->addAction(actionAbout_this_software);
        menuAbout->addAction(actionAbout_Qt);
        menuPreferences->addAction(actionChange_background_color);
        menuHelp->addSeparator();
        menuHelp->addSeparator();
        menuHelp->addAction(actionDocumentation);
        menuHelp->addSeparator();
        menuHelp->addAction(actionContact_developers);
        menuView_3D->addAction(actionSolid_View);
        menuView_3D->addAction(actionWireframe_View);

        retranslateUi(MainWindow);
        QObject::connect(widget_4, SIGNAL(yRotationChanged(int)), ySlider, SLOT(setValue(int)));
        QObject::connect(widget_4, SIGNAL(zRotationChanged(int)), zSlider, SLOT(setValue(int)));
        QObject::connect(xSlider, SIGNAL(valueChanged(int)), widget_4, SLOT(setXRotation(int)));
        QObject::connect(ySlider, SIGNAL(valueChanged(int)), widget_4, SLOT(setYRotation(int)));
        QObject::connect(widget_4, SIGNAL(xRotationChanged(int)), xSlider, SLOT(setValue(int)));
        QObject::connect(zSlider, SIGNAL(valueChanged(int)), widget_4, SLOT(setZRotation(int)));
        QObject::connect(zoomslider, SIGNAL(valueChanged(int)), widget_4, SLOT(setzoom(int)));
        QObject::connect(zoomslider, SIGNAL(valueChanged(int)), zoomval, SLOT(setNum(int)));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "QT_COP290_Engineering Drawing", Q_NULLPTR));
        actionImport_Ortho->setText(QApplication::translate("MainWindow", "Import Ortho", Q_NULLPTR));
        actionImport_3D_Model->setText(QApplication::translate("MainWindow", "Import 3D Model", Q_NULLPTR));
        actionExport_Ortho->setText(QApplication::translate("MainWindow", "Export Ortho", Q_NULLPTR));
        actionExport_3D_Model->setText(QApplication::translate("MainWindow", "Export 3D Model", Q_NULLPTR));
        action3D_to_Orthp->setText(QApplication::translate("MainWindow", "3D Model", Q_NULLPTR));
        actionImport->setText(QApplication::translate("MainWindow", "Import", Q_NULLPTR));
        actionExport->setText(QApplication::translate("MainWindow", "Export", Q_NULLPTR));
        action3D_Model->setText(QApplication::translate("MainWindow", "3D Model", Q_NULLPTR));
        actionOrthographic_projection->setText(QApplication::translate("MainWindow", "Orthographic projection", Q_NULLPTR));
        action3D_Model_2->setText(QApplication::translate("MainWindow", "3D Model", Q_NULLPTR));
        actionOrthograhic_projection->setText(QApplication::translate("MainWindow", "Orthograhic projection", Q_NULLPTR));
        actionCapture_snapshot->setText(QApplication::translate("MainWindow", "Capture snapshot", Q_NULLPTR));
        actionSave->setText(QApplication::translate("MainWindow", "Save", Q_NULLPTR));
        action3D_Model_3->setText(QApplication::translate("MainWindow", "3D Model", Q_NULLPTR));
        actionOrthographic_Projections->setText(QApplication::translate("MainWindow", "Orthographic Projections", Q_NULLPTR));
        actionIsometric_View->setText(QApplication::translate("MainWindow", "Isometric View", Q_NULLPTR));
        actionPerspective_View->setText(QApplication::translate("MainWindow", "Perspective View", Q_NULLPTR));
        actionSectional_View->setText(QApplication::translate("MainWindow", "Sectional View", Q_NULLPTR));
        actionOrthographic_Projection->setText(QApplication::translate("MainWindow", "Orthographic Projection", Q_NULLPTR));
        actionComplete_Model->setText(QApplication::translate("MainWindow", "Complete Model", Q_NULLPTR));
        actionComplete_Model_2->setText(QApplication::translate("MainWindow", "Complete Model", Q_NULLPTR));
        actionComplete_Model_3->setText(QApplication::translate("MainWindow", "Complete Model", Q_NULLPTR));
        actionAbout_this_software->setText(QApplication::translate("MainWindow", "About this software", Q_NULLPTR));
        actionAbout_Qt->setText(QApplication::translate("MainWindow", "About Qt", Q_NULLPTR));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", Q_NULLPTR));
        actionChange_background_color->setText(QApplication::translate("MainWindow", "Change background color", Q_NULLPTR));
        actionDocumentation->setText(QApplication::translate("MainWindow", "Documentation", Q_NULLPTR));
        actionContact_developers->setText(QApplication::translate("MainWindow", "Contact developers", Q_NULLPTR));
        actionSolid_View->setText(QApplication::translate("MainWindow", "Solid View", Q_NULLPTR));
        actionWireframe_View->setText(QApplication::translate("MainWindow", "Wireframe View", Q_NULLPTR));
        actionCreate_new_wireframe->setText(QApplication::translate("MainWindow", "Create new wireframe", Q_NULLPTR));
        actionAdd_on_wireframe->setText(QApplication::translate("MainWindow", "Add on wireframe", Q_NULLPTR));
        RotateObject->setText(QApplication::translate("MainWindow", "Rotate Object:", Q_NULLPTR));
        theta_2->setText(QApplication::translate("MainWindow", "theta", Q_NULLPTR));
        valTheta->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        alpha_2->setText(QApplication::translate("MainWindow", "alpha", Q_NULLPTR));
        valAlpha->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        beta_2->setText(QApplication::translate("MainWindow", "beta", Q_NULLPTR));
        valBeta->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        TranslateObject->setText(QApplication::translate("MainWindow", "Translate Origin:", Q_NULLPTR));
        X_2->setText(QApplication::translate("MainWindow", "X:", Q_NULLPTR));
        valX->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        Y_2->setText(QApplication::translate("MainWindow", "Y:", Q_NULLPTR));
        valY->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        Z_2->setText(QApplication::translate("MainWindow", "Z:", Q_NULLPTR));
        valZ->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        SacleObject->setText(QApplication::translate("MainWindow", "Scale Object:", Q_NULLPTR));
        ScaleFactor->setText(QApplication::translate("MainWindow", "Scale Factor:", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Add Edge: (Press Space to fix point)", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Current X:", Q_NULLPTR));
        xcurr->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Current Y:", Q_NULLPTR));
        ycurr->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Current Z:", Q_NULLPTR));
        zcurr->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        initial->setText(QApplication::translate("MainWindow", "Inital Edge Point", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "Commands:", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Y++, Y-- : W, S", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "X++, X-- : D, A", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "Z++, Z-- : L, O", Q_NULLPTR));
        checkBox->setText(QApplication::translate("MainWindow", "Reconstruct Planes (Required for hidden lines)", Q_NULLPTR));
        UpdateModel->setText(QApplication::translate("MainWindow", "Update Model", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "About this software", Q_NULLPTR));
        AboutQt->setText(QApplication::translate("MainWindow", "About Qt", Q_NULLPTR));
        quitButton->setText(QApplication::translate("MainWindow", "Quit", Q_NULLPTR));
        Developed->setText(QApplication::translate("MainWindow", "Developed by:", Q_NULLPTR));
        names->setText(QApplication::translate("MainWindow", "Shreshth Tuli, Sankalan Pal Chaowdhury", Q_NULLPTR));
        label_17->setText(QApplication::translate("MainWindow", "Front View", Q_NULLPTR));
        label_18->setText(QApplication::translate("MainWindow", "Top View", Q_NULLPTR));
        label_19->setText(QApplication::translate("MainWindow", "Left Side View", Q_NULLPTR));
        x->setText(QApplication::translate("MainWindow", "X", Q_NULLPTR));
        xRotVal->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        y->setText(QApplication::translate("MainWindow", "Y", Q_NULLPTR));
        yRotVal->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        z->setText(QApplication::translate("MainWindow", "Z", Q_NULLPTR));
        zRotVal->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        zoom->setText(QApplication::translate("MainWindow", "+", Q_NULLPTR));
        zoomval->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
        menuOpen_File->setTitle(QApplication::translate("MainWindow", "Open File", Q_NULLPTR));
        menuSave_As->setTitle(QApplication::translate("MainWindow", "Save As...", Q_NULLPTR));
        menuCovert->setTitle(QApplication::translate("MainWindow", "Convert to", Q_NULLPTR));
        menuView->setTitle(QApplication::translate("MainWindow", "View-2D", Q_NULLPTR));
        menuAbout->setTitle(QApplication::translate("MainWindow", "About", Q_NULLPTR));
        menuPreferences->setTitle(QApplication::translate("MainWindow", "Preferences", Q_NULLPTR));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", Q_NULLPTR));
        menuView_3D->setTitle(QApplication::translate("MainWindow", "View-3D", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
