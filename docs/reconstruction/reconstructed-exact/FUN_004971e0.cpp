// =============================================================================
// FUN_004971e0
// -----------------------------------------------------------------------------
// Stable ID: aa_004971e0
// Address:   0x004971e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004971e0 @ 0x004971e0
// Stable ID: aa_004971e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: if×1, do×1, while×1, return×1.
//  - Notable callees: FUN_00496750, FUN_004971e0.
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

void __fastcall FUN_004971e0(int param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  

  puVar1 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x1c);

  if (puVar1 != *(uint32_t /* width from decompiler */ **)(param_1 + 0x20)) {

    do {

      FUN_00496750(*puVar1);

      puVar1 = puVar1 + 1;

    } while (puVar1 != *(uint32_t /* width from decompiler */ **)(param_1 + 0x20));

  }

  return;

}
