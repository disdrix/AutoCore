// =============================================================================
// FUN_0044b6e0
// -----------------------------------------------------------------------------
// Stable ID: aa_0044b6e0
// Address:   0x0044b6e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0044b6e0 @ 0x0044b6e0
// Stable ID: aa_0044b6e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0044b6e0, FUN_009728e0, FUN_009730e0, FUN_009732d0, SQRT.
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

void FUN_0044b6e0(void)



{

  float *pfVar1;

  float fVar2;

  int in_EAX;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ *unaff_EBX;

  uint32_t /* width from decompiler */ *unaff_EDI;

  float fVar4;

  float local_c;

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  puVar3 = (uint32_t /* width from decompiler */ *)FUN_009732d0(&local_c,unaff_EDI + 1);

  unaff_EBX[1] = *puVar3;

  unaff_EBX[2] = puVar3[1];

  unaff_EBX[3] = puVar3[2];

  if ((*(uint *)(in_EAX + 0xbc) >> 1 & 1) != 0) {

    FUN_009730e0();

  }

  FUN_009728e0(&local_c);

  pfVar1 = (float *)(unaff_EBX + 4);

  *pfVar1 = local_c;

  unaff_EBX[5] = local_8;

  unaff_EBX[6] = local_4;

  *unaff_EBX = *unaff_EDI;

  fVar2 = SQRT((float)unaff_EBX[6] * (float)unaff_EBX[6] +

               (float)unaff_EBX[5] * (float)unaff_EBX[5] + *pfVar1 * *pfVar1);

  fVar4 = g_flOne / fVar2;

  *pfVar1 = fVar4 * *pfVar1;

  unaff_EBX[5] = (float)unaff_EBX[5] * fVar4;

  unaff_EBX[6] = (float)unaff_EBX[6] * fVar4;

  unaff_EBX[7] = fVar2 * (float)unaff_EDI[7];

  return;

}
