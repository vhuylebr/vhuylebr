int             is_arrow(char *buf)
{
        if (buf[0] != 27 || buf[1] != 91)
                return (0);
        if (buf[2] == 65)
                return (1);
	if (buf[2] == 66)
		return (2);
	if (buf[2] == 67)
		return (3);
	if (buf[2] == 68)
		return (4);
	else
            	return (0);
}

int             is_space(char *buf)
{
 	return (buf[0] == 32);
}

int             is_bspace(char *buf)
{
 	return (buf[0] == 127);
}

int             is_del(char *buf)
{
 	return (buf[3] == 126);
}
