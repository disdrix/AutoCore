// =============================================================================
// FUN_004febe0
// -----------------------------------------------------------------------------
// Stable ID: aa_004febe0
// Address:   0x004febe0  (autoassault.exe, image base 0x400000)
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

uint32_t /* width from decompiler */ __thiscall FUN_004febe0(int param_1,int param_2)

{
  int *piVar1;
  uint8_t local_18 [4];
  int *local_14;
  int local_10;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t /* width from decompiler */ local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a2d79;
  local_c = ExceptionList;
  if ((param_2 != 0) && (*(int *)(param_1 + 0x2b0) != 0)) {
    ExceptionList = &local_c;
    local_14 = (int *)FUN_0040fb90();
    local_10 = 0;
    local_4 = 0;
    FUN_00572110(0x10,local_18);
    if (local_10 != 0) {
      piVar1 = (int *)*local_14;
      if (piVar1 != local_14) {
        do {
          if (*(uint *)(*(int *)(*(int *)(piVar1[2] + 0xa8) + 0x3c) + 0x3d4) ==
              (uint)*(byte *)(param_2 + 9)) {
            FUN_00403430();
            ExceptionList = local_c;
            return 1;
          }
          piVar1 = (int *)*piVar1;
        } while (piVar1 != local_14);
      }
    }
    FUN_00403430();
  }
  ExceptionList = local_c;
  return 0;
}
