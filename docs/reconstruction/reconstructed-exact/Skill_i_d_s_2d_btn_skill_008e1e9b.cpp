// READABILITY (auto CF):
//  - Body size: ~49 non-empty decompiler lines.
//  - Control keywords: if×7, do×1, while×1, return×1.
//  - Notable callees: FUN_00792490, FUN_008e1e9b, strstr.
//  - Strings: "i_d_s_2d_btn_skill".
//  - Return sites: 1.

// =============================================================================
// Skill_i_d_s_2d_btn_skill_008e1e9b
// -----------------------------------------------------------------------------
// Stable ID: aa_008e1e9b
// Address:   0x008e1e9b  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "i_d_s_2d_btn_skill"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall Skill_i_d_s_2d_btn_skill_008e1e9b(int *param_1)



{

  char cVar1;

  int *piVar2;

  int in_EAX;

  char *pcVar3;

  char *pcVar4;

  char cVar5;

  int *unaff_EBX;

  bool in_ZF;

  

  cVar5 = (char)unaff_EBX;

  if (((!in_ZF) && (piVar2 = *(int **)(in_EAX + 0x4b4), piVar2 != unaff_EBX)) &&

     ((int *)piVar2[5] != unaff_EBX)) {

    pcVar3 = (char *)(**(code **)(*(int *)piVar2[5] + 0x70))();

    pcVar4 = pcVar3 + 1;

    do {

      cVar1 = *pcVar3;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != cVar5);

    if (pcVar3 != pcVar4) {

      pcVar3 = "i_d_s_2d_btn_skill";

      pcVar4 = (char *)(**(code **)(**(int **)(DAT_00d1b778[0x12d] + 0x14) + 0x70))();

      pcVar4 = strstr(pcVar4,pcVar3);

      if (pcVar4 != (char *)0x0) {

        if (*(int **)(DAT_00d1b778[0x12d] + 0x1c) != unaff_EBX) {

          (**(code **)(*DAT_00d1b778 + 0xb0))(*(int **)(DAT_00d1b778[0x12d] + 0x1c));

          if (*(int **)(DAT_00d1b778[0x12d] + 0x1c) != unaff_EBX) {

            (**(code **)**(int **)(DAT_00d1b778[0x12d] + 0x1c))(1);

          }

          *(int **)(DAT_00d1b778[0x12d] + 0x1c) = unaff_EBX;

        }

        if ((int *)DAT_00d1b778[0x12d] != unaff_EBX) {

          (*(code *)**(uint32_t /* width from decompiler */ **)DAT_00d1b778[0x12d])(1);

        }

        DAT_00d1b778[0x12d] = (int)unaff_EBX;

      }

    }

  }

  DAT_00d1d8f6 = 1;

  DAT_00d1d8f7 = cVar5;

  if (DAT_00d1d8e0 != unaff_EBX) {

    (**(code **)(*DAT_00d1d8e0 + 4))();

    DAT_00d1d8e0[0x145] = (int)unaff_EBX;

    *(char *)(DAT_00d1d8e0 + 0x13f) = cVar5;

  }

  (**(code **)(*param_1 + 0x3ac))();

  FUN_00792490();

  return;

}
