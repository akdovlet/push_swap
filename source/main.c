/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 17:22:03 by akdovlet          #+#    #+#             */
/*   Updated: 2024/04/24 15:43:00 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Use as such: ARG=$(seq 500 | shuf | tr '\n' ' ')
// Or ARG=$(shuf -i 0-10000 -n 500 | tr '\n' ' ')
// Then: ./push_swap $ARG | ./checker $ARG
int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_val	val;
	long	*tab;

	if (ac == 1)
		return (0);
	val.size = 0;
	stack_a = NULL;
	stack_b = NULL;
	tab = parse_and_check(&stack_a, av, ac, &val);
	if (!tab)
		return (0);
	solver(&stack_a, &stack_b, &val, val.size);
	ps_lstclear(&stack_a, free);
	free(tab);
	return (0);
}
