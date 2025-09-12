class Solution {
public:
    bool doesAliceWin(string s) {
        int count = 0;

        for(int i=0;i<s.length();i++){
            char ch = s[i];
            if( ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') count++;
        }

        if(count == 0) return false; //contains no vowel hence Alice can't remove any substring containing odd vowels

        else return true; //Alice removes substring containing odd vowels hence there left odd vowel substring (even - odd = odd), now bob can remove substring containing substring containing even vowel substring hence there left odd vowel containing string (odd - even = odd), now Alice will remove whole string because it contains odd vowels and bob can't remove anything next

    }
};