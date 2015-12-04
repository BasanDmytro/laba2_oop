//
//  Queue.hpp
//  laba2_OOP
//
//  Created by Дима Басан on 04.12.15.
//  Copyright © 2015 Дима Басан. All rights reserved.
//

#ifndef Queue_hpp
#define Queue_hpp

#include <iostream>
#include "ForQueue.hpp"
using namespace std;

class Queue:public ForQueue
{
public:
    
    class ForPsevdo
    {
        
    public:
        Queue &qforpsevdo;
        int i;
        int j;
        ForPsevdo(Queue &arg,int a,int b):qforpsevdo(arg),i(a),j(b){}
        ForPsevdo(Queue &arg,int a):qforpsevdo(arg),i(a){}
        Queue & operator= (int arg)
        {
            for(int h=i;h<j;h++)
            {
                qforpsevdo.q[h].data=arg;
            }
            return qforpsevdo;
        }
        Queue & operator=(Queue queueforcopy)
        {
            for(int h=i;h<j;h++)
            {
                qforpsevdo.q[h].data=queueforcopy.q[h].data;
                qforpsevdo.q[h].priority=queueforcopy.q[h].priority;
            }
            return qforpsevdo;
        }
        
    };
    
    ForPsevdo operator()(int i,int j)
    {
        return ForPsevdo(*this,i,j);
    }
    
    ForPsevdo operator()(int i)
    {
        return ForPsevdo(*this,i);
    }
    
    Queue();
    
    Queue(Queue&);
    
    Queue(int,short);
    
    Queue(Queue&,Queue&,int countforcopy);
    
    void Add(const Element elem);
    
    void AddFromFile();
    
    void SaveToFile(int count,int nameforfile);
    
    Element Remove();
    
    int GetCount();
    
    void Clear();
    
    Queue& operator->();
    
    int& operator[](int);
    
    Queue & operator=(Queue queueforcopy);
    
};

ostream& operator <<(ostream&, Queue&);
istream& operator >>(istream&, Queue&);


#endif /* Queue_hpp */
