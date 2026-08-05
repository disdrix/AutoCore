// =============================================================================
// CVOGPhysics_ApplyVector_Vtbl5c_Inferred  (Ghidra: FUN_00404cb0)
// -----------------------------------------------------------------------------
// Stable ID: aa_00404cb0
// Address:   0x00404cb0  (autoassault.exe, image base 0x400000)
// System:    physics / CVOGPhysics
// Generated: 2026-07-23 scaffold; refined 2026-07-29 dual A/B
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Optional readiness prepare on CVOGPhysics, then forward a vector pointer to
//   the bound rigid-body virtual method at vtable slot +0x5c.
//
//   Twin of CVOGPhysics_ApplyImpulseVector @ 0x0040d260 (slot +0x50). Only the
//   final vtbl offset differs (bytes: FF 52 5C vs FF 52 50).
//
// SIGNATURE:
//   void __thiscall (CVOGPhysics* this, void* pVec);  // RET 4
//
// CONTROL FLOW:
//   1) FUN_005070b0(this, &readyByte)  // out-param; EAX=&readyByte
//   2) if readyByte==0 && *(this+0x44)!=0 → FUN_005070d0(this)
//   3) body = *(this+0x3c);  body->vtbl[+0x5c](pVec)   // unconditional
//
// KEY OFFSETS:
//   this+0x3c  body*
//   this+0x44  readiness host*
//   body vtbl +0x5c  vector apply/set (English open)
//
// RELATED:
//   CVOGPhysics_ApplyImpulseVector 0x0040d260  (slot +0x50)
//   Client_Input_DriveControlTick brake-edge call @ 0x00922fd4
//   FUN_005070b0 / FUN_005070d0 readiness helpers
//
// DECOMPILER NOTE:
//   Ghidra shows FUN_005070b0 as returning char*. Bytes: void thiscall writer
//   that leaves EAX = out pointer. Model as out-byte, not returned global*.
// =============================================================================

void __thiscall FUN_00404cb0(int param_1, uint32_t /* pointer width */ param_2)
{
  char *pcVar1;
  uint32_t uStack_4;

  uStack_4 = param_1;
  /* out-param ready flag at high byte of stack this-copy; EAX aliases &flag */
  pcVar1 = (char *)FUN_005070b0((int)&uStack_4 + 3);
  if ((*pcVar1 == '\0') && (*(int *)(param_1 + 0x44) != 0)) {
    FUN_005070d0();
  }
  /* body = *(this+0x3c); (*body)->vtbl[+0x5c](pVec) */
  (**(code **)(**(int **)(param_1 + 0x3c) + 0x5c))(param_2);
  return;
}
