#include <vector>
#include <iostream>

#include<QtGui>

using namespace std;
enum Shape{
    Circle,
    Triangle
};

struct Color{
    int r;
    int b;
    int g;
};

struct Data{
    int x;
    int y;
    int x2;
    int x3;
    int y2;
    int y3;

    Color color;
};

class Node;

struct Edge{
    int weight;
    int node;
};

class Node{
public:
    Data data;
    Shape shape;
    vector <Edge> edges;
    int n;

    Node(){
        data.color.r=0;
        data.color.b=0;
        data.color.g=0;
    }

    void setPos(int x,int y){
        data.x=x;
        data.y=y;
    }

    void setColor(Color c){
        data.color=c;
    }
};
