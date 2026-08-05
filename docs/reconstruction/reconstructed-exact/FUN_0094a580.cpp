// =============================================================================
// FUN_0094a580
// -----------------------------------------------------------------------------
// Stable ID: aa_0094a580
// Address:   0x0094a580  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0094a580 @ 0x0094a580
// Stable ID: aa_0094a580
// Embedded strings (evidence for future rename):
//   - "InitUserInterface start"
//   - "Can not initialize any input devices"
//   - "VOG_DEBUG_STOP"
//   - "createNDUIDialogs"
//   - "before switch(m_eServerConnectCurrent)"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~45 non-empty decompiler lines.
//  - Control keywords: if×5, return×2, goto×1, switch×1.
//  - Notable callees: FUN_007a4480×6, FUN_00796d40×4, FUN_007209a0, FUN_00720d40, FUN_00796d70, FUN_0085cb40, FUN_00937560, FUN_0093e7e0.
//  - Strings: "InitUserInterface start"; "Can not initialize any input devices"; "VOG_DEBUG_STOP"; "createNDUIDialogs".
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

int FUN_0094a580(void)



{

  char cVar1;

  int iVar2;

  int iVar3;

  int unaff_ESI;

  uint32_t /* width from decompiler */ uVar4;

  

  FUN_007a4480(0,"InitUserInterface start");

  FUN_0085cb40();

  uVar4 = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x3188);

  FUN_00796d40();

  iVar2 = FUN_00796d70(uVar4);

  if (iVar2 < 0) {

    FUN_007a4480(1,"Can not initialize any input devices");

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  iVar3 = FUN_00796d40();

  *(uint8_t **)(iVar3 + 4) = &LAB_0092d140;

  if (*(int *)(unaff_ESI + 0xdd0) != 0) {

    iVar3 = FUN_00796d40();

    (**(code **)(unaff_ESI + 0xdd0))(*(int *)(iVar3 + 0x78) != 0);

  }

  cVar1 = *(char *)(unaff_ESI + 0xa8);

  iVar3 = FUN_00796d40();

  if ((*(int *)(iVar3 + 0x70) != 0) && (*(int *)(iVar3 + 0x80) != 0)) {

    iVar3 = (**(code **)(**(int **)(iVar3 + 0x70) + 0x34))

                      (*(int **)(iVar3 + 0x70),*(int *)(iVar3 + 0x80),

                       (-(uint)(cVar1 != '\0') & 0xfffffff0) + 0x10 | 6);

    if (-1 < iVar3) goto LAB_0094a639;

  }

  FUN_007a4480(0,"VOG_DEBUG_STOP");

LAB_0094a639:

  FUN_007a4480(0xffffffff,"createNDUIDialogs");

  FUN_0093e7e0(unaff_ESI);

  FUN_007a4480(0xffffffff,"before switch(m_eServerConnectCurrent)");

  if ((0 < *(int *)(unaff_ESI + 0xc0)) && (*(int *)(unaff_ESI + 0xc0) < 3)) {

    FUN_009494c0();

    return iVar2;

  }

  uVar4 = 1;

  FUN_00720d40(1);

  FUN_007209a0(uVar4);

  FUN_00937560(unaff_ESI);

  return iVar2;

}
