#include <stdio.h>
#include <stdlib.h>
#include "tracking.h"

TrackingSystem* tracking_system_create() {
    TrackingSystem *system = (TrackingSystem *)malloc(sizeof(TrackingSystem));
    if (system == NULL) {
        fprintf(stderr, "Memory allocation failed for Tracking System\n");
        exit(EXIT_FAILURE);
    }
    system->records = (PerformanceRecord *)malloc(sizeof(PerformanceRecord) * 10); // Initial capacity
    system->count = 0;
    system->capacity = 10;
    return system;
}

void tracking_system_free(TrackingSystem *system) {
    if (system != NULL) {
        free(system->records);
        free(system);
    }
}

void tracking_record_attempt(TrackingSystem *system, Flashcard *flashcard, int correct) {
    PerformanceRecord *record = tracking_find_record(system, flashcard);
    if (record == NULL) {
        if (system->count == system->capacity) {
            system->capacity *= 2;
            system->records = (PerformanceRecord *)realloc(system->records, sizeof(PerformanceRecord) * system->capacity);
            if (system->records == NULL) {
                fprintf(stderr, "Memory allocation failed for expanding Tracking System\n");
                exit(EXIT_FAILURE);
            }
        }
        record = &system->records[system->count++];
        record->flashcard = flashcard;
        record->attempts = 0;
        record->correct = 0;
    }
    record->attempts++;
    record->correct += correct;
}

PerformanceRecord* tracking_find_record(TrackingSystem *system, Flashcard *flashcard) {
    for (int i = 0; i < system->count; i++) {
        if (system->records[i].flashcard == flashcard) {
            return &system->records[i];
        }
    }
    return NULL;
}

void tracking_print_summary(const TrackingSystem *system) {
    for (int i = 0; i < system->count; i++) {
        PerformanceRecord *record = &system->records[i];
        printf("Flashcard: %s, Attempts: %d, Correct: %d\n",
               record->flashcard->question, record->attempts, record->correct);
    }
}
