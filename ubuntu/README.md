# Summary

Attempt at general purpose linux environment. Largeish.

## Update amd Install tools

## Volumes

These containers will be dependent on external volumes. See Instructions.

## Links

https://github.com/deluan/zsh-in-docker/
https://github.com/spaceship-prompt/spaceship-prompt/
https://www.soberkoder.com/better-zsh-history/

## Instructions

Create a volume for your command history:
```
docker volume create shell-history-volume
```

Set variables (Powershell):
``` Powershell
$Env:COMPOSE_VAR_COMMAND_HISTORY_VOLUME="shell-history-volume"; `
$Env:COMPOSE_VAR_DOCKER_REPO_NAME="<repo>"
```
Where <repo> is your Docker account.


Check vars:
``` Powershell
dir env: | findstr "COMPOSE_VAR"
```

Start all containers:
```
docker-compose up -d
```

Get your zsh:
```
docker exec -it <container> zsh
```

Push your images:
```

```