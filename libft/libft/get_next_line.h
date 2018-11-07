/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 11:19:05 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/10/25 18:25:54 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "./libft.h"
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# define BUFF_SIZE 1
# define STR ((t_data*)tmp->content)->str
# define FD ((t_data*)tmp->content)->fd

typedef struct		s_data
{
	char			*str;
	int				fd;
}					t_data;

int					get_next_line(const int fd, char **line);

#endif
