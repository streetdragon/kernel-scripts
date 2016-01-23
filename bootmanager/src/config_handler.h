#ifndef CONFIG_HANDLER_H
#define CONFIG_HANDLER_H


struct boot_option {
	char *label;
	char *menu_label;
	char *image;
	char *root;
	char *initrd;
	char *com32;
};

typedef enum {BOOT_OPTION, TEXT_BLOCK} data_type;

struct node {
	data_type type;
	void *data;
	struct node *next;
};

struct boot_option *new_boot_option();
void print_boot_option(struct boot_option *b);
void fprint_boot_option(FILE *fp, struct boot_option *b);
void add_to_string(char **str_ptr, char *str);
void print_file(char *path, int start_line, int end_line);
char *get_part_file(char *path, int start_line, int end_line);
struct node *parse_config_file(struct boot_option ***boot_options, int *size,
		int *line_number, char *config_file);
void delete_configuration(struct node **head, struct boot_option *to_delete,
		char *boot_dir);
void output_config_file(struct node *head, char *path);
void print_list(struct node *head);
void get_boot_options_list(struct boot_option ***boot_options, int *size,
		struct node *head);

#endif
