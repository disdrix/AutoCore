// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0069dca0
// -----------------------------------------------------------------------------
// Stable ID: aa_0069dca0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x0069dca0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~72 non-empty decompiler lines.
//  - Control keywords: for×3, return×1.
//  - Notable callees: FUN_0069dca0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0069dca0(uint32_t /* width from decompiler */ *param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ local_9c [39];

  

  *param_1 = 0;

  param_1[0xe] = 0;

  param_1[0x1d] = 0;

  param_1[0x1e] = 0;

  local_9c[0x13] = 0;

  local_9c[0x14] = 0;

  local_9c[0x15] = 0;

  local_9c[0x16] = 0;

  local_9c[0x17] = 0;

  local_9c[0x18] = 0;

  local_9c[0x19] = 0;

  local_9c[6] = 0;

  local_9c[7] = 0;

  local_9c[8] = 0;

  local_9c[9] = 0;

  local_9c[10] = 0;

  local_9c[0xb] = 0;

  local_9c[0xc] = 0;

  local_9c[0x20] = 0;

  local_9c[0x21] = 0;

  local_9c[0x22] = 0;

  local_9c[0x23] = 0;

  local_9c[0x24] = 0;

  local_9c[0x25] = 0;

  local_9c[0x26] = 0;

  local_9c[0xd] = 0x3f4ccccd;

  local_9c[0xe] = 0x3f4ccccd;

  local_9c[0xf] = 0x3f4ccccd;

  local_9c[0x10] = 0x3e4ccccd;

  local_9c[0x11] = 0x3e4ccccd;

  local_9c[0x12] = 0x3e4ccccd;

  puVar2 = local_9c + 0xd;

  puVar3 = param_1;

  for (iVar1 = 0xd; puVar3 = puVar3 + 1, iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar3 = *puVar2;

    puVar2 = puVar2 + 1;

  }

  local_9c[0] = 0x3f800000;

  local_9c[1] = 0x3f800000;

  local_9c[2] = 0x3f800000;

  local_9c[3] = 0x3f000000;

  local_9c[4] = 0x3f000000;

  local_9c[5] = 0x3f000000;

  puVar3 = local_9c;

  puVar2 = param_1 + 0xf;

  for (iVar1 = 0xd; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar2 = *puVar3;

    puVar3 = puVar3 + 1;

    puVar2 = puVar2 + 1;

  }

  local_9c[0x1a] = 0x3f800000;

  local_9c[0x1b] = 0x3f800000;

  local_9c[0x1c] = 0x3f800000;

  local_9c[0x1d] = 0x3f000000;

  local_9c[0x1e] = 0x3f000000;

  local_9c[0x1f] = 0x3f000000;

  puVar3 = local_9c + 0x1a;

  puVar2 = param_1 + 0x1f;

  for (iVar1 = 0xd; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar2 = *puVar3;

    puVar3 = puVar3 + 1;

    puVar2 = puVar2 + 1;

  }

  param_1[0x1c] = 0x3f000000;

  return;

}
