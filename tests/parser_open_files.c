/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_open_files.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:14:28 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/13 12:53:41 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

Test(parser, open_file)
{
	int	fd;

	fd = open_file(NULL);
	cr_assert( fd < 0, "the filename is NULL");
	close(fd);

	fd = open_file("");
	cr_assert( fd < -0,  "the filename is empty");
	close(fd);

	fd = open_file("../testfiles/open_file/wrongsufix1");
	cr_assert( fd < 0 -1, "wrong suffix 1");
	close(fd);

	fd = open_file("../testfiles/open_file/wrongsufix2.rtt");
	cr_assert( fd < 0, "wrong suffix 2");
	close(fd);

	fd = open_file("../testfiles/open_file/wrongsufix3.r");
	cr_assert( fd < 0, "wrong suffix 3");
	close(fd);

	fd = open_file("../testfiles/directory.rt");
	cr_assert( fd < 0, "the file is a directory");
	close(fd);

	fd = open_file("../testfiles/open_file/doesnotexist.rt");
	cr_assert( fd < 0, "the file does not exist");
	close(fd);

	fd = open_file("../testfiles/open_file/file_okay.rt");
	cr_assert( fd > 0, "the file has 6elements");
	close(fd);
}
