#include <iostream>
#include <thread>
#include <vector>


using namespace std;

class MergeSort 
{
public:
    void Sort(vector<int>& arr) 
    {
        if (arr.size() > 1) 
        {
            vector<int> left(arr.begin(), arr.begin() + arr.size() / 2);
            vector<int> right(arr.begin() + arr.size() / 2, arr.end());

            Sort(left);
            Sort(right);

            merge(arr, left, right);
        }
    }

private:
    void merge(vector<int>& arr, const vector<int>& left, const vector<int>& right) 
    {
        size_t i = 0, j = 0, k = 0;

        while (i < left.size() && j < right.size()) 
        {
            if (left[i] <= right[j]) 
            {
                arr[k++] = left[i++];
            }
            else 
            {
                arr[k++] = right[j++];
            }
        }
        while (i < left.size()) 
        {
            arr[k++] = left[i++];
        }
        while (j < right.size()) 
        {
            arr[k++] = right[j++];
        }
    }
};

int main() 
{
    setlocale(LC_ALL, "Rus");

    vector<int> num1(10);
    cout << "Введите пожалуйста десять целых чисел для ввашего маассива: \n";
    for (int& num2 : num1) 
    {
        cin >> num2;
    }

    MergeSort Sortt;
    thread SortWithThread([&Sortt, &num1] {Sortt.Sort(num1); });
    SortWithThread.join();

    cout << "Вот ваш отсортированный массив :3 : \n";
    for (int num : num1) 
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}