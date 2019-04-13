/*
Runtime: 8 ms, faster than 96.32% of C++ online submissions for Regular Expression Matching.
Memory Usage: 11.1 MB, less than 75.98% of C++ online submissions for Regular Expression Matching.
*/

class Solution {
public:
    bool isMatch(string s, string p) {
        queue<int> q;
        q.push(-1);
        for (int i = 0; i< p.length(); i++){
            queue<int> q2;
            if (q.empty())
                return false;
            if (i < p.length() - 1 and p[i+1] == '*'){
                if (p[i] == '.'){
                    int first = q.front();
                    q.pop();
                    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
                    // This convert from size_t to int ensure it works, 
                    // It should be very careful when you compare int with size_t, when int is negative
                    for(int j = first; j < (int)s.length(); j++){
                        q2.push(j);
                    }
                }else{
                    
                    int curLoc = -2;
                    while(!q.empty()){
                        int loc = q.front();
                        q.pop();
                        //q2.push(curLoc);
                        if(loc >= curLoc){
                            q2.push(loc);
                            curLoc = loc + 1;
                            while(curLoc<s.length() and s[curLoc] == p[i]){
                                q2.push(curLoc);
                                curLoc ++;
                            }
                        }
                    }
                   
                }
                i++;
            }else{
                while(!q.empty()){
                    int loc = q.front();
                    q.pop();
                    if (loc + 1 < s.length()){
                        if (p[i] == '.' || p[i] == s[loc + 1]){
                            q2.push(loc + 1);
                        } 
                    }
                }
            }
            q = q2;
        }
        while(!q.empty()){
            int loc = q.front();
            // cout<<loc<<endl;
            q.pop();
            if(loc == s.length() -1 )
                return true;
            
        }
        return false;
    }
};
