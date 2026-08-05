// =============================================================================
// FUN_00907440
// -----------------------------------------------------------------------------
// Stable ID: aa_00907440
// Address:   0x00907440  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00907440 @ 0x00907440
// Stable ID: aa_00907440
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: atoi×4, __allmul×3, FUN_00907440.
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

longlong FUN_00907440(void)



{

  char cVar1;

  int *in_EAX;

  char *pcVar2;

  int iVar3;

  int iVar4;

  longlong lVar5;

  longlong lVar6;

  longlong lVar7;

  

  cVar1 = (**(code **)(*in_EAX + 0x3d8))();

  if (cVar1 == '\0') {

    return 0;

  }

  pcVar2 = (char *)(**(code **)(*(int *)in_EAX[0x194] + 0x1dc))();

  iVar3 = atoi(pcVar2);

  pcVar2 = (char *)(**(code **)(*(int *)in_EAX[0x195] + 0x1dc))();

  iVar4 = atoi(pcVar2);

  lVar5 = __allmul(iVar4,iVar4 >> 0x1f,1000,0);

  pcVar2 = (char *)(**(code **)(*(int *)in_EAX[0x196] + 0x1dc))();

  iVar4 = atoi(pcVar2);

  lVar6 = __allmul(iVar4,iVar4 >> 0x1f,1000000,0);

  pcVar2 = (char *)(**(code **)(*(int *)in_EAX[0x197] + 0x1dc))();

  iVar4 = atoi(pcVar2);

  lVar7 = __allmul(iVar4,iVar4 >> 0x1f,1000000000,0);

  lVar7 = lVar5 + iVar3 + lVar6 + lVar7;

  if (((int)((ulonglong)lVar7 >> 0x20) < 1) && (lVar7 < 0)) {

    lVar7 = 0;

  }

  return lVar7;

}
