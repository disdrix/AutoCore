// =============================================================================
// FUN_004d0250
// -----------------------------------------------------------------------------
// Stable ID: aa_004d0250
// Address:   0x004d0250  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004d0250 @ 0x004d0250
// Stable ID: aa_004d0250
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_004d0250, FUN_004e16f0.
//  - Return sites: 1.

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

void FUN_004d0250(int param_1,int param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  

  puVar2 = operator_new(0x18);

  iVar1 = *(int *)(*(int *)(param_1 + 4) + 4);

  *puVar2 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x164 + param_1);

  puVar2[1] = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x168 + param_1);

  if (param_2 == 0) {

    puVar3 = &DAT_009cbf68;

  }

  else {

    puVar3 = (uint32_t /* width from decompiler */ *)(param_2 + 0x160);

  }

  puVar2[2] = *puVar3;

  puVar2[3] = puVar3[1];

  puVar2[4] = puVar3[2];

  puVar2[5] = puVar3[3];

  FUN_004e16f0(puVar2);

  return;

}
