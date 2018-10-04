#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QGraphicsView>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QImage>
#include <QListView>
#include <QListWidgetItem>
#include <QStringList>
#include <QTextBrowser>


MainWindow::MainWindow(QWidget *parent) :  QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MainWindow::setWindowTitle("Image Info");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    imagePath = QFileDialog::getOpenFileName(this, tr("Open File"), tr("JPEG (*.jpg *.jpeg);;PNG (*.png)"));
    DisplayImage();
    DisplayImageData(*image_obj);
}

void MainWindow::DisplayImage()
{
    image_obj = new QImage();
    image_obj->load(imagePath);
    image = QPixmap::fromImage(*image_obj);
    scene = new QGraphicsScene(this);
    scene->addPixmap(image);
    scene->setSceneRect(image.rect());
    ui->graphicsView->setScene(scene);
    ui->graphicsView->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
}

void MainWindow::DisplayImageData(QImage image)
{
    long long img_size = 0;

    ui->textBrowser->clear();
    //image.bitPlaneCount();
    QString bitCount = QString::number(image.bitPlaneCount());
    QString bits = QString::number(*image.bits());
    QString bytes_per_line = QString::number(image.bytesPerLine());
    QFileInfo image_name = imagePath;
    QFile file_size(imagePath);
    img_size = file_size.size();
    QString size = QString::number(img_size);
    QString name = image_name.fileName();
    MainWindow::setWindowTitle(name);
    QString cache_key = QString::number(image.cacheKey());
    QString image_color = QString::number(image.colorCount());
    QString image_depth = QString::number(image.depth());
    QString image_height = QString::number(image.height());
    QString image_width = QString::number(image.width());
    QString device_pixel_ratio = QString::number(image.devicePixelRatio());
    QString dots_per_meter_X = QString::number(image.dotsPerMeterX());
    QString dots_per_meter_Y = QString::number(image.dotsPerMeterY());
    QString image_format = QString::number(image.format());
    //bool hasAlpha = image.hasAlphaChannel();
    //QString image_alpha = QString::number(hasAlpha);


    ui->textBrowser->setPlainText("Name: " + name + "\n"
                                  + "Source: " + imagePath + "\n"
                                  + "Height: " + image_height + "\n"
                                  + "Width: " + image_width + "\n"
                                  + "Size: " + size + " bytes" +"\n"
                                  + "Bit Count: " + bitCount + "\n"
                                  + "Bits: " + bits + "\n"
                                  + "Bytes per Line: " + bytes_per_line + "\n"
                                   + "Cache Key: " + cache_key + "\n"
                                  + "Color Count: " + image_color + "\n"
                                  + "Image Depth: " + image_depth + "\n"
                                  + "Device Pixel Ratio: " + device_pixel_ratio + "\n"
                                  + "Dots per meter X: " + dots_per_meter_X + "\n"
                                  + "Dots per meter Y: " + dots_per_meter_Y + "\n"
                                  + "Image Format: " + image_format + "\n"
                                  //+ "Alpha: " + hasAlpha + "\n"

                                  );

}

