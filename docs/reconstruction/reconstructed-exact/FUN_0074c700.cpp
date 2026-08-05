// =============================================================================
// FUN_0074c700
// -----------------------------------------------------------------------------
// Stable ID: aa_0074c700
// Address:   0x0074c700  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0074c700 @ 0x0074c700
// Stable ID: aa_0074c700
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~45 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: SQRT×2, FUN_0074c700, FUN_0076f5f0, FUN_009728e0, FUN_009730e0, FUN_009732d0.
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

uint32_t /* width from decompiler */ FUN_0074c700(uint32_t /* width from decompiler */ param_1,float *param_2)



{

  uint32_t /* width from decompiler */ in_EAX;

  float *unaff_EBX;

  int unaff_EDI;

  float fVar1;

  float fVar2;

  float fVar3;

  float local_24;

  float local_20;

  float local_1c;

  float local_18;

  float local_14;

  float local_10;

  float local_c;

  float local_8;

  float local_4;

  

  FUN_009732d0(&local_c,in_EAX);

  if ((*(uint *)(unaff_EDI + 0xbc) >> 1 & 1) != 0) {

    FUN_009730e0();

  }

  FUN_009728e0(&local_18);

  local_24 = local_18;

  local_20 = local_14;

  local_1c = local_10;

  FUN_0076f5f0(&local_24,&local_24);

  local_8 = unaff_EBX[1] - local_8;

  local_4 = unaff_EBX[2] - local_4;

  local_c = *unaff_EBX - local_c;

  fVar2 = local_4 * local_4 + local_8 * local_8 + local_c * local_c;

  fVar3 = unaff_EBX[3] * unaff_EBX[3];

  fVar1 = local_4 * local_1c + local_8 * local_20 + local_c * local_24;

  if (((fVar2 < fVar3) || (0.0 <= fVar1)) && (fVar3 = fVar3 - (fVar2 - fVar1 * fVar1), 0.0 <= fVar3)

     ) {

    if (param_2 != (float *)0x0) {

      fVar1 = fVar1 - SQRT(fVar3);

      fVar2 = *(float *)(unaff_EDI + 0x9c) * local_24 * fVar1;

      fVar3 = *(float *)(unaff_EDI + 0xa0) * local_20 * fVar1;

      fVar1 = *(float *)(unaff_EDI + 0xa4) * local_1c * fVar1;

      *param_2 = SQRT(fVar2 * fVar2 + fVar3 * fVar3 + fVar1 * fVar1);

    }

    return 1;

  }

  return 0;

}
