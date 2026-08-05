// =============================================================================
// FUN_0079afa0
// -----------------------------------------------------------------------------
// Stable ID: aa_0079afa0
// Address:   0x0079afa0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0079afa0 @ 0x0079afa0
// Stable ID: aa_0079afa0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_0079afa0, FUN_007a81e0.
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

uint32_t /* width from decompiler */ __fastcall FUN_0079afa0(int *param_1)



{

  char cVar1;

  uint32_t /* width from decompiler */ unaff_ESI;

  uint32_t /* width from decompiler */ uVar2;

  

  cVar1 = (**(code **)(*param_1 + 0xd8))();

  if (cVar1 != '\0') {

    if (*(char *)((int)param_1 + 0xd3) != '\0') {

      uVar2 = 0;

      (**(code **)(*param_1 + 0x3d0))(0);

      (**(code **)(*param_1 + 0x3c8))(*(char *)((int)param_1 + 0x48e) == '\0',1);

      (**(code **)(*param_1 + 0x34c))();

      FUN_007a81e0(uVar2,unaff_ESI);

    }

    return 1;

  }

  return 0;

}
