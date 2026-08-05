// =============================================================================
// FUN_004232c0
// -----------------------------------------------------------------------------
// Stable ID: aa_004232c0
// Address:   0x004232c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004232c0 @ 0x004232c0
// Stable ID: aa_004232c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: return×2, for×2, if×1.
//  - Notable callees: FUN_004232c0.
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

uint32_t /* width from decompiler */ __fastcall FUN_004232c0(uint32_t /* width from decompiler */ *param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint uVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ *puVar5;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  puStack_c = &LAB_009bc000;

  local_10 = ExceptionList;

  local_8 = 0;

  ExceptionList = &local_10;

  puVar1 = operator_new__(param_1[1] * 8 + 8);

  if (puVar1 == (uint32_t /* width from decompiler */ *)0x0) {

    ExceptionList = local_10;

    return 0x8007000e;

  }

  puVar4 = (uint32_t /* width from decompiler */ *)*param_1;

  puVar5 = puVar1;

  for (uVar2 = (uint)(param_1[1] * 8) >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {

    *puVar5 = *puVar4;

    puVar4 = puVar4 + 1;

    puVar5 = puVar5 + 1;

  }

  for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {

    *(uint8_t *)puVar5 = *(uint8_t *)puVar4;

    puVar4 = (uint32_t /* width from decompiler */ *)((int)puVar4 + 1);

    puVar5 = (uint32_t /* width from decompiler */ *)((int)puVar5 + 1);

  }

  param_1[1] = param_1[1] + 1;

  operator_delete__((void *)*param_1);

  *param_1 = puVar1;

  ExceptionList = local_10;

  return 0;

}
