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

 #define VERSION "1.0"

 #define ENOSWITCH 1
 #define EINVALIDSWITCH 2
 #define EOPENFAILED 4
 #define EWRITEFAILED 6

 typedef struct {
 	unsigned c;
 	char **vec;
 } anf_stat;

 char *getval(char *);
 char *getkey(char *);
 unsigned isparam(char *);
 void print_usage(anf_stat *);
 void hwset(char *,char *);
 void helloworld(anf_stat *); // declare new module

 char *strdup(char *);

 #define SWITCH(x,y) {x,&y},

 #ifndef EXCLUDE_ANF_EXT

 struct anf_ext_ {
 	unsigned char s;
 	void (*func)(anf_stat *);
 } anf_ext [] = {
 	// Add new switches here 
 	// first argument is the character of switch and second argument is the function which handles the switch's calls
 	SWITCH('h',print_usage)
 	SWITCH('H',helloworld) // attach it to a switch !
};
 #endif
