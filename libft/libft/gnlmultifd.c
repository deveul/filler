/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 12:18:19 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/11/14 16:40:31 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_free_all(void *tofree, size_t useless)
{
	(void)useless;
	ft_strdel(&(((t_data*)tofree)->str));
	free(tofree);
	tofree = NULL;
}

static int	ft_lstrmone(t_list **b, t_list *to_del, void (*del)(void *, size_t))
{
	t_list *previous;
	t_list *current;

	current = *b;
	if (current == to_del)
	{
		*b = current->next;
		ft_lstdelone(&current, del);
		return (0);
	}
	while (current->next)
	{
		previous = current;
		current = current->next;
		if (current == to_del)
		{
			previous->next = current->next;
			ft_lstdelone(&current, del);
			return (0);
		}
	}
	return (0);
}

static char	*ft_streraseuntilc(char *src, char c)
{
	int		i;
	int		a;
	char	*new;

	i = 0;
	a = 0;
	while (src[i] && src[i] != c)
		i++;
	if (!src[i])
	{
		if ((new = ft_memalloc(1)) == 0)
			return (NULL);
	}
	else
	{
		if ((new = ft_memalloc((ft_strlen(src) - i))) == 0)
			return (NULL);
		i++;
		while (src[i])
			new[a++] = src[i++];
	}
	ft_strdel(&src);
	return (new);
}

t_list		*ft_block_of_fd(t_list **begin, const int fd)
{
	t_list	*news;
	t_list	*tmp;
	t_data	*data;

	if (!(*begin))
	{
		*begin = ft_lstnew(&data, sizeof(t_data));
		tmp = *begin;
		((t_data*)tmp->content)->fd = fd;
		((t_data*)tmp->content)->str = NULL;
		return (tmp);
	}
	tmp = *begin;
	while (tmp && tmp->content)
	{
		if (((t_data*)tmp->content)->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	if ((news = ft_lstnew(&data, sizeof(t_data))) == NULL)
		return (NULL);
	ft_lstadd(begin, news);
	((t_data*)news->content)->fd = fd;
	((t_data*)news->content)->str = NULL;
	return (news);
}

int			get_next_line(const int fd, char **line)
{
	int				ret;
	char			buf[BUFF_SIZE + 1];
	static t_list	*begin = NULL;
	t_list			*tmp;
	char			*str;

	if ((fd < 0 || read(fd, buf, 0) < 0) || !line
			|| !(((tmp = ft_block_of_fd(&begin, fd)))))
		return (-1);
	str = ((t_data*)tmp->content)->str;
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if ((str = ft_strjoinfree(str, buf)) == 0)
			return (-1);
		if (ft_memchr(buf, '\n', ret))
			break ;
	}
	if ((ret < BUFF_SIZE && (!str || !ft_strlen(str))))
		return (ft_lstrmone(&begin, tmp, &ft_free_all));
	if (!(*line = ft_strndup(str, ft_strlenuntilc(str, '\n')))
			|| !(str = ft_streraseuntilc(str, '\n')))
		return (-1);
	return (1);
}
