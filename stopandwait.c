#include <stdio.h>

int main() {
    int total_frames, ack, i;

    printf("Enter total number of frames to send: ");
    scanf("%d", &total_frames);

    printf("\n--- Stop and Wait ARQ Simulation ---\n");

    for (i = 1; i <= total_frames; i++) {
        printf("\nSending frame %d...", i);

        // Check if frame received correctly
        printf("\nDid you receive ACK for frame %d? (1 = Yes, 0 = No): ", i);
        scanf("%d", &ack);

        if (ack == 1) {
            printf("Frame %d acknowledged successfully.\n", i);
        } else {
            printf("Timeout! Frame %d not acknowledged.\n", i);
            printf("Resending frame %d...\n", i);
            printf("Frame %d received successfully now.\n", i);
        }
    }

    printf("\nAll frames sent and acknowledged successfully.\n");
    return 0;
}
