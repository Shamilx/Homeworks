#include <algorithm>
#include <iostream> 
#include <vector> 
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> Temp{};
        vector<int> test;
        int count2 = 0;
        
        bool deletee = false;
        
        if(nums.size() < 3)
        {
            return Temp;
        }
        if(nums.empty()) 
        {
            return Temp;
        }
        
        int size  = nums.size();

        for(int i = 0;i < size;i++)
        {
            for(int j = i + 1;j < size;j++)
            {
                for(int x = j + 1;x < size;x++)
                {

                                
                    if((nums[i] + nums[j] + nums[x]) == 0)
                    {

                            test.push_back(nums[i]);
                            test.push_back(nums[j]);
                            test.push_back(nums[x]);
                            
                            for(int d = 0;d < Temp.size();d++)
                            {
                                for(int f = 0;f < 3;f++)
                                {
                                    for(int g = 0;g < 3;g++)
                                    {
                                        if(Temp[d][f] == test[g])
                                        {
                                            count2++;
                                        }
                                    }
                                }
                            }
                            
                            if(count2 >= 3)
                            {
                               test.clear();
                               count2 = 0;
                               continue;
                            }
                            
                            cout << "PUSHED : " << test[0] << endl;
                            cout << "PUSHED : " << test[1] << endl;
                            cout << "PUSHED : " << test[2] << endl;
                            cout << endl;
                            Temp.push_back(test);
                            test.clear();


                    }
                }
            }
        }
        
        return Temp;
    }
};

int main()
{
    Solution obj1;
    vector<int> a = {3,0,-2,-1,1,2};
    obj1.threeSum(a);
}
