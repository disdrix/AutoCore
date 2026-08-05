// =============================================================================
// FUN_007ad9c0
// -----------------------------------------------------------------------------
// Stable ID: aa_007ad9c0
// Address:   0x007ad9c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007ad9c0 @ 0x007ad9c0
// Stable ID: aa_007ad9c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~62 non-empty decompiler lines.
//  - Control keywords: if×2, for×1, return×1.
//  - Notable callees: block×30, FUN_00799460, FUN_007ad9c0, SysFreeString.
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

/* WARNING: Removing unreachable block (ram,0x007ada6f) */

/* WARNING: Removing unreachable block (ram,0x007ada76) */

/* WARNING: Removing unreachable block (ram,0x007adab2) */

/* WARNING: Removing unreachable block (ram,0x007adb31) */

/* WARNING: Removing unreachable block (ram,0x007adbae) */

/* WARNING: Removing unreachable block (ram,0x007adc28) */

/* WARNING: Removing unreachable block (ram,0x007adc3f) */

/* WARNING: Removing unreachable block (ram,0x007adc9b) */

/* WARNING: Removing unreachable block (ram,0x007adc6a) */

/* WARNING: Removing unreachable block (ram,0x007adc7f) */

/* WARNING: Removing unreachable block (ram,0x007adc8f) */

/* WARNING: Removing unreachable block (ram,0x007adbc1) */

/* WARNING: Removing unreachable block (ram,0x007adc20) */

/* WARNING: Removing unreachable block (ram,0x007adbec) */

/* WARNING: Removing unreachable block (ram,0x007adc01) */

/* WARNING: Removing unreachable block (ram,0x007adc11) */

/* WARNING: Removing unreachable block (ram,0x007adb44) */

/* WARNING: Removing unreachable block (ram,0x007adba3) */

/* WARNING: Removing unreachable block (ram,0x007adb6f) */

/* WARNING: Removing unreachable block (ram,0x007adb84) */

/* WARNING: Removing unreachable block (ram,0x007adb94) */

/* WARNING: Removing unreachable block (ram,0x007adac7) */

/* WARNING: Removing unreachable block (ram,0x007adb26) */

/* WARNING: Removing unreachable block (ram,0x007adca1) */

/* WARNING: Removing unreachable block (ram,0x007adcb2) */

/* WARNING: Removing unreachable block (ram,0x007adaf2) */

/* WARNING: Removing unreachable block (ram,0x007adb07) */

/* WARNING: Removing unreachable block (ram,0x007adb17) */

/* WARNING: Removing unreachable block (ram,0x007adcc7) */

/* WARNING: Removing unreachable block (ram,0x007adce6) */

/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffe8 : 0x007adceb */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* WARNING: Restarted to delay deadcode elimination for space: stack */



void __fastcall FUN_007ad9c0(BSTR param_1)



{

  char cVar1;

  int iVar2;

  int *unaff_EBX;

  int unaff_ESI;

  int iStack_20;

  void *pvStack_1c;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009aceb2;

  pvStack_c = ExceptionList;

  local_4 = 0;

  ExceptionList = &pvStack_c;

  *(uint8_t *)(unaff_ESI + 0xd7) = 1;

  iVar2 = (**(code **)(*(int *)param_1 + 0x44))();

  if (((iVar2 == 0) && (iStack_20 != 0)) && (cVar1 = FUN_00799460(), cVar1 == '\x01')) {

    *(bool *)(unaff_ESI + 0x1c8) = pvStack_1c == (void *)0x1;

  }

  (**(code **)(*(int *)param_1 + 0x30))();

  if (unaff_EBX != (int *)0x0) {

    (**(code **)(*unaff_EBX + 0x20))();

    (*pcRam00000008)();

  }

  SysFreeString(param_1);

  ExceptionList = pvStack_1c;

  return;

}
