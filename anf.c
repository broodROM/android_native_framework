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

 #include <stdio.h>
 #include <stdlib.h>
 #include <fcntl.h>
 #include <string.h>
 #include <unistd.h>
 #include <anf.h>

 char *getval(char *a) {
 	while(*a!='=') { a++; }
 	return strdup(a+1);
 }

 char *getkey(char *s) {
 	char *a=strdup(s);
 	char *b=a;
 	while(*a!='\0') { if(*a=='=') { *a='\0'; break; } a++; }
 	return b;
 }

 unsigned isparam(char *s) {
 	while(*s!='\0') { if(*s=='=') { return 1; } s++; } return 0; 
 }

 void do_switch(unsigned char s,anf_stat *b) {
 	unsigned i,f;
 	// small credit to sean bright (http://www.seanbright.com) for using sizeof instead of while loop
 	for(i=0;i<sizeof(anf_ext)/sizeof(anf_ext[0]);i++) {
 		if(anf_ext[i].s==s) { anf_ext[i].func(b); f=1; }
 	}
 	if(!f) {
 	#ifdef ANF_INTERACTIVE
 		printf("invalid switch\n");
 	#endif
 		exit(EINVALIDSWITCH);
 	}
 }

 void hwset(char *path,char *val) {
 	int f=open(path,O_RDWR);
 	if(!f) {
 		#ifdef ANF_INTERACTIVE
 		perror("hwset");
 		#endif
 		exit(EOPENFAILED);
	}
	register unsigned s=strlen(val);
	register int rstat=write(f,val,strlen(val));
	if(rstat!=s) {
		#ifdef ANF_INTERACTIVE
		printf("hwset : write %s at %s failed\n",val,path);
		#endif
		exit(EWRITEFAILED);
	}
	fsync(f); // be sure data is written
	close(f); 
 }

 int main(int argc,char **argv) {
 	unsigned char nswitch=NULL;
 	unsigned i;
 	for(i=1;i<argc;i++) {
 		if(*argv[i]=='-') {
 			nswitch=argv[i][1];
 			break;
 		}
 	}
 	if(!nswitch) {
 		#ifdef ANF_INTERACTIVE
 		printf("no switch has been used!\n");
 		#endif
 		exit(ENOSWITCH);
 	}
 	anf_stat a;
 	a.c=argc;
 	a.vec=argv;
 	do_switch(nswitch,&a);
 }
