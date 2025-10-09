/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrio <mrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 18:05:21 by mrio              #+#    #+#             */
/*   Updated: 2025/10/09 19:50:50 by mrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft/ft_printf/ft_printf.h"
# include "libft/gnl/get_next_line.h"
# include "libft/libft.h"
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

void	handle_signal(int sig, siginfo_t *info, void *context);
void	send_string(int pid, char *str);

#endif
