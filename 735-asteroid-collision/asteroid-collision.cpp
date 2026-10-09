class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        vector<int> ans;
        stack <int> pos;      

        for(int i = 0; i < n; i++){
            if(asteroids[i] < 0){
                bool equal = false;
                while(!pos.empty() && pos.top() <= abs(asteroids[i])){
                    int pos_top = pos.top();
                    pos.pop();
                    if(pos_top == abs(asteroids[i])){
                        equal = true;
                        break;
                    }
                }
                if(pos.empty() && !equal) ans.push_back(asteroids[i]);
            }

            else pos.push(asteroids[i]);
        }

        vector <int> temp;
        while(!pos.empty()){
            temp.push_back(pos.top());
            pos.pop();
        }

        for(int i = temp.size()-1; i >= 0; i--) ans.push_back(temp[i]);

        return ans;
    }
};