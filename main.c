 #include <stdio.h>
#include <string.h>

int main() {
    FILE *f;
    char search[50];
    char trackID[50], status[50], location[50];
    int found = 0;

    f = fopen("courier.txt", "r");
    if (f == NULL) {
        printf("Unable to open file!\n");
        return 1;
    }

    printf("=== Courier Tracking System ===\n");
    printf("Enter Tracking ID to search: ");
    scanf("%s", search);

    while (fscanf(f, "%s %s %s", trackID, status, location) != EOF) {
        if (strcmp(trackID, search) == 0) {
            found = 1;
            printf("\n Parcel Found!\n");
            printf("Tracking ID : %s\n", trackID);
            printf("Status      : %s\n", status);
            printf("Location    : %s\n", location);

            if (strcmp(status, "Delivered") == 0)
                printf("=> Your parcel has been DELIVERED.\n");
            else if (strcmp(status, "In_Transit") == 0)
                printf("=> Your parcel is moving through the network.\n");
            else if (strcmp(status, "Out_For_Delivery") == 0)
                printf("=> Your parcel will reach today!\n");
            else
                printf("=> Your parcel is pending process.\n");

            break;
        }
    }

    if (!found)
        printf("\nTracking ID not found!\n");

    fclose(f);
    return 0;
}

