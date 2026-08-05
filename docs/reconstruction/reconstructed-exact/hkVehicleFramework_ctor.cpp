// =============================================================================
// hkVehicleFramework_ctor
// -----------------------------------------------------------------------------
// Stable ID: aa_0064cd30
// Address:   0x0064cd30  (autoassault.exe, image base 0x400000)
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

uint32_t /* width from decompiler */ * __thiscall hkVehicleFramework_ctor(uint32_t /* width from decompiler */ *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  FUN_00636b30(param_2);
  *param_1 = &PTR_FUN_009e4a40;
  param_1[0xe] = 0;
  param_1[0x7d] = 0;
  param_1[0x7c] = &PTR_FUN_009e4a38;
  param_1[0xb7] = 0;
  param_1[0xb3] = 0;
  param_1[0xb4] = 0;
  param_1[0xb5] = 0;
  param_1[0xb8] = 0;
  param_1[0xb9] = 0;
  param_1[0xbe] = 0;
  param_1[0xba] = 0;
  param_1[0xbb] = 0;
  param_1[0xbc] = 0;
  param_1[0xbf] = 0;
  param_1[0xc0] = 0;
  piVar1 = param_1 + 0xcc;
  *piVar1 = 0;
  param_1[0xcd] = 0;
  param_1[0xce] = 0x80000000;
  hkVehicleFramework_initFromDescriptor(param_2);
  iVar2 = *(int *)(param_2 + 0x54);
  if ((int)(param_1[0xce] & 0x7fffffff) < iVar2) {
    iVar3 = (param_1[0xce] & 0x7fffffff) * 2;
    if (iVar3 <= iVar2) {
      iVar3 = iVar2;
    }
    FUN_005b3300(piVar1,iVar3,4);
  }
  iVar3 = 0;
  param_1[0xcd] = iVar2;
  if (0 < *(int *)(param_2 + 0x54)) {
    do {
      *(uint32_t /* width from decompiler */ *)(*piVar1 + iVar3 * 4) = *(uint32_t /* width from decompiler */ *)(*(int *)(param_2 + 0x50) + iVar3 * 4);
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(param_2 + 0x54));
  }
  param_1[0x7e] = *(uint32_t /* width from decompiler */ *)(*(int *)(param_2 + 4) + 8);
  *(short *)(param_1[0xc] + 6) = *(short *)(param_1[0xc] + 6) + 1;
  return param_1;
}
