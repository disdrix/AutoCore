// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_0059db80
// -----------------------------------------------------------------------------
// Stable ID: aa_0059db80
// Callee of Named_VOG_DEBUG_STOP (+1 other named callers)
// Address:   0x0059db80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_VOG_DEBUG_STOP (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: if×8, return×4, goto×2, while×2, do×1.
//  - Notable callees: FUN_0059db80.
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of Named_VOG_DEBUG_STOP (+1 other named callers)
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

int __thiscall Named_CalleeOf_Named_VOG_DEBUG_STOP_0059db80(int param_1,int param_2)



{

  int *piVar1;

  char cVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  uint32_t /* width from decompiler */ *puVar6;

  

  iVar4 = *(int *)(param_1 + 0x120);

  if (iVar4 == -1) {

    iVar4 = *(int *)(*(int *)(param_1 + 0x14c) + 0xfc);

  }

  iVar5 = *(int *)(*(int *)(*(int *)(*(int *)(param_2 + 0x55c) + 0x10) +

                           (*(uint *)(*(int *)(param_2 + 0x55c) + 8) & *(uint *)(param_1 + 0x10)) *

                           4) + 4);

  if (iVar5 == 0) {

LAB_0059dbda:

    iVar5 = 0;

  }

  else {

    do {

      if (*(uint *)(param_1 + 0x10) == *(uint *)(iVar5 + 0x10)) {

        if (iVar5 == 0) goto LAB_0059dbda;

        iVar5 = *(int *)(iVar5 + 8);

        goto LAB_0059dbe1;

      }

      iVar5 = *(int *)(iVar5 + 0xc);

    } while (iVar5 != 0);

    iVar5 = 0;

  }

LAB_0059dbe1:

  if (iVar5 == 0) {

    return iVar4;

  }

  puVar6 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x158);

  if (puVar6 != *(uint32_t /* width from decompiler */ **)(param_1 + 0x15c)) {

    while( true ) {

      piVar1 = (int *)*puVar6;

      cVar2 = (**(code **)(*piVar1 + 8))(param_2,iVar5);

      if (((cVar2 == '\0') && (iVar3 = (**(code **)(*piVar1 + 0x58))(), iVar3 != -1)) &&

         (iVar3 != 0)) break;

      puVar6 = puVar6 + 1;

      if (puVar6 == *(uint32_t /* width from decompiler */ **)(param_1 + 0x15c)) {

        return iVar4;

      }

    }

    return iVar3;

  }

  return iVar4;

}
