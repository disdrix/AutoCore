// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RefreshOpen_00513580
// -----------------------------------------------------------------------------
// Stable ID: aa_00513580
// Callee of Named_CalleeOf_Named_CalleeOf_Client_RefreshOpenMissionUiWindow
// Address:   0x00513580  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Client_RefreshOpenMissionUiWindow: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~78 non-empty decompiler lines.
//  - Control keywords: if×8, goto×5, return×2, do×1, switch×1, while×1.
//  - Notable callees: FUN_00508ac0×2, FUN_00508b10×2, FUN_00508b60×2, FUN_00508bb0×2, FUN_00508c00×2, FUN_00508c50×2, FUN_004ce940, FUN_00513580.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Client_RefreshOpenMissionUiWindow
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

int __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RefreshOpen_00513580(int *param_1)



{

  uint16_t uVar1;

  int iVar2;

  uint uVar3;

  int iVar4;

  uint uVar5;

  

  iVar4 = 0;

  iVar2 = FUN_004ce940();

  if (iVar2 == 0) {

    return 0;

  }

  uVar5 = 0;

  iVar2 = (**(code **)(*param_1 + 0x60))();

  if (iVar2 != 0) {

    do {

      switch(*(uint32_t /* width from decompiler */ *)(param_1[0x2a] + 0x38)) {

      case 10:

        uVar1 = (**(code **)(*param_1 + 0x5c))(uVar5);

        iVar2 = FUN_00508b60(uVar1);

        if (iVar2 != 0) {

          uVar1 = (**(code **)(*param_1 + 0x5c))(uVar5);

          iVar2 = FUN_00508b60(uVar1);

LAB_005136ee:

          iVar4 = iVar4 + *(int *)(iVar2 + 0x94);

        }

        break;

      case 0xc:

        uVar1 = (**(code **)(*param_1 + 0x5c))(uVar5);

        iVar2 = FUN_00508ac0(uVar1);

        if (iVar2 != 0) {

          uVar1 = (**(code **)(*param_1 + 0x5c))(uVar5);

          iVar2 = FUN_00508ac0(uVar1);

          goto LAB_005136ee;

        }

        break;

      case 0xe:

        uVar1 = (**(code **)(*param_1 + 0x5c))(uVar5);

        iVar2 = FUN_00508bb0(uVar1);

        if (iVar2 != 0) {

          uVar1 = (**(code **)(*param_1 + 0x5c))(uVar5);

          iVar2 = FUN_00508bb0(uVar1);

          goto LAB_005136ee;

        }

        break;

      case 0x1c:

        uVar1 = (**(code **)(*param_1 + 0x5c))(uVar5);

        iVar2 = FUN_00508b10(uVar1);

        if (iVar2 != 0) {

          uVar1 = (**(code **)(*param_1 + 0x5c))(uVar5);

          iVar2 = FUN_00508b10(uVar1);

          goto LAB_005136ee;

        }

        break;

      case 0x44:

        uVar1 = (**(code **)(*param_1 + 0x5c))(uVar5);

        iVar2 = FUN_00508c50(uVar1);

        if (iVar2 != 0) {

          uVar1 = (**(code **)(*param_1 + 0x5c))(uVar5);

          iVar2 = FUN_00508c50(uVar1);

          goto LAB_005136ee;

        }

        break;

      case 0x46:

        uVar1 = (**(code **)(*param_1 + 0x5c))(uVar5);

        iVar2 = FUN_00508c00(uVar1);

        if (iVar2 != 0) {

          uVar1 = (**(code **)(*param_1 + 0x5c))(uVar5);

          iVar2 = FUN_00508c00(uVar1);

          goto LAB_005136ee;

        }

      }

      uVar5 = uVar5 + 1;

      uVar3 = (**(code **)(*param_1 + 0x60))();

    } while (uVar5 < uVar3);

  }

  return iVar4;

}
