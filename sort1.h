#ifndef SORT_H
#define SORT_H
#include <iostream>
#include <cassert>
using namespace std;

template<class T>
class sort
{
	private:
		T *in;
		size_t n;
	public:
		virtual void type_sort(T *in , size_t n)=0;
};

template <class T>
class bubble : public sort<T>
{
	/*private:
	T *in;
	int n;*/			
	public:
	/*bubble(T * _in , size_t _n)
	{
		in=_in;
		n=_n;
	}*/
	void type_sort(T *in , size_t n)
	{
		int temp;
		for (int k=0; k<n-1; k++ )
	
		for(int j=0;j<n-k-1;j++)
		{
			if(*(in+j)>*(in+j+1))
			{
				temp= *(in+j);
				*(in+j)=*(in+j+1);
				*(in+j+1)=temp;
			}
		}
	}

};

template <class T>
class insert : public sort<T>
{
	/*private:
	T *in;
	int n;*/			
	public:
	/*insert(T *_in , size_t _n)
	{
		in=_in;
		n=_n;
	}*/
	void type_sort(T *in , size_t n)
	{
		for (int j=1; j<n; j++) 
		{
			int x = *(in+j);
			int k = j;
			while (--k>=0 && x<*(in+k))
			{
				*(in+k+1) = *(in+k);
			}
			*(in+k+1) = x;
		}
	}		
};

template <class T>
class shell : public sort<T>
{
	/*private:
	T *in;
	int n;*/			
	public:
	/*shell(T *_in , size_t _n)
	{
		in=_in;
		n=_n;
	}*/
	void type_sort(T *in , size_t n)
	{
		int temp;
	    for (int k = n / 2; k > 0; k /= 2) 
		{
	        for (int i = k; i < n; i++) 
			{
	            for (int j = i - k; j >= 0 && *(in+j) > *(in+j+k); j -= k) 
				{
	                temp = *(in+j);
	                *(in+j) = *(in+j+k);
	                *(in+j+k) = temp;
	            }   
	        }   
    	}
	}		
};
template <class T>
class merge : public sort<T>
{
	public:
	void type_sort(T * in, size_t n)
	{
		merge1(in,0,n-1);
	}
	void merge2(T*a, int low,int high, int mid)
	{
		int i=low;
		int k=0;
		int j=mid+1;
		T temp[(high-low)+1];
		while(i<=mid && j<=high)
		{
			if(*(a+i)<*(a+j))
			{
				temp[k]=*(a+i);
				k++;
				i++;
			}
			else
			{
				temp[k]=*(a+j);
				k++;
				j++;
			}
		}
		while(i<=mid)
		{
			temp[k]=*(a+i);
			k++;
			i++;
		}
		while(j<=high)
		{
			temp[k]=*(a+j);
			k++;
			j++;
		}
		for(i=low;i<=high;i++)
		{
			*(a+i)=temp[i-low];
		}
	}
	void merge1(T *a,int low, int high)
	{
		int mid;
		if(low<high)
		{
			mid=(low+high)/2;
			merge1(a,low,mid);
			merge1(a,mid+1,high);
			merge2(a,low,high,mid);
		}
	}
};

template <class T>
class quick : public sort<T>
{
	public:
		void type_sort(T *in, size_t n)
		{
			quicksort(in,0,n);
		}
		int divide(T *array, int start, int end) 
		{
	    	int left;
	    	int right;
	    	int pivot;
	    	int temp;
	 
	    	pivot = array[start];
	    	left = start;
	    	right = end;
	 
	    // Mientras no se cruzen los índices
	    	while (left < right) {
	        	while (array[right] > pivot) {
	            	right--;
	        	}
	 
	  		    while ((left < right) && (array[left] <= pivot)) {
	            	left++;
	        	}
	 
	        	// Si todavía no se cruzan los indices seguimos intercambiando
	        	if (left < right) {
	        	    temp = array[left];
	        	    array[left] = array[right];
	        	    array[right] = temp;
	        	}
	    	}
	 
	    	// Los índices ya se han cruzado, ponemos el pivot en el lugar que le corresponde
	    	temp = array[right];
	    	array[right] = array[start];
	    	array[start] = temp;
	 
	    	// La nueva posición del pivot
	    	return right;
		}
	 
	// Función recursiva para hacer el ordenamiento
		void quicksort(T *array, int start, int end)
		{
	    	int pivot;
	    	if (start < end) {
	    	    pivot = divide(array, start, end);
	    	    // Ordeno la lista de los menores
	    	    quicksort(array, start, pivot - 1);
	    	    // Ordeno la lista de los mayores
	    	    quicksort(array, pivot + 1, end);
	    	}
		}
};

#endif
