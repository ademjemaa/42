#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

size_t	ft_strlen(char *);
char	*ft_strcpy(char *, const char *);
int		ft_strcmp(const char *, const char *);
int		ft_write(int, const void *, size_t);
int		ft_read(int, const void *, size_t);
char	*ft_strdup(const char*);

int main()
{
	char s[6];
	char s1[7];
	char s2[6];
	char *s3;
	char *s4;
	char s5[11];
	int i;
	int j;
	j = -1;
	while (++j < 11)
		s5[j] = 0;
	s[5] = '\0';
	s[0] = 's';
	s[1] = 'a';
	s[2] = 'l';
	s[3] = 'u';
	s[4] = 't';
	printf("%s\n", s);
	printf("--- FT_STRLEN ---\n");
	printf("ft : [%zu]  real : [%zu]\n", ft_strlen(""), strlen(""));
	printf("ft : [%zu]  real : [%zu]\n", ft_strlen(s), strlen(s));
	printf("ft : [%zu]  real : [%zu]\n", ft_strlen(" "), strlen(" "));
	printf("--- FT_STRCPY ---\n");
	printf("source : [%s]  dest : [%s]\n",s, ft_strcpy(s2, s));
	printf("source : [%s]  dest : [%s]\n", "static", ft_strcpy(s1, "static"));
	printf("--- FT_STRCMP ---\n");
	printf("ft : [%d]  real : [%d]\n", ft_strcmp("", ""), strcmp("", ""));
	printf("ft : [%d]  real : [%d]\n", ft_strcmp("", " "), strcmp("", " "));
	printf("ft : [%d]  real : [%d]\n", ft_strcmp("  ", "  "), strcmp("  ", "  "));
	printf("ft : [%d]  real : [%d]\n", ft_strcmp("salut", "coucou"), strcmp("salut", "coucou"));
	printf("ft : [%d]  real : [%d]\n", ft_strcmp("13", "12"), strcmp("13", "12"));
	printf("ft : [%d]  real : [%d]\n", ft_strcmp("1113", "1116"), strcmp("1113", "1116"));
	printf("ft : [%d]  real : [%d]\n", ft_strcmp(s, s2), strcmp(s, s2));
	printf("--- FT_WRITE ---\n");
	ft_write(1, "voila le write\n", 15);
	printf("--- FT_READ ---\n taille de la chaine max  : 10\n");
	i = ft_read(0, s5, 10);
	printf("la valeur de retour du read est de : [%d] et la chaine est : [%s]\n", i, s5);
	printf("--- FT_STRDUP ---\n");
	s3 = ft_strdup("ara7");
	printf("nouvelle chaine : [%s]\n", s3);
	s4 = ft_strdup(s1);
	printf("nouvelle chaine : [%s]\n", s4);
	free(s4);
	free(s3);
}
