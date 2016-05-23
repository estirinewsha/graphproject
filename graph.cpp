#include"graph.h"
#include"cmath"
int Graph::mx(){
    int max=nodes[0]->data.x;
    for(int i=1;i<nodes.size();i++){
        if(max<nodes[i]->data.x){
            max=nodes[i]->data.x;
        }
    }
    return max;
}


int Graph::my(){
    int max=nodes[0]->data.y;
    for(int i=1;i<nodes.size();i++){
        if(max<nodes[i]->data.y){
            max=nodes[i]->data.y;
        }
    }
    return max;
}
void Graph::load(QString Filename){
        qDebug() <<"ok";
        qDebug() <<Filename;
       QFile MyFile(Filename);
       QTextStream in(&MyFile);
       QString MyText;
       QString t1,t2;

         if(!MyFile.open(QFile::ReadOnly | QFile::Text)) {
        qDebug() << "could not open file for reading"; return;
        }
        t1 = in.readLine();
        qDebug() <<t1;
        do {
            t1+=t2;
            t2 = in.readLine();
        }while(t2!="}");
        t1+=t2;
        qDebug() <<t1;
        MyText=t1;


        qDebug() << MyText;
        int i,j;
        int num;
    int counter=-1;
    bool flag=true;
        for(i=0;i<MyText.size();i++){
        if(MyText[i]=='{'){
            j=i+1;
            break;}
           }
    do{
        if(counter%2==1){
        i++;
        j++;}
        counter++;

        if(flag){
        flag=false;
        i++;}
        else {
        j++;
        flag=true;}
            num=MyText.mid(i,1).toInt();
            qDebug() << "\n"<<"num="<<num;
            i+=2;
            QCharRef type=MyText[i];
            qDebug() << "\n"<<"type="<<type;
        if(type=='c'){
            CircleNode*example=new CircleNode;
            i+=2;
                for(j=i;j<MyText.size();j++){
                    if(MyText[j]==',')break;
                }
                example->data.x=MyText.mid(i,j-i).toInt();
                qDebug() << "\n"<<"x"<<example->data.x;
                j++;
                for(i=j;i<MyText.size();i++){
                        if(MyText[i]==',')break;
                }
                example->data.y=MyText.mid(j,i-j).toInt();
                qDebug() << "\n"<<"y"<<example->data.y;
                i++;
                for(j=i;j<MyText.size();j++){
                        if(MyText[j]==',')break;
                }
                example->data.color.r=MyText.mid(i,j-i).toInt();
                qDebug() << "\n"<<"r"<<example->data.color.r;
                j++;
                for(i=j;i<MyText.size();i++){
                        if(MyText[i]==',')break;
                }
                example->data.color.g=MyText.mid(j,i-j).toInt();
                qDebug() << "\n"<<"g"<<example->data.color.g;
                i++;
                for(j=i;j<MyText.size();j++){
                  if(MyText[j]==',')break;
                }
                example->data.color.b=MyText.mid(i,j-i).toInt();
                qDebug() << "\n"<<"b"<<example->data.color.b;
                int k=0;
                while (MyText[j]!=';') {
                   j++;
                   for(i=j;i<MyText.size();i++){
                        if(MyText[i]=='-')break;
                    }
                   Edge e;
                    int n=MyText.mid(j,i-j).toInt();
                    qDebug() << "\n"<<n;
                    e.node=n;
                    //qDebug() << "\n"<<"k"<<k<<",,";
                    i++;
                    for(j=i;j<MyText.size();j++){
                        if(MyText[j]==','||MyText[j]==';')break;
                    }
                    e.weight=MyText.mid(i,j-i).toInt();
                    qDebug() << "\n"<<"weight="<<e.weight;
                    example->edges.push_back(e);
                    k++;
                }
            if(flag){
            j+=2;}
            else{
            i+=2;}
            nodes.push_back(example);
        }
        else{

            TriangleNode*node=new TriangleNode;
            i+=2;
                for(j=i;j<MyText.size();j++){
                    if(MyText[j]==',')break;
                }
                node->data.x=MyText.mid(i,j-i).toInt();

                j++;
                for(i=j;i<MyText.size();i++){
                        if(MyText[i]==',')break;
                }
                node->data.y=MyText.mid(j,i-j).toInt();
                i++;
                for(j=i;j<MyText.size();j++){
                        if(MyText[j]==',')break;
                }
                node->data.color.r=MyText.mid(i,j-i).toInt();
                j++;
                for(i=j;i<MyText.size();i++){
                        if(MyText[i]==',')break;
                }
                node->data.color.g=MyText.mid(j,i-j).toInt();
                i++;
                for(j=i;j<MyText.size();j++){
                  if(MyText[j]==',')break;
                }
                node->data.color.b=MyText.mid(i,j-i).toInt();
                int k=0;
                while (MyText[j]!=';') {
                   j++;
                   Edge e;
                    for(i=j;i<MyText.size();i++){
                        if(MyText[i]=='-')break;
                    }
                    int n=MyText.mid(j,i-j).toInt();
                    e.node=n;
                    i++;
                    for(j=i;j<MyText.size();j++){
                        if(MyText[j]==','||MyText[j]==';')break;
                    }
                    e.weight=MyText.mid(i,j-i).toInt();
                    node->edges.push_back(e);
                    k++;
                }
            if(flag){
            j+=2;}
            else{
            i+=2;}
            nodes.push_back(node);
        }
    }while(j<MyText.size()-2&&j<MyText.size()-2);
        MyFile.close();

    }
