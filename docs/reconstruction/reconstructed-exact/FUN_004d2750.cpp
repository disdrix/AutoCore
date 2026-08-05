// =============================================================================
// FUN_004d2750
// -----------------------------------------------------------------------------
// Stable ID: aa_004d2750
// Address:   0x004d2750  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004d2750 @ 0x004d2750
// Stable ID: aa_004d2750
// Embedded strings (evidence for future rename):
//   - "allocatenewobjectfromcbid failed %d"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: CVOGReaction_GiveItemByCbid, FUN_004d0ed0, FUN_004d2750, FUN_00512160, FUN_005123e0, FUN_007a4480.
//  - Strings: "allocatenewobjectfromcbid failed %d".
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

void __thiscall FUN_004d2750(int param_1,int param_2,uint32_t /* width from decompiler */ param_3,int param_4,int param_5)



{

  uint uVar1;

  int iVar2;

  int *piVar3;

  uint32_t /* width from decompiler */ unaff_EBX;

  uint32_t /* width from decompiler */ unaff_retaddr;

  

  iVar2 = FUN_005123e0(param_2,param_3);

  piVar3 = (int *)CVOGReaction_GiveItemByCbid(iVar2);

  if (piVar3 != (int *)0x0) {

    iVar2 = (**(code **)(*piVar3 + 8))(iVar2,param_1,1);

    if (iVar2 == 0) {

      piVar3[0x31] = param_2;

      piVar3[0x5c] = param_4;

      piVar3[0x5d] = param_5;

    }

    uVar1 = *(uint *)(param_1 + 0xe6e0);

    iVar2 = *(int *)(param_1 + 0xe6e4);

    *(uint *)(param_1 + 0xe6e4) = iVar2 + (uint)(0xfffffffe < uVar1);

    *(uint *)(param_1 + 0xe6e0) = uVar1 + 1;

    FUN_00512160(uVar1,iVar2,1);

    (**(code **)(*piVar3 + 0x2a4))(*(uint32_t /* width from decompiler */ *)(param_1 + 0xe4e8));

    FUN_004d0ed0(piVar3,unaff_EBX,unaff_retaddr,param_2);

    return;

  }

  FUN_007a4480(0,"allocatenewobjectfromcbid failed %d",iVar2);

  return;

}
