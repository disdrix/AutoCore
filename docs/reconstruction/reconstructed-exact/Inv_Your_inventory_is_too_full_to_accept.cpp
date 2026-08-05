// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: CONCAT22, Client_SendSectorPacket, FUN_00521e90, FUN_007fdfb0, FUN_0094caa0.
//  - Strings: "Your inventory is too full to accept.".
//  - Return sites: 2.

// =============================================================================
// Inv_Your_inventory_is_too_full_to_accept
// -----------------------------------------------------------------------------
// Stable ID: aa_0094caa0
// Address:   0x0094caa0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "Your inventory is too full to accept."
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Inv_Your_inventory_is_too_full_to_accept(void)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  char cVar4;

  uint16_t extraout_var;

  char unaff_BL;

  void *unaff_ESI;

  uint32_t /* width from decompiler */ auStack_18 [2];

  uint32_t /* width from decompiler */ uStack_10;

  uint32_t /* width from decompiler */ uStack_c;

  

  if ((((*(int *)((int)unaff_ESI + 0xe98) != 0) &&

       (piVar1 = *(int **)((int)unaff_ESI + 0x1050), piVar1 != (int *)0x0)) &&

      (cVar4 = (**(code **)(*piVar1 + 0x3d8))(), cVar4 != '\0')) &&

     (*(int *)(*(int *)((int)unaff_ESI + 0xe98) + 0x250) != 0)) {

    if ((unaff_BL != '\0') &&

       (iVar2 = *(int *)(*(int *)((int)unaff_ESI + 0xe98) + 0x250),

       cVar4 = FUN_00521e90(*(uint32_t /* width from decompiler */ *)(piVar1[0x144] + 0xce0),*(uint32_t /* width from decompiler */ *)(iVar2 + 0x2b0),

                            CONCAT22(extraout_var,*(uint16_t *)(iVar2 + 0x1e6))), cVar4 == '\0'))

    {

      FUN_007fdfb0(unaff_ESI,"Your inventory is too full to accept.",0xffffffff,1,0);

      return;

    }

    iVar2 = *(int *)((int)unaff_ESI + 0xe98);

    auStack_18[0] = 0x208f;

    iVar3 = *(int *)(*(int *)(iVar2 + 4) + 4);

    uStack_10 = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x164 + iVar2);

    uStack_c = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x168 + iVar2);

    Client_SendSectorPacket(unaff_ESI,0x18,auStack_18);

  }

  return;

}
