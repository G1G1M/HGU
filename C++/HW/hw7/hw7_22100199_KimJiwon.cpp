#include <iostream>
#include <string>
using namespace std;

// 구조체 정의
struct s_record
{
  string id;   // 학번
  string name; // 이름
  float grade; // 학점
};

// 리스트 출력 함수
void show_thelist(s_record s_list[], int n)
{
  for (int i = 0; i < n; i++)
  {
    cout << s_list[i].id << " " << s_list[i].name << " " << s_list[i].grade << endl;
  }
}

// Insertion Sort
void insertion_sort(s_record s_list[], int n)
{
  for (int i = 1; i < n; i++)
  {
    s_record key = s_list[i];
    int j = i - 1;
    while (j >= 0 && s_list[j].grade > key.grade)
    {
      s_list[j + 1] = s_list[j];
      j--;
    }
    s_list[j + 1] = key;
  }
}

// Bubble Sort
void bubble_sort(s_record s_list[], int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - i - 1; j++)
    {
      if (s_list[j].grade > s_list[j + 1].grade)
      {
        swap(s_list[j], s_list[j + 1]);
      }
    }
  }
}

// Selection Sort
void selection_sort(s_record s_list[], int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    int min_idx = i;
    for (int j = i + 1; j < n; j++)
    {
      if (s_list[j].grade < s_list[min_idx].grade)
      {
        min_idx = j;
      }
    }
    swap(s_list[i], s_list[min_idx]);
  }
}

// Quick Sort
int partition(s_record s_list[], int low, int high)
{
  float pivot = s_list[high].grade;
  int i = low - 1;
  for (int j = low; j < high; j++)
  {
    if (s_list[j].grade <= pivot)
    {
      i++;
      swap(s_list[i], s_list[j]);
    }
  }
  swap(s_list[i + 1], s_list[high]);
  return i + 1;
}

void quick_sort(s_record s_list[], int low, int high)
{
  if (low < high)
  {
    int pi = partition(s_list, low, high);
    quick_sort(s_list, low, pi - 1);
    quick_sort(s_list, pi + 1, high);
  }
}

// Merge Sort
void merge(s_record s_list[], int left, int mid, int right)
{
  int n1 = mid - left + 1;
  int n2 = right - mid;

  s_record *L = new s_record[n1];
  s_record *R = new s_record[n2];

  for (int i = 0; i < n1; i++)
    L[i] = s_list[left + i];
  for (int i = 0; i < n2; i++)
    R[i] = s_list[mid + 1 + i];

  int i = 0, j = 0, k = left;

  while (i < n1 && j < n2)
  {
    if (L[i].grade <= R[j].grade)
    {
      s_list[k++] = L[i++];
    }
    else
    {
      s_list[k++] = R[j++];
    }
  }

  while (i < n1)
    s_list[k++] = L[i++];
  while (j < n2)
    s_list[k++] = R[j++];

  delete[] L;
  delete[] R;
}

void merge_sort(s_record s_list[], int left, int right)
{
  if (left < right)
  {
    int mid = left + (right - left) / 2;
    merge_sort(s_list, left, mid);
    merge_sort(s_list, mid + 1, right);
    merge(s_list, left, mid, right);
  }
}

// Heap Sort
void heapify(s_record s_list[], int n, int i)
{
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && s_list[left].grade > s_list[largest].grade)
    largest = left;
  if (right < n && s_list[right].grade > s_list[largest].grade)
    largest = right;

  if (largest != i)
  {
    swap(s_list[i], s_list[largest]);
    heapify(s_list, n, largest);
  }
}

void heap_sort(s_record s_list[], int n)
{
  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(s_list, n, i);

  for (int i = n - 1; i > 0; i--)
  {
    swap(s_list[0], s_list[i]);
    heapify(s_list, i, 0);
  }
}

int main()
{
  s_record s_list[12] = {
      {"21900013", "Kim ", 6.5}, {"21900136", "Lee ", 8.8}, {"21900333", "Park", 9.2}, {"21800442", "Choi", 7.1}, {"21900375", "Ryu ", 5.4}, {"21700248", "Cho ", 6.3}, {"21700302", "Jung", 8.3}, {"21800255", "Han ", 6.9}, {"21800369", "Kang", 6.3}, {"21900401", "Yang", 9.1}, {"21800123", "Moon", 8.1}, {"21700678", "Seo ", 7.9}};
  int n = 12;

  insertion_sort(s_list, n);

  // bubble_sort(s_list, n);

  // selection_sort(s_list, n);

  // quick_sort(s_list, 0, n - 1);

  // merge_sort(s_list, 0, n - 1);

  // heap_sort(s_list, n);

  cout << "< The result of the sorting > " << "\n";

  show_thelist(s_list, n);

  return 0;
}
