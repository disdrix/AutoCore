// =============================================================================
// FUN_007a4ee0
// -----------------------------------------------------------------------------
// Stable ID: aa_007a4ee0
// Address:   0x007a4ee0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007a4ee0 @ 0x007a4ee0
// Stable ID: aa_007a4ee0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, do×1, while×1.
//  - Notable callees: FUN_007a4ee0.
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

int FUN_007a4ee0(int param_1,int param_2)



{

  int iVar1;

  int in_EAX;

  uint uVar2;

  uint uVar3;

  int *piVar4;

  

  if (*(int *)(in_EAX + 8) == 0) {

    uVar2 = 0;

  }

  else {

    uVar2 = *(int *)(in_EAX + 0xc) - *(int *)(in_EAX + 8) >> 2;

  }

  uVar3 = 0;

  if (uVar2 != 0) {

    piVar4 = *(int **)(in_EAX + 8);

    do {

      iVar1 = *piVar4;

      if (((iVar1 != 0) && (*(int *)(iVar1 + 0x200) == param_1)) &&

         (*(int *)(iVar1 + 0x204) == param_2)) {

        return (*(int **)(in_EAX + 8))[uVar3];

      }

      uVar3 = uVar3 + 1;

      piVar4 = piVar4 + 1;

    } while (uVar3 < uVar2);

  }

  return 0;

}
