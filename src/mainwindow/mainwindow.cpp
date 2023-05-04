#include "./mainwindow.h"
#include "../canvas/canvas.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    Canvas *canvas = new Canvas(this);
    this->ui->canvasLayout->addWidget(canvas);
    canvas->setFocus();
    this->setWindowTitle(tr("Опыт Резерфорда"));
}

MainWindow::~MainWindow() { delete ui; }
