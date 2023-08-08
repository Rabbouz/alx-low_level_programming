#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void validate_elf(unsigned char *magic_numbers);
void print_magic_numbers(unsigned char *magic_numbers);
void print_architecture_class(unsigned char *magic_numbers);
void print_data_encoding(unsigned char *magic_numbers);
void print_file_version(unsigned char *magic_numbers);
void print_os_and_abi(unsigned char *magic_numbers);
void print_abi_version(unsigned char *magic_numbers);
void print_elf_type(unsigned int elf_type, unsigned char *magic_numbers);
void p_entry_point(unsigned long int e_point, unsigned char *magic_numbers);
void closing_elf(int elf);
/**
 * validate_elf - A function that checks if a file
 * is an ELF file or not.
 * @magic_numbers: A pointer
 *
 * Return: void
 */
void validate_elf(unsigned char *magic_numbers)
{
	for (int index = 0; index < 4; index++)
	{
	if (magic_numbers[index] != 127 &&
	magic_numbers[index] != 'E' &&
	magic_numbers[index] != 'L' &&
	magic_numbers[index] != 'F')
	{
		dprintf(STDERR_FILENO, "Error: Not a ELF file\n");
		exit(98);
		}
	}
}
/**
 * print_magic_numbers - A function that prints
 *  the magic numbers of an ELF header.
 * @magic_numbers: A pointer.
 *
 * Return : void
 */
void print_magic_numbers(unsigned char *magic_numbers)
{
	printf(" Magic Numbers: ");

	for (int index = 0; index < EI_NIDENT; index++)
	{
		printf("%02x", magic_numbers[index]);
		if (index == EI_NIDENT - 1)
		printf("\n");
		else
		printf(" ");
		}
}
/**
 * print_architecture_class - A function that prints the class of an ELF
 *  header.
 * @magic_numbers: A pointer
 */

void print_architecture_class(unsigned char *magic_numbers)
{
	printf(" Class: ");

	if (magic_numbers[EI_CLASS] == ELFCLASSNONE)
	{
		printf("none\n");
		}
		else if (magic_numbers[EI_CLASS] == ELFCLASS32)
		{
			printf("ELF32\n");
			}
			else if (magic_numbers[EI_CLASS] == ELFCLASS64)
			{
				printf("ELF64\n");
				}
				else
				{
					printf("<unknown: %x>\n", magic_numbers[EI_CLASS]);
					}
}
/**
 * print_data_encoding - A function that prints the data
 *  of an ELF header
 * @magic_numbers: pointer
 *
 * Return: void
 */
void print_data_encoding(unsigned char *magic_numbers)
{
	printf(" Data: ");
	switch (magic_numbers[EI_DATA])
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
		printf("<unknown: %x>\n", magic_numbers[EI_CLASS]);
	}
}
/**
 * print_file_version - A function that ripnts
 * the version of an ELF.
 * @magic_numbers: pointer
 * Return : void
 */

void print_file_version(unsigned char *magic_numbers)
{
	printf(" Version: %d", e_ident[EI_VERSION]);

	if (magic_numbers[EI_VERSION] == EV_CURRENT)
	{
		printf(" (current)\n");
		}
		else
		{
			printf("\n");
			}
}

/**
 * print_os_and_abi - Prints the OS/ABI of an ELF header.
 * @magic_numbers: A pointer to an array containing the ELF version.
 */
void print_os_and_abi(unsigned char *magic_numbers)
{
	printf(" OS/ABI: ");

	switch (magic_numbers[EI_OSABI])
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
		printf("<unknown: %x>\n", magic_numbers[EI_OSABI]);
	}
}
/**
 * print_abi_version - A function that prints the ABI version of an ELF.
 * @magic_numbers: A pointer
 * Return: void
 */
void print_abi_version(unsigned char *magic_numbers);
{
	printf(" ABI Version: %d\n",
		magic_numbers[EI_ABIVERSION]);
}
/**
 * print_elf_type - A function that prints the type of an ELF.
 * @elf_type: ELF type.
 * @magic_numbers: pointer
 * Return: void
 */

void print_elf_type(unsigned int elf_type, unsigned char *magic_numbers)
{
	if (magic_numbers[EI_DATA] == ELFDATA2MSB)
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
 * p_entry_point - A function that pints the entry point of an ELF.
 * @e_point: address
 * @magic_numbers: pointer
 * Return: void
 */

void p_entry_point(unsigned long int e_point, unsigned char *magic_numbers)
{
	printf(" Entry point address: ");

	if (magic_numbers[EI_DATA] == ELFDATA2MSB)
	{
		e_point = ((e_point << 8) & 0xFF00FF00) |
			  ((e_point >> 8) & 0xFF00FF);
		e_point = (e_point << 16) | (e_point >> 16);
	}

	if (magic_numbers[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_point);

	else
		printf("%#lx\n", e_point);
}

/**
 * closing_elf - A function that closes an ELF file.
 * @elf: The file descriptor.
 */
void closing_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", elf);
		exit(98);
	}
}

/**
 * main - A function that Displays the information contained
 * in the ELF header at the start of an ELF file.
 * @argc: The number of arguments.
 * @argv: An array of pointers.
 *
 * Return: Always 0 (success).
 *
 */

int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;

	int op bytes_rd;

	op = open(argv[1], O_RDONLY);
	if (op == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		closing_elf(op);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	bytes_rd = read(op, header, sizeof(Elf64_Ehdr));
	if (bytes_rd == -1)
	{
		free(header);
		closing_elf(op);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	validate_elf(header->magic_numbers);
	printf("ELF Header:\n");
	print_magic_numbers(header->magic_numbers);
	print_architecture_class(header->magic_numbers);
	print_data_encoding(header->magic_numbers);
	print_file_version(header->magic_numbers);
	print_os_and_abi(header->magic_numbers);
	print_abi_version(header->magic_numbers);
	print_elf_type(header->elf_type, header->magic_numbers);
	p_entry_point(header->e_point, header->magic_numbers);

	free(header);
	closing_elf(op);
	return (0);
}
