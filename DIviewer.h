#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include  <QMainWindow>
#include  <QLabel>
#include  <QScrollArea>
#include  <QImage>
#include  <QDialog>
#include  <QAction>
#include  <QtPrintSupport/QPrinter>
#include  <QMenu>
#include  <QMenuBar>
#include  <QMessageBox>
#include  <QScrollBar>
#include  <QFileDialog>
#include  <QString>
#include  <QtPrintSupport/QPrintDialog>


#include "dcmtk/config/arith.h"
#include "dcmtk/config/osconfig.h"
#include "dcmtk/dcmdata/cmdlnarg.h"
#include "dcmtk/dcmdata/dcbytstr.h"
#include "dcmtk/dcmdata/dcchrstr.h"
#include "dcmtk/dcmdata/dccodec.h"
#include "dcmtk/dcmdata/dcdatset.h"





class QAction;
class QLabel;
class QMenu;
class QScrollArea;
class QScrollBar;

 class DIviewer : public QMainWindow
 {
     Q_OBJECT

 public:
     DIviewer();

 private slots:
     void open();
//     void saveAs();
     void print();
//     void copy();
//     void paste();
     void zoomIn();
     void zoomOut();
     void normalSize();
     void fitToWindow();
     void about();

 private:
     void createActions();
     void createMenus();
     void updateActions();
     bool saveFile(const QString &fileName);
     void setImage(const QImage &newImage);
     void scaleImage(double factor);
     void adjustScrollBar(QScrollBar *scrollBar, double factor);


     QImage image;
     QLabel *imageLabel;
     QScrollArea *scrollArea;
     double scaleFactor;

 #ifndef QT_NO_PRINTER
     QPrinter printer;
 #endif

     QAction *openAct;
     QAction *saveAsAct;
     QAction *printAct;
     QAction *copyAct;
     QAction *exitAct;
     QAction *zoomInAct;
     QAction *zoomOutAct;
     QAction *normalSizeAct;
     QAction *fitToWindowAct;
     QAction *aboutAct;
     QAction *aboutQtAct;

     QMenu *fileMenu;
     QMenu *viewMenu;
     QMenu *helpMenu;
 };

 #endif

