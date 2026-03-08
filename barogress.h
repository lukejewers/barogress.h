#ifndef BAROGRESS_H
#define BAROGRESS_H

#include <stdbool.h>
#include <stdio.h>
#include <time.h>

typedef struct {
    size_t current;
    size_t total;
    size_t _tick;
    time_t start_time;
    const char* label;
    int bar_width;
} BarogressInfo;

static inline void barogress_print(BarogressInfo *binfo) {
    if (binfo->total == 0) return;

    time_t now = time(NULL);
    double elapsed = difftime(now, binfo->start_time);
    double speed = (elapsed > 0) ? (double)binfo->current / elapsed : 0;

    float progress = (float)binfo->current / binfo->total;
    int bar_length = (int)(progress * binfo->bar_width);

    const char spinner[] = {'-', '\\', '|', '/'};
    char current_spinner = spinner[binfo->_tick++ % 4];

    printf("\r%c %s: [", current_spinner, binfo->label);

    for (int i = 0; i < binfo->bar_width; ++i) {
        printf("%s", (i < bar_length) ? "#" : "·");
    }

    bool show_eta = (elapsed > 0 && binfo->current > 0);
    if (!show_eta) {
        printf("] %.2f%% | ETA: --:--   ", progress * 100);
    } else {
        int total_eta_s = (int)((binfo->total - binfo->current) / speed);
        int mins = total_eta_s / 60;
        int secs = total_eta_s % 60;
        printf("] %.2f%% | ETA: %02d:%02d   ", progress * 100, mins, secs);
    }

    fflush(stdout);
    if (binfo->current >= binfo->total) printf("\n");
}

#endif /* BAROGRESS_H */
