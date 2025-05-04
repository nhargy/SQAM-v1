#include "MyDetectorConstruction.hh"

MyDetectorConstruction::MyDetectorConstruction() {
};

MyDetectorConstruction::~MyDetectorConstruction() {
};

void MyDetectorConstruction::DefineMaterials() {
};

G4VPhysicalVolume *MyDetectorConstruction::Construct() {
    
    // **** Build World ****************************************************
    G4double xWorld = 50.*cm;
    G4double yWorld = 50.*cm;
    G4double zWorld = 100.*cm;

    G4double xWorldPos = 0.*cm;
    G4double yWorldPos = 0.*cm;
    G4double zWorldPos = 0.*cm;
    
    auto WorldVector = G4ThreeVector(xWorldPos, yWorldPos, zWorldPos);    


    solidWorld = new G4Box("solidWorld",
                           xWorld,
                           yWorld,
                           zWorld); 

    logicWorld = new G4LogicalVolume(solidWorld,
                                    Air,
                                    "logicWorld");

    physWorld  = new G4PVPlacement(0,
                                   WorldVector,
                                   logicWorld,
                                   "physWorld",
                                   0,
                                   false,
                                   0,
                                   true); 
    // *********************************************************************


    // **** Build Floor ****************************************************
    G4double xFloor = xWorld;
    G4double yFloor = yWorld;
    G4double zFloor = 10.*cm;

    G4double xFloorPos = 0.*cm;
    G4double yFloorPos = 0.*cm;
    G4double zFloorPos = (-zWorld + zFloor);
    
    auto FloorVector = G4ThreeVector(xFloorPos, yFloorPos, zFloorPos);    

    solidFloor = new G4Box("solidFloor",
                           xFloor,
                           yFloor,
                           zFloor); 

    logicFloor = new G4LogicalVolume(solidFloor,
                                    Concrete,
                                    "logicFloor");

    physFloor  = new G4PVPlacement(0,
                                   FloorVector,
                                   logicFloor,
                                   "physFloor",
                                   logicWorld,
                                   false,
                                   0,
                                   true); 
    
    /* Colours & Styling */
    G4VisAttributes* visAttributesFloor = new G4VisAttributes(G4Colour(0.5, 0.5, 0.5));
    visAttributesFloor->SetVisibility(true);
    visAttributesFloor->SetForceSolid(true);
    logicFloor->SetVisAttributes(visAttributesFloor);

    // *********************************************************************


    // **** Build Profile  *************************************************
    G4double xProfile = 2*cm;
    G4double yProfile = 2*cm;
    G4double zProfile = 49.5*cm;

    G4double xProfilePos = 0.*cm;
    G4double yProfilePos = 0.*cm;
    G4double zProfilePos = (-zWorld + 2*zFloor + zProfile);
    
    auto ProfileVector = G4ThreeVector(xProfilePos, yProfilePos, zProfilePos);    

    solidProfile = new G4Box("solidProfile",
                           xProfile,
                           yProfile,
                           zProfile); 

    logicProfile = new G4LogicalVolume(solidProfile,
                                    Al,
                                    "logicProfile");

    physProfile  = new G4PVPlacement(0,
                                   ProfileVector,
                                   logicProfile,
                                   "physProfile",
                                   logicWorld,
                                   false,
                                   0,
                                   true); 
    
    /* Colours & Styling */
    G4VisAttributes* visAttributesProfile = new G4VisAttributes(G4Colour(0.9, 0.9, 0.95));
    visAttributesProfile->SetVisibility(true);
    visAttributesProfile->SetForceSolid(true);
    logicProfile->SetVisAttributes(visAttributesProfile);

    // *********************************************************************


    // **** Build Legs *****************************************************
    G4double xLeg = 15.*cm;
    G4double yLeg = 2.*cm;
    G4double zLeg = 2.*cm;

    solidLeg = new G4Box("solidLeg",
                           xLeg,
                           yLeg,
                           zLeg); 

    logicLeg = new G4LogicalVolume(solidLeg,
                                    Al,
                                    "logicLeg");

    G4double xLeg1Pos = xLeg + xProfile;
    G4double yLeg1Pos = 0*cm;
    G4double zLeg1Pos = (-zWorld + 2*zFloor + zLeg);

    auto Leg1Vector = G4ThreeVector(xLeg1Pos, yLeg1Pos, zLeg1Pos);    

    G4RotationMatrix *rot1 = new G4RotationMatrix();
    rot1->rotateZ(0*deg);
 
    physLeg1  = new G4PVPlacement(rot1,
                                   Leg1Vector,
                                   logicLeg,
                                   "physLeg1",
                                   logicWorld,
                                   false,
                                   0,
                                   true); 
 
    G4double xLeg2Pos = 0*cm;
    G4double yLeg2Pos = xLeg + yProfile;
    G4double zLeg2Pos = (-zWorld + 2*zFloor + zLeg);

    auto Leg2Vector = G4ThreeVector(xLeg2Pos, yLeg2Pos, zLeg2Pos);    

    G4RotationMatrix *rot2 = new G4RotationMatrix();
    rot2->rotateZ(90*deg);

    physLeg2  = new G4PVPlacement(rot2,
                                   Leg2Vector,
                                   logicLeg,
                                   "physLeg2",
                                   logicWorld,
                                   false,
                                   1,
                                   true); 
  
    G4double xLeg3Pos = -xLeg - xProfile;
    G4double yLeg3Pos = 0*cm;
    G4double zLeg3Pos = (-zWorld + 2*zFloor + zLeg);

    auto Leg3Vector = G4ThreeVector(xLeg3Pos, yLeg3Pos, zLeg3Pos);    

    G4RotationMatrix *rot3 = new G4RotationMatrix();
    rot3->rotateZ(0*deg);

    physLeg3  = new G4PVPlacement(rot3,
                                   Leg3Vector,
                                   logicLeg,
                                   "physLeg3",
                                   logicWorld,
                                   false,
                                   2,
                                   true); 
  
    G4double xLeg4Pos = 0*cm;
    G4double yLeg4Pos = -xLeg - yProfile;
    G4double zLeg4Pos = (-zWorld + 2*zFloor + zLeg);

    auto Leg4Vector = G4ThreeVector(xLeg4Pos, yLeg4Pos, zLeg4Pos);    

    G4RotationMatrix *rot4 = new G4RotationMatrix();
    rot4->rotateZ(90*deg);

    physLeg4  = new G4PVPlacement(rot4,
                                   Leg4Vector,
                                   logicLeg,
                                   "physLeg4",
                                   logicWorld,
                                   false,
                                   3,
                                   true); 
        
    /* Colours & Styling */
    G4VisAttributes* visAttributesLeg = new G4VisAttributes(G4Colour(0.92, 0.9, 0.85));
    visAttributesLeg->SetVisibility(true);
    visAttributesLeg->SetForceSolid(true);
    logicLeg->SetVisAttributes(visAttributesLeg);

    // *********************************************************************


    // **** Build Rim ******************************************************
    G4double InnerRadRim = 12.*cm;
    G4double OuterRadRim = 15.*cm;
    G4double HeightRim    = 0.05*cm;

    G4double xRimPos = 0.*cm;
    G4double yRimPos = 0.*cm;
    G4double zRimPos = (-zWorld + 2*zFloor + 2*zProfile + HeightRim);
    
    auto RimVector = G4ThreeVector(xRimPos, yRimPos, zRimPos);    

    solidRim = new G4Tubs("solidRim",
                           InnerRadRim,
                           OuterRadRim,
                           HeightRim,
                           0.*deg,
                           360.0*deg); 

    logicRim = new G4LogicalVolume(solidRim,
                                    Al,
                                    "logicRim");

    physRim  = new G4PVPlacement(0,
                                   RimVector,
                                   logicRim,
                                   "physRim",
                                   logicWorld,
                                   false,
                                   0,
                                   true); 
    
    /* Colours & Styling */
    G4VisAttributes* visAttributesRim = new G4VisAttributes(G4Colour(0.9, 0.95, 0.85));
    visAttributesRim->SetVisibility(true);
    visAttributesRim->SetForceSolid(true);
    logicRim->SetVisAttributes(visAttributesProfile);

    // *********************************************************************


    // **** Build Spine ****************************************************
    G4double xSpine = 11.7*cm;
    G4double ySpine = 2.*cm;
    G4double zSpine = 0.05*cm;

    G4double xSpinePos = 0.*cm;
    G4double ySpinePos = 0.*cm;
    G4double zSpinePos = (-zWorld + 2*zFloor + 2*zProfile + zSpine);
    
    auto SpineVector = G4ThreeVector(xSpinePos, ySpinePos, zSpinePos);    

    solidSpine = new G4Box("solidSpine",
                           xSpine,
                           ySpine,
                           zSpine); 

    logicSpine = new G4LogicalVolume(solidSpine,
                                    Al,
                                    "logicSpine");

    physSpine  = new G4PVPlacement(0,
                                   SpineVector,
                                   logicSpine,
                                   "physSpine",
                                   logicWorld,
                                   false,
                                   0,
                                   true); 
    
    /* Colours & Styling */
    logicSpine->SetVisAttributes(visAttributesRim);

    // *********************************************************************


    // **** Build subSpines ************************************************
    G4double xSubSpine = 2*cm;
    G4double ySubSpine = 4.8*cm;
    G4double zSubSpine = 0.05*cm;

    solidSubSpine = new G4Box("solidSubSpine",
                           xSubSpine,
                           ySubSpine,
                           zSubSpine); 

    logicSubSpine = new G4LogicalVolume(solidSubSpine,
                                    Al,
                                    "logicSubSpine");

    G4double xSubSpine1Pos = 0.*cm;
    G4double ySubSpine1Pos = ySubSpine + ySpine;
    G4double zSubSpine1Pos = (-zWorld + 2*zFloor + 2*zProfile + zSubSpine);
    
    auto SubSpineVector1 = G4ThreeVector(xSubSpine1Pos, ySubSpine1Pos, zSubSpine1Pos);    


    physSubSpine1  = new G4PVPlacement(0,
                                   SubSpineVector1,
                                   logicSubSpine,
                                   "physSubSpine",
                                   logicWorld,
                                   false,
                                   0,
                                   true); 
 
    G4double xSubSpine2Pos = 0.*cm;
    G4double ySubSpine2Pos = -ySubSpine - ySpine;
    G4double zSubSpine2Pos = (-zWorld + 2*zFloor + 2*zProfile + zSubSpine);
    
    auto SubSpineVector2 = G4ThreeVector(xSubSpine2Pos, ySubSpine2Pos, zSubSpine2Pos);    


    physSubSpine2  = new G4PVPlacement(0,
                                   SubSpineVector2,
                                   logicSubSpine,
                                   "physSubSpine",
                                   logicWorld,
                                   false,
                                   1,
                                   true); 
       
    /* Colours & Styling */
    logicSubSpine->SetVisAttributes(visAttributesRim);

    // *********************************************************************


    // **** Build Cylinder *************************************************
    G4double InnerRadCylinder = 1.68*cm;
    G4double OuterRadCylinder = 3.35*cm;
    G4double HeightCylinder   = 5.2*cm;

    G4double xCylinderPos = 0.*cm;
    G4double yCylinderPos = 0.*cm;
    G4double zCylinderPos = (-zWorld + 2*zFloor + 2*zProfile + 2*HeightRim + HeightCylinder);
    
    auto CylinderVector = G4ThreeVector(xCylinderPos, yCylinderPos, zCylinderPos);    

    solidCylinder = new G4Tubs("solidCylinder",
                           InnerRadCylinder,
                           OuterRadCylinder,
                           HeightCylinder,
                           0.*deg,
                           360.0*deg); 

    logicCylinder = new G4LogicalVolume(solidCylinder,
                                    Pb,
                                    "logicCylinder");

    physCylinder  = new G4PVPlacement(0,
                                   CylinderVector,
                                   logicCylinder,
                                   "physCylinder",
                                   logicWorld,
                                   false,
                                   0,
                                   true); 
    
    /* Colours & Styling */
    G4VisAttributes* visAttributesCylinder = new G4VisAttributes(G4Colour(0.1, 0.1, 0.8));
    visAttributesCylinder->SetVisibility(true);
    visAttributesCylinder->SetForceSolid(true);
    logicCylinder->SetVisAttributes(visAttributesCylinder);

    // *********************************************************************


    // **** Build Plugs ** *************************************************
    G4double InnerRadPlug = 0.*cm;
    G4double OuterRadPlug = 1.68*cm;
    G4double HeightPlug   = 0.85*cm;

    solidPlug = new G4Tubs("solidPlug",
                           InnerRadPlug,
                           OuterRadPlug,
                           HeightPlug,
                           0.*deg,
                           360.0*deg); 

    logicPlug = new G4LogicalVolume(solidPlug,
                                    Pb,
                                    "logicPlug");

    G4double xPlug1Pos = 0.*cm;
    G4double yPlug1Pos = 0.*cm;
    G4double zPlug1Pos = (-zWorld + 2*zFloor + 2*zProfile + 2*HeightRim + 2*HeightCylinder - HeightPlug);
    
    auto Plug1Vector = G4ThreeVector(xPlug1Pos, yPlug1Pos, zPlug1Pos);    

    physPlug1  = new G4PVPlacement(0,
                                   Plug1Vector,
                                   logicPlug,
                                   "physPlug1",
                                   logicWorld,
                                   false,
                                   0,
                                   true); 
 
    G4double xPlug2Pos = 0.*cm;
    G4double yPlug2Pos = 0.*cm;
    G4double zPlug2Pos = (-zWorld + 2*zFloor + 2*zProfile + 2*HeightRim + HeightPlug);
    
    auto Plug2Vector = G4ThreeVector(xPlug2Pos, yPlug2Pos, zPlug2Pos);    

    physPlug2  = new G4PVPlacement(0,
                                   Plug2Vector,
                                   logicPlug,
                                   "physPlug2",
                                   logicWorld,
                                   false,
                                   1,
                                   true);    

    /* Colours & Styling */
    logicPlug->SetVisAttributes(visAttributesCylinder);

    // *********************************************************************



    return physWorld;
};

