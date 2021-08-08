/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 16:25:41 by ahaddad           #+#    #+#             */
/*   Updated: 2021/08/08 22:09:03 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.class.hpp"

int main()
{
    // std::cout << "tkharbi9" << std::endl;
    FreqMap wf;
    std::string word;
    std::ifstream infile("webserv.conf");
    std::fstream file;
    std::string filename;
    std::string name;
    Parse serv(filename);
    filename = "webserv.conf";
    serv.file = filename;
    file.open(filename.c_str());
    while (getline(file ,word))
    {
        int len = CountWords(word);
        if (len > 0)
        {
            wf.insert(std::pair<std::string , std::string>(get_key(word), get_value(word)));
        }
    }
    return 0;
}