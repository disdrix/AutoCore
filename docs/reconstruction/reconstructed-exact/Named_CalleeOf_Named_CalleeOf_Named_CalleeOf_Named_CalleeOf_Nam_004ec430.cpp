// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004ec430
// -----------------------------------------------------------------------------
// Stable ID: aa_004ec430
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x004ec430  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper. Evidence string: "CollectAllAnimationPreloads". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "CollectAllAnimationPreloads"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~152 non-empty decompiler lines.
//  - Control keywords: if×10, do×7, while×7, goto×5, return×1.
//  - Notable callees: FUN_007b6730×5, FUN_007b6a20×5, FUN_00989e00×5, FUN_0043d670×4, FUN_004c3320×3, FUN_004ec430, FUN_0076cef0, FUN_0076cf00.
//  - Strings: "CollectAllAnimationPreloads".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004ec430(int param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  char cVar2;

  char *pcVar3;

  int iVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint8_t *puVar6;

  uint32_t /* width from decompiler */ uVar7;

  uint32_t /* width from decompiler */ local_254 [10];

  uint8_t local_22c [4];

  uint32_t /* width from decompiler */ local_228;

  uint8_t local_224 [4];

  uint8_t local_220 [4];

  uint8_t local_21c [4];

  uint8_t local_218 [3];

  uint32_t /* width from decompiler */ uStack_215;

  uint8_t local_210 [256];

  uint8_t local_110 [260];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a2801;

  local_c = ExceptionList;

  local_228 = DAT_00d1f040;

  ExceptionList = &local_c;

  FUN_0076cf00("CollectAllAnimationPreloads");

  pcVar3 = (char *)(param_1 + 0x188);

  local_4 = 0;

  iVar4 = 1 - (int)pcVar3;

  do {

    cVar2 = *pcVar3;

    pcVar3[(int)&uStack_215 + iVar4] = cVar2;

    pcVar3 = pcVar3 + 1;

  } while (cVar2 != '\0');

  iVar4 = *(int *)(param_1 + 0x38);

  if (iVar4 == 0xc) {

    puVar1 = &uStack_215;

    do {

      puVar5 = puVar1;

      puVar1 = (uint32_t /* width from decompiler */ *)((int)puVar5 + 1);

    } while (*(char *)((int)puVar5 + 1) != '\0');

    iVar4 = (int)&uStack_215 + 1;

    *(uint32_t /* width from decompiler */ *)((int)puVar5 + 1) = DAT_009ccd1c;

    uVar7 = 0xffffffff;

    *(uint32_t /* width from decompiler */ *)((int)puVar5 + 5) = DAT_009ccd20;

    FUN_007b6a20(iVar4,0xffffffff);

    cVar2 = FUN_007b6730(iVar4,uVar7);

    if (cVar2 == '\0') goto LAB_004ec77c;

    FUN_00989e00(local_22c,(int)&uStack_215 + 1);

    puVar6 = local_22c;

  }

  else {

    if (iVar4 == 0x12) {

      iVar4 = 0;

      do {

        FUN_004c3320(iVar4,(int)&uStack_215 + 1,local_110);

        puVar6 = local_110;

        uVar7 = 0xffffffff;

        FUN_007b6a20(puVar6,0xffffffff);

        cVar2 = FUN_007b6730(puVar6,uVar7);

        if (cVar2 != '\0') {

          FUN_00989e00(local_224,local_110);

          FUN_0043d670(local_224);

        }

        iVar4 = iVar4 + 1;

      } while (iVar4 < 0x13);

      if (*(int *)(*(int *)(param_1 + 0x3c) + 0x4e8) == 1) {

        puVar1 = &uStack_215;

        do {

          puVar5 = puVar1;

          puVar1 = (uint32_t /* width from decompiler */ *)((int)puVar5 + 1);

        } while (*(char *)((int)puVar5 + 1) != '\0');

        *(uint32_t /* width from decompiler */ *)((int)puVar5 + 1) = DAT_009cbf54;

        *(uint8_t *)((int)puVar5 + 5) = DAT_009cbf58;

        local_254[0] = 3;

        local_254[1] = 4;

        local_254[2] = 0x10;

        local_254[3] = 0x11;

        local_254[4] = 2;

        local_254[5] = 1;

        local_254[6] = 0;

        local_254[7] = 5;

        local_254[8] = 6;

        local_254[9] = 7;

        iVar4 = 9;

        do {

          FUN_004c3320(local_254[iVar4],(int)&uStack_215 + 1,local_110);

          puVar6 = local_110;

          uVar7 = 0xffffffff;

          FUN_007b6a20(puVar6,0xffffffff);

          cVar2 = FUN_007b6730(puVar6,uVar7);

          if (cVar2 != '\0') {

            FUN_00989e00(local_218,local_110);

            FUN_0043d670(local_218);

          }

          iVar4 = iVar4 + -1;

        } while (-1 < iVar4);

      }

      goto LAB_004ec77c;

    }

    if (iVar4 == 0x14) {

      iVar4 = 9;

      local_254[0] = 1;

      local_254[1] = 2;

      local_254[2] = 9;

      local_254[3] = 10;

      local_254[4] = 0xb;

      local_254[5] = 0xc;

      local_254[6] = 0xd;

      local_254[7] = 0xe;

      local_254[8] = 0xf;

      local_254[9] = 0x12;

      do {

        FUN_004c3320(local_254[iVar4],(int)&uStack_215 + 1,local_110);

        puVar6 = local_110;

        uVar7 = 0xffffffff;

        FUN_007b6a20(puVar6,0xffffffff);

        cVar2 = FUN_007b6730(puVar6,uVar7);

        if (cVar2 != '\0') {

          FUN_00989e00(local_220,local_110);

          FUN_0043d670(local_220);

        }

        iVar4 = iVar4 + -1;

      } while (-1 < iVar4);

      goto LAB_004ec77c;

    }

    if ((*(byte *)(*(int *)(param_1 + 0x3c) + 0x3f2) & 4) == 0) goto LAB_004ec77c;

    puVar1 = &uStack_215;

    do {

      puVar5 = puVar1;

      puVar1 = (uint32_t /* width from decompiler */ *)((int)puVar5 + 1);

    } while (*(char *)((int)puVar5 + 1) != '\0');

    iVar4 = (int)&uStack_215 + 1;

    *(uint32_t /* width from decompiler */ *)((int)puVar5 + 1) = DAT_00a30aa0;

    uVar7 = 0xffffffff;

    *(uint32_t /* width from decompiler */ *)((int)puVar5 + 5) = _DAT_00a30aa4;

    FUN_007b6a20(iVar4,0xffffffff);

    cVar2 = FUN_007b6730(iVar4,uVar7);

    if (cVar2 == '\0') goto LAB_004ec77c;

    FUN_00989e00(local_21c,(int)&uStack_215 + 1);

    puVar6 = local_21c;

  }

  FUN_0043d670(puVar6);

LAB_004ec77c:

  local_4 = 0xffffffff;

  FUN_0076cef0();

  ExceptionList = local_c;

  return;

}
