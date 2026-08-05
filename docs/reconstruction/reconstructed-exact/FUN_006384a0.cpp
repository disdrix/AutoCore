// =============================================================================
// FUN_006384a0
// -----------------------------------------------------------------------------
// Stable ID: aa_006384a0
// Address:   0x006384a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006384a0 @ 0x006384a0
// Stable ID: aa_006384a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: for×3, do×1, while×1, return×1.
//  - Notable callees: FUN_006384a0.
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

void FUN_006384a0(byte *param_1,int param_2,int param_3)



{

  byte bVar1;

  int iVar2;

  byte *pbVar3;

  uint uVar4;

  int iVar5;

  int unaff_EBX;

  int unaff_ESI;

  int *piVar6;

  int aiStack_40c [258];

  

  aiStack_40c[1] = 0;

  piVar6 = aiStack_40c + 2;

  for (iVar5 = 0xff; iVar2 = param_3, pbVar3 = param_1, iVar5 != 0; iVar5 = iVar5 + -1) {

    *piVar6 = 0;

    piVar6 = piVar6 + 1;

  }

  for (; iVar2 != 0; iVar2 = iVar2 + -1) {

    aiStack_40c[(*pbVar3 ^ 0x80) + 1] = aiStack_40c[(*pbVar3 ^ 0x80) + 1] + 1;

    pbVar3 = pbVar3 + unaff_ESI;

  }

  uVar4 = 1;

  do {

    aiStack_40c[uVar4 + 1] = aiStack_40c[uVar4 + 1] + aiStack_40c[uVar4];

    aiStack_40c[uVar4 + 2] = aiStack_40c[uVar4 + 2] + aiStack_40c[uVar4 + 1];

    aiStack_40c[uVar4 + 3] = aiStack_40c[uVar4 + 3] + aiStack_40c[uVar4 + 2];

    aiStack_40c[uVar4 + 4] = aiStack_40c[uVar4 + 4] + aiStack_40c[uVar4 + 3];

    aiStack_40c[uVar4 + 5] = aiStack_40c[uVar4 + 5] + aiStack_40c[uVar4 + 4];

    uVar4 = uVar4 + 5;

  } while (uVar4 < 0x100);

  for (iVar5 = unaff_EBX + param_3 * 4; iVar5 != unaff_EBX; iVar5 = iVar5 + -4) {

    iVar2 = *(int *)(iVar5 + -4);

    bVar1 = param_1[iVar2 * unaff_ESI];

    aiStack_40c[(bVar1 ^ 0x80) + 1] = aiStack_40c[(bVar1 ^ 0x80) + 1] + -1;

    *(int *)(param_2 + aiStack_40c[(bVar1 ^ 0x80) + 1] * 4) = iVar2;

  }

  return;

}
