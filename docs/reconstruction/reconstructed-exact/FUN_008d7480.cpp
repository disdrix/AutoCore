// =============================================================================
// FUN_008d7480
// -----------------------------------------------------------------------------
// Stable ID: aa_008d7480
// Address:   0x008d7480  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008d7480 @ 0x008d7480
// Stable ID: aa_008d7480
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~74 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_004c0380×3, FUN_008d7480.
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

void FUN_008d7480(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  int unaff_ESI;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint32_t /* width from decompiler */ uVar7;

  uint32_t /* width from decompiler */ uVar8;

  uint32_t /* width from decompiler */ uVar9;

  uint32_t /* width from decompiler */ local_40;

  uint32_t /* width from decompiler */ local_3c;

  uint32_t /* width from decompiler */ local_38;

  uint32_t /* width from decompiler */ local_34;

  uint32_t /* width from decompiler */ local_30;

  uint32_t /* width from decompiler */ local_2c;

  uint32_t /* width from decompiler */ local_28;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ uStack_20;

  uint32_t /* width from decompiler */ uStack_1c;

  uint32_t /* width from decompiler */ uStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  

  iVar3 = *(int *)(unaff_ESI + 0x548);

  if ((iVar3 != 0) && (*(int *)(iVar3 + 600) != 0)) {

    local_30 = DAT_00aaa630;

    local_2c = DAT_00aaa630;

    local_28 = DAT_00aaa630;

    local_24 = 0;

    local_40 = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x534);

    local_3c = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x538);

    local_38 = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x53c);

    local_34 = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x540);

    uVar8 = 0;

    uVar7 = 0;

    uVar6 = 1;

    puVar5 = &local_40;

    puVar4 = &local_30;

    uVar2 = (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(iVar3 + 600) + 4) + 4) + 4 +

                                 *(int *)(iVar3 + 600)) + 0x1cc))(puVar4,puVar5,1,0,0,param_2);

    FUN_004c0380(uVar2,puVar4,puVar5,uVar6,uVar7,uVar8,param_2);

    uStack_20 = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x528);

    uStack_1c = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x52c);

    uStack_18 = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x530);

    uStack_14 = 0;

    uVar8 = 0;

    uVar7 = 0;

    uVar6 = 1;

    puVar5 = &local_40;

    puVar4 = &uStack_20;

    uVar2 = (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(unaff_ESI + 0x548) + 4) + 4) + 4 +

                                 *(int *)(unaff_ESI + 0x548)) + 0x1cc))(puVar4,puVar5,1,0,0,param_1)

    ;

    FUN_004c0380(uVar2,puVar4,puVar5,uVar6,uVar7,uVar8,param_1);

    iVar3 = 0;

    do {

      iVar1 = *(int *)(iVar3 + *(int *)(*(int *)(unaff_ESI + 0x548) + 0x260));

      if (iVar1 != 0) {

        uVar9 = 0;

        uVar8 = 0;

        uVar7 = 1;

        puVar5 = &local_40;

        puVar4 = &local_30;

        uVar2 = param_3;

        uVar6 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1) + 0x1cc))

                          (puVar4,puVar5,1,0,0,param_3);

        FUN_004c0380(uVar6,puVar4,puVar5,uVar7,uVar8,uVar9,uVar2);

      }

      iVar3 = iVar3 + 4;

    } while (iVar3 < 0xc);

  }

  return;

}
