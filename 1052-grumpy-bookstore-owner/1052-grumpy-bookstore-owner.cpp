class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int i=0,j=0;

        int unsatisfiedCustomers = 0;
        int maxUnsatisfiedCustomers = 0;

        int totalSatisfiedCustomers = 0;

        for(int i=0;i<n;i++){
            if(grumpy[i] == 0)
                totalSatisfiedCustomers += customers[i];
        }

        while(j<n){
            //add the unsatisfied Customer
            if(grumpy[j] == 1){
                unsatisfiedCustomers += customers[j];
            }
            

            if(j-i+1 < minutes){
                j++;
            }
            else if(j-i+1 == minutes){
                //do the calculation
                maxUnsatisfiedCustomers = max(maxUnsatisfiedCustomers,unsatisfiedCustomers);

                //remove the ith
                if(grumpy[i] == 1){
                    unsatisfiedCustomers -= customers[i];
                }

                i++;
                j++;
            }
        }

        return totalSatisfiedCustomers + maxUnsatisfiedCustomers;
    }
};