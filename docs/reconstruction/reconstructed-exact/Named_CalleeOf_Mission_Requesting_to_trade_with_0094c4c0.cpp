// =============================================================================
// Named_CalleeOf_Mission_Requesting_to_trade_with_0094c4c0
// -----------------------------------------------------------------------------
// Stable ID: aa_0094c4c0
// Callee of Mission_Requesting_to_trade_with (+1 other named callers)
// Address:   0x0094c4c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Mission_Requesting_to_trade_with: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Mission_Requesting_to_trade_with (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_0094c4c0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Mission_Requesting_to_trade_with (+1 other named callers)
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

void Named_CalleeOf_Mission_Requesting_to_trade_with_0094c4c0(uint8_t param_1)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  char cVar4;

  int unaff_ESI;

  uint32_t /* width from decompiler */ local_20 [2];

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ local_10;

  uint32_t /* width from decompiler */ local_c;

  uint8_t local_8;

  uint8_t local_7;

  

  if ((*(int *)(unaff_ESI + 0xe98) != 0) &&

     (((piVar1 = *(int **)(unaff_ESI + 0x1050), piVar1 == (int *)0x0 ||

       (cVar4 = (**(code **)(*piVar1 + 0x3d8))(), cVar4 == '\0')) ||

      (cVar4 = (**(code **)(*piVar1 + 0xd0))(), cVar4 == '\0')))) {

    local_7 = param_1;

    iVar2 = *(int *)(unaff_ESI + 0xe98);

    local_20[0] = 0x2085;

    local_8 = 0;

    iVar3 = *(int *)(*(int *)(iVar2 + 4) + 4);

    local_18 = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x164 + iVar2);

    local_14 = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x168 + iVar2);

    local_10 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0xcd8);

    local_c = *(uint32_t /* width from decompiler */ *)(iVar2 + 0xcdc);

    if (*(int *)(unaff_ESI + 0xc78) != 0) {

      (**(code **)(**(int **)(unaff_ESI + 0xc78) + 0x18))(0xffffffff,local_20,0x20,0);

    }

  }

  return;

}
