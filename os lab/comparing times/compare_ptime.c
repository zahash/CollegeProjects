#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define DATA_SIZE 1000

int create_file()
{
   /* File pointer to hold reference to our file */
    FILE * fPtr;


    /* 
     * Open file in w (write) mode. 
     * "data/file1.txt" is complete path to create file
     */
    fPtr = fopen("file1.txt", "w");


    /* fopen() return NULL if last operation was unsuccessful */
    if(fPtr == NULL)
    {
        /* File not created hence exit */
        printf("Unable to create file.\n");
        exit(EXIT_FAILURE);
    }
	
    /* Close file to save file data */
    fclose(fPtr);

    return 0;
}

int merge_files()
{
   FILE *fs1, *fs2, *ft;
 
   char ch;
    
   fs1 = fopen("dummy_file.txt", "r");
   fs2 = fopen("dummy_file2.txt", "r");
 
   if(fs1 == NULL || fs2 == NULL)
   {
      perror("Error ");
      printf("Press any key to exit...\n");
      exit(EXIT_FAILURE);
   }
 
   ft = fopen("merged_dummy.txt", "w"); // Opening in write mode
 
   if(ft == NULL)
   {
      perror("Error ");
      printf("Press any key to exit...\n");
      exit(EXIT_FAILURE);
   }
 
   while((ch = fgetc(fs1)) != EOF)
      fputc(ch,ft);
 
   while((ch = fgetc(fs2)) != EOF)
      fputc(ch,ft);
 
   fclose(fs1);
   fclose(fs2);
   fclose(ft);
 
   return 0;
}

 
int copy_file()
{
   char ch;
   FILE *source, *target;
 
   source = fopen("dummy_file2.txt", "r");
 
   if (source == NULL)
   {
      printf("Press any key to exit...\n");
      exit(EXIT_FAILURE);
   }
 
   target = fopen("dummy_file2copy.txt", "w");
 
   if (target == NULL)
   {
      fclose(source);
      printf("Press any key to exit...\n");
      exit(EXIT_FAILURE);
   }
 
   while ((ch = fgetc(source)) != EOF)
      fputc(ch, target);
  
   fclose(source);
   fclose(target);
 
   return 0;
}


int main(){
	clock_t start1, end1, start2, end2, start3, end3;
    double command1_time;
    double command2_time;
    double command3_time;
    
    int num_iterations = 1000;
    
    //char command1[] = "cp dummy_file.txt another_file.txt";
    //char command2[] = "cat dummy_file.txt dummy_file2.txt > dummy_final.txt";
    //char command3[] = "touch zahash";
    
    start1 = clock();
    for(int i=0; i<num_iterations; i++) { create_file(); system("rm file1.txt"); }
    end1 = clock();
	
	
    start2 = clock();
    for(int i=0; i<num_iterations; i++) { merge_files(); }
    end2 = clock();
	
	
    start3 = clock();
    for(int i=0; i<num_iterations; i++) { copy_file(); }
    end3 = clock();
	
    
    command1_time = ((double) (end1 - start1)) / CLOCKS_PER_SEC;
    command2_time = ((double) (end2 - start2)) / CLOCKS_PER_SEC;
    command3_time = ((double) (end3 - start3)) / CLOCKS_PER_SEC;
    
	/*
    printf("\n\n");
    printf(" cp    : %f\n", command1_time);
    printf(" cat   : %f\n", command2_time);
    printf(" touch : %f\n", command3_time);
    */
    
    printf("\n\n");
    printf(" create file : %f\n", command1_time);
    printf(" merge file  : %f\n", command2_time);
    printf(" copy file   : %f\n", command3_time);
    
    
    return 0;
}
