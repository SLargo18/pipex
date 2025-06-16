/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slargo-b <slargo-b@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:18:35 by slargo-b          #+#    #+#             */
/*   Updated: 2025/06/16 12:18:36 by slargo-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	if (!validate_args(argc, argv))
		is_error("ERROR: Invalid Arguments\n", 1, 1);
	ft_pipex(argv, envp);
	return (0);
}
