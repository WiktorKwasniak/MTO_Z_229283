#include <stdio.h>
#include <string.h>
#include <ctype.h>

int custom_printf(char *format_string, char *text) {
    char tmp_str[1024];
	for(int i = 0; i < strlen(format_string); i++) {
		if((format_string[i] == '#') && (format_string[i+1] == 'k')) {
			i++;

            for(int j = 0; j < strlen(text); j++) {
                if (text[j] >= 'A' && text[j] <= 'Z') {
                    tmp_str[j] = tolower(text[j]);
                } else {
                    tmp_str[j] = toupper(text[j]);
                }
            }

			printf("%s",tmp_str);
		}else {
			putchar(format_string[i]);
        }
	}

	puts("");
}

int main(int argc, char *argv[]) {
	char format_string[1024];
    char text[1024];

	while(gets(format_string)) {
		gets(text);
		custom_printf(format_string, text);
	}

	return 0;
}