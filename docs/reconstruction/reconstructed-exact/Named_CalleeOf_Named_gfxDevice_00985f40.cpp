// =============================================================================
// Named_CalleeOf_Named_gfxDevice_00985f40
// -----------------------------------------------------------------------------
// Stable ID: aa_00985f40
// Callee of Named_gfxDevice
// Address:   0x00985f40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxDevice: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: for×2, if×1, return×1.
//  - Notable callees: FUN_00985f40.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_gfxDevice
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

void Named_CalleeOf_Named_gfxDevice_00985f40(void)



{

  int *piVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int in_EAX;

  int *piVar4;

  uint32_t /* width from decompiler */ *puVar5;

  

  piVar1 = *(int **)(in_EAX + 8);

  for (piVar4 = *(int **)(in_EAX + 4); piVar4 != piVar1; piVar4 = piVar4 + 1) {

    iVar2 = *piVar4;

    puVar5 = *(uint32_t /* width from decompiler */ **)(iVar2 + 8);

    if ((puVar5 != (uint32_t /* width from decompiler */ *)0x0) && (*(int *)(iVar2 + 0xc) - (int)puVar5 >> 2 != 0)) {

      puVar3 = *(uint32_t /* width from decompiler */ **)(iVar2 + 0xc);

      for (; puVar5 != puVar3; puVar5 = puVar5 + 1) {

        (**(code **)(*(int *)*puVar5 + 0xc))();

      }

    }

  }

  return;

}
