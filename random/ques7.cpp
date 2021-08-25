#include <bits/stdc++.h>
using namespace std;


int minJumps(vector<int>arr, int n)
{
	if (n <= 1)
		return 0;
	if (arr[0] == 0)
		return -1;
	int jump = 1;
	int subArrEndIndex = arr[0];

	int i = 1;
	int subArrFistHalfMaxSteps = 0;

	int subArrSecondHalfMaxSteps = 0;

	for (i = 1; i < n;) {

		subArrEndIndex = i + subArrEndIndex;
		if (subArrEndIndex >= n)
			return jump;

		int firstHalfMaxStepIndex = 0;

		for (; i < subArrEndIndex; i++) {
			int stepsCanCover = arr[i] + i;
			if (subArrFistHalfMaxSteps < stepsCanCover) {
				subArrFistHalfMaxSteps = stepsCanCover;
				subArrSecondHalfMaxSteps = 0;
				firstHalfMaxStepIndex = i;
			}
			else if (subArrSecondHalfMaxSteps
					< stepsCanCover) {
				subArrSecondHalfMaxSteps = stepsCanCover;
			}
		}
		if (i > subArrFistHalfMaxSteps)
			return -1;
		jump++;
	
		subArrEndIndex = arr[firstHalfMaxStepIndex];
		subArrFistHalfMaxSteps = subArrSecondHalfMaxSteps;
	}

	return -1;
}


int main() {
	string input; 
    getline(cin,input);
    vector<int> arr = splitAtSpace(input);
	cout << minJumps(arr, arr.size());
	cout<<"\n";
	return 0;
}