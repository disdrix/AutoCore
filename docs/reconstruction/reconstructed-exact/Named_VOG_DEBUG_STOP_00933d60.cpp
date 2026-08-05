// READABILITY (auto CF):
//  - Body size: ~283 non-empty decompiler lines.
//  - Control keywords: if×29, while×6, for×5, do×4, return×1.
//  - Notable callees: FUN_004022a0×8, FUN_007a4480×8, FUN_004294f0×4, LeaveCriticalSection×4, Character_GetTechForPoolCalcs, FUN_004c4070, FUN_004c4140, FUN_004c41c0.
//  - Strings: "HashError:TraversalLock, already locked for traversal"; "VOG_DEBUG_STOP"; "HashError:TraverseToNext, not locked for traversal".
//  - Return sites: 1.

// =============================================================================
// Named_VOG_DEBUG_STOP_00933d60
// -----------------------------------------------------------------------------
// Stable ID: aa_00933d60
// Address:   0x00933d60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "VOG_DEBUG_STOP"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */



void __fastcall

Named_VOG_DEBUG_STOP_00933d60(uint32_t /* width from decompiler */ param_1,int param_2,int param_3,char *param_4,uint32_t /* width from decompiler */ param_5)



{

  void *pCharacter;

  int iVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int iVar4;

  int *piVar5;

  int local_2d1c;

  int *local_2d18;

  uint32_t /* width from decompiler */ uStack_2d14;

  uint32_t /* width from decompiler */ local_2d10 [4];

  uint32_t /* width from decompiler */ uStack_2d00;

  uint32_t /* width from decompiler */ uStack_2cfc;

  uint32_t /* width from decompiler */ auStack_2cf8 [32];

  uint32_t /* width from decompiler */ auStack_2c78 [32];

  uint8_t uStack_2bf8;

  uint8_t uStack_2bf7;

  int iStack_2bf4;

  int iStack_2bf0;

  int iStack_2bec;

  int iStack_2be8;

  int iStack_2be4;

  uint32_t /* width from decompiler */ uStack_2be0;

  uint32_t /* width from decompiler */ uStack_2bdc;

  uint32_t /* width from decompiler */ uStack_2bd8;

  uint32_t /* width from decompiler */ local_2bd0;

  uint32_t /* width from decompiler */ local_2bcc;

  int local_2bc8 [624];

  int local_2208 [624];

  int aiStack_1848 [624];

  int aiStack_e88 [624];

  uint32_t /* width from decompiler */ uStack_4c8;

  uint32_t /* width from decompiler */ uStack_4c4;

  uint32_t /* width from decompiler */ uStack_4c0;

  uint32_t /* width from decompiler */ uStack_4bc;

  uint32_t /* width from decompiler */ uStack_4b8;

  uint32_t /* width from decompiler */ uStack_4b4;

  uint32_t /* width from decompiler */ uStack_4b0;

  uint16_t uStack_4ac;

  uint16_t uStack_4aa;

  uint16_t uStack_4a8;

  uint16_t uStack_4a6;

  uint32_t /* width from decompiler */ uStack_4a0;

  uint32_t /* width from decompiler */ uStack_49c;

  int aiStack_498 [64];

  uint8_t local_398;

  uint32_t /* width from decompiler */ uStack_390;

  uint32_t /* width from decompiler */ uStack_38c;

  uint32_t /* width from decompiler */ auStack_288 [32];

  char acStack_208 [508];

  uint32_t /* width from decompiler */ uStack_c;

  

  uStack_c = 0x933d70;

  pCharacter = *(void **)(param_3 + 0xe98);

  if (pCharacter != (void *)0x0) {

    local_2d18 = (int *)0x0;

    puVar3 = local_2d10;

    for (iVar4 = 0xb42; iVar4 != 0; iVar4 = iVar4 + -1) {

      *puVar3 = 0;

      puVar3 = puVar3 + 1;

    }

    if (param_2 == 0) {

      local_2d10[0] = 0x2094;

    }

    else if (param_2 == 1) {

      local_2d10[0] = 0x2095;

    }

    else if (param_2 == 2) {

      local_2d10[0] = 0x2096;

    }

    local_2d10[1] = param_5;

    local_398 = *(uint8_t *)((int)pCharacter + 0xce4);

    iVar4 = *(int *)(*(int *)((int)pCharacter + 4) + 4);

    local_2d10[2] = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x164 + (int)pCharacter);

    local_2d10[3] = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x168 + (int)pCharacter);

    iVar4 = *(int *)((int)pCharacter + 0xcb0);

    if (iVar4 == 0) {

      local_2bd0 = 0xffffffff;

      local_2bcc = 0xffffffff;

    }

    else {

      local_2bd0 = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x160);

      local_2bcc = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x164);

    }

    iVar4 = *(int *)(*(int *)((int)pCharacter + 0x250) + 0x2b0);

    local_2d1c = 0;

    FUN_004294f0();

    iVar1 = FUN_004022a0(&local_2d1c,&local_2d18);

    if (iVar1 == 0) {

      piVar5 = local_2208;

      do {

        if (local_2d18 != (int *)0x0) {

          piVar5[-0x270] = local_2d18[0x58];

          piVar5[-0x26f] = local_2d18[0x59];

          iVar1 = (**(code **)(*local_2d18 + 0x25c))();

          *piVar5 = iVar1;

          piVar5[1] = iVar1 >> 0x1f;

          piVar5 = piVar5 + 2;

        }

        iVar1 = FUN_004022a0(&local_2d1c,&local_2d18);

      } while (iVar1 == 0);

    }

    if (*(char *)(iVar4 + 0x54) != '\0') {

      *(uint8_t *)(iVar4 + 0x54) = 0;

      LeaveCriticalSection((LPCRITICAL_SECTION)(iVar4 + 0x30));

    }

    local_2d1c = 0;

    iVar4 = *(int *)(*(int *)(param_3 + 0xe98) + 0xcbc);

    FUN_004294f0();

    iVar1 = FUN_004022a0(&local_2d1c,&local_2d18);

    if (iVar1 == 0) {

      piVar5 = aiStack_e88;

      do {

        if (local_2d18 != (int *)0x0) {

          piVar5[-0x270] = local_2d18[0x58];

          piVar5[-0x26f] = local_2d18[0x59];

          iVar1 = (**(code **)(*local_2d18 + 0x25c))();

          *piVar5 = iVar1;

          piVar5[1] = iVar1 >> 0x1f;

          piVar5 = piVar5 + 2;

        }

        iVar1 = FUN_004022a0(&local_2d1c,&local_2d18);

      } while (iVar1 == 0);

    }

    if (*(char *)(iVar4 + 0x54) != '\0') {

      *(uint8_t *)(iVar4 + 0x54) = 0;

      LeaveCriticalSection((LPCRITICAL_SECTION)(iVar4 + 0x30));

    }

    iVar4 = *(int *)(*(int *)(*(int *)((int)pCharacter + 4) + 4) + 0xa4 + (int)pCharacter);

    iVar1 = 0;

    if (iVar4 == 0) {

      uStack_2d00 = 0xffffffff;

      uStack_2cfc = 0xffffffff;

    }

    else {

      uStack_2d00 = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x160);

      uStack_2cfc = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x164);

    }

    uStack_4a0 = *(uint32_t /* width from decompiler */ *)((int)pCharacter + 0xcd8);

    uStack_49c = *(uint32_t /* width from decompiler */ *)((int)pCharacter + 0xcdc);

    iStack_2bf0 = *(uint *)((int)pCharacter + 0x720) - *(uint *)((int)pCharacter + 0x728);

    iStack_2bec = (*(int *)((int)pCharacter + 0x724) - *(int *)((int)pCharacter + 0x72c)) -

                  (uint)(*(uint *)((int)pCharacter + 0x720) < *(uint *)((int)pCharacter + 0x728));

    iStack_2be8 = *(int *)((int)pCharacter + 0x730);

    iStack_2be4 = iStack_2be8 >> 0x1f;

    if ((*(int *)(param_3 + 0xe98) != 0) &&

       (iVar4 = *(int *)(*(int *)(*(int *)(*(int *)(param_3 + 0xe98) + 4) + 4) + 0xb4 +

                        *(int *)(param_3 + 0xe98)), iVar4 != 0)) {

      local_2d1c = 0;

      uStack_2d14 = 0;

      FUN_004294f0();

      iVar2 = FUN_004022a0(&uStack_2d14,&local_2d1c);

      while (iVar2 == 0) {

        if ((*(int *)(local_2d1c + 0x1c) == 1) && (iVar1 < 0x20)) {

          iVar2 = __RTDynamicCast(local_2d1c,0,&CVOGHBBase::RTTI_Type_Descriptor,

                                  &CVOGHBSkillBase::RTTI_Type_Descriptor,0);

          auStack_288[iVar1] = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x620);

          iVar1 = iVar1 + 1;

        }

        iVar2 = FUN_004022a0(&uStack_2d14,&local_2d1c);

      }

      if (*(char *)(iVar4 + 0x28) != '\0') {

        *(uint8_t *)(iVar4 + 0x28) = 0;

        LeaveCriticalSection((LPCRITICAL_SECTION)(iVar4 + 4));

      }

    }

    uStack_4aa = FUN_004c4070();

    uStack_4a6 = FUN_004c41c0();

    iVar4 = Character_GetTechForPoolCalcs(pCharacter);

    uStack_4ac = (uint16_t)iVar4;

    uStack_4a8 = FUN_004c4140();

    iStack_2bf4 = (int)*(short *)((int)pCharacter + 0x6ce);

    iVar4 = *(int *)((int)pCharacter + 0x540);

    iVar1 = 0;

    local_2d1c = 0;

    if (*(char *)(iVar4 + 0x1d) != '\0') {

      FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    *(uint8_t *)(iVar4 + 0x1d) = 1;

    while( true ) {

      iVar4 = *(int *)((int)pCharacter + 0x540);

      if (*(char *)(iVar4 + 0x1d) == '\0') {

        FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

        FUN_007a4480(0,"VOG_DEBUG_STOP");

      }

      if (iVar1 == 0) {

        iVar1 = *(int *)(iVar4 + 0x14);

      }

      else {

        iVar1 = *(int *)(iVar1 + 0x14);

      }

      if (iVar1 == 0) {

        puVar3 = (uint32_t /* width from decompiler */ *)0x0;

      }

      else {

        puVar3 = *(uint32_t /* width from decompiler */ **)(iVar1 + 8);

      }

      if ((puVar3 == (uint32_t /* width from decompiler */ *)0x0) || (0x1f < local_2d1c)) break;

      auStack_2cf8[local_2d1c] = *puVar3;

      local_2d1c = local_2d1c + 1;

    }

    *(uint8_t *)(*(int *)((int)pCharacter + 0x540) + 0x1d) = 0;

    iVar4 = *(int *)((int)pCharacter + 0x544);

    iVar1 = 0;

    local_2d1c = 0;

    if (*(char *)(iVar4 + 0x1d) != '\0') {

      FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    *(uint8_t *)(iVar4 + 0x1d) = 1;

    do {

      iVar4 = *(int *)((int)pCharacter + 0x544);

      if (*(char *)(iVar4 + 0x1d) == '\0') {

        FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

        FUN_007a4480(0,"VOG_DEBUG_STOP");

      }

      if (iVar1 == 0) {

        iVar1 = *(int *)(iVar4 + 0x14);

      }

      else {

        iVar1 = *(int *)(iVar1 + 0x14);

      }

      if (iVar1 == 0) {

        puVar3 = (uint32_t /* width from decompiler */ *)0x0;

      }

      else {

        puVar3 = *(uint32_t /* width from decompiler */ **)(iVar1 + 8);

      }

      if (puVar3 == (uint32_t /* width from decompiler */ *)0x0) break;

      auStack_2c78[local_2d1c] = *puVar3;

      local_2d1c = local_2d1c + 1;

    } while (local_2d1c < 0x20);

    *(uint8_t *)(*(int *)((int)pCharacter + 0x544) + 0x1d) = 0;

    uStack_2bd8 = *(uint32_t /* width from decompiler */ *)((int)pCharacter + 0x744);

    uStack_2bdc = *(uint32_t /* width from decompiler */ *)((int)pCharacter + 0x740);

    uStack_2be0 = *(uint32_t /* width from decompiler */ *)((int)pCharacter + 0x73c);

    iVar4 = *(int *)(*(int *)(param_3 + 0xe98) + 0xce0);

    local_2d1c = 0;

    FUN_004294f0();

    iVar1 = FUN_004022a0(&local_2d1c,&local_2d18);

    if (iVar1 == 0) {

      piVar5 = aiStack_498;

      do {

        if (local_2d18 != (int *)0x0) {

          *piVar5 = local_2d18[0x58];

          piVar5[1] = local_2d18[0x59];

          piVar5 = piVar5 + 2;

        }

        iVar1 = FUN_004022a0(&local_2d1c,&local_2d18);

      } while (iVar1 == 0);

    }

    if (*(char *)(iVar4 + 0x54) != '\0') {

      *(uint8_t *)(iVar4 + 0x54) = 0;

      LeaveCriticalSection((LPCRITICAL_SECTION)(iVar4 + 0x30));

    }

    uStack_390 = *(uint32_t /* width from decompiler */ *)((int)pCharacter + 0xce8);

    uStack_38c = *(uint32_t /* width from decompiler */ *)((int)pCharacter + 0xcec);

    puVar3 = (uint32_t /* width from decompiler */ *)

             (**(code **)(*(int *)(*(int *)(*(int *)((int)pCharacter + 4) + 4) + 4 + (int)pCharacter

                                  ) + 0x1a4))();

    uStack_4bc = *puVar3;

    uStack_4b8 = puVar3[1];

    uStack_4b4 = puVar3[2];

    uStack_4b0 = puVar3[3];

    puVar3 = (uint32_t /* width from decompiler */ *)

             (**(code **)(*(int *)(*(int *)(*(int *)((int)pCharacter + 4) + 4) + 4 + (int)pCharacter

                                  ) + 0x1a0))();

    uStack_4c8 = *puVar3;

    uStack_4c4 = puVar3[1];

    uStack_4c0 = puVar3[2];

    uStack_2bf8 = (**(code **)(*(int *)(*(int *)(*(int *)((int)pCharacter + 4) + 4) + 4 +

                                       (int)pCharacter) + 0x27c))();

    uStack_2bf7 = *(uint8_t *)((int)pCharacter + 0x6cc);

    strncpy(acStack_208,param_4,0x1ff);

    if (*(int *)(param_3 + 0xc78) != 0) {

      (**(code **)(**(int **)(param_3 + 0xc78) + 0x18))(0xffffffff,local_2d10,0x2d08,0);

    }

  }

  return;

}
