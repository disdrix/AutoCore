// =============================================================================
// FUN_00424d60
// -----------------------------------------------------------------------------
// Stable ID: aa_00424d60
// Address:   0x00424d60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00424d60 @ 0x00424d60
// Stable ID: aa_00424d60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: for×2, if×1, return×1.
//  - Notable callees: FUN_00424d60, malloc.
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

void __fastcall FUN_00424d60(int param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint uVar2;

  uint uVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ *puVar5;

  

  if (*(char *)(param_1 + 0x14) == '\0') {

    puVar1 = malloc(*(size_t *)(param_1 + 0x10));

    uVar3 = *(uint *)(param_1 + 0x10);

    puVar4 = *(uint32_t /* width from decompiler */ **)(param_1 + 0xc);

    puVar5 = puVar1;

    for (uVar2 = uVar3 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {

      *puVar5 = *puVar4;

      puVar4 = puVar4 + 1;

      puVar5 = puVar5 + 1;

    }

    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {

      *(uint8_t *)puVar5 = *(uint8_t *)puVar4;

      puVar4 = (uint32_t /* width from decompiler */ *)((int)puVar4 + 1);

      puVar5 = (uint32_t /* width from decompiler */ *)((int)puVar5 + 1);

    }

    *(uint32_t /* width from decompiler */ **)(param_1 + 0xc) = puVar1;

    *(uint8_t *)(param_1 + 0x14) = 1;

  }

  return;

}
