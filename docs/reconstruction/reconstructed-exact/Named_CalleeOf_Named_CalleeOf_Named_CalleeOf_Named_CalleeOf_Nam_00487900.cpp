// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00487900
// -----------------------------------------------------------------------------
// Stable ID: aa_00487900
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x00487900  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~39 non-empty decompiler lines.
//  - Control keywords: while×3, if×2, for×1, return×1.
//  - Notable callees: FUN_00487900.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00487900(int param_1)



{

  int iVar1;

  uint uVar2;

  int iVar3;

  int iVar4;

  int in_EAX;

  int iVar5;

  int unaff_EBX;

  int unaff_ESI;

  int iVar6;

  

  if (param_1 != unaff_ESI) {

    iVar5 = unaff_ESI;

    if (3 < unaff_ESI - param_1) {

      for (iVar6 = unaff_ESI + -4; param_1 <= iVar6; iVar6 = iVar6 + -1) {

        iVar1 = *(int *)(in_EAX + iVar6 * 4);

        uVar2 = *(uint *)(unaff_EBX + iVar1 * 4);

        iVar4 = iVar6;

        while ((iVar4 = iVar4 + 4, iVar4 <= unaff_ESI &&

               (iVar3 = *(int *)(in_EAX + iVar4 * 4), *(uint *)(unaff_EBX + iVar3 * 4) < uVar2))) {

          *(int *)(in_EAX + -0x10 + iVar4 * 4) = iVar3;

        }

        *(int *)(in_EAX + -0x10 + iVar4 * 4) = iVar1;

      }

    }

    while (iVar6 = iVar5 + -1, param_1 <= iVar6) {

      iVar1 = *(int *)(in_EAX + iVar6 * 4);

      uVar2 = *(uint *)(unaff_EBX + iVar1 * 4);

      while ((iVar5 <= unaff_ESI &&

             (iVar4 = *(int *)(in_EAX + iVar5 * 4), *(uint *)(unaff_EBX + iVar4 * 4) < uVar2))) {

        *(int *)(in_EAX + -4 + iVar5 * 4) = iVar4;

        iVar5 = iVar5 + 1;

      }

      *(int *)(in_EAX + -4 + iVar5 * 4) = iVar1;

      iVar5 = iVar6;

    }

  }

  return;

}
