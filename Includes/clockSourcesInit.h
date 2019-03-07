/*
 * @file clockSourcesInit.h
 * @author Nathan Lindberg (nml6520@g.rit.edu)
 * @brief File containing function definitions for default clock settings
 */
 
#ifndef CLOCK_SOURCES_H
#define CLOCK_SOURCES_H

#include "pinUsage.h"
#include "commonHeader.h"
#include "clockSources.h"

/**
 * Select the default sources for all the system clocks. 
 * @param: None
 * @return: None
 */
void default_clock_sources(void);

/**
 * Select the default system clock division factors.
 * @param: None
 * @return: None
 */
void default_clock_divisors(void);

/**
 * Select the default drive strength for the high and low external clock sources
 * @param: None
 * @return: None
 */
void high_low_freq_drive_strengths(void);

/**
 * Select all the clock sources wich should be disabled by default to conserve power. 
 * @param: None
 * @return: None
 */
void diabled_clock_signals(void);

/** 
 * Select all the clocks which have diabled conditional request
 * @param: None
 * @return: None
 */
void diabled_conditional_request(void);