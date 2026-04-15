class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        
        if(words[startIndex] == target) return 0;
        int n = words.size();

        int left = (startIndex - 1 + n)%n;
        int right = (startIndex + 1) %n;
        int distance = 1;

        while(1){
            
            if(left == right && words[left] != target) return -1;

            if(words[left] == target || words[right] == target) return distance;
            
            left = (left - 1 + n) % n;
            right = (right + 1) % n;
            distance++;
        }
    }
};