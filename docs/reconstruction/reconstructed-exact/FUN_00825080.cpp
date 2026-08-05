// =============================================================================
// FUN_00825080
// -----------------------------------------------------------------------------
// Stable ID: aa_00825080
// Address:   0x00825080  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00825080 @ 0x00825080
// Stable ID: aa_00825080
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~105 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_00825080.
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

void FUN_00825080(void)



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

    if (*(int **)(unaff_ESI + 0x544) != (int *)0x0) {

      auStack_24[0] = 1;

      puStack_28 = local_10;

      uStack_2c = 0x8250ba;

      puVar2 = (uint32_t /* width from decompiler */ *)(**(code **)(**(int **)(unaff_ESI + 0x544) + 0x140))();

      uVar1 = puVar2[1];

      uStack_2c = 0;

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x530) = *puVar2;

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x534) = uVar1;

      uStack_30 = 1;

      puStack_34 = auStack_18;

      uStack_38 = 0x8250e2;

      puVar2 = (uint32_t /* width from decompiler */ *)(**(code **)(**(int **)(unaff_ESI + 0x544) + 0x120))();

      uVar1 = puVar2[1];

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x520) = *puVar2;

      uStack_38 = 1;

      puStack_3c = auStack_24;

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x524) = uVar1;

      iStack_40 = 0x825108;

      piVar3 = (int *)(**(code **)(**(int **)(unaff_ESI + 0x544) + 0x140))();

      puStack_3c = (uint32_t /* width from decompiler */ *)(int)((float)*piVar3 * *(float *)(unaff_ESI + 0x508));

      iStack_40 = 1;

      puStack_44 = &uStack_2c;

      iStack_48 = 0x825130;

      iVar4 = (**(code **)(**(int **)(unaff_ESI + 0x544) + 0x140))();

      iStack_40 = (int)((float)*(int *)(iVar4 + 4) * *(float *)(unaff_ESI + 0x508));

      iStack_48 = 1;

      ppuStack_4c = &puStack_34;

      iStack_50 = 0x82515a;

      piVar3 = (int *)(**(code **)(**(int **)(unaff_ESI + 0x544) + 0x140))();

      puStack_44 = (uint32_t /* width from decompiler */ *)((*piVar3 - (int)ppuStack_4c) / 2 + *(int *)(unaff_ESI + 0x520));

      iStack_50 = 1;

      ppuStack_54 = &puStack_3c;

      iVar4 = (**(code **)(**(int **)(unaff_ESI + 0x544) + 0x140))();

      iStack_48 = (*(int *)(iVar4 + 4) - iStack_50) / 2 + *(int *)(unaff_ESI + 0x524);

      (**(code **)(**(int **)(unaff_ESI + 0x544) + 8))(&ppuStack_54);

      (**(code **)(**(int **)(unaff_ESI + 0x544) + 0x118))(&iStack_50);

      (**(code **)(**(int **)(unaff_ESI + 0x544) + 0x34c))();

    }

    if (*(int **)(unaff_ESI + 0x540) != (int *)0x0) {

      auStack_24[0] = 1;

      puStack_28 = local_10;

      uStack_2c = 0x8251e6;

      puVar2 = (uint32_t /* width from decompiler */ *)(**(code **)(**(int **)(unaff_ESI + 0x540) + 0x140))();

      uVar1 = puVar2[1];

      uStack_2c = 0;

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x528) = *puVar2;

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x52c) = uVar1;

      uStack_30 = 1;

      puStack_34 = auStack_18;

      uStack_38 = 0x82520e;

      puVar2 = (uint32_t /* width from decompiler */ *)(**(code **)(**(int **)(unaff_ESI + 0x540) + 0x120))();

      uVar1 = puVar2[1];

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x518) = *puVar2;

      uStack_38 = 1;

      puStack_3c = auStack_24;

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x51c) = uVar1;

      iStack_40 = 0x825234;

      piVar3 = (int *)(**(code **)(**(int **)(unaff_ESI + 0x540) + 0x140))();

      puStack_3c = (uint32_t /* width from decompiler */ *)(int)((float)*piVar3 * *(float *)(unaff_ESI + 0x508));

      iStack_40 = 1;

      puStack_44 = &uStack_2c;

      iStack_48 = 0x82525c;

      iVar4 = (**(code **)(**(int **)(unaff_ESI + 0x540) + 0x140))();

      iStack_40 = (int)((float)*(int *)(iVar4 + 4) * *(float *)(unaff_ESI + 0x508));

      iStack_48 = 1;

      ppuStack_4c = &puStack_34;

      iStack_50 = 0x825286;

      piVar3 = (int *)(**(code **)(**(int **)(unaff_ESI + 0x540) + 0x140))();

      puStack_44 = (uint32_t /* width from decompiler */ *)((*piVar3 - (int)ppuStack_4c) / 2 + *(int *)(unaff_ESI + 0x518));

      iStack_50 = 1;

      ppuStack_54 = &puStack_3c;

      iVar4 = (**(code **)(**(int **)(unaff_ESI + 0x540) + 0x140))();

      iStack_48 = (*(int *)(iVar4 + 4) - iStack_50) / 2 + *(int *)(unaff_ESI + 0x51c);

      (**(code **)(**(int **)(unaff_ESI + 0x540) + 8))(&ppuStack_54);

      (**(code **)(**(int **)(unaff_ESI + 0x540) + 0x118))(&iStack_50);

      (**(code **)(**(int **)(unaff_ESI + 0x540) + 0x34c))();

    }

  }

  return;

}
