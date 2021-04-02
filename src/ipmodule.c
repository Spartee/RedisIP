#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include<string.h>
#include "redismodule.h"

int RedisModule_OnLoad(RedisModuleCtx *ctx, RedisModuleString **argv, int argc) {
    char hostbuffer[256];
    char IPbuffer[50];
    struct hostent *host_entry;
    int hostname;
    struct in_addr **addr_list;
    int i;

    if (RedisModule_Init(ctx,"RedisIP",1,REDISMODULE_APIVER_1)
            == REDISMODULE_ERR) return REDISMODULE_ERR;

    hostname = gethostname(hostbuffer, sizeof(hostbuffer));

    // checks /etc/hosts
    if ((host_entry = gethostbyname(hostbuffer)) == NULL) {
        RedisModule_Log(ctx, "warning", "Hostname: NOTFOUND");
        return REDISMODULE_OK;
    }

    addr_list = (struct in_addr **) host_entry->h_addr_list;

    for(i = 0; addr_list[i] != NULL; i++)
    {
        //Return the first one;
        strcpy(IPbuffer , inet_ntoa(*addr_list[i]) );
        break;
    }
    RedisModule_Log(ctx, "warning", "Hostname: %s", hostbuffer);
    RedisModule_Log(ctx, "warning", "IP: %s", IPbuffer);

    return REDISMODULE_OK;
}
