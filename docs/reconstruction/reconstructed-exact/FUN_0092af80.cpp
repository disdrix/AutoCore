// =============================================================================
// FUN_0092af80
// -----------------------------------------------------------------------------
// Stable ID: aa_0092af80
// Address:   0x0092af80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0092af80 @ 0x0092af80
// Stable ID: aa_0092af80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: if×6, return×1.
//  - Notable callees: CVOGReaction_ResolveObjectTarget, FUN_00929cd0, FUN_0092a760, FUN_0092a980, FUN_0092abc0, FUN_0092adf0, FUN_0092af80.
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

bool FUN_0092af80(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2)



{

  bool bVar1;

  bool bVar2;

  bool bVar3;

  char cVar4;

  int in_EAX;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ *unaff_ESI;

  bool bVar6;

  

  bVar6 = (*(uint *)(in_EAX + 0x20) & *(uint *)(in_EAX + 0x24)) != 0xffffffff;

  if (bVar6) {

    uVar5 = CVOGReaction_ResolveObjectTarget(0,*(uint *)(in_EAX + 0x20),*(uint *)(in_EAX + 0x24));

    *unaff_ESI = uVar5;

  }

  bVar1 = 0 < *(int *)(in_EAX + 0x28);

  if (bVar1) {

    FUN_0092adf0(param_1,unaff_ESI,param_2);

  }

  bVar2 = 0 < *(int *)(in_EAX + 0x80);

  if (bVar2) {

    FUN_0092abc0(param_1,unaff_ESI,param_2);

  }

  bVar3 = 0 < *(int *)(in_EAX + 0x54);

  if (bVar3) {

    FUN_0092a980(param_1,unaff_ESI,param_2);

  }

  bVar3 = bVar3 || (bVar2 || (bVar1 || bVar6));

  if (0 < *(int *)(in_EAX + 0xac)) {

    cVar4 = FUN_0092a760(param_1,unaff_ESI,param_2);

    if (cVar4 == '\0') {

      FUN_00929cd0(in_EAX,param_1,unaff_ESI,param_2);

    }

    bVar3 = true;

  }

  return bVar3;

}
