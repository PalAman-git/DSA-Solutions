class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int totalDrinks = numBottles; // drink all initial bottles
        int emptyBottles = numBottles;

        while (emptyBottles >= numExchange) {
            int newFullBottles = emptyBottles / numExchange;   // bottles you can get
            int remainingEmptyBottles = emptyBottles % numExchange; // leftover
            totalDrinks += newFullBottles;  // drink them
            emptyBottles = newFullBottles + remainingEmptyBottles; // update empties
        }

        return totalDrinks;
    }
};