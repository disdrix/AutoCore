// =============================================================================
// Named_CalleeOf_Named_netSession_0076c500
// -----------------------------------------------------------------------------
// Stable ID: aa_0076c500
// Callee of Named_netSession (+4 other named callers)
// Address:   0x0076c500  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_netSession: auth/session helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_netSession (+4 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~39 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0076c270, FUN_0076c4d0, FUN_0076c500, __allmul, __aulldiv.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_netSession (+4 other named callers)
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



int * __thiscall Named_CalleeOf_Named_netSession_0076c500(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  double dVar1;

  uint uVar2;

  int iVar3;

  uint uVar4;

  bool bVar5;

  ulonglong uVar6;

  uint64_t uVar7;

  

  bVar5 = DAT_00d1a530 == '\0';

  *param_1 = 0;

  param_1[1] = 0;

  param_1[2] = 0;

  param_1[3] = 0;

  param_1[4] = 0;

  param_1[5] = 0;

  *(uint8_t *)(param_1 + 6) = 0;

  param_1[8] = 0;

  param_1[9] = 0;

  if (bVar5) {

    FUN_0076c270();

  }

  iVar3 = DAT_00d1a53c;

  uVar2 = DAT_00d1a538;

  uVar6 = __aulldiv(DAT_00d1a538,DAT_00d1a53c,param_2,0);

  uVar4 = (uint)(uVar6 >> 0x20);

  param_1[9] = uVar4;

  dVar1 = _DAT_00aaa5f8 /

          (-(double)(longlong)(((ulonglong)uVar4 & 0x80000000) << 0x20) +

          (double)(uVar6 & 0x7fffffffffffffff));

  param_1[8] = (int)uVar6;

  *(double *)(param_1 + 10) = dVar1;

  uVar7 = __allmul(uVar6,param_2,0);

  *param_1 = uVar2 - (uint)uVar7;

  param_1[1] = (iVar3 - (int)((ulonglong)uVar7 >> 0x20)) - (uint)(uVar2 < (uint)uVar7);

  FUN_0076c4d0();

  return param_1;

}
