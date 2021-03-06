/*
 * webserver/socket.c
 * Launch a TCP server in the localhost
 *
 * Copyright (C) 2016 Mathieu debaerdemaeker mathieu.debaerdemaeker@gmail.com
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or (at
 * your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE, GOOD TITLE or
 * NON INFRINGEMENT.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include "../include/socket.h"

#define handle_error(msg) \
	do { perror(msg); exit(EXIT_FAILURE); } while (0)

/*
 * create_server - start listen socket on given port
 */
int create_server(int port)
{
    int socket_server;
    if ((socket_server = socket(AF_INET, SOCK_STREAM, 0)) == -1)
        handle_error("Socket error");

    int optval = 1;
    if (setsockopt(socket_server, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(int)) == -1)
        handle_error("Can nit set SO_REUSEADDR option");

    struct sockaddr_in saddr;
    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(port);
    saddr.sin_addr.s_addr = INADDR_ANY;
    if (bind(socket_server, (struct sockaddr *) &saddr, sizeof(saddr)) == -1)
        handle_error("Bind error");

    if (listen(socket_server, 10) == -1)
        handle_error("Listen error");

    return socket_server;
}
