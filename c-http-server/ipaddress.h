#define MAX_LINE_LENGTH (1024)

int extract_ip_address_from_header(char *line, char *address) {
  int found = 0;
  char *ptr;
  char *name;
  char *value;

  name = strndup(line, MAX_LINE_LENGTH);
  ptr = index(name, (int)':');
  if (ptr == NULL) {
    return 0;
  }
  // end the string at the colon
  *ptr = '\0';

  // get the value part of the header field
  ptr = index(line, (int) ':');
  value = strndup(ptr + 2, MAX_LINE_LENGTH);

  // most ugly way to remove \r\n from the end of the string
  value[strlen(value)-2] = '\0';

  if (strncmp(name, "X-Forwarded-For", MAX_LINE_LENGTH) == 0) {
    found = 1;
    strncpy(address, value, MAX_LINE_LENGTH);
  }

  free(name);
  free(value);

  return found;
}

char * get_ip_address(FILE *f) {
  int address_found = 0;
  char *res;
  char *ip_address = malloc (sizeof (char) * MAX_LINE_LENGTH);
  char header_line[MAX_LINE_LENGTH];

  do {
    res = fgets(header_line, MAX_LINE_LENGTH, f);

    if (res != NULL) {
      printf("%s", res);
      if (!address_found) {
        address_found = extract_ip_address_from_header(res, ip_address);
      }
    }
  } while (res != NULL && strcmp(header_line, "\r\n") != 0);

  return ip_address;
}