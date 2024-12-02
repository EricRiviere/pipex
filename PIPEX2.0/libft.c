#include "pipex.h"

void    ft_putstr_fd(int fd, const char *str)
{
    while (*str)
        write(fd, str++, 1);
}


size_t  ft_strlen(const char *str)
{
    size_t  i;

    i = 0;
    while (str[i])
        i++;
    return(i);
}

char    *ft_substr(const char *str, unsigned int start, size_t len)
{
    char    *dest;
    size_t  i;
    size_t  str_len;

    if (!str)
        return (NULL);
    str_len = ft_strlen(str);
    if (start >= str_len)
        len = 0;
    if (len > str_len - start)
        len = str_len - start;
    dest = malloc(sizeof(char) * (len + 1));
    if (!dest)
        return (NULL);
    i = 0;
    while (str[start] && i < len)
    {
        dest[i] = str[start];
        i++;
        start++;
    }
    dest[i] = 0;
    return (dest);
}

void    free_split(size_t i, char **arr)
{
    while (i > 0)
    {
        i--;
        free(arr[i]);
    }
    free(arr);
}

size_t count_words(const char *str, char c)
{
    size_t i;
    size_t words_nbr;

    i = 0;
    words_nbr = 0;
    while(str[i])
    {
        while(str[i] == c)
            i++;
        if (str[i])
            words_nbr++;
        while (str[i] && str[i] != c)
            i++;
    }
    return (words_nbr);
}

char    **in_split(const char *str, char c, char **arr, size_t words_nbr)
{
    size_t  i;
    size_t  j;
    size_t  start;

    i = 0;
    j = 0;
    while (i < words_nbr)
    {
        while(str[j] && str[j] == c)
            j++;
        start = j;
        while(str[j] && str[j] != c)
            j++;
        arr[i] = ft_substr(str, start, j - start);
        if (!arr[i])
        {
            free_split(i, arr);
            return (NULL);
        }
        i++;
    }
    arr[i] = NULL;
    return (arr);
}

char    **ft_split(const char *str, char c)
{
    size_t words_nbr;
    char    **arr;

    if (!str)
        return (NULL);
    words_nbr = count_words(str, c);
    arr = malloc(sizeof(char *) * (words_nbr + 1));
    if (!arr)
        return (NULL);
    arr = in_split(str, c, arr, words_nbr);
    return (arr);
}

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t  i;

    if (n == 0)
        return (0);
    i = 0;
    while (s1[i] && s1[i] == s2[i] && i < n - 1)
        i++;
    return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char    *ft_strnstr(const char *s, const char *f, size_t len)
{
    size_t f_len;

    f_len = ft_strlen(f);
    if (f_len == 0)
        return ((char *)s);
    while(*s && len >= f_len)
    {
        if (ft_strncmp(s, f, f_len) == 0)
            return ((char *)s);
        s++;
        len--;
    }
    return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
    size_t  i;
    size_t  j;
    size_t  s1_len;
    size_t  s2_len;
    char    *jstr;

    if (!s1 || !s2)
        return (NULL);
    s1_len = ft_strlen(s1);
    s2_len = ft_strlen(s2);
    jstr = malloc(sizeof(char) * (s1_len + s2_len + 1));
    if (!jstr)
        return (NULL);
    i = -1;
    while (s1[++i])
        jstr[i] = s1[i];
    j = -1;
    while (s2[++j])
        jstr[i++] = s2[j];
    jstr[i] = 0;
    return (jstr);
}