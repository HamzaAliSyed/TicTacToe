#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     setupUI();
}

void MainWindow::aiMove()
{
     if (findBestMove(true)) return;

     if (findBestMove(false)) return;

     if (buttons[1][1]->text().isEmpty()) {
         buttons[1][1]->click();
         return;
     }

     int corners[4][2] = {{0,0}, {0,2}, {2,0}, {2,2}};
     for (auto corner : corners) {
         if (buttons[corner[0]][corner[1]]->text().isEmpty()) {
             buttons[corner[0]][corner[1]]->click();
             return;
         }
     }

     for (int i = 0; i < 3; i++) {
         for (int j = 0; j < 3; j++) {
             if (buttons[i][j]->text().isEmpty()) {
                 buttons[i][j]->click();
                 return;
             }
         }
     }
}

bool MainWindow::findBestMove(bool forAI)
{
    QString symbol = forAI ? "O" : "X";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (buttons[i][j]->text().isEmpty()) {
                buttons[i][j]->setText(symbol);
                if (checkWin()) {
                    buttons[i][j]->setText("");
                    buttons[i][j]->click();
                    return true;
                }
                buttons[i][j]->setText("");
            }
        }
    }
    return false;
}

void MainWindow::setupUI()
{
    QGridLayout* layout = new QGridLayout();
    layout->setSpacing(10);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            buttons[i][j] = new QPushButton();
            buttons[i][j]->setFixedSize(100, 100);
            buttons[i][j]->setFont(QFont("Arial", 40));
            layout->addWidget(buttons[i][j], i, j);
        }
    }

    QWidget* gameWidget = new QWidget();
    gameWidget->setLayout(layout);
    gameWidget->setStyleSheet("border: 2px solid black;");

    turnLabel = new QLabel("Player's turn");
    turnLabel->setAlignment(Qt::AlignCenter);
    turnLabel->setFont(QFont("Arial", 16));

    QVBoxLayout* mainLayout = new QVBoxLayout();
    mainLayout->addWidget(gameWidget);
    mainLayout->addWidget(turnLabel);

    QWidget* centralWidget = new QWidget();
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            connect(buttons[i][j], &QPushButton::clicked, this, &MainWindow::onButtonClicked);
        }
    }
    playerTurn = true;

    setFixedSize(sizeHint());

    restartButton = new QPushButton("Restart Game");
    restartButton->setFont(QFont("Arial", 14));
    restartButton->setVisible(false);
    connect(restartButton, &QPushButton::clicked, this, &MainWindow::restartGame);

    mainLayout->addWidget(restartButton);
}

void MainWindow::onButtonClicked() {
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (button && button->text().isEmpty()) {
        if (playerTurn) {
            button->setText("X");
            turnLabel->setText("AI's turn");
        } else {
            button->setText("O");
            turnLabel->setText("Player's turn");
        }
        button->setEnabled(false);

        if (checkWin()) {
            turnLabel->setText(playerTurn ? "Player wins!" : "AI wins!");
            disableAllButtons();
            restartButton->setVisible(true);
        } else if (isBoardFull()) {
            turnLabel->setText("It's a draw!");
            disableAllButtons();
            restartButton->setVisible(true);}
        else {
            playerTurn = !playerTurn;
            if (!playerTurn) {
                aiMove();
            }
        }
    }
}

void MainWindow::disableAllButtons() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            buttons[i][j]->setEnabled(false);
        }
    }
}

bool MainWindow::checkWin() {

    for (int i = 0; i < 3; ++i) {
        if (buttons[i][0]->text() == buttons[i][1]->text() &&
            buttons[i][1]->text() == buttons[i][2]->text() &&
            !buttons[i][0]->text().isEmpty())
            return true;

        if (buttons[0][i]->text() == buttons[1][i]->text() &&
            buttons[1][i]->text() == buttons[2][i]->text() &&
            !buttons[0][i]->text().isEmpty())
            return true;
    }

    if (buttons[0][0]->text() == buttons[1][1]->text() &&
        buttons[1][1]->text() == buttons[2][2]->text() &&
        !buttons[0][0]->text().isEmpty())
        return true;

    if (buttons[0][2]->text() == buttons[1][1]->text() &&
        buttons[1][1]->text() == buttons[2][0]->text() &&
        !buttons[0][2]->text().isEmpty())
        return true;

    return false;
}

bool MainWindow::isBoardFull() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (buttons[i][j]->text().isEmpty()) {
                return false;
            }
        }
    }
    return true;
}

void MainWindow::restartGame()
{
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            buttons[i][j]->setText("");
            buttons[i][j]->setEnabled(true);
        }
    }
    playerTurn = true;
    turnLabel->setText("Player's turn");
    restartButton->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}
