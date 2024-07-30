#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_COMBINATIONS 100000

void generate_combinations(char **data, int data_size, FILE *output) {
    for (int i = 0; i < data_size; i++) {
        for (int j = 0; j < data_size; j++) {
            if (i != j) {
                fprintf(output, "%s%s\n", data[i], data[j]);
                fprintf(output, "%s%s\n", data[j], data[i]);
            }
        }
    }
}

int main(int argc, char *argv[])
{
  if(argc != 3)
  {
    fprintf(stderr, "Usage: %s <input_file.csv> <output_file.txt>\n", argv[0]);
    return EXIT_FAILURE;
  }

  FILE *input = fopen(argv[1], "r");
  if(!input)
  {
    perror("Error opening input file");
    return EXIT_FAILURE;
  }
  
  FILE *output = fopen(argv[2], "w");
  if(!output)
  {
    perror("Error opening output file");
    return EXIT_FAILURE;
  }

  char line[MAX_LINE_LENGTH];
    char *data[MAX_COMBINATIONS];
    int data_size = 0;

    while (fgets(line, sizeof(line), input) && data_size < MAX_COMBINATIONS) {
        line[strcspn(line, "\n")] = 0;
        data[data_size] = strdup(line);
        data_size++;
    }

    fclose(input);

    generate_combinations(data, data_size, output);

    fclose(output);

    for (int i = 0; i < data_size; i++) {
        free(data[i]);
    }

    printf("Dictionary generated successfully.\n");

    return 0;

  return EXIT_SUCCESS;
}
