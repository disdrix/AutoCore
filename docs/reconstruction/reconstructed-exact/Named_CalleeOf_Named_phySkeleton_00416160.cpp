// =============================================================================
// Named_CalleeOf_Named_phySkeleton_00416160
// -----------------------------------------------------------------------------
// Stable ID: aa_00416160
// Callee of Named_phySkeleton (+1 other named callers)
// Address:   0x00416160  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_phySkeleton: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_phySkeleton (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~45 non-empty decompiler lines.
//  - Control keywords: if×3, for×2, return×1.
//  - Notable callees: FUN_00416160.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_phySkeleton (+1 other named callers)
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

void __thiscall Named_CalleeOf_Named_phySkeleton_00416160(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2)



{

  uint uVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ *puVar4;

  

  param_1[0x20] = param_2[0x20];

  param_1[0x21] = param_2[0x21];

  param_1[0x22] = param_2[0x22];

  param_1[0x23] = param_2[0x23];

  param_1[0x24] = param_2[0x24];

  param_1[0x25] = param_2[0x25];

  param_1[0x26] = param_2[0x26];

  param_1[0x27] = param_2[0x27];

  param_1[0x28] = param_2[0x28];

  param_1[0x29] = param_2[0x29];

  *(uint8_t *)(param_1 + 0x2e) = *(uint8_t *)(param_2 + 0x2e);

  uVar1 = param_2[0x2f];

  param_1[0x2f] = uVar1;

  if ((uVar1 & 1) == 0) {

    puVar3 = param_2;

    puVar4 = param_1;

    for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {

      *puVar4 = *puVar3;

      puVar3 = puVar3 + 1;

      puVar4 = puVar4 + 1;

    }

  }

  if (((uint)param_1[0x2f] >> 1 & 1) == 0) {

    puVar3 = param_2 + 0x10;

    puVar4 = param_1 + 0x10;

    for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {

      *puVar4 = *puVar3;

      puVar3 = puVar3 + 1;

      puVar4 = puVar4 + 1;

    }

  }

  if (((uint)param_1[0x2f] >> 2 & 1) == 0) {

    param_1[0x2a] = param_2[0x2a];

    param_1[0x2b] = param_2[0x2b];

    param_1[0x2c] = param_2[0x2c];

  }

  param_1[0x2d] = param_1[0x2d] + 1;

  return;

}
