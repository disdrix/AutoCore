// =============================================================================
// FUN_0090e3c0
// -----------------------------------------------------------------------------
// Stable ID: aa_0090e3c0
// Address:   0x0090e3c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0090e3c0 @ 0x0090e3c0
// Stable ID: aa_0090e3c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×8, return×1.
//  - Notable callees: FUN_007fb990, FUN_0090e3c0, __RTDynamicCast.
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

void __thiscall FUN_0090e3c0(int param_1,int param_2)



{

  int *piVar1;

  int iVar2;

  int *piVar3;

  char cVar4;

  int iVar5;

  

  if (param_2 != 0) {

    iVar5 = *(int *)(param_1 + 0x758);

    if (iVar5 == param_2) {

      if ((*(int *)(param_1 + 0x4b8) == 0) &&

         (((iVar2 = *(int *)(*(int *)(iVar5 + 0xa8) + 0x38), iVar2 == 1 || (iVar2 == 3)) &&

          (iVar5 = __RTDynamicCast(iVar5,0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,

                                   &CVOGGraphicsBase::RTTI_Type_Descriptor,0),

          *(int *)(iVar5 + 0x1c) != 0)))) {

        FUN_007fb990();

      }

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x758) = 0;

    }

    piVar3 = DAT_00d1b898;

    if (DAT_00d1b898 != (int *)0x0) {

      iVar5 = DAT_00d1b898[0x191];

      if (iVar5 != 0) {

        iVar5 = *(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5;

      }

      if (param_2 == iVar5) {

        piVar1 = DAT_00d1b898 + 0x1b6;

        DAT_00d1b898[0x191] = 0;

        if ((int *)*piVar1 != (int *)0x0) {

          (**(code **)(*(int *)*piVar1 + 0x1d8))(&DAT_00a1419b,1,1);

          (**(code **)(*(int *)piVar3[0x1b6] + 0x34c))();

        }

        cVar4 = (**(code **)(*piVar3 + 0xd0))();

        if (cVar4 != '\0') {

          (**(code **)(*piVar3 + 4))(0);

        }

      }

    }

  }

  return;

}
