/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylambark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 14:55:59 by ylambark          #+#    #+#             */
/*   Updated: 2022/02/25 14:56:20 by ylambark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdarg.h>
# include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

int ft_putstr(char *s)
{
    int i = 0;
    if (!s)
    {
        write(1, "(null)", 6);
        return (6);
    }
    while(s[i])
        ft_putchar(s[i++]);
    return (i);
}

int calcul_size_decimal(long long n)
{
    int k = 1;
    if (n < 0)
        k++;
    while(n >= 10 || n <= -10)
    {
        k++;
        n /= 10;
    }
    return (k);
}

int ft_putnbr(int k)
{
    long long n;
    n = k;
    if (n < 0)
    {
        n *= -1;
        ft_putchar('-');
    }
    if (n > 9)
        ft_putnbr(n / 10);
    ft_putchar(n % 10 + 48);
    return (calcul_size_decimal((long long)k));
}

int calcul_size_hexa(unsigned int n)
{
    int k = 1;
    while(n >= 16)
    {
        k++;
        n /= 16;
    }
    return (k);
}

int ft_putnbr_hexa(unsigned int k)
{
    unsigned int n = k;
    if (n > 15)
        ft_putnbr_hexa(n / 16);
    ft_putchar("0123456789abcdef"[n % 16]);
    return (calcul_size_hexa(k));
}

int ft_printf(char *str, ...)
{
    int len = 0;
    int i = 0;
    va_list arg;
    if (!*str)
		return (0);
    va_start(arg, str);
    while(str[len])
        len++;

    while(str[i])
    {
        if (str[i] == '%')
        {
            i++;
            if (str[i] == 'd')
            {
                len = len + ft_putnbr(va_arg(arg, int)) - 2;
                i++;
            }
            else if (str[i] == 's')
            {
                len = len + ft_putstr(va_arg(arg, char *)) - 2;
                i++;
            }
            else if (str[i] == 'x')
            {
                len = len + ft_putnbr_hexa(va_arg(arg, unsigned int)) - 2;
                i++;
            }
        }
        if (str[i] != '%' && str[i])
			ft_putchar(str[i++]);
    }
    va_end(arg);
    return (len);
}

// int main()
// {
//     printf("|%d|\n",ft_printf("%d%x%s",5654,56464,NULL));
//     printf("|%d|",printf("%d%x%s",5654,56464,NULL));
// }
