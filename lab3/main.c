#include <stdio.h>
#include <string.h>
#include <ctype.h>


int my_printf(char *format_string, char *param){
	for(int i=0;i<strlen(format_string);i++){
		if((format_string[i] == '#') && (format_string[i+1] == 'k')){
			i++;

			char tmp_buf[1024] = {0};
			for (int j = 0; j < strlen(param); j++) {
				if (param[j] >= 'A' && param[j] <= 'Z') {
					tmp_buf[j] = tolower(param[j]);
				} else {
					tmp_buf[j] = toupper(param[j]);
				}
			}

			printf("%s", tmp_buf);
		} else if ((format_string[i] == '#') && (format_string[i+1] == '.')) {
			i += 2;
			int k = i;
			int init_k = i;
			while (isdigit(format_string[k])) {
				k++;
			}

			int p_length = 0;
			if (format_string[k] == 'k') {
				k--;
				int d = 1;
				for (int rk = k; rk >= init_k; rk--) {
					p_length += (format_string[rk]-'0')*d;
					d *= 10;
				}

				char tmp_buf[1024] = {0};
				for (int j = 0; j < strlen(param); j++) {
					if (param[j] >= 'A' && param[j] <= 'Z') {
						tmp_buf[j] = tolower(param[j]);
					} else {
						tmp_buf[j] = toupper(param[j]);
					}
				}

				int p_index = 0;
				int buf_length = strlen(tmp_buf);
				if (p_length > buf_length) {
					p_length = buf_length;
				}

				while (p_length > 0) {
					putchar(tmp_buf[p_index]);

					p_index++;
					p_length--;
				}

				i += (k-init_k);
			} else {
				i -= 2;
			}
		} else if ((format_string[i] == '#') && isdigit(format_string[i+1])) {
			printf("  HERE  ");
			i += 2;
			int k = i;
			int init_k = i;
			int param_length = strlen(param);
			while (isdigit(format_string[k])) {
				k++;
			}

			int p_length = 0;
			if (format_string[k] == 'k') {
				k--;
				int d = 1;
				for (int rk = k; rk >= init_k; rk--) {
					p_length += (format_string[rk]-'0')*d;
					d *= 10;
				}

				int add_spaces = p_length - param_length;
				printf(" ###### ");
				printf("%d", add_spaces);
				while (add_spaces > 0) {
					printf(" ");
				}

				char tmp_buf[1024] = {0};
				for (int j = 0; j < param_length; j++) {
					if (param[j] >= 'A' && param[j] <= 'Z') {
						tmp_buf[j] = tolower(param[j]);
					} else {
						tmp_buf[j] = toupper(param[j]);
					}
				}

				printf("%s", tmp_buf);

				i += (k-init_k)-1;
			} else {
				i -= 2;
			}
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
