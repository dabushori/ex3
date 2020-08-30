#pragma once

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <ostream>
#include <string.h>
#include <string>
#include <vector>

namespace cache {

class Cache {
protected:
  std::string m_fileName;

public:
  Cache(const std::string &fileName);
  void save(const std::vector<std::string> &lines) const;
  virtual std::vector<std::string>
  search(const std::vector<std::string> &lines) const = 0;
  virtual void clear() const = 0;
};

class MatCache : public Cache {
public:
  // constructor
  MatCache(const std::string &fileName);
  virtual std::vector<std::string>
  search(const std::vector<std::string> &lines) const override;
  virtual void clear() const override;
};

class ImageCache : public Cache {
public:
  // constructor
  ImageCache(const std::string &fileName);
  virtual std::vector<std::string>
  search(const std::vector<std::string> &lines) const override;
  virtual void clear() const override;
};
} // namespace cache