// =============================================================================
// FUN_0090d7c0
// -----------------------------------------------------------------------------
// Stable ID: aa_0090d7c0
// Address:   0x0090d7c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0090d7c0 @ 0x0090d7c0
// Stable ID: aa_0090d7c0
// Embedded strings (evidence for future rename):
//   - "DIRLIGHT_H_X"
//   - "DIRLIGHT_H_Y"
//   - "DIRLIGHT_H_Z"
//   - "DIRLIGHT_DIFF_R"
//   - "DIRLIGHT_DIFF_G"
//   - "DIRLIGHT_DIFF_B"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~213 non-empty decompiler lines.
//  - Control keywords: if×25, do×12, while×12, return×12.
//  - Notable callees: atof×12, strtok×12, FUN_0090d7c0.
//  - Strings: "DIRLIGHT_H_X"; "DIRLIGHT_H_Y"; "DIRLIGHT_H_Z"; "DIRLIGHT_DIFF_R".
//  - Return sites: 12.

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

void __thiscall FUN_0090d7c0(int param_1,char *param_2,char *param_3)



{

  char *pcVar1;

  int iVar2;

  char *pcVar3;

  bool bVar4;

  double dVar5;

  

  if ((param_2 != (char *)0x0) && (param_3 != (char *)0x0)) {

    iVar2 = 0xd;

    bVar4 = true;

    pcVar1 = param_2;

    pcVar3 = "DIRLIGHT_H_X";

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

      *(float *)(param_1 + 0x5a0) = (float)dVar5;

      return;

    }

    iVar2 = 0xd;

    bVar4 = true;

    pcVar1 = param_2;

    pcVar3 = "DIRLIGHT_H_Y";

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

      *(float *)(param_1 + 0x5a4) = (float)dVar5;

      return;

    }

    iVar2 = 0xd;

    bVar4 = true;

    pcVar1 = param_2;

    pcVar3 = "DIRLIGHT_H_Z";

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

      *(float *)(param_1 + 0x5a8) = (float)dVar5;

      return;

    }

    iVar2 = 0x10;

    bVar4 = true;

    pcVar1 = param_2;

    pcVar3 = "DIRLIGHT_DIFF_R";

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

      *(float *)(param_1 + 0x57c) = (float)dVar5;

      return;

    }

    iVar2 = 0x10;

    bVar4 = true;

    pcVar1 = param_2;

    pcVar3 = "DIRLIGHT_DIFF_G";

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

      *(float *)(param_1 + 0x580) = (float)dVar5;

      return;

    }

    iVar2 = 0x10;

    bVar4 = true;

    pcVar1 = param_2;

    pcVar3 = "DIRLIGHT_DIFF_B";

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

      *(float *)(param_1 + 0x584) = (float)dVar5;

      return;

    }

    iVar2 = 0xf;

    bVar4 = true;

    pcVar1 = param_2;

    pcVar3 = "DIRLIGHT_AMB_R";

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

      *(float *)(param_1 + 0x56c) = (float)dVar5;

      return;

    }

    iVar2 = 0xf;

    bVar4 = true;

    pcVar1 = param_2;

    pcVar3 = "DIRLIGHT_AMB_G";

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

      *(float *)(param_1 + 0x570) = (float)dVar5;

      return;

    }

    iVar2 = 0xf;

    bVar4 = true;

    pcVar1 = param_2;

    pcVar3 = "DIRLIGHT_AMB_B";

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

      *(float *)(param_1 + 0x574) = (float)dVar5;

      return;

    }

    iVar2 = 0x10;

    bVar4 = true;

    pcVar1 = param_2;

    pcVar3 = "DIRLIGHT_SPEC_R";

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

      *(float *)(param_1 + 0x58c) = (float)dVar5;

      return;

    }

    iVar2 = 0x10;

    bVar4 = true;

    pcVar1 = param_2;

    pcVar3 = "DIRLIGHT_SPEC_G";

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

      *(float *)(param_1 + 0x590) = (float)dVar5;

      return;

    }

    iVar2 = 0x10;

    bVar4 = true;

    pcVar1 = "DIRLIGHT_SPEC_B";

    do {

      if (iVar2 == 0) break;

      iVar2 = iVar2 + -1;

      bVar4 = *param_2 == *pcVar1;

      param_2 = param_2 + 1;

      pcVar1 = pcVar1 + 1;

    } while (bVar4);

    if (bVar4) {

      pcVar1 = strtok((char *)0x0,param_3);

      dVar5 = atof(pcVar1);

      *(float *)(param_1 + 0x594) = (float)dVar5;

    }

  }

  return;

}
