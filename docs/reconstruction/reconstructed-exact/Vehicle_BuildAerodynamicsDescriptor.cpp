// =============================================================================
// Vehicle_BuildAerodynamicsDescriptor
// -----------------------------------------------------------------------------
// Stable ID: aa_005fc4f0
// Address:   0x005fc4f0  (autoassault.exe, image base 0x400000)
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

int Vehicle_BuildAerodynamicsDescriptor(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ *param_3)

{
  uint32_t /* width from decompiler */ uVar1;
  uint32_t /* width from decompiler */ uVar2;
  int iVar3;
  uint32_t /* width from decompiler */ local_14;
  
  *param_3 = *(uint32_t /* width from decompiler */ *)
              (*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c) +
              0x5a8);
  param_3[1] = *(uint32_t /* width from decompiler */ *)
                (*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c) +
                0x59c);
  param_3[2] = *(uint32_t /* width from decompiler */ *)
                (*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c) +
                0x5a0);
  param_3[3] = *(uint32_t /* width from decompiler */ *)
                (*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c) +
                0x5a4);
  iVar3 = *(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c);
  uVar1 = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x5b0);
  uVar2 = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x5b4);
  param_3[4] = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x5ac);
  param_3[5] = uVar1;
  param_3[6] = uVar2;
  param_3[7] = local_14;
  return iVar3 + 0x5ac;
}
