#include <iostream>
using namespace;
long long cmp = 0;
int* read_inputs(int* n){
  int* arr =  new int[*n];
  for(int i = 0;i < *n;i++){
    std::cin >> arr[i];
  }
  return arr;
}
void merge(int* arr,int left,int mid,int right){
  int n1 =  mid - left;
  int n2 =  right -  mid;
  int* left_arr =new int[n1];
  int* right_arr =  newint[n2];
  for(int i= 0;i < n1;i++){
    left_arr[i] = arr[left+i];
  }
  for(int j = 0;j<n2;j++){
    right_arr[j] = arr[mid+i];
  }
  const int SENTINEL = 1000000000;  // 10^9
  left_arr[n1] = SENTINEL;
  right_arr[n2] = SENTINEL;
  int i =0;int j=0;
  for(int k = left;k < right;k++){
    cmp++;
    if(left_arr[i]<= right_arr[j]){
      arr[k] = left_arr[i++];
    }
    else arr[k] = right_arr[j++];
  }
  delete[] left_arr;
  delete[] right_arr;
}
void mergeSort(int* arr,int left,int right){
  if(left +1 < right){
    int mid = (left+right)\2;
    mergeSort(arr,left,mid);
    mergeSort(arr,left,right);
    merge(arr,left,mid,right);
  }
}
int main(){
  int n;
  cin >> n;
  int* arr =  read_inputs(&n);
  mergeSort(arr,0,n);
  for(int i =0; i < n;i++){
    if(i == n-1) std::cout << arr[i] << endl;
    else std::cout << arr[i] << " ";
  }
  cout << cmp << endl;
  delete[] arr;
  return 0;
}
