// =============================================================================
// FUN_008f7ad0
// -----------------------------------------------------------------------------
// Stable ID: aa_008f7ad0
// Address:   0x008f7ad0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008f7ad0 @ 0x008f7ad0
// Stable ID: aa_008f7ad0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~46 non-empty decompiler lines.
//  - Control keywords: if×8, do×1, while×1, return×1.
//  - Notable callees: FUN_007916e0, FUN_008f7ad0.
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

void __thiscall FUN_008f7ad0(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  char cVar2;

  int iVar3;

  

  FUN_007916e0(param_2);

  if (((char)param_2 != '\0') && (cVar2 = (**(code **)(*param_1 + 0x3d8))(), cVar2 != '\0')) {

    (**(code **)(*param_1 + 0x450))();

    if ((param_1[0x141] != 0) &&

       (cVar2 = (**(code **)(*(int *)param_1[0x141] + 0xd0))(), cVar2 != '\0')) {

      (**(code **)(*(int *)param_1[0x141] + 4))(0);

    }

    if ((param_1[0x14c] != 0) &&

       (cVar2 = (**(code **)(*(int *)param_1[0x14c] + 0xd0))(), cVar2 != '\0')) {

      (**(code **)(*(int *)param_1[0x14c] + 4))(0);

    }

    if ((param_1[0x14b] != 0) &&

       (cVar2 = (**(code **)(*(int *)param_1[0x14b] + 0xd0))(), cVar2 != '\0')) {

      (**(code **)(*(int *)param_1[0x14b] + 4))(0);

    }

    if ((param_1[0x14d] != 0) &&

       (cVar2 = (**(code **)(*(int *)param_1[0x14d] + 0xd0))(), cVar2 != '\0')) {

      (**(code **)(*(int *)param_1[0x14d] + 4))(0);

    }

    if ((param_1[0x142] != 0) &&

       (cVar2 = (**(code **)(*(int *)param_1[0x142] + 0xd0))(), cVar2 != '\0')) {

      (**(code **)(*(int *)param_1[0x142] + 4))(0);

    }

    if ((param_1[0x152] != 0) &&

       (cVar2 = (**(code **)(*(int *)param_1[0x152] + 0xd0))(), cVar2 != '\0')) {

      (**(code **)(*(int *)param_1[0x152] + 4))(0);

    }

    param_1 = param_1 + 0x150;

    iVar3 = 2;

    do {

      iVar1 = *param_1;

      if (((iVar1 != 0) && (*(int *)(iVar1 + 0xe80) != 0)) &&

         (cVar2 = (**(code **)(**(int **)(iVar1 + 0xe80) + 0xd0))(), cVar2 != '\0')) {

        (**(code **)(**(int **)(*param_1 + 0xe80) + 4))(0);

      }

      param_1 = param_1 + 1;

      iVar3 = iVar3 + -1;

    } while (iVar3 != 0);

  }

  return;

}
