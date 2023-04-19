#pragma once

# include <iostream>
# include <fstream>
# include <string>
# include <map>
# include <iomanip>
# include <sstream>
# include <list>
# include <cstdlib>

class   BitcoinExchange
{
    private:
        static std::map<std::string, double> database;
        static bool db_status;

        double  get_data(const std::string &data) const;
        void    init_database(const std::string &data_path, bool inited) const;
        void    print_exchange(const std::string &input) const;
        int     is_valid_input(const std::string &input_line, std::string &input_date, double *input_qty) const;
        bool    is_valid_date(const std::string &year, const std::string &month, const std::string &day) const;
        bool     is_valid_input_qty(double input_qty, const std::string &input_line) const;

    public:
        BitcoinExchange(void);
        BitcoinExchange(BitcoinExchange const &src);
        BitcoinExchange& operator=(BitcoinExchange const &rhs);
        ~BitcoinExchange(void);
        void    print_output(const std::string &data_path, const std::string &input, bool mode = false);
};