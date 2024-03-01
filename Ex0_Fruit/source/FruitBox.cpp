#include "FruitBox.hpp"

FruitBox::FruitBox(int size)    :   _sizeBox(size),
                                    _nbFruits(0),
                                    _headFruitNode(nullptr)
{}

// FruitBox::FruitBox(const FruitBox& rhs) :   _sizeBox(rhs._sizeBox),
//                                             _nbFruits(rhs._nbFruits),
//                                             _headFruitNode(rhs._headFruitNode)
// {}

FruitBox::~FruitBox(void)
{
    delete _headFruitNode;
}

// FruitBox        &FruitBox::operator=(const FruitBox& rhs)
// {
//     if (this != &rhs)
//     {
//         _sizeBox = rhs._sizeBox;
//         _nbFruits = rhs._nbFruits;
//         _headFruitNode = rhs._headFruitNode;
//     }
//     return *this;
// }

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

bool            FruitBox::putFruit(Fruit *f)
{
    if (f == nullptr)
        return false;
    else
    {
        if (_nbFruits < _sizeBox)
        {
            FruitNode *tempFruitNode = _headFruitNode;
            if (tempFruitNode != nullptr)
            {
                while (tempFruitNode != nullptr)
                {
                    if (tempFruitNode->fruit == f)
                        return false;
                    tempFruitNode = tempFruitNode->next;
                }
            }
           /* 1. create and allocate node And create a lastFruitNode which is equal to _head*/
            FruitNode *newFruitNode = new FruitNode();  // I dont understand if i have to use  
                                                                // new FruitNode[_sizeBox];
                                                                // or new FruitNode();
                                                                // or new FruitNode[sizeof(FruitNode)];
            FruitNode *lastFruitNode = _headFruitNode; /* used in step 5*/
    
            /* 2. assign data to the new node */
            newFruitNode->fruit = f;
    
            /* 3. set next pointer of new node to null as its the last node*/
            newFruitNode->next = nullptr;
    
            /* 4. if list is empty, new node becomes first node */
            if (_headFruitNode == nullptr)
            {
                _headFruitNode = newFruitNode;
                _nbFruits++;
                return true;
            }
    
            /* 5. Else traverse till the last node */
            while (lastFruitNode->next != nullptr)
                lastFruitNode = lastFruitNode->next;
    
            /* 6. Change the next of last node */
            lastFruitNode->next = newFruitNode;

            // increment the nb fruit after add nodee
            _nbFruits++;
            return true;
        }
        else
            return false;
    }
}

Fruit           *FruitBox::pickFruit(void)
{
    if (_nbFruits <= 0 || _headFruitNode == nullptr)
        return nullptr;
    FruitNode *currentFruitNode = _headFruitNode;

    // Remove the first node from the list
    Fruit *fruit = currentFruitNode->fruit;
    _headFruitNode = currentFruitNode->next;
    currentFruitNode = nullptr;
    delete currentFruitNode;
    _nbFruits--;
    return fruit;
}

void FruitBox::displayList(FruitNode *node)
{
   //traverse the list to display each node
   std::cerr << "FruitBox[";
   while (node != NULL)
   {
      std::cerr << node->fruit->getName()<<"-->";
      node = node->next;
   }

    if(node== NULL)
        std::cerr<<"nullptr]" << std::endl;
}