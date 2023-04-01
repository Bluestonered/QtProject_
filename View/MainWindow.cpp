//
// Created by blue on 18/03/23.
//
#include "MainWindow.h"
#include <QMenuBar>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QTextStream>
#include <QPushButton>
#include <QDebug>
#include "MyGraphicsView.h"
#include <QBrush>
#include "StartWindow.h"
#include "../Controller/SlotController.h"
#include "../Model/SlotModel.h"
#include <QPen>
#include <QWidget>
#include <QGraphicsView>

#include "QGraphicsRectItem"
#include "iostream"


MainWindow::MainWindow(QString projectName, QFile file): fileo(file.fileName()) {

    StartWindow* p = new StartWindow();
    setFixedSize(712, 512);
    setWindowTitle(projectName);

    auto *scene = new QGraphicsScene();
    auto *view = new MyGraphicsView();

    SlotModel *slotModel = new SlotModel();
    SlotController slotController(*slotModel);
    slotController.UpdateProject(file, *slotModel);

    QObject::connect(view, &MyGraphicsView::cellClicked, [&slotController, slotModel](int row, int col) {
        std::cout << slotModel->SlotData.size() << std::endl;
        slotController.SetCellVal(col, row, *slotModel, 1);
    });

// Création de la barre de menu
    QMenuBar *menuBar = new QMenuBar(this);
    QMenu *characMenu = menuBar->addMenu("File");
    QAction *action1 = new QAction("New", this);
    QAction *action2 = new QAction("Open", this);
    characMenu->addAction(action1);
    characMenu->addAction(action2);

    connect(action1, &QAction::triggered, p, &StartWindow::onButton1Clicked);
    connect(action2, &QAction::triggered, p, &StartWindow::onButton2Clicked);



    // Création du layout principal
    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    mainLayout->addWidget(menuBar);
    setLayout(mainLayout);

    QPushButton *button1 = new QPushButton("Sol");
    QPushButton *button2 = new QPushButton("Rocher");
    QVBoxLayout *leftLayout = new QVBoxLayout;
    leftLayout->addWidget(button1);
    leftLayout->addWidget(button2);
    mainLayout->addLayout(leftLayout);



    const int tailleGrille = 5;
    const int tailleCellule = 95;


    view->setScene(scene);
    view->setFixedSize(500, 500);

    connect(button1, &QPushButton::clicked, [view](){
        view->setColorSelect(1);

        std::cout<< view->getColorSelect() << std::endl;
    });
    connect(button2, &QPushButton::clicked, [view, slotController, slotModel](){
        view->setColorSelect(2);
        std::cout<< view->getColorSelect() << std::endl;
    });

    //Juste les cellules
    for (int row = 0; row < tailleGrille; row++) {
        for (int col = 0; col < tailleGrille; col++) {
            QRectF rect(col * tailleCellule, row * tailleCellule, tailleCellule, tailleCellule);
            QGraphicsRectItem *cell = new QGraphicsRectItem(rect);
            int x = atoi(&slotModel->SlotData[col][row][4]);
            switch (x) {
                case 0:
                    cell->setBrush(QBrush(Qt::darkGreen));
                    break;
                case 1:
                    cell->setBrush(QBrush(Qt::darkGray));
                    break;
                case 2:
                    cell->setBrush(QBrush(Qt::darkRed));
                    break;
                default:
                    cell->setBrush(QBrush(Qt::darkGreen));
                    break;
            }
            scene->addItem(cell);
        }
    }

    // grille qui sépare les cellules pour rendre ça tout beau
    for (int i = 0; i <= tailleGrille; i++) {
        scene->addLine(i * tailleCellule, 0, i * tailleCellule, tailleCellule * tailleGrille, QPen(Qt::black));
        scene->addLine(0, i * tailleCellule, tailleCellule * tailleGrille, i * tailleCellule, QPen(Qt::black));
    }



    mainLayout->addWidget(view);
    setLayout(mainLayout);

}

MainWindow::~MainWindow() {

}