#include "addcategorydialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    addCategoryDialog w;
    w.show();
    
    return a.exec();
}
