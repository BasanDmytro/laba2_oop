//
//  ForQueue.cpp
//  laba2_OOP
//
//  Created by Дима Басан on 04.12.15.
//  Copyright © 2015 Дима Басан. All rights reserved.
//
#include <iostream>
#include "ForQueue.hpp"

bool ForQueue::IsEmpty()
{
    return first == EMPTY;
}

bool ForQueue::IsFull()
{
    return first == FULL;
}
void ForQueue::PrintWithPriority()
{
    if(IsEmpty())
        return;
    
    for(int i = first; i >= 0; i--)
        std::cout << q[i].data <<", pr: "
        <<q[i].priority <<"\t";
    
    std::cout << std::endl;
    
}