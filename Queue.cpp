//
//  Queue.cpp
//  laba2_OOP
//
//  Created by Дима Басан on 04.12.15.
//  Copyright © 2015 Дима Басан. All rights reserved.
//

#include "Queue.hpp"
#include <fstream>
Element elementtwo;
Queue::Queue()
{
    first = EMPTY;
};

Queue::Queue(Queue& queue)
{
    for(int i=0;i<queue.GetCount();i++)
    {
        q[i].data=queue.q[i].data;
        q[i].priority=queue.q[i].priority;
        first=queue.first;
    }
}

Queue::Queue(int dataforconstr,short prioritetforconstr)
{
    Element elementforconstr;
    elementforconstr.data=dataforconstr;
    elementforconstr.priority=prioritetforconstr;
    Add(elementforconstr);
}

void Queue::Add(const Element elem)
{
    int i;
    
    // поиск позиции
    for(i = first; i >= 0; i--)
        if(q[i].priority > elem.priority)
            break;
    // Если очередь заполнена, удалить элемент с меньшим приоритетом
    if(IsFull())
    {
        if(i != -1)
        {
            for(int j = 0; j < i; j++)
                q[j] = q[j + 1];
            
            q[i] = elem;
        }
    }
    else
    {
        for(int j = first; j > i; j--)
            q[j + 1] = q[j];
        
        q[i + 1] = elem;
        first++;
    }
    
}

int Queue::GetCount()
{
    return first + 1;
}

Element Queue::Remove()
{
    if(IsEmpty())
        return Element();
    int temp1=9999;
    int temp2=0;
    for (int i=0; i<GetCount(); i++) {
        if(q[i].priority<temp1)
        {
            temp1=q[i].priority;
            temp2=i;
        }
    }
    for(int i=temp2;i<GetCount()-1;i++)
    {
        q[i]=q[i+1];
    }
    
    return q[first--];
}



void Queue::Clear()
{
    first = EMPTY;
}

void Queue::AddFromFile()
{
    ifstream fin;
    fin.open("/Users/admin/Desktop/C++/laba2_OOP/laba2_OOP/1.txt");
    while (!fin.eof())
    {
        fin>>elementtwo.data;
        fin>>elementtwo.priority;
        Add(elementtwo);
    }
    fin.close();
}

void Queue::SaveToFile(int count,int nameforfile)
{
    ofstream fout;
    
    char namefileforsave[51]="/Users/admin/Desktop/C++/laba2_OOP/laba2_OOP/";
    char str[2];
    str[0] =nameforfile+'0';
    str[1]=0;
    char a[5]=".txt";
    fout.open(strcat(namefileforsave, strcat(str, a)));
    
    for(int i=0;i<count;i++)
    {
        
        fout<<q[i].data;
        fout<<" ";
        fout<<q[i].priority;
        fout<<endl;
    }
    fout.close();
}

Queue& Queue::operator->()
{
    return *this;
}

Queue::Queue(Queue&qq,Queue&p,int countforcopy)
{
    for(int i=0; i<countforcopy;i++)
    {
        p.q[i].data=qq.q[i].data;
        p.q[i].priority=qq.q[i].priority;
    }
};

ostream& operator << (std::ostream& os, Queue& queue) {
    return os << queue;
}

istream& operator >>(istream& is, Queue& queue) {
    Element elementforoperator;
    is>>elementforoperator.data;
    is>>elementforoperator.priority;
    queue.Add(elementforoperator);
    return is;
}

int& Queue::operator[](int index)
{
    return ((int*)this)[index];
}

Queue & Queue::operator=(Queue  queueforcopy1)
{
    
    int k1=(*this).GetCount();
    int k2=queueforcopy1.GetCount();
    if (k2<k1) {
        k1=k2;
    }
    
    for(int i=0;i<k1;i++)
    {
        q[i].data=queueforcopy1.q[i].data;
        q[i].priority=queueforcopy1.q[i].priority;
    }
    return (*this);
    
}




