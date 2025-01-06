# Ordenación elemental

# Selection sort

Es el algoritmo mas sencillo pero no asi el mas rápido. Su funcionamiento se basa en seleccionar el menor elemento de todos, lo intercambia con el elemento que se encuentra en la primera posición, luego, selecciona al menor de los restantes y lo pone en la segunda posición, y asi sucesivamente hasta terminar

![1000001069.png](Ordenacio%CC%81n%20elemental%200c5a4d97c00a4823992506959597dd1b/1000001069.png)

En el lenguaje de la materia:

```c
proc selection_sort(in/out a:array[1..n] of T)
	var minp: nat
	for i:= 1 to n-1 do
		minp := min_pos_from(a,i)
		swap(a,i,minp)
	od
end proc

fun min_pos_from(a:array[1..n] of T, i: nat) ret minp: nat
	minp := i
	for j:=i+1 to n do
		if a[j] < a[minp] then minp := j fi
	od
end fun

proc swap(in/out a:array[1..n] of T, in i,j : nat)
	var tmp: T
	tmp := a[i]
	a[i] := a[j]
	a[j] := tmp
end proc
```

En C:

```c
#include <stdio.h>

void swap(int* nums, int a, int b){
	int temp = nums[a];
	nums[a] = nums[b];
	nums[b] = temp;
}

int min_pos_from(int* nums, int i, int numsSize){
	int min = i;
	for(int j = i+1; j < numsSize; j++){
		if(nums[j] < nums[min]){
			min = j;
		}
	}
	return min;
}

void selection_sort (int* nums, int numsSize){
	int min = 0;
	for(int i = 0; i < numsSize - 1; i++){
		min = min_pos_from(nums, i, numsSize);
		swap(nums, i, min);	
	}
}

```

# Insertion sort

Cada elemento menor se agarra del arreglo y se inserta en su lugar correspondiente

![1000001070.png](Ordenacio%CC%81n%20elemental%200c5a4d97c00a4823992506959597dd1b/1000001070.png)

En el lenguaje de la materia:

```c
proc insertion_sort(in/out a:array[1..n] of T)
	for i:= 2 to n do
		insert(a,i)
	od
end proc

proc insert(in/out a:array[1..n] of T, in i: nat)
	var j: nat
	j:=i
	do j > 1 && a[j] < a[j-1] -> swap(a,j-1,j)
															 j:= j-1
	od
end proc

proc swap(in/out a:array[1..n] of T, in i,j : nat)
	var tmp: T
	tmp := a[i]
	a[i] := a[j]
	a[j] := tmp
end proc.														 
```

En C:

```c
#include <stdio.h>

void swap(int* nums, int a, int b){
	int temp = nums[a];
	nums[a] = nums[b];
	nums[b] = temp;
}

void insert(int* nums, int i){
	int j = i;
	while(j > 0 && nums[j] < nums[j-1]){
		swap(nums, j-1, j);
		j--;
	}
}

void insertion_sort(int* nums, int numsSize){
	for(int i = 1; i < numsSize; i++){
		insert(nums, i);
	}
}
```