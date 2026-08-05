// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_006c9780
// -----------------------------------------------------------------------------
// Stable ID: aa_006c9780
// Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
// Address:   0x006c9780  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: if×5, do×1, while×1, return×1.
//  - Notable callees: FUN_005b3300, FUN_006c9780.
//  - Return sites: 1.

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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_006c9780(int param_1,int *param_2,int param_3,int param_4)



{

  int *piVar1;

  uint uVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  int iVar5;

  

  piVar1 = (int *)(param_1 + 0xc);

  uVar2 = *(uint *)(param_1 + 0x14) & 0x7fffffff;

  if ((int)uVar2 < param_3) {

    iVar5 = uVar2 * 2;

    if (iVar5 <= param_3) {

      iVar5 = param_3;

    }

    FUN_005b3300(piVar1,iVar5,8);

  }

  iVar5 = 0;

  *(int *)(param_1 + 0x10) = param_3;

  if (0 < param_3) {

    iVar3 = param_4 - (int)param_2;

    do {

      if (*param_2 != 0) {

        *(int *)(*piVar1 + iVar5 * 8) = *param_2;

        if (param_4 == 0) {

          uVar4 = 0;

        }

        else {

          uVar4 = *(uint32_t /* width from decompiler */ *)(iVar3 + (int)param_2);

        }

        *(uint32_t /* width from decompiler */ *)(*piVar1 + 4 + iVar5 * 8) = uVar4;

        *(short *)(*param_2 + 6) = *(short *)(*param_2 + 6) + 1;

      }

      iVar5 = iVar5 + 1;

      param_2 = param_2 + 1;

    } while (iVar5 < param_3);

  }

  return;

}
