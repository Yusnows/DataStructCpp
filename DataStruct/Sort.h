#pragma once

#define UP 1
#define DOWN 0


template<class T>
class Sort
{
public:
	static T* BublleSort(T a[], int len, char mode);
	static T* InsertSort(T a[], int len, char mode);
	static T* MergeSort(T a[], int len, char mode);
	static T* InsertMergeSort(T a[], int len, char mode);
	static void MergeBorder(T x[], T y[], int s, int n,char mode);
	static void Merge(T a[],T b[], int left, int mid, int right,char mode);
	static void InsertSort_s(T a[], int left, int right, char mode);
};

template<class T>
inline T * Sort<T>::BublleSort(T a[], int len, char mode)
{
	T temp = a[0];
	bool sorted = false;
	if (mode == UP)
	{
		for (int i = 0; (i < len - 1) && (sorted =!sorted); i++)
		{
			for (int j = 0; j < len - i - 1; j++)
			{
				if (a[j] > a[j + 1])
				{
					temp = a[j];
					a[j] = a[j + 1];
					a[j + 1] = temp;
					sorted = false;
				}
			}
		}
	}
	else if (mode == DOWN)
	{
		for (int i = 0; i < len - 1; i++)
		{
			for (int j = 0; (j < len - i - 1)&&(sorted = !sorted); j++)
			{
				if (a[j] < a[j + 1])
				{
					temp = a[j];
					a[j] = a[j + 1];
					a[j + 1] = temp;
					sorted = false;
				}
			}
		}
	}
	return a;
}

template<class T>
inline T * Sort<T>::InsertSort(T a[], int len, char mode)
{
	T key = a[0];
	int i = 0;
	if (mode == UP)
	{
		for (int j = 1; j < len; j++)
		{
			key = a[j];
			for (i = j - 1; i >= 0 && a[i] > key; i--)
			{
				a[i + 1] = a[i];
			}
			a[i + 1] = key;
		}
	}
	else if (mode == DOWN)
	{
		for (int j = 0; j < len; j++)
		{
			key = a[j];
			for (i = j - 1; i >= 0 && a[i] < key; i--)
			{
				a[i + 1] = a[i];
			}
			a[i + 1] = key;
		}
	}
	return a;
}

template<class T>
inline T * Sort<T>::MergeSort(T a[], int len, char mode)
{
	T* pResult = new T[len];
	int s = 1;
	while (s < len)
	{
		MergeBorder(a, pResult, s, len, mode);
		s = 2 * s;
		if (s < len)
			MergeBorder(pResult, a, s, len, mode);
		else
		{
			s = s / 2;
			MergeBorder(pResult, a, s, len, mode);
		}
		s = 2 * s;
	}
	delete[]pResult;
	return a;
}

template<class T>
inline T * Sort<T>::InsertMergeSort(T a[], int len, char mode)
{
	T* pResult = new T[len];
	int s = 8; //8
	int i = 0;
	if(s < len)
	{
		while (i + s - 1 < len)
		{
			InsertSort_s(a, i, i + s - 1, mode);
			i = i + s;
		}
		if (i < len)
		{
			InsertSort_s(a, i, len - 1, mode);
		}
	}
	else
	{
		InsertSort_s(a, i, len-1, mode);
	}
	while (s < len)
	{
		MergeBorder(a, pResult, s, len, mode);
		s = 2 * s;
		if (s < len)
			MergeBorder(pResult, a, s, len, mode);
		else
		{
			s = s / 2;
			for (int z = 0; z < len; z++)
				a[z] = pResult[z];
		}
		s = 2 * s;
	}
	delete[]pResult;
	return a;
}

template<class T>
inline void Sort<T>::MergeBorder(T x[], T y[], int s, int n,char mode)
{
	int i = 0;
	while (i+2*s-1<n)
	{
		Merge(x, y, i, i + s - 1, i + 2 * s - 1, mode);
		i += 2 * s;
	}
	if (i + s < n)
		Merge(x, y, i, i + s - 1, n - 1, mode);
	else
		for (int j = i; j <= n - 1; j++)
		{
			y[j] = x[j];
		}
}

template<class T>
inline void Sort<T>::Merge(T x[], T y[],int left, int mid, int right,char mode)
{
	int i = left;
	int j = mid + 1;
	int k = left;
	if (mode == UP)
	{
		while (i <= mid&&j <= right)
		{
			if (x[i] < x[j])
				y[k++] = x[i++];
			else
				y[k++] = x[j++];
		}
		if (i > mid)
		{
			for (int z = j; z <= right; z++)
				y[k++] = x[z];
		}
		else
		{
			for (int z = i; z <= mid; z++)
				y[k++] = x[z];
		}
	}
	else if (mode == DOWN)
	{
		while (i <= mid&&j <= right)
		{
			if (x[i] > x[j])
				y[k++] = x[i++];
			else
				y[k++] = x[j++];
		}
		if (i > mid)
		{
			for (int z = j; z <= right; z++)
				y[k++] = x[z];
		}
		else
		{
			for (int z = i; z <= mid; z++)
				y[k++] = x[z];
		}
	}
}

template<class T>
inline void Sort<T>::InsertSort_s(T a[], int left, int right, char mode)
{
	T key = a[0];
	int i = left;
	if (mode == UP)
	{
		for (int j = left+1; j <=right; j++)
		{
			key = a[j];
			for (i = j - 1; i >= left && a[i] > key; i--)
			{
				a[i + 1] = a[i];
			}
			a[i + 1] = key;
		}
	}
	else if (mode == DOWN)
	{
		for (int j = left+1; j <=right; j++)
		{
			key = a[j];
			for (i = j - 1; i >= left && a[i] < key; i--)
			{
				a[i + 1] = a[i];
			}
			a[i + 1] = key;
		}
	}
}
