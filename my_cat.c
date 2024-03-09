#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#define BUF_SIZE 4096

static void	putstr_fd(const char *str, int fd)
{
	unsigned int	n = 0;

	while (str[n])
		n++;
	write(fd, str, n);
}

static void	putfile(int fd)
{
	char			*buf; 
	unsigned int	bytes_read;

	buf = (char *)malloc(sizeof(char) * BUF_SIZE);
	if (!buf)
		return ;
	bytes_read = read(fd, buf, BUF_SIZE);
	while (bytes_read > 0)
	{
		write(1, buf, bytes_read);
		bytes_read = read(fd, buf, BUF_SIZE);
	}
}

int	main(int ac, char **av)
{
	int	i;
	int	fd;
	int	return_status;

	if (ac < 2)
	{
		putstr_fd("Usage:\tprogram [FILE...]\n", 2);
		exit(EXIT_FAILURE);
	}
	i = 1;
	return_status = 0;
	while (i < ac)
	{
		fd = open(av[i], O_RDONLY);
		if (fd <= 0)
		{
			putstr_fd("my_cat: ", 1);
			putstr_fd(av[i], 1);
			putstr_fd(": No such file or directory\n", 1);
			return_status = 1;
			i++;
			continue ;
		}
		putfile(fd);
		close(fd);
		i++;
	}
	return (return_status);
}
