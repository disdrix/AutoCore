// =============================================================================
// FUN_00845880
// -----------------------------------------------------------------------------
// Stable ID: aa_00845880
// Address:   0x00845880  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00845880 @ 0x00845880
// Stable ID: aa_00845880
// Embedded strings (evidence for future rename):
//   - "described as"
//   - "Ultimately refined from"
//   - "%s %s, %s:  "
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~104 non-empty decompiler lines.
//  - Control keywords: if×11, return×4, while×2, goto×2, do×1.
//  - Notable callees: FUN_007a6de0×3, free×3, FUN_00402d50×2, FUN_007a69d0×2, FUN_007a6a30×2, FUN_00403450, FUN_00845880, sprintf.
//  - Strings: "described as"; "Ultimately refined from"; "%s %s, %s:  ".
//  - Return sites: 4.

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

uint32_t /* width from decompiler */ FUN_00845880(int *param_1,int param_2)



{

  int iVar1;

  uint uVar2;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint32_t /* width from decompiler */ uVar7;

  uint32_t /* width from decompiler */ uVar8;

  uint8_t **unaff_EBP;

  uint8_t *unaff_ESI;

  uint8_t *local_190;

  uint8_t local_18c [128];

  char local_10c [248];

  void *pvStack_14;

  void *pvStack_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ac4eb;

  local_c = ExceptionList;

  iVar4 = *(int *)(param_2 + 0xa8);

  iVar1 = *(int *)(iVar4 + 0x3c);

  if ((iVar1 != -0x114) && (*(short *)(iVar1 + 0x114) != 0)) {

    local_190 = local_18c;

    ExceptionList = &local_c;

    uVar3 = (*(code *)PTR_FUN_00af8c9c)();

    FUN_00403450(iVar1 + 0x114,uVar3);

    local_4 = 0;

    iVar4 = *param_1;

    uVar3 = FUN_007a69d0();

    uVar3 = FUN_007a6a30(uVar3);

    (**(code **)(iVar4 + 0x250))(uVar3);

    puStack_8 = (uint8_t *)0xffffffff;

    if (unaff_EBP != &local_190) {

      free(unaff_EBP);

    }

    ExceptionList = pvStack_10;

    return 1;

  }

  if ((*(int *)(iVar4 + 0x38) == 0x1a) && (iVar4 != 0)) {

    iVar4 = *(int *)(iVar4 + 0x3c);

    while (iVar4 != 0) {

      if (((short *)(iVar4 + 0x114) != (short *)0x0) && (*(short *)(iVar4 + 0x114) != 0)) {

        ExceptionList = &local_c;

        uVar5 = FUN_007a69d0();

        puVar6 = (uint32_t /* width from decompiler */ *)FUN_00402d50(iVar4 + 0x92);

        local_4 = 1;

        uVar3 = *puVar6;

        uVar7 = FUN_007a6de0("described as",0xffffffff);

        uVar3 = FUN_007a6de0(uVar3,0xffffffff);

        uVar8 = FUN_007a6de0("Ultimately refined from",0xffffffff);

        sprintf(local_10c,"%s %s, %s:  ",uVar8,uVar3,uVar7);

        local_4 = 0xffffffff;

        if (local_190 != local_18c) {

          free(local_190);

        }

        (**(code **)(*param_1 + 0x250))(local_10c);

        FUN_00402d50(iVar4 + 0x114);

        puStack_8 = (uint8_t *)0x2;

        iVar4 = *param_1;

        uVar3 = FUN_007a6a30(uVar5);

        (**(code **)(iVar4 + 0x250))(uVar3);

        local_c = (void *)0xffffffff;

        if (unaff_ESI != &stack0xfffffe6c) {

          free(unaff_ESI);

        }

        ExceptionList = pvStack_14;

        return 1;

      }

      uVar2 = *(uint *)(iVar4 + 0x4d0);

      if (uVar2 == 0xffffffff) {

        return 0;

      }

      iVar4 = *(int *)(*(int *)(*(int *)(*(int *)(DAT_00b041fc + 0xf10) + 0x10) +

                               (*(uint *)(*(int *)(DAT_00b041fc + 0xf10) + 8) & uVar2) * 4) + 4);

      if (iVar4 == 0) {

LAB_008459b5:

        iVar4 = 0;

      }

      else {

        do {

          if (uVar2 == *(uint *)(iVar4 + 0x10)) {

            if (iVar4 == 0) goto LAB_008459b5;

            iVar4 = *(int *)(iVar4 + 8);

            goto LAB_008459bc;

          }

          iVar4 = *(int *)(iVar4 + 0xc);

        } while (iVar4 != 0);

        iVar4 = 0;

      }

LAB_008459bc:

      if (iVar4 == 0) {

        iVar4 = 0;

      }

      else {

        iVar4 = *(int *)(iVar4 + 0x3c);

      }

    }

  }

  return 0;

}
