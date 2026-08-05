// =============================================================================
// FUN_005a56a0
// -----------------------------------------------------------------------------
// Stable ID: aa_005a56a0
// Address:   0x005a56a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005a56a0 @ 0x005a56a0
// Stable ID: aa_005a56a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: CONCAT31, FUN_005a56a0, SQRT.
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

uint __thiscall FUN_005a56a0(int param_1,float param_2)



{

  uint in_EAX;

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  

  *(float *)(param_1 + 100) = param_2 + *(float *)(param_1 + 100);

  if (*(char *)(param_1 + 0x51) == '\0') {

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x30) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x20);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x34) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x24);

    *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x28);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x3c) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c);

    return *(uint *)(param_1 + 0x28) & 0xffffff00;

  }

  fVar1 = param_2 + *(float *)(param_1 + 0x60);

  *(float *)(param_1 + 0x60) = fVar1;

  *(float *)(param_1 + 0x58) = param_2 + *(float *)(param_1 + 0x58);

  if (*(float *)(param_1 + 0x5c) <= fVar1) {

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x30) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x20);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x34) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x24);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x38) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x28);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x3c) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c);

    *(uint8_t *)(param_1 + 0x50) = 1;

    return CONCAT31((int3)((uint)*(uint32_t /* width from decompiler */ *)(param_1 + 0x28) >> 8),1);

  }

  fVar4 = *(float *)(param_1 + 0x28) - *(float *)(param_1 + 0x38);

  fVar3 = *(float *)(param_1 + 0x24) - *(float *)(param_1 + 0x34);

  fVar2 = *(float *)(param_1 + 0x20) - *(float *)(param_1 + 0x30);

  fVar1 = (fVar1 / *(float *)(param_1 + 0x5c)) * SQRT(fVar4 * fVar4 + fVar3 * fVar3 + fVar2 * fVar2)

  ;

  *(float *)(param_1 + 0x30) = *(float *)(param_1 + 0x30) + fVar1 * *(float *)(param_1 + 0x40);

  *(float *)(param_1 + 0x38) = *(float *)(param_1 + 0x38) + *(float *)(param_1 + 0x48) * fVar1;

  *(float *)(param_1 + 0x34) = *(float *)(param_1 + 0x34) + *(float *)(param_1 + 0x44) * fVar1;

  *(float *)(param_1 + 0x3c) = *(float *)(param_1 + 0x3c) + *(float *)(param_1 + 0x4c) * fVar1;

  return in_EAX & 0xffffff00;

}
