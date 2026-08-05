// =============================================================================
// FUN_00933b70
// -----------------------------------------------------------------------------
// Stable ID: aa_00933b70
// Address:   0x00933b70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00933b70 @ 0x00933b70
// Stable ID: aa_00933b70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~108 non-empty decompiler lines.
//  - Control keywords: if×18, return×10.
//  - Notable callees: FUN_007829b0×2, FUN_00782b00×2, FUN_004c2690, FUN_004cd600, FUN_005742f0, FUN_0092a600, FUN_00933b70, FUN_00980890.
//  - Return sites: 10.

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

void FUN_00933b70(void)



{

  uint32_t /* width from decompiler */ *puVar1;

  void *pvVar2;

  void *pvVar3;

  int unaff_ESI;

  bool bVar4;

  

  if (*(uint32_t /* width from decompiler */ **)(unaff_ESI + 0x4f4) != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)**(uint32_t /* width from decompiler */ **)(unaff_ESI + 0x4f4))(1);

  }

  puVar1 = *(uint32_t /* width from decompiler */ **)(unaff_ESI + 0x3088);

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x4f4) = 0;

  if (puVar1 != (uint32_t /* width from decompiler */ *)0x0) {

    FUN_00782b00();

    pvVar2 = (void *)*puVar1;

    if (pvVar2 != (void *)0x0) {

      FUN_007829b0();

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar2);

    }

                    /* WARNING: Subroutine does not return */

    operator_delete(puVar1);

  }

  puVar1 = *(uint32_t /* width from decompiler */ **)(unaff_ESI + 0x308c);

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x3088) = 0;

  if (puVar1 != (uint32_t /* width from decompiler */ *)0x0) {

    FUN_00782b00();

    pvVar2 = (void *)*puVar1;

    if (pvVar2 != (void *)0x0) {

      FUN_007829b0();

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar2);

    }

                    /* WARNING: Subroutine does not return */

    operator_delete(puVar1);

  }

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x308c) = 0;

  FUN_004cd600();

  pvVar2 = *(void **)(unaff_ESI + 0x31ec);

  if (pvVar2 != (void *)0x0) {

    FUN_005742f0();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar2);

  }

  pvVar2 = *(void **)(unaff_ESI + 0x31f0);

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x31ec) = 0;

  if (pvVar2 != (void *)0x0) {

    FUN_004c2690();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar2);

  }

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x31f0) = 0;

  if (*(uint32_t /* width from decompiler */ **)(unaff_ESI + 0xdec) != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)**(uint32_t /* width from decompiler */ **)(unaff_ESI + 0xdec))(1);

  }

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xdec) = 0;

  if (*(uint32_t /* width from decompiler */ **)(unaff_ESI + 0xe0c) != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)**(uint32_t /* width from decompiler */ **)(unaff_ESI + 0xe0c))(1);

  }

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xe0c) = 0;

  if (*(uint32_t /* width from decompiler */ **)(unaff_ESI + 0xd34) != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)**(uint32_t /* width from decompiler */ **)(unaff_ESI + 0xd34))(1);

  }

  pvVar2 = DAT_00d09874;

  bVar4 = DAT_00d09874 != (void *)0x0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xd34) = 0;

  if (bVar4) {

    pvVar3 = *(void **)((int)pvVar2 + 0x18);

    if (pvVar3 != (void *)0x0) {

      operator_delete__(pvVar3);

    }

    *(uint32_t /* width from decompiler */ *)((int)pvVar2 + 0x18) = 0;

    if (*(FILE **)((int)pvVar2 + 0x23c) != (FILE *)0x0) {

      fclose(*(FILE **)((int)pvVar2 + 0x23c));

      *(uint32_t /* width from decompiler */ *)((int)pvVar2 + 0x23c) = 0;

    }

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar2);

  }

  DAT_00d09874 = (void *)0x0;

  if (*(uint32_t /* width from decompiler */ **)(unaff_ESI + 0xd38) != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)**(uint32_t /* width from decompiler */ **)(unaff_ESI + 0xd38))(1);

  }

  pvVar2 = *(void **)(unaff_ESI + 0x4d0);

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xd38) = 0;

  if (pvVar2 != (void *)0x0) {

    FUN_0092a600(pvVar2);

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar2);

  }

  pvVar2 = *(void **)(unaff_ESI + 0x4ec);

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x4d0) = 0;

  if (pvVar2 != (void *)0x0) {

    FUN_00980890(pvVar2);

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar2);

  }

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x4ec) = 0;

  if (*(uint32_t /* width from decompiler */ **)(unaff_ESI + 0x4f0) != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)**(uint32_t /* width from decompiler */ **)(unaff_ESI + 0x4f0))(1);

  }

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x4f0) = 0;

  if (*(void **)(unaff_ESI + 0xc6c) != (void *)0x0) {

    operator_delete__(*(void **)(unaff_ESI + 0xc6c));

  }

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xc6c) = 0;

  return;

}
