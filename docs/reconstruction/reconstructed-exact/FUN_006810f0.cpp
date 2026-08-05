// =============================================================================
// FUN_006810f0
// -----------------------------------------------------------------------------
// Stable ID: aa_006810f0
// Address:   0x006810f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006810f0 @ 0x006810f0
// Stable ID: aa_006810f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~56 non-empty decompiler lines.
//  - Control keywords: for×6, if×2, return×2, do×1, while×1.
//  - Notable callees: FUN_00680e80, FUN_006810f0.
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

uint32_t /* width from decompiler */ __thiscall FUN_006810f0(int param_1,char *param_2,uint param_3)



{

  char cVar1;

  char *pcVar2;

  uint uVar3;

  uint uVar4;

  uint32_t /* width from decompiler */ *puVar5;

  

  if ((uint)((*(int *)(param_1 + 8) - *(int *)(param_1 + 0xc)) - *(int *)(param_1 + 0x10)) < param_3

     ) {

    FUN_00680e80(*(int *)(param_1 + 0xc) + param_3);

  }

  pcVar2 = param_2;

  do {

    cVar1 = *pcVar2;

    pcVar2 = pcVar2 + 1;

  } while (cVar1 != '\0');

  uVar3 = (int)pcVar2 - (int)(param_2 + 1);

  if (uVar3 < param_3) {

    pcVar2 = (char *)(*(int *)(param_1 + 0xc) + *(int *)(param_1 + 4) + *(int *)(param_1 + 0x10));

    for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar2 = *(uint32_t /* width from decompiler */ *)param_2;

      param_2 = param_2 + 4;

      pcVar2 = pcVar2 + 4;

    }

    for (uVar4 = uVar3 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {

      *pcVar2 = *param_2;

      param_2 = param_2 + 1;

      pcVar2 = pcVar2 + 1;

    }

    puVar5 = (uint32_t /* width from decompiler */ *)

             (*(int *)(param_1 + 0xc) + *(int *)(param_1 + 4) + uVar3 + *(int *)(param_1 + 0x10));

    for (uVar4 = param_3 - uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {

      *puVar5 = 0;

      puVar5 = puVar5 + 1;

    }

    for (uVar3 = param_3 - uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {

      *(uint8_t *)puVar5 = 0;

      puVar5 = (uint32_t /* width from decompiler */ *)((int)puVar5 + 1);

    }

    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + param_3;

    return *(uint32_t /* width from decompiler */ *)(param_1 + 0xc);

  }

  pcVar2 = (char *)(*(int *)(param_1 + 4) + *(int *)(param_1 + 0xc) + *(int *)(param_1 + 0x10));

  for (uVar3 = param_3 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {

    *(uint32_t /* width from decompiler */ *)pcVar2 = *(uint32_t /* width from decompiler */ *)param_2;

    param_2 = param_2 + 4;

    pcVar2 = pcVar2 + 4;

  }

  for (uVar3 = param_3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {

    *pcVar2 = *param_2;

    param_2 = param_2 + 1;

    pcVar2 = pcVar2 + 1;

  }

  *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + param_3;

  return *(uint32_t /* width from decompiler */ *)(param_1 + 0xc);

}
