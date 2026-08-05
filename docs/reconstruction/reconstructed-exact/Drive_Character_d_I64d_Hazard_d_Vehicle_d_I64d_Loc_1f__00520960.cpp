// READABILITY (auto CF):
//  - Body size: ~51 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: d×3, _snprintf×2, FUN_00520960.
//  - Strings: "Target: %d (%I64d) Loc: %.1f,%.1f,%.1f \r\n".
//  - Return sites: 1.

// =============================================================================
// Drive_Character_d_I64d_Hazard_d_Vehicle_d_I64d_Loc_1f__00520960
// -----------------------------------------------------------------------------
// Stable ID: aa_00520960
// Address:   0x00520960  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "Character: %d (%I64d) Hazard: %d Vehicle: %d (%I64d), Loc: %.1f,%.1f,%.1f 

"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall

Drive_Character_d_I64d_Hazard_d_Vehicle_d_I64d_Loc_1f__00520960(int param_1,

            basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_2)



{

  int iVar1;

  int *piVar2;

  int iVar3;

  int iVar4;

  float *pfVar5;

  int iVar6;

  int iVar7;

  char acStack_408 [1028];

  

  iVar1 = *(int *)(param_1 + 0x250);

  iVar3 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0x1a0))();

  iVar4 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0x1a0))();

  pfVar5 = (float *)(**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0x1a0

                                ))();

  iVar6 = *(int *)(*(int *)(param_1 + 4) + 4) + param_1;

  iVar7 = *(int *)(*(int *)(iVar1 + 4) + 4);

  _snprintf(acStack_408,0x400,

            "Character: %d (%I64d) Hazard: %d Vehicle: %d (%I64d), Loc: %.1f,%.1f,%.1f \r\n",

            *(uint32_t /* width from decompiler */ *)(*(int *)(iVar6 + 0xac) + 0x34),*(uint32_t /* width from decompiler */ *)(iVar6 + 0x164),

            *(uint32_t /* width from decompiler */ *)(iVar6 + 0x168),(uint)*(byte *)(param_1 + 0x6b9),

            *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 0xac + iVar1) + 0x34),

            *(uint32_t /* width from decompiler */ *)(iVar7 + 0x164 + iVar1),*(uint32_t /* width from decompiler */ *)(iVar7 + 0x168 + iVar1),

            (double)*pfVar5,(double)*(float *)(iVar4 + 4),(double)*(float *)(iVar3 + 8));

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::append

            (param_2,acStack_408);

  piVar2 = *(int **)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa4 + param_1);

  if ((piVar2 != (int *)0x0) && (iVar6 = (**(code **)(*piVar2 + 0x1c8))(), iVar6 != 0)) {

    iVar1 = *(int *)(iVar6 + 8);

    if (iVar1 == 0) {

      iVar7 = *(int *)(*(int *)(iVar6 + 4) + 4) + 0x84 + iVar6;

      iVar3 = *(int *)(*(int *)(iVar6 + 4) + 4) + 0x84 + iVar6;

      pfVar5 = (float *)(*(int *)(*(int *)(iVar6 + 4) + 4) + 0x84 + iVar6);

    }

    else {

      iVar7 = *(int *)(iVar1 + 0x3c) + 0xb0;

      iVar3 = *(int *)(iVar1 + 0x3c) + 0xb0;

      pfVar5 = (float *)(*(int *)(iVar1 + 0x3c) + 0xb0);

    }

    iVar6 = iVar6 + *(int *)(*(int *)(iVar6 + 4) + 4);

    _snprintf(acStack_408,0x400,"Target: %d (%I64d) Loc: %.1f,%.1f,%.1f \r\n",

              *(uint32_t /* width from decompiler */ *)(*(int *)(iVar6 + 0xac) + 0x34),*(uint32_t /* width from decompiler */ *)(iVar6 + 0x164),

              *(uint32_t /* width from decompiler */ *)(iVar6 + 0x168),(double)*pfVar5,(double)*(float *)(iVar3 + 4),

              (double)*(float *)(iVar7 + 8));

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::append

              (param_2,acStack_408);

  }

  return;

}
