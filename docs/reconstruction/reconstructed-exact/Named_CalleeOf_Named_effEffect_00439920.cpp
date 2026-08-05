// =============================================================================
// Named_CalleeOf_Named_effEffect_00439920
// -----------------------------------------------------------------------------
// Stable ID: aa_00439920
// Callee of Named_effEffect
// Address:   0x00439920  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_effEffect: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×3, return×3.
//  - Notable callees: FUN_00439920, FUN_00767160.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_effEffect
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_effEffect_00439920(void)



{

  int in_EAX;

  uint uVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *unaff_ESI;

  

  if (unaff_ESI[7] != 0) {

    if (*(uint *)(in_EAX + 0x18) < 0x10) {

      iVar2 = in_EAX + 4;

    }

    else {

      iVar2 = *(int *)(in_EAX + 4);

    }

    uVar1 = FUN_00767160(&DAT_00a9d6f8,iVar2);

    unaff_ESI[1] = unaff_ESI[1] | uVar1;

    unaff_ESI[8] = 0;

    uVar1 = (**(code **)(*(int *)*unaff_ESI + 0x18))(&DAT_00a97b84,2);

    unaff_ESI[1] = unaff_ESI[1] | uVar1;

    return unaff_ESI[1];

  }

  if (0xf < *(uint *)(in_EAX + 0x18)) {

    uVar1 = (**(code **)(*(int *)*unaff_ESI + 0x18))

                      (*(uint32_t /* width from decompiler */ *)(in_EAX + 4),*(int *)(in_EAX + 0x14) + 1);

    unaff_ESI[1] = unaff_ESI[1] | uVar1;

    return unaff_ESI[1];

  }

  uVar1 = (**(code **)(*(int *)*unaff_ESI + 0x18))(in_EAX + 4,*(int *)(in_EAX + 0x14) + 1);

  unaff_ESI[1] = unaff_ESI[1] | uVar1;

  return unaff_ESI[1];

}
