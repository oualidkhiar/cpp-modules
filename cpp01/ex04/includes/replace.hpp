/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oukhiar <oukhiar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 13:19:11 by Oukhiar           #+#    #+#             */
/*   Updated: 2025/07/10 13:24:21 by Oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
# define REPLACE_HPP

#include <iostream>
#include <fstream>


class File {
    private:
        std::ifstream in_file;
        std::ofstream out_file;
        std::string s1;
        std::string s2;
        bool flag;
    public:
        File(char **args);
        ~File();
        bool check_flag() const;
        void replace( void );
};



#endif