// =============================================================================
// FUN_007965c0
// -----------------------------------------------------------------------------
// Stable ID: aa_007965c0
// Address:   0x007965c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007965c0 @ 0x007965c0
// Stable ID: aa_007965c0
// Embedded strings (evidence for future rename):
//   - "NDUIPlayer"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~53 non-empty decompiler lines.
//  - Control keywords: for×1, while×1, return×1.
//  - Notable callees: FUN_007965c0.
//  - Strings: "NDUIPlayer".
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

void FUN_007965c0(uint32_t /* width from decompiler */ param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  int iVar2;

  int in_EAX;

  int iVar3;

  int *piVar4;

  char **ppcVar5;

  char *local_40 [4];

  int local_30;

  uint32_t /* width from decompiler */ local_2c;

  uint32_t /* width from decompiler */ local_28;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ local_10;

  uint32_t /* width from decompiler */ local_c;

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  uVar1 = *(uint32_t /* width from decompiler */ *)(in_EAX + 0x80);

  iVar2 = *(int *)(in_EAX + 0xc);

  ppcVar5 = local_40;

  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {

    *ppcVar5 = (char *)0x0;

    ppcVar5 = ppcVar5 + 1;

  }

  local_40[1] = *(char **)(in_EAX + 0x7c);

  local_20 = 0xff3cbff1;

  local_18 = 0xff3cbff1;

  local_c = 0x80000000;

  local_8 = 0x80000000;

  piVar4 = (int *)(in_EAX + 0xc);

  local_30 = in_EAX + 0x84;

  local_40[0] = (char *)0x40;

  local_40[2] = "NDUIPlayer";

  local_40[3] = (char *)0x1;

  local_4 = 0;

  local_28 = 0x24;

  local_24 = 0xffffffff;

  local_1c = 0x80ffffff;

  local_14 = 0x808c988c;

  local_10 = 0x80710000;

  local_2c = uVar1;

  while (iVar2 != 0) {

    (**(code **)(*(int *)*piVar4 + 0x20))((int *)*piVar4);

    piVar4 = piVar4 + 1;

    iVar2 = *piVar4;

  }

  (**(code **)(**(int **)(in_EAX + 8) + 0x28))(*(int **)(in_EAX + 8),0,local_40,param_1,0);

  return;

}
