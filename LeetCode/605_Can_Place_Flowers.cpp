class Solution 
{
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) 
    {
        int size = 0;
        for(int i=0; i<flowerbed.size(); i++)
        {
            if(flowerbed[i] == 1) continue;
            try{
                if(flowerbed[i+1] == 0 && flowerbed[i-1] == 0)
                {
                size++;
                }
            }catch(Exception e){
                size++;
            }
            
        }

        if(size >= n) return true;
        else return false;
    }
};