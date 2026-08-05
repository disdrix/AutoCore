// =============================================================================
// Named_CalleeOf_Named_ClientSpecialEvent_TeleportIn_00439a80
// -----------------------------------------------------------------------------
// Stable ID: aa_00439a80
// Callee of Named_ClientSpecialEvent_TeleportIn (+2 other named callers)
// Address:   0x00439a80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_ClientSpecialEvent_TeleportIn: spawn/transfer helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_ClientSpecialEvent_TeleportIn (+2 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~97 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_00972cc0×5, FUN_0040cf90×3, FUN_0040d1a0×3, FUN_00973030×3, FUN_00439a80, FUN_0076f6e0, FUN_00972e50.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_ClientSpecialEvent_TeleportIn (+2 other named callers)
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void Named_CalleeOf_Named_ClientSpecialEvent_TeleportIn_00439a80(void)



{

  int iVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *unaff_EDI;

  float fVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ uStack_338;

  uint32_t /* width from decompiler */ uStack_334;

  uint32_t /* width from decompiler */ uStack_330;

  uint32_t /* width from decompiler */ uStack_328;

  uint32_t /* width from decompiler */ uStack_324;

  uint32_t /* width from decompiler */ uStack_320;

  float fStack_31c;

  float fStack_2a8;

  float fStack_2a4;

  float fStack_2a0;

  float fStack_29c;

  uint32_t /* width from decompiler */ uStack_298;

  uint32_t /* width from decompiler */ uStack_294;

  uint32_t /* width from decompiler */ uStack_290;

  int iStack_274;

  uint32_t /* width from decompiler */ uStack_26c;

  uint8_t auStack_260 [120];

  float fStack_1e8;

  float fStack_1e4;

  float fStack_1e0;

  float fStack_1dc;

  uint8_t auStack_1a8 [16];

  uint8_t auStack_198 [200];

  uint8_t local_d0 [100];

  uint8_t auStack_6c [20];

  uint8_t auStack_58 [84];

  

  iVar1 = unaff_EDI[3];

  iVar2 = unaff_EDI[1];

  FUN_00972cc0();

  if (iVar2 == 0) {

    (**(code **)(*(int *)*unaff_EDI + 8))(0xffffffff,local_d0);

  }

  else {

    (**(code **)(*(int *)*unaff_EDI + 8))(*(uint32_t /* width from decompiler */ *)(iVar2 + 0xc),local_d0);

    FUN_00972cc0();

    FUN_0040cf90(iVar2 + 0x20);

    FUN_0040d1a0(iVar2 + 0x10);

    FUN_00973030(auStack_198);

  }

  uStack_328 = 0;

  uStack_324 = 0;

  uStack_320 = 0;

  fStack_31c = g_flOne;

  (**(code **)(*(int *)unaff_EDI[2] + 0x14))(&uStack_328);

  uStack_338 = 0;

  uStack_334 = 0;

  uStack_330 = 0;

  (**(code **)(*(int *)unaff_EDI[2] + 0x18))(&uStack_338);

  (**(code **)(*(int *)unaff_EDI[2] + 0x34))();

  FUN_00972cc0();

  if (iVar1 == 0) {

    (**(code **)(*(int *)unaff_EDI[2] + 8))(0xffffffff,auStack_260);

  }

  else {

    (**(code **)(*(int *)unaff_EDI[2] + 8))(*(uint32_t /* width from decompiler */ *)(iVar1 + 0xc),auStack_260);

    FUN_00972cc0();

    FUN_0040cf90(iVar1 + 0x20);

    FUN_0040d1a0(iVar1 + 0x10);

    FUN_00973030(auStack_1a8);

  }

  FUN_00972cc0();

  iStack_274 = iStack_274 + 1;

  fVar3 = fStack_1e8 * fStack_1e8 + fStack_1e4 * fStack_1e4 + fStack_1e0 * fStack_1e0 +

          fStack_1dc * fStack_1dc;

  uStack_26c = 0xffffffff;

  if ((_DAT_00a240ec <= fVar3) || (fVar3 <= DAT_00aaa640)) {

    fVar3 = g_flOne / fVar3;

    fStack_2a8 = (0.0 - fStack_1e8) * fVar3;

    fStack_2a4 = (0.0 - fStack_1e4) * fVar3;

    fStack_2a0 = (0.0 - fStack_1e0) * fVar3;

    fStack_29c = fStack_1dc * fVar3;

  }

  FUN_00972e50();

  iStack_274 = iStack_274 + 1;

  uStack_26c = 0xffffffff;

  FUN_0076f6e0();

  uStack_298 = uStack_338;

  uStack_294 = uStack_334;

  uStack_290 = uStack_330;

  FUN_00973030(&uStack_328);

  uVar4 = 3;

  (**(code **)(*(int *)unaff_EDI[2] + 0x10))(3,auStack_58);

  FUN_0040cf90(uVar4);

  uVar4 = 3;

  (**(code **)(*(int *)unaff_EDI[2] + 0x10))(3,auStack_6c);

  FUN_0040d1a0(uVar4);

  (**(code **)(*(int *)unaff_EDI[2] + 0x34))();

  return;

}
