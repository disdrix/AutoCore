// =============================================================================
// FUN_0040ccb0
// -----------------------------------------------------------------------------
// Stable ID: aa_0040ccb0
// Address:   0x0040ccb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0040ccb0 @ 0x0040ccb0
// Stable ID: aa_0040ccb0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~59 non-empty decompiler lines.
//  - Control keywords: if×3, return×3.
//  - Notable callees: __alldiv×4, CONCAT44×3, block×3, FUN_0040ccb0.
//  - Return sites: 3.

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

/* WARNING: Removing unreachable block (ram,0x0040cd7a) */

/* WARNING: Removing unreachable block (ram,0x0040cd17) */

/* WARNING: Removing unreachable block (ram,0x0040cde1) */



int FUN_0040ccb0(void)



{

  uint uVar1;

  uint uVar2;

  int in_EAX;

  int iVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  longlong lVar8;

  uint uVar3;

  

  uVar1 = *(uint *)(in_EAX + 0x720);

  uVar2 = *(uint *)(in_EAX + 0x728);

  uVar3 = *(uint *)(in_EAX + 0x728);

  iVar5 = *(int *)(*(int *)(in_EAX + 4) + 4);

  iVar6 = *(int *)(in_EAX + 0x724);

  iVar7 = *(int *)(in_EAX + 0x72c);

  iVar4 = (**(code **)(*(int *)(*(int *)(*(int *)(in_EAX + 4) + 4) + 4 + in_EAX) + 0x27c))();

  iVar5 = (**(code **)(*(int *)(iVar5 + 4 + in_EAX) + 0x27c))();

  iVar5 = iVar5 * (iVar4 + -5);

  lVar8 = __alldiv(iVar5,iVar5 >> 0x1f,2,0);

  if (lVar8 < CONCAT44((iVar6 - iVar7) - (uint)(uVar1 < uVar2),uVar1 - uVar3)) {

    iVar5 = *(int *)(*(int *)(in_EAX + 4) + 4);

    iVar6 = (**(code **)(*(int *)(*(int *)(*(int *)(in_EAX + 4) + 4) + 4 + in_EAX) + 0x27c))();

    iVar5 = (**(code **)(*(int *)(iVar5 + 4 + in_EAX) + 0x27c))();

    iVar5 = iVar5 * (iVar6 + -5);

    lVar8 = __alldiv(iVar5,iVar5 >> 0x1f,2,0);

  }

  else {

    lVar8 = CONCAT44((*(int *)(in_EAX + 0x724) - *(int *)(in_EAX + 0x72c)) -

                     (uint)(*(uint *)(in_EAX + 0x720) < *(uint *)(in_EAX + 0x728)),

                     *(uint *)(in_EAX + 0x720) - *(uint *)(in_EAX + 0x728));

  }

  if (lVar8 < 1) {

    return 0;

  }

  uVar1 = *(uint *)(in_EAX + 0x720);

  uVar2 = *(uint *)(in_EAX + 0x728);

  uVar3 = *(uint *)(in_EAX + 0x728);

  iVar5 = *(int *)(in_EAX + 0x724);

  iVar6 = *(int *)(in_EAX + 0x72c);

  iVar7 = *(int *)(*(int *)(in_EAX + 4) + 4);

  iVar4 = (**(code **)(*(int *)(*(int *)(*(int *)(in_EAX + 4) + 4) + 4 + in_EAX) + 0x27c))();

  iVar7 = (**(code **)(*(int *)(iVar7 + 4 + in_EAX) + 0x27c))();

  iVar7 = iVar7 * (iVar4 + -5);

  lVar8 = __alldiv(iVar7,iVar7 >> 0x1f,2,0);

  if (CONCAT44((iVar5 - iVar6) - (uint)(uVar1 < uVar2),uVar1 - uVar3) <= lVar8) {

    return *(int *)(in_EAX + 0x720) - *(int *)(in_EAX + 0x728);

  }

  iVar5 = *(int *)(*(int *)(in_EAX + 4) + 4);

  iVar6 = (**(code **)(*(int *)(*(int *)(*(int *)(in_EAX + 4) + 4) + 4 + in_EAX) + 0x27c))();

  iVar5 = (**(code **)(*(int *)(iVar5 + 4 + in_EAX) + 0x27c))();

  iVar5 = iVar5 * (iVar6 + -5);

  iVar5 = __alldiv(iVar5,iVar5 >> 0x1f,2,0);

  return iVar5;

}
