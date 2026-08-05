// =============================================================================
// FUN_00770170
// -----------------------------------------------------------------------------
// Stable ID: aa_00770170
// Address:   0x00770170  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00770170 @ 0x00770170
// Stable ID: aa_00770170
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: return×3, if×2, do×1, while×1.
//  - Notable callees: FUN_00770170.
//  - Return sites: 3.

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

int __fastcall FUN_00770170(uint32_t /* width from decompiler */ param_1,char param_2)



{

  char *pcVar1;

  int iVar2;

  

  iVar2 = 0;

  pcVar1 = &DAT_00d183b4;

  do {

    if (*pcVar1 == param_2) {

      if ((&DAT_00d183b0)[iVar2 * 0x19] == 0) {

        return -1;

      }

      return iVar2;

    }

    pcVar1 = pcVar1 + 100;

    iVar2 = iVar2 + 1;

  } while ((int)pcVar1 < 0xd19034);

  return -1;

}
