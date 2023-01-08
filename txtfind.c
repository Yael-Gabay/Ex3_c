#include <stdio.h>
#include <string.h>

#define LINE 256
#define WORD 30


//The function reads a line of input from the user and stores it in the character array s. 
int get_line(char s[])
{
    int i = 0,c = 0;
    for (i = 0; i < LINE - 1 && c != '\n' && c!='\r'; ++i){
        if((c = getchar()) != EOF)
            if(c != '\r')
                s[i] = c;
            else
                s[i] = '\0';
            else
                return 0;
    }
    if (i == 0) return 1;   
    s[i] = '\0';
    return i;
}

//The function reads a word (a sequence of characters separated by whitespace) from the user and stores it in the character array w.
int getword(char w[])
{
    int c, i = 0;
    // Continue reading characters until end of word is reached
    while ( i < WORD - 1 && (c = getchar()) != EOF && c != ' ' && c != '\t' && c != '\n'){
        w[i] = c;
        i++;
    }
    if (c == '\n' && i == 0)
        w[i++] = c;
    w[i] = '\0';
    return i;
}

//The function checks if one string (str2) is a substring of another string (str1). 
int substring(char *str1, char *str2)
{
    if (strlen(str1) < strlen(str2)) // if the length of str2 longer than str1, it cant be cointained in str1
    {
        return 0;
    }
    int count = 0;
    for (int i = 0; i < strlen(str1); i++)
    {
        for (int j = 0; j < strlen(str2); j++)
        {
            if (str1[i + j] == str2[j])
            {
                count++;
            }
            else
            {
                count = 0;
                break;
            }
        }
        if (count == strlen(str2))
        {
            return 1;
        }
    }
    return 0;
}

/**
 * The function checks if string t is contained within string s, allowing for a maximum of n differences between the two strings. 
 * It does this by iterating through both strings, comparing characters and keeping track of the number of differences encountered. 
 * If the number of differences exceeds n, the function returns 0. 
 * Otherwise, it returns 1 if t is contained within s with a maximum of n differences.
*/
int similar(char *s, char *t, int n)
{
    if (strlen(s) - n != strlen(t))
    {
        return 0;
    }
    int i = 0;
    int j = 0;
    while (i < strlen(s) && j < strlen(t)) 
    {
        if (s[i] == t[j]) 
        {
            i++;
            j++;
            if (j == strlen(t))
            {
                return 1;
            }
        }
        else 
        {
            i++;
            n--;
        }
    }
    if (j == strlen(t) && i == strlen(s) && n == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/**
 * The function reads lines of input and prints them to the console if they contain a specified string. 
 * It does this by using a loop to read each line of input, checking if it contains the specified string, and printing it if it does. 
 * The loop continues until there are no more lines of input to read.
*/
void print_lines(char *str)
{
    char check[LINE];
    while (get_line(check) > 0)
    {
       if (substring(check, str) == 1)
        {
            printf("%s", check);
        }
    }
 }

/**
 * The function reads words and prints them to the console if they are similar to a specified string. 
 * It does this by using a loop to read each word, checking if it is similar to the specified string with a maximum of either 1 or 0 differences, and printing it if it is. 
 * The loop continues until there are no more words to read.
*/
void print_similar_words(char *str)
{
    char word[WORD];
    while (getword(word) > 0)
    {
        if (similar(word, str, 1) == 1 || similar(word, str, 0) == 1)
        {
            printf("%s\n", word);
        }
    }
}


int main()
{
    char word[WORD];
    getword(word);

    char check[LINE];
    get_line(check);

    char empty[LINE];
    get_line(empty);

    if (check[0] == 'a')
    {
        print_lines(word);
    }
    else if (check[0] == 'b')
    {
        print_similar_words(word);
    }

    return 0;
}