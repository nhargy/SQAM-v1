#include "MyActionInitialization.hh"
#include "MyPrimaryGenerator.hh"
#include "MyRunAction.hh"
#include "MySteppingAction.hh"
#include "MyTrackingAction.hh"
#include "MyStackingAction.hh"
#include "MyEventAction.hh"

MyActionInitialization::MyActionInitialization(){
};

MyActionInitialization::~MyActionInitialization(){
};

void MyActionInitialization::Build() const{
    SetUserAction(new PrimaryGeneratorAction);
    SetUserAction(new MyRunAction());
    SetUserAction(new MySteppingAction());
    SetUserAction(new MyTrackingAction());
    SetUserAction(new MyStackingAction());
    SetUserAction(new MyEventAction());
};
