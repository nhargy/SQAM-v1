#ifndef MY_ACTION_INITIALIZATION_HH
#define MY_ACTION_INITIALIZATION_HH

#include "G4VUserActionInitialization.hh"

#include "MyPrimaryGenerator.hh"
#include "MySteppingAction.hh"
#include "MyTrackingAction.hh"
#include "MyStackingAction.hh"
#include "MyEventAction.hh"

class MyActionInitialization : public G4VUserActionInitialization{
    public:
        MyActionInitialization();
        ~MyActionInitialization();

        virtual void Build() const;
};

#endif
