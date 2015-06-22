/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/15 15:13:28 by ncharret          #+#    #+#             */
/*   Updated: 2015/05/15 17:10:37 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void		read_bmp(int fd, char *header, t_image *img)
{
	int		imgsize;
	int		datapos;

	datapos = *(int*)&(header[0x0A]);
	imgsize = *(int*)&(header[0x22]);
	img->width = *(int*)&(header[0x12]);
	img->height = *(int*)&(header[0x16]);
	if (datapos == 0)
		datapos = 54;
	if (imgsize == 0)
		imgsize = img->width * img->height * 3;
	img->data = (unsigned char*)malloc(sizeof(unsigned char) * imgsize);
	read(fd, img->data, imgsize);
	glGenTextures(1, &img->textureid);
	glBindTexture(GL_TEXTURE_2D, img->textureid);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width,
		img->height, 0, GL_BGR, GL_UNSIGNED_BYTE, img->data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
}

t_image		load_bmp(char *path)
{
	int		fd;
	char	header[54];
	t_image	img;

	if ((fd = open(path, O_RDONLY)) < 0)
	{
		img.data = NULL;
		ft_putendl("Error : can't open image");
	}
	else
	{
		if (read(fd, header, 54) != 54)
		{
			img.data = NULL;
			ft_putendl("Error : not a bmp file");
		}
		else if (header[0] != 'B' || header[1] != 'M')
		{
			img.data = NULL;
			ft_putendl("Error : Not a correct BMP file");
		}
		else
			read_bmp(fd, header, &img);
	}
	close(fd);
	return (img);
}
