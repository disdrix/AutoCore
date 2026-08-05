// =============================================================================
// FUN_00781b40
// -----------------------------------------------------------------------------
// Stable ID: aa_00781b40
// Address:   0x00781b40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00781b40 @ 0x00781b40
// Stable ID: aa_00781b40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×4, while×1, return×1.
//  - Notable callees: FUN_004263a0, FUN_007808b0, FUN_00780c90, FUN_00781b40, FUN_00975760.
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

void __fastcall FUN_00781b40(uint32_t /* width from decompiler */ *param_1)



{

  int iVar1;

  

  iVar1 = param_1[0x48];

  *param_1 = &PTR_LAB_00a9b834;

  while (iVar1 != 0) {

    FUN_004263a0(0);

    iVar1 = param_1[0x48];

  }

  if (param_1[0x82] != 0) {

    FUN_00780c90();

  }

  FUN_007808b0();

  operator_delete__((void *)param_1[0x87]);

  operator_delete__((void *)param_1[0x89]);

  operator_delete__((void *)param_1[0x88]);

  operator_delete__((void *)param_1[0x82]);

  if (param_1[0x8a] != 0) {

    if (param_1[0x8b] == 0) {

      *(uint32_t /* width from decompiler */ *)(param_1[0x8a] + 4) = param_1[0x8c];

    }

    else {

      *(uint32_t /* width from decompiler */ *)(param_1[0x8b] + 8) = param_1[0x8c];

    }

    if (param_1[0x8c] != 0) {

      *(uint32_t /* width from decompiler */ *)(param_1[0x8c] + 4) = param_1[0x8b];

    }

  }

  FUN_00975760();

  return;

}
