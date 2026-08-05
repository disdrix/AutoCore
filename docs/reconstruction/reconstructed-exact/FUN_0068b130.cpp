// =============================================================================
// FUN_0068b130
// -----------------------------------------------------------------------------
// Stable ID: aa_0068b130
// Address:   0x0068b130  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0068b130 @ 0x0068b130
// Stable ID: aa_0068b130
// Embedded strings (evidence for future rename):
//   - "DeleteTransientData() called with no intact transient data"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~70 non-empty decompiler lines.
//  - Control keywords: if×8, return×5, for×2.
//  - Notable callees: memmove×2, DeleteTransientData, FUN_0068b130, FUN_0068e080, FUN_00698280, FUN_006a1360.
//  - Strings: "DeleteTransientData() called with no intact transient data".
//  - Return sites: 5.

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

void __fastcall FUN_0068b130(int *param_1)



{

  int iVar1;

  void *pvVar2;

  uint32_t /* width from decompiler */ *puVar3;

  

  puVar3 = DAT_00d08e98;

  if (param_1[0xd] == 0) {

    for (; puVar3 != DAT_00d08e9c; puVar3 = puVar3 + 1) {

      if ((int *)*puVar3 == param_1) {

        if (puVar3 != DAT_00d08e9c) {

          memmove(puVar3,puVar3 + 1,((int)DAT_00d08e9c - (int)(puVar3 + 1) >> 2) << 2);

          DAT_00d08e9c = DAT_00d08e9c + -1;

        }

        break;

      }

    }

  }

  *(int *)param_1[0xc] = *(int *)param_1[0xc] + -1;

  if (param_1[0xd] != 0) {

    iVar1 = param_1[0xe];

    for (puVar3 = *(uint32_t /* width from decompiler */ **)(iVar1 + 4);

        (puVar3 != *(uint32_t /* width from decompiler */ **)(iVar1 + 8) && ((int *)*puVar3 != param_1)); puVar3 = puVar3 + 1)

    {

    }

    memmove(puVar3,puVar3 + 1,(*(int *)(iVar1 + 8) - (int)(puVar3 + 1) >> 2) << 2);

    *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + -4;

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[0xd]);

  }

  if (*(int *)param_1[0xc] != 0) {

    param_1[1] = 0;

    param_1[3] = 0;

    param_1[4] = 0;

    param_1[2] = 0;

    param_1[5] = 0;

    *param_1 = 0;

    param_1[0xc] = 0;

    param_1[0x10] = 0;

    param_1[0xe] = 0;

    param_1[0x15] = 0;

    param_1[0x13] = 0;

    param_1[0x16] = 0;

    param_1[0x17] = 0;

    param_1[0xb] = 0;

    param_1[0x14] = 0;

    param_1[0x19] = 0;

    DAT_00d08e58 = DAT_00d08e58 + -1;

    if (DAT_00d08e58 != 0) {

      return;

    }

    FUN_006a1360();

    return;

  }

  if (*(char *)(*param_1 + 0x21) == '\0') {

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator=

              ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

               &DAT_00d08e78,"DeleteTransientData() called with no intact transient data");

  }

  else {

    FUN_00698280();

  }

  pvVar2 = (void *)param_1[1];

  if (pvVar2 == (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[3]);

  }

  FUN_0068e080();

                    /* WARNING: Subroutine does not return */

  operator_delete(pvVar2);

}
