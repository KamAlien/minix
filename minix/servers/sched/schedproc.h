/* This table has one slot per process.  It contains scheduling information
 * for each process.
 */
#include <limits.h>

#include <minix/bitmap.h>

/* EXTERN should be extern except in main.c, where we want to keep the struct */
#ifdef _MAIN
#undef EXTERN
#define EXTERN
#endif

#ifndef CONFIG_SMP
#define CONFIG_MAX_CPUS 1
#endif

/**
 * Más adelante podríamos querer añadir más información a esta tabla, como el
 * propietario del proceso, el grupo del proceso o la máscara de CPU.
 */

EXTERN struct schedproc
{
	endpoint_t endpoint; /* id de endpoint del proceso */
	endpoint_t parent;	 /* id de endpoint del padre */
	unsigned flags;		 /* bits de banderas */

	/* Planificación en espacio de usuario */
	unsigned max_priority;								 /* la prioridad máxima permitida de este proceso */
	unsigned priority;									 /* la prioridad actual del proceso */
	unsigned time_slice;								 /* el quantum de tiempo de este proceso */
	unsigned count_quantums;							 /* el número de quantums que el proceso ha consumido */
	unsigned cpu;										 /* en qué CPU se está ejecutando el proceso */
	bitchunk_t cpu_mask[BITMAP_CHUNKS(CONFIG_MAX_CPUS)]; /* en qué CPUs tiene permitido ejecutarse el proceso */
} schedproc[NR_PROCS];

/* Flag values */
#define IN_USE 0x00001 /* set when 'schedproc' slot in use */
