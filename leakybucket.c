#include <stdio.h>
int main() {
intbucketSize, outputRate, n, incoming;
int stored = 0;
printf("=== Leaky Bucket Algorithm Simulation ===\n");
printf("Enter bucket capacity (in packets): ");
if (scanf("%d", &bucketSize) != 1 || bucketSize<= 0) {
printf("Invalid bucket size.\n");
return 1;
    }
printf("Enter output rate (packets per second): ");
if (scanf("%d", &outputRate) != 1 || outputRate<= 0) {
printf("Invalid output rate.\n");
return 1;
    }
printf("Enter number of incoming packets (time slots): ");
if (scanf("%d", &n) != 1 || n <= 0) {
printf("Invalid number of time slots.\n");
return 1;
    }
for (int i = 1; i <= n; i++) {
printf("\nTime %d: Enter number of incoming packets: ", i);
if (scanf("%d", &incoming) != 1 || incoming < 0) {
printf("Invalid input for incoming packets.\n");
return 1;
        }
printf("Incoming packets: %d\n", incoming);
if (incoming + stored >bucketSize) {
int dropped = (incoming + stored) - bucketSize;
stored = bucketSize;
printf("Bucket overflow! Dropped packets: %d\n", dropped);
        } else {
stored += incoming;
        }
int sent = (stored >= outputRate) ? outputRate : stored;
stored -= sent;
printf("Packets sent: %d, Packets remaining in bucket: %d\n", sent, stored);
    }
while (stored > 0) {
int sent = (stored >= outputRate) ? outputRate : stored;
stored -= sent;
printf("\nDraining... Packets sent: %d, Packets remaining: %d\n", sent, stored);
    }
printf("\nAll packets processed successfully!\n");
return 0;
}
