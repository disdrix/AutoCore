// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004ad730
// -----------------------------------------------------------------------------
// Stable ID: aa_004ad730
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_Server_needs
// Address:   0x004ad730  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_Server_needs: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~165 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_004af8f0×32, FUN_00439770, FUN_004ad730.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_Server_needs
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

int __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004ad730(int param_1)



{

  float fVar1;

  int iVar2;

  char *local_28;

  uint8_t local_24;

  uint8_t local_20 [12];

  void *local_14;

  uint8_t *puStack_10;

  uint32_t /* width from decompiler */ local_c;

  

  local_c = 0xffffffff;

  puStack_10 = &LAB_009a133a;

  local_14 = ExceptionList;

  ExceptionList = &local_14;

  iVar2 = FUN_00439770();

  *(int *)(param_1 + 0x3d0) = iVar2;

  *(uint8_t *)(iVar2 + 0x15) = 1;

  *(int *)(*(int *)(param_1 + 0x3d0) + 4) = *(int *)(param_1 + 0x3d0);

  *(uint32_t /* width from decompiler */ *)*(uint32_t /* width from decompiler */ *)(param_1 + 0x3d0) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x3d0);

  *(int *)(*(int *)(param_1 + 0x3d0) + 8) = *(int *)(param_1 + 0x3d0);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x3d4) = 0;

  local_c = 0;

  if (DAT_00b03630 == '\0') {

    DAT_00b03631 = DAT_00b03e64 == '\0';

    DAT_00b03630 = '\x01';

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x18) = DAT_00aaa6c4;

  fVar1 = g_flOne;

  *(uint8_t *)(param_1 + 0x1c) = 1;

  *(uint8_t *)(param_1 + 0x1d) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x38c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x39c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x390) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x394) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x3a4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x3e4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 1000) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x3ec) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x3f0) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x3f4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x3f8) = 0;

  *(uint8_t *)(param_1 + 0x398) = 0;

  *(float *)(param_1 + 0x33c) = fVar1;

  *(uint32_t /* width from decompiler */ *)(param_1 + 8) = 2;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x3a0) = 6;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = 0x200;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x14) = 0x200;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x3a8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x3ac) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x3b0) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x3b4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x3b8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x3bc) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x3c0) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x3c4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x334) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x3dc) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x3e0) = 0;

  *(uint16_t *)(param_1 + 0x32e) = 0;

  *(uint16_t *)(param_1 + 0x330) = 0;

  *(uint16_t *)(param_1 + 0x332) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x340) = 0;

  *(uint8_t *)(param_1 + 0x338) = 1;

  *(uint8_t *)(param_1 + 0x339) = 1;

  *(uint8_t *)(param_1 + 0xc) = 1;

  local_24 = 1;

  local_28 = (char *)0xff0000;

  FUN_004af8f0(local_20,&local_28);

  local_28 = (char *)0xff00;

  local_24 = 2;

  FUN_004af8f0(local_20,&local_28);

  local_28 = (char *)0xff;

  local_24 = 3;

  FUN_004af8f0(local_20,&local_28);

  local_28 = (char *)0xffffff;

  local_24 = 4;

  FUN_004af8f0(local_20,&local_28);

  local_28 = &DAT_00bf0000;

  local_24 = 5;

  FUN_004af8f0(local_20,&local_28);

  local_28 = (char *)0xbf00;

  local_24 = 6;

  FUN_004af8f0(local_20,&local_28);

  local_28 = (char *)0xbf;

  local_24 = 7;

  FUN_004af8f0(local_20,&local_28);

  local_28 = (char *)0xdfdfdf;

  local_24 = 8;

  FUN_004af8f0(local_20,&local_28);

  local_28 = (char *)0x7f0000;

  local_24 = 9;

  FUN_004af8f0(local_20,&local_28);

  local_28 = (char *)0x7f00;

  local_24 = 10;

  FUN_004af8f0(local_20,&local_28);

  local_28 = (char *)0x7f;

  local_24 = 0xb;

  FUN_004af8f0(local_20,&local_28);

  local_28 = &DAT_00bfbfbf;

  local_24 = 0xc;

  FUN_004af8f0(local_20,&local_28);

  local_28 = (char *)0x3f0000;

  local_24 = 0xd;

  FUN_004af8f0(local_20,&local_28);

  local_28 = (char *)0x3f00;

  local_24 = 0xe;

  FUN_004af8f0(local_20,&local_28);

  local_28 = (char *)0x3f;

  local_24 = 0xf;

  FUN_004af8f0(local_20,&local_28);

  local_28 = "";

  local_24 = 0x10;

  FUN_004af8f0(local_20,&local_28);

  local_28 = (char *)0xffff00;

  local_24 = 0x11;

  FUN_004af8f0(local_20,&local_28);

  local_28 = (char *)0xffff;

  local_24 = 0x12;

  FUN_004af8f0(local_20,&local_28);

  local_28 = (char *)0xff00ff;

  local_24 = 0x13;

  FUN_004af8f0(local_20,&local_28);

  local_28 = (char *)0x7f7f7f;

  local_24 = 0x14;

  FUN_004af8f0(local_20,&local_28);

  local_28 = &DAT_00bfbf00;

  local_24 = 0x15;

  FUN_004af8f0(local_20,&local_28);

  local_28 = (char *)0xbfbf;

  local_24 = 0x16;

  FUN_004af8f0(local_20,&local_28);

  local_28 = &DAT_00bf00bf;

  local_24 = 0x17;

  FUN_004af8f0(local_20,&local_28);

  local_28 = (char *)0x5f5f5f;

  local_24 = 0x18;

  FUN_004af8f0(local_20,&local_28);

  local_28 = "";

  local_24 = 0x19;

  FUN_004af8f0(local_20,&local_28);

  local_28 = (char *)0x7f7f;

  local_24 = 0x1a;

  FUN_004af8f0(local_20,&local_28);

  local_28 = (char *)0x7f007f;

  local_24 = 0x1b;

  FUN_004af8f0(local_20,&local_28);

  local_28 = (char *)0x3f3f3f;

  local_24 = 0x1c;

  FUN_004af8f0(local_20,&local_28);

  local_28 = (char *)0x3f3f00;

  local_24 = 0x1d;

  FUN_004af8f0(local_20,&local_28);

  local_28 = (char *)0x3f3f;

  local_24 = 0x1e;

  FUN_004af8f0(local_20,&local_28);

  local_28 = (char *)0x3f003f;

  local_24 = 0x1f;

  FUN_004af8f0(local_20,&local_28);

  local_28 = (char *)0x1f1f1f;

  local_24 = 0x20;

  FUN_004af8f0(local_20,&local_28);

  ExceptionList = local_14;

  return param_1;

}
