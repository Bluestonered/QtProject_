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


MainWindow::MainWindow(QString projectName, QFile file): fileo(file.fileName()) {

    StartWindow* p = new StartWindow();
    setFixedSize(712, 512);
    setWindowTitle(projectName);

    SlotModel a;
    SlotController r(a);

// Création de la barre de menu
    QMenuBar *menuBar = new QMenuBar(this);
    QMenu *characMenu = menuBar->addMenu("File");
    QAction *action1 = new QAction("New", this);
    QAction *action2 = new QAction("Open", this);
    characMenu->addAction(action1);
    characMenu->addAction(action2);

    connect(action1, &QAction::triggered, p, &StartWindow::onButton1Clicked);
    connect(action2, &QAction::triggered, p, &StartWindow::onButton2Clicked);



    // Création du QTextEdit
/*    QTextEdit *textEdit = new QTextEdit(this);*/

    // Création du QPushButton
/*    QPushButton *button = new QPushButton("save", this);*/

    // Création du layout principal
    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    mainLayout->addWidget(menuBar);
/*    mainLayout->addWidget(textEdit);
    mainLayout->addWidget(button);  // Ajout du bouton au layout principal*/
    setLayout(mainLayout);

/*    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
       QString text = in.readAll();
        textEdit->setText(text);
        file.close();
    }*/

    auto *b = new QGraphicsScene();
    auto *c = new MyGraphicsView();
    c->setScene(b);
    c->setFixedSize(500,500);
    b->addRect(0,0,1,1, QColor(255,255,255,255));
    mainLayout->addWidget(c);
    setLayout(mainLayout);

    // Connexion du signal clicked() du bouton à une fonction lambda
/*    connect(button, &QPushButton::clicked, [=]() {
        if (fileo.open(QIODevice::WriteOnly | QIODevice::Text)) {
            fileo.write(textEdit->toPlainText().toUtf8());
            fileo.close();
        }
    });*/
}

MainWindow::~MainWindow() {

}