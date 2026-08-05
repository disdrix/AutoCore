// =============================================================================
// FUN_00930be0
// -----------------------------------------------------------------------------
// Stable ID: aa_00930be0
// Address:   0x00930be0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00930be0 @ 0x00930be0
// Stable ID: aa_00930be0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00418700, FUN_00418790, FUN_00930be0.
//  - Return sites: 2.

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

uint32_t /* width from decompiler */ * __thiscall

FUN_00930be0(int *param_1,uint32_t /* width from decompiler */ param_2,uint8_t param_3,uint32_t /* width from decompiler */ param_4,

            uint32_t /* width from decompiler */ param_5,uint32_t /* width from decompiler */ param_6,uint32_t /* width from decompiler */ param_7,uint32_t /* width from decompiler */ param_8,

            uint32_t /* width from decompiler */ param_9)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int iVar3;

  int unaff_retaddr;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009ac67a;

  local_c = ExceptionList;

  if (param_1 == (int *)0x0) {

    return (uint32_t /* width from decompiler */ *)0x0;

  }

  ExceptionList = &local_c;

  (**(code **)(*param_1 + 0x300))(1);

  puVar2 = operator_new(0x34);

  puStack_8 = (uint8_t *)0xffffffff;

  *puVar2 = param_1;

  puVar2[7] = param_4;

  puVar2[8] = param_5;

  puVar2[9] = param_6;

  puVar2[4] = param_7;

  puVar2[5] = param_8;

  puVar2[6] = param_9;

  puVar2[0xb] = param_2;

  puVar2[10] = param_2;

  *(uint8_t *)(puVar2 + 0xc) = param_3;

  iVar1 = *(int *)(unaff_retaddr + 0xef4);

  iVar3 = FUN_00418700(iVar1,*(uint32_t /* width from decompiler */ *)(iVar1 + 4),&stack0xffffffec);

  FUN_00418790();

  *(int *)(iVar1 + 4) = iVar3;

  **(int **)(iVar3 + 4) = iVar3;

  ExceptionList = param_1;

  return puVar2;

}
