#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#include "redismodule.h"

int RedisModule_OnLoad(RedisModuleCtx *ctx, RedisModuleString **argv, int argc) {
    char hostbuffer[256];
    char *IPbuffer;
    struct hostent *host_entry;
    int hostname;

    if (RedisModule_Init(ctx,"RedisIP",1,REDISMODULE_APIVER_1)
            == REDISMODULE_ERR) return REDISMODULE_ERR;

    hostname = gethostname(hostbuffer, sizeof(hostbuffer));

    // checks /etc/hosts (needs error handling for if hostname isn't present)
    host_entry = gethostbyname(hostbuffer);

    IPbuffer = inet_ntoa(*((struct in_addr*)
                           host_entry->h_addr_list[0]));

    RedisModule_Log(ctx, "warning", "Hostname: %s", hostbuffer);
    RedisModule_Log(ctx, "warning", "IP: %s", IPbuffer);

    return REDISMODULE_OK;
}
