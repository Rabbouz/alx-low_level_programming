#ifndef DOG_H
#define DOG_H

/**
 * struct dog - a dog's basic info
 * @name: First member
 * @age: Second member
 * @owner: Third member
 *
 * Description: Longer description
 */

struct dog

{
	char *name;
	float age;
	char *owner;
};

/**
 * dog_tp - typedef for struct dog
 */
typedef struct dog dog_tp;

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
dog_tp *new_dog(char *name, float age, char *owner);
void free_dog(dog_tp *d);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);

#endif
