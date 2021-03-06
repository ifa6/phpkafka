/**
 *  Copyright 2015 Elias Van Ootegem
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 * Special thanks to Patrick Reilly and Aleksandar Babic for their work
 * On which this extension was actually built.
 */

#ifndef __KAFKA_H__
#define __KAFKA_H__
#include "librdkafka/rdkafka.h"

void kafka_setup(char *brokers);
void kafka_set_log_level(int ll);
void kafka_set_partition(int partition);
int kafka_produce(rd_kafka_t *r, char* topic, char* msg, int msg_len);
rd_kafka_t *kafka_set_connection(rd_kafka_type_t type, const char *b);
int kafka_consume(rd_kafka_t *r, zval* return_value, char* topic, char* offset, int item_count, int partition);
void kafka_get_partitions(rd_kafka_t *r, zval *return_value, char *topic);
int kafka_partition_offsets(rd_kafka_t *r, long **partitions, const char *topic);
void kafka_get_topics(rd_kafka_t *r,zval *return_value);
void kafka_consume_all(rd_kafka_t *rk, zval *return_value, const char *topic, const char *offset, int item_count);
void kafka_destroy(rd_kafka_t *r, int timeout);

#endif
