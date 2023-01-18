/*
    Esercizio 1 - pratiche 2021.09.16

    - creare una directory chiamata exec
    - scrivere un programma execname che se fiene aggiunto un file nella directory exec interpreti il nome del file come comando con parametri, lo esegua e cancelli il file.
es: sopo aver lanciato execname:
 execname exec
a seguito di questo comando:
 touch 'exec/echo ciao mare'
il programma stampa:
 ciao mare
(consiglio, usare inotify)
    **************************
    Cosa useremo:
       inotify := meccanismo del kernel che idividua i file
       readdir() := 
*/

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h> 
char* files[1000];
int fileslen=0;
void func(){
	DIR* dir = opendir(".");
	struct dirent* entity;
	while ((entity = readdir(dir)) != NULL){
		int j=0;
		for(j=0; j<fileslen; j++){
			if (strcmp(files[j], entity->d_name)==0) break; //se il singolo elemento era giÃ  presente nella dir...
		}
		if (j == fileslen) {
			printf("nuovo file trovato: %s\n", entity->d_name);
			files[fileslen++] = entity->d_name;
		}
	}
}
int main(int argc, char *argv[]){
	mkdir(argv[1], 0754); //x = 4 w = 2 r = 1 somma
	chdir(argv[1]);
	DIR* dir = opendir(".");
	if (dir == NULL){
		printf("errore\n");
		return 1;
	}
	struct dirent* entity;
	while ((entity = readdir(dir)) != NULL){
		files[fileslen++] = entity->d_name;
	}
	closedir(dir);
	while (1){
		sleep(2);
		func();
	}
	return 0;
}
