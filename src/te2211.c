#include "common.h"


int longestConsec(const char* strarr[], int n, int k, int maxlength, char* max_str);
//  n - кол-во слов, k - кол-во слов в строчке , maxlength - максимальна€ длина строчки,
//  max_str - максимальна€ суммарна€ строка.
//  функци€ возвращает длину максимальной строки.  

int main()
{
    const char* starr[] = { "tree", "foling", "trashy", "blue", "abcdef", "uvwxyz" };
    const int starr_length = sizeof(starr);
    char* max_str = (char*)calloc(1, sizeof(char));;

    unsigned words = sizeof(starr) / sizeof(starr[0]);
    int longest = longestConsec(starr, words, 2, sizeof(starr), max_str);

    printf("Stroka: %s\nDlina: %d\n", max_str, longest);
}

int longestConsec(const char* inpstr[], int n, int k, int maxlength, char* max_str)
{
    int start = 0;
    int result = 0;

    if (n == 0 || k > n || k <= 0)
    {
        max_str = (char*)"Nothing";
    }
    else
    {
        int* length = (int*)calloc(maxlength, sizeof(int));

        if (length)
        {
            *length = '\0';

            for (int i = 0; i < n; ++i)
            {
                length[i] = strlen(inpstr[i]);
            }

            int max_sum = 0;
            int sum_temp = 0;

            for (int i = 0; i < (n - k + 1); i++)
            {
                for (int j = 0; j < k; j++)
                {
                    sum_temp = sum_temp + length[i + j];
                }

                if (sum_temp > max_sum)
                {
                    max_sum = sum_temp;
                    start = i;
                }
                sum_temp = 0;
            }

            free(length);

            for (int i = 0; i < k; i++)
            {
                const int buffer_length = sizeof(max_str) + sizeof(inpstr[start + i]);
                strcat_s(max_str, buffer_length, inpstr[start + i]);
            }

            int count = 0;

            while (max_str[count] != '\0')
            {
                count++;
                result++;
            }
        }
    }

    return result;
}

