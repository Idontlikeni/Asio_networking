//
// blocking_tcp_echo_client.cpp
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2024 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <cstdlib>
#include <cstring>
#include <iostream>
#include "asio.hpp"
#include <random>

using asio::ip::tcp;

enum { max_length = 1024 };

int main(int argc, char* argv[])
{
    std::cout << "Client\n";
    srand(time(NULL));
    setlocale(LC_ALL, "RU");
    int id;
    std::cout << "¬ведите ваш ID:\n";
    std::cin >> id;
    try
    {
        //if (argc != 3)
        //{
        //    std::cerr << "Usage: blocking_tcp_echo_client <host> <port>\n";
        //    return 1;
        //}

        asio::io_context io_context;

        tcp::socket s(io_context);
        tcp::resolver resolver(io_context);
        asio::connect(s, resolver.resolve("127.0.0.1", "8080"));
        {
            using namespace std;
            cout << "Commands: \nbuy <usd> <rub>\nsell <usd> <rub>\nexit\n";

        }
        while(1)
        {
            int c, usd, rub;
            {
                using namespace std;
                string comm;
                cin >> comm;
                if (comm == "buy" || comm == "sell")
                {
                    c = comm == "buy" ? 1 : -1;
                    cin >> usd;
                    cin >> rub;
                }
                else if (comm == "exit")
                {
                    break;
                }
                else
                {
                    cout << "There is no such command\n";
                    continue;
                }
            }
            //std::cout << "Enter t:\n";
            //std::cin >> t;
            int request[4];
            
            
            //int r = rand() % 2;
            //c = (r) == 1 ? 1 : -1;
            ////std::cout << "c: " << r << "\n";
            //usd = rand() % 100;
            //rub = rand() % 100;

            {
                using namespace std;
                
            }

            request[0] = c;
            request[1] = usd;
            request[2] = rub;
            request[3] = id;


            asio::write(s, asio::buffer(request, sizeof request));
            std::cout << "a";
            int answer[2];
            size_t reply_length = asio::read(s,
                asio::buffer(answer, sizeof answer));
            std::cout << "Reply is: ";
            std::cout << answer[0] << "\n";
            std::cout << "\n";
            
        }
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}