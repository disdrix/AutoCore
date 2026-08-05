// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Drive_Your_Vehicle_Name_Is_Invali_008d2840
// -----------------------------------------------------------------------------
// Stable ID: aa_008d2840
// Callee of Named_CalleeOf_Drive_Your_Vehicle_Name_Is_Invalid_Please_Choose
// Address:   0x008d2840  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Drive_Your_Vehicle_Name_Is_Invalid_Please_Choose: drive/input helper. Evidence string: "This character race/class/gender combination is not available, please select another.". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "This character race/class/gender combination is not available, please select another."
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~75 non-empty decompiler lines.
//  - Control keywords: if×5, return×3, while×1.
//  - Notable callees: FUN_008ceab0×3, FUN_008d0b70×3, FUN_007fdfb0, FUN_008d2840, FUN_008d7480, FUN_008d7620, FUN_008d80c0, FUN_0090ed80.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Drive_Your_Vehicle_Name_Is_Invalid_Please_Choose
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

void Named_CalleeOf_Named_CalleeOf_Drive_Your_Vehicle_Name_Is_Invali_008d2840(int param_1,int param_2,int param_3)



{

  int iVar1;

  int iVar2;

  int in_EAX;

  uint32_t /* width from decompiler */ uVar3;

  uint *puVar4;

  

  FUN_008d80c0(in_EAX);

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x7f0) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x844) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x7f4) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x848) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x7f8) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x84c) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x7fc) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x850) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x800) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x854) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x804) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x858) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x808) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x85c) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x5a0) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x594) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x58c) = 0xffffffff;

  if (*(int **)(in_EAX + 0x694) != (int *)0x0) {

    (**(code **)(**(int **)(in_EAX + 0x694) + 0x1d8))(0,1,1);

    (**(code **)(**(int **)(in_EAX + 0x694) + 0x34c))();

  }

  iVar1 = (&DAT_00d09940)[param_2 + (param_1 + (uint)(param_3 != 0) * 3) * 4];

  *(int *)(in_EAX + 0x544) = iVar1;

  if (iVar1 == 0) {

    (**(code **)(**(int **)(in_EAX + 0x558) + 0xd4))(0);

    (**(code **)(**(int **)(in_EAX + 0x558) + 0x34c))();

    FUN_007fdfb0(&DAT_00d1a840,

                 "This character race/class/gender combination is not available, please select another."

                 ,0xffffffff,1,0);

  }

  else {

    FUN_008d7620(&LAB_008ceda0);

    (**(code **)(**(int **)(in_EAX + 0x558) + 0xd4))(1);

    (**(code **)(**(int **)(in_EAX + 0x558) + 0x34c))();

    if (DAT_00b046a8 != DAT_00b046ac) {

      iVar1 = *(int *)(in_EAX + 0x544);

      puVar4 = DAT_00b046a8;

      while ((puVar4[1] !=

              (uint)*(byte *)(*(int *)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 0xac + iVar1) +

                                      0x3c) + 0x531) ||

             (*puVar4 !=

              (uint)*(byte *)(*(int *)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 0xac + iVar1) +

                                      0x3c) + 0x532)))) {

        puVar4 = puVar4 + 0xe;

        if (puVar4 == DAT_00b046ac) {

          FUN_008d0b70();

          FUN_008ceab0();

          return;

        }

      }

      uVar3 = FUN_0090ed80(0,0,0xffffffff,0xffffffff,0,0,0);

      *(uint32_t /* width from decompiler */ *)(in_EAX + 0x548) = uVar3;

      FUN_008d7480(&LAB_008ced70,&LAB_008d2810,0);

      if ((*(int *)(in_EAX + 0x694) != 0) && (iVar1 = *(int *)(in_EAX + 0x548), iVar1 != 0)) {

        iVar2 = **(int **)(in_EAX + 0x694);

        uVar3 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1) + 0x15c))(1,1);

        (**(code **)(iVar2 + 0x1d8))(uVar3);

        FUN_008d0b70();

        FUN_008ceab0();

        return;

      }

    }

  }

  FUN_008d0b70();

  FUN_008ceab0();

  return;

}
