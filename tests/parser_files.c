/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_files.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:14:28 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/06 11:19:14 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

Test(parser, open_file)
{
	cr_assert(open_file(NULL) == -1, "the filename is NULL" );
	cr_assert(open_file("" ) == -1, "the filename is empty");
	cr_assert(open_file("../testfiles/open_file/wrongsufix1" ) == -1, "wrong suffix 1");
	cr_assert(open_file("../testfiles/open_file/wrongsufix2.rtt" ) == -1, "wrong suffix 2");
	cr_assert(open_file("../testfiles/open_file/wrongsufix3.r" ) == -1, "wrong suffix 3");
	cr_assert(open_file("../testfiles/directory.rt") == -1, "the file is a directory");
	cr_assert(open_file("../testfiles/open_file/doesnotexist.rt") == -1, "the file does not exist");
	cr_assert(open_file("../testfiles/open_file/file_okay.rt") > 0,"the file has 6elements");
}
