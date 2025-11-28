#include <stdio.h>

int main() {
    int total_frames, window_size;
    int i = 1, j, ack;

    printf("Enter total number of frames to send: ");
    scanf("%d", &total_frames);

    printf("Enter window size: ");
    scanf("%d", &window_size);

    printf("\n--- Go-Back-N ARQ Simulation ---\n");

    while (i <= total_frames) {
        // Send frames in current window
        printf("\nSending frames: ");
        for (j = i; j < i + window_size && j <= total_frames; j++) {
            printf("%d ", j);
        }

        // Acknowledgment checking
        for (j = i; j < i + window_size && j <= total_frames; j++) {
            printf("\nDid you receive ACK for frame %d? (1 = Yes, 0 = No): ", j);
            scanf("%d", &ack);

            if (ack == 0) {
                // If error: resend this and all next frames in the window
                printf("\nError detected at frame %d!", j);
                printf("\nGo-Back-N: Resending frames %d to %d...\n", j, i + window_size - 1);

                for (int k = j; k < i + window_size && k <= total_frames; k++) {
                    printf("Resending frame %d...\n", k);
                    printf("Frame %d received successfully now.\n", k);
                }
                break; // After error, go to next window
            } else {
                printf("Frame %d acknowledged successfully.\n", j);
            }
        }

        // Move window forward
        i = i + window_size;
    }

    printf("\nAll frames sent and acknowledged successfully.\n");
    return 0;
}

