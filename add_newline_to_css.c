/* This program add newline character '\n' to css files
   that have all white spaces trimmed out. The output file
   name is "newfile.css", which is a lot more readable
*/

#include <stdio.h>
#include <pwd.h>
#include <unistd.h>
#include <string.h>

void setHomeDirectory(void);

int main( int argc, const char * argv[])
{
  FILE *fp, *new_fp;
  setHomeDirectory();
  printf("Enter file name: ");
  char path_to_file[256];
  scanf("%s", path_to_file);
  fp = fopen(path_to_file, "r");
  new_fp = fopen ("newfile.css", "w+");

  if (NULL == fp) {
    printf("Error opening the file\n");
  } else {
    int c;
    while ((c = fgetc(fp)) != EOF) {
      if (c == '}') {
	fputc(c, new_fp);
	fputc('\n', new_fp);
      } else {
	fputc(c, new_fp);
      }
    }
    fclose(fp);
    fclose(new_fp);
  }
  return 0;
}

void setHomeDirectory(void) {
  struct passwd *pw;
  pw = getpwuid(getuid());
  chdir(pw->pw_dir);
}
