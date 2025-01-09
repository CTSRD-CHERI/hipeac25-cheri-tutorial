/*
 * SPDX-License-Identifier: BSD-2-Clause
 * Copyright (c) 2024 Konrad Witaszczyk
 */
#include <err.h>
#include <stdio.h>
#include <stdlib.h>

char *cp;

int
main(int argc, char *argv[])
{

	cp = malloc(sizeof(*cp));
	if (cp == NULL)
		err(1, "malloc");
	*cp = 'c';			/* Allocated. */
	free(cp);
	*cp = 'c';			/* Freed, but in quarantine. */
	malloc_revoke();
	printf("%c\n", *cp);		/* Revoked. */
	exit(1);
}
