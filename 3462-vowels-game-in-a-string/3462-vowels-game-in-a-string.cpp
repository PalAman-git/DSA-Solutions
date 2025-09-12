class Solution {
public:
    bool doesAliceWin(string s) {
        int count = 0;

        for(int i=0;i<s.length();i++){
            char ch = s[i];
            if( ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') count++;
        }

        if(count == 0) return false; //contains no vowel hence Alice can't remove any substring containing odd vowels

        else return true; //if there is string containing odd cound of vowel then Alice will remove the entire string and bob would not be able to remove anything next so Alice will win the game, if the count of vowel in string is even then Alice will remove the odd vowel count substring , the remaining would contain odd count vowels as even - odd = odd. next bob have to remove substring containg even count vowel substring which would leave behind odd count vowel substring as odd - even = odd. Then alice will remove the entire string and will win.

    }
};