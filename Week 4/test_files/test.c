#include <stdio.h>

int main(void)
{
    FILE* input = fopen("file1.txt","w");
    char * ch;
    if (input != NULL)
    {
        fputs("This is a test", input);
        fputc('!',input);
        fputs("\nThis is the second test!\n",input);
        char* c = "This is the third test!";
        int a = 6;
        int b = 5;
        char* d = "This is the final test!";
        fprintf(input, "%s\n", c);
        fprintf(input, "%s\n", d);
        fprintf(input, "%i\n", a + b);
        fprintf(input, "%i\n", a + b);
        fprintf(input, "%i\n", a + b);
        fprintf(input, "%i\n", a + b);
        fprintf(input, "%i\n", a + b);
        fprintf(input, "%i\n", a + b);
        fclose(input);

    }
    fopen("file1.txt", "r");
    FILE* output = fopen("file2.txt", "w");
    if (output != NULL)
    {
        int input_arr[sizeof(input)];
        while (fread(&input_arr, sizeof(char), 1, input))
        {
            fwrite(&input_arr, sizeof(char), 1, output);
        }
        fclose(input);
        fclose(output);

    }


}