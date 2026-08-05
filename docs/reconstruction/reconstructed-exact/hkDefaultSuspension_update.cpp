// =============================================================================
// hkDefaultSuspension_update
// -----------------------------------------------------------------------------
// Stable ID: aa_0064de50
// Address:   0x0064de50  (autoassault.exe, image base 0x400000)
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

void __fastcall hkDefaultSuspension_update(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  float fVar6;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 0xc);
  fVar6 = *(float *)(*(int *)(*(int *)(*(int *)(param_1 + 8) + 0x30) + 0x3c) + 0x2c);
  if (fVar6 == 0.0) {
    fVar6 = 0.0;
  }
  else {
    fVar6 = g_flOne / fVar6;
  }
  iVar4 = 0;
  if (0 < *(int *)(param_1 + 0x40)) {
    iVar5 = 0;
    do {
      iVar2 = *(int *)(iVar1 + 0x80) + iVar5;
      if (*(char *)(iVar2 + 0x80) == '\0') {
        *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x34) + iVar4 * 4) = 0;
      }
      else {
        if (0.0 <= *(float *)(iVar2 + 0xb4)) {
          iVar3 = *(int *)(param_1 + 0x5c);
        }
        else {
          iVar3 = *(int *)(param_1 + 0x50);
        }
        *(float *)(*(int *)(param_1 + 0x34) + iVar4 * 4) =
             ((*(float *)(*(int *)(param_1 + 0x28) + iVar4 * 4) - *(float *)(iVar2 + 0xb0)) *
              *(float *)(*(int *)(param_1 + 0x44) + iVar4 * 4) * *(float *)(iVar2 + 0xac) -
             *(float *)(iVar3 + iVar4 * 4) * *(float *)(iVar2 + 0xb4)) * fVar6;
      }
      iVar4 = iVar4 + 1;
      iVar5 = iVar5 + 0xc0;
    } while (iVar4 < *(int *)(param_1 + 0x40));
  }
  return;
}
