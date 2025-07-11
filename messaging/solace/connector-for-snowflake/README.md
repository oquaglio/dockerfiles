#

## Setup

Replace the vars in config which will be used by solace-pubsub-connector-snowflake:

```SH
envsubst < connector_config.json > final_config.json
```

```SH
envsubst < config/application.template.yaml > config/application.yaml
```

## Run

Set env vars:

SNOWFLAKE_PRIVATE_KEY_PASSPHRASE

``SH
docker-compose up
```
