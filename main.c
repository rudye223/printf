#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - Custom printf function
 * @format: Format string
 * @...: Variable arguments
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
    int printed_chars = 0;
    va_list args;

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++; // Move past '%'
            if (*format == '\0') // If % is the last character, break the loop
                break;

            // Handle conversion specifiers
            if (*format == 'c')
            {
                char c = (char)va_arg(args, int);
                write(1, &c, 1);
                printed_chars++;
            }
            else if (*format == 's')
            {
                char *s = va_arg(args, char *);
                if (s)
                {
                    while (*s)
                    {
                        write(1, s, 1);
                        s++;
                        printed_chars++;
                    }
                }
            }
            else if (*format == '%')
            {
                write(1, "%", 1);
                printed_chars++;
            }
        }
        else
        {
            write(1, format, 1);
            printed_chars++;
        }
        
        format++;
    }

    va_end(args);

    return printed_chars;
}

