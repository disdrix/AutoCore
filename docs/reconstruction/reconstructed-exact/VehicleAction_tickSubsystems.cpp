// =============================================================================
// VehicleAction_tickSubsystems
// -----------------------------------------------------------------------------
// Stable ID: aa_00636a60
// Address:   0x00636a60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WI-MOV-003: this = hkVehicleFramework (VA+0x40), NOT VehicleAction. Call site applyAction
   005987a2: ECX=[ESI+0x40]. Body: fw+8 += dt; vtbl+0x14 on self then 7 children at +0x14..+0x2c;
   vtbl+0x18 post-tick. entity+0x1a0 is 0xC handle: [0]=VehicleAction*, [4]=framework*,
   [8]=driverInput/ctrl* (PushDriveAxes → ctrl+0x20 throttle). */

void __thiscall VehicleAction_tickSubsystems(int *param_1,float *param_2)

{
  uint64_t uVar1;
  
  if (DAT_00bc5644 < DAT_00bc5648) {
    *DAT_00bc5644 = "TtVehicle";
    uVar1 = rdtsc();
    DAT_00bc5644[1] = (int)uVar1;
    DAT_00bc5644 = DAT_00bc5644 + 3;
  }
  param_1[2] = (int)((float)param_1[2] + *param_2);
  (**(code **)(*param_1 + 0x14))(param_2);
  (**(code **)(*(int *)param_1[5] + 0x14))(param_2);
  (**(code **)(*(int *)param_1[6] + 0x14))(param_2);
  (**(code **)(*(int *)param_1[7] + 0x14))(param_2);
  (**(code **)(*(int *)param_1[8] + 0x14))(param_2);
  (**(code **)(*(int *)param_1[9] + 0x14))(param_2);
  (**(code **)(*(int *)param_1[10] + 0x14))(param_2);
  (**(code **)(*(int *)param_1[0xb] + 0x14))(param_2);
  (**(code **)(*param_1 + 0x18))(param_2);
  if (DAT_00bc5644 < DAT_00bc5648) {
    *DAT_00bc5644 = &DAT_009d2878;
    uVar1 = rdtsc();
    DAT_00bc5644[1] = (int)uVar1;
    DAT_00bc5644 = DAT_00bc5644 + 3;
  }
  return;
}
