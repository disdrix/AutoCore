// =============================================================================
// FUN_0048c8c0
// -----------------------------------------------------------------------------
// Stable ID: aa_0048c8c0
// Address:   0x0048c8c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0048c8c0 @ 0x0048c8c0
// Stable ID: aa_0048c8c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~39 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, do×1, while×1.
//  - Notable callees: FUN_0048a940, FUN_0048c120, FUN_0048c8c0.
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

int __fastcall FUN_0048c8c0(int param_1)



{

  char cVar1;

  void *pvVar2;

  int iVar3;

  char *pcVar4;

  char *pcVar5;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a059b;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  pvVar2 = operator_new(0x30);

  local_4 = 0;

  if (pvVar2 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_0048c120(&DAT_00a1419b);

  }

  local_4 = 0xffffffff;

  if (iVar3 == 0) {

    ExceptionList = local_c;

    return 0;

  }

  pcVar5 = (char *)(*(int *)(param_1 + 0x20) + 8);

  pcVar4 = pcVar5;

  do {

    cVar1 = *pcVar4;

    pcVar4 = pcVar4 + 1;

  } while (cVar1 != '\0');

  FUN_0048a940(pcVar5,(int)pcVar4 - (*(int *)(param_1 + 0x20) + 9));

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0xc) = *(uint32_t /* width from decompiler */ *)(param_1 + 0xc);

  *(uint8_t *)(iVar3 + 0x2c) = *(uint8_t *)(param_1 + 0x2c);

  ExceptionList = local_c;

  return iVar3;

}
