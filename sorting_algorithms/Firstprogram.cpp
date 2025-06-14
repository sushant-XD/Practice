#include<iostream>
#include<vector>
// bubble sort
// compare with previous value to sort (similar to how bubbles rise from the bottom) 
void printVector(std::vector<int>&  original);
void mergesort(std::vector<int> &arr, int left, int right);

std::vector<int> SelectionSort(std::vector<int>& original);
std::vector<int> BubbleSort(std::vector<int>& original);
std::vector<int> InsertionSort(std::vector<int> &original);
std::vector<int> MergeSort(std::vector<int> &original);
std::vector<int> QuickSort(std::vector<int> &original);

int main (int argc, char *argv[]) {
  std::vector<int> original = {2,1,4,3,1,22,199,12,21};
  std::vector<int> sortedArray;
  std::cout << "Enter the type of Sorting algorithms to use\n";
  std::cout << "---------------------------------------------\n";
  std::cout << "  1 -> BubbleSort \n  2 -> SelectionSort \n  3 -> InsertionSort \n 4 -> MergeSort \n 5 -> QuickSort \n";
  int input = 0;
  std::cin >> input;

  std::cout << "Unsorted Array: \n";
  printVector(original);

  switch (input) {
    case 1:
     sortedArray = BubbleSort(original);
      break;
    case 2:
      sortedArray = SelectionSort(original);
      break;
    case 3:
      sortedArray = InsertionSort(original);
    case 4:
      sortedArray = MergeSort(original);
    case 5:
      sortedArray = QuickSort(original);
    default:
      std::cout << "Select valid options";
      break;
  }
  std::cout << "Sorted Array: \n";
  printVector(sortedArray);
  return 0;
}

void printVector(std::vector<int>& original){
  for(size_t i = 0;i<original.size();i++){
    std::cout << original[i] << " ";
  }
  std::cout << "\n";
  return;
}

std::vector<int> SelectionSort(std::vector<int>& original){
  std::cout << "Selection Sort" << std::endl;
  int smallest_idx = 0;
  for(size_t i=0;i<original.size()-1;i++){
    smallest_idx = i;
    for(size_t j=i+1;j<original.size();j++){
      if(original[j] < original[smallest_idx]){
        smallest_idx = j;
      }else{
        continue;
      }
    }
    std::swap(original[i],original[smallest_idx]);
  }
  return original;
}

// really simple
// just go through an array and search for the smallest value 
// when the smallest value is found, swap it with previous one 
std::vector<int> BubbleSort(std::vector<int>& original){
  std::cout << "Bubble Sort" << std::endl;  
  int temp = 0;
  for(std::size_t i=0;i<original.size()-1;i++){
    for(std::size_t j=0;j<original.size()-i-1;j++){
      if(original[j]>original[j+1]){
        temp = original[j];
        original[j] = original[j+1];    
        original[j+1] = temp;
      }
    }
  }
  return original;
}


// Todo: implement this function 
std::vector<int> HeapSort(std::vector<int> & original){
  std::cout << "Heap Sort";
}

// Todo: implement this function
std::vector<int> CountingSort(std::vector<int> &original){
  std::cout << "Counting Sort";
}

// Todo: implement this function
std::vector<int> RadixSort(stod::vector<int> &original){
  
}

// take the first element, that is sorted 
// keep adding elements and check everytime if we need to swap with the leftmost number until we don't have to 
// sounds pretty easy, lets go
std::vector<int> InsertionSort(std::vector<int> &original){
  std::cout << "Insertion Sort" << std::endl;
  std::vector<int> sorted_array = {original[0]};
  for(size_t i=1;i<original.size();i++){
    sorted_array.push_back(original[i]);
    for(size_t j=i;j>=0;j--){
      if(sorted_array[j]<sorted_array[j-1]){
        std::swap(sorted_array[j],sorted_array[j-1]);
      }else{
        break;
      }
    }
  }
  return sorted_array;
}

int partition(std::vector<int> &original, int left, int right){
  int pivot = original[right];
  int i=left, j= right-1; 
  while(i < right && j >= i){
    while(original[i] < pivot){
      i++;
    }
    while(original[j] > pivot){
      j--;
    }
    if(i<=j){
      std::swap(original[i],original[j]);
      i++;
      j--;
    }
  }
  std::swap(original[i], original[right]);
  return i;
}

void quick_sort(std::vector<int> &original, int left, int right){
  if(left >= right || right < 0 || left < 0){
    return;
  }
  int index = partition(original, left, right);
  quick_sort(original, left, index -1);
  quick_sort(original, index+1, right);
}

// sounds simple but is not
// take a value (last value for now), and consider it a node
// start pointers left and right
std::vector<int> QuickSort(std::vector<int> &original){
  std::cout << "Quick Sort" << std::endl;
  if(original.size() <= 1){
    return original;
  }
  quick_sort(original, 0, original.size() - 1);
  return original;
}

void merge(std::vector<int> &arr, int left, int mid, int right){
  std::vector<int> temp;
  int i=left, j=mid+1;
  while (i<=mid && j<=right) {
    if(arr[j] < arr[i]){
      temp.push_back(arr[j++]);
    }else{
      temp.push_back(arr[i++]);
    }
  }

  while(i<=mid){
    temp.push_back(arr[i++]);
  }
  while(j<=right){
    temp.push_back(arr[j++]);
  }

  for(size_t k=0;k<temp.size();k++){
    arr[left+k] = temp[k];
  }
}

void mergesort(std::vector<int> &arr, int left, int right){
  if(left>=right){
    return;
  }
  int mid = left + (right - left) / 2;
  mergesort(arr, left, mid);
  mergesort(arr, mid+1, right);
  merge(arr, left, mid, right);
}

// Recursive divide and concquer type of sorting algorithm
// divide an array into small subarrays until they are sorted(essentially get just a single array which is sorted by default)
// merge them as you go (have two pointers poiting at start of both subarrays, check for smaller value and insert at the back, copy to the original// array and return)
std::vector<int> MergeSort(std::vector<int> &original){
  std::vector<int> org_copy = original;
  std::cout << "Merge sort";
  if(org_copy.size() != 1){
      mergesort(original, 0, original.size()-1);
  }   
  return original;
}









