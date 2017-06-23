
void	ft_bzero(char *s, int len)
{
	while (len-- > 0)
	  s[len] = 0;
}
