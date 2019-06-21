#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QFile>

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
    void load_number( int num);
    void add_loaded_num();
    void on_pushButton_2_clicked();


    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

signals:
   void number_loaded(int num);

private:
    Ui::MainWindow *ui;
    int sum;
    QFile *file;
    //{1,2,3,4,5,6,7,8,9};
    int currentIndex = 0;
     QVector<int> nums;
     QTimer *timer;
     void readNUmsFromFile();
};

#endif // MAINWINDOW_H
