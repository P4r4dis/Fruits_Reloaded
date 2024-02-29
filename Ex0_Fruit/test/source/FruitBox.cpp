#include "FruitBox.hpp"

FruitBox::FruitBox(int size)    :   _sizeBox(size),
                                    _nbFruits(0),
                                    _headFruitNode(nullptr)
{

}


FruitBox::~FruitBox(void)
{}

int             FruitBox::getSizeBox(void) const
{
    return _sizeBox;
}

int             FruitBox::nbFruits(void) const
{
    return _nbFruits;
}

FruitNode       *FruitBox::head(void) const
{
    if (_nbFruits == 0)
        return nullptr;
    else
        return _headFruitNode;
}

// bool            FruitBox::putFruit(Fruit *f)
// {
//     if (f == nullptr)
//         return false;
//     else
//     {
//         if (_nbFruits < _sizeBox)
//         {
//             /* 1. create and allocate node */
//                 // std::cout << "TEST" << std::endl;

//             FruitNode* newNode = new FruitNode;
//             FruitNode *last = _headFruitNode; /* used in step 5*/
    
//             /* 2. assign data to the node */
//                 // std::cout << "TEST" << std::endl;

//             newNode->fruit = f;
    
//             /* 3. set next pointer of new node to null as its the last node*/
//                 // std::cout << "TEST" << std::endl;

//             newNode->next = nullptr;
    
//             /* 4. if list is empty, new node becomes first node */
//                 // std::cout << "TEST 4" << std::endl;

//             if (_headFruitNode == nullptr)
//             {
//                 _headFruitNode = newNode;

//                 // increment the nb fruit after add nodee
//                 _nbFruits++;
//                 return true;
//             }
    
//             /* 5. Else traverse till the last node */
//             while (last->next != nullptr)
//                 last = last->next;
    
//             /* 6. Change the next of last node */
//             last->next = newNode;

//             // increment the nb fruit after add nodee
//             _nbFruits++;

//             return true;
//         }
//         else
//             return false;
//     }
// }

// void FruitBox::displayList(FruitNode *node)
// {
//    //traverse the list to display each node
//    while (node != NULL)
//    {
//       std::cerr<<node->fruit->getName()<<"-->";
//       node = node->next;
//    }

//     if(node== NULL)
//         std::cerr<<"nullptr" << std::endl;; 
// } 