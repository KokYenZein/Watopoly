#include "ownableProperty.h"


OwnableProperty::OwnableProperty(std::string name, std::string id, int cost, int improvementCost, std::vector<int> tuition, int position, bool isGym, bool isResidence, int propertiesInSet): 
    BoardPiece{name, id, cost, improvementCost, tuition, position, isGym, isResidence, propertiesInSet, true}{}

bool OwnableProperty::mortgage(Player* p){
    if(!this->mortgaged && this->improvementTier == 0 && p == this->ownedPlayer){
        int morgageMoney = this->cost/2;
        p->addMoney(morgageMoney);
        this->mortgaged = true;
    }
    return false;
}

bool OwnableProperty::unmortgage(Player* p){
    if(this->mortgaged && p == this->ownedPlayer){
        int morgageMoney = this->cost*0.6;
        //player gets money withdrawed
        if(p->getMoney() >= morgageMoney){
            p->subtractMoney(morgageMoney);
            this->mortgaged = false;
            return true;
        }
    }
    return false;
}

bool OwnableProperty::improve(Player* p){
    if(p == this->ownedPlayer){
        std::vector<BoardPiece*> properties = p->getProperties();
        int sameIdCount = 1;
        for(auto & i : properties){
            if(i->getId() == this->id){
                sameIdCount++;
            }
        }
        if(sameIdCount == this->propertiesInSet && p->getMoney() >= this->improvementCost){
            p->subtractMoney(this->improvementCost);
            this->improvementTier++;
            return true;
        }
    }  
    return false;
}

bool OwnableProperty::sellImprovement(Player* p){
    if(p == this->ownedPlayer && this->improvementTier > 0){
        int refund = this->improvementCost/2;
        p->addMoney(refund);
        this->improvementTier--;
        return true;
    }
    return false;
}


void OwnableProperty::landedOn(Player* p){
    if(owned && !mortgaged){
        this->tuitionPaid = true;
        int tuitionRequired = 0;
        //determine the cost of tuition
        //if there are improvements
        if(this->improvementTier > 0){
            tuitionRequired = tuition[this->improvementTier];
        }
        //if there are no improvements, check if full set is owned
        else{
            std::vector<BoardPiece*> properties = this->ownedPlayer->getProperties();
            int sameIdCount = 1;
            for(auto & i : properties){
                if(i->getId() == this->id){
                    sameIdCount++;
                }
            }
            if(sameIdCount == this->propertiesInSet){
                tuitionRequired = tuition[0]*2;
            }
            else{
                tuitionRequired = tuition[0];
            }
        }
        //exchange tuition
        if(p->getMoney() >= tuitionRequired){
            p->subtractMoney(tuitionRequired);
            ownedPlayer->addMoney(tuitionRequired);
            this->tuitionPaid = true;
        }
        else{
            //Game class should allow Player to make enough money to pay, or bankrupt 
            this->tuitionPaid = false;
        }
        
    }
    else if(owned && !mortgaged){
        std::cout << "This property is mortgaged" << std::endl;
    }
    else if(!owned){
        std::cout << "Would you like to purchase " << this->getName() << " for $" << this->getPrice() << "? (y/n)" << std::endl;
        char input;
        try{
            std::cin >> input;
        }
        catch(...){}
        if(input == 'y'){
            if(p->getMoney() >= this->cost){
                p->addProperty(this);
                this->owned = true;
                this->ownedPlayer = p;
                std::cout << "Purchased" << std::endl;
            }
            else{
                std::cout << "You do not have enough money to purchase this property" << std::endl;
                //Game class will enter an auction
            }
        }
    }
}

OwnableProperty::~OwnableProperty(){}
