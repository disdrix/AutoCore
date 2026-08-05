// =============================================================================
// FUN_00790630
// -----------------------------------------------------------------------------
// Stable ID: aa_00790630
// Address:   0x00790630  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00790630 @ 0x00790630
// Stable ID: aa_00790630
// Embedded strings (evidence for future rename):
//   - "SHOW_BG"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, while×1, return×1.
//  - Notable callees: FUN_00790630, atoi, strtok.
//  - Strings: "SHOW_BG".
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

void __thiscall FUN_00790630(int param_1,char *param_2,char *param_3)



{

  char *pcVar1;

  int iVar2;

  bool bVar3;

  

  if ((param_2 != (char *)0x0) && (param_3 != (char *)0x0)) {

    iVar2 = 8;

    bVar3 = true;

    pcVar1 = "SHOW_BG";

    do {

      if (iVar2 == 0) break;

      iVar2 = iVar2 + -1;

      bVar3 = *param_2 == *pcVar1;

      param_2 = param_2 + 1;

      pcVar1 = pcVar1 + 1;

    } while (bVar3);

    if (bVar3) {

      pcVar1 = strtok((char *)0x0,param_3);

      iVar2 = atoi(pcVar1);

      *(bool *)(param_1 + 0x495) = iVar2 != 0;

    }

  }

  return;

}
