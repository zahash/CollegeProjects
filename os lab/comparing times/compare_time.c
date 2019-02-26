#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){
	clock_t start1, end1, start2, end2, start3, end3;
    double command1_time;
    double command2_time;
    double command3_time;
    
    int num_iterations = 1000;
    
    char command1[] = "cp dummy_file.txt another_file.txt";
    char command2[] = "cat dummy_file.txt dummy_file2.txt > dummy_final.txt";
    char command3[] = "touch zahash";
    
    start1 = clock();
    for(int i=0; i<num_iterations; i++) { system(command1); }
    end1 = clock();

    start2 = clock();
    for(int i=0; i<num_iterations; i++) { system(command2); }
    end2 = clock();

    start3 = clock();
    for(int i=0; i<num_iterations; i++) { system(command3); }
    end3 = clock();

    
    command1_time = ((double) (end1 - start1)) / CLOCKS_PER_SEC;
    command2_time = ((double) (end2 - start2)) / CLOCKS_PER_SEC;
    command3_time = ((double) (end3 - start3)) / CLOCKS_PER_SEC;
    
//    printf(" command1 : %d \n command2: %d \n command3 : %d \n", command1_time, command2_time, command3_time);
    
    printf("\n\n");
    printf(" cp    : %f\n", command1_time);
    printf(" cat   : %f\n", command2_time);
    printf(" touch : %f\n", command3_time);
    
    
    return 0;
}
