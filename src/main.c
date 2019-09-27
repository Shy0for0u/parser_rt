#include "../includes/rt.h"

void			del_array(char **array)
{
	int 		i;

	i = 0;
	while (array[i])
		i++;
	while (array[--i])
		ft_strdel(&array[i]);
	free(array);
}

int				get_center(t_rt *rt, char *line, int index)
{
	char 		**array;

	if (ft_chrcnt(line, ',') == 3)
	{
		array = ft_strsplit(line, ',');
		rt->memory[index].center[0] = atof(array[0]);
		rt->memory[index].center[1] = atof(array[1]);
		rt->memory[index].center[2] = atof(array[2]);
		rt->memory[index].center[3] = atof(array[3]);
		del_array(array);
		return (1);
	}
	return (0);
}

int				decision_base(char *str)
{
	int			i;

	i = 2;
	if (str[0] != '0' || str[1] != 'x')
	{
		while (str[i] && (ft_isdigit(str[i]) || (str[i] > 64 && str[i] < 71) || (str[i] > 96 && str[i] < 103)))
			i++;
		if (i > 3 && i < 9)
			return (16);
	}
	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) &&
			(str[i] < 65 || str[i] > 70) &&
			(str[i] < 97 || str[i] > 102))
			return (0);
		i++;
		if (i > 8)
			return (0);
	}
	if (i < 3)
		return (0);
	return (1);
}

int				get_color(t_rt *rt, char *line, int index)
{
	char 		**array;

	if (ft_chrcnt(line, ',') == 3)
	{
		array = ft_strsplit(line, ',');
		rt->memory[index].color[0] = (int)strtol(array[0], NULL, decision_base(array[0]));
		rt->memory[index].color[1] = (int)strtol(array[1], NULL, decision_base(array[1]));
		rt->memory[index].color[2] = (int)strtol(array[2], NULL, decision_base(array[2]));
		rt->memory[index].color[3] = (int)strtol(array[3], NULL, decision_base(array[3]));
		del_array(array);
		return (1);
	}


	return (0);
}

int				get_params(t_rt *rt, const char *line, int index)
{
	char 		*pnt;

	if ((pnt = ft_strchr(line, ':')))
	{
		if (ft_strncmp(line, "\tid:", (pnt - line)) == 0)
			rt->memory[index].id = ft_atoi(pnt + 2);
		if (ft_strncmp(line, "\tcenter:", (pnt - line)) == 0)
			get_center(rt, pnt + 1, index);
		if (ft_strncmp(line, "\tradius:", (pnt - line)) == 0)
			rt->memory[index].radius = atof(pnt + 2);
		if (ft_strncmp(line, "\tcolor:", (pnt - line)) == 0)
			get_color(rt, pnt + 1, index);
	}
//	if (ft_strcmp(line, "\tid:") == 0)
//	{
//		if ((pnt = ft_strchr(line, ':')))
//		{
//			rt->memory[index].id = ft_atoi((pnt + 1));
//		}
//	}
	return (0);
}

int 			check_obj(t_rt *rt, char *line, int index)
{
	if (ft_strcmp(line, "sphere:") == 0)
	{
		ft_strcpy(rt->memory[index].type_obj, line);
	}
	else
		return (0);
	return (1);
}

int				get_data(t_rt *rt, char *file)
{
	char 		*line;
	int 		fd;
	char 		buff[1];
	int 		index;

	index = 0;
	line = NULL;
	fd = open(file, O_RDONLY);
	if (read(fd, buff, 0) < 0 || fd < 0)
		return (5);
	while (get_next_line(fd, &line))
	{
		if (line[0] != '\t' && line[0] != '\n')
		{
			if (!check_obj(rt, line, index))
				return (0);
		}
		if (line[0] == '\t')
		{
			get_params(rt, line, index);
			continue ;
		}
		if (line[0] == '\n')
			index++;
	}
	ft_strdel(&line);
	close(fd);
	return (1);
}

int 			main(int argc, char *argv[])
{
	t_rt		rt;

	if (argc == 2)
		printf("Error number: %d \n", get_data(&rt, argv[1]));
	return 0;
}