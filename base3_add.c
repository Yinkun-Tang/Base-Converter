#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]){
  if(argc != 3){
    fprintf(stderr, "Wrong number of command-line arguments.\n");
    return 1;
  }

  int num1 = 0;
  int num2 = 0;
  int curr_num = 0;
  char curr_num_char;
  int carry_out = 0;

  int num_length = 0;
  num_length = strlen(argv[1]);
  char Final_Output[num_length + 1];
  Final_Output[num_length] = '\0';
  num_length -= 1;

  while(num_length >= 0){
    num1 = argv[1][num_length] - 48;
    num2 = argv[2][num_length] - 48;

    curr_num = num1 + num2 + carry_out;
    if(curr_num >= 3){
      carry_out = 1;
      curr_num -= 3;
    }

    curr_num_char = curr_num + 48;
    Final_Output[num_length] = curr_num_char;

    num_length -= 1;
  }

  printf("Base 3 addition %s + %s results in %s.\n", argv[1], argv[2], Final_Output);
  printf("Carry out is %d.\n", carry_out);
  return 0;
}
