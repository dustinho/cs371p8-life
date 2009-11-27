// ---------
// FredkinCell.h
// ---------

#include "AbstractCell.h"

#ifndef FredkinCell_h
#define FredkinCell_h

class FredkinCell : public AbstractCell {

    public:
        int age;

        FredkinCell (int a) : AbstractCell((a > -1)),
                              age (a) {
            // Age will be -1 for dead FredkinCell
        }

        FredkinCell* clone () const {
            return new FredkinCell(*this);
        }

        char get() const {
            if (life) {
                assert(age > -1);
                if (age < 10) {
                    // age if age is less than 10
                    return age;
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
            // a dead cell becomes a live cell, if 1 or 3 neighbors are alive
            } else if (!life && neighbors%2 == 1) {
                life = true;
            }

            // Increment age
            if (life) {
                ++age;
            }
        }
};

#endif // FredkinCell_h
