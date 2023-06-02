#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
  va_list args;
  int count = 0;

  va_start(args, format);

  while (*format != '\0')
  {
    if (*format == '%')
    {
      format++; //skip '%'
      if (*format == 'c')
      {
        count += printf("%c", va_arg(args, int));
      }
      else if (*format == 's')
      {
        count += printf("%s", va_arg(args, char *));
      }
      else if (*format == '%')
      {
        count += printf("%%");
      }
    }
    else
    {
      count += putchar(*format);
    }
    format++;
  }

  va_end(args);

  return count;
}
