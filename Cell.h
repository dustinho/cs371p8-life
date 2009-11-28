// ---------
// Cell.h
// ---------

#include <algorithm> // swap

#include "AbstractCell.h"
#include "ConwayCell.h"
#include "FredkinCell.h"

#ifndef Cell_h
#define Cell_h

class Cell {
    private:
        AbstractCell* _p;

    public:
        Cell (AbstractCell* p) {
            _p = p;}

        Cell (char c) {
            if (c == '.' || c == '*') {
                _p = new ConwayCell(c);
            } else {
                _p = new FredkinCell(c);
            }
        }

        Cell (const Cell& that) {
            if (!that._p)
                _p = 0;
            else
                _p = that._p->clone();}

        ~Cell () {
            delete _p;}

        Cell& operator = (Cell that) {
            swap(that);
            return *this;}

        char get() const {
            return _p->get();
        }

        void eval() {
            _p->eval();
            // Special case: if you're a Fredkin cell
            if (FredkinCell* p = dynamic_cast<FredkinCell*>(_p)) {
                // and your age has become 2
                if (p->age == 2) {
                    // then you become a ConwayCell
                    delete _p;
                    _p = new ConwayCell('*');
                }
            }
        }

        void swap (Cell& that) {
            std::swap(_p, that._p);
        }

        bool isAlive() {
            return _p->isAlive();
        }

        void conwayInc() {
            _p->conwayInc();
        }

        void incNeighbors() {
            _p->incNeighbors();
        }

        void setNeighbors(int n) {
            _p->setNeighbors(n);
        }

        /*
        AbstractCell& operator * () {
            return *_p;}

        const AbstractCell& operator * () const {
            return *_p;}

        AbstractCell* operator -> () {
            return _p;}

        const AbstractCell* operator -> () const {
            return _p;}
        */
};

#endif // Cell_h
