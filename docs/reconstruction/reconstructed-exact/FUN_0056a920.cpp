// =============================================================================
// FUN_0056a920
// -----------------------------------------------------------------------------
// Stable ID: aa_0056a920
// Address:   0x0056a920  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0056a920 @ 0x0056a920
// Stable ID: aa_0056a920
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: FUN_0040da70, FUN_0056a920, FUN_0074e910, FUN_0079a110.
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

uint32_t /* width from decompiler */ __thiscall FUN_0056a920(int param_1,int param_2)



{

  char cVar1;

  int iVar2;

  float10 fVar3;

  

  if (((*(int **)(param_1 + 0x24) != (int *)0x0) && (-1 < param_2)) &&

     (iVar2 = *(int *)(param_1 + 0x2c + param_2 * 4), iVar2 != 0)) {

    cVar1 = (**(code **)(**(int **)(param_1 + 0x24) + 0x18))(iVar2,0x3e4ccccd,0x3f800000);

    if (cVar1 != '\0') {

      *(int *)(param_1 + 0x78) = param_2;

      *(uint8_t *)(param_1 + 0xc) = 1;

      if (param_2 == 1) {

        iVar2 = FUN_0040da70();

        if ((*(byte *)(iVar2 + 0x536) & 0x80) == 0) {

          fVar3 = (float10)FUN_0079a110();

          FUN_0074e910(0,(float)fVar3);

        }

      }

      return 1;

    }

  }

  return 0;

}
