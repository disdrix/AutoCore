// =============================================================================
// FUN_005b0ed0
// -----------------------------------------------------------------------------
// Stable ID: aa_005b0ed0
// Address:   0x005b0ed0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005b0ed0 @ 0x005b0ed0
// Stable ID: aa_005b0ed0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~69 non-empty decompiler lines.
//  - Control keywords: if×7, return×1.
//  - Notable callees: FUN_004c00f0, FUN_004d0e90, FUN_0053dd40, FUN_005b0ed0, FUN_00797170.
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

void __fastcall FUN_005b0ed0(int param_1)



{

  uint *puVar1;

  byte bVar2;

  bool bVar3;

  char cVar4;

  int *piVar5;

  int iVar6;

  uint32_t /* width from decompiler */ uVar7;

  uint32_t /* width from decompiler */ uStack_44;

  uint32_t /* width from decompiler */ uStack_40;

  uint32_t /* width from decompiler */ uStack_3c;

  uint32_t /* width from decompiler */ uStack_38;

  uint32_t /* width from decompiler */ uStack_34;

  uint32_t /* width from decompiler */ uStack_30;

  uint32_t /* width from decompiler */ uStack_2c;

  uint32_t /* width from decompiler */ uStack_28;

  uint8_t auStack_24 [32];

  

  if ((*(int *)(param_1 + 0x5c) != 0) && (*(int *)(param_1 + 0x50) != 0)) {

    piVar5 = (int *)(**(code **)(**(int **)(param_1 + 0x50) + 0x1c8))();

    (**(code **)(*(int *)(*(int *)(piVar5[1] + 4) + 4 + (int)piVar5) + 0x240))

              (*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x5c) + 0x10));

    bVar2 = *(byte *)(*(int *)(param_1 + 0x5c) + 0x8a);

    cVar4 = (**(code **)(*(int *)(*(int *)(piVar5[1] + 4) + 4 + (int)piVar5) + 0x198))();

    if ((cVar4 == '\0') || (bVar2 != 0)) {

      cVar4 = (**(code **)(*(int *)(*(int *)(piVar5[1] + 4) + 4 + (int)piVar5) + 0x198))();

      if ((cVar4 == '\0') && (bVar2 != 0)) {

        *(uint32_t /* width from decompiler */ *)(*(int *)(piVar5[1] + 4) + 0xd0 + (int)piVar5) = 0;

        FUN_004d0e90((int)piVar5 + *(int *)(piVar5[1] + 4) + 4);

      }

      else {

        puVar1 = (uint *)((int)piVar5 + *(int *)(piVar5[1] + 4) + 0x180);

        *puVar1 = *puVar1 ^ ((uint)bVar2 << 8 ^

                            *(uint *)((int)piVar5 + *(int *)(piVar5[1] + 4) + 0x180)) & 0x100;

      }

    }

    else {

      FUN_0053dd40();

      iVar6 = (**(code **)(*(int *)(*(int *)(piVar5[1] + 4) + 4 + (int)piVar5) + 0x1cc))();

      if (iVar6 != 0) {

        uVar7 = (**(code **)(*(int *)((int)piVar5 + *(int *)(piVar5[1] + 4) + 4) + 0x1cc))();

        FUN_004c00f0(uVar7);

      }

    }

    iVar6 = piVar5[2];

    if (iVar6 != 0) {

      if ((*(char *)(iVar6 + 0x40) == '\0') || (*(int *)(iVar6 + 8) == 0)) {

        bVar3 = true;

      }

      else {

        bVar3 = false;

      }

      if (bVar3) {

        iVar6 = *(int *)(param_1 + 0x5c);

        uStack_44 = 0;

        uStack_40 = 0;

        uStack_3c = 0;

        uStack_38 = 0;

        uStack_2c = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x6c);

        uStack_30 = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x68);

        uStack_34 = *(uint32_t /* width from decompiler */ *)(iVar6 + 100);

        uStack_28 = 0;

        FUN_00797170(auStack_24);

        (**(code **)(*piVar5 + 0x24))(&uStack_34,auStack_24,&uStack_44,&uStack_44,0);

      }

    }

  }

  return;

}
