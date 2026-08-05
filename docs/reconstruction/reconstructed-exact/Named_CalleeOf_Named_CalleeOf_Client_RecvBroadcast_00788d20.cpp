// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_RecvBroadcast_00788d20
// -----------------------------------------------------------------------------
// Stable ID: aa_00788d20
// Callee of Named_CalleeOf_Client_RecvBroadcast
// Address:   0x00788d20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_RecvBroadcast: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×2, do×2, while×2, return×1.
//  - Notable callees: FUN_00788d20.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_RecvBroadcast
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

uint32_t /* width from decompiler */ __fastcall Named_CalleeOf_Named_CalleeOf_Client_RecvBroadcast_00788d20(uint32_t /* width from decompiler */ *param_1,int param_2)



{

  uint32_t /* width from decompiler */ *in_EAX;

  int iVar1;

  

  if (4 < param_2) {

    iVar1 = (param_2 - 5U >> 2) + 1;

    param_2 = param_2 + iVar1 * -4;

    do {

      *in_EAX = *param_1;

      in_EAX = in_EAX + 1;

      param_1 = param_1 + 1;

      iVar1 = iVar1 + -1;

    } while (iVar1 != 0);

  }

  if (0 < param_2) {

    iVar1 = (int)param_1 - (int)in_EAX;

    do {

      *(uint8_t *)in_EAX = *(uint8_t *)(iVar1 + (int)in_EAX);

      in_EAX = (uint32_t /* width from decompiler */ *)((int)in_EAX + 1);

      param_2 = param_2 + -1;

    } while (param_2 != 0);

  }

  return 1;

}
