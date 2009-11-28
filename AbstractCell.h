// --------
// AbstractCell.h
// --------

#ifndef AbstractCell_h
#define AbstractCell_h

class AbstractCell {

    public:
        bool life;
        int neighbors;

        AbstractCell (char c) {
            neighbors = 0;
            }

        virtual ~AbstractCell () {}

        virtual AbstractCell* clone () const = 0;

        virtual char get() const = 0;

        virtual void eval() = 0;

        bool isAlive() {
            return life;
        }

        virtual void conwayInc() = 0;
        virtual void incNeighbors() = 0;
        virtual void setNeighbors(int n) = 0;
};

#endif // AbstractCell_h
