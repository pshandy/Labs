#ifndef _DYNAMIC_QUEUE_H
#define _DYNAMIC_QUEUE_H

# include <stdio.h>
# include <unistd.h>
# include <time.h>
# include <stdlib.h>
# include <signal.h>

typedef struct	s_record {
	char	data;
	struct s_record *next;
}				t_record;

int 		del();
int			is_empty();
void 		add(char data);
void 		print();
void		clear_queue();
t_record	*create_element(char data);

#endif
