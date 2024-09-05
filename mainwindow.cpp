#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QFileDialog>
#include <QKeyEvent>
#include <numeric>
#include <future>
#include <string>
#include <mutex>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    converted = false;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
   if (event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return)
   {
       std::future<void> result( std::async([this](){convertImage();}));
       result.get();
       ui->teAscii->setPlainText(convertedText);
   }
}

void MainWindow::on_btnChoose_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Choose"), "/home", "Images (*.png *.bmp *.jpg *.jpeg)");

    if (QString::compare(filename, QString()) == 0)
        return;

    image.load(filename);
    image = image.scaled(ui->lblImage->contentsRect().size());
    ui->lblImage->setPixmap((QPixmap::fromImage(image)));
    ui->teAscii->setPlainText("");
    convertedText = "";
    converted = false;
    imageWidth = ui->lblImage->contentsRect().width();
    imageHeight = ui->lblImage->contentsRect().height();
}

void MainWindow::convertImage()
{
    if (converted)
    {
        return;
    }
    converted = true;

    if (imageWidth == 0 || imageHeight == 0)
        return;

    int asciiWidth = 69;
    int asciiHeight = 29;

    int ppwAscii = imageWidth / asciiWidth;
    int pphAscii = imageHeight / asciiHeight;

    for (int i = 0; i < imageHeight; i += pphAscii)
    {
        for (int j = 0; j < imageWidth; j += ppwAscii)
        {
            float averageR = 0;
            float averageB = 0;
            float averageG = 0;
            int pixelCount = 0;

            for (int x = i; x < std::min(imageHeight, i + pphAscii); ++x)
            {
                for (int y = j; y < std::min(imageWidth, j + ppwAscii); ++y)
                {
                    averageR += image.pixelColor(y, x).red();
                    averageG += image.pixelColor(y, x).green();
                    averageB += image.pixelColor(y, x).blue();
                    pixelCount++;
                }
            }

            averageR /= (float)pixelCount;
            averageG /= (float)pixelCount;
            averageB /= (float)pixelCount;

           convertedText += getCharacter(averageR, averageG, averageB);
        }
        convertedText += '\n';
    }
}

void MainWindow::on_btnConvert_clicked()
{
    convertImage();
    ui->teAscii->setPlainText(convertedText);
}

void MainWindow::addText(QChar str)
{
    ui->teAscii->setPlainText(ui->teAscii->toPlainText() + str);
}

QChar MainWindow::getCharacter(float r, float g, float b)
{
    float light = 0.2126 * r + 0.7152 * g + 0.0722 * b;
    float maxLight = 0.2126 * 255 + 0.7152 * 255 + 0.0722 * 255;
    int chars = characters.size();

    for (int i = 0; i + 1 < chars; ++i)
    {
        if (light <= maxLight * (float)(i + 1) / (float)chars)
            return characters[chars - 1 - i];
    }
    return characters[0];
}

void MainWindow::on_btnInverse_clicked()
{
    if (!converted)
        return;
    QString asciiArt = ui->teAscii->toPlainText();
    for (auto& i : asciiArt)
    {
        int index = -1;
        for (int j = 0; j < characters.size(); ++j)
            if (characters[j] == i)
                index = characters.size() - j - 1;
        if (index != -1)
            i = characters[index];
    }
    ui->teAscii->setPlainText(asciiArt);
}

void MainWindow::on_btnConvert_2_clicked(){}
