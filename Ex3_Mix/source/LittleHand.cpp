#include "../include/LittleHand.hpp"

LittleHand::LittleHand(void)
{}

LittleHand::~LittleHand(void)
{}

void            LittleHand::sortFruitbox(FruitBox& unsorted, FruitBox& lemons,
                                            FruitBox& bananas, FruitBox& limes)
{
    FruitNode *current = unsorted.head();
    
    while (current != nullptr)
    {
        Fruit* fruit = current->fruit;    
        bool added = false;

        if (fruit->getName() == "lemon") {
            added = lemons.putFruit(fruit);
            unsorted.pickFruit();
        }
        else if (fruit->getName() == "banana")
        {
            added = bananas.putFruit(fruit);
            unsorted.pickFruit();
        }
        else if (fruit->getName() == "lime"){
            added = limes.putFruit(fruit);
            unsorted.pickFruit();
        }
        if (!added)
            unsorted.putFruit(fruit);
        current = current->next;
    }
}

FruitBox * const *   LittleHand::organizeCoconut(Coconut const * const * coconuts)
{
    // Count the number of Coconuts
    int numCoconuts = 0;
    while (coconuts[numCoconuts] != nullptr) {
        ++numCoconuts;
    }
    // Calculate the number of FruitBoxes needed
    int numFruitBoxes = (numCoconuts / 6) + (numCoconuts % 6 != 0);

    // Allocate memory for FruitBoxes array
    FruitBox** fruitBoxes = new FruitBox*[numFruitBoxes + 1]; // +1 for the null terminator

    for (int i = 0; i < numFruitBoxes; ++i) {
        fruitBoxes[i] = new FruitBox(6);
        
        // Add 6 Coconuts to each FruitBox
        for (int j = 0; coconuts[i * 6 + j]; ++j) {
            // Add logic to add Coconut to FruitBox (Assuming addCoconut method in FruitBox)
            fruitBoxes[i]->addCoconut(coconuts[i * 6 + j]);
        }
    }
    // Add null terminator to the end of the array
    fruitBoxes[numFruitBoxes] = nullptr;

    return fruitBoxes;
}

void                 LittleHand::plugMixer(MixerBase& mixer)
{
    Mixer* myMixer = (Mixer *) &mixer;

    if (myMixer)
        myMixer->Connect();
}

void                 LittleHand::unplugMixer(MixerBase& mixer)
{
    Mixer* myMixer = (Mixer *) &mixer;

    if (myMixer)
        myMixer->disconnect();
}