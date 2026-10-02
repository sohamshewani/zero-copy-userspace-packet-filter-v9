```c
#ifndef PACKET_RECEIVER_H
#define PACKET_RECEIVER_H

#include <stdint.h>
#include <stddef.h>

#define MAX_RING_BUFFER_SIZE 1024

// Structure for ring buffer
struct ring_buffer {
    uint8_t *buffer;
    size_t size;
    size_t read_index;
    size_t write_index;
    size_t count;
};

// Structure for packet receiver
struct packet_receiver {
    struct ring_buffer rb;
};

// Initialize packet receiver
void packet_receiver_init(struct packet_receiver *receiver);

// Receive a packet and store in ring buffer
int packet_receiver_receive(struct packet_receiver *receiver, const uint8_t *packet, size_t packet_size);

// Get next packet from ring buffer
const uint8_t *packet_receiver_get_packet(const struct packet_receiver *receiver, size_t *packet_size);

// Clean up packet receiver
void packet_receiver_cleanup(struct packet_receiver *receiver);

#endif // PACKET_RECEIVER_H
```
