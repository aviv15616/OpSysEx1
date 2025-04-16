#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void send_bit(int pid, int bit) {
    int sig = (bit == 0) ? SIGUSR1 : SIGUSR2;
    kill(pid, sig);
    // 🟢 דגש 2: אין תור לסיגנלים , נדרשת השהיה כדי לא לאבד סיגנלים (ולוודא טיפול תקין)
    usleep(1000);  // המתנה קצרה שהנמען יספיק לטפל
}

int main() {
    int pid, value;

    printf("Enter receiver PID: ");
    scanf("%d", &pid);

    printf("Enter message: ");
    scanf("%d", &value);

    for (int i = 0; i < 8; i++) {
        int bit = (value >> i) & 1;
        send_bit(pid, bit);
    }

    return 0;
}
