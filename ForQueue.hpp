//
//  ForQueue.hpp
//  laba2_OOP
//
//  Created by Дима Басан on 04.12.15.
//  Copyright © 2015 Дима Басан. All rights reserved.
//

#ifndef ForQueue_hpp
#define ForQueue_hpp
struct Element
{
    int data;
    short priority;
};

class ForQueue
{
    
    //private:
public:
    enum {EMPTY = -1, FULL = 999};
    
    // Массив элементов
    Element q[FULL + 1];
    int first;
    
    void PrintWithPriority();
    bool IsEmpty();
    bool IsFull();
};

#endif /* ForQueue_hpp */
