//
// Created by Administrator on 2022/7/22.
//

#ifndef NGINX_HTTP_HELLO_H
#define NGINX_HTTP_HELLO_H

#include "nginx.h"
#include "ngx_string.h"
#include "ngx_conf_file.h"
#include "ngx_core.h"
#include "ngx_http_config.h"

typedef struct {
    ngx_str_t hello_string;
    ngx_str_t hello_counter;
} ngx_http_hello_loc_conf_t;

static char *ngx_http_hello_string(ngx_conf_t *cf, ngx_command_t *cmd, void *conf);

static char *ngx_http_hello_counter(ngx_conf_t *cf, ngx_command_t *cmd, void *conf);

static ngx_command_t ngx_http_hello_commands[] = {
        {
                ngx_string("hello_string"),
                NGX_HTTP_LOC_CONF | NGX_CONF_NOARGS | NGX_CONF_TAKE1,
                ngx_http_hello_string,
                NGX_HTTP_LOC_CONF_OFFSET,
                offsetof(ngx_http_hello_loc_conf_t, hello_string),
                NULL
        }, {
                ngx_string("hello_counter"),
                NGX_HTTP_LOC_CONF | NGX_CONF_FLAG,
                ngx_http_hello_counter,
                NGX_HTTP_LOC_CONF_OFFSET,
                offsetof(ngx_http_hello_loc_conf_t, hello_counter),
                NULL
        },
        ngx_null_command
};

#endif //NGINX_HTTP_HELLO_H
