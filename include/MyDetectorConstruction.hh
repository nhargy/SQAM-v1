#ifndef MY_CONSTRUCTION_HH
#define MY_CONSTRUCTION_HH

#include "G4Box.hh"
#include "G4GenericMessenger.hh"
#include "G4LogicalVolume.hh"
#include "G4NistManager.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"
#include "G4Tubs.hh"
#include "G4VPhysicalVolume.hh"
#include "G4VUserDetectorConstruction.hh"

#include "G4Colour.hh"
#include "G4VisAttributes.hh"

#include "MyDetectorConstruction.hh"

class MyDetectorConstruction : public G4VUserDetectorConstruction() {
    public:
        MyDetectorConstruction();
        ~MyDetectorConstruction();

        virtual G4VPhysicalVolume *Construct(); 

    private:
        // World         := Mother volume  
        // Leg(1,2,3,4)  := Legs on which profile balances
        // Profile       := Main profile
        // Spine         := Longer plane connecting rim
        // SubSpine(1,2) := Two smaller planes connecting rim
        // Cube          := LiF cube
        // Rim           := Aluminium outer rim
        // MidCylinder   := Pb shield middle part
        // EdgeCylinder  := Pb shield edge part       

        // Moderator     := Water container (to be added later)
                    
        /* Messenger variables */
        G4double xCube, yCube, zCube;

        /* Define solid, logical and physical volumes */
        G4Box *solidWorld; 
        G4Box *solidLeg, *solidProfile, *solidSpine, *solidSubSpine;
        G4Box *solidCube;
        G4Tubs *solidRim, *solidMidCylinder, *solidEdgeCylinder;
    
        G4LogicalVolume *logicWorld;
        G4LogicalVolume *logicLeg, *logicProfile, *logicSpine, *logicSubSpine;
        G4LogicalVolune *logicCube;
        G4LogicalVolume *logicRim, *logicMidCylinder, *logicEdgeCylinder;

        G4VPhysicalVolume *physWorld;
        G4VPhysicalVolume *physLeg, *physProfile, *physSpine, *physSubSpine;
        G4VPhysicalVolume *physCube;
        G4VPhysicalVolume *physRim, *physMidCylinder, *physEdgeCylinder;
        
        // Material definitions
        G4Material *Air, *Water, *LiF, *Pb, *Al, *Concrete;
        void DefineMaterials();

        G4GenericMessenger *fMessengerCube;
}

#endif
