// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_anmTrackMaster_inl_0044ec90
// -----------------------------------------------------------------------------
// Stable ID: aa_0044ec90
// Callee of Named_CalleeOf_Named_anmTrackMaster_inl
// Address:   0x0044ec90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_anmTrackMaster_inl: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_0044ec90.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_anmTrackMaster_inl
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

uint32_t /* width from decompiler */ * __fastcall Named_CalleeOf_Named_CalleeOf_Named_anmTrackMaster_inl_0044ec90(uint32_t /* width from decompiler */ param_1,uint *param_2)



{

  int in_EAX;

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  

  puVar2 = *(uint32_t /* width from decompiler */ **)(in_EAX + 4);

  if (*(char *)((int)puVar2[1] + 0x21) == '\0') {

    puVar1 = puVar2;

    puVar3 = (uint32_t /* width from decompiler */ *)puVar2[1];

    do {

      puVar2 = puVar3;

      if ((param_2[1] < (uint)puVar2[5]) ||

         ((param_2[1] <= (uint)puVar2[5] && (*param_2 <= (uint)puVar2[4])))) {

        puVar3 = (uint32_t /* width from decompiler */ *)*puVar2;

      }

      else {

        puVar3 = (uint32_t /* width from decompiler */ *)puVar2[2];

        puVar2 = puVar1;

      }

      puVar1 = puVar2;

    } while (*(char *)((int)puVar3 + 0x21) == '\0');

  }

  return puVar2;

}
