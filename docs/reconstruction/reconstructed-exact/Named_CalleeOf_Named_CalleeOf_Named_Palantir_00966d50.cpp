// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_Palantir_00966d50
// -----------------------------------------------------------------------------
// Stable ID: aa_00966d50
// Callee of Named_CalleeOf_Named_Palantir
// Address:   0x00966d50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_Palantir: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~64 non-empty decompiler lines.
//  - Control keywords: if×6, goto×1, return×1.
//  - Notable callees: FUN_0076c3c0×2, FUN_00966d50.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_Palantir
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

void Named_CalleeOf_Named_CalleeOf_Named_Palantir_00966d50(void)



{

  int *piVar1;

  void *pvVar2;

  int iVar3;

  int iVar4;

  uint32_t /* width from decompiler */ uVar5;

  int unaff_EDI;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  iVar3 = DAT_00d1f614;

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009aca50;

  pvStack_c = ExceptionList;

  pvVar2 = *(void **)(DAT_00d1f614 + 0xc4);

  ExceptionList = &pvStack_c;

  if (*(char *)(DAT_00d1f614 + 200) == '\0') {

    ExceptionList = &pvStack_c;

    iVar4 = FUN_0076c3c0();

    piVar1 = (int *)(iVar3 + 0x34 + *(int *)(iVar3 + 0xc4) * 4);

    *piVar1 = *piVar1 + (iVar4 - *(int *)(iVar3 + 0x30));

    *(int *)(iVar3 + 0x30) = iVar4;

    *(uint32_t /* width from decompiler */ *)(iVar3 + 0xc4) = 3;

  }

  local_4 = 0;

  if (*(char *)(unaff_EDI + 0x3d8) != '\0') {

    iVar4 = (**(code **)(**(int **)(unaff_EDI + 0x3d4) + 0x1c))

                      (*(int **)(unaff_EDI + 0x3d4),unaff_EDI + 0x3dc,0x160,0);

    if (-1 < iVar4) {

      *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x36c) = *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x500);

      *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x370) = *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x52c);

      *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x374) = *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x47c);

      *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x378) = *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x508);

      *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x37c) = *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x534);

      *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x380) = *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x484);

      *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x3b4) = *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x504);

      *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x3b8) = *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x530);

      *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x3bc) = *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x480);

      *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x3c0) = *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x50c);

      *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x3c4) = *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x538);

      *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x3c8) = *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x488);

    }

    *(uint8_t *)(unaff_EDI + 0x3d8) = 0;

    if (*(char *)(unaff_EDI + 0x3d8) != '\0') goto LAB_00966e9c;

  }

  piVar1 = *(int **)(unaff_EDI + 0x3d4);

  if (piVar1 != (int *)0x0) {

    (**(code **)(*piVar1 + 0x18))(piVar1,1);

    *(uint8_t *)(unaff_EDI + 0x3d8) = 1;

  }

LAB_00966e9c:

  uVar5 = (**(code **)(*(int *)*DAT_00d1f044 + 0x10))((int *)*DAT_00d1f044);

  *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x3cc) = uVar5;

  if (*(char *)(iVar3 + 200) == '\0') {

    iVar4 = FUN_0076c3c0();

    piVar1 = (int *)(iVar3 + 0x34 + *(int *)(iVar3 + 0xc4) * 4);

    *piVar1 = *piVar1 + (iVar4 - *(int *)(iVar3 + 0x30));

    *(int *)(iVar3 + 0x30) = iVar4;

    *(void **)(iVar3 + 0xc4) = pvVar2;

  }

  ExceptionList = pvVar2;

  return;

}
