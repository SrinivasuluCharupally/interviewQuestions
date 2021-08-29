#include<iostream>
#include<stack>
#include<vector>


using namespace std;

int largestRectangleArea(vector<int> &hist) {
    stack<int> s;
    int max_area = 0;
    int tp;
    int area_with_top;
    int i = 0;
    while (i < hist.size()) {
        if (s.empty() || hist[s.top()] <= hist[i])
            s.push(i++);
        else {
            tp = s.top();
            s.pop();
            area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);
            if (max_area < area_with_top)
                max_area = area_with_top;
        }
    }
    while (s.empty() == false) {
        tp = s.top();
        s.pop();
        area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);
        if (max_area < area_with_top)
            max_area = area_with_top;
    }
    return max_area;
}

int main() {
	vector<int> hist = {2,1,5,6,2,3};

	cout << largestRectangleArea(hist) << endl;
}
