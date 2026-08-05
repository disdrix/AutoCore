// =============================================================================
// FUN_0062b3d0
// -----------------------------------------------------------------------------
// Stable ID: aa_0062b3d0
// Address:   0x0062b3d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0062b3d0 @ 0x0062b3d0
// Stable ID: aa_0062b3d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_0062b3d0, FUN_00651a80.
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

void __fastcall FUN_0062b3d0(int param_1)



{

  if (-1 < (int)*(uint *)(param_1 + 0x98)) {

    (**(code **)(*DAT_00b05060 + 0x14))

              (*(uint32_t /* width from decompiler */ *)(param_1 + 0x90),(*(uint *)(param_1 + 0x98) & 0x7fffffff) * 0x1c,0x12)

    ;

  }

  if (-1 < *(int *)(param_1 + 0x3c)) {

    (**(code **)(*DAT_00b05060 + 0x14))

              (*(uint32_t /* width from decompiler */ *)(param_1 + 0x34),*(int *)(param_1 + 0x3c) << 5,0x12);

  }

  if (-1 < (int)*(uint *)(param_1 + 0x28)) {

    (**(code **)(*DAT_00b05060 + 0x14))

              (*(uint32_t /* width from decompiler */ *)(param_1 + 0x20),*(uint *)(param_1 + 0x28) & 0x7fffffff,0x12);

  }

  FUN_00651a80();

  return;

}
