// =============================================================================
// FUN_00826270
// -----------------------------------------------------------------------------
// Stable ID: aa_00826270
// Address:   0x00826270  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00826270 @ 0x00826270
// Stable ID: aa_00826270
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~105 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_00826270.
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

void FUN_00826270(void)



{

  uint32_t /* width from decompiler */ uVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int *piVar3;

  int iVar4;

  int unaff_ESI;

  uint32_t /* width from decompiler */ **ppuStack_54;

  int iStack_50;

  uint8_t **ppuStack_4c;

  int iStack_48;

  uint32_t /* width from decompiler */ *puStack_44;

  int iStack_40;

  uint32_t /* width from decompiler */ *puStack_3c;

  uint32_t /* width from decompiler */ uStack_38;

  uint8_t *puStack_34;

  uint32_t /* width from decompiler */ uStack_30;

  uint32_t /* width from decompiler */ uStack_2c;

  uint8_t *puStack_28;

  uint32_t /* width from decompiler */ auStack_24 [3];

  uint8_t auStack_18 [8];

  uint8_t local_10 [12];

  

  if (*(char *)(unaff_ESI + 0x4fd) == '\0') {

    *(uint8_t *)(unaff_ESI + 0x4fd) = 1;

    if (*(int **)(unaff_ESI + 0x564) != (int *)0x0) {

      auStack_24[0] = 1;

      puStack_28 = local_10;

      uStack_2c = 0x8262aa;

      puVar2 = (uint32_t /* width from decompiler */ *)(**(code **)(**(int **)(unaff_ESI + 0x564) + 0x140))();

      uVar1 = puVar2[1];

      uStack_2c = 0;

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x534) = *puVar2;

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x538) = uVar1;

      uStack_30 = 1;

      puStack_34 = auStack_18;

      uStack_38 = 0x8262d2;

      puVar2 = (uint32_t /* width from decompiler */ *)(**(code **)(**(int **)(unaff_ESI + 0x564) + 0x120))();

      uVar1 = puVar2[1];

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x524) = *puVar2;

      uStack_38 = 1;

      puStack_3c = auStack_24;

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x528) = uVar1;

      iStack_40 = 0x8262f8;

      piVar3 = (int *)(**(code **)(**(int **)(unaff_ESI + 0x564) + 0x140))();

      puStack_3c = (uint32_t /* width from decompiler */ *)(int)((float)*piVar3 * *(float *)(unaff_ESI + 0x50c));

      iStack_40 = 1;

      puStack_44 = &uStack_2c;

      iStack_48 = 0x826320;

      iVar4 = (**(code **)(**(int **)(unaff_ESI + 0x564) + 0x140))();

      iStack_40 = (int)((float)*(int *)(iVar4 + 4) * *(float *)(unaff_ESI + 0x50c));

      iStack_48 = 1;

      ppuStack_4c = &puStack_34;

      iStack_50 = 0x82634a;

      piVar3 = (int *)(**(code **)(**(int **)(unaff_ESI + 0x564) + 0x140))();

      puStack_44 = (uint32_t /* width from decompiler */ *)((*piVar3 - (int)ppuStack_4c) / 2 + *(int *)(unaff_ESI + 0x524));

      iStack_50 = 1;

      ppuStack_54 = &puStack_3c;

      iVar4 = (**(code **)(**(int **)(unaff_ESI + 0x564) + 0x140))();

      iStack_48 = (*(int *)(iVar4 + 4) - iStack_50) / 2 + *(int *)(unaff_ESI + 0x528);

      (**(code **)(**(int **)(unaff_ESI + 0x564) + 8))(&ppuStack_54);

      (**(code **)(**(int **)(unaff_ESI + 0x564) + 0x118))(&iStack_50);

      (**(code **)(**(int **)(unaff_ESI + 0x564) + 0x34c))();

    }

    if (*(int **)(unaff_ESI + 0x560) != (int *)0x0) {

      auStack_24[0] = 1;

      puStack_28 = local_10;

      uStack_2c = 0x8263d6;

      puVar2 = (uint32_t /* width from decompiler */ *)(**(code **)(**(int **)(unaff_ESI + 0x560) + 0x140))();

      uVar1 = puVar2[1];

      uStack_2c = 0;

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x52c) = *puVar2;

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x530) = uVar1;

      uStack_30 = 1;

      puStack_34 = auStack_18;

      uStack_38 = 0x8263fe;

      puVar2 = (uint32_t /* width from decompiler */ *)(**(code **)(**(int **)(unaff_ESI + 0x560) + 0x120))();

      uVar1 = puVar2[1];

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x51c) = *puVar2;

      uStack_38 = 1;

      puStack_3c = auStack_24;

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x520) = uVar1;

      iStack_40 = 0x826424;

      piVar3 = (int *)(**(code **)(**(int **)(unaff_ESI + 0x560) + 0x140))();

      puStack_3c = (uint32_t /* width from decompiler */ *)(int)((float)*piVar3 * *(float *)(unaff_ESI + 0x50c));

      iStack_40 = 1;

      puStack_44 = &uStack_2c;

      iStack_48 = 0x82644c;

      iVar4 = (**(code **)(**(int **)(unaff_ESI + 0x560) + 0x140))();

      iStack_40 = (int)((float)*(int *)(iVar4 + 4) * *(float *)(unaff_ESI + 0x50c));

      iStack_48 = 1;

      ppuStack_4c = &puStack_34;

      iStack_50 = 0x826476;

      piVar3 = (int *)(**(code **)(**(int **)(unaff_ESI + 0x560) + 0x140))();

      puStack_44 = (uint32_t /* width from decompiler */ *)((*piVar3 - (int)ppuStack_4c) / 2 + *(int *)(unaff_ESI + 0x51c));

      iStack_50 = 1;

      ppuStack_54 = &puStack_3c;

      iVar4 = (**(code **)(**(int **)(unaff_ESI + 0x560) + 0x140))();

      iStack_48 = (*(int *)(iVar4 + 4) - iStack_50) / 2 + *(int *)(unaff_ESI + 0x520);

      (**(code **)(**(int **)(unaff_ESI + 0x560) + 8))(&ppuStack_54);

      (**(code **)(**(int **)(unaff_ESI + 0x560) + 0x118))(&iStack_50);

      (**(code **)(**(int **)(unaff_ESI + 0x560) + 0x34c))();

    }

  }

  return;

}
