// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004561e0
// -----------------------------------------------------------------------------
// Stable ID: aa_004561e0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxShadowVol
// Address:   0x004561e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxShadowVol: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_004561e0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxShadowVol
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004561e0(uint32_t /* width from decompiler */ *param_1)



{

  uint32_t /* width from decompiler */ *in_EAX;

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *unaff_EDI;

  

  if (param_1 != unaff_EDI) {

    puVar1 = in_EAX + 8;

    puVar2 = param_1 + 8;

    do {

      if (in_EAX != (uint32_t /* width from decompiler */ *)0x0) {

        *in_EAX = *param_1;

        puVar1[-7] = puVar2[-7];

        puVar1[-6] = puVar2[-6];

        puVar1[-5] = puVar2[-5];

        puVar1[-4] = puVar2[-4];

        puVar1[-3] = puVar2[-3];

        puVar1[-2] = puVar2[-2];

        puVar1[-1] = puVar2[-1];

        *puVar1 = *puVar2;

      }

      param_1 = param_1 + 9;

      in_EAX = in_EAX + 9;

      puVar1 = puVar1 + 9;

      puVar2 = puVar2 + 9;

    } while (param_1 != unaff_EDI);

  }

  return;

}
