// =============================================================================
// FUN_005d89f0
// -----------------------------------------------------------------------------
// Stable ID: aa_005d89f0
// Address:   0x005d89f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005d89f0 @ 0x005d89f0
// Stable ID: aa_005d89f0
// Embedded strings (evidence for future rename):
//   - "Frame Timer"
//   - "VisualDebugger: ["
//   - "Visual Debugger instance has been created"
//   - "Shapes"
//   - "DebugDisplay"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~54 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_005d8960×2, FUN_00631dc0×2, FUN_0055e970, FUN_0055e9f0, FUN_005d89f0, FUN_00631da0, FUN_00631f80, FUN_00641640.
//  - Strings: "Frame Timer"; "VisualDebugger: ["; "Visual Debugger instance has been created"; "Shapes".
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

uint32_t /* width from decompiler */ * __thiscall

FUN_005d89f0(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,int param_4)



{

  char *pcVar1;

  uint32_t /* width from decompiler */ uVar2;

  

  param_1[1] = &PTR_LAB_009db1d8;

  param_1[2] = &PTR_LAB_009db1d0;

  param_1[3] = param_2;

  *param_1 = &PTR_FUN_009db36c;

  param_1[1] = &PTR_LAB_009db364;

  param_1[2] = &PTR_LAB_009db35c;

  param_1[4] = 0;

  param_1[5] = 0;

  param_1[6] = 0;

  param_1[7] = 0x80000000;

  param_1[8] = 0;

  param_1[9] = 0;

  param_1[10] = 0x80000000;

  param_1[0xb] = param_3;

  param_1[0xc] = param_4;

  *(uint8_t *)(param_1 + 0xd) = 0;

  param_1[0x18] = "Frame Timer";

  param_1[0xe] = 0;

  param_1[0xf] = 0;

  param_1[0x10] = 0;

  param_1[0x11] = 0;

  param_1[0x12] = 0;

  param_1[0x13] = 0;

  param_1[0x14] = 0;

  param_1[0x15] = 0;

  *(uint8_t *)(param_1 + 0x16) = 0;

  param_1[0x17] = 0;

  if (0 < DAT_00d030ec) {

    pcVar1 = "VisualDebugger: [";

    (**(code **)(*DAT_00d030e0 + 4))("VisualDebugger: [");

    FUN_00631dc0(pcVar1);

    uVar2 = 0x5d;

    pcVar1 = "Visual Debugger instance has been created";

    (**(code **)(*DAT_00d030e0 + 4))("Visual Debugger instance has been created",0x5d);

    FUN_00631dc0(pcVar1);

    uVar2 = FUN_00631da0(uVar2);

    FUN_00631f80(uVar2);

  }

  FUN_00641640();

  if (param_4 != 0) {

    *(short *)(param_4 + 6) = *(short *)(param_4 + 6) + 1;

  }

  FUN_0055e9f0(param_1 + 1);

  FUN_0055e970(param_1 + 2);

  FUN_005d8960("Shapes");

  FUN_005d8960("DebugDisplay");

  FUN_00654e60(param_1);

  return param_1;

}
