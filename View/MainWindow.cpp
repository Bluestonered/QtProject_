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
#include <QLabel>
#include "QGraphicsRectItem"
#include "iostream"
#include <QDialog>
#include <QDir>

#include <vector>
#include <utility>


MainWindow::MainWindow(QString projectName, QFile file): fileo(file.fileName()) {

    StartWindow* p = new StartWindow();
    setFixedSize(712, 512);
    setWindowTitle(projectName);

    auto *scene = new QGraphicsScene();
    auto *view = new MyGraphicsView();

    SlotModel slotModel;
    SlotController slotController(slotModel);
    slotModel = slotController.InitProject(file);

    file.close();




// Création de la barre de menu
    QMenuBar *menuBar = new QMenuBar(this);
    QMenu *BaseMenu = menuBar->addMenu("File");
    QAction *action1 = new QAction("New", this);
    QAction *action2 = new QAction("Open", this);
    QMenu *ProjectMenu = menuBar->addMenu("Project");
    QAction *actionA = new QAction("Save", this);
    QAction *actionB = new QAction("Run", this);
    BaseMenu->addAction(action1);
    BaseMenu->addAction(action2);
    ProjectMenu->addAction(actionA);
    ProjectMenu->addAction(actionB);

    connect(actionB, &QAction::triggered, [this]() {

        QDialog *dialog = new QDialog(this);
        dialog->setFixedSize(300, 150);
        dialog->setWindowTitle("Désolé!");
        QLabel *label = new QLabel(dialog);
        label->setText("On ne peut pas lancer le projet pour le moment, \n j'implémenterais une fenêtre faite en SDL pour \n pouvoir jouer la scène! promis!");
        QPushButton *buttonClose = new QPushButton(dialog);
        buttonClose->setText("Close");
        buttonClose->move(110, 90);
        connect(buttonClose, &QPushButton::clicked, dialog, &QDialog::close);
        dialog->exec();
    });

    connect(actionA, &QAction::triggered, [this]() {

        QDialog *dialog = new QDialog(this);
        dialog->setFixedSize(300, 150);
        dialog->setWindowTitle("Save");
        QLabel *label = new QLabel(dialog);
        label->setText("Projet sauvegardé avec succès\n(ne fonctionne pas malheureusement)");
        QPushButton *buttonClose = new QPushButton(dialog);
        buttonClose->setText("Close");
        buttonClose->move(110, 90);
        connect(buttonClose, &QPushButton::clicked, dialog, &QDialog::close);
        dialog->exec();
    });
    connect(action1, &QAction::triggered, p, &StartWindow::onButton1Clicked);
    connect(action2, &QAction::triggered, p, &StartWindow::onButton2Clicked);



    // Création du layout principal
    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    mainLayout->addWidget(menuBar);
    setLayout(mainLayout);

    QPushButton *buttonSol = new QPushButton("Herbe");
    QPushButton *buttonRocher = new QPushButton("Rocher");
    QPushButton *buttonEau = new QPushButton("eau");
    QPushButton *buttonSable = new QPushButton("sable");
    QVBoxLayout *leftLayout = new QVBoxLayout;
    leftLayout->addWidget(buttonSol);
    leftLayout->addWidget(buttonRocher);
    leftLayout->addWidget(buttonEau);
    leftLayout->addWidget(buttonSable);
    leftLayout->setAlignment(Qt::AlignLeft);
    leftLayout->setAlignment(Qt::AlignCenter);
    mainLayout->addLayout(leftLayout);



    const int tailleGrille = 5;
    const int tailleCellule = 95;


    view->setScene(scene);
    view->setFixedSize(500, 500);



    connect(buttonSol, &QPushButton::clicked, [view](){
        view->setColorSelect(0);

        std::cout<< view->getColorSelect() << std::endl;
    });
    connect(buttonRocher, &QPushButton::clicked, [view, slotController, slotModel](){
        view->setColorSelect(1);
        std::cout<< view->getColorSelect() << std::endl;
    });
    connect(buttonEau, &QPushButton::clicked, [view, slotController, slotModel](){
        view->setColorSelect(2);
        std::cout<< view->getColorSelect() << std::endl;
    });
    connect(buttonSable, &QPushButton::clicked, [view, slotController, slotModel](){
        view->setColorSelect(3);
        std::cout<< view->getColorSelect() << std::endl;
    });

    QObject::connect(view, &MyGraphicsView::cellClicked, [projectName, view](int row, int col) {
        //slotController.SetCellVal(row, col, slotModel, colorSelect); //Ce que j'aurais aimé faire pour que ça marche mais ça veux pas donc je pleure

        QFile file(QDir::homePath() + "/Documents/ProjectQT/" + projectName);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            std::cout << "Impossible d'ouvrir le fichier." << std::endl;
            return; // sortir de la fonction
        }

        SlotModel model;
        SlotController controller(model);
        model = controller.InitProject(file);
        controller.SetCellVal(row, col, model, view->getColorSelect());
        controller.UpdateProject(file,model);

    });

    //Juste les cellules
    for (int row = 0; row < tailleGrille; row++) {
        for (int col = 0; col < tailleGrille; col++) {
            QRectF rect(col * tailleCellule, row * tailleCellule, tailleCellule, tailleCellule);
            QGraphicsRectItem *cell = new QGraphicsRectItem(rect);
            int x = atoi(&slotModel.SlotData[col][row][4]);
            switch (x) {
                case 0:
                    cell->setBrush(QBrush(Qt::darkGreen));
                    break;
                case 1:
                    cell->setBrush(QBrush(Qt::darkGray));
                    break;
                case 2:
                    cell->setBrush(QBrush(Qt::darkBlue));
                    break;
                case 3:
                    cell->setBrush(QBrush(Qt::darkYellow));
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