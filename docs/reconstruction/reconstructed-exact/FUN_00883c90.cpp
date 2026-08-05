// =============================================================================
// FUN_00883c90
// -----------------------------------------------------------------------------
// Stable ID: aa_00883c90
// Address:   0x00883c90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00883c90 @ 0x00883c90
// Stable ID: aa_00883c90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: atoi×4, __allmul×3, FUN_00883c90.
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

longlong FUN_00883c90(void)



{

  int in_EAX;

  char *pcVar1;

  int iVar2;

  int iVar3;

  longlong lVar4;

  longlong lVar5;

  longlong lVar6;

  

  pcVar1 = (char *)(**(code **)(**(int **)(in_EAX + 0x558) + 0x1dc))();

  iVar2 = atoi(pcVar1);

  pcVar1 = (char *)(**(code **)(**(int **)(in_EAX + 0x55c) + 0x1dc))();

  iVar3 = atoi(pcVar1);

  lVar4 = __allmul(iVar3,iVar3 >> 0x1f,1000,0);

  pcVar1 = (char *)(**(code **)(**(int **)(in_EAX + 0x560) + 0x1dc))();

  iVar3 = atoi(pcVar1);

  lVar5 = __allmul(iVar3,iVar3 >> 0x1f,1000000,0);

  pcVar1 = (char *)(**(code **)(**(int **)(in_EAX + 0x564) + 0x1dc))();

  iVar3 = atoi(pcVar1);

  lVar6 = __allmul(iVar3,iVar3 >> 0x1f,1000000000,0);

  lVar6 = lVar4 + iVar2 + lVar5 + lVar6;

  if (((int)((ulonglong)lVar6 >> 0x20) < 1) && (lVar6 < 0)) {

    return 0;

  }

  return lVar6;

}
