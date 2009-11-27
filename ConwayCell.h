// ---------
// ConwayCell.h
// ---------

#include "AbstractCell.h"

#ifndef ConwayCell_h
#define ConwayCell_h

class ConwayCell : public AbstractCell {

    public:
        ConwayCell (bool l) : AbstractCell(l) {}

        ConwayCell* clone () const {
            return new ConwayCell(*this);
        }

        char get() const {
            return (life) ? '*' : '.';
        }

        void eval() {
            assert(neighbors >= 0 && neighbors <= 8);
            // a live cell becomes a dead cell, if less than 2 or more than 3
            // neighbors are alive
            if (life && (neighbors < 2 || neighbors > 3)) {
                life = false;
            // a dead cell becomes a live cell, if exactly 3 neighbors are alive
            } else if (!life && neighbors == 3) {
                life = true;
            }
        }
};

#endif // ConwayCell_h
