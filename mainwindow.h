#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QGraphicsScene>
#include <QtGui>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QPixmap image;
    QImage* image_obj;
    QGraphicsScene* scene;
    QString imagePath;
    QFileInfo image_name;

public:
    void DisplayImage();
    void DisplayImageData(QImage image);
};

#endif // MAINWINDOW_H
