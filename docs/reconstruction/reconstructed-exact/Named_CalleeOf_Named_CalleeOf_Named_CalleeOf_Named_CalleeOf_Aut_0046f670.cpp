// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Aut_0046f670
// -----------------------------------------------------------------------------
// Stable ID: aa_0046f670
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Auth_Setup_of_CNDA
// Address:   0x0046f670  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Auth_Setup_of_CNDA: auth/session helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, do×1, while×1.
//  - Notable callees: FUN_0046f670, FUN_0046f6e0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Auth_Setup_of_CNDA
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

uint32_t /* width from decompiler */ * __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Aut_0046f670(int param_1)



{

  int *in_EAX;

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int *piVar3;

  uint32_t /* width from decompiler */ *puVar4;

  

  puVar4 = *(uint32_t /* width from decompiler */ **)(param_1 + 4);

  if (*(char *)((int)puVar4[1] + 0x19) == '\0') {

    puVar1 = (uint32_t /* width from decompiler */ *)puVar4[1];

    do {

      if ((int)puVar1[3] < *in_EAX) {

        puVar2 = (uint32_t /* width from decompiler */ *)puVar1[2];

      }

      else {

        puVar2 = (uint32_t /* width from decompiler */ *)*puVar1;

        puVar4 = puVar1;

      }

      puVar1 = puVar2;

    } while (*(char *)((int)puVar2 + 0x19) == '\0');

  }

  if ((puVar4 != *(uint32_t /* width from decompiler */ **)(param_1 + 4)) && ((int)puVar4[3] <= *in_EAX)) {

    return puVar4 + 4;

  }

  piVar3 = (int *)FUN_0046f6e0(puVar4);

  return (uint32_t /* width from decompiler */ *)(*piVar3 + 0x10);

}
