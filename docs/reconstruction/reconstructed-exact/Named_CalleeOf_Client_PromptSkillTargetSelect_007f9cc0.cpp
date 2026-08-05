// =============================================================================
// Named_CalleeOf_Client_PromptSkillTargetSelect_007f9cc0
// -----------------------------------------------------------------------------
// Stable ID: aa_007f9cc0
// Callee of Client_PromptSkillTargetSelect
// Address:   0x007f9cc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_PromptSkillTargetSelect: skill/cast helper. Evidence string: "Failed to access level 0 surface of icon #%d.\n". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "Failed to access level 0 surface of icon #%d.\n"
//   - "Failed to set cursorproperties with surface of icon #%d.\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~54 non-empty decompiler lines.
//  - Control keywords: if×9, return×5.
//  - Notable callees: FUN_007a4480×2, FUN_007f9cc0.
//  - Strings: "Failed to access level 0 surface of icon #%d.\n"; "Failed to set cursorproperties with surface of icon #%d.\n".
//  - Return sites: 5.

/*
 * Behavioral notes:
 * Callee of Client_PromptSkillTargetSelect
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

void __fastcall Named_CalleeOf_Client_PromptSkillTargetSelect_007f9cc0(int *param_1)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int *piVar4;

  int unaff_ESI;

  int *unaff_EDI;

  int *local_4;

  

  if ((-1 < unaff_ESI) && (unaff_ESI < 8)) {

    param_1[0x13c] = unaff_ESI;

    local_4 = param_1;

    if (*(char *)((int)param_1 + 0x489) == '\0') {

      param_1[0xa5] = param_1[unaff_ESI + 0x13d];

      *(uint8_t *)((int)param_1 + 0xbb) = 0;

      (**(code **)(*param_1 + 0x34c))();

      return;

    }

    if (DAT_00d1b213 == '\0') {

      piVar4 = (int *)param_1[unaff_ESI + 0x13d];

      iVar3 = unaff_ESI * 2 + 0x129;

    }

    else {

      piVar4 = (int *)param_1[unaff_ESI + 0x145];

      iVar3 = unaff_ESI * 2 + 0x150;

    }

    iVar1 = (param_1 + iVar3)[1];

    iVar3 = param_1[iVar3];

    if (piVar4 == (int *)0x0) {

      (**(code **)(*param_1 + 4))(0);

      return;

    }

    if (((DAT_00d1b6d8 != 0) && (DAT_00d1b213 != '\0')) && ((unaff_ESI == 0 || (unaff_ESI == 7)))) {

      param_1[0x160] = -1;

    }

    iVar2 = (**(code **)(**(int **)(*piVar4 + 0x10) + 0x48))(*(int **)(*piVar4 + 0x10),0,&local_4);

    if (iVar2 < 0) {

      FUN_007a4480(0,"Failed to access level 0 surface of icon #%d.\n");

      return;

    }

    iVar3 = (**(code **)(*(int *)*DAT_00d1f044 + 0x28))((int *)*DAT_00d1f044,iVar3,iVar1);

    if (iVar3 < 0) {

      FUN_007a4480(0,"Failed to set cursorproperties with surface of icon #%d.\n");

      if (unaff_EDI != (int *)0x0) {

        (**(code **)(*unaff_EDI + 8))(unaff_EDI);

        return;

      }

    }

    else if (unaff_EDI != (int *)0x0) {

      (**(code **)(*unaff_EDI + 8))(unaff_EDI);

    }

  }

  return;

}
