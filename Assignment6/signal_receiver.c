#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h> 

int received_value = 0;
int bit_index = 0;

void handle_signal(int sig) {
    if (sig == SIGUSR1) {
        // 0
        received_value |= (0 << bit_index);
    } else if (sig == SIGUSR2) {
        // 1
        received_value |= (1 << bit_index);
    }

    bit_index++;

    if (bit_index == 8) {
        printf("Received %d\n", received_value);
        received_value = 0;
        bit_index = 0;
    }
}

int main() {
    printf("My PID is %d\n", getpid());

    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = handle_signal;
    sa.sa_flags = SA_RESTART;

      //   sa_mask דגש 1: שימוש ב־ 
      // כדי למנוע טיפול כפול בזמן סיגנל
    // ווידוא שסיגנלים לא יפריעו זה לזה בזמן עיבוד אחד מהם
    
    sigemptyset(&sa.sa_mask);
    sigaddset(&sa.sa_mask, SIGUSR1);
    sigaddset(&sa.sa_mask, SIGUSR2);
    
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    while (1) {
        pause();  //   מאפשר קבלה מדויקת של כל סיגנל ,pause דגש 3: ממתין לסיגנל עם 
    }

    return 0;
}
