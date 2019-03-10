#include<stdio.h>
#include<iostream>
#include<conio.h>

using namespace std;

// ============================ Template Functions =============================
template<typename T>
void swap_array(T ptr[], size_t index_ii, size_t index_jj);

template<typename T>
void print_array(T arr[], size_t len);

template<typename T>
void array_restore(T arr_backup[], T arr_to_restore[], size_t len);

template<typename T>
void sort_select(T arr[], size_t len, bool flag);

template<typename T>
void sort_bubble(T arr[], size_t len, bool flag);

template<typename T>
void sort_bubble_optimized(T arr[], size_t len, bool flag);

template<typename T>
void sort_insert(T arr[], size_t len, bool flag);

template<typename T>
void sort_shell(T arr[], int len, bool flag);

