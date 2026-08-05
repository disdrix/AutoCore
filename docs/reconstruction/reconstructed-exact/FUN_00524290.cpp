// =============================================================================
// FUN_00524290
// -----------------------------------------------------------------------------
// Stable ID: aa_00524290
// Address:   0x00524290  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00524290 @ 0x00524290
// Stable ID: aa_00524290
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, do×1, while×1.
//  - Notable callees: FUN_00524290.
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

int __fastcall FUN_00524290(int param_1)



{

  int iVar1;

  uint *puVar2;

  uint uVar3;

  

  uVar3 = (*(byte *)(param_1 + 0x59a) >> 1) + 3;

  if (7 < uVar3) {

    uVar3 = 8;

  }

  iVar1 = 0;

  if (uVar3 != 0) {

    puVar2 = (uint *)(param_1 + 0x5a0);

    do {

      if ((*puVar2 & puVar2[1]) == 0xffffffff) {

        return iVar1;

      }

      iVar1 = iVar1 + 1;

      puVar2 = puVar2 + 2;

    } while (iVar1 < (int)uVar3);

  }

  return -1;

}
