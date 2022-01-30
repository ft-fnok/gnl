/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleik <nlalleik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 12:38:31 by nlalleik          #+#    #+#             */
/*   Updated: 2022/01/24 21:53:46 by nlalleik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE.H
# define GET_NEXT_LINE.H
# ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
# endif

# include <stddef.h>
// included for use of size_t type
# include <stdlib.h>
// include for use of malloc
# include <unistd.h>
// include for use of read

char	*get_next_line(int fd);


#endif