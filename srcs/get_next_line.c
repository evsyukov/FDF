/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 17:14:46 by smanta            #+#    #+#             */
/*   Updated: 2019/10/21 20:03:03 by smanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void		ft_free_node(t_fd **afd, int fd)
{
	t_fd	*node_fd;

	node_fd = *afd;
	while (node_fd != NULL && node_fd->fd != fd)
		node_fd = node_fd->next;
	if (node_fd == NULL)
		return ;
	if (node_fd->prev == NULL && node_fd->next == NULL)
		*afd = NULL;
	if (node_fd->prev != NULL)
		(node_fd->prev)->next = node_fd->next;
	if (node_fd->next != NULL)
	{
		(node_fd->next)->prev = node_fd->prev;
		if (node_fd->prev == NULL)
			*afd = node_fd->next;
	}
	free(node_fd);
}

static t_fd		*ft_init(t_fd **afd, int fd)
{
	t_fd	*node_fd;

	node_fd = *afd;
	while (node_fd != NULL && node_fd->fd != fd)
		node_fd = node_fd->next;
	if (node_fd == NULL)
	{
		if ((node_fd = (t_fd *)malloc(sizeof(t_fd))) == NULL)
			return (NULL);
		ft_bzero(node_fd->buf, BUFF_SIZE + 1);
		node_fd->fd = fd;
		node_fd->ind = 0;
		node_fd->next = *afd;
		node_fd->prev = NULL;
		if (*afd != NULL)
			(*afd)->prev = node_fd;
		*afd = node_fd;
	}
	return (node_fd);
}

static char		*ft_subnjoin(char **line, char *src, size_t start, size_t size)
{
	char	*temp_line;
	char	*new_line;
	size_t	len;
	size_t	index;
	size_t	index_src;

	temp_line = *line;
	len = ft_strlen(temp_line);
	if ((new_line = (char *)malloc(sizeof(char) * (len + size + 1))) == NULL)
		return (NULL);
	index = 0;
	while (index < len)
	{
		new_line[index] = temp_line[index];
		index++;
	}
	index_src = 0;
	while (index_src < size)
	{
		new_line[index + index_src] = src[start + index_src];
		index_src++;
	}
	new_line[index + index_src] = '\0';
	free(temp_line);
	return (new_line);
}

static int		ft_check_buf_n(t_fd *node, char **line, int *flag)
{
	size_t	ind;

	if ((node->buf)[node->ind] != '\0')
	{
		if ((*flag)++ == 0 && (*line = ft_strnew(0)) == NULL)
			return (-1);
		ind = node->ind;
		while (node->buf[ind] != '\n' && node->buf[ind] != '\0')
			ind++;
		if (!(*line = ft_subnjoin(line, node->buf, node->ind, ind - node->ind)))
			return (-1);
		if ((node->buf)[ind] == '\n')
		{
			node->ind = ++ind;
			if (node->ind == BUFF_SIZE)
			{
				node->ind = 0;
				(node->buf)[0] = '\0';
			}
			return (1);
		}
		node->ind = 0;
		(node->buf)[0] = '\0';
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	int			ret;
	static t_fd	*fd_lst = NULL;
	t_fd		*node;
	int			check_n;
	int			flag;

	flag = 0;
	if (fd < 0 || !(node = ft_init(&fd_lst, fd)) || read(fd, node->buf, 0) < 0
			|| !line || (check_n = ft_check_buf_n(node, line, &flag)) == -1)
		return (-1);
	if (check_n == 1)
		return (1);
	while ((ret = read(fd, node->buf, BUFF_SIZE)) != 0)
	{
		if (ret < 0)
			return (-1);
		(node->buf)[ret] = '\0';
		if ((check_n = ft_check_buf_n(node, line, &flag)) != 0)
			return (check_n == 1 ? 1 : -1);
	}
	if (flag != 0)
		return (1);
	ft_free_node(&fd_lst, fd);
	return (0);
}
