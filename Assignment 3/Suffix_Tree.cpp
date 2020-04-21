#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
int find(char *doc, char *str);
int helper(const void *str1, const void *str2);
int count(char *str1, char *str2);
char *LCS(char *doc, char *str);
void findLCS(char **docs, char *str, int n);
int find(char *doc, char *str);
 
int main()
{
    setbuf(stdout,NULL);
    int n;
    scanf("%d", &n);
 
    char *docs[n];
    for (int i = 0; i < n; i++)
    {
        docs[i] = (char *)malloc(sizeof(char) * 3000);
        scanf("%s", docs[i]);
    }
 
   
    int q;
    scanf("%d", &q);
 
    char *strings[q];
    for (int i = 0; i < q; i++)
    {
        strings[i] = (char *)malloc(sizeof(char) * 300);
        scanf("%s", strings[i]);
    }

    int pos;
    int sdoc;
    int flag;
    int found;
    for (int i = 0; i < q; i++)
    {
        flag = 1;
        found = 0;
        for (int j = 0; j < n; j++)
        {
            
            pos = find(docs[j], strings[i]);
            if (pos >= 0)
            {
                found = 1;
                if (flag)
                {
                    flag = 0;
                    printf("%s\n", strings[i]);
                }
                printf("%d %d\n", j, pos);
            }
        }
        if (!found)
        {
            char *substr;
            char *lcs;
            int lcslen = 0;
            int substrlen = 0;
            int ind = -1;
 
            for (int j = 0; j < n; j++)
            {
                
                substr = LCS(docs[j], strings[i]);
              
                substrlen = strlen(substr);
                if (substrlen > lcslen)
                {
                    lcslen = substrlen;
                    lcs = substr;                 
                    ind = j;
                }
            }
 
            if (ind != -1)
            {
                int pos = find(docs[ind], lcs);
                printf("%s\n", lcs);
                printf("%d %d\n", ind, pos);
            }
            else
            {
                printf("-1\n");
            }
        }
    }
}
 
int find(char *doc, char *str)
{
    int n = strlen(doc);
    int m = strlen(str);
 
    if (n >= m)
    {
        int j;
        for (int i = 0; i < n - m; i++)
        {
            j = 0;
            while (j < m && doc[i + j] == str[j])
            {
                j++;
            }
            if (j == m)
            {
                return i;
            }
        }
    }
    return -1;
}
 
char* LCS(char *doc, char *str)
{
    int n = strlen(doc);
    int m = strlen(str);
    int total = n + m;
    char *stotal = (char*)malloc(sizeof(char)*(total+1));
    strcpy(stotal, doc);
    strcat(stotal, str);
    char *sarray[total];
    
    for (int i = 0; i < total; i++)
    {
        sarray[i] = stotal + i;
        
    }
    
    qsort(sarray, total, sizeof(char *), helper);
    
    int length = 0;
    int max = 0;
    int index = -1;
 

    for (int i = 0; i < (total - 1); i++)
    {
        if(sarray[i]-stotal < n && sarray[i+1]-stotal>=n)
        {
            
            length = count(sarray[i], sarray[i + 1]);
            
            if (length > max)
            {
                max = length;
                index = i;
            }
        }
    }
    if (index == -1)
    {
        return "";
    }
    int ind = 0;
    char *result = (char *)malloc(sizeof(char) * (max + 1));
    for (int i = 0; i < max; i++)
    {
        result[i] = sarray[index][i];
    }
    result[max] = '\0';
    return result;
}
 
int count(char *str1, char *str2)
{
    
    int n = strlen(str1);
    int m = strlen(str2);
    int size = n < m ? n : m;
    int i = 0;
    while (i < size)
    {
        if (str1[i] != str2[i])
        {
            break;
        }
        i++;
    }
    return i;
}
 
int helper(const void *str1, const void *str2)
{
    
    return strcmp((const char *)*(char**)str1, (const char *)*(char**)str2);
}    