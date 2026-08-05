// =============================================================================
// FUN_008b9370
// -----------------------------------------------------------------------------
// Stable ID: aa_008b9370
// Address:   0x008b9370  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008b9370 @ 0x008b9370
// Stable ID: aa_008b9370
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×4, do×2, while×2, return×1.
//  - Notable callees: FUN_0082ad70, FUN_008b9370.
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

void __fastcall FUN_008b9370(char *param_1,int param_2,int param_3)



{

  char cVar1;

  int in_EAX;

  char *pcVar2;

  

  if ((((-1 < param_3) && (param_3 < 0xf)) && (-1 < param_2)) && (param_2 < 5)) {

    if (*(int *)(in_EAX + 0x568 + param_3 * 4) != 0) {

      FUN_0082ad70();

    }

    param_2 = param_2 + param_3 * 5;

    if ((void *)(&DAT_00d177c8)[param_2] != (void *)0x0) {

      operator_delete__((void *)(&DAT_00d177c8)[param_2]);

    }

    (&DAT_00d177c8)[param_2] = 0;

    if (param_1 != (char *)0x0) {

      pcVar2 = param_1;

      do {

        cVar1 = *pcVar2;

        pcVar2 = pcVar2 + 1;

      } while (cVar1 != '\0');

      pcVar2 = operator_new__((uint)(pcVar2 + (1 - (int)(param_1 + 1))));

      (&DAT_00d177c8)[param_2] = pcVar2;

      do {

        cVar1 = *param_1;

        *pcVar2 = cVar1;

        param_1 = param_1 + 1;

        pcVar2 = pcVar2 + 1;

      } while (cVar1 != '\0');

    }

  }

  return;

}
