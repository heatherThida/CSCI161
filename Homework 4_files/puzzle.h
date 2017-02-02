#ifndef PUZZLE_H
#define PUZZLE_H

#include <vector>
#include <unordered_set>
#include <string>

typedef std::pair<int, int> position;

struct entry
{
	std::string s;
	position start, end;

	entry(const std::string & init_s = std::string(),
	      const position & init_start = position(),
	      const position & init_end = position())
	{
		s = init_s;
		start = init_start;
		end = init_end;
	}
};

std::ostream & operator << (std::ostream &, const entry &);
bool operator <(const entry &, const entry &);



class puzzle
{
  public:
    puzzle(const char *name, const char *dictname);
    std::vector<entry> solve();

  private:
    std::vector<std::vector<char> > _data;
    std::unordered_set<std::string> _dict;
};

#endif // PUZZLE_H
