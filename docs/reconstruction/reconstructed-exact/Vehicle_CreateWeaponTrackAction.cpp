// =============================================================================
// Vehicle_CreateWeaponTrackAction
// -----------------------------------------------------------------------------
// Stable ID: aa_005a4f60
// Address:   0x005a4f60  (autoassault.exe, image base 0x400000)
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

/* Vehicle_CreateWeaponTrackAction — separate timed action (period = 30 ms) for weapon
   tracking / secondary systems. NOT the combat pool.
   
   Countdown special -1000; period +0x08 = 0x1E (30). */

uint32_t /* width from decompiler */ * __thiscall Vehicle_CreateWeaponTrackAction(uint32_t /* width from decompiler */ *param_1,int param_2)

{
  void *unaff_ESI;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t /* width from decompiler */ local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a6358;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CVOGHBBase_ctor(param_1);
  local_4 = 0;
  *param_1 = &PTR_FUN_009d81b8;
  CVOGHBBase_SetPeriodAndCounter(param_1,-1000,true);
  param_1[2] = 0x1e;
  param_1[7] = 4;
  if (param_2 == 0) {
    FUN_007a4480(0,"VOG_DEBUG_STOP");
    FUN_005083f0(1,1);
    ExceptionList = unaff_ESI;
    return param_1;
  }
  param_1[9] = param_2;
  CVOGHBBase_AttachOwnerObject(param_1,(void *)(*(int *)(*(int *)(param_2 + 4) + 4) + 4 + param_2));
  if (*(int *)(*(int *)(param_1[9] + 0x260) + 4) != 0) {
    FUN_004f8430();
  }
  ExceptionList = local_c;
  return param_1;
}
