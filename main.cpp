#include <iostream>

template<class c_Type>
int fn_Partition(c_Type c_Arr[], int i_LowI, int i_HighI){
	int i_Pivot = c_Arr[i_LowI];
	int i_I = i_LowI - 1;
	int i_J = i_HighI + 1;

	for(;;){
        do {
			i_I++;
		} while (c_Arr[i_I] > i_Pivot);

		do {
			i_J--;
		} while (c_Arr[i_J] < i_Pivot);

		if (i_I >= i_J){
			return i_J;
		}
		else{
            c_Type o_Tmp    = c_Arr[i_I];
            c_Arr[i_I]      = c_Arr[i_J];
            c_Arr[i_J]      = o_Tmp;
		}
	}
}

template<class c_Type>
void fn_QuickSort(c_Type c_Arr[], int i_LowI, int i_HighI){
	if (i_LowI < i_HighI) {
		int i_PiI = fn_Partition<c_Type>(c_Arr, i_LowI, i_HighI);

		fn_QuickSort(c_Arr, i_LowI, i_PiI);
		fn_QuickSort(c_Arr, i_PiI + 1, i_HighI);
	}
}


int main(){

	int i_Arr[] = { 5, 1, 2, 8, 9, 10 };
	int i_N = sizeof(i_Arr) / sizeof(int);
	fn_QuickSort<int>(i_Arr, 0, i_N - 1);
	std::cout<< "Sorted array: \n";
	for(int i_Ct=0; i_Ct< i_N; i_Ct++){
        std::cout<< i_Arr[i_Ct] << " ";
	}
	return 0;
}
