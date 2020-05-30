#pragma once

#include<iostream>
#include<string>
#include<vector>
#include<iterator>
#include<any>
#include<algorithm>

using namespace std;

//	Header Declaration

#ifndef Booklist_H
#define Booklist_H

template<class Book>

class Booklist {
private:
  vector <Book> listBooks;
  int len;

public:
  Booklist();
  void display_list();
  void add_at_end();
  void add_at_pos();
  void delete_at_pos();
  void delete_by_name();
  int linear_searcher(Book);
  void find_using_linear_search();
  int binary_searcher(Book input, int start_pos, int end_pos);
  void find_using_binary_search();
  void selection_sort();
  void bubble_sort();
  vector<Book> getBook();
};

#endif
