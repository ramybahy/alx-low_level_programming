#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void check_elf(unsigned char *e_idntf);
void print_magic(unsigned char *e_idntf);
void print_class(unsigned char *e_idntf);
void print_data(unsigned char *e_idntf);
void print_version(unsigned char *e_idntf);
void print_abi(unsigned char *e_idntf);
void print_osabi(unsigned char *e_idntf);
void print_type(unsigned int e_type, unsigned char *e_idntf);
void print_entry(unsigned long int e_entry, unsigned char *e_idntf);
void close_elf(int elf);

/**
 * check_elf - file check
 * @e_idntf: elf magic num arr
 * Description: exit code 98 if not elf file
 */
void check_elf(unsigned char *e_idntf)
{
	int idx;

	for (idx = 0; idx < 4; idx++)
	{
		if (e_idntf[idx] != 127 &&
		    e_idntf[idx] != 'E' &&
		    e_idntf[idx] != 'L' &&
		    e_idntf[idx] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an elf file\n");
			exit(98);
		}
	}
}

void print_magic(unsigned char *e_idntf)
{
	int idx;

	printf("  Magic:   ");

	for (idx = 0; idx < EI_NIDENT; idx++)
	{
		printf("%02x", e_idntf[idx]);

		if (idx == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

void print_class(unsigned char *e_idntf)
{
	printf("  Class:                             ");

	switch (e_idntf[EI_CLASS])
	{
	case elfCLASSNONE:
		printf("none\n");
		break;
	case elfCLASS32:
		printf("elf32\n");
		break;
	case elfCLASS64:
		printf("elf64\n");
		break;
	default:
		printf("<unknown: %x>\n", e_idntf[EI_CLASS]);
	}
}

void print_data(unsigned char *e_idntf)
{
	printf("  Data:                              ");

	switch (e_idntf[EI_DATA])
	{
	case elfDATANONE:
		printf("none\n");
		break;
	case elfDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case elfDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", e_idntf[EI_CLASS]);
	}
}

void print_version(unsigned char *e_idntf)
{
	printf("  Version:                           %d",
	       e_idntf[EI_VERSION]);

	switch (e_idntf[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

void print_osabi(unsigned char *e_idntf)
{
	printf("  OS/ABI:                            ");

	switch (e_idntf[EI_OSABI])
	{
	case elfOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case elfOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case elfOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case elfOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case elfOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case elfOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case elfOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case elfOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case elfOSABI_ARM:
		printf("ARM\n");
		break;
	case elfOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", e_idntf[EI_OSABI]);
	}
}

void print_abi(unsigned char *e_idntf)
{
	printf("  ABI Version:                       %d\n",
	       e_idntf[EI_ABIVERSION]);
}

void print_type(unsigned int e_type, unsigned char *e_idntf)
{
	if (e_idntf[EI_DATA] == elfDATA2MSB)
		e_type >>= 8;

	printf("  Type:                              ");

	switch (e_type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", e_type);
	}
}

void print_entry(unsigned long int e_entry, unsigned char *e_idntf)
{
	printf("  Entry point address:               ");

	if (e_idntf[EI_DATA] == elfDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			  ((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (e_idntf[EI_CLASS] == elfCLASS32)
		printf("%#x\n", (unsigned int)e_entry);

	else
		printf("%#lx\n", e_entry);
}

void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", elf);
		exit(98);
	}
}

int main(int __attribute__((__unused__)) vfqc, char *vfqb[])
{
	elf64_Ehdr *hdr;
	int s, t;

	s = open(vfqb[1], O_RDONLY);
	if (s == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", vfqb[1]);
		exit(98);
	}
	hdr = malloc(sizeof(elf64_Ehdr));
	if (hdr == NULL)
	{
		close_elf(s);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", vfqb[1]);
		exit(98);
	}
	t = read(s, hdr, sizeof(elf64_Ehdr));
	if (t == -1)
	{
		free(hdr);
		close_elf(s);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", vfqb[1]);
		exit(98);
	}

	check_elf(hdr->e_idntf);
	printf("elf hdr:\n");
	print_magic(hdr->e_idntf);
	print_class(hdr->e_idntf);
	print_data(hdr->e_idntf);
	print_version(hdr->e_idntf);
	print_osabi(hdr->e_idntf);
	print_abi(hdr->e_idntf);
	print_type(hdr->e_type, hdr->e_idntf);
	print_entry(hdr->e_entry, hdr->e_idntf);

	free(hdr);
	close_elf(s);
	return (0);
}
