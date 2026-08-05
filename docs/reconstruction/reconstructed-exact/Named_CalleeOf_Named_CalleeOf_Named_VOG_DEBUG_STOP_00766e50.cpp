// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_00766e50
// -----------------------------------------------------------------------------
// Stable ID: aa_00766e50
// Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
// Address:   0x00766e50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×6, return×2, while×1, goto×1.
//  - Notable callees: FUN_00766e50.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
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

int __thiscall Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_00766e50(int *param_1,int param_2,int param_3)



{

  bool bVar1;

  int iVar2;

  char cVar3;

  int iVar4;

  char unaff_BL;

  int iVar5;

  

  bVar1 = false;

  iVar5 = 0;

  cVar3 = (**(code **)(*param_1 + 0x10))();

  iVar2 = param_2;

  if (cVar3 == '\0') {

    param_3 = param_3 + -1;

    while (iVar5 < param_3) {

      iVar4 = (**(code **)(*param_1 + 0x14))(&param_2,1);

      if (iVar4 < 0) goto LAB_00766ec8;

      if (unaff_BL == '\n') break;

      if (bVar1) {

        (**(code **)(*param_1 + 4))(0xffffffff,1);

        break;

      }

      if (unaff_BL == '\r') {

        bVar1 = true;

      }

      else {

        *(char *)(iVar5 + iVar2) = unaff_BL;

        iVar5 = iVar5 + 1;

      }

      cVar3 = (**(code **)(*param_1 + 0x10))();

      if (cVar3 != '\0') {

        *(uint8_t *)(iVar5 + iVar2) = 0;

        return 0;

      }

    }

  }

  iVar4 = 0;

LAB_00766ec8:

  *(uint8_t *)(iVar5 + iVar2) = 0;

  return iVar4;

}
