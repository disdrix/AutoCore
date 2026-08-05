// =============================================================================
// FUN_004d0640
// -----------------------------------------------------------------------------
// Stable ID: aa_004d0640
// Address:   0x004d0640  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004d0640 @ 0x004d0640
// Stable ID: aa_004d0640
// Embedded strings (evidence for future rename):
//   - "HashError:TraversalLock, already locked for traversal"
//   - "VOG_DEBUG_STOP"
//   - "HashError:TraverseToNext, not locked for traversal"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~122 non-empty decompiler lines.
//  - Control keywords: if×12, for×2, goto×2, do×1, return×1, while×1.
//  - Notable callees: FUN_007a4480×4, __RTDynamicCast×4, FUN_0079cb60×2, FUN_004d0640, FUN_004e88c0, FUN_00522500, FUN_00797130, FUN_0079c9a0.
//  - Strings: "HashError:TraversalLock, already locked for traversal"; "VOG_DEBUG_STOP"; "HashError:TraverseToNext, not locked for traversal".
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

void __thiscall FUN_004d0640(int param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  int iVar2;

  int *piVar3;

  int unaff_EBP;

  int iVar4;

  int iVar5;

  int local_6d4;

  uint32_t /* width from decompiler */ local_6d0;

  uint32_t /* width from decompiler */ local_6cc;

  int local_6c8 [6];

  undefined **appuStack_6b0 [2];

  undefined **local_6a8;

  char local_6a3;

  void *local_14;

  uint8_t local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a1f7d;

  local_c = ExceptionList;

  local_6d0 = *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xe5c4) + 0xc);

  iVar4 = 0;

  ExceptionList = &local_c;

  local_6d4 = param_1;

  FUN_0079ce60();

  local_6a8 = &PTR_FUN_009cbfd0;

  local_14 = (void *)0x0;

  local_10 = 0;

  local_4 = 0;

  FUN_0079c9a0(param_2);

  if (local_6a3 == '\0') {

    (*(code *)local_6a8[2])(&local_6d0,4);

  }

  else {

    (*(code *)local_6a8[1])();

  }

  iVar5 = *(int *)(param_1 + 0xe5c4);

  if (*(char *)(iVar5 + 0x1d) != '\0') {

    FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  *(uint8_t *)(iVar5 + 0x1d) = 1;

  do {

    iVar5 = *(int *)(param_1 + 0xe5c4);

    if (*(char *)(iVar5 + 0x1d) == '\0') {

      FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    if (iVar4 == 0) {

      iVar4 = *(int *)(iVar5 + 0x14);

    }

    else {

      iVar4 = *(int *)(iVar4 + 0x14);

    }

    if (iVar4 == 0) {

      iVar5 = 0;

    }

    else {

      iVar5 = *(int *)(iVar4 + 8);

    }

    if (iVar5 == 0) {

      *(uint8_t *)(*(int *)(unaff_EBP + 0xe5c4) + 0x1d) = 0;

      FUN_0079cb60();

      appuStack_6b0[0] = &PTR_FUN_009cbfd0;

      local_c = (void *)0x1;

      FUN_0079cb60();

      ExceptionList = local_14;

      return;

    }

    iVar1 = CVOGReaction_ResolveObjectTarget

                      (1,*(uint32_t /* width from decompiler */ *)(iVar5 + 8),*(uint32_t /* width from decompiler */ *)(iVar5 + 0xc));

    if (iVar1 == 0) {

      piVar3 = local_6c8;

      local_6c8[0] = 0;

      local_6c8[1] = 0;

      local_6c8[2] = 0;

    }

    else {

      if ((*(uint *)(iVar1 + 0x17c) >> 5 & 1) != 0) {

        iVar2 = __RTDynamicCast(iVar1,0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,

                                &CVOGPhysicsBase::RTTI_Type_Descriptor,0);

        if (*(int *)(iVar2 + 8) != 0) {

          iVar1 = __RTDynamicCast(iVar1,0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,

                                  &CVOGPhysicsBase::RTTI_Type_Descriptor,0);

          if (*(int *)(iVar1 + 8) == 0) {

            iVar1 = *(int *)(*(int *)(iVar1 + 4) + 4) + 0x84 + iVar1;

          }

          else {

            iVar1 = *(int *)(*(int *)(iVar1 + 8) + 0x3c) + 0xb0;

          }

          FUN_004e88c0(iVar1,local_6c8 + 3);

          piVar3 = local_6c8 + 3;

          goto LAB_004d084f;

        }

      }

      if ((*(uint *)(iVar1 + 0x17c) >> 6 & 1) != 0) {

        iVar2 = __RTDynamicCast(iVar1,0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,

                                &CVOGGraphicsBase::RTTI_Type_Descriptor,0);

        if (*(int *)(iVar2 + 8) != 0) {

          iVar1 = __RTDynamicCast(iVar1,0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,

                                  &CVOGGraphicsBase::RTTI_Type_Descriptor,0);

          iVar1 = (**(code **)(**(int **)(iVar1 + 8) + 0xc))();

          piVar3 = (int *)(iVar1 + 0x90);

          goto LAB_004d084f;

        }

      }

      piVar3 = &local_6d4;

      local_6d4 = 0;

      local_6d0 = 0;

      local_6cc = 0;

    }

LAB_004d084f:

    FUN_00797130(piVar3);

    *(uint32_t /* width from decompiler */ *)(iVar5 + 0x20) = 0xffffffff;

    *(uint32_t /* width from decompiler */ *)(iVar5 + 0x24) = 0xffffffff;

    FUN_00522500(appuStack_6b0,0x3e);

    param_1 = unaff_EBP;

  } while( true );

}
