// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0069bb40
// -----------------------------------------------------------------------------
// Stable ID: aa_0069bb40
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x0069bb40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~76 non-empty decompiler lines.
//  - Control keywords: if×8, return×3, do×1, goto×1, while×1.
//  - Notable callees: FUN_004073a0×3, FUN_0069bb40.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0069bb40(void)



{

  int *piVar1;

  int local_10;

  uint local_c;

  int local_8;

  int local_4;

  

  if (DAT_00d08f04 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(DAT_00d08f04);

  }

  DAT_00d08f04 = (void *)0x0;

  DAT_00d08f08 = (int *)0x0;

  DAT_00d08f0c = 0;

  if (DAT_00d08ee0 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(DAT_00d08ee0);

  }

  DAT_00d08ee0 = (void *)0x0;

  DAT_00d08ee4 = (int *)0x0;

  DAT_00d08ee8 = 0;

  local_c = 0;

  local_10 = 0;

  local_8 = 0;

  do {

    if ((*(int *)(DAT_00d08ebc + 0x10) == 0) ||

       ((uint)((*(int *)(DAT_00d08ebc + 0x14) - *(int *)(DAT_00d08ebc + 0x10)) / 0x54) <= local_c))

    {

      return;

    }

    local_4 = local_10;

    if (*(char *)(local_8 + *(int *)(DAT_00d08ebc + 0x10)) == '\0') {

      if ((DAT_00d08ee0 == (void *)0x0) ||

         ((uint)(DAT_00d08ee8 - (int)DAT_00d08ee0 >> 2) <=

          (uint)((int)DAT_00d08ee4 - (int)DAT_00d08ee0 >> 2))) {

        FUN_004073a0(DAT_00d08ee4,1,&local_4);

      }

      else {

        *DAT_00d08ee4 = local_10;

        DAT_00d08ee4 = DAT_00d08ee4 + 1;

      }

      piVar1 = DAT_00d08ee4;

      if ((DAT_00d08ee0 == (void *)0x0) ||

         ((uint)(DAT_00d08ee8 - (int)DAT_00d08ee0 >> 2) <=

          (uint)((int)DAT_00d08ee4 - (int)DAT_00d08ee0 >> 2))) goto LAB_0069bcfc;

      *DAT_00d08ee4 = local_10 + 1;

      DAT_00d08ee4 = DAT_00d08ee4 + 1;

    }

    else {

      if ((DAT_00d08f04 == (void *)0x0) ||

         ((uint)(DAT_00d08f0c - (int)DAT_00d08f04 >> 2) <=

          (uint)((int)DAT_00d08f08 - (int)DAT_00d08f04 >> 2))) {

        FUN_004073a0(DAT_00d08f08,1,&local_4);

      }

      else {

        *DAT_00d08f08 = local_10;

        DAT_00d08f08 = DAT_00d08f08 + 1;

      }

      piVar1 = DAT_00d08f08;

      if ((DAT_00d08f04 == (void *)0x0) ||

         ((uint)(DAT_00d08f0c - (int)DAT_00d08f04 >> 2) <=

          (uint)((int)DAT_00d08f08 - (int)DAT_00d08f04 >> 2))) {

LAB_0069bcfc:

        local_4 = local_10 + 1;

        FUN_004073a0(piVar1,1,&local_4);

      }

      else {

        *DAT_00d08f08 = local_10 + 1;

        DAT_00d08f08 = DAT_00d08f08 + 1;

      }

    }

    local_c = local_c + 1;

    local_8 = local_8 + 0x54;

    local_10 = local_10 + 2;

  } while( true );

}
