// READABILITY (auto CF):
//  - Body size: ~39 non-empty decompiler lines.
//  - Control keywords: if×5, goto×1, return×1.
//  - Notable callees: CVOGSectorMap_AddCharacter, CVOGSectorMap_DoCreatorLoadTrigger, CVOGSectorMap_DoPlayerOnLoadTrigger, FUN_004e39d0, path.
//  - Return sites: 1.

// =============================================================================
// CVOGSectorMap_AddCharacter
// -----------------------------------------------------------------------------
// Stable ID: aa_004d35c0
// Address:   0x004d35c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

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

/* CVOGSectorMap_AddCharacter: push character into sector list; maybe DoCreatorLoadTrigger once;

   always DoPlayerOnLoadTrigger. Invoked from character create path (FUN_00521310 /

   CreateFromPacket). */



void __thiscall CVOGSectorMap_AddCharacter(int param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ uVar3;

  bool bVar4;

  

  uVar3 = param_2;

  iVar1 = *(int *)(param_1 + 0xe75c);

  if ((iVar1 == 0) ||

     ((uint)(*(int *)(param_1 + 0xe764) - iVar1 >> 2) <=

      (uint)(*(int *)(param_1 + 0xe760) - iVar1 >> 2))) {

    FUN_004e39d0(*(uint32_t /* width from decompiler */ *)(param_1 + 0xe760),1,&param_2);

  }

  else {

    puVar2 = *(uint32_t /* width from decompiler */ **)(param_1 + 0xe760);

    *puVar2 = param_2;

    *(uint32_t /* width from decompiler */ **)(param_1 + 0xe760) = puVar2 + 1;

  }

  iVar1 = *(int *)(param_1 + 0xe75c);

  if (*(char *)(param_1 + 0xf6) == '\0') {

    if (iVar1 == 0) goto LAB_004d365d;

    bVar4 = *(int *)(param_1 + 0xe760) - iVar1 >> 2 == 1;

  }

  else if (iVar1 == 0) {

    bVar4 = *(int *)(*(int *)(param_1 + 0xe5d0) + 0xc) == 0;

  }

  else {

    bVar4 = *(int *)(param_1 + 0xe760) - iVar1 >> 2 == *(int *)(*(int *)(param_1 + 0xe5d0) + 0xc);

  }

  if (bVar4) {

    CVOGSectorMap_DoCreatorLoadTrigger(uVar3);

  }

LAB_004d365d:

  CVOGSectorMap_DoPlayerOnLoadTrigger(uVar3);

  return;

}
