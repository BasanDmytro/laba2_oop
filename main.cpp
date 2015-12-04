//
//  main.cpp
//  laba2_OOP
//
//  Created by Дима Басан on 04.12.15.
//  Copyright © 2015 Дима Басан. All rights reserved.
//

#include <iostream>
#include "Queue.hpp"
#include <fstream>
using namespace std;

int main(int argc, const char * argv[]) {
    cout<<"Добрый день! В данной программе демонстрируется работа с очередью с приоритетами."<<endl;
    cout<<"Создаем очередь №1, с которой вы сможете работать и после показа тестовой программы"<<endl;
    int n=1;
    Queue *qtest=new Queue[n];
    int countforqueue=1;
    
    cout<<"Заполняем очередь №1"<<endl;
    Element e1[10];
    for (int i=0; i<10; i++) {
        e1[i].data=random()%20;
        e1[i].priority=random()%20;
    }
    qtest[1].Remove();
    for(int i=0;i<10;i++)
    {
        qtest[1].Add(*(e1+i));
    }
    cout<<"Создаем очередь №2, которая предназначена для демонстрации работы псевдопеременных"<<endl;
    Queue qforpsevdo;
    cout<<"Заполняем очередь №2"<<endl;
    qforpsevdo.Remove();
    Element eforpsevdo[10];
    
    for (int i=0; i<10; i++) {
        eforpsevdo[i].data=random()%20;
        eforpsevdo[i].priority=random()%20;
    }
    for(int i=0;i<10;i++)
    {
        qforpsevdo.Add(*(eforpsevdo+i));
    }
    cout<<"Выводим очередь №1"<<endl;
    qtest[1].PrintWithPriority();
    cout<<endl<<endl;
    cout<<"Выводим очередь №2"<<endl;
    qforpsevdo.PrintWithPriority();
    cout<<endl<<endl;
    cout<<"Демонстрация работы псевдопеременных"<<endl;
    
    
    qtest[1](0,2)=5;
    qtest[1](3,4)=qforpsevdo;
    
    
    
    cout<<"Выводим результат после псевдопеременных"<<endl;
    cout<<endl;
    qtest[1].PrintWithPriority();
    cout<<endl<<endl;
    
    cout<<"Присваиваем первой очереди второй"<<endl;
    
    qtest[1]=qforpsevdo;
    qtest[1].PrintWithPriority();
    cout<<endl<<endl;
    cout<<"Удаляем очередь, которая предназначена для демонстрации работы псевдопеременных"<<endl;
    qforpsevdo.~Queue();
    cout<<endl<<endl;
    
    
    char key=10;
    
    int *countfordeletnull=new int[1];
    countfordeletnull[1]=1;
    Element elementone;
    
    while (key!=0)
    {
        
        cout<<"Если вы хотите добавить элемент в очередь, нажмите клавишу < a >"<<endl;
        cout<<"Если вы хотите напечатать очередь, нажмите клавишу < p >"<<endl;
        cout<<"Если вы хотите очистить очередь, нажмите клавишу < c >"<<endl;
        cout<<"Если вы хотите удалить элемент с очереди, нажмите клавишу < d >"<<endl;
        cout<<"Если вы хотите загрузить элементы очереди с файла, нажмите клавишу < f >"<<endl;
        cout<<"Если вы хотите сохранить элементы очереди в файл, нажмите клавишу < s >"<<endl;
        cout<<"Если вы хотите создать очередь, нажимите клавишу < o >"<<endl;
        cout<<"Если вы хотите выйти с программы, нажмите клавиишу < e >"<<endl;
        cin>>key;
        switch (key) {
                
                
            case 'o':
            {
                countforqueue++;
                if(countforqueue>n)
                {
                    Queue *queueforcopy= new Queue[n++];
                    for(int i=1;i<n;i++)
                    {
                        for(int j=0;j<qtest[i].GetCount();j++)
                        {
                            queueforcopy[i].q[j].data=qtest[i].q[j].data;
                            queueforcopy[i].q[j].priority=qtest[i].q[j].priority;
                        }
                    }
                    for(int i=1;i<n;i++)
                    {
                        qtest[i].~Queue();
                    }
                    
                    Queue *qtest=new Queue[n];
                    
                    for(int i=1;i<n;i++)
                    {
                        for(int j=0;j<queueforcopy[i].GetCount();j++)
                        {
                            qtest[i].q[j].data=queueforcopy[i].q[j].data;
                            qtest[i].q[j].priority=queueforcopy[i].q[j].priority;
                        }
                        
                    }
                    for(int i=1;i<n;i++)
                    {
                        queueforcopy[i].~Queue();
                    }
                    
                    
                }
                
                
                qtest[countforqueue].Remove();
                
                break;
            }
            case 'd':
            {
                int countford=0;
                cout<<endl<<endl;
                cout<<"Введите номер очереди, с которой вы желаете удалить элемент: "<<endl;
                cin>>countford;
                qtest[countford].Remove();
                break;
            }
            case 'p':
            {
                
                int countforp=0;
                cout<<endl<<endl;
                cout<<"Введите номер очереди, которую вы желаете вывести на экран: "<<endl;
                cin>>countforp;
                if(countforp>n )
                {
                    cout<<("Вы еще не создали осередь под номером №")<<countforp<<endl<<endl;
                    break;
                }
                qtest[countforp].PrintWithPriority();
                break;
            }
            case 'a':
            {
                //int kk=0;
                int countfora=0;
                cout<<endl<<endl;
                cout<<"Введите номер очереди, в которую вы желаете добавить элемент: "<<endl;
                cin>>countfora;
                cout<<endl;
                cout<<"Введите данные и приоритет через пробел"<<endl;
                cin>>elementone.data>>elementone.priority;
                //kk++;
                qtest[countfora].Add(elementone);
                break;
            }
            case 'e':
            {
                for(int i=0;i<countforqueue;i++)
                {
                    qtest[countforqueue].~Queue();
                }
                exit(0);
                break;
            }
            case 'c':
            {
                int countforc=0;
                cout<<endl<<endl;
                cout<<"Введите номер очереди, которую вы желаете очистить: "<<endl;
                cin>>countforc;
                qtest[countforc].Clear();
                break;
            }
            case 'f':
            {
                int countforf=0;
                cout<<endl<<endl;
                cout<<"Введите номер очереди, в которую вы желаете загрузть элементы с файла: "<<endl;
                cin>>countforf;
                qtest[countforf].AddFromFile();
                break;
            }
            case 's':
            {
                int countfors=0;
                cout<<endl<<endl;
                cout<<"Введите номер очереди, которую вы желаете сохранить в файл: "<<endl;
                cin>>countfors;
                int countfordelet=0;
                
                countfordelet=qtest[countfors].GetCount();
                
                int count=qtest[countfors].GetCount();
                
                qtest[countfors].SaveToFile(count,countfors);
                break;
            }
                
        }
        
    }
    
    
    
    return 0;
}
