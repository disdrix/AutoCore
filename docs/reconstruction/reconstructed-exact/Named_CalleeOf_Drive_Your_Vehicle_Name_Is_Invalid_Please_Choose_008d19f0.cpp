// =============================================================================
// Named_CalleeOf_Drive_Your_Vehicle_Name_Is_Invalid_Please_Choose_008d19f0
// -----------------------------------------------------------------------------
// Stable ID: aa_008d19f0
// Callee of Drive_Your_Vehicle_Name_Is_Invalid_Please_Choose_Anoth
// Address:   0x008d19f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Drive_Your_Vehicle_Name_Is_Invalid_Please_Choose: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~60 non-empty decompiler lines.
//  - Control keywords: if×6, return×1.
//  - Notable callees: CNDHash_LookupByKey×2, FUN_00523430×2, FUN_00410050, FUN_008cf310, FUN_008d1890, FUN_008d19f0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Drive_Your_Vehicle_Name_Is_Invalid_Please_Choose_Anoth
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

void Named_CalleeOf_Drive_Your_Vehicle_Name_Is_Invalid_Please_Choose_008d19f0(void)



{

  int iVar1;

  int unaff_ESI;

  uint32_t /* width from decompiler */ uStack_2c;

  uint32_t /* width from decompiler */ uStack_28;

  void *pvStack_24;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ad294;

  local_c = ExceptionList;

  if ((*(int *)(unaff_ESI + 0x890) != 0) &&

     (*(int *)(unaff_ESI + 0x894) - *(int *)(unaff_ESI + 0x890) >> 2 != 0)) {

    iVar1 = *(int *)(*(int *)(unaff_ESI + 0x890) + *(int *)(unaff_ESI + 0x810) * 4);

    if ((iVar1 == 0) || (*(int *)(iVar1 + 0x94) == 0)) {

      ExceptionList = &local_c;

      if (*(char *)(unaff_ESI + 0x598) != '\0') {

        ExceptionList = &local_c;

        *(uint8_t *)(unaff_ESI + 0x598) = 0;

        pvStack_24 = (void *)0x8d1adc;

        pvStack_24 = CNDHash_LookupByKey(*(void **)(*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(

                                                  unaff_ESI + 0x544) + 4) + 4) + 0xac +

                                                  *(int *)(unaff_ESI + 0x544)) + 0x3c) + 0x544),

                                         *(uint *)(unaff_ESI + 0x59c));

        if (pvStack_24 != (void *)0x0) {

          uStack_28 = 1;

          uStack_2c = 0x8d1aeb;

          FUN_00523430();

          FUN_00410050(&uStack_2c);

          local_4 = 0xffffffff;

          FUN_008d1890(0,0);

        }

      }

    }

    else {

      ExceptionList = &local_c;

      if (*(char *)(unaff_ESI + 0x598) == '\0') {

        ExceptionList = &local_c;

        *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x59c) = *(uint32_t /* width from decompiler */ *)(*(int *)(unaff_ESI + 0x544) + 0x700);

      }

      *(uint8_t *)(unaff_ESI + 0x598) = 1;

      pvStack_24 = (void *)0x8d1a91;

      pvStack_24 = CNDHash_LookupByKey(*(void **)(*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(

                                                  unaff_ESI + 0x544) + 4) + 4) + 0xac +

                                                  *(int *)(unaff_ESI + 0x544)) + 0x3c) + 0x544),

                                       0xffffffff);

      if (pvStack_24 != (void *)0x0) {

        uStack_28 = 1;

        uStack_2c = 0x8d1aa0;

        FUN_00523430();

      }

    }

    pvStack_24 = (void *)0x8d1b2e;

    FUN_008cf310();

  }

  ExceptionList = local_c;

  return;

}
