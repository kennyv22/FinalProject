#ifndef TRACKING_H
#define TRACKING_H

#include "flashcard.h"

typedef struct {
    Flashcard *flashcard;
    int attempts;
    int correct;
} PerformanceRecord;

typedef struct {
    PerformanceRecord *records;
    int count;
    int capacity;
} TrackingSystem;

TrackingSystem* tracking_system_create();
void tracking_record_attempt(TrackingSystem *system, Flashcard *flashcard, int correct);
void tracking_system_free(TrackingSystem *system); 
PerformanceRecord* tracking_find_record(TrackingSystem *system, Flashcard *flashcard);
void tracking_print_summary(const TrackingSystem *system);

#endif
