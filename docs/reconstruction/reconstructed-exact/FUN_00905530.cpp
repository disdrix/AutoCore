// =============================================================================
// FUN_00905530
// -----------------------------------------------------------------------------
// Stable ID: aa_00905530
// Address:   0x00905530  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00905530 @ 0x00905530
// Stable ID: aa_00905530
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~83 non-empty decompiler lines.
//  - Control keywords: if×19, do×1, while×1, return×1.
//  - Notable callees: FUN_00902c40, FUN_00904d50, FUN_00905530, FUN_00907910, GetTickCount.
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

void FUN_00905530(uint param_1,uint param_2)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int in_EAX;

  uint uVar4;

  DWORD DVar5;

  uint uVar6;

  int iVar7;

  

  iVar3 = DAT_00d1ad2c;

  if ((param_1 & param_2) == 0xffffffff) {

    FUN_00902c40();

  }

  iVar7 = 0;

  if (0 < *(int *)(in_EAX + 0x524)) {

    do {

      iVar1 = *(int *)(iVar3 + 0x18);

      if (iVar1 == 0) {

        uVar4 = 0;

      }

      else {

        uVar4 = *(int *)(iVar3 + 0x1c) - iVar1 >> 2;

      }

      uVar6 = *(int *)(in_EAX + 0x530) + iVar7;

      if (uVar6 < uVar4) {

        if (((param_1 & param_2) == 0xffffffff) ||

           ((iVar2 = *(int *)(iVar1 + uVar6 * 4), *(uint *)(iVar2 + 0x1f0) == param_1 &&

            (*(uint *)(iVar2 + 500) == param_2)))) {

          FUN_00904d50(in_EAX,*(uint32_t /* width from decompiler */ *)(iVar1 + uVar6 * 4));

        }

      }

      else {

        if (*(int *)(*(int *)(in_EAX + 0x538) + iVar7 * 4) != 0) {

          (**(code **)(**(int **)(*(int *)(in_EAX + 0x538) + iVar7 * 4) + 4))(0);

        }

        if (*(int *)(*(int *)(in_EAX + 0x53c) + iVar7 * 4) != 0) {

          (**(code **)(**(int **)(*(int *)(in_EAX + 0x53c) + iVar7 * 4) + 4))(0);

        }

        if (*(int *)(*(int *)(in_EAX + 0x540) + iVar7 * 4) != 0) {

          (**(code **)(**(int **)(*(int *)(in_EAX + 0x540) + iVar7 * 4) + 4))(0);

        }

        if (*(int *)(*(int *)(in_EAX + 0x544) + iVar7 * 4) != 0) {

          (**(code **)(**(int **)(*(int *)(in_EAX + 0x544) + iVar7 * 4) + 4))(0);

        }

        if (*(int *)(*(int *)(in_EAX + 0x548) + iVar7 * 4) != 0) {

          (**(code **)(**(int **)(*(int *)(in_EAX + 0x548) + iVar7 * 4) + 4))(0);

        }

        if (*(int *)(*(int *)(in_EAX + 0x550) + iVar7 * 4) != 0) {

          (**(code **)(**(int **)(*(int *)(in_EAX + 0x550) + iVar7 * 4) + 4))(0);

        }

        if (*(int *)(*(int *)(in_EAX + 0x554) + iVar7 * 4) != 0) {

          (**(code **)(**(int **)(*(int *)(in_EAX + 0x554) + iVar7 * 4) + 4))(0);

        }

        if (*(int *)(*(int *)(in_EAX + 0x558) + iVar7 * 4) != 0) {

          (**(code **)(**(int **)(*(int *)(in_EAX + 0x558) + iVar7 * 4) + 4))(0);

        }

        if (*(int *)(*(int *)(in_EAX + 0x54c) + iVar7 * 4) != 0) {

          (**(code **)(**(int **)(*(int *)(in_EAX + 0x54c) + iVar7 * 4) + 4))(0);

        }

        if (*(int *)(*(int *)(in_EAX + 0x560) + iVar7 * 4) != 0) {

          (**(code **)(**(int **)(*(int *)(in_EAX + 0x560) + iVar7 * 4) + 4))(0);

        }

        if (*(int *)(*(int *)(in_EAX + 0x564) + iVar7 * 4) != 0) {

          (**(code **)(**(int **)(*(int *)(in_EAX + 0x564) + iVar7 * 4) + 4))(0);

        }

        if (*(int *)(*(int *)(in_EAX + 0x568) + iVar7 * 4) != 0) {

          (**(code **)(**(int **)(*(int *)(in_EAX + 0x568) + iVar7 * 4) + 4))(0);

        }

        if (*(int *)(*(int *)(in_EAX + 0x56c) + iVar7 * 4) != 0) {

          (**(code **)(**(int **)(*(int *)(in_EAX + 0x56c) + iVar7 * 4) + 4))(0);

        }

      }

      iVar7 = iVar7 + 1;

    } while (iVar7 < *(int *)(in_EAX + 0x524));

  }

  iVar3 = *(int *)(in_EAX + 0x50c);

  DVar5 = GetTickCount();

  if (3999 < DVar5 - *(int *)(iVar3 + 0x510)) {

    FUN_00907910(0);

  }

  return;

}
