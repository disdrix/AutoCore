// =============================================================================
// FUN_00470640
// -----------------------------------------------------------------------------
// Stable ID: aa_00470640
// Address:   0x00470640  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00470640 @ 0x00470640
// Stable ID: aa_00470640
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~54 non-empty decompiler lines.
//  - Control keywords: if×3, return×3, do×2, while×2, for×2.
//  - Notable callees: FUN_00476d60×2, FUN_00477740×2, FUN_00470640, FUN_004766e0, FUN_00477710.
//  - Return sites: 3.

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

void FUN_00470640(int param_1,char *param_2,uint8_t param_3,uint32_t /* width from decompiler */ *param_4,uint param_5)



{

  char cVar1;

  char *pcVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint uVar5;

  int iVar6;

  int unaff_EBX;

  uint32_t /* width from decompiler */ *puVar7;

  

  if ((((param_1 != 0) && (unaff_EBX != 0)) && (param_2 != (char *)0x0)) &&

     (pcVar2 = param_2, param_4 != (uint32_t /* width from decompiler */ *)0x0)) {

    do {

      cVar1 = *pcVar2;

      pcVar2 = pcVar2 + 1;

    } while (cVar1 != '\0');

    iVar3 = FUN_00477740();

    if (iVar3 == 0) {

      FUN_00476d60();

      return;

    }

    iVar6 = iVar3 - (int)param_2;

    do {

      cVar1 = *param_2;

      param_2[iVar6] = cVar1;

      param_2 = param_2 + 1;

    } while (cVar1 != '\0');

    puVar4 = (uint32_t /* width from decompiler */ *)FUN_00477740();

    if (puVar4 == (uint32_t /* width from decompiler */ *)0x0) {

      FUN_00477710();

      FUN_00476d60();

      return;

    }

    puVar7 = puVar4;

    for (uVar5 = param_5 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {

      *puVar7 = *param_4;

      param_4 = param_4 + 1;

      puVar7 = puVar7 + 1;

    }

    for (uVar5 = param_5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {

      *(uint8_t *)puVar7 = *(uint8_t *)param_4;

      param_4 = (uint32_t /* width from decompiler */ *)((int)param_4 + 1);

      puVar7 = (uint32_t /* width from decompiler */ *)((int)puVar7 + 1);

    }

    FUN_004766e0(param_1);

    *(uint *)(unaff_EBX + 0xb8) = *(uint *)(unaff_EBX + 0xb8) | 0x10;

    *(byte *)(unaff_EBX + 9) = *(byte *)(unaff_EBX + 9) | 0x10;

    *(uint *)(unaff_EBX + 0xcc) = param_5;

    *(int *)(unaff_EBX + 0xc4) = iVar3;

    *(uint32_t /* width from decompiler */ **)(unaff_EBX + 200) = puVar4;

    *(uint8_t *)(unaff_EBX + 0xd0) = param_3;

  }

  return;

}
