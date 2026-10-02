// src/main.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <packet_receiver.h>
#include <packet_filter.h>
#include <packet_transmitter.h>

int main() {
    // Initialize packet receiver
    packet_receiver_t *receiver = packet_receiver_init();

    // Process packets
    while (1) {
        packet_t *packet = packet_receiver_next(receiver);
        if (!packet) {
            // No more packets to process
            break;
        }
        // Apply packet filter
        if (packet_filter(packet)) {
            // Packet passes filter
            // Transmit the packet
            packet_transmitter_transmit(packet);
        }
        packet_destroy(packet);
    }

    // Cleanup
    packet_receiver_destroy(receiver);

    return 0;
}