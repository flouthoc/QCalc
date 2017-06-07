#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
     QPoint oldPos;

protected:
    void mousePressEvent(QMouseEvent *evt);
    void mouseMoveEvent(QMouseEvent *evt);

private slots:
    void push_button_pressed();
    void push_clear_pressed();
    void push_operation_pressed();
    void push_equals_pressed();
    void close_button_pressed();

};

#endif // MAINWINDOW_H
