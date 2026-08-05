// =============================================================================
// Named_CalleeOf_Named_gfxDevice_0073d8d0
// -----------------------------------------------------------------------------
// Stable ID: aa_0073d8d0
// Callee of Named_gfxDevice
// Address:   0x0073d8d0  (autoassault.exe, image base 0x400000)
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
//  - Notable callees: FUN_0073d8d0, FUN_0074f0c0, FUN_00752640.
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

void Named_CalleeOf_Named_gfxDevice_0073d8d0(void)



{

  int iVar1;

  int iVar2;

  int in_EAX;

  int iVar3;

  int iVar4;

  

  iVar1 = *(int *)(in_EAX + 8);

  for (iVar4 = *(int *)(in_EAX + 4); iVar4 != iVar1; iVar4 = iVar4 + 0x14) {

    FUN_0074f0c0();

    iVar2 = *(int *)(iVar4 + 0xc);

    for (iVar3 = *(int *)(iVar4 + 8); iVar3 != iVar2; iVar3 = iVar3 + 4) {

      FUN_00752640();

    }

  }

  *(uint8_t *)(DAT_00d1f048 + 0xc) = 0;

  if (DAT_00d1f044[0x1df] == 1) {

    (**(code **)(*(int *)*DAT_00d1f044 + 0x134))((int *)*DAT_00d1f044,0);

  }

  return;

}
