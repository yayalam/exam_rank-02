/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylambark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 14:58:54 by ylambark          #+#    #+#             */
/*   Updated: 2022/02/25 15:13:32 by ylambark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int ac, char **av)
{
    char noo[255] = {0};
    int i;
    i = -1;

    if (ac != 3)
    {
        write(1,"\n",1);
        return 0;
    }

    while(av[2][++i])
    {
        if (noo[(int) av[2][i]] == 0)
            noo[(int) av[2][i]] = 1;
    }

    i = -1;

    while(av[1][++i])
    {
        if (noo[(int) av[1][i]] == 1)
            write (1,&av[1][i],1);
            noo[(int) av[1][i]] = 0;
    }

    write(1,"\n",1);
    return 0;
}
