// =============================================================================
// FUN_0043f660
// -----------------------------------------------------------------------------
// Stable ID: aa_0043f660
// Address:   0x0043f660  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0043f660 @ 0x0043f660
// Stable ID: aa_0043f660
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: if×3, for×1, return×1.
//  - Notable callees: FUN_00412d40, FUN_0043f660, FUN_009730e0.
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

uint32_t /* width from decompiler */ __fastcall FUN_0043f660(int param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint8_t local_50 [76];

  

  iVar1 = *(int *)(param_1 + 8);

  if (*(int *)(iVar1 + 0xb4) != *(int *)(param_1 + 0x4c)) {

    *(int *)(param_1 + 0x4c) = *(int *)(iVar1 + 0xb4);

    *(uint8_t *)(param_1 + 0x49) = 1;

  }

  if (*(char *)(param_1 + 0x49) != '\0') {

    *(uint8_t *)(param_1 + 0x49) = 0;

    if ((*(uint *)(iVar1 + 0xbc) >> 1 & 1) == 0) {

      iVar1 = iVar1 + 0x40;

    }

    else {

      iVar1 = FUN_009730e0();

    }

    puVar2 = (uint32_t /* width from decompiler */ *)FUN_00412d40(local_50,iVar1,*(uint32_t /* width from decompiler */ *)(param_1 + 0x50));

    puVar3 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x54);

    for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {

      *puVar3 = *puVar2;

      puVar2 = puVar2 + 1;

      puVar3 = puVar3 + 1;

    }

  }

  return *(uint32_t /* width from decompiler */ *)(param_1 + 0x54);

}
