// ---------
// FredkinCell.h
// ---------
#include <stdio.h>
#include "AbstractCell.h"

#ifndef FredkinCell_h
#define FredkinCell_h

class FredkinCell : public AbstractCell {

    public:
        int age;

        FredkinCell (char c) : AbstractCell((c)) {
            // Age will be -1 for dead FredkinCell
            life = !(c == '-');
            if (life){
                age = (c == '+') ? 10 : c - '0';
            } else {
                age = -1;
            }
        }

        FredkinCell* clone () const {
            return new FredkinCell(*this);
        }

        char get() const {
            if (life) {
                assert(age > -1);
                if (age < 10) {
                    // age if age is less than 10
                    return age + '0';
                } else {
                    // + if age is greater than 9
                    return '+';
                }
            } else {
                assert (age == -1);
                // - if dead
                return '-';
            }
        }

        void eval() {
            assert(neighbors >= 0 && neighbors <= 4);
            // a live cell becomes a dead cell, if 0, 2, or 4 neighbors are
            // alive
            if (life && (neighbors%2 == 0)) {
                life = false;
                age = -1;
            // a dead cell becomes a live cell, if 1 or 3 neighbors are alive
            } else if (!life && neighbors%2 == 1) {
                life = true;
            }

            // Increment age
            if (life) {
                ++age;
            }
        }

        void conwayInc() {}

        void incNeighbors() {
            ++neighbors;
        }

        void setNeighbors(int n) {
            neighbors = n;
        }
};

#endif // FredkinCell_h
