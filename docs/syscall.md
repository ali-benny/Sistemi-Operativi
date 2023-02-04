# syscall
- # stat - Get file status[*](https://www.unix.com/man-page/Linux/2/lstat/)
    *stat*  -> statistiche del file puntato dal path ed si esegue/riempie nel buf
    
    *lstat* ->        " - se il path è un symlink, allora ho le statistiche del link stesso, non del file a cui si riferisce.
    
    *fstat* ->        " - il file da "statisticare" è specificato da un file descriptor fd
  ```c
  #include <sys/types.h>// stat
  #include <sys/stat.h>//stat
  #include <unistd.h>//stat
  ```
  ```c
  int stat(const char *path, struct stat *buf);
  int lstat(const char *path, struct stat *buf);
  int fstat(int fd, struct stat *buf);
  ```
  All of these system calls **return** a stat structure, which contains the following fields:
  
  	   struct stat {
  	       dev_t	 st_dev;     /* ID of device containing file */
  	       ino_t	 st_ino;     /* inode number */
  	       mode_t	 st_mode;    /* protection */
  	       nlink_t	 st_nlink;   /* number of hard links */
  	       uid_t	 st_uid;     /* user ID of owner */
  	       gid_t	 st_gid;     /* group ID of owner */
  	       dev_t	 st_rdev;    /* device ID (if special file) */
  	       off_t	 st_size;    /* total size, in bytes */
  	       blksize_t st_blksize; /* blocksize for file system I/O */
  	       blkcnt_t  st_blocks;  /* number of 512B blocks allocated */
  	       time_t	 st_atime;   /* time of last access */
  	       time_t	 st_mtime;   /* time of last modification */
  	       time_t	 st_ctime;   /* time of last status change */
  	   };
  **Macro** definite per controllare il tipo di file usando il campo `st_mode`
  > Esempio di utilizzo: `S_ISDIR(s.st_mode)` dove s è un `struct state s;`
  
         S_ISREG(m)  is it a regular file?
  	   S_ISDIR(m)  directory?
  	   S_ISCHR(m)  character device?
  	   S_ISBLK(m)  block device?
  	   S_ISFIFO(m) FIFO (named pipe)?
  	   S_ISLNK(m)  symbolic link? (Not in POSIX.1-1996.)
  	   S_ISSOCK(m) socket? (Not in POSIX.1-1996.)
  
  - # Rimuovi il link[*](http://www.unix.com/man-page/Linux/2/unlink/)

        int unlink(const char *__name)
    Remove the link NAME.
  - # Trova il vero path di un symlink

        char *realpath(const char *__restrict__ __name, char *__restrict__ __resolved)
    **Return** the canonical absolute name of file NAME. 
    - If RESOLVED is null, the result is malloc'd; otherwise, 
    - if the canonical name is PATH_MAX chars or more, returns null with `errno' set to ENAMETOOLONG; 
    - if the name fits in fewer than PATH_MAX chars, returns the name in RESOLVED.
- # open - Apri ed eventualmente crea file o device[*](https://www.unix.com/man-page/Linux/2/open/)
  ```c
     #include <sys/types.h>
     #include <sys/stat.h>
     #include <fcntl.h>
  
     int open(const char *pathname, int flags);     // -> return open file descriptor | -1 se c'è un errore
     int open(const char *pathname, int flags, mode_t mode);
  
     int creat(const char *pathname, mode_t mode);
  ```
   ## Argument flags
  Access mode:  `O_RDONLY, O_WRONLY, or O_RDWR`.  These request  opening  the  file  read-only, write-only, or read/write, respectively.
  
  `O_APPEND` file creato in modalità di aggiunta di contenuti in coda al file
  
  `O_CREATE` se il file non esiste verrà creato
  
  `O_ASYNC` abilita il segnale guidato i/o
  
  `O_CLOEXEC` abilita la flag chiudi-in-caso-di-exec nel nuovo file descriptor
- # Send file[*](http://www.unix.com/man-page/Linux/2/sendfile/)
  ```c
  #include <sys/sendfile.h>
  ssize_t sendfile(int __out_fd, int __in_fd, off_t *__offset, size_t __count)
  ```
- # Copy file 
  ### my function
  ```c
  #include <stdio.h>
  #include <stdlib.h>
  #include <sys/types.h>	// stat, lstat
  #include <sys/stat.h>	// stat, lstat
  #include <unistd.h>		// stat, lstat
  #include <fcntl.h>		// stat, lstat
  #include <sys/sendfile.h>	// sendfile
  
  // copiare un file da una directory all'altra
  int copyfile(const char *directory, const char *name){
  	int fd = open(directory, O_RDONLY);
  	if (fd == -1) {
  		perror("open");
          return -1;    
  	}
  	int fd_copy = open(name, O_WRONLY | O_CREAT, 0666);		// 0666 = mode_t mode = e` il set of permission
  	struct stat stat_buf;
  	lstat(directory, &stat_buf);
  	sendfile(fd_copy, fd, 0, stat_buf.st_size);
  	close(fd_copy);
  	close(fd);
      return 0;
  }
  
  ```
- # Directory
  - ## opendir - aprire directory[*](https://man7.org/linux/man-pages/man3/opendir.3.html)
    ```c
    #include <sys/types.h>
    #include <dirent.h>
    DIR *opendir(const char *__name)
    
    ```
    Open a directory stream on NAME.
    Return a DIR stream on the directory, or NULL if it could not be opened.
  - ## readdir - leggere directory[*](https://man7.org/linux/man-pages/man3/readdir.3.html)  
    ```c
    #include <dirent.h>
    struct dirent *readdir(DIR *directory_pointer);
    ```
    ### return
    - struttura:
    
          struct dirent {
             ino_t          d_ino;       /* Inode number */
             off_t          d_off;       /* Not an offset; see below */
             unsigned short d_reclen;    /* Length of this record */
             unsigned char  d_type;      /* Type of file; not supported
                                            by all filesystem types */
             char           d_name[256]; /* Null-terminated filename */
          };
    - NULL con/senza errno
- # realpath - absolute pathname[*](https://man7.org/linux/man-pages/man3/realpath.3.html)
  ```c
  #include <limits.h>
  #include <stdlib.h>
  
  char *realpath(const char *restrict path, char *restrict resolved_path);
  ```
  ### return
  - pointer to the resolved_path
  - NULL -> undefined path & errno
  ### const
  - `PATH_MAX` = 4096      //! BUGS
  - `NAME_MAX`