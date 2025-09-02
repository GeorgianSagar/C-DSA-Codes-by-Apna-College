We have used two Data Structures - Queue and Unordered Map
we will perform the following operations :
I) Traverse the Complete String (Storing the frequency)
   1) We will check our Map if the character already exists or not
       a) If the Character doesn't exist we will push it into our Queue (its index not the actual characters) 
       b) If the Character does exist we will move to the next character 
       - After both an and b we will increment the frequency of the character in our map.

II) we will now traverse the front of the Queue we have created which have the first occurrence of each character in index form and check its frequency in our map
  a) If the frequency of front is greater than 1, we will pop the front element and traverse the next front
  b) If the frequency of front is 1 we will move out of the loop and return the index of that element.

If at last we don't have any element left in the queue we will return -1.


class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int>m;
        queue<int> Q;

        for(int i=0; i<s.size(); i++){
            if(m.find(s[i]) == m.end()){
                Q.push(i);
            }
            m[s[i]]++;

            while(Q.size() > 0 && m[s[Q.front()]] > 1){
                Q.pop();
            }
        }
        return Q.empty() ? -1: Q.front();
    }
};