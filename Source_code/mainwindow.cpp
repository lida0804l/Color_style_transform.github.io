#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    input = 0;
//    image = new QImage();

    scene = new LidaScene();
    pixmap_item = new QGraphicsPixmapItem();
    this->setWindowTitle("RGB Tone Curve Specification");

    QLabel *Name = new QLabel(this);
    Name->setText("by Ethan(Li-Ta) Chen");
    ui->statusbar->addPermanentWidget(Name);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionLoad_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(NULL, "Load Image", 0, "Image Files(*.jpg *.bmp *.png *tif)");
    if(!(fileName.isNull())){
        if(input != 0){
            delete input;
            cout << "image contained" << endl;
        }
        QImage* image = new QImage();
        image->load(fileName);
    //    scene->image = image;
        *image = image->convertToFormat(QImage::Format_RGB888);
        input = MainWindow::QImage2LidaImage(image);
        MainWindow::showImage(image);
        delete image;
    }
}

LidaImage *MainWindow::QImage2LidaImage(QImage *input)
{
    LidaImage* output = new LidaImage(input->height(), input->width());
    for (int x = 0; x < input->height(); x++) {
        for (int y = 0; y < input->width(); y++) {
            int r = input->pixelColor(y,x).red();
            int g = input->pixelColor(y,x).green();
            int b = input->pixelColor(y,x).blue();
            output->matrix3D[0][x][y] = r;
            output->matrix3D[1][x][y] = g;
            output->matrix3D[2][x][y] = b;
        }
    }
    return output;
}

QImage *MainWindow::LidaImage2QImage(LidaImage *input)
{
    QImage* output = new QImage(input->col, input->row, QImage::Format_RGB888);
    for (int x = 0; x < output->height(); x++) {
        for (int y = 0; y < output->width(); y++) {
            int r = input->matrix3D[0][x][y];
            int g = input->matrix3D[1][x][y];
            int b = input->matrix3D[2][x][y];
            output->setPixel(y,x,qRgb(r,g,b));
        }
    }
    return output;
}

void MainWindow::showImage(QImage *imageDisplay)
{
    pixmap_item->setPixmap(QPixmap::fromImage(*imageDisplay));

    QList<QGraphicsItem *> itemList = scene->items();
    if(itemList.contains(pixmap_item))
    {
        scene->removeItem(pixmap_item);
    }
    scene->pixmap_item = pixmap_item;
    scene->addItem(pixmap_item);
    scene->setSceneRect(pixmap_item->boundingRect());
    ui->graphicsView->setScene(scene);
}

void MainWindow::on_actionHistogram_specification_triggered()
{
//    LidaImage* input = LIDA::QImage2LidaImage(image);
//    LidaImage* output = IntensityTransformation::histogram_equalization(input);
//    LidaImage* output = IntensityTransformation::histogram_specification(input);
    LidaImage* output = IntensityTransformation::histogram_specification_rgb(input);
//    LidaImage* output = IntensityTransformation::fuzzy(input);

    output->scaling(LidaImage::cutoff);

    delete input;
    input = output;
    QImage* result = MainWindow::LidaImage2QImage(output);
    MainWindow::showImage(result);
//    QString savepath = QFileDialog::getSaveFileName(this, tr("Save File"), NULL, tr("jpg (*.jpg);; bmp (*.bmp);; png (*.png)"));
//    result->save(savepath);
//    delete result;
}

void MainWindow::on_actionSave_as_triggered()
{
    QImage* result = MainWindow::LidaImage2QImage(input);
    QString savepath = QFileDialog::getSaveFileName(this, tr("Save File"), NULL, tr("jpg (*.jpg);; bmp (*.bmp);; png (*.png)"));
    result->save(savepath);
    delete result;
}
