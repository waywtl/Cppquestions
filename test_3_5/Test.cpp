#define _CRT_SECURE_NO_WARNINGS 1

//╫╚╬ДвсеепР
char* sortSentence(char* s)
{
    int slen = strlen(s);
    char arr[10][201] = { 0 };
    char* start = s;
    char* end = s;
    for (size_t i = 0; i < slen; ++i)
    {
        if (isdigit(s[i]))
        {
            int len = end - start;
            strncpy(arr[s[i] - '0'], start, len);
            arr[s[i] - '0'][len] = ' ';
        }
        if (s[i] == ' ')
        {
            start = s + i + 1;
        }
        ++end;
    }
    char* retStr = (char*)malloc((slen + 1));
    memset(retStr, 0, slen + 1);
    for (int i = 0; i < 10; ++i)
    {
        strcat(retStr, arr[i]);
    }
    retStr[strlen(retStr) - 1] = '\0';
    return retStr;
}