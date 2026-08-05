// =============================================================================
// FUN_006f0d10
// -----------------------------------------------------------------------------
// Stable ID: aa_006f0d10
// Address:   0x006f0d10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006f0d10 @ 0x006f0d10
// Stable ID: aa_006f0d10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~57 non-empty decompiler lines.
//  - Control keywords: if×8, return×2.
//  - Notable callees: FUN_005d68f0, FUN_006f0d10.
//  - Return sites: 2.

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

void __thiscall FUN_006f0d10(float *param_1,uint32_t /* width from decompiler */ param_2)



{

  float fVar1;

  float *in_EAX;

  float *unaff_ESI;

  float local_30;

  float local_2c;

  float local_28;

  float local_24;

  float local_20;

  float local_1c;

  float local_18;

  uint32_t /* width from decompiler */ local_14;

  

  local_14 = 0;

  local_20 = *param_1 * *in_EAX;

  local_1c = param_1[1] * in_EAX[1];

  local_18 = param_1[2] * in_EAX[2];

  FUN_005d68f0(param_2,&local_20);

  fVar1 = local_30;

  if (*unaff_ESI < local_30) {

    fVar1 = *unaff_ESI;

  }

  *unaff_ESI = fVar1;

  fVar1 = local_2c;

  if (unaff_ESI[1] < local_2c) {

    fVar1 = unaff_ESI[1];

  }

  unaff_ESI[1] = fVar1;

  fVar1 = local_28;

  if (unaff_ESI[2] < local_28) {

    fVar1 = unaff_ESI[2];

  }

  unaff_ESI[2] = fVar1;

  fVar1 = local_24;

  if (unaff_ESI[3] < local_24) {

    fVar1 = unaff_ESI[3];

  }

  unaff_ESI[3] = fVar1;

  if (local_30 < unaff_ESI[4]) {

    local_30 = unaff_ESI[4];

  }

  unaff_ESI[4] = local_30;

  if (local_2c < unaff_ESI[5]) {

    local_2c = unaff_ESI[5];

  }

  unaff_ESI[5] = local_2c;

  if (local_28 < unaff_ESI[6]) {

    local_28 = unaff_ESI[6];

  }

  unaff_ESI[6] = local_28;

  if (unaff_ESI[7] <= local_24) {

    unaff_ESI[7] = local_24;

    return;

  }

  unaff_ESI[7] = unaff_ESI[7];

  return;

}
