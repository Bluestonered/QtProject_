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

#include "ViewProject.h"
#include "QGraphicsRectItem"


MainWindow::MainWindow(QString projectName, QFile file): fileo(file.fileName()) {

    StartWindow* p = new StartWindow();
    setFixedSize(712, 512);
    setWindowTitle(projectName);

    SlotModel slotmodel;
    SlotController slotcontroller(slotmodel);
    slotcontroller.UpdateProject(file, slotmodel);

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

    const int tailleGrille = 5;
    const int tailleCellule = 95;

    auto *scene = new QGraphicsScene();
    auto *view = new MyGraphicsView();
    view->setScene(scene);
    view->setFixedSize(500, 500);



    //Juste les cellules
    for (int row = 0; row < tailleGrille; row++) {
        for (int col = 0; col < tailleGrille; col++) {
            QRectF rect(col * tailleCellule, row * tailleCellule, tailleCellule, tailleCellule);
            QGraphicsRectItem *cell = new QGraphicsRectItem(rect);
            cell->setBrush(QBrush(Qt::darkGreen));
            scene->addItem(cell);

            if (row == 1 && col == 1) {
                //cell->setBrush(QBrush(Qt::red));
            }
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