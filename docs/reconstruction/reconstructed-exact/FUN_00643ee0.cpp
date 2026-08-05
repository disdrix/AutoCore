// =============================================================================
// FUN_00643ee0
// -----------------------------------------------------------------------------
// Stable ID: aa_00643ee0
// Address:   0x00643ee0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00643ee0 @ 0x00643ee0
// Stable ID: aa_00643ee0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×4, do×2, while×2, return×1.
//  - Notable callees: FUN_00643ee0, SQRT.
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

void __thiscall FUN_00643ee0(int *param_1,int param_2)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  

  param_1[3] = param_2;

  if (2 < param_1[1]) {

    iVar1 = param_1[1] / 2;

    if ((param_1[3] == 1) && (iVar5 = 0, 0 < param_1[1])) {

      iVar3 = -iVar1;

      do {

        iVar2 = 0;

        if (0 < param_1[1]) {

          iVar4 = -iVar1;

          do {

            if ((float)iVar1 < SQRT((float)iVar4 * (float)iVar4 + (float)iVar3 * (float)iVar3)) {

              *(uint32_t /* width from decompiler */ *)(*param_1 + (param_1[1] * iVar2 + iVar5) * 4) = 0;

            }

            iVar2 = iVar2 + 1;

            iVar4 = iVar4 + 1;

          } while (iVar2 < param_1[1]);

        }

        iVar5 = iVar5 + 1;

        iVar3 = iVar3 + 1;

      } while (iVar5 < param_1[1]);

    }

  }

  return;

}
