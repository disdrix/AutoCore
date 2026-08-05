// =============================================================================
// Named_CalleeOf_Client_UpdateObjectiveDisplayHud_008beb40
// -----------------------------------------------------------------------------
// Stable ID: aa_008beb40
// Callee of Client_UpdateObjectiveDisplayHud
// Address:   0x008beb40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_UpdateObjectiveDisplayHud: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×4, return×4.
//  - Notable callees: FUN_008beb40.
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of Client_UpdateObjectiveDisplayHud
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

uint32_t /* width from decompiler */ Named_CalleeOf_Client_UpdateObjectiveDisplayHud_008beb40(ushort param_1)



{

  int iVar1;

  int in_EAX;

  uint uVar2;

  

  if (*(int *)(in_EAX + 0x52c) == 0) {

    uVar2 = 0;

  }

  else {

    uVar2 = *(int *)(in_EAX + 0x530) - *(int *)(in_EAX + 0x52c) >> 3;

  }

  iVar1 = *(int *)(in_EAX + 0x52c);

  if (uVar2 <= param_1) {

    if ((iVar1 != 0) && (*(int *)(in_EAX + 0x530) - iVar1 >> 3 != 0)) {

      if (iVar1 == 0) {

        return uRamfffffffc;

      }

      return *(uint32_t /* width from decompiler */ *)

              (*(int *)(in_EAX + 0x52c) + (*(int *)(in_EAX + 0x530) - iVar1 >> 3) * 8 + -4);

    }

    return 0;

  }

  return *(uint32_t /* width from decompiler */ *)(iVar1 + (uint)param_1 * 8 + 4);

}
