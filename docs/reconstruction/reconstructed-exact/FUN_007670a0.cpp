// =============================================================================
// FUN_007670a0
// -----------------------------------------------------------------------------
// Stable ID: aa_007670a0
// Address:   0x007670a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007670a0 @ 0x007670a0
// Stable ID: aa_007670a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_007670a0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void FUN_007670a0(void)



{

  uint uVar1;

  uint16_t *puVar2;

  uint32_t /* width from decompiler */ *unaff_ESI;

  

  uVar1 = (**(code **)(*(int *)*unaff_ESI + 0x18))();

  unaff_ESI[1] = unaff_ESI[1] | uVar1;

  puVar2 = &DAT_00a7050c;

  if (unaff_ESI[7] != 0) {

    puVar2 = (uint16_t *)&DAT_00a85110;

  }

  uVar1 = (**(code **)(*(int *)*unaff_ESI + 0x18))(puVar2);

  unaff_ESI[1] = unaff_ESI[1] | uVar1;

  uVar1 = (**(code **)(*(int *)*unaff_ESI + 0x18))(&stack0xffffffef,1);

  unaff_ESI[1] = unaff_ESI[1] | uVar1;

  uVar1 = (**(code **)(*(int *)*unaff_ESI + 0x18))(&DAT_00a9d72c,2);

  unaff_ESI[1] = unaff_ESI[1] | uVar1;

  if (unaff_ESI[7] == 1) {

    uVar1 = (**(code **)(*(int *)*unaff_ESI + 0x18))(&DAT_00a97b84,2);

    unaff_ESI[1] = unaff_ESI[1] | uVar1;

  }

  return;

}
