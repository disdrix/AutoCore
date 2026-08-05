// =============================================================================
// FUN_0083d100
// -----------------------------------------------------------------------------
// Stable ID: aa_0083d100
// Address:   0x0083d100  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0083d100 @ 0x0083d100
// Stable ID: aa_0083d100
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~61 non-empty decompiler lines.
//  - Control keywords: if×8, while×2, return×1.
//  - Notable callees: FUN_004022a0×4, FUN_004294f0×2, FUN_0051f3b0×2, FUN_0083cdb0×2, LeaveCriticalSection×2, __RTDynamicCast×2, FUN_0083c7b0, FUN_0083d100.
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

void FUN_0083d100(int *param_1)



{

  int *piVar1;

  char cVar2;

  int iVar3;

  int iVar4;

  uint32_t /* width from decompiler */ uStack_4;

  

  piVar1 = param_1;

  FUN_0083c7b0(param_1);

  if ((DAT_00d1b6d8 != 0) && (cVar2 = (**(code **)(*piVar1 + 0x3d8))(), cVar2 != '\0')) {

    iVar4 = *(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 0xb4 + DAT_00d1b6d8);

    if (iVar4 != 0) {

      param_1 = (int *)0x0;

      uStack_4 = 0;

      FUN_004294f0();

      iVar3 = FUN_004022a0(&uStack_4,&param_1);

      while (iVar3 == 0) {

        if ((((param_1 != (int *)0x0) && (*(int *)((int)param_1 + 0x1c) == 1)) &&

            (iVar3 = __RTDynamicCast(param_1,0,&CVOGHBBase::RTTI_Type_Descriptor,

                                     &CVOGHBSkillBase::RTTI_Type_Descriptor,0), iVar3 != 0)) &&

           (((*(byte *)(iVar3 + 0x639) & 1) == 0 &&

            (cVar2 = FUN_0051f3b0(*(uint32_t /* width from decompiler */ *)(iVar3 + 0x620)), cVar2 == '\0')))) {

          FUN_0083cdb0(piVar1,iVar3,0);

        }

        iVar3 = FUN_004022a0(&uStack_4,&param_1);

      }

      if (*(char *)(iVar4 + 0x28) != '\0') {

        *(uint8_t *)(iVar4 + 0x28) = 0;

        LeaveCriticalSection((LPCRITICAL_SECTION)(iVar4 + 4));

      }

    }

    iVar4 = *(int *)(DAT_00d1b6d8 + 0x250);

    if ((iVar4 == 0) || (*(char *)(DAT_00d1b6d8 + 0x30c) == '\0')) {

      iVar4 = 0;

    }

    else {

      iVar4 = *(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 0xb4 + iVar4);

    }

    if (iVar4 != 0) {

      param_1 = (int *)0x0;

      uStack_4 = 0;

      FUN_004294f0();

      iVar3 = FUN_004022a0(&uStack_4,&param_1);

      while (iVar3 == 0) {

        if ((((param_1 != (int *)0x0) && (*(int *)((int)param_1 + 0x1c) == 1)) &&

            (iVar3 = __RTDynamicCast(param_1,0,&CVOGHBBase::RTTI_Type_Descriptor,

                                     &CVOGHBSkillBase::RTTI_Type_Descriptor,0), iVar3 != 0)) &&

           (((*(byte *)(iVar3 + 0x639) & 1) == 0 &&

            (cVar2 = FUN_0051f3b0(*(uint32_t /* width from decompiler */ *)(iVar3 + 0x620)), cVar2 == '\0')))) {

          FUN_0083cdb0(piVar1,iVar3,0);

        }

        iVar3 = FUN_004022a0(&uStack_4,&param_1);

      }

      if (*(char *)(iVar4 + 0x28) != '\0') {

        *(uint8_t *)(iVar4 + 0x28) = 0;

        LeaveCriticalSection((LPCRITICAL_SECTION)(iVar4 + 4));

      }

    }

  }

  return;

}
