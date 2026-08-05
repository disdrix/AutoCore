// =============================================================================
// Named_CalleeOf_Named_gfxLightManager_00968080
// -----------------------------------------------------------------------------
// Stable ID: aa_00968080
// Callee of Named_gfxLightManager
// Address:   0x00968080  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxLightManager: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, for×1, while×1, return×1.
//  - Notable callees: FUN_0040ae90, FUN_004494b0, FUN_00456780, FUN_00968080.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_gfxLightManager
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

void Named_CalleeOf_Named_gfxLightManager_00968080(void)



{

  uint32_t /* width from decompiler */ *puVar1;

  int *piVar2;

  int *in_EAX;

  int *piVar3;

  uint32_t /* width from decompiler */ *puVar4;

  int local_4;

  

  if (*in_EAX != 0) {

    FUN_004494b0();

  }

  local_4 = 0;

  if (0 < *DAT_00d1f62c) {

    piVar3 = in_EAX + 3;

    do {

      puVar1 = (uint32_t /* width from decompiler */ *)*piVar3;

      for (puVar4 = (uint32_t /* width from decompiler */ *)piVar3[-1]; puVar4 != puVar1; puVar4 = puVar4 + 1) {

        piVar2 = (int *)*puVar4;

        if (piVar2 != (int *)0x0) {

          FUN_0040ae90();

          *piVar2 = (int)DAT_00d21998;

          DAT_00d21998 = piVar2;

        }

      }

      FUN_00456780(0);

      local_4 = local_4 + 1;

      piVar3 = piVar3 + 4;

    } while (local_4 < *DAT_00d1f62c);

  }

  return;

}
