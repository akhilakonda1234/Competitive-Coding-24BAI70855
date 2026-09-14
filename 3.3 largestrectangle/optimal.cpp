#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int largestRectangle(vector<int>& heights)
{
    stack<int> st;
    int maxArea = 0;
    for(int i = 0; i <= heights.size(); i++)
    {
        int currentHeight;
        if(i == heights.size())
            currentHeight = 0;
        else
            currentHeight = heights[i];
        while(!st.empty() && currentHeight < heights[st.top()])
        {
            int height = heights[st.top()];
            st.pop();
            int width;
            if(st.empty())
                width = i;
            else
                width = i - st.top() - 1;
            int area = height * width;
            if(area > maxArea)
                maxArea = area;
        }
        st.push(i);
    }
    return maxArea;
}
int main()
{
    int n;
    cout << "Enter number of bars: ";
    cin >> n;
    vector<int> heights(n);
    cout << "Enter heights: ";
    for(int i = 0; i < n; i++)
        cin >> heights[i];
    cout << "Largest Rectangle Area = "
         << largestRectangle(heights) << endl;
    return 0;
}
