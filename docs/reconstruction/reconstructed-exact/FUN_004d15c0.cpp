// =============================================================================
// FUN_004d15c0
// -----------------------------------------------------------------------------
// Stable ID: aa_004d15c0
// Address:   0x004d15c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004d15c0 @ 0x004d15c0
// Stable ID: aa_004d15c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~39 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_004b6240, FUN_004d15c0, FUN_0099bf90.
//  - Return sites: 2.

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

void FUN_004d15c0(void)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  void *pvVar3;

  void *unaff_ESI;

  uint32_t /* width from decompiler */ uVar4;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009a1fd6;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  (*(code *)PTR_FUN_00af43c0)();

  uVar4 = 0x20;

  iVar2 = (**(code **)(*DAT_00b05060 + 0x10))(0x20,0x13);

  *(uint16_t *)(iVar2 + 4) = 0x20;

  pvStack_c = (void *)0x0;

  uVar4 = FUN_0099bf90(uVar4,iVar2);

  puVar1 = DAT_00bc56d0;

  pvStack_c = (void *)0xffffffff;

  if ((DAT_00bc56d0 != (uint32_t /* width from decompiler */ *)0x0) &&

     (*(short *)((int)DAT_00bc56d0 + 6) = *(short *)((int)DAT_00bc56d0 + 6) + -1,

     *(short *)((int)puVar1 + 6) == 0)) {

    (**(code **)*puVar1)(1);

  }

  DAT_00bc56d0 = (uint32_t /* width from decompiler */ *)uVar4;

  pvVar3 = operator_new(0x1c);

  pvStack_c = (void *)0x1;

  if (pvVar3 != (void *)0x0) {

    DAT_00b037f0 = FUN_004b6240(pvVar3);

    ExceptionList = unaff_ESI;

    return;

  }

  DAT_00b037f0 = 0;

  ExceptionList = unaff_ESI;

  return;

}
