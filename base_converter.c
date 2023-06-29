#include <stdio.h>
#include <math.h>
#include <string.h>

int main(){
  int Input_Base = 0;
  int Output_Base = 0;
  char Input_Value[40];
  char Output_Value[40];

  //Part 1 : Covert Input Value to Base 10 Integer

  printf("Enter initial base: ");
  scanf("%d", &Input_Base);
  printf("Enter base-%d representation: ", Input_Base);
  scanf("%s", Input_Value);

  int Input_Value_Length = 0;
  Input_Value_Length = strlen(Input_Value);

  int Input_Max_Power = 0;
  Input_Max_Power = Input_Value_Length - 1;

  char Single_Number_Char;
  int Position_Index = 0;
  int Single_Number_Int = 0;
  unsigned int Current_Base_Power = 1;
  unsigned int Output_Value_Base10 = 0;

  for(int j = 0; j < Input_Max_Power; ++j){
    Current_Base_Power *= Input_Base;
  }

  while(Input_Max_Power >= 0){
    Single_Number_Char = Input_Value[Position_Index];
    Single_Number_Int = Single_Number_Char;

    if(Single_Number_Int >= 65){
      Single_Number_Int -= 55;
    } else {
      Single_Number_Int -= 48;
    }

    Output_Value_Base10 += Current_Base_Power * Single_Number_Int;
    Current_Base_Power = Current_Base_Power / Input_Base;

    Input_Max_Power -= 1;
    Position_Index += 1;

    Single_Number_Int = 0;
  }

  //End of Part 1. Local Test Pass.

  //Part 2 : Conver Base 10 Integer to Desired Base Value

  printf("Enter desired base: ");
  scanf("%d", &Output_Base);

  int i = 0;
  if(Output_Value_Base10 == 0){
    Output_Value[i++] = '0';
    Output_Value[i] = '\0';
  }

  int remain = 0;
  while(Output_Value_Base10 != 0){
    remain = Output_Value_Base10 % Output_Base;
    if(remain > 9){
      Output_Value[i++] = 'A' + remain - 10;
    } else {
      Output_Value[i++] = '0' + remain;
    }
    Output_Value_Base10 = Output_Value_Base10 / Output_Base;
  }
  Output_Value[i] = '\0';
  i = 0;

  //End of Part 2.

  char Final_Output[40];
  int Final_Length = 0;
  Final_Length = strlen(Output_Value);
  Final_Length -= 1;

  while(Final_Length >= 0){
    Final_Output[i] = Output_Value[Final_Length];
    Final_Length -= 1;
    i += 1;
  }
  Final_Output[i] = '\0';

  printf("Base-%d representation: %s\n", Output_Base, Final_Output);

  return 0;

  //End of the program.
}
