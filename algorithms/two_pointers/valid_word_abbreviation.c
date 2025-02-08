#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int is_valid_abbreviation(char *str, char *abbr)
{
    int start = 0;
    int abbr_idx = 0;
    int num;
    while(str[start] != '\0')
    {
        if(abbr[abbr_idx] == '0')
        {
            return 0;
        }
        else if(!(abbr[abbr_idx] >= 'a' && abbr[abbr_idx] <= 'z'))
        {
            if(abbr[abbr_idx+1] != '\0' && !(abbr[abbr_idx+1] >= 'a' && abbr[abbr_idx+1] <= 'z'))
            {
                char *idx_str = malloc(3 * sizeof(char));
                idx_str[0] = abbr[abbr_idx];
                idx_str[1] = abbr[abbr_idx+1];
                idx_str[2] = '\0';
                num = atoi(idx_str);
                abbr_idx++;
                abbr_idx++;
            }
            else {
                num = atoi(&abbr[abbr_idx]);
                abbr_idx++;
            }
            while(num > 0)
            {
                start++;
                num--;
            }

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

    int valid_abbrev = is_valid_abbreviation(str, abbr);
    printf("%s \n", valid_abbrev?"Valid abbreviation":"Invalid abbreviation");

    return 0;
}
