// --------
// AbstractCell.h
// --------

#ifndef AbstractCell_h
#define AbstractCell_h

class AbstractCell {

    public:
        bool life;
        int neighbors;

        AbstractCell (bool l) : life (l) {
            neighbors = 0;
            }

        virtual ~AbstractCell () {}

        virtual AbstractCell* clone () const = 0;

        virtual char get() const = 0;

        virtual void eval() = 0;

        bool isAlive() {
            return life;
        }
};

#endif // AbstractCell_h
