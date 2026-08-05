void FUN_005d73a0(void)

{
  VehicleEntity_SetSteerInput(0);
  VehicleEntity_SetLongitudinalInput(0);
  VehicleEntity_SetHandbrake(1);
  CVOGHBAIFollowVehicle_FireWeapons(0,0);
  VehicleEntity_PushDriveAxesToController();
  FUN_005cc560();
  return;
}
