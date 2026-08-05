// =============================================================================
// FUN_0041c660
// -----------------------------------------------------------------------------
// Stable ID: aa_0041c660
// Address:   0x0041c660  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0041c660 @ 0x0041c660
// Stable ID: aa_0041c660
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~52 non-empty decompiler lines.
//  - Control keywords: if×8, return×3, while×1.
//  - Notable callees: FUN_00415b30, FUN_0041c660.
//  - Return sites: 3.

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

uint32_t /* width from decompiler */ FUN_0041c660(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ *param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  char cVar2;

  uint in_EAX;

  int unaff_EDI;

  

  if (param_2 != (uint32_t /* width from decompiler */ *)0x0) {

    *param_2 = 0;

  }

  puVar1 = *(uint32_t /* width from decompiler */ **)

            (*(int *)(*(int *)(unaff_EDI + 0x10) + (*(uint *)(unaff_EDI + 8) & in_EAX) * 4) + 4);

  while( true ) {

    if (puVar1 == (uint32_t /* width from decompiler */ *)0x0) {

      return 0x80004005;

    }

    if (*(code **)(unaff_EDI + 0x34) == (code *)0x0) {

      cVar2 = in_EAX == puVar1[4];

    }

    else {

      cVar2 = (**(code **)(unaff_EDI + 0x34))(puVar1[2],param_1);

    }

    if (cVar2 != '\0') break;

    puVar1 = (uint32_t /* width from decompiler */ *)puVar1[3];

  }

  FUN_00415b30();

  if (param_2 != (uint32_t /* width from decompiler */ *)0x0) {

    *param_2 = puVar1[2];

  }

  puVar1[2] = 0;

  if (puVar1 == *(uint32_t /* width from decompiler */ **)(unaff_EDI + 0x14)) {

    *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x14) = puVar1[5];

  }

  else {

    *(uint32_t /* width from decompiler */ *)(puVar1[6] + 0x14) = puVar1[5];

  }

  if (puVar1 == *(uint32_t /* width from decompiler */ **)(unaff_EDI + 0x18)) {

    *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x18) = puVar1[6];

  }

  else {

    *(uint32_t /* width from decompiler */ *)(puVar1[5] + 0x18) = puVar1[6];

  }

  *puVar1 = &PTR_FUN_00a86174;

  if ((void *)puVar1[2] == (void *)0x0) {

    puVar1[2] = 0;

    *puVar1 = *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x20);

    *(uint32_t /* width from decompiler */ **)(unaff_EDI + 0x20) = puVar1;

    *(int *)(unaff_EDI + 0xc) = *(int *)(unaff_EDI + 0xc) + -1;

    return 0;

  }

                    /* WARNING: Subroutine does not return */

  operator_delete((void *)puVar1[2]);

}
