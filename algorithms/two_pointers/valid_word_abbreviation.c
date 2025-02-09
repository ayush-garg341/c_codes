#include<stdio.h>
#include<stdlib.h>

int is_valid_abbreviation(char *str, char *abbr, int len_str)
{
    int start = 0;
    int abbr_idx = 0;
    int num;
    int digit_count = 0;
    while(str[start] != '\0')
    {
        if(abbr[abbr_idx] == '0')
        {
            return 0;
        }
        else if(!(abbr[abbr_idx] >= 'a' && abbr[abbr_idx] <= 'z'))
        {
            digit_count = 1;
            while(abbr[abbr_idx+1] != '\0' && !(abbr[abbr_idx+1] >= 'a' && abbr[abbr_idx+1] <= 'z'))
            {
                digit_count++;
                abbr_idx++;
            }
            char* idx_int = malloc(sizeof(char) * (digit_count+1));
            int idx = 0;
            for(int i = abbr_idx - digit_count + 1; i <= abbr_idx; i++)
            {
                idx_int[idx] = abbr[i];
                idx++;
            }
            idx_int[idx] = '\0';
            num = atoi(idx_int);
            printf("num = %d \n", num);
            if(num > len_str - start)
            {
                return 0;
            }

            abbr_idx++;
            while(num > 0)
            {
                start++;
                num--;
            }

            free(idx_int);

        }
        else if(abbr[abbr_idx] != str[start])
        {
            return 0;
        }
        else {
            start++;
            abbr_idx++;
        }
    }

    return 1;
}

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        printf("Usage: ./a.out <str: string> <str: abbreviation>");
        exit(1);
    }
    char *str = argv[1];
    char *abbr = argv[2];

    int len = 0;
    while(str[len] != '\0')
    {
        len++;
    }
    int valid_abbrev = is_valid_abbreviation(str, abbr, len);
    printf("%s \n", valid_abbrev?"Valid abbreviation":"Invalid abbreviation");

    return 0;
}
