// =============================================================================
// FUN_0053dd40
// -----------------------------------------------------------------------------
// Stable ID: aa_0053dd40
// Address:   0x0053dd40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0053dd40 @ 0x0053dd40
// Stable ID: aa_0053dd40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_004cd540, FUN_00516a00, FUN_00517a70, FUN_0053dd40.
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

void __fastcall FUN_0053dd40(int param_1)



{

  byte *pbVar1;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  

  FUN_00517a70();

  pbVar1 = (byte *)(*(int *)(*(int *)(param_1 + -0x4c) + 4) + 0x131 + param_1);

  *pbVar1 = *pbVar1 & 0xfe;

  iVar3 = *(int *)(*(int *)(*(int *)(param_1 + -0x4c) + 4) + -0x4c + param_1);

  uVar2 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0x4c) + 4) + -0x4c + param_1) + 0x244))

                    ();

  (**(code **)(iVar3 + 0x240))(uVar2);

  iVar3 = *(int *)(*(int *)(*(int *)(*(int *)(param_1 + -0x4c) + 4) + 0x5c + param_1) + 0x38);

  if ((iVar3 != 0x12) && (iVar3 != 0x14)) {

    FUN_00516a00(1);

  }

  iVar3 = 0;

  if (param_1 != 0x50) {

    iVar3 = *(int *)(*(int *)(param_1 + -0x4c) + 4) + -0x4c + param_1;

  }

  FUN_004cd540(iVar3,1);

  if (*(int *)(param_1 + -0x48) != 0) {

    (**(code **)(*(int *)(param_1 + -0x50) + 0x14))(0);

  }

  return;

}
