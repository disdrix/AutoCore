// READABILITY (auto CF):
//  - Body size: ~72 non-empty decompiler lines.
//  - Control keywords: if×8, for×2, return×2, while×1.
//  - Notable callees: FUN_007a4480×5, FUN_004c4070, FUN_004c41c0, FUN_004c8f00, FUN_004cbdc0, FUN_0051b230, __RTDynamicCast.
//  - Strings: "HashError:TraversalLock, already locked for traversal"; "VOG_DEBUG_STOP"; "HashError:TraverseToNext, not locked for traversal".
//  - Return sites: 2.

// =============================================================================
// Mission_CVOGClonedObjectBase_RTTI_Type_Descriptor
// -----------------------------------------------------------------------------
// Purpose:  String-driven human alias for decompiled bulk unit.
//           Primary evidence: "CVOGClonedObjectBase_RTTI_Type_Descriptor"
//           Named entry point for reconstruction indexing / coverage ledger.
//           Behavior preserved from FUN_004c8f00 clean capture (not modernized).
//
// Address:  0x004c8f00  (autoassault.exe, image base 0x400000)
// Stable:   aa_004c8f00
// Stable ID: aa_004c8f00
// System:   missions-progression
//
// Naming:   From informative string/keyword evidence in
//           docs/reconstruction/raw/aa_004c8f00_*.md
//           Original Ghidra symbol: FUN_004c8f00
//
// Exactness: Body mirrors reconstructed-exact/FUN_004c8f00*.cpp when present.
//            Offsets and control flow are not invented here.
// =============================================================================

// =============================================================================
// Mission_CVOGClonedObjectBase_RTTI_Type_Descriptor
// -----------------------------------------------------------------------------
// Stable ID: aa_004c8f00
// Address:   0x004c8f00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven human alias evidence: "CVOGClonedObjectBase_RTTI_Type_Descriptor"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int __fastcall Mission_CVOGClonedObjectBase_RTTI_Type_Descriptor(int param_1)



{

  uint16_t uVar1;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  

  uVar2 = FUN_0051b230(0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,

                       &CVOGCreature::RTTI_Type_Descriptor,0);

  iVar3 = __RTDynamicCast(uVar2);

  iVar5 = 0;

  if (iVar3 != 0) {

    iVar4 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + -0x4fc + param_1) +

                        0x27c))();

    if (iVar4 < 2) {

      iVar4 = 1;

    }

    *(int *)(iVar3 + 0x150) = iVar4;

    iVar4 = *(int *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3);

    uVar2 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + -0x4fc + param_1) +

                        0x244))();

    (**(code **)(iVar4 + 0x248))(uVar2);

    iVar4 = *(int *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3);

    uVar2 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + -0x4fc + param_1) +

                        0x23c))();

    (**(code **)(iVar4 + 0x240))(uVar2);

    *(uint32_t /* width from decompiler */ *)(iVar3 + 0x128) = *(uint32_t /* width from decompiler */ *)(param_1 + -0x3d8);

    uVar1 = FUN_004c4070();

    *(uint16_t *)(iVar3 + 0x13e) = uVar1;

    uVar1 = FUN_004c41c0();

    *(uint16_t *)(iVar3 + 0x142) = uVar1;

    *(uint8_t *)(iVar3 + 0x100) = *(uint8_t *)(param_1 + -0x400);

    if (*(char *)(param_1 + -0x1f5) != '\0') {

      *(uint8_t *)(iVar3 + 0x30b) = 1;

    }

    FUN_004cbdc0(2);

    iVar4 = *(int *)(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + -0x48c + param_1);

    if (*(char *)(iVar4 + 0x1d) != '\0') {

      FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    *(uint8_t *)(iVar4 + 0x1d) = 1;

    while( true ) {

      iVar4 = *(int *)(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + -0x48c + param_1);

      if (*(char *)(iVar4 + 0x1d) == '\0') {

        FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

        FUN_007a4480(0,"VOG_DEBUG_STOP");

      }

      if (iVar5 == 0) {

        iVar5 = *(int *)(iVar4 + 0x14);

      }

      else {

        iVar5 = *(int *)(iVar5 + 0x14);

      }

      if (iVar5 == 0) {

        iVar4 = 0;

      }

      else {

        iVar4 = *(int *)(iVar5 + 8);

      }

      if (iVar4 == 0) break;

      Skill_EnsureLoadedInTree

                ((void *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3),*(int *)(iVar4 + 0x5fc),

                 *(short *)(iVar4 + 0x5f6));

    }

    *(uint8_t *)(*(int *)(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + -0x48c + param_1) + 0x1d) =

         0;

    return *(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3;

  }

  FUN_007a4480(0,"VOG_DEBUG_STOP");

  return 0;

}
