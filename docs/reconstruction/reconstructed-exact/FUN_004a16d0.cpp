// =============================================================================
// FUN_004a16d0
// -----------------------------------------------------------------------------
// Stable ID: aa_004a16d0
// Address:   0x004a16d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004a16d0 @ 0x004a16d0
// Stable ID: aa_004a16d0
// Embedded strings (evidence for future rename):
//   - "%s_FOR_EVENT_%d"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: if×2, for×1, return×1.
//  - Notable callees: FUN_004a0b90, FUN_004a16d0, Map_LowerBoundFindByIntKey, _snprintf.
//  - Strings: "%s_FOR_EVENT_%d".
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

void __thiscall FUN_004a16d0(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,int param_4)



{

  void *this;

  int iVar1;

  int *extraout_EAX;

  int iVar2;

  int iVar3;

  int *unaff_EDI;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ local_118;

  uint8_t local_114 [4];

  char local_110 [2];

  uint32_t /* width from decompiler */ local_10e [66];

  

  this = (void *)*param_1;

  local_118 = param_2;

  Map_LowerBoundFindByIntKey(this,local_114,&local_118,unaff_EDI);

  iVar2 = *extraout_EAX;

  if (iVar2 != *(int *)((int)this + 4)) {

    iVar1 = *(int *)(iVar2 + 0x10);

    local_110[0] = '\0';

    local_110[1] = '\0';

    puVar4 = local_10e;

    for (iVar3 = 0x40; iVar3 != 0; iVar3 = iVar3 + -1) {

      *puVar4 = 0;

      puVar4 = puVar4 + 1;

    }

    *(uint16_t *)puVar4 = 0;

    _snprintf(local_110,0x104,"%s_FOR_EVENT_%d",iVar1 + 0xd5,param_2);

    iVar2 = FUN_004a0b90(*(uint32_t /* width from decompiler */ *)(iVar2 + 0x10),local_110,param_3,0xffffffff,0);

    if (((iVar2 != 0) && (-1 < param_4)) && (param_4 < 5)) {

      *(int *)(iVar2 + 0x230) = param_4;

    }

  }

  return;

}
