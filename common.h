#pragma once

#include <iomanip>
#include <sstream>
#include <string>
#include <vector>

inline std::string bytes2hexStr(const unsigned char* vec, int length, bool withSpace = true) {
  std::stringstream ss;
  for (int i = 0; i < length; i++) {
    ss << std::uppercase << std::setfill('0') << std::setw(2) << std::hex << static_cast<int>(vec[i]);
    if (withSpace) ss << " ";
  }
  return ss.str();
}

inline std::string bytes2hexStr(const std::vector<unsigned char>& vec, bool withSpace = true) {
  return bytes2hexStr(vec.data(), vec.size(), withSpace);
}

template <typename T>
std::string int2str(const std::vector<T>& vec, bool withSpace = true) {
  std::stringstream ss;
  for (int i = 0; i < vec.size(); i++) {
    ss << static_cast<int>(vec[i]);
    if (withSpace) ss << " ";
  }
  return ss.str();
}

template <typename T>
std::string int2str(const std::vector<T>& vec, int len, bool withSpace = true) {
  std::stringstream ss;
  for (int i = 0; i < len; i++) {
    ss << static_cast<int>(vec[i]);
    if (withSpace) ss << " ";
  }
  return ss.str();
}

template <typename T>
struct CTreeNode {
  T val;
  CTreeNode* left = nullptr;
  CTreeNode* right = nullptr;

  explicit CTreeNode(T v_) : val(v_) {}
};

template <typename T>
struct CListNode {
  T val;
  CListNode* next = nullptr;

  explicit CListNode(T v_) : val(v_) {}
};

