#include <vector>
#include <string>

#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QGridLayout>
#include <QObject>

#include "calc.h"

int main(int argc, char **argv)
{


 QApplication app (argc, argv);

 BinaryExpression expression;

 QWidget w;
 QGridLayout *gridWin = new QGridLayout(&w);

 QWidget ops, nums, display;
 QGridLayout *gridOps = new QGridLayout(&ops);
 QGridLayout *gridNum = new QGridLayout(&nums);



 QPushButton add("+",&ops), dif("-",&ops), div(":",&ops), mul("x",&ops), get("=",&ops);
 
 QObject::connect(&add, &QPushButton::clicked, [&expression]() { expression.SetOp(ADD);      expression.SetBuffer(2);});
 QObject::connect(&mul, &QPushButton::clicked, [&expression]() { expression.SetOp(MULTIPLY); expression.SetBuffer(2);});
 QObject::connect(&dif, &QPushButton::clicked, [&expression]() { expression.SetOp(SUBTRACT); expression.SetBuffer(2);});
 QObject::connect(&div, &QPushButton::clicked, [&expression]() { expression.SetOp(DIVIDE);   expression.SetBuffer(2);});
 QObject::connect(&get, &QPushButton::clicked, [&expression]() { expression.DoOp();    expression.Print();});
 
 
 
 gridOps->addWidget (&add, 0, 0, 1, 1);
 gridOps->addWidget (&dif, 0, 1, 1, 1);
 gridOps->addWidget (&div, 1, 0, 1, 1);
 gridOps->addWidget (&mul, 1, 1, 1, 1);
 gridOps->addWidget (&get, 2, 1, 1, 1);


 std::vector<QPushButton* > numsBtn;
 for (int i=0; i<10; i++)
 {
  numsBtn.push_back( new  QPushButton (QString::number(i),&nums)  );
  QObject::connect(numsBtn[i], &QPushButton::clicked, [&expression,i]() { expression.UpdateBuffer(i); });
  gridNum->addWidget( numsBtn[i],i/3,i%3,1,1);
 }

 gridWin->addWidget (&ops,  1, 0, 1, 1);
 gridWin->addWidget (&nums, 1, 1, 1, 1);
 //gridWin->addWidget (&display, 0,0,2,1);
 w.show();



 return app.exec();
}
