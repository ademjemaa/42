/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 17:12:37 by adjemaa           #+#    #+#             */
/*   Updated: 2019/12/01 17:14:18 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main()
{
	ft_printf("%*.*d\n", 15, -10, 5);
	printf("%*.*d\n", 15, -10, 5);
}
