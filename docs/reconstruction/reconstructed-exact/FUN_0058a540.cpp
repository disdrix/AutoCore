// =============================================================================
// FUN_0058a540
// -----------------------------------------------------------------------------
// Stable ID: aa_0058a540
// Address:   0x0058a540  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0058a540 @ 0x0058a540
// Stable ID: aa_0058a540
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, do×1, while×1.
//  - Notable callees: CONCAT31, FUN_0058a540.
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

uint FUN_0058a540(int *param_1,int param_2,float param_3)



{

  uint in_EAX;

  int iVar1;

  short *psVar2;

  short *psVar3;

  

  if (param_1 != (int *)0x0) {

    iVar1 = (**(code **)(*param_1 + 0x214))();

    in_EAX = 0;

    if (iVar1 != 0) {

      psVar2 = (short *)(iVar1 + 0x194);

      psVar3 = (short *)(param_2 + 0x90);

      iVar1 = 6;

      do {

        if (*psVar3 != 0) {

          psVar2[-0xc] = (short)(int)((float)(int)*psVar3 * param_3 + (float)(int)psVar2[-0xc]);

          *psVar2 = (short)(int)((float)(int)psVar3[-0xc] * param_3 + (float)(int)*psVar2);

        }

        psVar3 = psVar3 + 1;

        psVar2 = psVar2 + 1;

        iVar1 = iVar1 + -1;

      } while (iVar1 != 0);

      return CONCAT31((int3)((uint)psVar2 >> 8),1);

    }

  }

  return in_EAX & 0xffffff00;

}
