#include "bowling.h"

void Scorer::start() {
    score = 0;
    last_roll = 0;
    next_bonus = 0;
    next_next_bonus = 0;
    in_frame = false;
    frame_count = 0;
}
int Scorer::get_score() {
    return score;
};

void Scorer::addRoll(int roll) {
    add_bonuses(roll);
    detect_specials(roll);
    update_score(roll);
}

void Scorer::add_bonuses(int roll) {
    while(next_bonus) {
        score += roll;
        next_bonus--;
    }
    if (next_next_bonus) {
        next_bonus++;
        next_next_bonus--;
    }   
}
void Scorer::detect_specials(int roll) {
    if (frame_count < 10) {
        if(!in_frame && roll == 10) {
            next_bonus += 1;
            next_next_bonus += 1;
            in_frame = true;
        }
        else if(in_frame && (roll + last_roll) == 10)
            next_bonus += 1;
    }
}
void Scorer::update_score(int roll) {
    if(frame_count < 10) 
        score += roll;
    last_roll = roll;
    in_frame = !in_frame;
    if(!in_frame)
        frame_count++;
}
