#include <unistd.h>
#include "barogress.h"

int main(int argc, char **argv) {
    time_t now = time(NULL);

    BarogressInfo binfo = {
        .total = 100,
        .start_time = now,
        .bar_width = 20,
        .label = "Progress",
    };

    for (size_t i = 0; i <= binfo.total; ++i) {
        binfo.current = i;
        barogress_print(&binfo);
        usleep(100000);
    }

    return 0;
}
