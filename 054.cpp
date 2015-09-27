/*
题目说in each hand there is a clear winner，所以不用考虑平局情况。
*/

#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>
#include <set>
#include <vector>
#include <unordered_map>

#define CARD_A 14
#define CARD_K 13
#define CARD_Q 12
#define CARD_J 11
#define CARD_T 10

using namespace std;

enum Rank {
    HighCard, 
    OnePair, 
    TwoPairs, 
    ThreeofaKind, 
    Straight, 
    Flush, 
    FullHouse, 
    FourofaKind, 
    StraightFlush, 
    RoyalFlush
};

enum Suit {
    S, 
    H, 
    D, 
    C
};

enum Result {
    PLAYER1, 
    PLAYER2, 
    TIE
};

struct Card {
    Suit suit;
    int num; 
};

struct Hand {
    vector<Card> card;
};

Card getCard(string c) {
    Card card;
    switch(c[0]) {
        case 'A':
            card.num = CARD_A;
            break;
        case 'K':
            card.num = CARD_K;
            break;
        case 'Q':
            card.num = CARD_Q;
            break;
        case 'J':
            card.num = CARD_J;
            break;
        case 'T':
            card.num = CARD_T;
            break;
        default:
            card.num = c[0] - '0';
            break;
    }

    switch(c[1]) {
        case 'S':
            card.suit = S;
            break;
        case 'H':
            card.suit = H;
            break;
        case 'D':
            card.suit = D;
            break;
        case 'C':
            card.suit = C;
            break;
    }

    return card;
}

bool operator<(Card c1, Card c2) {
    return (c1.num < c2.num);
}

Hand getHand(vector<string> v) {
    Hand hand;
    hand.card.resize(5);
    for(int i = 0; i < 5; i++) {
        hand.card[i] = getCard(v[i]);
    }
    sort(hand.card.begin(), hand.card.end());
    reverse(hand.card.begin(), hand.card.end());
    return hand;
}

bool isSameSuit(Card c1, Card c2) {
    return (c1.suit == c2.suit);
}

bool isFlush(Hand hand) {
    int n = hand.card.size();
    for(int i = 1; i < n; i++) {
        if(!isSameSuit(hand.card[0], hand.card[i])) {
            return false;
        }
    }
    return true;
}

bool isStraight(Hand hand) {
    int n = hand.card.size();
    for(int i = 1; i < n; i++) {
        if(hand.card[i].num != hand.card[i - 1].num - 1) {
            return false;
        }
    }
    return true;
}

bool isStraightFlush(Hand hand) {
    return (isFlush(hand) && isStraight(hand));
}

bool isRoyalFlush(Hand hand) {
    return (isStraightFlush(hand) && hand.card[0].num == CARD_A);
}

bool isFourofaKind(Hand hand) {
    unordered_map<int, int> m;
    int n = hand.card.size();
    for(int i = 0; i < n; i++) {
        m[hand.card[i].num]++;
    }
    unordered_map<int, int>::iterator it = m.begin();
    vector<int> cnt;
    for(it = m.begin(); it != m.end(); it++) {
        cnt.push_back(it->second);
    }
    sort(cnt.begin(), cnt.end());
    return (cnt.back() == 4);
}

bool isFullHouse(Hand hand) {
    unordered_map<int, int> m;
    int n = hand.card.size();
    for(int i = 0; i < n; i++) {
        m[hand.card[i].num]++;
    }
    unordered_map<int, int>::iterator it = m.begin();
    vector<int> cnt;
    for(it = m.begin(); it != m.end(); it++) {
        cnt.push_back(it->second);
    }
    sort(cnt.begin(), cnt.end());
    return (cnt.back() == 3 && cnt.size() == 2);
}

bool isThreeofaKind(Hand hand) {
    unordered_map<int, int> m;
    int n = hand.card.size();
    for(int i = 0; i < n; i++) {
        m[hand.card[i].num]++;
    }
    unordered_map<int, int>::iterator it = m.begin();
    vector<int> cnt;
    for(it = m.begin(); it != m.end(); it++) {
        cnt.push_back(it->second);
    }
    sort(cnt.begin(), cnt.end());
    return (cnt.back() == 3 && cnt.size() == 3);
}

bool isTwoPairs(Hand hand) {
    unordered_map<int, int> m;
    int n = hand.card.size();
    for(int i = 0; i < n; i++) {
        m[hand.card[i].num]++;
    }
    unordered_map<int, int>::iterator it = m.begin();
    vector<int> cnt;
    for(it = m.begin(); it != m.end(); it++) {
        cnt.push_back(it->second);
    }
    sort(cnt.begin(), cnt.end());
    return (cnt.back() == 2 && cnt.size() == 3);
}

bool isOnePair(Hand hand) {
    unordered_map<int, int> m;
    int n = hand.card.size();
    for(int i = 0; i < n; i++) {
        m[hand.card[i].num]++;
    }
    unordered_map<int, int>::iterator it = m.begin();
    vector<int> cnt;
    for(it = m.begin(); it != m.end(); it++) {
        cnt.push_back(it->second);
    }
    sort(cnt.begin(), cnt.end());
    return (cnt.back() == 2 && cnt.size() == 4);
}

Rank getRank(Hand hand) {
    if(isRoyalFlush(hand)) return RoyalFlush;
    if(isStraightFlush(hand)) return StraightFlush;
    if(isFourofaKind(hand)) return FourofaKind;
    if(isFullHouse(hand)) return FullHouse;
    if(isFlush(hand)) return Flush;
    if(isStraight(hand)) return Straight;
    if(isThreeofaKind(hand)) return ThreeofaKind;
    if(isTwoPairs(hand)) return TwoPairs;
    if(isOnePair(hand)) return OnePair;
    return HighCard;
}

bool isHighCard(Hand hand) {
    return (getRank(hand) == HighCard);
}

string rtos(Rank r) {
    switch(r) {
        case HighCard: 
            return "HighCard";
        case OnePair: 
            return "OnePair";
        case TwoPairs: 
            return "TwoPairs";
        case ThreeofaKind: 
            return "ThreeofaKind";
        case Straight: 
            return "Straight";
        case Flush: 
            return "Flush";
        case FullHouse: 
            return "FullHouse";
        case FourofaKind: 
            return "FourofaKind";
        case StraightFlush: 
            return "StraightFlush";
        case RoyalFlush: 
            return "RoyalFlush";
    }
}

string htos(Hand hand) {
    return rtos(getRank(hand));
}

Result getWinnerHighCard(Hand hand1, Hand hand2) {
    int n = hand1.card.size();
    for(int i = 0; i < n; i++) {
        if(hand1.card[i].num > hand2.card[i].num) {
            return PLAYER1;
        } else if(hand1.card[i].num < hand2.card[i].num) {
            return PLAYER2;
        }
    }
    return TIE;
}

Result getWinnerOnePair(Hand hand1, Hand hand2) {
    vector<int> exist1(256, 0);
    vector<int> exist2(256, 0);
    int n = hand1.card.size();
    for(int i = 0; i < n; i++) {
        exist1[hand1.card[i].num]++;
        exist2[hand2.card[i].num]++;
    }
    int c12 = 0;
    int c22 = 0;
    int c11_1 = 0;
    int c11_2 = 0;
    int c11_3 = 0;
    int c21_1 = 0;
    int c21_2 = 0;
    int c21_3 = 0;
    for(int i = 0; i < 256; i++) {
        if(exist1[i] == 2) {
            c12 = i;
        }
        if(exist2[i] == 2) {
            c22 = i;
        }
        if(exist1[i] == 1) {
            if(c11_3 == 0) {
                c11_3 = i;
            } else if(c11_2 == 0) {
                c11_2 = i;
            } else {
                c11_3 = i;
            }
        }
        if(exist2[i] == 1) {
            if(c21_3 == 0) {
                c21_3 = i;
            } else if(c21_2 == 0) {
                c21_2 = i;
            } else {
                c21_3 = i;
            }
        }
    }
    if(c12 > c22) {
        return PLAYER1;
    } else if(c12 < c22) {
        return PLAYER2;
    } else if(c11_3 > c21_3) {
        return PLAYER1;
    } else if(c11_3 < c21_3) {
        return PLAYER2;
    } else if(c11_2 > c21_2) {
        return PLAYER1;
    } else if(c11_2 < c21_2) {
        return PLAYER2;
    } else if(c11_1 > c21_1) {
        return PLAYER1;
    } else if(c11_1 < c21_1) {
        return PLAYER2;
    } else {
        return TIE;
    }
}

Result getWinnerTwoPairs(Hand hand1, Hand hand2) {
    vector<int> exist1(256, 0);
    vector<int> exist2(256, 0);
    int n = hand1.card.size();
    for(int i = 0; i < n; i++) {
        exist1[hand1.card[i].num]++;
        exist2[hand2.card[i].num]++;
    }
    int c12_1 = 0;
    int c12_2 = 0;
    int c22_1 = 0;
    int c22_2 = 0;
    int c11 = 0;
    int c21 = 0;
    for(int i = 0; i < 256; i++) {
        if(exist1[i] == 2) {
            if(c12_1 == 0) {
                c12_1 = i;
            } else {
                c12_2 = i;
            }
        }
        if(exist2[i] == 2) {
            if(c22_1 == 0) {
                c22_1 = i;
            } else {
                c22_2 = i;
            }
        }
        if(exist1[i] == 1) {
            c11 = i;
        }
        if(exist2[i] == 2) {
            c21 = i;
        }
    }
    if(max(c12_1, c12_2) > max(c22_1, c22_2)) {
        return PLAYER1;
    } else if(max(c12_1, c12_2) < max(c22_1, c22_2)) {
        return PLAYER2;
    } else if(min(c12_1, c12_2) > min(c22_1, c22_2)) {
        return PLAYER1;
    } else if(min(c12_1, c12_2) < min(c22_1, c22_2)) {
        return PLAYER2;
    } else if(c11 > c21) {
        return PLAYER1;
    } else if(c11 < c21) {
        return PLAYER2;
    } else {
        return TIE;
    }
}

Result getWinnerThreeofaKind(Hand hand1, Hand hand2) {
    vector<int> exist1(256, 0);
    vector<int> exist2(256, 0);
    int n = hand1.card.size();
    for(int i = 0; i < n; i++) {
        exist1[hand1.card[i].num]++;
        exist2[hand2.card[i].num]++;
    }
    int c13;
    int c23;
    int c11_1 = 0;
    int c11_2 = 0;
    int c21_1 = 0;
    int c21_2 = 0;
    for(int i = 0; i < 256; i++) {
        if(exist1[i] == 3) {
            c13 = i;
        }
        if(exist2[i] == 3) {
            c23 = i;
        }
        if(exist1[i] == 1) {
            if(c11_1 == 0) {
                c11_1 = i;
            } else {
                c11_2 = i;
            }
        }
        if(exist2[i] == 2) {
            if(c21_1 == 0) {
                c21_1 = i;
            } else {
                c21_2 = i;
            }
        }
    }
    if(c13 > c23) {
        return PLAYER1;
    } else if(c13 < c23) {
        return PLAYER2;
    } else if(max(c11_1, c11_2) > max(c21_1, c21_2)) {
        return PLAYER1;
    } else if(max(c11_1, c11_2) < max(c21_1, c21_2)) {
        return PLAYER2;
    } else if(min(c11_1, c11_2) > min(c21_1, c21_2)) {
        return PLAYER1;
    } else if(min(c11_1, c11_2) < min(c21_1, c21_2)) {
        return PLAYER2;
    } else {
        return TIE;
    }
}

Result getWinnerStraight(Hand hand1, Hand hand2) {
    if(hand1.card[0].num > hand2.card[0].num) {
        return PLAYER1;
    } else if(hand1.card[0].num < hand2.card[0].num) {
        return PLAYER2;
    } else {
        return TIE;
    }
}

Result getWinnerFlush(Hand hand1, Hand hand2) {
    int n = hand1.card.size();
    for(int i = 0; i < n; i++) {
        if(hand1.card[i].num > hand2.card[i].num) {
            return PLAYER1;
        } else if(hand1.card[i].num < hand2.card[i].num) {
            return PLAYER2;
        }
    }
    return TIE;
}

Result getWinnerFullHouse(Hand hand1, Hand hand2) {
    vector<int> exist1(256, 0);
    vector<int> exist2(256, 0);
    int n = hand1.card.size();
    for(int i = 0; i < n; i++) {
        exist1[hand1.card[i].num]++;
        exist2[hand2.card[i].num]++;
    }
    int c13;
    int c23;
    int c12;
    int c22;
    for(int i = 0; i < 256; i++) {
        if(exist1[i] == 3) {
            c13 = i;
        }
        if(exist2[i] == 3) {
            c23 = i;
        }
        if(exist1[i] == 2) {
            c12 = i;
        }
        if(exist2[i] == 2) {
            c22 = i;
        }
    }
    if(c13 > c23) {
        return PLAYER1;
    } else if(c13 < c23) {
        return PLAYER2;
    } else if(c12 > c22) {
        return PLAYER1;
    } else if(c12 < c22) {
        return PLAYER2;
    } else {
        return TIE;
    }
}

Result getWinnerFourofaKind(Hand hand1, Hand hand2) {
    vector<int> exist1(256, 0);
    vector<int> exist2(256, 0);
    int n = hand1.card.size();
    for(int i = 0; i < n; i++) {
        exist1[hand1.card[i].num]++;
        exist2[hand2.card[i].num]++;
    }
    int c14;
    int c24;
    int c11;
    int c21;
    for(int i = 0; i < 256; i++) {
        if(exist1[i] == 4) {
            c14 = i;
        }
        if(exist2[i] == 4) {
            c24 = i;
        }
        if(exist1[i] == 1) {
            c11 = i;
        }
        if(exist2[i] == 1) {
            c21 = i;
        }
    }
    if(c14 > c24) {
        return PLAYER1;
    } else if(c14 < c24) {
        return PLAYER2;
    } else if(c11 > c21) {
        return PLAYER1;
    } else if(c11 < c21) {
        return PLAYER2;
    } else {
        return TIE;
    }
}

Result getWinnerStraightFlush(Hand hand1, Hand hand2) {
    if(hand1.card[0].num > hand2.card[0].num) {
        return PLAYER1;
    } else if(hand1.card[0].num < hand2.card[0].num) {
        return PLAYER2;
    } else {
        return TIE;
    }
}

Result getWinnerRoyalFlush(Hand hand1, Hand hand2) {
    return TIE;
}

Result getWinner(Hand hand1, Hand hand2) {
    int r1 = getRank(hand1);
    int r2 = getRank(hand2);
    if(r1 > r2) {
        return PLAYER1;
    } else if(r1 < r2) {
        return PLAYER2;
    } else {
        if(r2 == RoyalFlush) {
            return getWinnerRoyalFlush(hand1, hand2);
        } else if(r2 == StraightFlush) {
            return getWinnerStraightFlush(hand1, hand2);
        } else if(r2 == FourofaKind) {
            return getWinnerFourofaKind(hand1, hand2);
        } else if(r2 == FullHouse) {
            return getWinnerFullHouse(hand1, hand2);
        } else if(r2 == Flush) {
            return getWinnerFlush(hand1, hand2);
        } else if(r2 == Straight) {
            return getWinnerStraight(hand1, hand2);
        } else if(r2 == ThreeofaKind) {
            return getWinnerThreeofaKind(hand1, hand2);
        } else if(r2 == TwoPairs) {
            return getWinnerTwoPairs(hand1, hand2);
        } else if(r2 == OnePair) {
            return getWinnerOnePair(hand1, hand2);
        } else {
            return getWinnerHighCard(hand1, hand2);
        }
    }
    return PLAYER2;
}

int main() {
    int res = 0;
    int n = 1000;
    vector<string> t1;
    vector<string> t2;
    t1.resize(5);
    t2.resize(5);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 5; j++) {
            cin>>t1[j];
        }
        for(int j = 0; j < 5; j++) {
            cin>>t2[j];
        }
        Hand hand1 = getHand(t1);
        Hand hand2 = getHand(t2);
        if(getWinner(hand1, hand2) == PLAYER1) {
            res++;
        }
    }

    cout<<"Result "<<res<<endl;

    int wait = 0;
    cin>>wait;

    return 0; 
}
