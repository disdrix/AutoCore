// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_assManager_0043c8c0
// -----------------------------------------------------------------------------
// Stable ID: aa_0043c8c0
// Callee of Named_CalleeOf_Named_assManager (+1 other named callers)
// Address:   0x0043c8c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_assManager: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_CalleeOf_Named_assManager (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~46 non-empty decompiler lines.
//  - Control keywords: if×7, do×2, while×2, return×1.
//  - Notable callees: FUN_0043c8c0, FUN_0043d300, FUN_0043d390.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_assManager (+1 other named callers)
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

int * Named_CalleeOf_Named_CalleeOf_Named_assManager_0043c8c0(int *param_1,uint32_t /* width from decompiler */ param_2,int param_3,uint32_t /* width from decompiler */ param_4,int param_5)



{

  int in_EAX;

  uint uVar1;

  int iVar2;

  int iVar3;

  

  uVar1 = param_3 - *(int *)(in_EAX + 0xc);

  iVar2 = param_5 - param_3;

  if (uVar1 < (uint)((*(int *)(in_EAX + 0x10) + *(int *)(in_EAX + 0xc)) - param_5)) {

    FUN_0043d300(&param_2);

    if (iVar2 != 0) {

      iVar3 = *(int *)(in_EAX + 0x10);

      do {

        if (iVar3 != 0) {

          *(int *)(in_EAX + 0xc) = *(int *)(in_EAX + 0xc) + 1;

          if ((uint)(*(int *)(in_EAX + 8) * 4) <= *(uint *)(in_EAX + 0xc)) {

            *(uint32_t /* width from decompiler */ *)(in_EAX + 0xc) = 0;

          }

          iVar3 = iVar3 + -1;

          if (iVar3 == 0) {

            *(uint32_t /* width from decompiler */ *)(in_EAX + 0xc) = 0;

          }

        }

        iVar2 = iVar2 + -1;

      } while (iVar2 != 0);

      *(int *)(in_EAX + 0x10) = iVar3;

    }

  }

  else {

    FUN_0043d390(&param_2,param_4,param_5);

    if (iVar2 != 0) {

      iVar3 = *(int *)(in_EAX + 0x10);

      do {

        if ((iVar3 != 0) && (iVar3 = iVar3 + -1, iVar3 == 0)) {

          *(uint32_t /* width from decompiler */ *)(in_EAX + 0xc) = 0;

        }

        iVar2 = iVar2 + -1;

      } while (iVar2 != 0);

      *(int *)(in_EAX + 0x10) = iVar3;

    }

  }

  iVar2 = *(int *)(in_EAX + 0xc);

  *param_1 = in_EAX;

  param_1[1] = iVar2 + uVar1;

  return param_1;

}
