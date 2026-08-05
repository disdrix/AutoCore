// =============================================================================
// FUN_008f71a0
// -----------------------------------------------------------------------------
// Stable ID: aa_008f71a0
// Address:   0x008f71a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008f71a0 @ 0x008f71a0
// Stable ID: aa_008f71a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, while×1, return×1.
//  - Notable callees: FUN_008f71a0.
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

void FUN_008f71a0(int param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int *piVar3;

  

  piVar3 = (int *)(param_1 + 0xe88);

  puVar2 = (uint32_t /* width from decompiler */ *)(param_1 + 0x524);

  iVar1 = 0x96;

  do {

    puVar2[2] = 0;

    if ((void *)*puVar2 != (void *)0x0) {

      operator_delete__((void *)*puVar2);

    }

    *puVar2 = 0;

    if ((void *)puVar2[1] != (void *)0x0) {

      operator_delete__((void *)puVar2[1]);

    }

    puVar2[1] = 0;

    if (*piVar3 != 0) {

      (**(code **)(*(int *)*piVar3 + 0x1d8))(0,1,1);

    }

    puVar2 = puVar2 + 4;

    piVar3 = piVar3 + 1;

    iVar1 = iVar1 + -1;

  } while (iVar1 != 0);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x508) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x50c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x518) = 0;

  *(uint8_t *)(param_1 + 0x500) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x510) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x51c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x514) = 0xffffffff;

  return;

}
