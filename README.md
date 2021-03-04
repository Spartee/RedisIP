
# RedisIP

RedisIP is a very simple Redis module with no registered commands. The only functionality introduced by the module
is that is logs the IP address and hostname of the Redis instance to the redis log. 

Note: This relies on the fact that the machine where a redis instances is started has entries for the hostname and related IP address in ``/etc/hosts``

## installation

Installation is simple and there are no dependencies other than CMake and a C compiler toolchain.

```bash
git clone <address>
cd RedisIP
mkdir build
cd build
cmake ..
make
```

This will create a shared library that can be loaded into a redis instance.

## Usage

```bash
/path/to/redis-server --loadmodule /path/to/libredisip.so
```

## Example Logging Output

The added output looks like the output pasted below. 

```text
30333:C 04 Mar 2021 15:39:33.158 # oO0OoO0OoO0Oo Redis is starting oO0OoO0OoO0Oo
30333:C 04 Mar 2021 15:39:33.158 # Redis version=6.0.8, bits=64, commit=03b59cd5, modified=1, pid=30333, just started
30333:C 04 Mar 2021 15:39:33.158 # Configuration loaded
                _._
           _.-``__ ''-._
      _.-``    `.  `_.  ''-._           Redis 6.0.8 (03b59cd5/1) 64 bit
  .-`` .-```.  ```\/    _.,_ ''-._
 (    '      ,       .-`  | `,    )     Running in standalone mode
 |`-._`-...-` __...-.``-._|'` _.-'|     Port: 6780
 |    `-._   `._    /     _.-'    |     PID: 30333
  `-._    `-._  `-./  _.-'    _.-'
 |`-._`-._    `-.__.-'    _.-'_.-'|
 |    `-._`-._        _.-'_.-'    |           http://redis.io
  `-._    `-._`-.__.-'_.-'    _.-'
 |`-._`-._    `-.__.-'    _.-'_.-'|
 |    `-._`-._        _.-'_.-'    |
  `-._    `-._`-.__.-'_.-'    _.-'
      `-._    `-.__.-'    _.-'
          `-._        _.-'
              `-.__.-'

30333:M 04 Mar 2021 15:39:33.159 # Server initialized
30333:M 04 Mar 2021 15:39:33.160 # <RedisIP> Hostname: nid00001
30333:M 04 Mar 2021 15:39:33.160 # <RedisIP> IP: 127.0.0.1
30333:M 04 Mar 2021 15:39:33.160 * Module 'RedisIP' loaded from ./libredisip.so
30333:M 04 Mar 2021 15:39:33.160 * Ready to accept connections
```
