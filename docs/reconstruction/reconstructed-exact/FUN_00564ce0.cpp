// =============================================================================
// FUN_00564ce0
// -----------------------------------------------------------------------------
// Stable ID: aa_00564ce0
// Address:   0x00564ce0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00564ce0 @ 0x00564ce0
// Stable ID: aa_00564ce0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: if×4, return×3.
//  - Notable callees: FUN_004bcbc0, FUN_004e2600, FUN_00564ce0, FUN_00582b00.
//  - Return sites: 3.

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

void __fastcall FUN_00564ce0(int param_1)



{

  int iVar1;

  

  *(undefined ***)(param_1 + -0x1e0) = &PTR_LAB_009d2d34;

  *(undefined ***)(*(int *)(*(int *)(param_1 + -0x1dc) + 4) + -0x1dc + param_1) = &PTR_LAB_009d2a6c;

  iVar1 = *(int *)(*(int *)(param_1 + -0x1dc) + 4);

  *(int *)(iVar1 + -0x1e0 + param_1) = iVar1 + -0x1dc;

  iVar1 = *(int *)(param_1 + -0x20);

  if (iVar1 != 0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1))(1);

  }

  iVar1 = *(int *)(param_1 + -0x1c);

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x20) = 0;

  if (iVar1 != 0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1))(1);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x1c) = 0;

  FUN_004e2600(FUN_00563760,0,1);

  if (*(void **)(param_1 + -0x4c) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + -0x4c));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x4c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x48) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x44) = 0;

  if (*(void **)(param_1 + -0x5c) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + -0x5c));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x5c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x58) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x54) = 0;

  FUN_004bcbc0();

  FUN_00582b00();

  return;

}
