#include "puzzle.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <utility>
#include <algorithm>

bool operator <(const entry & a, const entry &b)
{
    return (a.s < b.s);
    
}

std::ostream & operator << (std::ostream & os, const entry & e)
{
  os << e.s << ": " << "(" << e.start.first << ", " << e.start.second << "), ";
  os << "(" << e.end.first << ", " << e.end.second << ")";
  return os;
}


puzzle::puzzle(const char *name, const char *dictname)
{
    std::ifstream is(name);
    if (is.fail())
    {
        std::cout << "Can't open puzzle!" << std::endl;
        exit(2);
    }

    std::string line;
    std::size_t width;

    while (getline(is, line))
    {
        std::stringstream ss(line);
        std::vector<char> row;
        char c;
        while (ss >> c)
            row.push_back(tolower(c));
        if (_data.size() == 0)
            width = row.size();
        else if (row.size() != width)
        {
            std::cout << "Corrupted puzzle!" << std::endl;
            exit(3);
        }
        _data.push_back(row);
    }
    is.close();

    std::ifstream ds(dictname);
    if (ds.fail())
    {
        std::cout << "Can't open dictionary!" << std::endl;
        exit(2);
    }


    std::string word;
    while (ds >> word)
        _dict.insert(word);

    ds.close();
}

std::vector<entry> puzzle::solve() 
{

    std::vector<entry> ans;
    if (_data.size() == 0)
      return std::vector<entry>();

    int width = _data[0].size();
    int height = _data.size();

    for (int r = 0; r < height; ++r)
        for (int c = 0; c < width; ++c)
             for (int dx = -1; dx <= 1; ++dx)
                for (int dy = -1; dy <= 1; ++dy)
                {
                    if (dx == 0 && dy == 0)
                        continue;

                    std::string s;
                    s += _data[r][c];

                    for (int r1 = r + dy, c1 = c+dx;
                        r1 >= 0 && r1 < height && c1 >= 0 && c1 < width;
                        r1 += dy, c1 += dx)
                    {
                        s += _data[r1][c1];
                        if (_dict.find(s) != _dict.end() && s.size() >= 6)
			{
				ans.push_back(entry(s, position(r, c), position(r1, c1)));
			}
                    }
                }

   sort(ans.begin(), ans.end());

   return ans;

}
