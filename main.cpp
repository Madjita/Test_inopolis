#include <QCoreApplication>
#include <QTime>
#include <QDebug>
#include <iostream>

qint64 Multiplications_max3(QList<int> mass)
{
    std::sort(mass.begin(),mass.end());

    for(int i=0;i < mass.count();i++)
    {
        qDebug () << mass.value(i);
    }

    qint64 aMax1 = mass.value(mass.count()-1);
    qint64 aMin = mass.value(0);
    qint64 aMin2 = mass.value(1);

    qint64 aMax2 = mass.value(mass.count()-2);
    qint64 aMax3 = mass.value(mass.count()-3);

    qint64 x =  aMax1 * aMin * aMin2;

    qint64 y =  aMax1 * aMax2 * aMax3;


    qDebug () << "X = " << mass.value(mass.count()-1) <<" * "<<mass.value(0) << " * "<< mass.value(1) <<" = " << x;
    qDebug () << "Y = " << mass.value(mass.count()-1) <<" * "<<mass.value(mass.count()-2) << " * "<< mass.value(mass.count()-3) <<" = " << y;

    if(x > y)
    {
        return x;
    }
    else
    {

        return y;
    }

}

int findCountBacteria(QList<int> mass)
{
    int countBacteria = 0;

    QString bit = QString::number(mass.last(),2);

    for(int i=0;i<bit.count();i++)
    {
        if(bit[i] =="1")
        {
            countBacteria++;
        }
    }

    return countBacteria;
}



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug () << "=======Task 1===========";

    QTime midnight(0,0,0);
    qsrand(static_cast<unsigned int>(midnight.secsTo(QTime::currentTime())));

    QList<int> mass ;   //= {-8 ,-7 ,-6, 1 , 2 , 3 };

    for(int i=0;i < qrand()% 100;i++)
    {
        mass.append(qrand() %  20001 - 10000);

        qDebug () << mass.last();
    }

    qDebug () << "==========Sort============";
    qDebug () << "MAX = " << Multiplications_max3(mass);
    qDebug () << "=======Task 1===========";

    mass.clear();

    for(int i=0;i < qrand() % 100;i++)
    {
        int add = 0;

        if(mass.isEmpty())
        {
            mass.append(1);

            add++;
        }
        else
        {
            add = qrand() % 2 - 0;
            mass.append(mass.last()*2 + add);
        }


        qDebug () << mass.last() << "\t " << add;
    }

    qDebug () << "Add bacteria for all time = "<< findCountBacteria(mass);

    system("pause");

    return 0;
}
