#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void checking_elf(unsigned char *elf_ident);
void printing_magic(unsigned char *elf_ident);
void printing_class(unsigned char *elf_ident);
void printing_data(unsigned char *elf_ident);
void printing_version(unsigned char *elf_ident);
void printing_abi(unsigned char *elf_ident);
void printing_osabi(unsigned char *elf_ident);
void printing_type(unsigned int elf_type, unsigned char *elf_ident);
void printing_entry(unsigned long int elf_entry, unsigned char *elf_ident);
void closing_elf(int elf);

/**
 * checking_elf - A function that checks if a file is an ELF file.
 * @elf_ident: A pointer
 *
 * Return: void
 */

void checking_elf(unsigned char *elf_ident)
{
	int idx;

	for (idx = 0; idx < 4; idx++)
	{
		if (elf_ident[idx] != 127 &&
		    elf_ident[idx] != 'E' &&
		    elf_ident[idx] != 'L' &&
		    elf_ident[idx] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * printing_magic - A functuon that prints the magic numbers of an ELF
 * @elf_ident: A pointer
 *
 * Return: void
 */

void printing_magic(unsigned char *elf_ident)
{
	int idx;

	printf(" Magic: ");

	for (idx = 0; idx < EI_NIDENT; idx++)
	{
		printf("%02x", elf_ident[idx]);

		if (idx == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * printing_class - A function that prints the class of an ELF.
 * @elf_ident: A pointer
 * Return: void
 */

void printing_class(unsigned char *elf_ident)
{
	printf(" Class: ");

	switch (elf_ident[EI_CLASS])
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
		printf("<unknown: %x>\n", elf_ident[EI_CLASS]);
	}
}

/**
 * printing_data - A function that prints the data of an ELF
 * @elf_ident: A pointer.
 * Return: void
 */
void printing_data(unsigned char *elf_ident)
{
	printf(" Data: ");

	switch (elf_ident[EI_DATA])
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
		printf("<unknown: %x>\n", elf_ident[EI_CLASS]);
	}
}

/**
 *printing_version - A function that prints
 * the version of an ELF header.
 * @elf_ident: A pointer
 * Return: void.
 */
void printing_version(unsigned char *elf_ident)
{
	 printf(" Version: %d",
			  elf_ident[EI_VERSION]);

	switch (elf_ident[EI_VERSION])
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
 * @elf_ident: A pointer
 */
void printing_osabi(unsigned char *elf_ident)

{
	printf(" OS/ABI: ");

	switch (elf_ident[EI_OSABI])
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
		printf("<unknown: %x>\n", elf_ident[EI_OSABI]);
	}
}

/**
 * printing_abi - A function that prints the ABI version of an ELF.
 * @elf_ident: A pointer.
 * Return: void.
 */

void printing_abi(unsigned char *elf_ident)
{
	printf(" ABI Version: %d\n",
		elf_ident[EI_ABIVERSION]);
}

/**
 * printing_type - A function that prints the type of an ELF.
 * @elf_type: ELF type
 * @elf_ident: A pointer.
 * Return: void
 */
void printing_type(unsigned int elf_type, unsigned char *elf_ident)
{
	if (elf_ident[EI_DATA] == ELFDATA2MSB)
		elf_type >>= 8;

	printf(" Type: ");

	switch (elf_type)
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
		printf("<unknown: %x>\n", elf_type);
	}
}

/**
 * printing_entry - A function that prints
 * the entry point of an ELF.
 * @elf_entry: Address of ELF
 * @elf_ident: A pointer
 * Return: void
 */

void printing_entry(unsigned long int elf_entry, unsigned char *elf_ident)
{
	printf(" Entry point address: ");

	if (elf_ident[EI_DATA] == ELFDATA2MSB)
	{
		elf_entry = ((elf_entry << 8) & 0xFF00FF00) |
			  ((elf_entry >> 8) & 0xFF00FF);
		elf_entry = (elf_entry << 16) | (elf_entry >> 16);
	}

	if (elf_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)elf_entry);

	else
		printf("%#lx\n", elf_entry);
}

/**
 * close_elf - A function that closes an ELF file.
 * @elf: The file descriptor
 *
 * Return; void
 * Description: If file not closed - exit code 98.
 */

void closing_elf(int elf)

{
	if (closing(elf) == -1)
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
 *
 * Description: If the file not an ELF File or failled, exit code 98.
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
		close_elf(op);
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

	checking_elf(header->elf_ident);
	printf("ELF Header:\n");
	printing_magic(header->elf_ident);
	printing_class(header->elf_ident);
	printing_data(header->elf_ident);
	printing_version(header->elf_ident);
	printing_osabi(header->elf_ident);
	printing_abi(header->elf_ident);
	printing_type(header->elf_type, header->elf_ident);
	printing_entry(header->elf_entry, header->elf_ident);

	free(header);
	closing_elf(op);
	return (0);
}
