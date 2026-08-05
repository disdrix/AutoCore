// =============================================================================
// FUN_007a49e0
// -----------------------------------------------------------------------------
// Stable ID: aa_007a49e0
// Address:   0x007a49e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007a49e0 @ 0x007a49e0
// Stable ID: aa_007a49e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~51 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: strncpy×3, CARRY4, FUN_007a49e0, __alldiv, time.
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

void __thiscall FUN_007a49e0(int *param_1,char *param_2,uint param_3,int param_4)



{

  int iVar1;

  uint uVar2;

  char *_Source;

  uint uVar3;

  uint64_t uVar4;

  time_t tVar5;

  uint32_t /* width from decompiler */ in_stack_0000001c;

  uint32_t /* width from decompiler */ in_stack_00000020;

  uint32_t /* width from decompiler */ in_stack_00000024;

  

  iVar1 = *(int *)(param_2 + 0x1ec);

  uVar2 = *(uint *)(param_2 + 0x1e8);

  uVar4 = __alldiv(uVar2,iVar1,100,0);

  uVar3 = uVar2 - (uint)uVar4;

  *(uint *)(param_2 + 0x1e8) = uVar3 + param_3;

  *(uint *)(param_2 + 0x1ec) =

       ((iVar1 - (int)((ulonglong)uVar4 >> 0x20)) - (uint)(uVar2 < (uint)uVar4)) + param_4 +

       (uint)CARRY4(uVar3,param_3);

  _Source = (char *)(**(code **)(*param_1 + 0x38))

                              (in_stack_0000001c,in_stack_00000020,in_stack_00000024);

  *param_2 = '\0';

  if (_Source != (char *)0x0) {

    strncpy(param_2,_Source,0x31);

    param_2[0x31] = '\0';

  }

  *(int *)(param_2 + 0x214) = param_4;

  param_2[0x224] = '\x02';

  *(uint *)(param_2 + 0x210) = param_3;

  param_2[0x1d3] = '\0';

  if (param_2 != (char *)0x0) {

    strncpy(param_2 + 0x1d3,param_2,0x10);

    param_2[0x1e3] = '\0';

  }

  param_2[0x208] = -1;

  param_2[0x209] = -1;

  param_2[0x20a] = -1;

  param_2[0x20b] = -1;

  param_2[0x20c] = -1;

  param_2[0x20d] = -1;

  param_2[0x20e] = -1;

  param_2[0x20f] = -1;

  param_2[0x1c2] = '\0';

  strncpy(param_2 + 0x1c2,"",0x10);

  param_2[0x1d2] = '\0';

  tVar5 = time((time_t *)0x0);

  *(int *)(param_2 + 0x218) = (int)tVar5;

  *(int *)(param_2 + 0x21c) = (int)tVar5 + 0x278d00;

  param_2[0x248] = '\0';

  return;

}
