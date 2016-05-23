#include <QFile>
#include <QString>
#include <QCoreApplication>
#include <QDebug>
#include <QTextStream>
#include <vector>
#include <iostream>
#include <list>
//#include "node.h"
#include <fstream>
#include"circle.h"
#include"triangle.h"

using namespace std;


class Graph
{
public:
    vector <Node*> nodes;
    void load(QString Filename);
    void setPos();
    int mx();
    int my();
};
