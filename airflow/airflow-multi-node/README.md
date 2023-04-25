#

Note: moved to https://github.com/oquaglio/airflow

## Links

https://airflow.apache.org/docs/apache-airflow/stable/howto/docker-compose/index.html#running-airflow-in-docker


## Volumes

Compose file will create:

```
local     airflow_postgres-db-volume
```
## Init

On all operating systems, you need to run database migrations and create the first user account. To do this, run:

```
docker-compose up airflow-init
```

Will create:
```
 - Network airflow_default
 - Volume "airflow_airflow-volume"
 - Volume "airflow_airflow-postgres-db-volume"
 - Container airflow-redis-1
 - Container airflow-postgres-1
 - Container airflow-airflow-init-1
```

## Running Airflow

Now you can start all services:

```
docker-compose up
```
Check running containers:
```
docker-compose ps

```

## DAG Files

Files in /dags will get mounted to all containers using airflow-common :

- airflow-airflow-worker-1
- airflow-airflow-scheduler-1
- airflow-airflow-webserver-1

mounted to:
```
/dags
```
```
airflow@7c05c27b14c3:/opt/airflow/dags$
```

## Cleanup Everything

Warning: will also remove volumes.

```
docker-compose down --volumes --remove-orphans
```

Will remove:

```
 - Container airflow-airflow-init-1
 - Container airflow-redis-1
 - Container airflow-postgres-1
 - Volume airflow_airflow-volume
 - Volume airflow_airflow-postgres-db-volume
 - Network airflow_default
 ```

 Manually remove /dags, /logs, /plugins