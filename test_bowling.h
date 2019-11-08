// test_bowling.h

#include <cxxtest/TestSuite.h>
#include "bowling.h"

class TestBowling : public CxxTest::TestSuite {
public:

void testInitialScoreIsZero(void) {
    Scorer scorer;
    scorer.start();
    TS_ASSERT_EQUALS(0, scorer.get_score());
}

void testAfterOneRollScoreIsThatRoll(void) {
    Scorer scorer;
    scorer.start();
    scorer.addRoll(4);
    TS_ASSERT_EQUALS(4, scorer.get_score());
}

void testAfterTwoOneRollsScoreIsRoll1PlusRoll2(void) {
    Scorer scorer;
    scorer.start();
    scorer.addRoll(3); scorer.addRoll(5);
    TS_ASSERT_EQUALS(8, scorer.get_score());
}

void testAfterASpareNextRollIsCountedTwice(void) {
    Scorer scorer;
    scorer.start();
    scorer.addRoll(2); scorer.addRoll(8);
    scorer.addRoll(1);
    TS_ASSERT_EQUALS(2+8+1+1, scorer.get_score());
    scorer.start();
    scorer.addRoll(7); scorer.addRoll(3);
    scorer.addRoll(9);
    TS_ASSERT_EQUALS(7+3+9+9, scorer.get_score());
    scorer.start();
    scorer.addRoll(2); scorer.addRoll(3);
    scorer.addRoll(9); scorer.addRoll(1);
    scorer.addRoll(7);
    TS_ASSERT_EQUALS(2+3+9+1+7+7, scorer.get_score());
}

void testNotEveryTenIsASpare(void) {
    Scorer scorer;
    scorer.start();
    scorer.addRoll(0); scorer.addRoll(5);
    scorer.addRoll(5); scorer.addRoll(2);
    TS_ASSERT_EQUALS(0+5+5+2, scorer.get_score());
}

void testAfterAStrikeTwoNextRollsAreCountedTwice() {
    Scorer scorer;
    scorer.start();
    scorer.addRoll(10);
    scorer.addRoll(2); scorer.addRoll(3);
    TS_ASSERT_EQUALS(10+2+2+3+3, scorer.get_score());
}   

void testNotEveryTenIsAStrike(void) {
    Scorer scorer;
    scorer.start();
    scorer.addRoll(0); scorer.addRoll(10);
    scorer.addRoll(5); scorer.addRoll(6);
    TS_ASSERT_EQUALS(0+10+5+5+6, scorer.get_score());
}

void testAStrikeEndsAFrame(void) {
    Scorer scorer;
    scorer.start();
    scorer.addRoll(10);
    scorer.addRoll(0); scorer.addRoll(5);
    TS_ASSERT_EQUALS(10+0+0+5+5, scorer.get_score());
}

void testAfterTwoStrikesStrikeBonunesAreCountedForEachStrike(void) {
    Scorer scorer;
    scorer.start();
    scorer.addRoll(10);
    scorer.addRoll(10);
    scorer.addRoll(5);
    scorer.addRoll(4);
    TS_ASSERT_EQUALS(10+10+5+4+10+5+5+4, scorer.get_score());
}

void testAfterTenFramesOnlyPastBonusesAreCounted() {
    Scorer scorer;
    scorer.start();
    for(int i = 0; i < 12; i++) 
        scorer.addRoll(10);
    TS_ASSERT_EQUALS(300, scorer.get_score());
    }
};
