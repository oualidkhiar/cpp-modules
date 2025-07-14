/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oukhiar <oukhiar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 13:18:53 by Oukhiar           #+#    #+#             */
/*   Updated: 2025/07/14 16:20:43 by Oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/replace.hpp"

std::string get_name(std::string filename)
{
    return (filename + ".replace");
}

File::File(char **args): in_file(args[1]), \
out_file(get_name(args[1]).c_str()), s1(args[2]), s2(args[3])
{
    if (!in_file || !out_file)
        flag = false;
    else
        flag = true;
}

File::~File()
{
    this->in_file.close();
    this->out_file.close();
}

bool File::check_flag() const {
    return (this->flag);
}

void File::replace( void )
{
    std::string line;   
    while (getline(this->in_file, line)) {
        std::size_t pos = 0;
        while ((pos = line.find(this->s1)) != std::string::npos) {
            line.erase(pos, this->s1.length());
            line.insert(pos, this->s2);
            pos += this->s1.length();
        }
        this->out_file << line << std::endl;
    }
}
