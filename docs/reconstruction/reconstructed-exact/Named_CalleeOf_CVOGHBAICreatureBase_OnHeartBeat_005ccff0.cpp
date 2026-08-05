// =============================================================================
// Named_CalleeOf_CVOGHBAICreatureBase_OnHeartBeat_005ccff0
// -----------------------------------------------------------------------------
// Stable ID: aa_005ccff0
// Callee of CVOGHBAICreatureBase_OnHeartBeat
// Address:   0x005ccff0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGHBAICreatureBase_OnHeartBeat: creature/setup helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~79 non-empty decompiler lines.
//  - Control keywords: if×10, return×5, while×1.
//  - Notable callees: FUN_004022a0×2, FUN_005172d0×2, LeaveCriticalSection×2, FUN_004294f0, FUN_004c3c80, FUN_004c8970, FUN_005ccff0, Object_ResolveFromTFID.
//  - Return sites: 5.

/*
 * Behavioral notes:
 * Callee of CVOGHBAICreatureBase_OnHeartBeat
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

void __fastcall Named_CalleeOf_CVOGHBAICreatureBase_OnHeartBeat_005ccff0(int param_1)



{

  int *piVar1;

  char cVar2;

  int *piVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  int iStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  TFID_16 local_10;

  

  iVar4 = *(int *)(param_1 + 100);

  local_10.dwCoidLo = *(uint *)(iVar4 + 0x228);

  local_10.dwCoidHi = *(uint *)(iVar4 + 0x22c);

  local_10._8_4_ = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x230);

  local_10._12_4_ = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x234);

  piVar3 = Object_ResolveFromTFID(&local_10);

  if (piVar3 == (int *)0x0) {

    FUN_004c3c80(0);

    return;

  }

  if ((piVar3[0x28] == 0) ||

     (cVar2 = (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 100) + 4) + 4) + 4 +

                                   *(int *)(param_1 + 100)) + 0x298))(piVar3[0x28]), cVar2 == '\0'))

  {

    iVar4 = *(int *)(param_1 + 100);

    if ((*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 0xa4 + iVar4) != 0) &&

       (iVar4 = (**(code **)(**(int **)(*(int *)(*(int *)(iVar4 + 4) + 4) + 0xa4 + iVar4) + 0x214))

                          (), iVar4 != 0)) {

      iVar4 = *(int *)(param_1 + 100);

      iVar4 = FUN_004c8970(*(uint32_t /* width from decompiler */ *)(iVar4 + 0x228),*(uint32_t /* width from decompiler */ *)(iVar4 + 0x22c),

                           *(uint32_t /* width from decompiler */ *)(iVar4 + 0x230),*(uint32_t /* width from decompiler */ *)(iVar4 + 0x234));

      if (iVar4 != 0) {

        return;

      }

    }

    uStack_14 = 0;

    iVar4 = (**(code **)(*piVar3 + 0x19c))();

    iVar4 = *(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 0xb4 + iVar4);

    FUN_004294f0();

    iVar5 = FUN_004022a0(&uStack_14,&iStack_18);

    while (iVar5 == 0) {

      if (*(int *)(iStack_18 + 0x1c) == 2) {

        iVar6 = __RTDynamicCast(iStack_18,0,&CVOGHBBase::RTTI_Type_Descriptor,

                                &CVOGHBLinkedDeath::RTTI_Type_Descriptor,0);

        iVar5 = *(int *)(iVar6 + 0x24);

        if ((((iVar5 != 0) && (*(char *)(iVar6 + 0x20) == '\0')) &&

            (*(char *)(iVar5 + 0x20) == '\0')) &&

           (((piVar1 = *(int **)(iVar5 + 0x18), piVar1 != (int *)0x0 &&

             (iVar5 = (**(code **)(*piVar1 + 0x214))(), iVar5 != 0)) &&

            (cVar2 = (**(code **)(*piVar1 + 0x298))(piVar3), cVar2 != '\0')))) {

          if (*(char *)(iVar4 + 0x28) != '\0') {

            *(uint8_t *)(iVar4 + 0x28) = 0;

            LeaveCriticalSection((LPCRITICAL_SECTION)(iVar4 + 4));

          }

          iVar4 = (**(code **)(*piVar1 + 0x19c))();

          if (iVar4 != 0) {

            iVar4 = *(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4;

          }

          FUN_005172d0(iVar4);

          return;

        }

      }

      iVar5 = FUN_004022a0(&uStack_14,&iStack_18);

    }

    if (*(char *)(iVar4 + 0x28) != '\0') {

      *(uint8_t *)(iVar4 + 0x28) = 0;

      LeaveCriticalSection((LPCRITICAL_SECTION)(iVar4 + 4));

    }

  }

  else {

    iVar4 = (**(code **)(*(int *)piVar3[0x28] + 0x1c8))();

    if (iVar4 != 0) {

      FUN_005172d0(piVar3[0x28]);

      return;

    }

  }

  return;

}
