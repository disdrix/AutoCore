// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_0083b830
// -----------------------------------------------------------------------------
// Stable ID: aa_0083b830
// Callee of Named_VOG_DEBUG_STOP
// Address:   0x0083b830  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: return×4, if×3.
//  - Notable callees: FUN_0083b830.
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of Named_VOG_DEBUG_STOP
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

void __fastcall Named_CalleeOf_Named_VOG_DEBUG_STOP_0083b830(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int *in_EAX;

  

  iVar1 = *(int *)(param_1 + 0x4fc);

  iVar2 = *(int *)(param_1 + 0x500);

  if (*(int *)(param_1 + 0x504) + iVar1 + iVar2 <= param_2) {

    *in_EAX = -100;

    in_EAX[1] = -100;

    return;

  }

  if (iVar1 + iVar2 <= param_2) {

    iVar3 = *(int *)(param_1 + 0x51c);

    *in_EAX = *(int *)(param_1 + 0x518) -

              (*(int *)(param_1 + 0x528) + *(int *)(param_1 + 0x520)) * ((param_2 - iVar1) - iVar2);

    in_EAX[1] = iVar3;

    return;

  }

  if (iVar1 <= param_2) {

    iVar2 = *(int *)(param_1 + 0x514);

    *in_EAX = *(int *)(param_1 + 0x510) -

              (*(int *)(param_1 + 0x528) + *(int *)(param_1 + 0x520)) * (param_2 - iVar1);

    in_EAX[1] = iVar2;

    return;

  }

  iVar1 = *(int *)(param_1 + 0x50c);

  *in_EAX = *(int *)(param_1 + 0x508) -

            (*(int *)(param_1 + 0x528) + *(int *)(param_1 + 0x520)) * param_2;

  in_EAX[1] = iVar1;

  return;

}
