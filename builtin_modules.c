/*
 * Copyright (C) 2014 AliReza Forouzandeh Nezhad (aka alireza7991)
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

 #define EXCLUDE_ANF_EXT

 #include <stdio.h>
 #include <stdlib.h>
 #include <anf.h>

 void print_usage(anf_stat *a) {
 #ifdef ANF_INTERACTIVE
 	printf(
 		"\tAndroid Native Framework " VERSION "\n"
 		" %s -[s|z|h] param=val ...\n"
 		"\ts: set system parameter\n"
 		"\tz: flash zips\n"
 		"\th: help menu\n"
 		,a->vec[0]
 		);
 #endif
 }
