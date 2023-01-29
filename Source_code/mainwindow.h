#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <iostream>
#include <lidaimage.h>
#include <lidascene.h>
#include <intensitytransformation.h>

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
    void on_actionLoad_triggered();

    void on_actionHistogram_specification_triggered();

    void on_actionSave_as_triggered();

private:
    Ui::MainWindow *ui;

    LidaImage* input;

    LidaScene* scene;
    QGraphicsPixmapItem* pixmap_item;

    //FourierTransform* freq;

    static LidaImage* QImage2LidaImage(QImage* input);
    static QImage* LidaImage2QImage(LidaImage* input);
    void showImage(QImage* imageDisplay);
};
#endif // MAINWINDOW_H
