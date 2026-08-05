// =============================================================================
// FUN_007997b0
// -----------------------------------------------------------------------------
// Stable ID: aa_007997b0
// Address:   0x007997b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007997b0 @ 0x007997b0
// Stable ID: aa_007997b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00799350, FUN_007997b0.
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

void __fastcall

FUN_007997b0(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,char *param_4,char *param_5)



{

  char cVar1;

  int unaff_ESI;

  char local_8 [4];

  char local_4 [4];

  

  cVar1 = FUN_00799350(param_3,param_2,local_4,local_8);

  if (cVar1 != '\0') {

    if (unaff_ESI != 0) {

      local_8[0] = local_8[0] - local_4[0];

    }

    *param_4 = local_4[0];

    *param_5 = local_8[0];

  }

  return;

}
