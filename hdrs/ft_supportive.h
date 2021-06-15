#ifndef FT_SUPPORTIVE_H
# define FT_SUPPORTIVE_H
# include "ft_printf.h"

void	ft_putnbr_fd(int n, int fd);

int		ft_isdigit(int ch);

int		ft_strlen(const char *str);

char	*ft_strchr( const char *string, int symbol);

void	ft_putnbr_base_fd(unsigned long long nbr, char *base, int fd);

void	extract_star(t_mask *mask, va_list *arg_list, int *val, int *shft);

int32_t	ft_max3(int32_t a, int32_t b, int32_t c);

int32_t	ft_max(int32_t a, int32_t b);

int32_t	ft_min(int32_t a, int32_t b);

#endif