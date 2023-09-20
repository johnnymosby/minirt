/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:14:28 by aguilmea          #+#    #+#             */
/*   Updated: 2023/09/20 20:50:15 by aguilmea         ###   ########.fr       */
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
Test(parser, get_number_elements)
{
	cr_assert(get_number_elements(NULL) == 0, "the filename is NULL" );
	cr_assert(get_number_elements("" ) == 0, "the filename is empty");
	cr_assert(get_number_elements("../testfiles/directory.rt") == 0, "the file is a directory");
	cr_assert(get_number_elements("../testfiles/get_number_elements/6elmts_basic_noNL_start_end.rt") == 6);
	cr_assert(get_number_elements("../testfiles/get_number_elements/6elmts_NL_start.rt") == 6);
	cr_assert(get_number_elements("../testfiles/get_number_elements/6elmts_NL_end.rt") == 6);
	cr_assert(get_number_elements("../testfiles/get_number_elements/6elmts_NL_between_elmts.rt") == 6);
}
