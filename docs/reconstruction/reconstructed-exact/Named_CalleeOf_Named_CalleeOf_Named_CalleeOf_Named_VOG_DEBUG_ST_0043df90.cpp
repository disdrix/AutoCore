// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST_0043df90
// -----------------------------------------------------------------------------
// Stable ID: aa_0043df90
// Callee of Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP
// Address:   0x0043df90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~49 non-empty decompiler lines.
//  - Control keywords: if×7, do×2, while×2, return×1.
//  - Notable callees: FUN_0043df90, FUN_0043ebb0, FUN_0043ec50.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP
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

void __thiscall

Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST_0043df90(int param_1,int *param_2,uint32_t /* width from decompiler */ param_3,int param_4,uint32_t /* width from decompiler */ param_5,int param_6)



{

  int iVar1;

  uint uVar2;

  int iVar3;

  int iVar4;

  

  iVar1 = *(int *)(param_1 + 0xc);

  uVar2 = param_4 - iVar1;

  iVar3 = param_6 - param_4;

  iVar4 = *(int *)(param_1 + 0x10) + iVar1;

  if (uVar2 < (uint)(iVar4 - param_6)) {

    FUN_0043ebb0(&param_3,param_1,iVar1,param_3,param_4,param_5,param_6);

    if (iVar3 != 0) {

      iVar4 = *(int *)(param_1 + 0x10);

      do {

        if (iVar4 != 0) {

          *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;

          if ((uint)(*(int *)(param_1 + 8) * 4) <= *(uint *)(param_1 + 0xc)) {

            *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 0;

          }

          iVar4 = iVar4 + -1;

          if (iVar4 == 0) {

            *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 0;

          }

        }

        iVar3 = iVar3 + -1;

      } while (iVar3 != 0);

      *(int *)(param_1 + 0x10) = iVar4;

    }

  }

  else {

    FUN_0043ec50(&param_3,param_5,param_6,param_1,iVar4,param_3,param_4,param_2);

    if (iVar3 != 0) {

      iVar4 = *(int *)(param_1 + 0x10);

      do {

        if ((iVar4 != 0) && (iVar4 = iVar4 + -1, iVar4 == 0)) {

          *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 0;

        }

        iVar3 = iVar3 + -1;

      } while (iVar3 != 0);

      *(int *)(param_1 + 0x10) = iVar4;

    }

  }

  iVar4 = *(int *)(param_1 + 0xc);

  *param_2 = param_1;

  param_2[1] = iVar4 + uVar2;

  return;

}
