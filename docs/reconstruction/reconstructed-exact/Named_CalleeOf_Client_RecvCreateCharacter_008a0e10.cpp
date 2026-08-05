// =============================================================================
// Named_CalleeOf_Client_RecvCreateCharacter_008a0e10
// -----------------------------------------------------------------------------
// Stable ID: aa_008a0e10
// Callee of Client_RecvCreateCharacter
// Address:   0x008a0e10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_RecvCreateCharacter: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×4, do×1, while×1, return×1.
//  - Notable callees: FUN_007fce10, FUN_00826860, FUN_00827670, FUN_008283a0, FUN_008a0e10, QuickBar_ClearActiveSlot_INFERRED.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Client_RecvCreateCharacter
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

void Named_CalleeOf_Client_RecvCreateCharacter_008a0e10(int *param_1)



{

  int iVar1;

  int iVar2;

  char cVar3;

  int *piVar4;

  int iVar5;

  

  cVar3 = (**(code **)(*param_1 + 0x3d8))();

  if ((cVar3 != '\0') && (DAT_00d1b6d8 != 0)) {

    FUN_007fce10(&DAT_00d1a840);

    iVar5 = 0;

    piVar4 = param_1 + 399;

    do {

      iVar1 = iVar5 + param_1[0x143] * 10;

      iVar2 = *(int *)(&DAT_00d1da60 + iVar1 * 0x18);

      if (iVar2 == 1) {

        FUN_00826860(*piVar4);

      }

      else if (iVar2 == 2) {

        FUN_008283a0();

      }

      else if (iVar2 == 5) {

        FUN_00827670(*(uint32_t /* width from decompiler */ *)(&DAT_00d1da68 + iVar1 * 0x18));

      }

      else {

        QuickBar_ClearActiveSlot_INFERRED();

      }

      iVar5 = iVar5 + 1;

      piVar4 = piVar4 + 1;

    } while (iVar5 < 10);

  }

  return;

}
