#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void checking_elf(unsigned char *e_ident);
void printing_magic(unsigned char *e_ident);
void printing_class(unsigned char *e_ident);
void printing_data(unsigned char *e_ident);
void printing_version(unsigned char *e_ident);
void printing_abi(unsigned char *e_ident);
void printing_osabi(unsigned char *e_ident);
void printing_type(unsigned int e_type, unsigned char *elf_ident);
void printing_entry(unsigned long int e_entry, unsigned char *elf_ident);
void closing_elf(int elf);

/**
 * checking_elf - A function that checks if a file is an ELF file.
 * @e_ident: A pointer
 * Return: void
 */

void checking_elf(unsigned char *e_ident)
{
	int idx;

	for (idx = 0; idx < 4; idx++)
	{
		if (e_ident[idx] != 127 &&
		    e_ident[idx] != 'E' &&
		    e_ident[idx] != 'L' &&
		    e_ident[idx] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * printing_magic - A functuon that prints the magic numbers of an ELF
 * @e_ident: A pointer
 *
 * Return: void
 */

void printing_magic(unsigned char *e_ident)
{
	int idx;

	printf(" Magic: ");

	for (idx = 0; idx < EI_NIDENT; idx++)
	{
		printf("%02x", e_ident[idx]);

		if (idx == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * printing_class - A function that prints the class of an ELF.
 * @e_ident: A pointer
 * Return: void
 */

void printing_class(unsigned char *e_ident)
{
	printf(" Class: ");

	switch (e_ident[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * printing_data - A function that prints the data of an ELF
 * @e_ident: A pointer.
 * Return: void
 */
void printing_data(unsigned char *e_ident)
{
	printf(" Data: ");

	switch (e_ident[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 *printing_version - A function that prints
 * the version of an ELF header.
 * @e_ident: A pointer
 * Return: void.
 */
void printing_version(unsigned char *e_ident)
{
	 printf(" Version: %d",
			  e_ident[EI_VERSION]);

	switch (e_ident[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

/**
 * printing_osabi - A function that prints
 *  the OS/ABI of an ELF.
 * @e_ident: A pointer
 * Return: void
 */
void printing_osabi(unsigned char *e_ident)

{
	printf(" OS/ABI: ");

	switch (e_ident[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
 * printing_abi - A function that prints the ABI version of an ELF.
 * @e_ident: A pointer.
 * Return: void.
 */

void printing_abi(unsigned char *e_ident)
{
	printf(" ABI Version: %d\n",
		e_ident[EI_ABIVERSION]);
}

/**
 * printing_type - A function that prints the type of an ELF.
 * @e_type: ELF type
 * @e_ident: A pointer.
 * Return: void
 */
void printing_type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf(" Type: ");

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

/**
 * printing_entry - A function that prints
 * the entry point of an ELF.
 * @e_entry: Address of ELF
 * @e_ident: A pointer
 * Return: void
 */

void printing_entry(unsigned long int e_entry, unsigned char *e_ident)
{
	printf(" Entry point address: ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			  ((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);

	else
		printf("%#lx\n", e_entry);
}

/**
 * closing_elf - A function that closes an ELF file.
 * @elf: The file descriptor
 * Return: void.
 * Description: If file not closed, exit code 98.
 */
void closing_elf(int elf)

{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: not closed file descriptor %d\n", elf);
		exit(98);
	}
}

/**
 * main - A function that displays the information of the
 * ELF header.
 * @argc: The number of arguments
 * @argv: An array of pointers
 *
 * Return: Always 0 (success).
*/
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int op, rd;

	op = open(argv[1], O_RDONLY);
	if (op == -1)
	{
		dprintf(STDERR_FILENO, "Error: Couldn't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		closing_elf(op);
		dprintf(STDERR_FILENO, "Error: Coudn't read file %s\n", argv[1]);
		exit(98);
	}
	rd = read(op, header, sizeof(Elf64_Ehdr));
	if (rd == -1)
	{
		free(header);
		closing_elf(op);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file exists\n", argv[1]);
		exit(98);
	}

	checking_elf(header->e_ident);
	printf("ELF Header:\n");
	printing_magic(header->e_ident);
	printing_class(header->e_ident);
	printing_data(header->e_ident);
	printing_version(header->e_ident);
	printing_osabi(header->e_ident);
	printing_abi(header->e_ident);
	printing_type(header->e_type, header->e_ident);
	printing_entry(header->e_entry, header->e_ident);

	free(header);
	closing_elf(op);
	return (0);
}
