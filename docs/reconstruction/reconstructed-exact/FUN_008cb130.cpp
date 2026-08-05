// =============================================================================
// FUN_008cb130
// -----------------------------------------------------------------------------
// Stable ID: aa_008cb130
// Address:   0x008cb130  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008cb130 @ 0x008cb130
// Stable ID: aa_008cb130
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~55 non-empty decompiler lines.
//  - Control keywords: if×5, do×1, while×1, for×1, return×1.
//  - Notable callees: FUN_008ca6c0, FUN_008ca930, FUN_008cb130.
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

void FUN_008cb130(int *param_1,int param_2)



{

  int iVar1;

  char cVar2;

  int *piVar3;

  int iVar4;

  uint *puVar5;

  int iVar6;

  uint64_t uVar7;

  uint local_8;

  

  iVar1 = param_2;

  iVar6 = 0;

  param_1[0x156] = 0;

  piVar3 = param_1 + 0x15d;

  iVar4 = 0x10;

  do {

    piVar3[-4] = -1;

    *(uint8_t *)piVar3 = 0;

    *(uint16_t *)(piVar3 + -2) = 0;

    piVar3 = piVar3 + 0xf;

    iVar4 = iVar4 + -1;

  } while (iVar4 != 0);

  param_2 = 0;

  puVar5 = (uint *)(param_1 + 0x159);

  for (local_8 = 0;

      (iVar4 = *(int *)(iVar1 + 4), iVar4 != 0 &&

      (local_8 < (uint)((*(int *)(iVar1 + 8) - iVar4) / 0x14))); local_8 = local_8 + 1) {

    if (*(short *)(iVar4 + iVar6 + 0x10) != 0) {

      cVar2 = FUN_008ca930();

      if (cVar2 != '\0') {

        *puVar5 = (uint)*(byte *)(*(int *)(iVar1 + 4) + iVar6);

        param_2 = param_2 + 1;

        *(uint16_t *)(puVar5 + 2) = *(uint16_t *)(*(int *)(iVar1 + 4) + 0xe + iVar6);

        puVar5[3] = (uint)*(ushort *)(*(int *)(iVar1 + 4) + 0x10 + iVar6);

        puVar5[0xd] = *(uint *)(*(int *)(iVar1 + 4) + iVar6 + 4);

        puVar5 = puVar5 + 0xf;

      }

      if (param_2 == 0x10) break;

    }

    iVar6 = iVar6 + 0x14;

  }

  param_1[0x156] = param_2;

  if ((int *)param_1[0x252] != (int *)0x0) {

    uVar7 = (**(code **)(*(int *)param_1[0x252] + 0x44c))();

    *(uint64_t *)(param_1 + 0x154) = uVar7;

  }

  FUN_008ca6c0();

  if ((int *)param_1[0x252] != (int *)0x0) {

    (**(code **)(*(int *)param_1[0x252] + 0x448))(param_1[0x154],param_1[0x155]);

    uVar7 = (**(code **)(*(int *)param_1[0x252] + 0x44c))();

    *(uint64_t *)(param_1 + 0x154) = uVar7;

  }

  (**(code **)(*param_1 + 0x34c))();

  return;

}
