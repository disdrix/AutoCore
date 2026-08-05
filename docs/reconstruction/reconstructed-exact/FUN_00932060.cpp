// =============================================================================
// FUN_00932060
// -----------------------------------------------------------------------------
// Stable ID: aa_00932060
// Address:   0x00932060  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00932060 @ 0x00932060
// Stable ID: aa_00932060
// Embedded strings (evidence for future rename):
//   - "@@inside InitPhysics"
//   - "start initPhysics"
//   - "initterrain"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~73 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_007a4480×2, FUN_00405490, FUN_004d9cd0, FUN_0055ff20, FUN_00581220, FUN_0058e0b0, FUN_007a4390, FUN_007a4400.
//  - Strings: "@@inside InitPhysics"; "start initPhysics"; "initterrain".
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

uint32_t /* width from decompiler */ FUN_00932060(void)



{

  uint32_t /* width from decompiler */ uVar1;

  int unaff_ESI;

  uint32_t /* width from decompiler */ uStack_284;

  char *pcStack_280;

  uint32_t /* width from decompiler */ uStack_27c;

  uint32_t /* width from decompiler */ uStack_278;

  char *pcStack_274;

  uint32_t /* width from decompiler */ uStack_25c;

  uint32_t /* width from decompiler */ uStack_258;

  uint32_t /* width from decompiler */ uStack_254;

  uint32_t /* width from decompiler */ uStack_250;

  uint32_t /* width from decompiler */ uStack_24c;

  uint32_t /* width from decompiler */ uStack_248;

  uint32_t /* width from decompiler */ uStack_244;

  int iStack_240;

  void *pvStack_30;

  int iStack_28;

  uint8_t uStack_20;

  void *pvStack_1c;

  uint8_t *puStack_18;

  uint32_t /* width from decompiler */ local_14;

  

  local_14 = 0xffffffff;

  puStack_18 = &LAB_009ad391;

  pvStack_1c = ExceptionList;

  pcStack_274 = "@@inside InitPhysics";

  uStack_278 = 0x93208f;

  ExceptionList = &pvStack_1c;

  FUN_007a4400();

  local_14 = 0;

  pcStack_274 = "start initPhysics";

  uStack_278 = 0;

  uStack_27c = 0x9320a6;

  FUN_007a4480();

  pcStack_274 = (char *)0x0;

  uStack_278 = 0xc11cf5c3;

  uStack_27c = 0;

  pcStack_280 = (char *)0x9320bc;

  (**(code **)**(uint32_t /* width from decompiler */ **)(unaff_ESI + 0xe04))();

  pcStack_280 = "initterrain";

  uStack_284 = 0;

  FUN_007a4480();

  pcStack_280 = (char *)0x9320d6;

  FUN_004d9cd0();

  pcStack_280 = (char *)0x9320de;

  FUN_0058e0b0();

  uStack_20 = 1;

  uStack_24c = DAT_00a15868;

  uStack_248 = DAT_00a15868;

  uStack_244 = DAT_00a15868;

  pcStack_280 = (char *)0x2c;

  uStack_27c = 0x15;

  iStack_240 = 0;

  uStack_25c = DAT_00aaa9c0;

  uStack_258 = DAT_00aaa9c0;

  uStack_254 = DAT_00aaa9c0;

  uStack_250 = 0;

  uStack_284 = 0x90;

  iStack_240 = (**(code **)(*DAT_00b05060 + 0x10))();

  *(uint16_t *)(iStack_240 + 4) = 0x90;

  iStack_28._0_1_ = 2;

  uVar1 = FUN_00581220(&uStack_284);

  iStack_28._0_1_ = 1;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xed4) = uVar1;

  FUN_0055ff20(uVar1);

  iStack_28 = (uint)iStack_28._1_3_ << 8;

  FUN_00405490();

  iStack_28 = 0xffffffff;

  FUN_007a4390();

  ExceptionList = pvStack_30;

  return 0;

}
