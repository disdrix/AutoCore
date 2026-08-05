// =============================================================================
// FUN_004bfdb0
// -----------------------------------------------------------------------------
// Stable ID: aa_004bfdb0
// Address:   0x004bfdb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004bfdb0 @ 0x004bfdb0
// Stable ID: aa_004bfdb0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: do×2, if×2, return×2, while×2.
//  - Notable callees: FUN_004bfdb0, FUN_005c6720.
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

void __thiscall FUN_004bfdb0(int param_1,uint32_t /* width from decompiler */ param_2,uint8_t param_3)



{

  int iVar1;

  char cVar2;

  int *piVar3;

  uint uVar4;

  int *piVar5;

  

  uVar4 = 0;

  piVar3 = (int *)(param_1 + 8);

  do {

    if ((piVar3[1] != 0) && (piVar5 = *(int **)*piVar3, piVar5 != (int *)*piVar3)) {

      do {

        iVar1 = piVar5[2];

        cVar2 = FUN_005c6720(param_2);

        if (cVar2 != '\0') {

          *(uint8_t *)(iVar1 + 0x51) = param_3;

          return;

        }

        piVar5 = (int *)*piVar5;

      } while (piVar5 != (int *)*piVar3);

    }

    uVar4 = uVar4 + 1;

    piVar3 = piVar3 + 3;

  } while (uVar4 < 9);

  return;

}
