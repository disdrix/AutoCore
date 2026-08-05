// =============================================================================
// FUN_008574c0
// -----------------------------------------------------------------------------
// Stable ID: aa_008574c0
// Address:   0x008574c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008574c0 @ 0x008574c0
// Stable ID: aa_008574c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_008574c0.
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

void FUN_008574c0(void)



{

  float fVar1;

  float fVar2;

  int iVar3;

  float *unaff_EBX;

  int *unaff_ESI;

  int *unaff_EDI;

  float fVar4;

  float fVar5;

  float local_c;

  uint8_t local_8 [8];

  

  local_c = DAT_00af931c;

  if (DAT_00af9320 <= DAT_00af931c) {

    local_c = DAT_00af9320;

  }

  (**(code **)(*unaff_ESI + 0x140))();

  fVar5 = (float)((int)((*unaff_EBX / (float)local_8) * (float)(int)((float)unaff_ESI[0x141] * 1.0))

                 - unaff_ESI[0x15a]);

  fVar4 = (float)((int)((unaff_EBX[2] / (float)local_8) *

                       (float)(int)((float)(int)local_c * (float)unaff_ESI[0x141])) -

                 unaff_ESI[0x15b]);

  fVar1 = (float)unaff_ESI[0x16f];

  fVar2 = (float)unaff_ESI[0x171];

  iVar3 = unaff_ESI[0x15c];

  unaff_EDI[1] = (int)(fVar5 * (float)unaff_ESI[0x16f] + (float)unaff_ESI[0x171] * fVar4) +

                 unaff_ESI[0x15d];

  *unaff_EDI = (int)(fVar4 * fVar1 - fVar2 * fVar5) + iVar3;

  return;

}
