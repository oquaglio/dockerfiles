# Dual Node Solace Brokers

Adapted from https://github.com/SolaceLabs/solace-single-docker-compose

## Broker Consoles (PubSub+ Manager)

broker 1 -
http://localhost:8080/

broker 2 -
http://localhost:18080/


## Creat Test Topics and Queues

./create_topic_and_queue.sh localhost 8080

./create_topic_and_queue.sh localhost 18080


## Start

docker compose -f docker-compose.yml up -d


## Stop

docker compose -f docker-compose.yml down

## Permissions

Make sure to allow acccess for clients to consume from queue (queue settings on Solace)