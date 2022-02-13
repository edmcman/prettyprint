#include <iostream>
#include <vector>

#include "prettyprint.h"

void print_basic() {
    auto doc = pp::nil();
    doc = doc + "hello world";
    doc = doc + pp::nest(4, pp::line()
            + "indented"
            + pp::nest(4, pp::line()
                + "more indented" + pp::line()
                + "across lines")
            + pp::line() + "and with really long lines with many words including "
                           "veryveryveryverylongandcontiguouswordswhichneedwrapping");

    auto settings = std::cout << pp::set_width(40);
    settings << pp::set_max_indent(20) << doc
             << std::endl << std::endl;
}

std::shared_ptr<pp::doc> fillwords (const std::vector<std::string> &v) {
  auto doc = pp::nil ();
  bool first = true;

  for (auto it = v.begin (); it != v.end (); it++) {
    if (first) {
      doc = (doc + *it);
      first = false;
    } else
      doc = (doc + pp::group (pp::line ()) + *it);
  }

  return doc;
}

void print_grouped() {
    // auto doc = pp::group( pp::nil() +
    //         "one" + pp::line() +
    //         "two" + pp::line() +
    //         "three" + pp::line() +
    //         "four");


  std::vector<std::string> v = {"Rerum",
    "eveniet",
    "dolorem",
    "ducimus.",
    "Autem",
    "sit",
    "explicabo",
    "dolorem.",
    "Dolorem",
    "veniam",
    "velit",
    "maiores",
    "rem",
    "qui",
    "et",
    "laudantium",
    "deleniti."};

  auto doc = fillwords (v);
  //auto doc == pp::nil () 

    auto settings = std::cout << pp::set_width(30);
    settings << pp::set_max_indent(20) << doc
             << std::endl << std::endl;

    settings = std::cout << pp::set_width(15);
    settings << pp::set_max_indent(4) << doc
             << std::endl << std::endl;
}

int main() {
    print_basic();
    print_grouped();

    return 0;
}
