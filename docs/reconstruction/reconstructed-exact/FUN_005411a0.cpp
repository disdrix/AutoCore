// =============================================================================
// FUN_005411a0
// -----------------------------------------------------------------------------
// Stable ID: aa_005411a0
// Address:   0x005411a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005411a0 @ 0x005411a0
// Stable ID: aa_005411a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~100 non-empty decompiler lines.
//  - Control keywords: for×12, return×1.
//  - Notable callees: FUN_00510f90, FUN_00511040, FUN_00511100, FUN_005111b0, FUN_00511270, FUN_00511320, FUN_005411a0.
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

void FUN_005411a0(void)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ auStack_300 [17];

  uint32_t /* width from decompiler */ uStack_2bc;

  uint32_t /* width from decompiler */ uStack_2b8;

  uint32_t /* width from decompiler */ auStack_2b4 [75];

  uint32_t /* width from decompiler */ local_180 [95];

  

  puVar2 = local_180;

  for (iVar1 = 0x47; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar2 = 0;

    puVar2 = puVar2 + 1;

  }

  puVar2 = local_180;

  puVar3 = auStack_2b4 + 4;

  for (iVar1 = 0x47; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar3 = *puVar2;

    puVar2 = puVar2 + 1;

    puVar3 = puVar3 + 1;

  }

  auStack_2b4[3] = 0;

  auStack_2b4[2] = 0x5411df;

  FUN_00511040();

  puVar2 = local_180;

  for (iVar1 = 0x5e; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar2 = 0;

    puVar2 = puVar2 + 1;

  }

  puVar2 = local_180;

  puVar3 = auStack_300;

  for (iVar1 = 0x5e; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar3 = *puVar2;

    puVar2 = puVar2 + 1;

    puVar3 = puVar3 + 1;

  }

  FUN_00510f90(0);

  puVar2 = local_180;

  for (iVar1 = 0x4b; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar2 = 0;

    puVar2 = puVar2 + 1;

  }

  puVar2 = local_180;

  puVar3 = auStack_2b4;

  for (iVar1 = 0x4b; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar3 = *puVar2;

    puVar2 = puVar2 + 1;

    puVar3 = puVar3 + 1;

  }

  uStack_2b8 = 0;

  uStack_2bc = 0x541241;

  FUN_00511100();

  puVar2 = local_180;

  for (iVar1 = 0x59; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar2 = 0;

    puVar2 = puVar2 + 1;

  }

  puVar2 = local_180;

  puVar3 = auStack_300 + 5;

  for (iVar1 = 0x59; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar3 = *puVar2;

    puVar2 = puVar2 + 1;

    puVar3 = puVar3 + 1;

  }

  auStack_300[4] = 0;

  auStack_300[3] = 0x541272;

  FUN_005111b0();

  puVar2 = local_180;

  for (iVar1 = 0x48; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar2 = 0;

    puVar2 = puVar2 + 1;

  }

  puVar2 = local_180;

  puVar3 = auStack_2b4 + 3;

  for (iVar1 = 0x48; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar3 = *puVar2;

    puVar2 = puVar2 + 1;

    puVar3 = puVar3 + 1;

  }

  auStack_2b4[2] = 0;

  auStack_2b4[1] = 0x5412a3;

  FUN_00511270();

  puVar2 = local_180;

  for (iVar1 = 0x46; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar2 = 0;

    puVar2 = puVar2 + 1;

  }

  puVar2 = local_180;

  puVar3 = auStack_2b4 + 5;

  for (iVar1 = 0x46; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar3 = *puVar2;

    puVar2 = puVar2 + 1;

    puVar3 = puVar3 + 1;

  }

  auStack_2b4[4] = 0;

  auStack_2b4[3] = 0x5412d4;

  FUN_00511320();

  return;

}
