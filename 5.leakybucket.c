#include<stdio.h>

void main()
{
    int storage = 0, bucket_size = 10, buffer_size = 5, ip_packet_size = 4, op_packet_size = 2;

    for (int i = 0; i < buffer_size; i++) // space left
    {
        int size_left = bucket_size - storage;
        if (ip_packet_size <= size_left)
        {
            // update storage
            storage += ip_packet_size;
            printf("Buffer size= %d out of bucket size= %d\n", storage,bucket_size);
        }
        else
        {
            printf("Packet loss = %d\n", (ip_packet_size - (size_left)));

            // full size
            storage = bucket_size;
            printf("Buffer size= %d out of bucket size= %d\n", storage,bucket_size);
        }
        storage -= op_packet_size;
    }
}