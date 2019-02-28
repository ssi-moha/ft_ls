/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <ssi-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 19:05:19 by ssi-moha          #+#    #+#             */
/*   Updated: 2019/02/28 19:27:26 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void    split_list(t_file *file_list, t_file **front_list, t_file **back_list)
{
    t_file *fast;
    t_file *slow;

    slow = file_list;
    fast = file_list->next;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next; 
            fast = fast->next; 
        }
    }
    *front_list = file_list;
    *back_list = slow->next;
    slow->next = NULL;
}

void    print_list(t_file *file_list)
{
    t_file *tmp;

    tmp = file_list;
    if (!tmp)
    {
        printfast("empty list\n");
        return ;
    }
    
    while(tmp)
    {
        printfast("%s\n", tmp->name);
        tmp = tmp->next;
    }
}

int     sorting_condition(t_file *a, t_file *b, int options)
{
    int ret;

    ret = 0;
    if (check_option(options, 't'))
    {
        if (a->last_update_timestamp > b->last_update_timestamp)
            ret = -1;
        else if (a->last_update_timestamp < b->last_update_timestamp)
            ret = 1;
    }
    else
        ret = ft_strcmp(a->name, b->name);
    return (check_option(options, 'r') ? ret : -ret);
}

t_file *sorted_merge(t_file *a, t_file *b, int options)
{
    t_file *result = NULL;

    if (a == NULL) 
        return(b); 
    else if (b == NULL) 
        return(a);
    if (sorting_condition(a, b, options) > 0) 
    { 
        result = a; 
        result->next = sorted_merge(a->next, b, options); 
    } 
    else
    { 
        result = b; 
        result->next = sorted_merge(a, b->next, options); 
    }
    return (result);
}

void    sort_list(int options, t_file **file_list)
{
    t_file *front_list;
    t_file *back_list;

    (void)options;
    front_list = NULL;
    back_list = NULL;
    if (*file_list == NULL || (*file_list)->next == NULL)
        return;
    
    split_list(*file_list, &front_list, &back_list);
    
    sort_list(options, &front_list);
    sort_list(options, &back_list);
    
    //print_list(front_list);
    //print_list(back_list);

    *file_list = sorted_merge(front_list, back_list, options);
}