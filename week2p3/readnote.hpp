#ifndef _READNOTE_HPP
#define _READNOTE_HPP

#include <string.h>
#include <iostream>

void printnote(const char* data) {
  const char* lastcolon = strrchr(data, ':');
  for (size_t i = lastcolon - data + 1; i < strlen(data); i++) {
    if (data[i] == ',') {
      std::cout << std::endl;
      i++;
    }
    std::cout << data[i];
  }
  std::cout << std::endl;
}

#endif  //_READNOTE_HPP
