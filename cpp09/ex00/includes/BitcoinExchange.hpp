#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <map>

class Date {

    private:

        int _year;
        int _month;
        int _day;

    public:

        Date(int year, int month, int day);
        Date(const Date& other);
        Date& operator=(const Date& other);
        ~Date();

        bool operator<(const Date& other) const;
        bool operator==(const Date& other) const ;
        Date& operator--();

        int get_year() const ;
        int get_month() const;
        int get_day() const;

        static bool isLeapYear(int year);
        static int getMaxDaysInMonth(int month, int year);
};


std::ostream& operator<<(std::ostream& os, const Date& date);


class BitcoinExchange {
    private:

        std::map<Date, double> _dataBase;


        bool is_whitespace(const char& c) const ;
        void delete_items(void **addresses, const size_t& size);
        void **split_into_items(const std::string& line, const size_t& items_size);
        std::string trim(const std::string& s);
        void parse_header(std::ifstream& file, std::string& line) ;
        std::pair<bool, Date> parse_date(const std::string& date);
        std::pair<bool, double> parse_value(const std::string& val);
        void parse_data_and_display(const std::string& line) ;
        double get_exchange_rate_for_that_year(Date dt, const double& val);

    public:

        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange() ;

        void load_data_base() ;
        void print_data_base() ;

        void applyRate(std::string file_name);
};

#endif 