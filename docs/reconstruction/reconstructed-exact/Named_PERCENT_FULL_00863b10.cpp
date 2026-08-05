// =============================================================================
// Named_PERCENT_FULL_00863b10
// -----------------------------------------------------------------------------
// Stable ID: aa_00863b10
// Address:   0x00863b10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_PERCENT_FULL_00863b10 @ 0x00863b10
// Stable ID: aa_00863b10
// Embedded strings (evidence for future rename):
//   - "SPEED"
//   - "PERCENT_FULL"
//   - "SCALE_X"
//   - "SCALE_Y"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~80 non-empty decompiler lines.
//  - Control keywords: if×9, do×4, while×4, return×4.
//  - Notable callees: atof×4, strtok×4, FUN_00863b10.
//  - Strings: "SPEED"; "PERCENT_FULL"; "SCALE_X"; "SCALE_Y".
//  - Return sites: 4.

/*
 * Behavioral notes:
 * String-driven rename evidence: "PERCENT_FULL"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall Named_PERCENT_FULL_00863b10(int *param_1,char *param_2,char *param_3)



{

  char *pcVar1;

  int iVar2;

  char *pcVar3;

  bool bVar4;

  double dVar5;

  

  if ((param_2 != (char *)0x0) && (param_3 != (char *)0x0)) {

    iVar2 = 6;

    bVar4 = true;

    pcVar1 = param_2;

    pcVar3 = "SPEED";

    do {

      if (iVar2 == 0) break;

      iVar2 = iVar2 + -1;

      bVar4 = *pcVar1 == *pcVar3;

      pcVar1 = pcVar1 + 1;

      pcVar3 = pcVar3 + 1;

    } while (bVar4);

    if (bVar4) {

      pcVar1 = strtok((char *)0x0,param_3);

      dVar5 = atof(pcVar1);

      (**(code **)(*param_1 + 0x3b4))((float)DAT_00d1e81c * (float)dVar5 * DAT_00aaa678);

      return;

    }

    iVar2 = 0xd;

    bVar4 = true;

    pcVar1 = param_2;

    pcVar3 = "PERCENT_FULL";

    do {

      if (iVar2 == 0) break;

      iVar2 = iVar2 + -1;

      bVar4 = *pcVar1 == *pcVar3;

      pcVar1 = pcVar1 + 1;

      pcVar3 = pcVar3 + 1;

    } while (bVar4);

    if (bVar4) {

      pcVar1 = strtok((char *)0x0,param_3);

      iVar2 = *param_1;

      dVar5 = atof(pcVar1);

      (**(code **)(iVar2 + 0x3b0))((float)dVar5);

      return;

    }

    iVar2 = 8;

    bVar4 = true;

    pcVar1 = param_2;

    pcVar3 = "SCALE_X";

    do {

      if (iVar2 == 0) break;

      iVar2 = iVar2 + -1;

      bVar4 = *pcVar1 == *pcVar3;

      pcVar1 = pcVar1 + 1;

      pcVar3 = pcVar3 + 1;

    } while (bVar4);

    if (bVar4) {

      pcVar1 = strtok((char *)0x0,param_3);

      iVar2 = *param_1;

      dVar5 = atof(pcVar1);

      (**(code **)(iVar2 + 0x3b8))((float)dVar5);

      return;

    }

    iVar2 = 8;

    bVar4 = true;

    pcVar1 = "SCALE_Y";

    do {

      if (iVar2 == 0) break;

      iVar2 = iVar2 + -1;

      bVar4 = *param_2 == *pcVar1;

      param_2 = param_2 + 1;

      pcVar1 = pcVar1 + 1;

    } while (bVar4);

    if (bVar4) {

      pcVar1 = strtok((char *)0x0,param_3);

      iVar2 = *param_1;

      dVar5 = atof(pcVar1);

      (**(code **)(iVar2 + 0x3bc))((float)dVar5);

    }

  }

  return;

}
