// =============================================================================
// FUN_004f5880
// -----------------------------------------------------------------------------
// Stable ID: aa_004f5880
// Address:   0x004f5880  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004f5880 @ 0x004f5880
// Stable ID: aa_004f5880
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, do×1, while×1.
//  - Notable callees: FUN_004f5880.
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

int * __thiscall FUN_004f5880(int param_1,int param_2)



{

  byte bVar1;

  int iVar2;

  int *piVar3;

  int iVar4;

  

  iVar2 = *(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c);

  if ((iVar2 != 0) && (bVar1 = *(byte *)(iVar2 + 0x716), bVar1 != 0)) {

    iVar4 = 0;

    if (bVar1 != 0) {

      piVar3 = *(int **)(iVar2 + 0x720);

      do {

        if (*piVar3 == param_2) {

          return piVar3;

        }

        iVar4 = iVar4 + 1;

        piVar3 = piVar3 + 0x44;

      } while (iVar4 < (int)(uint)bVar1);

    }

  }

  return (int *)0x0;

}
