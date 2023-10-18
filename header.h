#ifndef _SIMPLE_SHELL_HEADER_
#define _SIMPLE_SHELL_HEADER_
/* globals */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <wait.h>
#include <stdarg.h>
#include <limits.h>
/* globals end */

/* shell functions */
extern char **environ;
struct exit_struct
{
	char *exit_1;
	int exit_2;
};
typedef struct exit_struct exit_struct_t;
void free_struct(exit_struct_t *d);
exit_struct_t my_execute(char *cmd, char *envv[]);
int pre_line(void);
char *_strdup(char *str);
char *get_user_input(void);
void string_splitter(char *arr[], char *str, char *dlm);
char *path_finder(void);
char *starts_with(char *haystack, char *needle);
char *search_in_paths(char *command, char *pathlist[]);
int current_env(void);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _atoi(char *s);

/* shell functions end */

/* printf functions */
int _printf(const char *format, ...);
int _putchar(char c);
int _print_hex_item(int num, char casing);
int _print_hexa(unsigned int num, unsigned int iter, int flag, char casing);
int _print_int(unsigned int num, unsigned int iter, int flag);
int _print_signed_int(int n);
int _print_string(char *s);
int _switcher(const char *s, int i, va_list item, int len);
int _print_binary(unsigned int n);
int _print_octal(unsigned int num, unsigned int iter, int flag);
int _unsigned_checker(unsigned int num);
int _print_address(unsigned long int num);
int _print_char(char c);
int _special_str(char *s);
int _string_navigator(char c, char *s);
int _print_rot13(char *s);
int _print_rev(char *s);

/* printf functions end */
#endif
