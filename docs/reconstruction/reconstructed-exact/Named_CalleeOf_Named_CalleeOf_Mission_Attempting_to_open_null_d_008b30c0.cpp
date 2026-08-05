// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Mission_Attempting_to_open_null_d_008b30c0
// -----------------------------------------------------------------------------
// Stable ID: aa_008b30c0
// Callee of Named_CalleeOf_Mission_Attempting_to_open_null_dialog_i
// Address:   0x008b30c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Mission_Attempting_to_open_null_dialog_i: mission/objective helper. Evidence string: "Open the Crafting Window to Assemble This Item". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "CRAFT"
//   - "Open the Crafting Window to Assemble This Item"
//   - "REPLACE"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: if×5, do×1, while×1, return×1.
//  - Notable callees: CONCAT31, FUN_008b30c0.
//  - Strings: "CRAFT"; "Open the Crafting Window to Assemble This Item"; "REPLACE".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Mission_Attempting_to_open_null_dialog_i
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Mission_Attempting_to_open_null_d_008b30c0(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  int in_EAX;

  uint32_t /* width from decompiler */ extraout_EDX;

  uint32_t /* width from decompiler */ extraout_EDX_00;

  uint32_t /* width from decompiler */ *puVar1;

  char cVar2;

  int *piVar3;

  int iVar4;

  uint32_t /* width from decompiler */ uStack_18;

  

  cVar2 = (char)param_3;

  *(char *)(in_EAX + 0x70c) = cVar2;

  if (*(int **)(in_EAX + 0x6fc) != (int *)0x0) {

    uStack_18 = param_3;

    (**(code **)(**(int **)(in_EAX + 0x6fc) + 4))();

    param_2 = extraout_EDX;

  }

  if (*(int **)(in_EAX + 0x564) != (int *)0x0) {

    uStack_18 = param_3;

    (**(code **)(**(int **)(in_EAX + 0x564) + 4))();

    param_2 = extraout_EDX_00;

  }

  if (*(int **)(in_EAX + 0x560) != (int *)0x0) {

    uStack_18 = CONCAT31((int3)((uint)param_2 >> 8),cVar2 == '\0');

    (**(code **)(**(int **)(in_EAX + 0x560) + 4))();

  }

  piVar3 = (int *)(in_EAX + 0x6d8);

  iVar4 = 8;

  do {

    if (*piVar3 != 0) {

      uStack_18 = 1;

      if (cVar2 == '\0') {

        (**(code **)(*(int *)*piVar3 + 0x1d8))("CRAFT",1);

        (**(code **)(*(int *)*piVar3 + 0x308))("Open the Crafting Window to Assemble This Item");

        puVar1 = (uint32_t /* width from decompiler */ *)&stack0xffffffec;

      }

      else {

        (**(code **)(*(int *)*piVar3 + 0x1d8))("REPLACE");

        (**(code **)(*(int *)*piVar3 + 0x308))(&DAT_00a1419b);

        uStack_18 = 0xffff3232;

        puVar1 = &uStack_18;

      }

      (**(code **)(*(int *)*piVar3 + 0x15c))(0,puVar1);

      (**(code **)(*(int *)*piVar3 + 0x34c))();

    }

    piVar3 = piVar3 + 1;

    iVar4 = iVar4 + -1;

  } while (iVar4 != 0);

  return;

}
