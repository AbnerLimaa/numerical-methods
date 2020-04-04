#ifndef TICKER_H
#define TICKER_H

typedef struct ticker ticker;

ticker* alloc_ticker();

void free_ticker(ticker* c);

void start(ticker* c);

void end(ticker* c);

double spent_time(ticker* c);

#endif