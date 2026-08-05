// =============================================================================
// Named_CalleeOf_Drive_SIZE_VEHICLES_0084fd60
// -----------------------------------------------------------------------------
// Stable ID: aa_0084fd60
// Callee of Drive_SIZE_VEHICLES
// Address:   0x0084fd60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Drive_SIZE_VEHICLES: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_0084fd60.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Drive_SIZE_VEHICLES
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void Named_CalleeOf_Drive_SIZE_VEHICLES_0084fd60(void)



{

  float fVar1;

  float fVar2;

  int in_EAX;

  float in_XMM0_Da;

  float fVar3;

  

  fVar2 = DAT_00aaa8dc;

  fVar1 = g_flOne;

  *(float *)(in_EAX + 0x504) = in_XMM0_Da;

  if (in_XMM0_Da <= fVar2) {

    if (in_XMM0_Da < fVar1) {

      *(float *)(in_EAX + 0x504) = fVar1;

    }

  }

  else {

    *(float *)(in_EAX + 0x504) = fVar2;

  }

  fVar2 = DAT_00af9328;

  _DAT_00af9330 = fVar1 / *(float *)(in_EAX + 0x504);

  *(float *)(in_EAX + 0x50c) = *(float *)(in_EAX + 0x508) * _DAT_00af9330;

  fVar3 = DAT_00af932c;

  if (fVar2 < DAT_00af932c) {

    fVar3 = fVar2;

  }

  _DAT_00af9330 = fVar3 * DAT_00a0f298 * _DAT_00af9330;

  if (_DAT_00af9330 < fVar1) {

    _DAT_00af9330 = fVar1;

  }

  return;

}
