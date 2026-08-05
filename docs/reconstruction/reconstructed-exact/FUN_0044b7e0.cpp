// =============================================================================
// FUN_0044b7e0
// -----------------------------------------------------------------------------
// Stable ID: aa_0044b7e0
// Address:   0x0044b7e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0044b7e0 @ 0x0044b7e0
// Stable ID: aa_0044b7e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_0044b7e0, FUN_00972f10, FUN_00972fa0, SQRT.
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

void FUN_0044b7e0(int param_1)



{

  float fVar1;

  float fVar2;

  float fVar3;

  uint *puVar4;

  uint *unaff_EBX;

  int unaff_ESI;

  uint8_t local_c [12];

  

  if ((*unaff_EBX & 1) != 0) {

    fVar1 = *(float *)(param_1 + 0x9c) * *(float *)(unaff_ESI + 0x10);

    fVar2 = *(float *)(param_1 + 0xa0) * *(float *)(unaff_ESI + 0x14);

    fVar3 = *(float *)(param_1 + 0xa4) * *(float *)(unaff_ESI + 0x18);

    unaff_EBX[7] = (uint)(SQRT(fVar2 * fVar2 + fVar3 * fVar3 + fVar1 * fVar1) *

                         *(float *)(unaff_ESI + 0x1c));

  }

  if ((*unaff_EBX & 3) != 0) {

    puVar4 = (uint *)FUN_00972fa0(unaff_ESI + 0x20);

    unaff_EBX[8] = *puVar4;

    unaff_EBX[9] = puVar4[1];

    unaff_EBX[10] = puVar4[2];

  }

  if ((*unaff_EBX & 7) != 0) {

    puVar4 = (uint *)FUN_00972f10(local_c,unaff_ESI + 0x2c);

    unaff_EBX[0xb] = *puVar4;

    unaff_EBX[0xc] = puVar4[1];

    unaff_EBX[0xd] = puVar4[2];

  }

  unaff_EBX[0xe] = *(uint *)(unaff_ESI + 0x38);

  unaff_EBX[0xf] = *(uint *)(unaff_ESI + 0x3c);

  unaff_EBX[0x10] = *(uint *)(unaff_ESI + 0x40);

  unaff_EBX[0x11] = *(uint *)(unaff_ESI + 0x44);

  unaff_EBX[0x12] = *(uint *)(unaff_ESI + 0x48);

  unaff_EBX[0x13] = *(uint *)(unaff_ESI + 0x4c);

  unaff_EBX[0x14] = *(uint *)(unaff_ESI + 0x50);

  unaff_EBX[0x15] = *(uint *)(unaff_ESI + 0x54);

  return;

}
