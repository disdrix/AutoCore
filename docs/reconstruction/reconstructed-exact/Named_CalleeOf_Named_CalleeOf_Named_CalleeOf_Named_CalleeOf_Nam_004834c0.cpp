// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004834c0
// -----------------------------------------------------------------------------
// Stable ID: aa_004834c0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x004834c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: while×1, return×1.
//  - Notable callees: FUN_004834c0.
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004834c0(int param_1,int param_2)



{

  int iVar1;

  int in_EAX;

  

  iVar1 = *(int *)(in_EAX + 0x25c);

  while (7 < iVar1) {

    *(uint8_t *)(*(int *)(in_EAX + 0x2c) + *(int *)(in_EAX + 0x4c)) =

         *(uint8_t *)(in_EAX + 0x25b);

    *(int *)(in_EAX + 0x4c) = *(int *)(in_EAX + 0x4c) + 1;

    *(int *)(in_EAX + 600) = *(int *)(in_EAX + 600) << 8;

    *(int *)(in_EAX + 0x25c) = *(int *)(in_EAX + 0x25c) + -8;

    iVar1 = *(int *)(in_EAX + 0x25c);

  }

  *(uint *)(in_EAX + 600) =

       *(uint *)(in_EAX + 600) |

       param_1 << ((' ' - (char)*(int *)(in_EAX + 0x25c)) - (char)param_2 & 0x1fU);

  *(int *)(in_EAX + 0x25c) = *(int *)(in_EAX + 0x25c) + param_2;

  return;

}
