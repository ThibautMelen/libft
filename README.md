# 42-libft

## Defines
Name      | Value      |
----------|------------|
BUFF_SIZE | `1024`     |
SPLITTER  | `\n`       |

## Typedefs
Name   | Link            |
-------|-----------------|
t_byte | `unsigned char` |
t_list | `struct s_list` |

## Structures
Name   | Vars                                                      |
-------|-----------------------------------------------------------|
s_list | `void *content`<br>`size_t size`<br>`struct s_list *next` |

## Functions

### Memory
Function    | Prototype                                                             |
------------|-----------------------------------------------------------------------|
ft_memset   | `void *ft_memset(void *mem, int byte, size_t size)`                   |
ft_bzero    | `void ft_bzero(void *mem, size_t size)`                               |
ft_memcpy   | `void *(void *dest, const void *src, size_t size)`                    |
ft_memccpy  | `void *ft_memccpy(void *dest, const void *src, int chr, size_t size)` |
ft_memmove  | `void *ft_memmove(void *dest, const void *src, size_t size)`          |
ft_memchr   | `void *ft_memchr(const void *mem, int chr, size_t size)`              |
ft_memcpy   | `int ft_memcmp(const void *mem1, const void *mem2, size_t size)`      |
ft_memalloc | `void *ft_memalloc(size_t size)`                                      |
ft_memdel   | `void ft_memdel(void **ptr)`                                          |

### String
Function         | Prototype                                                             |
-----------------|-----------------------------------------------------------------------|
ft_strlen        | `size_t ft_strlen(const char *str)`                                   |
ft_strdup        | `char *ft_strdup(const char *str)`                                    |
ft_strcpy        | `char *ft_strcpy(char *dest, const char *src)`                        |
ft_strncpy       | `char *ft_strncpy(char *dest, const char *src, size_t size)`          |
ft_strcat        | `char *ft_strcat(char *str1, const char *str2)`                       |
ft_strncat       | `char *ft_strncat(char *str1, const char *str2, size_t size)`         |
ft_strlcat       | `size_t ft_strlcat(char *dest, const char *src, size_t size)`         |
ft_strchr        | `char *ft_strchr(const char *str, int chr)`                           |
ft_strrchr       | `char *ft_strrchr(const char *str, int chr)`                          |
ft_strstr        | `char *ft_strstr(const char *str, const char *search)`                |
ft_strnstr       | `char *ft_strnstr(const char *str, const char *search, size_t size)`  |
ft_strcmp        | `int ft_strcmp(const char *str1, const char *str2)`                   |
ft_strncmp       | `int ft_strncmp(const char *str1, const char *str2, size_t size)`     |
ft_strnew        | `char *ft_strnew(size_t size)`                                        |
ft_strdel        | `void ft_strdel(char **ptr)`                                          |
ft_strclr        | `void ft_strclr(char *str)`                                           |
ft_striter       | `void ft_striter(char *str, void (*f)(char *))`                       |
ft_strsub        | `char *ft_strsub(const char *str, unsigned int start, size_t size)`   |
ft_strjoin       | `char *ft_strjoin(const char *str1, const char *str2)`                |
ft_strjoinch     | `char *ft_strjoinch(const char *str, char chr)`                       |
ft_strtrim       | `char *ft_strtrim(const char *str)`                                   |
ft_strsplit      | `char **ft_strsplit(const char *str, char c)`                         |
ft_strupper      | `void ft_strupper(char *str)`                                         |
ft_strlower      | `void ft_strlower(char *str)`                                         |
ft_strcapitalize | `void ft_strcapitalize(char *str)`                                    |

### List
Function     | Prototype                                                 |
-------------|-----------------------------------------------------------|
ft_lstnew    | `t_list *ft_lstnew(const void *content, size_t size)`     |
ft_lstdel    | `void ft_lstdel(t_list **plist)`                          |
ft_lstlen    | `size_t ft_lstlen(t_list *list)`                          |
ft_lstadd    | `void ft_lstadd(t_list **plist, t_list *new)`             |
ft_lstaddi   | `void ft_lstaddi(t_list **plist, t_list *new, int index)` |
ft_lstpush   | `void ft_lstpush(t_list **plist, t_list *new)`            |
ft_lstremove | `void ft_lstremove(t_list **plist, t_list *elem)`         |
ft_lstget    | `t_list *ft_lstget(t_list *list, int index)`              |
ft_lstiter   | `void ft_lstiter(t_list *list, void (*f)(t_list *elem))`  |

### Writers
Function      | Prototype                                |
--------------|------------------------------------------|
ft_printf     | `int ft_printf(const char *format, ...)` |

### Testers
Function    | Prototype                          |
------------|------------------------------------|
ft_isblank  | `int ft_isblank(int chr)`          |
ft_islower  | `int ft_islower(int chr)`          |
ft_isupper  | `int ft_isupper(int chr)`          |
ft_isalpha  | `int ft_isalpha(int chr)`          |
ft_isdigit  | `int ft_isdigit(int chr)`          |
ft_isalnum  | `int ft_isalnum(int chr)`          |
ft_isascii  | `int ft_isascii(int chr)`          |
ft_isprint  | `int ft_isprint(int chr)`          |
ft_isnumber | `int ft_isnumber(const char *str)` |

### Converters
Function      | Prototype                                          |
--------------|----------------------------------------------------|
ft_atol       | `long ft_atol(const char *str)`                    |
ft_ltoa       | `char *ft_ltoa(intmax_t nbr)`                      |
ft_ultoa      | `char *ft_ultoa(uintmax_t nbr)`                    |
ft_ultoa_base | `char *ft_ultoa_base(uintmax_t nbr, uint8_t base)` |
ft_toupper    | `int ft_toupper(int chr)`                          |
ft_tolower    | `int ft_tolower(int chr)`                          |

### Readers
Function | Prototype                               |
---------|-----------------------------------------|
ft_gnl   | `int ft_gnl(const int fd, char **line)` |
