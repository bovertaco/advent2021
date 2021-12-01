// advent of code 2021 day 1

//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void open_file_and_save_data_as_array(int *nums);
void compare_sum_of_window(int *nums, int window_size);

const int FLENGTH = 2000;

void main(){
    int nums[2000] = {0};
    open_file_and_save_data_as_array(&nums[0]);
    int window_size_p1 = 1;
    compare_sum_of_window(&nums[0],window_size_p1);
    int window_size_p2 = 3;
    compare_sum_of_window(&nums[0],window_size_p2);
    return;
}

void open_file_and_save_data_as_array(int *adress_of_nums){
    FILE *filepointer;
    filepointer = fopen("inputd1.txt","r");
    if (filepointer == NULL) {
        printf("can not open file\n");
        return;
    }
    int i = 0;
    while(i <= FLENGTH){
        fscanf(filepointer,"%d", &adress_of_nums[i]);
        ++i;
    }
    fclose(filepointer);
    return;
}
void compare_sum_of_window(int *nums,int window_size){
    printf("\npart one ----\n");
    int i;
    int j;
    int number_of_increases = 0;
    int this_window_sum;
    int last_window_sum = 0;
    for (j = 0; j<window_size; j++){
        last_window_sum = last_window_sum + nums[j];
        //printf("last window sum %d\n",last_window_sum);
    }
    for (i = window_size; i<FLENGTH; i++){
        
        this_window_sum = 0;
        for (j=0;j<window_size;j++){
            this_window_sum = this_window_sum + nums[i-j];
            //printf("this window sum %d\n",this_window_sum);
        }
        if (this_window_sum > last_window_sum){
            number_of_increases++;
        }
        last_window_sum = this_window_sum;
    }
    printf("%d\n",number_of_increases);
    return;
}