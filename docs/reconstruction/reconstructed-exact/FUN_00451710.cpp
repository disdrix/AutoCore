// =============================================================================
// FUN_00451710
// -----------------------------------------------------------------------------
// Stable ID: aa_00451710
// Address:   0x00451710  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00451710 @ 0x00451710
// Stable ID: aa_00451710
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~39 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00451710, FUN_004527d0, FUN_00453030, FUN_004544c0.
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

int FUN_00451710(int param_1)



{

  int iVar1;

  int *piVar2;

  float *unaff_ESI;

  uint8_t local_d4 [4];

  float local_d0;

  float local_cc;

  float local_c8;

  float local_c4;

  float local_c0;

  float local_bc;

  

  iVar1 = FUN_004544c0();

  if (((iVar1 == *(int *)(param_1 + 4)) ||

      (*unaff_ESI <= *(float *)(iVar1 + 0xc) && *(float *)(iVar1 + 0xc) != *unaff_ESI)) ||

     ((*unaff_ESI < *(float *)(iVar1 + 0xc) || *unaff_ESI == *(float *)(iVar1 + 0xc) &&

      ((unaff_ESI[1] <= *(float *)(iVar1 + 0x10) && *(float *)(iVar1 + 0x10) != unaff_ESI[1] ||

       ((unaff_ESI[1] < *(float *)(iVar1 + 0x10) || unaff_ESI[1] == *(float *)(iVar1 + 0x10) &&

        ((unaff_ESI[2] <= *(float *)(iVar1 + 0x14) && *(float *)(iVar1 + 0x14) != unaff_ESI[2] ||

         ((unaff_ESI[2] < *(float *)(iVar1 + 0x14) || unaff_ESI[2] == *(float *)(iVar1 + 0x14) &&

          ((unaff_ESI[3] <= *(float *)(iVar1 + 0x18) && *(float *)(iVar1 + 0x18) != unaff_ESI[3] ||

           ((unaff_ESI[3] < *(float *)(iVar1 + 0x18) || unaff_ESI[3] == *(float *)(iVar1 + 0x18) &&

            ((unaff_ESI[4] <= *(float *)(iVar1 + 0x1c) && *(float *)(iVar1 + 0x1c) != unaff_ESI[4]

             || ((unaff_ESI[4] < *(float *)(iVar1 + 0x1c) ||

                  unaff_ESI[4] == *(float *)(iVar1 + 0x1c) &&

                 (unaff_ESI[5] <= *(float *)(iVar1 + 0x20) &&

                  *(float *)(iVar1 + 0x20) != unaff_ESI[5])))))))))))))))))))) {

    local_d0 = *unaff_ESI;

    local_cc = unaff_ESI[1];

    local_c8 = unaff_ESI[2];

    local_c4 = unaff_ESI[3];

    local_c0 = unaff_ESI[4];

    local_bc = unaff_ESI[5];

    FUN_00453030();

    piVar2 = (int *)FUN_004527d0(local_d4,iVar1);

    iVar1 = *piVar2;

  }

  return iVar1 + 0x24;

}
