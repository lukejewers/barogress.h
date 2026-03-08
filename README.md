# barogress.h

Single-header C library for a simple, configurable progress bar.

| Progress: [########············] 40.00% | ETA: 00:04

## Usage

Include the header in your project and initialize the BarogressInfo struct.

```c
#include <unistd.h>
#include <time.h>
#include "barogress.h"

int main() {
    BarogressInfo binfo = {
        .total = 100,
        .start_time = time(NULL),
        .bar_width = 20,
        .label = "Progress",
    };

    for (int i = 0; i <= binfo.total; ++i) {
        binfo.current = i;
        barogress_print(&binfo);
        usleep(100000); // Simulate work
    }

    return 0;
}
```
