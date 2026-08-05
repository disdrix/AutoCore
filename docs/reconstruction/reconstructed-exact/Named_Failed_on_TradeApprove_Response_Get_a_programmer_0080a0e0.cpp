// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: FUN_007fdfb0, FUN_0080a0e0, TradeApprove_Response.
//  - Strings: "Failed on TradeApprove_Response (Get a programmer).".
//  - Return sites: 2.

// =============================================================================
// Named_Failed_on_TradeApprove_Response_Get_a_programmer_0080a0e0
// -----------------------------------------------------------------------------
// Stable ID: aa_0080a0e0
// Address:   0x0080a0e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "Failed on TradeApprove_Response (Get a programmer)."
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_Failed_on_TradeApprove_Response_Get_a_programmer_0080a0e0(void)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  int in_EAX;

  int unaff_ESI;

  

  if (*(char *)(unaff_ESI + 0x11) == '\0') {

    FUN_007fdfb0(in_EAX,"Failed on TradeApprove_Response (Get a programmer).",0xffffffff,1,0);

  }

  piVar1 = *(int **)(in_EAX + 0x1050);

  if (piVar1 != (int *)0x0) {

    iVar2 = *(int *)(in_EAX + 0xe98);

    iVar3 = *(int *)(*(int *)(iVar2 + 4) + 4);

    if ((*(int *)(unaff_ESI + 8) == *(int *)(iVar3 + 0x164 + iVar2)) &&

       (*(int *)(unaff_ESI + 0xc) == *(int *)(iVar3 + 0x168 + iVar2))) {

      *(uint8_t *)(piVar1 + 0x143) = *(uint8_t *)(unaff_ESI + 0x10);

    }

    if ((*(int *)(unaff_ESI + 8) == *(int *)(*(int *)(in_EAX + 0xe98) + 0xcd8)) &&

       (*(int *)(unaff_ESI + 0xc) == *(int *)(*(int *)(in_EAX + 0xe98) + 0xcdc))) {

      *(uint8_t *)((int)piVar1 + 0x50d) = *(uint8_t *)(unaff_ESI + 0x10);

    }

                    /* WARNING: Could not recover jumptable at 0x0080a160. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (**(code **)(*piVar1 + 0x448))();

    return;

  }

  return;

}
