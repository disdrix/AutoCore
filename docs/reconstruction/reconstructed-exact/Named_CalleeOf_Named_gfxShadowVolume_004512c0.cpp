// =============================================================================
// Named_CalleeOf_Named_gfxShadowVolume_004512c0
// -----------------------------------------------------------------------------
// Stable ID: aa_004512c0
// Callee of Named_gfxShadowVolume
// Address:   0x004512c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxShadowVolume: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~54 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_004512c0, FUN_004524a0, FUN_00453d40.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_gfxShadowVolume
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

int Named_CalleeOf_Named_gfxShadowVolume_004512c0(void)



{

  int iVar1;

  int *piVar2;

  float *unaff_ESI;

  int unaff_EDI;

  uint8_t local_44 [4];

  uint32_t /* width from decompiler */ local_40;

  uint32_t /* width from decompiler */ local_3c;

  uint32_t /* width from decompiler */ local_38;

  uint32_t /* width from decompiler */ local_34;

  uint32_t /* width from decompiler */ local_30;

  float local_2c;

  float local_28;

  float local_24;

  float local_20;

  float local_1c;

  float local_18;

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ local_10;

  uint32_t /* width from decompiler */ local_c;

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  iVar1 = FUN_00453d40();

  if (((iVar1 == *(int *)(unaff_EDI + 4)) ||

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

    local_2c = *unaff_ESI;

    local_28 = unaff_ESI[1];

    local_24 = unaff_ESI[2];

    local_20 = unaff_ESI[3];

    local_1c = unaff_ESI[4];

    local_18 = unaff_ESI[5];

    local_14 = local_40;

    local_10 = local_3c;

    local_8 = local_34;

    local_c = local_38;

    local_4 = local_30;

    piVar2 = (int *)FUN_004524a0(local_44,iVar1);

    iVar1 = *piVar2;

  }

  return iVar1 + 0x24;

}
