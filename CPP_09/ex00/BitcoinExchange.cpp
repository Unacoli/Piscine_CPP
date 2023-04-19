#include "BitcoinExchange.hpp"

bool BitcoinExchange::db_status = false;

std::map<std::string, double> BitcoinExchange::database = std::map<std::string, double>();

BitcoinExchange::BitcoinExchange(void)
{
    return ;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src)
{
    *this = src;
    return ;
}

BitcoinExchange::~BitcoinExchange(void)
{
    return ;
}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
    if (this != &rhs)
    {
        this->database = rhs.database;
        this->db_status = rhs.db_status;
    }
    return (*this);
}

void    BitcoinExchange::init_database(const std::string &data_path, bool inited) const
{
    std::string line, date;
    std::size_t middle;
    double value;

    if ((inited == false) && BitcoinExchange::db_status)
        return ;
    std::ifstream data_fd(data_path.c_str());
    if (data_fd.is_open())
    {
        getline(data_fd, line);
        while (getline(data_fd, line))
        {
            date = "";
            middle = line.find(',');
            if (middle != std::string::npos)
            {
                date = line.substr(0, middle);
                value = std::atof(line.substr(middle + 1).c_str());
                BitcoinExchange::database[date] = value;
            }
            else
            {
                std::cout << "Error : Wrong format on the database" << std::endl;
                data_fd.close();
                exit(-1);
            }
        }
        BitcoinExchange::db_status = true;
    }
    else
    {
        std::cout << "Error : No database founded" << std::endl;
        data_fd.close();
        exit (-1);
    }
    data_fd.close();
}

void    BitcoinExchange::print_output(const std::string &data_path, const std::string &input, bool inited)
{
    this->init_database(data_path, inited);
    this->print_exchange(input);
}

void    BitcoinExchange::print_exchange(const std::string &input) const
{
    std::ifstream infile(input.c_str());
    std::string line, date = "";
    int check;
    double value = 0.0, input_qty = 0.0;

    if (infile.is_open())
    {
        getline(infile, line);
        while(getline(infile, line))
        {
            check = this->is_valid_input(line, date, &input_qty);
            if (check == 1)
            {
                value = this->get_data(date);
                std::cout << date << " => " << input_qty << " = " << value * input_qty << std::endl;
            }
            else if (check == -1)
            {
                std::cout << "Error : bad input => " << line << std::endl;
            }
        }
    }
    else
    {
        std::cout << "Error : Infile not found" << std::endl;
        exit(-1);
    }
    infile.close();
}

int BitcoinExchange::is_valid_input(const std::string &input_line, std::string &input_date, double *input_qty) const
{
    size_t middle, date_1, date_2;
    std::string year, month, day;

    middle = input_line.find('|');
    if (middle == std::string::npos)
        return (-1);
    if (input_line[middle - 1] != ' ' || input_line[middle + 1] != ' ')
        return (-1);
    date_1 = input_line.find('-');
    if (date_1 == std::string::npos)
        return (-1);
    year = input_line.substr(0, date_1);

    date_2 = input_line.find('-', date_1 + 1);
    if (date_2 == std::string::npos)
        return (-1);
    month = input_line.substr(date_1 + 1, middle - 1 - (date_2 + 1));
    day = input_line.substr(date_2 + 1, middle - 1 - (date_2 + 1));
    if (!this->is_valid_date(year, month, day))
        return (-1);
    input_date = input_line.substr(0, middle - 1);
    *input_qty = std::atof(input_line.substr(middle + 2).c_str());
    return (this->is_valid_input_qty(*input_qty, input_line));
}

double BitcoinExchange::get_data(const std::string &data) const
{
    std::map<std::string, double>::iterator it;
    it = BitcoinExchange::database.find(data);
    if (it != BitcoinExchange::database.end())
        return (it->second);
    it = BitcoinExchange::database.upper_bound(data);
    if (it != database.begin())
        --it;
    return (it->second);
}

bool BitcoinExchange::is_valid_date(const std::string &year, const std::string &month, const std::string &day) const
{
    int tmp;

    if (year.size() != 4)
        return (false);
    if (std::atoi(year.c_str()) <= 0)
        return (false);
    if (month.size()!= 2)
        return (false);
    tmp = std::atoi(month.c_str());
    if (tmp <= 0 || tmp > 12)
        return (false);
    if (day.size() != 2)
        return (false);
    tmp = std::atoi(day.c_str());
    if (tmp <0 || tmp > 31)
        return (false);
    return (true);
}

bool BitcoinExchange::is_valid_input_qty(double input_qty, const std::string &input_line) const
{
    if (input_qty > 1000.0)
    {
        std::cout << "Error : too large number." << std::endl;
        return (false);
    }
    if (input_qty < 0.0)
    {
        std::cout << "Error : Not a positive number." << std::endl;
        return (false);
    }
    if (input_qty == 0.0)
    {
        std::cout << "Error : bad input => " << input_line << std::endl;
        return (false);
    }
    return (true);
}