// =============================================================================
// Named_CalleeOf_Mission_Attempting_to_open_null_dialog_i_0088a8a0
// -----------------------------------------------------------------------------
// Stable ID: aa_0088a8a0
// Callee of Mission_Attempting_to_open_null_dialog_i
// Address:   0x0088a8a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Mission_Attempting_to_open_null_dialog_i: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_0088a8a0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Mission_Attempting_to_open_null_dialog_i
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

void Named_CalleeOf_Mission_Attempting_to_open_null_dialog_i_0088a8a0(void)



{

  int in_EAX;

  uint32_t /* width from decompiler */ local_20 [2];

  uint local_18;

  uint local_14;

  uint8_t local_10;

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  if (((*(uint *)(in_EAX + 0x510) & *(uint *)(in_EAX + 0x514)) != 0xffffffff) ||

     (*(char *)(in_EAX + 0x518) != '\0')) {

    local_18 = *(uint *)(in_EAX + 0x510);

    local_14 = *(uint *)(in_EAX + 0x514);

    if ((local_18 & local_14) != 0xffffffff) {

      local_20[0] = 0x20a4;

      local_10 = 0;

      local_8 = 0;

      local_4 = 0;

      if (g_pSectorNetConnection_INFERRED != (void *)0x0) {

        (**(code **)(*(int *)g_pSectorNetConnection_INFERRED + 0x18))(0xffffffff,local_20,0x20,0);

      }

    }

  }

  return;

}
