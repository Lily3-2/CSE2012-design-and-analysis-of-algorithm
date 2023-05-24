//Quick Sort to arrange the details of the mobile phones in increasing order of their memory. - Divide and Conquer 

#include <bits/stdc++.h>
using namespace std;


int partition(vector<pair<string, int>> &phone_details, int low, int high) {
  int pivot = phone_details[high].second;
  int i = low - 1;
  for (int j = low; j <= high - 1; j++) {
    if (phone_details[j].second <= pivot) {
      i++;
      swap(phone_details[i], phone_details[j]);
    }
  }
  swap(phone_details[i + 1], phone_details[high]);
  return i + 1;
}

void quickSort(vector<pair<string, int>> &phone_details, int low, int high) {
  if (low < high) {
    int pivot_index = partition(phone_details, low, high);
    quickSort(phone_details, low, pivot_index - 1);
    quickSort(phone_details, pivot_index + 1, high);
  }
}

int main() {
  vector<pair<string, int>> phone_details;
  int n;
  cout<<"Enter the number of mobile phones: "<<endl;
  cin >> n;
  cout<<"Enter the phone numer with its respective memory size: "<<endl;
  for(int i =0; i< n; i++) {
    string pname;
    int memo;
    cin>> pname;
    cin >> memo;
    phone_details.push_back( make_pair(pname, memo));
  };

  quickSort(phone_details, 0, phone_details.size() - 1);

  cout << "Mobile phones sorted in increasing order of their memory: \n";
  for (const auto &phone : phone_details) {
    cout << phone.first << " - " << phone.second << "GB\n";
  }

  return 0;
}