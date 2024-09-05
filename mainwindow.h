#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    //QString characters = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/|()1{}[]?-_+~<>i!lI;:,^`'. ";
    QString characters = "@#%*=-:. ";

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void addText(QChar str);
    QChar getCharacter(float r, float g, float b);
    void convertImage();
protected:
    void keyPressEvent(QKeyEvent *event);

private slots:
    void on_btnChoose_clicked();
    void on_btnConvert_clicked();

    void on_btnConvert_2_clicked();

    void on_btnInverse_clicked();

private:
    Ui::MainWindow *ui;
    QImage image;
    bool converted = false;
    QString convertedText;
    int imageWidth, imageHeight;
};
#endif // MAINWINDOW_H
