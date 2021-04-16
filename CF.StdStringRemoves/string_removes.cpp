//
//  main.cpp
//  CF.StdStringRemoves
//
//  @see: https://en.cppreference.com/w/cpp/string/basic_string/operator%22%22s
//  @see: https://www.techiedelight.com/remove-certain-characters-string-cpp/
//
//  Created by Alan Sampson on 1/8/20.
//  Copyright © 2020 Alan @ FreeShell. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <string_view>
#include <algorithm>
#include <cstdio>
#include <cstdint>
#include <cinttypes>

using namespace std::literals::string_literals;
using namespace std::literals::string_view_literals;

void rem00(void);
void rem01(void);

/*
 *  MARK: main()
 */
int main(int argc, const char * argv[]) {
  std::cout << "CF.StdStringRemoves\n"s;
  std::cout << "C++ Version: "s << __cplusplus << std::endl;
  std::cout << "In: "s << __func__ << std::endl;

  auto RC(EXIT_SUCCESS);

  std::cout << "char *, std::string & std::string_view literals\n";
  auto s1 = std::string { "abc\0\0def" };
  auto s2 = "abc\0\0def"s;
  auto s3 = "abc\0\0def"sv;

  std::cout << "Literal: " << std::quoted("abc\\0\\0def"sv, '"', '$') << '\n';
  std::cout << "s1 (char *)         : " << s1.size() << ' ' << std::quoted(s1) << '\n';
  std::cout << "s2 (std::string)    : " << s2.size() << ' ' << std::quoted(s2) << '\n';
  std::cout << "s3 (std::string_view: " << s3.size() << ' ' << std::quoted(s3) << '\n';

  rem00();
  rem01();

  return RC;
}

/*
 *  MARK: rem00()
 */
void rem00(void) {
  std::cout << "In: "s << __func__ << std::endl;

  auto sv = "#Hello #World!!"s;
  auto chars = "#!"s;

  for (auto cv : chars) {
    sv.erase(std::remove(sv.begin(), sv.end(), cv), sv.end());
  }

  std::cout << sv << std::endl;

  return;
}

/*
 *  MARK: rem01()
 */
void rem01(void) {
  std::cout << "In: "s << __func__ << std::endl;

  auto sv = "#Hello #World!!"s;
  auto chars = "#!"sv;

  sv.erase(remove_if(sv.begin(), sv.end(),
            [&chars](auto const & cv) {
              return chars.find(cv) != std::string::npos;
            }),
            sv.end());

  std::cout << sv << std::endl;

  return;
}
