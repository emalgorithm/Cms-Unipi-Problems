#include <map>
#include <string.h>
#include <queue>
#include "pizza.h"

#define INF 199999999
#define NUM_ING 8
#define NUM_PIZZAS 256

using namespace std;

int order_num, ingredientsAvailable, ingredientsQuantity[NUM_ING];
queue< int > orders[NUM_PIZZAS];

void Init() {
    order_num = 0;
    ingredientsAvailable = 0;
    memset(ingredientsQuantity, 0, sizeof ingredientsQuantity);
}

void makePizza(int currentPizza){
    for(int i = 0; i < NUM_ING; i++){
        if((currentPizza & (1 << i)) != 0){
            ingredientsQuantity[i]--;
            if(ingredientsQuantity[i] == 0){
                ingredientsAvailable &= ~(1 << i);
            }
        }
    }
}

bool isBakable(int currentPizza){
    return  (currentPizza & ingredientsAvailable) == currentPizza;
}

void Order(int N, int *A) {
    int currentPizza = 0;
    for(int i = 0; i < N; i++){
        currentPizza |= (1 << A[i]);
    }

    if(isBakable(currentPizza)){
        Bake(order_num);
        makePizza(currentPizza);
    }
    else{
        orders[currentPizza].push(order_num);
    }    
    order_num++;
}

void Delivery(int I) {
    ingredientsQuantity[I]++;
    ingredientsAvailable |= (1 << I);

    int minOrder = INF;
    int pizza = -1;
    
    for(int i = 0; i < NUM_PIZZAS; i++){
        int currentPizza = i;
        if(!orders[currentPizza].empty() && isBakable(currentPizza)){
            int orderT = orders[currentPizza].front();
            if(orderT < minOrder){
                minOrder = orderT;
                pizza = currentPizza;
            }
        }
    }
    if(pizza != -1){
        orders[pizza].pop();
        Bake(minOrder);
        makePizza(pizza);
    }
}
