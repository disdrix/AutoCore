// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_UpdateObjectiveDisplayHud_0051fb50
// -----------------------------------------------------------------------------
// Stable ID: aa_0051fb50
// Callee of Named_CalleeOf_Client_UpdateObjectiveDisplayHud (+1 other named callers)
// Address:   0x0051fb50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_UpdateObjectiveDisplayHud: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_CalleeOf_Client_UpdateObjectiveDisplayHud (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~55 non-empty decompiler lines.
//  - Control keywords: return×5, if×3, switch×1.
//  - Notable callees: SCARRY4×4, __alldiv×3, __allmul×3, CARRY4×2, CONCAT44, FUN_0051fb50.
//  - Return sites: 5.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_UpdateObjectiveDisplayHud (+1 other named callers)
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

longlong Named_CalleeOf_Named_CalleeOf_Client_UpdateObjectiveDisplayHud_0051fb50(uint32_t /* width from decompiler */ param_1,uint param_2,int param_3)



{

  uint uVar1;

  int iVar2;

  int iVar3;

  uint uVar4;

  uint uVar5;

  int iVar6;

  int iVar7;

  longlong lVar8;

  uint64_t uVar9;

  longlong lVar10;

  longlong lVar11;

  longlong lVar12;

  

  lVar8 = 0;

  if ((-1 < param_3) && ((0 < param_3 || (lVar8 = 0, 999999999 < param_2)))) {

    lVar8 = __alldiv(param_2,param_3,1000000000,0);

  }

  uVar9 = __allmul(lVar8,0xc4653600,0xffffffff);

  iVar3 = (int)((ulonglong)uVar9 >> 0x20);

  uVar4 = param_2 + (uint)uVar9;

  uVar1 = (uint)CARRY4(param_2,(uint)uVar9);

  iVar2 = param_3 + iVar3;

  iVar6 = iVar2 + uVar1;

  lVar10 = 0;

  if ((-1 < iVar6) &&

     ((iVar6 != 0 && SCARRY4(param_3,iVar3) == SCARRY4(iVar2,uVar1) || (lVar10 = 0, 999999 < uVar4))

     )) {

    lVar10 = __alldiv(uVar4,iVar6,1000000,0);

  }

  uVar9 = __allmul(lVar10,0xfff0bdc0,0xffffffff);

  iVar3 = (int)((ulonglong)uVar9 >> 0x20);

  uVar5 = uVar4 + (uint)uVar9;

  uVar1 = (uint)CARRY4(uVar4,(uint)uVar9);

  iVar2 = iVar6 + iVar3;

  iVar7 = iVar2 + uVar1;

  lVar11 = 0;

  if ((-1 < iVar7) &&

     ((iVar7 != 0 && SCARRY4(iVar6,iVar3) == SCARRY4(iVar2,uVar1) || (lVar11 = 0, 999 < uVar5)))) {

    lVar11 = __alldiv(uVar5,iVar7,1000,0);

  }

  lVar12 = __allmul(lVar11,0xfffffc18,0xffffffff);

  switch(param_1) {

  case 0:

    return lVar12 + CONCAT44(iVar7,uVar5);

  case 1:

    return lVar11;

  case 2:

    return lVar10;

  case 3:

    return lVar8;

  default:

    return 0;

  }

}
