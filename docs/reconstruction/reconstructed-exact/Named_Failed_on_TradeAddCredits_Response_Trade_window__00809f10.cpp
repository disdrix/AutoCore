// READABILITY (auto CF):
//  - Body size: ~52 non-empty decompiler lines.
//  - Control keywords: if×5, return×5.
//  - Notable callees: FUN_007fdfb0×3, FUN_00883d50×2, Client_LookupObjectByTfid_Inferred, FUN_00809f10, TradeAddCredits_Response, exist, found.
//  - Strings: "Failed on TradeAddCredits_Response (Get a programmer).".
//  - Return sites: 5.

// =============================================================================
// Named_Failed_on_TradeAddCredits_Response_Trade_window__00809f10
// -----------------------------------------------------------------------------
// Stable ID: aa_00809f10
// Address:   0x00809f10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "Failed on TradeAddCredits_Response Trade window doesn't exist(Get a programmer)."
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_Failed_on_TradeAddCredits_Response_Trade_window__00809f10(void)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  uint nCoidLo;

  uint nCoidHi;

  void *pvVar4;

  int unaff_ESI;

  int unaff_EDI;

  

  if (*(char *)(unaff_ESI + 0x28) == '\0') {

    FUN_007fdfb0(unaff_EDI,"Failed on TradeAddCredits_Response (Get a programmer).",0xffffffff,1,0);

    return;

  }

  piVar1 = *(int **)(unaff_EDI + 0x1050);

  if (piVar1 == (int *)0x0) {

    FUN_007fdfb0(unaff_EDI,

                 "Failed on TradeAddCredits_Response Trade window doesn\'t exist(Get a programmer)."

                 ,0xffffffff,1,0);

    return;

  }

  iVar2 = *(int *)(unaff_EDI + 0xe98);

  iVar3 = *(int *)(*(int *)(iVar2 + 4) + 4);

  if ((*(uint *)(unaff_ESI + 0x10) == *(uint *)(iVar3 + 0x164 + iVar2)) &&

     (*(int *)(unaff_ESI + 0x14) == *(int *)(iVar3 + 0x168 + iVar2))) {

    *(uint32_t /* width from decompiler */ *)(iVar2 + 0xce8) = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x18);

    *(uint32_t /* width from decompiler */ *)(iVar2 + 0xcec) = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x1c);

    FUN_00883d50(1,*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x18),*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x1c));

                    /* WARNING: Could not recover jumptable at 0x00809f9f. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (**(code **)(*piVar1 + 0x34c))();

    return;

  }

  nCoidLo = *(uint *)(*(int *)(unaff_EDI + 0xe98) + 0xcd8);

  nCoidHi = *(uint *)(*(int *)(unaff_EDI + 0xe98) + 0xcdc);

  if ((*(uint *)(unaff_ESI + 0x10) == nCoidLo) && (*(uint *)(unaff_ESI + 0x14) == nCoidHi)) {

    pvVar4 = Client_LookupObjectByTfid_Inferred(1,nCoidLo,nCoidHi);

    if (pvVar4 != (void *)0x0) {

      *(uint32_t /* width from decompiler */ *)((int)pvVar4 + 0xce8) = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x18);

      *(uint32_t /* width from decompiler */ *)((int)pvVar4 + 0xcec) = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x1c);

      FUN_00883d50(0,*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x18),*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x1c));

                    /* WARNING: Could not recover jumptable at 0x0080a01a. Too many branches */

                    /* WARNING: Treating indirect jump as call */

      (**(code **)(*piVar1 + 0x34c))();

      return;

    }

    FUN_007fdfb0(unaff_EDI,

                 "Failed on TradeAddCredits_Response Target character not found(Get a programmer).",

                 0xffffffff,1,0);

  }

  return;

}
