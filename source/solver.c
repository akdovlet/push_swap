/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 15:33:10 by akdovlet          #+#    #+#             */
/*   Updated: 2024/04/11 13:53:25 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "ft_printf.h"

void	solver(t_list **stack_a, long *tab, int size)
{
	(void)tab;
	if (size <= 3)
	{
		if (size == 2)
			sort_two(stack_a);
		else if (size == 3)
			sort_three(stack_a);
	}
	// else if (size <= 5)
		// sort_five(stack_a, tab, size);
	// else
	// 	sort(stack_a, tab, size);
}

void	sort_two(t_list **stack_a)
{
	if ((long)(*stack_a)->content > (long)(*stack_a)->next->content)
		swap_a(stack_a, 1);
}

void	sort_three(t_list **stack_a)
{
	t_list *max;

	max = highest(*stack_a);
	if (*stack_a == max)
		rotate_a(stack_a, 1);
	else if ((*stack_a)->next == max)
		reverse_rotate_a(stack_a, 1);
	if ((long)(*stack_a)->content > (long)(*stack_a)->next->content)
		swap_a(stack_a, 1);
}

int	is_sorted(t_list *stack_a)
{
	while (stack_a->next)
	{
		if ((long)stack_a->content > (long)stack_a->next->content)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

t_list	*highest(t_list *lst)
{
	t_list	*tmp;
	t_list	*max;

	tmp = lst;
	max = lst;
	while (tmp)
	{
		if ((long)tmp->content > (long)max->content)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}
