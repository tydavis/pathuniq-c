#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  const char split[2] = ":";
  char *path_str, *sp;
  size_t t = 0;

  path_str = getenv("PATH");

  if (path_str != NULL) {
    size_t psize = strlen(path_str);
    // Create array size of existing path, so we have enough room
    char export_string[psize];
    // We memset contents of the array to the path-separator because if we
    // don't, the array terminates on the first element on the split-path.
    memset(export_string, ':', sizeof(export_string));
    export_string[psize] = '\0'; // Set last size to NUL

    sp = strtok(path_str, split);
    while (sp != NULL) {
      size_t l = strlen(sp);

      for (size_t i = 0; i < l; i++) {
        char b = sp[(int)i];
        if (b == '\0') {
          break;
        }
        export_string[t + i] = b;
      }

      // Move index the length of element (plus one for separator)
      t = t + l + 1;

      // Note: this command increments the next section of the split path
      sp = strtok(NULL, split);
    }
    printf("export PATH=%s\n", export_string);
  } else {                                            // Path not found
    printf("PATH environment variable not found!\n"); // DEBUG
    exit(EXIT_FAILURE);
  }
  exit(EXIT_SUCCESS);
}
