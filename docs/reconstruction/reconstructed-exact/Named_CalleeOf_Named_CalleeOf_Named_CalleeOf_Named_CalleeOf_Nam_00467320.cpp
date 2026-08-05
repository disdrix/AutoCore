// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00467320
// -----------------------------------------------------------------------------
// Stable ID: aa_00467320
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_anmAnimMaste
// Address:   0x00467320  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_anmAnimMaste: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_00467320.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_anmAnimMaste
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00467320(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2)



{

  int in_EAX;

  uint32_t /* width from decompiler */ *puVar1;

  

  if (in_EAX != 0) {

    puVar1 = param_1 + 6;

    do {

      if (param_1 != (uint32_t /* width from decompiler */ *)0x0) {

        *param_1 = *param_2;

        param_1[1] = param_2[1];

        param_1[2] = param_2[2];

        param_1[3] = param_2[3];

        puVar1[-2] = param_2[4];

        puVar1[-1] = param_2[5];

        *puVar1 = param_2[6];

      }

      param_1 = param_1 + 7;

      puVar1 = puVar1 + 7;

      in_EAX = in_EAX + -1;

    } while (in_EAX != 0);

  }

  return;

}
