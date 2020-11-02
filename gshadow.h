#ifndef _GSHADOW_H
#define _GSHADOW_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Structure of the group file.  */
struct sgrp {
	char *sg_namp; /* Group name */	
	char *sg_passwd; /* Encrypted password */
	char **sg_adm; /* Group administrator list */
	char **sg_mem; /* Group member list */
};

void setsgent(void);
void endsgent(void);
struct sgrp *getsgent(void);
struct sgrp *getsgnam(const char *__name);
struct sgrp *sgetsgent(const char *__string);
struct sgrp *fgetsgent(FILE *__stream);
int putsgent(const struct sgrp *__g, FILE *__stream);

#ifdef __cplusplus
}
#endif

#endif
