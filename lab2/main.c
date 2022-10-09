#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* change_case(char *param) {
	char tmp_buf[1024];
	for (int j = 0; j < strlen(param); j++) {
		if (param[j] >= 'A' && param[j] <= 'Z') {
			tmp_buf[j] = tolower(param[j]);
		} else {
			tmp_buf[j] = toupper(param[j]);
		}
	}

	return tmp_buf;
}

int my_printf(char *format_string, char *param){
	for(int i=0;i<strlen(format_string);i++){
		if((format_string[i] == '#') && (format_string[i+1] == 'k')){
			i++;

			char *buff = change_case(param);
			printf("%s", buff);
		} else if ((format_string[i] == '#') && (format_string[++i] == '.')) {
			i++;
			int k = i;
			int init_k = i;
			while (isdigit(format_string[k])) {
				k++;
			}

			int p_length = 0;
			if (format_string[k] == 'k') {
				int d = 1;
				for (int rk = --k; rk >= init_k; rk--) {
					p_length += format_string[rk]*d;
					d *= 10;
				}

				char *buff = change_case(param);

				int p_index = 0;
				while (p_length > 0) {
					putchar(buff[p_index]);
					p_index++;
					p--;
				}
			}

			for (int k = i; k < strlen(format_string); k++) {
				if (k)
			}
 			(format_string[i] == '#') && (format_string[i+1] == '')  && (format_string[++i] == 'k')
		} else
			putchar(format_string[i]);
	}
	puts("");
	return 0;
}

int main(int argc, char *argv[]){
	char buf[1024],buf2[1024];
	while(gets(buf)){
		gets(buf2);
		my_printf(buf,buf2);
	}
	return 0;
}
