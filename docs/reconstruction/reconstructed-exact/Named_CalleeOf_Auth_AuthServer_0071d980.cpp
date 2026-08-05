// =============================================================================
// Named_CalleeOf_Auth_AuthServer_0071d980
// -----------------------------------------------------------------------------
// Stable ID: aa_0071d980
// Callee of Auth_AuthServer
// Address:   0x0071d980  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Auth_AuthServer: auth/session helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~60 non-empty decompiler lines.
//  - Control keywords: do×4, while×4, for×2, return×1.
//  - Notable callees: FUN_0071d530×2, CONCAT11, CONCAT21, CONCAT31, FUN_0071d980.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Auth_AuthServer
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

uint32_t /* width from decompiler */ Named_CalleeOf_Auth_AuthServer_0071d980(int param_1,short param_2)



{

  int iVar1;

  uint *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int iVar4;

  uint32_t /* width from decompiler */ *puVar5;

  int local_4;

  

  puVar5 = &DAT_00afa9c0;

  puVar3 = &DAT_00afba08;

  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar3 = *puVar5;

    puVar5 = puVar5 + 1;

    puVar3 = puVar3 + 1;

  }

  puVar5 = &DAT_00afaa08;

  puVar3 = &DAT_00afba50;

  for (iVar1 = 0x400; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar3 = *puVar5;

    puVar5 = puVar5 + 1;

    puVar3 = puVar3 + 1;

  }

  iVar4 = (int)param_2;

  iVar1 = 0;

  local_4 = 0x12;

  puVar2 = &DAT_00afba08;

  do {

    iVar1 = (int)(short)iVar1;

    *puVar2 = *puVar2 ^ CONCAT31(CONCAT21(CONCAT11(*(uint8_t *)(iVar1 + param_1),

                                                   *(uint8_t *)((iVar1 + 1) % iVar4 + param_1)),

                                          *(uint8_t *)((iVar1 + 2) % iVar4 + param_1)),

                                 *(uint8_t *)((iVar1 + 3) % iVar4 + param_1));

    iVar1 = (iVar1 + 4) % iVar4;

    local_4 = local_4 + -1;

    puVar2 = puVar2 + 1;

  } while (local_4 != 0);

  puVar5 = &DAT_00afba0c;

  iVar1 = 9;

  do {

    FUN_0071d530();

    puVar5[-1] = 0;

    *puVar5 = 0;

    puVar5 = puVar5 + 2;

    iVar1 = iVar1 + -1;

  } while (iVar1 != 0);

  puVar5 = &DAT_00afba54;

  iVar1 = 4;

  do {

    iVar4 = 0x80;

    do {

      FUN_0071d530();

      puVar5[-1] = 0;

      *puVar5 = 0;

      puVar5 = puVar5 + 2;

      iVar4 = iVar4 + -1;

    } while (iVar4 != 0);

    iVar1 = iVar1 + -1;

  } while (iVar1 != 0);

  return 0;

}
