#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include "libasm.h"

static void		test_ft_strlen(const char *s)
{
	printf("s=\"%s\"\n", s);
	printf("%13s %zu\n", "strlen(s):", strlen(s));
	printf("%13s %zu\n", "ft_strlen(s):", ft_strlen(s));
}

static void		test_ft_strcpy(const char *src)
{
	char		*dst;

	if (!(dst = (char*)malloc(sizeof(char) * (strlen(src) + 1))))
	{
		printf("malloc error!");
		return ;
	}
	printf("src=\"%s\"\n", src);
	printf("\n%14s \"%s\"\n", "strcpy dst:", strcpy(dst, src));
	free(dst);
	if (!(dst = (char*)malloc(sizeof(char) * (strlen(src) + 1))))
	{
		printf("malloc error!");
		return ;
	}
	printf("\n%14s \"%s\"\n", "ft_strcpy dst:", ft_strcpy(dst, src));
	free(dst);
}

static void		test_ft_strcmp(const char *s1, const char *s2)
{
	printf("s1=\"%s\"\n", s1);
	printf("s2=\"%s\"\n", s2);
	printf("%10s %i\n", "strcmp:", strcmp(s1, s2));
	printf("%10s %i\n", "ft_strcmp:", ft_strcmp(s1, s2));
}

static void		test_ft_strdup(const char *s1)
{
	char		*dst;

	dst = strdup(s1);
	printf("s1=\"%s\"\n", s1);
	printf("\n%10s \"%s\"\n", "strdup:", dst);
	free(dst);
	dst = ft_strdup(s1);
	printf("\n%10s \"%s\"\n", "ft_strdup:", dst);
	free(dst);
}

int				main(void)
{
	char		*empty_string;
	char		*very_long_string;
	char		*s;
	char		*s1;
	int			fd;
	int			fd_ft;
	int			fd_wrong;

	very_long_string = strdup("Давным-давно в далёкой галактике... Идёт гражданская война. Космические корабли повстанцев, наносящие удар с тайной базы, одержали первую победу в схватке со зловещей Галактической Империей. Во время сражения разведчикам повстанцев удалось похитить секретные чертежи главного оружия Империи — Звезды Смерти, бронированной космической станции, способной уничтожить целую планету. Преследуемая имперскими солдатами, принцесса Лея спешит до- мой на своём космическом корабле. При ней находятся похищенные чертежи, которые могут спасти её народ и вернуть свободу галактике…");
	empty_string = strdup("");
	s = strdup("1234567890");

	printf("******** LIBASM TESTS ********\n");

	printf("\n========= ft_strlen =========\n");
	printf("\n+++++++TEST 1 string\n");
	test_ft_strlen(s);
	printf("\n+++++++TEST 2 empty string\n");
	test_ft_strlen(empty_string);
	printf("\n+++++++TEST 3 very long string\n");
	test_ft_strlen(very_long_string);
	printf("\n========= ft_strcpy =========\n");
	printf("\n+++++++TEST 1 string\n");
	test_ft_strcpy(s);
	printf("\n+++++++TEST 2 empty string\n");
	test_ft_strcpy(empty_string);
	printf("\n+++++++TEST 3 very long string\n");
	test_ft_strcpy(very_long_string);
	printf("\n========= ft_strcmp =========\n");
	printf("\n+++++++TEST 1\n");
	test_ft_strcmp(empty_string, empty_string);
	printf("\n+++++++TEST 2\n");
	test_ft_strcmp(empty_string, s);
	printf("\n+++++++TEST 3\n");
	test_ft_strcmp(s, empty_string);
	printf("\n+++++++TEST 4\n");
	s1 = strdup("1237");
	test_ft_strcmp(s, s1);
	printf("\n+++++++TEST 5\n");
	test_ft_strcmp(s1, s);
	printf("\n+++++++TEST 6\n");
	test_ft_strcmp(s, s);
	printf("\n+++++++TEST 7\n");
	test_ft_strcmp(s1, s1);

	printf("\n========= ft_write =========\n");
	printf("\n+++++++TEST 1 write to stdout\n");
	free(s);
	s = strdup("Test write to stdout\n");
	fd = 1;
	fd_ft = 1;
	errno = 0;
	printf("write returns %zd and errno is %d\n", write(fd, s, strlen(s)), errno);
	errno = 0;
	printf("ft_write returns %zd and errno is %d\n", ft_write(fd_ft, s, strlen(s)), errno);
	printf("\n+++++++TEST 2 write to open fd\n");
	free(s);
	s = strdup("Test write to file\n");
	fd = open("file.txt", O_WRONLY);
	fd_ft = open("file_ft.txt", O_WRONLY);
	fd_wrong = open("wrong.file", O_WRONLY);
	errno = 0;
	printf("write returns %zd and errno is %d\n", write(fd, s, strlen(s)), errno);
	close(fd);
	errno = 0;
	printf("ft_write returns %zd and errno is %d\n", ft_write(fd_ft, s, strlen(s)), errno);
	close(fd_ft);
	printf("\n+++++++TEST 3 write to wrong fd\n");
	free(s);
	s = strdup("Test write to file wrong.file\n");
	errno = 0;
	printf("write returns %zd and errno is %d\n", write(fd_wrong, s, strlen(s)), errno);
	errno = 0;
	printf("ft_write returns %zd and errno is %d\n", ft_write(fd_wrong, s, strlen(s)), errno);

	printf("\n========= ft_read =========\n");
	printf("\n+++++++TEST 1 read from stdin\n");
	fd = 0;
	free(s);
	if(!(s = (char*)calloc(5, sizeof(char))))
	{
		printf("calloc error!");
		return (-1);
	}
	printf("Print not more than 4 characters and press Enter:\n");
	errno = 0;
	printf("read returns %zd and errno is %d\n", read(fd, s, 5), errno);
	printf("Your string read with read is: \"%s\"\n", s);
	free(s);
	fd_ft = 0;
	if(!(s = (char*)calloc(5, sizeof(char))))
	{
		printf("calloc error!");
		return (-1);
	}
	printf("Repeat your input and press Enter:\n");
	errno = 0;
	printf("ft_read returns %zd and errno is %d\n", ft_read(fd_ft, s, 5), errno);
	printf("Your string read with ft_read is: \"%s\"\n", s);
	printf("\n+++++++TEST 2 read from an open fd\n");
	free(s);
	if(!(s = (char*)calloc(29, sizeof(char))))
	{
		printf("calloc error!");
		return (-1);
	}
	free(s1);
	if(!(s1 = (char*)calloc(29, sizeof(char))))
	{
		printf("calloc error!");
		return (-1);
	}
	fd = open("file.txt", O_RDONLY);
	fd_ft = open("file_ft.txt", O_RDONLY);
	errno = 0;
	printf("read returns %zd and errno is %d\n", read(fd, s, 28), errno);
	printf("Read from the file.txt: \"%s\"\n", s);
	close(fd);
	errno = 0;
	printf("ft_read returns %zd and errno is %d\n", ft_read(fd_ft, s, 28), errno);
	printf("Read from the file_ft.txt: \"%s\"\n", s);
	close(fd_ft);
	printf("\n+++++++TEST 3 read from the wrong fd\n");
	free(s);
	if(!(s = (char*)calloc(29, sizeof(char))))
	{
		printf("calloc error!");
		return (-1);
	}
	errno = 0;
	printf("read returns %zd and errno is %d\n", read(fd_wrong, s, 28), errno);
	errno = 0;
	printf("ft_read returns %zd and errno is %d\n", ft_read(fd_wrong, s, 28), errno);
	printf("\n========= ft_strdup =========\n");
	printf("\n+++++++TEST 1\n");
	test_ft_strdup(s1);
	printf("\n+++++++TEST 2\n");
	test_ft_strdup(empty_string);
	printf("\n+++++++TEST 3\n");
	test_ft_strdup(very_long_string);
	printf("\n========= DONE =========\n");

	free(s);
	free(s1);
	free(empty_string);
	free(very_long_string);
	return (0);
}
