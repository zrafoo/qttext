#include <QApplication>

#include "textedit.h"

 int main( int argc, char ** argv ) {
     QApplication a( argc, argv );
     Textedit mw;
     mw.resize( 1000, 400 );
     mw.show();
     return a.exec();
 }

