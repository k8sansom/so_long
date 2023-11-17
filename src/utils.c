#include "../inc/so_long.h"

void	ft_error (char *s, t_struct *game)
{
	
}

void	ft_free (char *arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free (arr[i]);
		i++;
	}
	free(arr);
}