/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oukhiar <oukhiar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 20:33:34 by Oukhiar           #+#    #+#             */
/*   Updated: 2025/07/14 12:59:46 by Oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/replace.hpp"

int main(int ac, char **av)
{
    if (ac == 4)
    {
        File my_obj(av);
        if (!my_obj.check_flag())
        {
            std::cout << "fiald to open the file: " << av[1] << std::endl;
            return (1);
        }
        my_obj.replace();
    }
    else
        std::cout << "Invalid number of arguments try using this order: \n\
        ./Replace infile s1 s2" << std::endl;
}
