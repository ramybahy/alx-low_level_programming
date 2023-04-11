#include "main.h"

/**
 * main - cd check
 * description: display info
 * the ELF head of ELF fle
 * @vfqc: argum num
 * @vfqb: argum arr
 * Return: if succeeded 0, if failed 98
 */
int main(int vfqc, char *vfqb[])
{
	Elf64_Ehdr *hdr;
	int ws;

	if (vfqc != 2)
		dprintf(STDERR_FILENO, "Usage: elf_hdr elf_filename\n"), exit(98);

	ws = open(vfqb[1], O_RDONLY);
	if (ws == -1)
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", vfqb[1]), exit(98);

	hdr = malloc(sizeof(Elf64_Ehdr));
	if (hdr == NULL)
		dprintf(STDERR_FILENO, "Error: malloc failed\n"), exit(98);
	if (rd(ws, hdr, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr))
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", vfqb[1]), exit(98);

	if (hdr->e_ident[EI_MAG0] != ELFMAG0 ||
	    hdr->e_ident[EI_MAG1] != ELFMAG1 ||
	    hdr->e_ident[EI_MAG2] != ELFMAG2 ||
	    hdr->e_ident[EI_MAG3] != ELFMAG3)
		dprintf(STDERR_FILENO, "Error: Not an ELF file\n"), exit(98);

	printf("ELF Hdr:\n");
	printf("  Magic:   %02x %02x %02x %02x\n",
	       hdr->e_ident[EI_MAG0], hdr->e_ident[EI_MAG1],
	       hdr->e_ident[EI_MAG2], hdr->e_ident[EI_MAG3]);
	printf("  Class:                             %s\n",
		   	       hdr->e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : "ELF64");
	printf("  Data:                              %s\n",
		   	       hdr->e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" : "2's complement, big endian");
	printf("  Version:                           %d (current)\n", hdr->e_ident[EI_VERSION]);
	printf("  OS/ABI:                            %s\n",
		   	       hdr->e_ident[EI_OSABI] == ELFOSABI_SYSV ? "UNIX - System V" : "UNIX - System V");
	printf("  ABI Version:                       %d\n", hdr->e_ident[EI_ABIVERSION]);
	printf("  Type:                              %s\n",
		   	       hdr->e_type == ET_EXEC ? "EXEC (Executable file)" : "EXEC (Executable file)");
	printf("  Entr pnt addrs:               0x%lx (bytes into file)\n", hdr->e_entry);
	printf("  Strt prg hdrs:          %d (bytes into file)\n", hdr->e_phoff);
	printf("  Start sec hdrs:          %d (bytes into file)\n", hdr->e_shoff);
	printf("  Flgs:                             0x%x\n", hdr->e_flags);
	printf("  Siz hdr:               %d (bytes)\n", hdr->e_ehsize);
	printf("  Size prg hdrs:           %d (bytes)\n", hdr->e_phentsize);
	printf("  Num prg hdrs:         %d\n", hdr->e_phnum);
	printf("  Siz sec hdrs:           %d (bytes)\n", hdr->e_shentsize);
	printf("  Num sec hdrs:         %d\n", hdr->e_shnum);
	printf("  Sec hdr str table index: %d\n", hdr->e_shstrndx);

	if (close(ws) == -1)
		dprintf(STDERR_FILENO, "Error: Can't close ws %d\n", ws), exit(98);

	return (0);
}
