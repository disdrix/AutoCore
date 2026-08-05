// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_gfxDeviceVB_00464ac0
// -----------------------------------------------------------------------------
// Stable ID: aa_00464ac0
// Callee of Named_CalleeOf_Named_gfxDeviceVB
// Address:   0x00464ac0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_gfxDeviceVB: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×2, for×1, return×1.
//  - Notable callees: FUN_00412d40, FUN_00464ac0, FUN_00972e50.
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

void Named_CalleeOf_Named_CalleeOf_Named_gfxDeviceVB_00464ac0(void)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int unaff_EBX;

  uint32_t /* width from decompiler */ *puVar3;

  uint8_t local_50 [76];

  

  if (*(int *)(unaff_EBX + 0x140) != *(int *)(unaff_EBX + 0xe4)) {

    iVar1 = unaff_EBX + 0x30;

    if ((*(byte *)(unaff_EBX + 0xec) & 1) != 0) {

      iVar1 = FUN_00972e50();

    }

    puVar2 = (uint32_t /* width from decompiler */ *)FUN_00412d40(local_50,*(int *)(unaff_EBX + 0xf4) + 0x40,iVar1);

    puVar3 = (uint32_t /* width from decompiler */ *)(unaff_EBX + 0x100);

    for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {

      *puVar3 = *puVar2;

      puVar2 = puVar2 + 1;

      puVar3 = puVar3 + 1;

    }

    *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x140) = *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0xe4);

  }

  return;

}
