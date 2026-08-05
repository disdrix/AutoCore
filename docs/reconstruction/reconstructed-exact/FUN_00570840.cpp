// =============================================================================
// FUN_00570840
// -----------------------------------------------------------------------------
// Stable ID: aa_00570840
// Address:   0x00570840  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00570840 @ 0x00570840
// Stable ID: aa_00570840
// SUPERSEDED 2026-07-29 by named clean:
//   docs/reconstruction/reconstructed-exact/InventoryGrid_CanPlace.cpp
// Dual: reviews/A|B_aa_00570840_InventoryGrid_CanPlace.md ; residual a_00570840.md
// Sealed: idx = height*x+y ; pageOK = (y%pageH)+sizeY<=pageH

// READABILITY (auto CF):
//  - Body size: ~57 non-empty decompiler lines.
//  - Control keywords: if×9, return×3, do×2, goto×2, while×2.
//  - Notable callees: CONCAT31, FUN_00570840.
//  - Return sites: 3.

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

uint __thiscall

FUN_00570840(int param_1,byte param_2,byte param_3,byte param_4,byte param_5,uint *param_6)



{

  uint uVar1;

  byte bVar2;

  uint uVar3;

  uint uVar4;

  uint uVar5;

  int iVar6;

  uint uVar7;

  

  if (param_6 != (uint *)0x0) {

    *param_6 = 0xffffffff;

    param_6[1] = 0xffffffff;

  }

  uVar7 = (uint)param_4;

  uVar4 = param_2 + uVar7;

  if ((int)*(uint *)(param_1 + 8) < (int)uVar4) {

    return *(uint *)(param_1 + 8) & 0xffffff00;

  }

  uVar5 = (uint)param_5;

  uVar3 = *(uint *)(param_1 + 0xc);

  uVar1 = uVar5 + param_3;

  if (((int)uVar1 <= (int)uVar3) &&

     (iVar6 = *(int *)(param_1 + 0x1c), uVar3 = (uint)((longlong)(ulonglong)uVar5 / (longlong)iVar6)

     , bVar2 = param_4,

     (int)((int)((longlong)(ulonglong)uVar5 % (longlong)iVar6) + (uint)param_3) <= iVar6)) {

    do {

      if (uVar4 <= uVar7) {

        return CONCAT31((int3)(uVar3 >> 8),1);

      }

      param_4 = param_5;

      if (uVar5 < uVar1) {

        uVar7 = uVar5;

        do {

          iVar6 = *(int *)(param_1 + 0xc) * (uint)bVar2 + uVar7;

          uVar3 = *(uint *)(*(int *)(param_1 + 0x28) + iVar6 * 8);

          uVar7 = *(uint *)(*(int *)(param_1 + 0x28) + 4 + iVar6 * 8);

          if ((uVar3 & uVar7) != 0xffffffff) {

            if (param_6 == (uint *)0x0) goto LAB_00570967;

            if ((*param_6 & param_6[1]) == 0xffffffff) {

              *param_6 = uVar3;

              param_6[1] = uVar7;

            }

            else if ((*param_6 != uVar3) || (param_6[1] != uVar7)) goto LAB_00570967;

          }

          param_4 = param_4 + 1;

          uVar7 = (uint)param_4;

        } while (uVar7 < uVar1);

      }

      uVar3 = (uint)(byte)(bVar2 + 1);

      bVar2 = bVar2 + 1;

      uVar7 = uVar3;

    } while( true );

  }

LAB_00570967:

  return uVar3 & 0xffffff00;

}
