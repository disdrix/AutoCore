// =============================================================================
// FUN_0080af70
// -----------------------------------------------------------------------------
// Stable ID: aa_0080af70
// Address:   0x0080af70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0080af70 @ 0x0080af70
// Stable ID: aa_0080af70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~65 non-empty decompiler lines.
//  - Control keywords: if×6, return×3.
//  - Notable callees: CVOGReaction_GiveItemByCbid, CVOGReaction_ResolveObjectTarget, FUN_004027f0, FUN_00418d70, FUN_004dbef0, FUN_004de760, FUN_007a4480, FUN_00807550.
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

void FUN_0080af70(void)



{

  char cVar1;

  int in_EAX;

  int iVar2;

  int *piVar3;

  int iVar4;

  int unaff_ESI;

  bool bVar5;

  int iStack_30;

  uint32_t /* width from decompiler */ uStack_2c;

  uint uStack_28;

  uint uStack_24;

  uint32_t /* width from decompiler */ uStack_20;

  uint32_t /* width from decompiler */ uStack_1c;

  

  uStack_1c = 0x80af96;

  iVar2 = CVOGReaction_ResolveObjectTarget();

  if (iVar2 == 0) {

    uStack_1c = 0x80afa9;

    piVar3 = (int *)CVOGReaction_GiveItemByCbid(*(int *)(in_EAX + 4));

    if ((piVar3 != (int *)0x0) && (iVar2 = (**(code **)(*piVar3 + 0x1d8))(), iVar2 != 0)) {

      uStack_1c = *(uint32_t /* width from decompiler */ *)(in_EAX + 4);

      uStack_20 = 0x80afdc;

      (**(code **)(*piVar3 + 8))();

      bVar5 = (*(uint *)(in_EAX + 0xf8) & *(uint *)(in_EAX + 0xfc)) == 0xffffffff;

      iStack_30 = *(int *)(unaff_ESI + 0xe04);

      uStack_20 = 0;

      uStack_24 = (uint)bVar5;

      uStack_28 = (uint)bVar5;

      uStack_2c = 1;

      (**(code **)(*piVar3 + 0xc4))();

      iVar2 = *(int *)(unaff_ESI + 0x4d0);

      cVar1 = FUN_0092a200();

      if (cVar1 != '\0') {

        *(uint8_t *)(iVar2 + 4) = 1;

      }

      iVar2 = (**(code **)(*piVar3 + 0x1d8))();

      iStack_30 = iVar2;

      FUN_004027f0(unaff_ESI + 0xf08);

      if (iVar2 == 0) {

        iVar4 = 0;

      }

      else {

        iVar4 = *(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2;

      }

      FUN_00807550(iVar4);

      if (((piVar3[0xe] & piVar3[0xf]) != 0xffffffff) && (*(int *)(piVar3[0x2a] + 0x38) != 0x36)) {

        FUN_004dbef0(piVar3,0,piVar3[0xe],piVar3[0xf],0xffffffff);

      }

      if (*(int *)(unaff_ESI + 0xe98) != 0) {

        FUN_004de760(*(int *)(unaff_ESI + 0xe98),iVar2);

        return;

      }

      iVar4 = *(int *)(*(int *)(iVar2 + 4) + 4);

      iStack_30 = *(int *)(iVar4 + 0x164 + iVar2);

      uStack_2c = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x168 + iVar2);

      FUN_00418d70(&iStack_30);

      return;

    }

    uStack_1c = 1;

    uStack_20 = 0x80b0f0;

    FUN_007a4480();

  }

  return;

}
