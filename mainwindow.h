#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onButtonClicked();
    bool checkWin();

private:
    Ui::MainWindow *ui;
    QPushButton* buttons[3][3];
    void setupUI();
    bool playerTurn;
    QLabel* turnLabel;
    void aiMove();
    bool findBestMove(bool forAI);
    bool isBoardFull();
    void disableAllButtons();
    QPushButton* restartButton;
    void restartGame();
};

#endif // MAINWINDOW_H
