/*
** EPITECH PROJECT, 2023
** B-NWP-400-REN-4-1-myteams-thomas.juin
** File description:
** connection
*/

#include "commands.h"
#include "my_id.h"

static void set_id_client(client_list_t *client_list,
    client_info_t *client_info, map_t *map)
{
    client_t *tmp = client_list->first;
    size_t id_tmp = 0;

    if (!client_list || !client_info)
        return;
    while (tmp) {
        if (tmp->info->player->id > id_tmp)
            id_tmp = tmp->info->player->id;
        tmp = tmp->next;
    }
    client_info->player->id = id_tmp + 1;
    list_add_id(map->tiles[client_info->player->y] \
        [client_info->player->x].players, client_info->player->id);
}

int accept_client(my_zappy_t *zappy)
{
    int fd_actual = 0;
    struct sockaddr_in address;
    socklen_t addrlen = sizeof(address);
    client_info_t *client_info = NULL;
    if (!zappy->server)
        return 84;
    if (FD_ISSET(zappy->server->sockfd, &zappy->server->rset)) {
        fd_actual = accept(zappy->server->sockfd,
        (struct sockaddr *)&address, &addrlen);
        if (fd_actual == -1)
            return 84;
        dprintf(1, "Client %d connected from %s:%d\n", fd_actual,
        inet_ntoa(address.sin_addr), ntohs(zappy->server->address.sin_port));
        client_info = init_clients_info(fd_actual, zappy->map->x,
            zappy->map->y);
        set_id_client(zappy->client_list, client_info, zappy->map);
        list_add_client(zappy->client_list, client_info);
        dprintf(fd_actual, "WELCOME\n");
    } return fd_actual;
}
