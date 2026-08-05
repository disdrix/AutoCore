// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_gfxDeviceVB_0096b280
// -----------------------------------------------------------------------------
// Stable ID: aa_0096b280
// Callee of Named_CalleeOf_Named_gfxDeviceVB
// Address:   0x0096b280  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_gfxDeviceVB: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×4, do×1, while×1, return×1.
//  - Notable callees: FUN_0040cf90, FUN_0040d1a0, FUN_0044b440, FUN_0076df50, FUN_0076f6e0, FUN_0096af80, FUN_0096b000, FUN_0096b280.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_gfxDeviceVB
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

void Named_CalleeOf_Named_CalleeOf_Named_gfxDeviceVB_0096b280(int param_1)



{

  int iVar1;

  int iVar2;

  byte local_14;

  

  iVar1 = *(int *)(param_1 + 4);

  if (iVar1 != 0) {

    *(uint32_t /* width from decompiler */ *)(param_1 + 4) = 0;

    FUN_00972cc0();

    iVar2 = *(int *)(param_1 + 0xc);

    if (iVar2 != *(int *)(param_1 + 0x10)) {

      do {

        FUN_0096b000();

        FUN_0096af80();

        if (iVar1 != 1) {

          FUN_0076df50();

          FUN_0040d1a0();

        }

        if ((local_14 & 1) != 0) {

          FUN_00972e50();

        }

        FUN_0076f6e0();

        FUN_0040cf90();

        FUN_0044b440();

        iVar2 = iVar2 + 4;

      } while (iVar2 != *(int *)(param_1 + 0x10));

    }

  }

  return;

}
