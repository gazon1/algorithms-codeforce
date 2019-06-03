//https://codeforces.com/problemset/problem/1144/D
#include <bits/stdc++.h>
using namespace std;
#define _DEBUG 1
#define DEBUG() if(_DEBUG)
void answer(int answer_type, int index1, int index2) {cout << (answer_type) << " " << (index1 + 1) << " " << (index2 + 1) << endl;}

map<int, int>  countFreq(int arr[], int n) 
{

    map<int, int> dict;
    // Mark all array elements as not visited 
    vector<bool> visited(n, false); 
  
    // Traverse through array elements and 
    // count frequencies
    DEBUG() cout << "in countFreq()" << endl;
    for (int i = 0; i < n; i++) { 
  
        // Skip this element if already processed 
        if (visited[i] == true) 
            continue; 
  
        // Count frequency 
        int count = 1; 
        for (int j = i + 1; j < n; j++) { 
            if (arr[i] == arr[j]) { 
                visited[j] = true; 
                count++; 
            } 
        }
	
        dict.insert(make_pair(arr[i], count));
	DEBUG() cout << "ar[i] = " << arr[i] << "; dict[..] = " << dict[arr[i]];
    }

    DEBUG() cout << "going out of the func" << endl;
    return dict;
} 


int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif



  int n;
  scanf("%d", &n);
  int ar[n];
  

  for (int i =0; i < n; ++i) {
    cin >> ar[i];
  }
  map<int, int> dict = countFreq(ar, n);
  int max = 0;
  int max_value_index;
  for (int i =0; i < n; ++i) {
    DEBUG()  cout << dict[ar[i]] << "; " << max << endl;
    if (max < dict[ar[i]]) {
      max = dict[ar[i]];
      max_value_index = i;
    }
  }
  

  DEBUG()  cout << max << "; " << max_value_index;

  cout << n - max << endl;
  for (int i = max_value_index; 0 < i; --i) {
    if (ar[i - 1] > ar[i]) answer(1, i-1, i);
    else answer(1, i-1, i);
  }
  for (int i = max_value_index; i < n - 1; ++i) {
    if (ar[i] == ar[i + 1]) continue;
    else if (ar[i + 1] > ar[i]) answer(2, i+1, i);
    else answer(1, i+1, i);
  }
  return 0;
}
