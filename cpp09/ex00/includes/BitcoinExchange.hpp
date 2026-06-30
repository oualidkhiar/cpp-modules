#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <map>

class Date {
    public:

        int _year;
        int _month;
        int _day;

        Date(int year, int month, int day) : _year(year), _month(month), _day(day) {}

        bool operator<(const Date& other) const {
            if (_year != other._year) return _year < other._year;
            if (_month != other._month) return _month < other._month;
            return _day < other._day;
        }

        bool operator==(const Date& other) const {
            return _year == other._year && _month == other._month && _day == other._day;
        }

        int get_year() const {
            return this->_year;
        }

        int get_month() const {
            return this->_month;
        }

        int get_day() const {
            return this->_day;
        }
};

std::ostream& operator<<(std::ostream& os, const Date& date) {
    os << date._year << "-" << date._month << "-" << date._day;
    return os;
}


class BitcoinExchange {
    private:
        std::map<Date, float> _dataBase;
    public:

        BitcoinExchange() {}

        void load_data_base() {
            std::ifstream file("data.csv");
            if (!file.is_open()) {
                std::cerr << "Error: could not open Data Base file" << std::endl;
                return ;
            }
            std::string line;
            // skip first line {date, exchange_rate}
            if (std::getline(file, line)) {
                std::cerr << "first line from data base " << line << std::endl;
            }

            while (std::getline(file, line)) {
                int year, month, day = 0;
                float value = 0.0f;
                char dilimiter;
                std::istringstream stream(line);
                if (stream >> year >> dilimiter >> month >> dilimiter >> day >> dilimiter >> value) {
                    this->_dataBase.insert({Date(year, month, day), value});
                }
                else {
                    std::cerr << "Error: could not load data base" << std::endl;
                }
            }
            std::cout << "data base loaded seccusfully" << std::endl;
            std::cout << std::endl;
            std::cout << "---------------------------------- the result of appling rate is -------------------------------" << std::endl;
        }

        void print_data_base() {
            for (std::map<Date, float>::iterator it = _dataBase.begin(); it != _dataBase.end(); it++) {
                std::cout << "date " << it->first << " value: " << it->second << std::endl;
            }
        }

        void applyRate(std::string file_name)
        {
            std::ifstream file(file_name);
            if (!file.is_open()) {
                std::cerr << "Error: could not open file." << std::endl;
                return ;
            }

            std::string line;
            // first line 
            while (std::getline(file, line)) {
                line = trim(line);
                if (line == "") {
                    continue ;
                } else {
                    void *tuple = convertItemsIntoTuple(line, 3);
                    if (!tuple) {
                        std::cerr << "Error: invalid header" << std::endl;
                    } else {

                    }
                    break ;
                }
            }

            while (std::getline(file, line)) {
                
            }
        }

        void *convertItemsIntoTuple(const std::string& line, size_t tupleSize) {
            void **address_holder = new void*[tupleSize];
            std::string item;
            int index = 0;
            while (typleSize)
            {
                item = line
            }
        }
        
        std::string trim(const std::string& s) {
            size_t start = s.find_first_not_of(" \t\r\n");
            size_t end = s.find_last_not_of(" \t\r\n");

            if (start == std::string::npos)
                return "";  // string is all whitespace
            return s.substr(start, end - start + 1);
        }
        
};

#endif 