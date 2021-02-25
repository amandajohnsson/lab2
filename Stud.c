/********* STUDENTS WRITE THE NEXT SEVEN ROUTINES *********/

#include "Stud.h"

const float expected_rtt = 15.0;

int checksumming(struct pkt packet)
{
    int checksum = 0;
    for (int i = 0; i < 20; i++)
    {
        checksum += packet.payload[i];
    }
    checksum += packet.seqnum + packet.acknum;
    return checksum;
}
struct sender
{
    int seq;
    struct last_packet;
} A;

// Function to send back acknowledgements
void send_ack(int AorB, int ack)
{
    struct pkt packet;
    packet.acknum = ack;
    packet.checksum = checksumming(&packet);
    tolayer3(AorB, packet);
}
/* called from layer 5, passed the data to be sent to other side */
void A_output(struct msg message)
{
    struct pkt packet;

    memcpy(packet.payload, message.data, sizeof(message.data));
}

void B_output(struct msg message) /* need be completed only for extra credit */
{
    printf("Behövs ej göras\n");
}

/* called from layer 3, when a packet arrives for layer 4 */
void A_input(struct pkt packet)
{
}

/* called when A's timer goes off */
void A_timerinterrupt()
{
}

/* the following routine will be called once (only) before any other */
/* entity A routines are called. You can use it to do any initialization */
void A_init()
{
}

/* Note that with simplex transfer from a-to-B, there is no B_output() */
/* called from layer 3, when a packet arrives for layer 4 at B*/
void B_input(struct pkt packet)
{
    if (packet.checksum != checksumming(packet))
    {
        printf("Packet is corrupted\n");
    }
}

/* called when B's timer goes off */
void B_timerinterrupt()
{
    printf("Används ej än då vi inte använder timer i B\n");
}

/* the following rouytine will be called once (only) before any other */
/* entity B routines are called. You can use it to do any initialization */
void B_init()
{
}
