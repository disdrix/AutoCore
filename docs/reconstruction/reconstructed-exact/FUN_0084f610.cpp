// =============================================================================
// FUN_0084f610
// -----------------------------------------------------------------------------
// Stable ID: aa_0084f610
// Address:   0x0084f610  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0084f610 @ 0x0084f610
// Stable ID: aa_0084f610
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~51 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_0084f610.
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

int * FUN_0084f610(void)



{

  float fVar1;

  float fVar2;

  int iVar3;

  int iVar4;

  float *in_EAX;

  float unaff_EBX;

  int iVar5;

  float unaff_EBP;

  int iVar6;

  int *unaff_ESI;

  int local_10;

  int local_c;

  uint8_t local_8 [4];

  int *piStack_4;

  

  iVar5 = DAT_00af932c;

  iVar3 = DAT_00af9328;

  local_c = DAT_00af9328;

  local_10 = DAT_00af932c;

  (**(code **)(*unaff_ESI + 0x140))(local_8,1);

  if (unaff_EBP <= unaff_EBX) {

    if (unaff_EBP < unaff_EBX) {

      local_c = (int)(((float)iVar3 / unaff_EBX) * unaff_EBP);

    }

  }

  else {

    local_10 = (int)(((float)iVar5 / unaff_EBP) * unaff_EBX);

  }

  fVar1 = (float)unaff_ESI[0x141];

  fVar2 = *in_EAX;

  iVar3 = unaff_ESI[0x15a];

  iVar6 = 0;

  iVar5 = 0;

  if (unaff_EBP <= unaff_EBX) {

    if (unaff_EBP < unaff_EBX) {

      iVar5 = -((int)((float)local_c * (float)unaff_ESI[0x141]) / 2);

    }

  }

  else {

    iVar6 = (int)((float)local_10 * fVar1) / 2;

  }

  iVar4 = unaff_ESI[0x15c];

  piStack_4[1] = (unaff_ESI[0x15d] -

                 ((int)((in_EAX[2] / unaff_EBP) *

                       (float)(int)((float)local_c * (float)unaff_ESI[0x141])) - unaff_ESI[0x15b]))

                 + iVar5;

  *piStack_4 = iVar4 + iVar6 +

               ((int)((fVar2 / unaff_EBX) * (float)(int)((float)local_10 * fVar1)) - iVar3);

  return piStack_4;

}
