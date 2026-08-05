// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_effDeviceEffect_00448270
// -----------------------------------------------------------------------------
// Stable ID: aa_00448270
// Callee of Named_CalleeOf_Named_effDeviceEffect
// Address:   0x00448270  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_effDeviceEffect: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: for×2, if×1, return×1.
//  - Notable callees: FUN_00448270.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_effDeviceEffect
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_effDeviceEffect_00448270(int param_1)



{

  uint32_t /* width from decompiler */ *in_EAX;

  int iVar1;

  uint32_t /* width from decompiler */ *unaff_EBX;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  

  for (; param_1 != 0; param_1 = param_1 + -1) {

    if (in_EAX != (uint32_t /* width from decompiler */ *)0x0) {

      puVar2 = unaff_EBX;

      puVar3 = in_EAX;

      for (iVar1 = 9; iVar1 != 0; iVar1 = iVar1 + -1) {

        *puVar3 = *puVar2;

        puVar2 = puVar2 + 1;

        puVar3 = puVar3 + 1;

      }

    }

    in_EAX = in_EAX + 9;

  }

  return;

}
