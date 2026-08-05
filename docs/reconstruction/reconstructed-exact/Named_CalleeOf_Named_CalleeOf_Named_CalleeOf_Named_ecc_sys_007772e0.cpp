// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_ecc_sys_007772e0
// -----------------------------------------------------------------------------
// Stable ID: aa_007772e0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_ecc_sys
// Address:   0x007772e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_ecc_sys: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~48 non-empty decompiler lines.
//  - Control keywords: if×9, return×7.
//  - Notable callees: FUN_00770440×2, FUN_00772250×2, FUN_00776c60×2, FUN_007772e0×2, FUN_007702e0, FUN_007705b0, FUN_007707d0, FUN_00770970.
//  - Return sites: 7.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_ecc_sys
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

int Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_ecc_sys_007772e0(uint32_t /* width from decompiler */ param_1,int param_2,int *param_3,uint32_t /* width from decompiler */ param_4)



{

  int iVar1;

  uint8_t local_20 [16];

  uint8_t local_10 [16];

  

  if (param_3[2] == 1) {

    return -3;

  }

  if (*(int *)(param_2 + 8) == 1) {

    iVar1 = FUN_00770440();

    if (iVar1 == 0) {

      iVar1 = FUN_00776560();

      if (iVar1 == 0) {

        iVar1 = FUN_00770440();

        if (iVar1 == 0) {

          iVar1 = FUN_00770970();

          if (iVar1 != 0) {

            FUN_00772250(local_20,local_10,0);

            return iVar1;

          }

          iVar1 = Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_ecc_sys_007772e0(local_20,local_10,param_3,param_4);

          FUN_00772250(local_20,local_10,0);

          return iVar1;

        }

      }

      FUN_007707d0();

      return iVar1;

    }

  }

  else {

    iVar1 = FUN_007702e0();

    if (iVar1 == 1) {

      iVar1 = FUN_00776c60(param_1,param_2,param_3,param_4,1);

      return iVar1;

    }

    iVar1 = FUN_007705b0();

    if (iVar1 == 0) {

      iVar1 = FUN_00771760();

      iVar1 = iVar1 * 2;

    }

    if (((*param_3 < 1) || ((*(byte *)param_3[3] & 1) == 0)) && (iVar1 == 0)) {

      iVar1 = FUN_00776c60(param_1,param_2,param_3,param_4,0);

      return iVar1;

    }

    iVar1 = FUN_007765a0(param_1,param_2,param_3,param_4,iVar1);

  }

  return iVar1;

}
