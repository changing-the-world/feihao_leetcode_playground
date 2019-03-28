//
// Created by Feihao on 2019/3/28.
//

#ifndef CPPS_LEETCODE850_H
#define CPPS_LEETCODE850_H
bool cmp1(pair<int,int>a,pair<int,int>b)
{
    return a.first < b.first;
}
class Solution {


public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        int64_t accum = 0;
        vector<pair<int, int>> hor_idx;
        vector<pair<int, int>> ver_idx;
        set<int> actset;
        set<int>::iterator it;
        for(int i =0; i< rectangles.size(); i++){

            hor_idx.push_back(make_pair(rectangles[i][0], i));
            hor_idx.push_back(make_pair(rectangles[i][2], i));
            ver_idx.push_back(make_pair(rectangles[i][1], i + 1));
            ver_idx.push_back(make_pair(rectangles[i][3], -1 * i - 1));
        }
        cout << "1\n";
        sort(hor_idx.begin(), hor_idx.end(), cmp1);
        sort(ver_idx.begin(), ver_idx.end(), cmp1);
        cout << "2\n";
        for(int i = 0; i< hor_idx.size() - 1; i++){
            cout << "3\n";
            it = actset.find(hor_idx[i].second);
            if(it == actset.end())
                actset.insert(hor_idx[i].second);
            else
                actset.erase(it);
            int delta_loc = hor_idx[i+1].first - hor_idx[i].first;
            if(delta_loc > 0 && actset.size()>0){
                int total_y_range = 0;
                int stack = 0;
                int start_ver = 0;
                for(int j=0; j<ver_idx.size(); j++){
                    cout << "4\n";
                    int true_idx = ver_idx[j].second > 0? ver_idx[j].second: -1 * ver_idx[j].second;
                    if(actset.find(true_idx - 1) != actset.end()){
                        if (stack == 0){
                            start_ver = ver_idx[j].first;
                        }
                        stack += ver_idx[j].second;
                        if(stack ==0){
                            total_y_range += ver_idx[j].first - start_ver;
                        }
                    }
                }
                cout << "xdelta: " << delta_loc << "; ydelta: "<<total_y_range << endl;
                accum += ((int64_t)delta_loc) * ((int64_t)total_y_range);
            }
        }
        return accum % (1000000000 + 7);
    }
};

int run(){
    //[[0,0,2,2],[1,0,2,3],[1,0,3,1]]
//    vector<int> r1= {0,0,2,2};
//    vector<int> r2 ={1,0,2,3};
//    vector<int> r3 ={1,0,3,1};
//    vector<vector<int>> rall = {r1, r2, r3};

    vector<vector<int>> rall = {{0,0,1000000000, 1000000000}};

    int res = Solution().rectangleArea(rall);
    cout<<"res "<<res<<endl;
    return 0;
}


#endif //CPPS_LEETCODE850_H
