#!/bin/bash

# This script automates the creation of a queue and a topic subscription in Solace PubSub+.
# It utilizes the Solace Element Management Protocol (SEMP) API to send configuration commands
# to the Solace broker. The script first creates a queue and then subscribes a topic to that queue.
#
# Variables:
# - ADMIN_USER: Username for the admin access to the Solace broker.
# - ADMIN_PASSWORD: Password for the admin access.
# - SOLACE_URL: The URL where the Solace broker SEMP interface is accessible.
# - QUEUE_NAME: The name of the queue to be created.
# - TOPIC_NAME: The name of the topic to subscribe to the queue.
# - ENCODED_QUEUE_NAME: The URL-encoded name of the queue to use in the API request.

# Check if enough arguments are provided
if [ "$#" -ne 2 ]; then
    echo "Usage: $0 <host> <port>"
    exit 1
fi

# Extract arguments
HOST=$1
PORT=$2

# Admin credentials
ADMIN_USER="admin"
ADMIN_PASSWORD="admin"
SOLACE_URL="http://$HOST:$PORT"  # Adjust if using a different port or host

# Queue and topic names
QUEUE_NAME="q/minaus/waio/sf/cam/trackmeasurement/recorded/v1"
TOPIC_NAME="t/minaus/waio/sf/cam/trackmeasurement/recorded/v1"

# URL-encode the queue name to handle any special characters (like slashes)
ENCODED_QUEUE_NAME=$(echo "$QUEUE_NAME" | sed 's:/:%2F:g')

#echo "Encoded Queue Name: $ENCODED_QUEUE_NAME"

# Create a queue using the SEMP API
curl -X POST "$SOLACE_URL/SEMP/v2/config/msgVpns/default/queues" \
     -u "$ADMIN_USER:$ADMIN_PASSWORD" \
     -H "Content-Type: application/json" \
     -d '{
           "queueName": "'$QUEUE_NAME'",
           "accessType": "exclusive",
           "egressEnabled": true,
           "ingressEnabled": true
         }'

# Create a topic subscription for the queue using the SEMP API
curl -X POST "$SOLACE_URL/SEMP/v2/config/msgVpns/default/queues/$ENCODED_QUEUE_NAME/subscriptions" \
     -u "$ADMIN_USER:$ADMIN_PASSWORD" \
     -H "Content-Type: application/json" \
     -d '{
           "subscriptionTopic": "'$TOPIC_NAME'"
         }'
