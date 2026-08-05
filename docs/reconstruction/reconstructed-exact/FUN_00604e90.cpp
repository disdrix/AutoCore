// =============================================================================
// FUN_00604e90
// -----------------------------------------------------------------------------
// Stable ID: aa_00604e90
// Address:   0x00604e90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00604e90 @ 0x00604e90
// Stable ID: aa_00604e90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×3, do×3, while×3, return×2.
//  - Notable callees: FUN_00604e90.
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

void __thiscall FUN_00604e90(int param_1,char *param_2)



{

  char cVar1;

  char *pcVar2;

  

  if (*(void **)(param_1 + 4) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 4));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 4) = 0;

  if (param_2 != (char *)0x0) {

    pcVar2 = param_2;

    do {

      cVar1 = *pcVar2;

      pcVar2 = pcVar2 + 1;

    } while (cVar1 != '\0');

    if (pcVar2 != param_2 + 1) {

      pcVar2 = param_2;

      do {

        cVar1 = *pcVar2;

        pcVar2 = pcVar2 + 1;

      } while (cVar1 != '\0');

      pcVar2 = operator_new__((uint)(pcVar2 + (1 - (int)(param_2 + 1))));

      *(char **)(param_1 + 4) = pcVar2;

      do {

        cVar1 = *param_2;

        *pcVar2 = cVar1;

        param_2 = param_2 + 1;

        pcVar2 = pcVar2 + 1;

      } while (cVar1 != '\0');

    }

  }

  return;

}
