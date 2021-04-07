#pragma once
#include "Direction.hpp"
#include <string>
#include <map>

namespace ariel
{
    class Board
    {
    private:

        std::map<unsigned int, std::map<unsigned int, char>> board;

        // min and max borders for the show function
        unsigned int min_row = 0;
        unsigned int max_row = 0;
        unsigned int min_col = 0;
        unsigned int max_col = 0;

        bool init_flag = false;
    
    public:

        // Board();
        void post(unsigned int row, unsigned int column, Direction direction, const std::string &message);
        std::string read(unsigned int row, unsigned int column, Direction direction, unsigned int length);
        void show();
    };
}