// =============================================================================
// FUN_005469a0
// -----------------------------------------------------------------------------
// Stable ID: aa_005469a0
// Address:   0x005469a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005469a0 @ 0x005469a0
// Stable ID: aa_005469a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, do×1, while×1.
//  - Notable callees: FUN_005469a0, FUN_0059d980.
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

uint32_t /* width from decompiler */ __thiscall FUN_005469a0(int param_1,uint32_t /* width from decompiler */ param_2)



{

  char cVar1;

  int iVar2;

  

  iVar2 = 0;

  if (*(char *)(param_1 + 0x130) != '\0') {

    do {

      cVar1 = FUN_0059d980(param_2);

      if (cVar1 != '\0') {

        return 1;

      }

      iVar2 = iVar2 + 1;

    } while (iVar2 < (int)(uint)*(byte *)(param_1 + 0x130));

  }

  return 0;

}
