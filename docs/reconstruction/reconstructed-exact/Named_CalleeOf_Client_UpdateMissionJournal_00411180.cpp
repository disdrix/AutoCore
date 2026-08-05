// =============================================================================
// Named_CalleeOf_Client_UpdateMissionJournal_00411180
// -----------------------------------------------------------------------------
// Stable ID: aa_00411180
// Callee of Client_UpdateMissionJournal
// Address:   0x00411180  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_UpdateMissionJournal: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_0040b6d0, FUN_00411180.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Client_UpdateMissionJournal
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

void Named_CalleeOf_Client_UpdateMissionJournal_00411180(void)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int in_EAX;

  uint32_t /* width from decompiler */ *unaff_ESI;

  

  iVar1 = *(int *)(in_EAX + 4);

  if ((iVar1 != 0) &&

     ((uint)(*(int *)(in_EAX + 8) - iVar1 >> 2) < (uint)(*(int *)(in_EAX + 0xc) - iVar1 >> 2))) {

    puVar2 = *(uint32_t /* width from decompiler */ **)(in_EAX + 8);

    *puVar2 = *unaff_ESI;

    *(uint32_t /* width from decompiler */ **)(in_EAX + 8) = puVar2 + 1;

    return;

  }

  FUN_0040b6d0(*(uint32_t /* width from decompiler */ *)(in_EAX + 8),unaff_ESI);

  return;

}
