// =============================================================================
// FUN_00787020
// -----------------------------------------------------------------------------
// Stable ID: aa_00787020
// Address:   0x00787020  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00787020 @ 0x00787020
// Stable ID: aa_00787020
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~44 non-empty decompiler lines.
//  - Control keywords: if×6, while×2, return×1.
//  - Notable callees: FUN_00780b70, FUN_00787020.
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

void __fastcall FUN_00787020(uint32_t /* width from decompiler */ *param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  

  iVar1 = param_1[9];

  *param_1 = &PTR_LAB_00a9ac00;

  while (iVar1 != 0) {

    FUN_00780b70();

    iVar1 = param_1[9];

  }

  if (param_1[6] != 0 || param_1[7] != 0) {

    if (param_1[3] == 0) {

      g_pNetObjectDirtyListHead = (void *)param_1[4];

    }

    else {

      *(uint32_t /* width from decompiler */ *)(param_1[3] + 0x10) = param_1[4];

    }

    if (param_1[4] != 0) {

      *(uint32_t /* width from decompiler */ *)(param_1[4] + 0xc) = param_1[3];

    }

  }

  if (param_1[10] != 0) {

    if (param_1[0xb] == 0) {

      *(uint32_t /* width from decompiler */ *)(param_1[10] + 4) = param_1[0xc];

    }

    else {

      *(uint32_t /* width from decompiler */ *)(param_1[0xb] + 8) = param_1[0xc];

    }

    if (param_1[0xc] != 0) {

      *(uint32_t /* width from decompiler */ *)(param_1[0xc] + 4) = param_1[0xb];

    }

  }

  *param_1 = &PTR_LAB_00a9b1dc;

  puVar3 = (uint32_t /* width from decompiler */ *)param_1[1];

  while (puVar3 != (uint32_t /* width from decompiler */ *)0x0) {

    puVar2 = (uint32_t /* width from decompiler */ *)puVar3[2];

    *puVar3 = 0;

    puVar3[1] = 0;

    puVar3[2] = 0;

    puVar3 = puVar2;

  }

  return;

}
