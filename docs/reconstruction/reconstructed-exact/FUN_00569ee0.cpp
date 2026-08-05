// =============================================================================
// FUN_00569ee0
// -----------------------------------------------------------------------------
// Stable ID: aa_00569ee0
// Address:   0x00569ee0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00569ee0 @ 0x00569ee0
// Stable ID: aa_00569ee0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: if×6, do×1, while×1, return×1.
//  - Notable callees: FUN_00569ee0, FUN_006a3db0, ceil.
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

void __thiscall FUN_00569ee0(int param_1,float param_2,char param_3)



{

  short sVar1;

  short *psVar2;

  int iVar3;

  

  if ((param_2 <= DAT_009c8354) || (DAT_009d2f7c <= param_2)) {

    psVar2 = (short *)(param_1 + 0x130);

    iVar3 = 6;

    do {

      if (*psVar2 != 0) {

        ceil((double)((float)(int)*psVar2 * param_2));

        sVar1 = FUN_006a3db0();

        if ((param_3 != '\0') && (sVar1 == *psVar2)) {

          if (param_2 <= g_flOne) {

            sVar1 = sVar1 + -1;

          }

          else {

            sVar1 = sVar1 + 1;

          }

        }

        if (sVar1 < 1) {

          sVar1 = 1;

        }

        if (sVar1 < psVar2[-6]) {

          sVar1 = psVar2[-6];

        }

        *psVar2 = sVar1;

      }

      psVar2 = psVar2 + 1;

      iVar3 = iVar3 + -1;

    } while (iVar3 != 0);

  }

  return;

}
