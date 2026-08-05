// =============================================================================
// FUN_007701d0
// -----------------------------------------------------------------------------
// Stable ID: aa_007701d0
// Address:   0x007701d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007701d0 @ 0x007701d0
// Stable ID: aa_007701d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×1, do×1, while×1, return×1.
//  - Notable callees: FUN_007701d0.
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

void __fastcall FUN_007701d0(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ *param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  

  puVar1 = (uint32_t /* width from decompiler */ *)param_2[3];

  iVar2 = 0;

  param_2[2] = 0;

  *param_2 = 0;

  if (0 < (int)param_2[1]) {

    do {

      *puVar1 = 0;

      iVar2 = iVar2 + 1;

      puVar1 = puVar1 + 1;

    } while (iVar2 < (int)param_2[1]);

  }

  return;

}
