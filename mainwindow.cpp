#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     setupUI();
}

void MainWindow::setupUI()
{
    QGridLayout* layout = new QGridLayout();

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            buttons[i][j] = new QPushButton();
            layout->addWidget(buttons[i][j], i, j);
        }
    }

    QWidget* centralWidget = new QWidget();
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            connect(buttons[i][j], &QPushButton::clicked, this, &MainWindow::onButtonClicked);
        }
    }
}

void MainWindow::onButtonClicked()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (button) {
        button->setText("X");
        button->setEnabled(false);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
