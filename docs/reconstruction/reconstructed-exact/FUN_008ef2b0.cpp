// =============================================================================
// FUN_008ef2b0
// -----------------------------------------------------------------------------
// Stable ID: aa_008ef2b0
// Address:   0x008ef2b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008ef2b0 @ 0x008ef2b0
// Stable ID: aa_008ef2b0
// Embedded strings (evidence for future rename):
//   - "this location"
//   - "is that correct?"
//   - "for a small fee"
//   - "INC will pick you up and drop you off at"
//   - "%s %s %s, %s"
//   - "the nearest repair station"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~170 non-empty decompiler lines.
//  - Control keywords: if×23, return×10, switch×1, for×1.
//  - Notable callees: FUN_007a6de0×8, CNDHash_LookupByKey×2, FUN_007fdfb0×2, FUN_008ec980×2, FUN_008ed8a0×2, sprintf×2, FUN_00402d50, FUN_00541a80.
//  - Strings: "this location"; "is that correct?"; "for a small fee"; "INC will pick you up and drop you off at".
//  - Return sites: 10.

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

uint32_t /* width from decompiler */ __thiscall FUN_008ef2b0(int param_1,int param_2,int param_3)



{

  int iVar1;

  char cVar2;

  int *piVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ *puVar5;

  void *pvVar6;

  void *pvVar7;

  uint32_t /* width from decompiler */ uVar8;

  uint32_t /* width from decompiler */ uVar9;

  uint32_t /* width from decompiler */ uVar10;

  uint32_t /* width from decompiler */ uVar11;

  char *pcVar12;

  uint uVar13;

  uint8_t auStack_4a8 [3];

  char cStack_4a5;

  uint local_4a4;

  int local_4a0;

  int iStack_49c;

  int local_498;

  int iStack_494;

  uint8_t *puStack_490;

  uint8_t auStack_48c [128];

  char acStack_40c [1024];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009b3a93;

  local_c = ExceptionList;

  local_4a4 = 0;

  ExceptionList = &local_c;

  FUN_007a69d0();

  if (0x9c44 < param_3) {

    if (param_2 == 5) {

      piVar3 = (int *)FUN_008eb970(param_3);

      if (piVar3 != (int *)0x0) {

        puVar4 = (uint32_t /* width from decompiler */ *)(**(code **)(*piVar3 + 0x140))(&local_498,1);

        puVar5 = (uint32_t /* width from decompiler */ *)(**(code **)(*piVar3 + 0x120))(auStack_4a8,1,0);

        FUN_008ec6d0(*puVar5,puVar5[1],*puVar4,puVar4[1]);

      }

      ExceptionList = local_c;

      return 1;

    }

    if (param_2 == 6) {

      FUN_008ebe60();

      ExceptionList = local_c;

      return 1;

    }

    if ((param_2 == 8) && (DAT_00d1b6d8 != 0)) {

      if (*(int *)(param_1 + 0x50c) == 0) {

        FUN_008eec60(param_3 + -0x9c45);

      }

      ExceptionList = local_c;

      return 1;

    }

  }

  switch(param_3 + -40000) {

  case 0:

    if (param_2 == 8) {

      FUN_007fca10();

      ExceptionList = local_c;

      return 1;

    }

    break;

  default:

    if (param_2 == 7) {

      if (((*(int **)(param_1 + 0x67c) != (int *)0x0) && (*(int *)(param_1 + 0x50c) == 1)) &&

         (*(int *)(DAT_00d1b644 + 0xfc) == *(int *)(param_1 + 0x540))) {

        (**(code **)(**(int **)(param_1 + 0x67c) + 0x120))(&local_4a0,1,1);

        (**(code **)(**(int **)(param_1 + 0x67c) + 0x140))(&local_4a4,1);

        if (((DAT_00d1d86c < local_4a0) || (local_498 + local_4a0 <= DAT_00d1d86c)) ||

           ((DAT_00d1d870 < iStack_49c ||

            ((iStack_494 + iStack_49c <= DAT_00d1d870 || (cVar2 = FUN_0084f810(), cVar2 == '\0')))))

           ) {

          DAT_00d1ad1c = 0;

        }

      }

    }

    else if ((param_2 == 0xe) && (*(int *)(param_1 + 0x50c) == 1)) {

      FUN_008ed8a0();

    }

    break;

  case 2:

    if (param_2 == 8) {

      if (*(int *)(param_1 + 0x50c) == 0) {

        FUN_008ec980();

      }

      ExceptionList = local_c;

      return 1;

    }

    break;

  case 3:

    if (param_2 == 8) {

      if (*(int *)(param_1 + 0x50c) == 0) {

        FUN_008ec980();

        ExceptionList = local_c;

        return 1;

      }

      if (*(int *)(param_1 + 0x50c) == 1) {

        FUN_008ed8a0();

      }

      ExceptionList = local_c;

      return 1;

    }

    break;

  case 4:

    if (param_2 == 8) {

      if (((*(int *)(param_1 + 0x50c) == 1) && (DAT_00d1b6d8 != 0)) &&

         (uVar13 = *(uint *)(param_1 + 0x540), -1 < (int)uVar13)) {

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x548) = 0xffffffff;

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x54c) = 0xffffffff;

        *(uint *)(param_1 + 0x544) = uVar13;

        pvVar6 = (void *)FUN_00541a80();

        pvVar6 = CNDHash_LookupByKey(pvVar6,uVar13);

        iVar1 = DAT_00d1b644;

        if ((DAT_00d1b644 == 0) ||

           (cStack_4a5 = '\x01', *(int *)(DAT_00d1b644 + 0xfc) != *(int *)(param_1 + 0x540))) {

          cStack_4a5 = '\0';

        }

        uVar13 = *(uint *)(param_1 + 0x540);

        pvVar7 = CNDHash_LookupByKey(*(void **)(DAT_00d1b6d8 + 0x534),uVar13);

        if (((pvVar7 != (void *)0x0) && (*(char *)((int)pvVar7 + 4) == '\x02')) ||

           (cStack_4a5 == '\x01')) {

          if ((iVar1 == 0) || (*(uint *)(iVar1 + 0xfc) != uVar13)) {

            if (pvVar6 == (void *)0x0) {

              pcVar12 = "this location";

            }

            else {

              puVar4 = (uint32_t /* width from decompiler */ *)FUN_00402d50((int)pvVar6 + 0xb4);

              uStack_4 = 0;

              pcVar12 = (char *)*puVar4;

              local_4a4 = 1;

            }

            uVar11 = FUN_007a6de0(pcVar12,0xffffffff);

            uVar8 = FUN_007a6de0("is that correct?",0xffffffff);

            uVar9 = FUN_007a6de0("for a small fee",0xffffffff);

            uVar10 = FUN_007a6de0("INC will pick you up and drop you off at",0xffffffff);

            sprintf(acStack_40c,"%s %s %s, %s",uVar10,uVar11,uVar9,uVar8);

            uStack_4 = 0xffffffff;

            if (((local_4a4 & 1) != 0) && (puStack_490 != auStack_48c)) {

              free(puStack_490);

            }

          }

          else {

            uVar11 = FUN_007a6de0("is that correct?",0xffffffff);

            uVar8 = FUN_007a6de0("the nearest repair station",0xffffffff);

            uVar9 = FUN_007a6de0("INC will pick you up and drop you off at",0xffffffff);

            sprintf(acStack_40c,"%s %s, %s",uVar9,uVar8,uVar11);

          }

          FUN_007fdfb0(&DAT_00d1a840,acStack_40c,0x4e23,1,0);

          ExceptionList = local_c;

          return 1;

        }

        uVar10 = 0;

        uVar9 = 1;

        uVar8 = 0xffffffff;

        uVar11 = FUN_007a6de0("INC cannot drop you off at a location you have not been to yet!",

                              0xffffffff);

        FUN_007fdfb0(&DAT_00d1a840,uVar11,uVar8,uVar9,uVar10);

      }

      ExceptionList = local_c;

      return 1;

    }

  }

  uVar11 = FUN_0087b500(param_2,param_3);

  ExceptionList = local_c;

  return uVar11;

}
