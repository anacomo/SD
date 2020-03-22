#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono;

ifstream in("data.in");

bool IsSorted(vector<long long>& v, vector <long long>& sorted);
int NrDigits(long long x);
void Interclasare(vector <long long>& v, int left, int right);

// Sorting functions
void BubbleSort(vector<long long>& v);
void CountSort(vector<long long>& v);
void MergeSort(vector<long long>& v, int left, int right);
void QuickSort(vector<long long>& v, int left, int right);
void RadixSort(vector<long long>& v);

int main()
{   int tests;
    in >> tests;
    for(int i = 0; i < tests; ++i){
        cout << "TEST NUMBER " << i + 1 << '\n';
        int n;
        in >> n;
        long long maxim;

        vector <long long> v, temp, sortat;
        for(int j = 0; j < n; ++j){
            long long x;
            in >> x;
            if(j == 0 || x > maxim)
                maxim = x;
            v.push_back(x);
            temp.push_back(x);
            sortat.push_back(x);
            }
        cout << "Size of array: " << n << '\n';
        cout << "Maxim: " << maxim << '\n';
        //Sort
        auto start = high_resolution_clock::now();
        sort(sortat.begin(), sortat.end());
        auto stop = high_resolution_clock::now();
        duration<double, std::milli> fp_ms = stop - start;
        cout << "STL Sort: " << fp_ms.count() / 100000 << "s\n";

        //Bubble Sort
        for(int k = 0; k < n; ++k)
            temp[k] = v[k];
        start = high_resolution_clock::now();
        BubbleSort(temp);
        stop = high_resolution_clock::now();
        fp_ms = stop - start;
        cout << "Bubble Sort: " << fp_ms.count() / 1000 << "s ";
        if(IsSorted(temp, sortat))
            cout << "Ok\n";
        else
            cout << "BUG\n";

        // CountSort
        for(int k = 0; k < n; ++k)
            temp[k] = v[k];
        start = high_resolution_clock::now();
        CountSort(temp);
        stop = high_resolution_clock::now();
        fp_ms = stop - start;
        cout << "Count Sort: " << fp_ms.count() / 1000 << "s ";
        if(IsSorted(temp, sortat))
            cout << "Ok\n";
        else
            cout << "BUG\n";

        //Radix Sort
        for(int k = 0; k < n; ++k)
            temp[k] = v[k];
        start = high_resolution_clock::now();
        RadixSort(temp);
        stop = high_resolution_clock::now();
        fp_ms = stop - start;
        cout << "Radix Sort: " << fp_ms.count() / 1000 << "s ";
        if(IsSorted(temp, sortat))
            cout << "Ok\n";
        else
            cout << "BUG\n";

        //Merge Sort
        for(int k = 0; k < n; ++k)
            temp[k] = v[k];
        start = high_resolution_clock::now();
        MergeSort(temp, 0, n-1);
        stop = high_resolution_clock::now();
        fp_ms = stop - start;
        cout << "Merge Sort: " << fp_ms.count() / 1000 << "s ";
        if(IsSorted(temp, sortat))
            cout << "Ok\n";
        else
            cout << "BUG\n";

        //Quick Sort
        for(int k = 0; k < n; ++k)
            temp[k] = v[k];
        start = high_resolution_clock::now();
        QuickSort(temp, 0, n-1);
        stop = high_resolution_clock::now();
        fp_ms = stop - start;
        cout << "Quick Sort: " << fp_ms.count() / 1000 << "s ";
        if(IsSorted(temp, sortat))
            cout << "Ok\n";
        else
            cout << "BUG\n";
        cout << "\n";
        }

    cout << "Hello world!" << endl;
    return 0;
}


bool IsSorted(vector<long long>& v, vector<long long>& sortat) {
	for (unsigned int i = 0; i < v.size(); i++) {
		if (v[i] != sortat[i])
            return false;
	}
	return true;
}


void Interclasare(vector<long long>& v, int left, int right) {
	int mid = (left + right) / 2;
	int i = left, j = mid + 1;
	vector<long long> w;
	while (i <= mid && j <= right) {
		if (v[i] < v[j])
			{w.push_back(v[i]);
			i++;
			}
		else
			{w.push_back(v[j]);
			j++;
			}
	}
	while (i <= mid)
		{w.push_back(v[i]);
		i++;
		}
	while (j <= right)
		{w.push_back(v[j]);
		j++;
		}

	for (i = left; i <= right; i++)
		v[i] = w[i - left];
}



void BubbleSort(vector<long long>& v){
    bool ok = false;
    do
    {ok = false;
    for(unsigned int i = 0; i < v.size() - 1; ++i)
        if(v[i] > v[i+1])
            {swap(v[i], v[i+1]);
            ok = true;
            }
    }while(ok);
}

void CountSort(vector <long long>& v)
{
    int max = *max_element(v.begin(), v.end());
    int min = *min_element(v.begin(), v.end());
    int range = max - min + 1;

    vector<int> count(range), output(v.size());
    for(int i = 0; i < v.size(); i++)
        count[v[i]-min]++;

    for(int i = 1; i < count.size(); i++)
           count[i] += count[i-1];

    for(int i = v.size()-1; i >= 0; i--)
    {
         output[ count[v[i]-min] -1 ] = v[i];
              count[v[i]-min]--;
    }

    for(int i = 0; i < v.size(); i++)
            v[i] = output[i];
}

void MergeSort(vector<long long>& v, int left, int right){
if(left < right){
    int mid = (left + right) / 2;
    MergeSort(v, left, mid);
    MergeSort(v, mid + 1, right);
    Interclasare(v, left, right);
    }
}

int NrDigits(long long x) {
	int d = 0;
	while(x) {
		d++;
		x /= 10;
	}
	return d;
}

void RadixSort(vector<long long>& v) {
	int n = v.size();
	if (n < 1)
        return;
	long long maxi = v[0];
	for (int i = 0; i < n; i++)
		if (v[i] > maxi)
            maxi = v[i];
	int pasi = NrDigits(maxi);
	vector<long long> l[10];

	long long p = 1;
	for (int k = 0; k < pasi; k++) {
		for (int i = 0; i < n; i++) {
			int c = (v[i] % (p * 10)) / p;
			l[c].push_back(v[i]);
		}
		int poz = 0;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < l[i].size(); j++)
                v[poz++] = l[i][j];
			l[i].clear();
		}
		p *= 10;
	}

}

void QuickSort(vector <long long>& v, int left, int right){
if(left < right){
    int mid = (left + right) / 2;
    int pivot = v[left];
    v[left] = v[mid];
    v[mid] = pivot;
    int i = left, j = right, d = 0;
    while(i < j)
        {if(v[i] > v[j])
            {swap(v[i], v[j]);
            d = 1 - d;
            }
            i += d;
            j -= 1 - d;
        }
        QuickSort(v, left, i - 1);
        QuickSort(v, i + 1, right);
    }
}
