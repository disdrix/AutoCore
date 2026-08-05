// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RefreshOpen_008e5350
// -----------------------------------------------------------------------------
// Stable ID: aa_008e5350
// Callee of Named_CalleeOf_Named_CalleeOf_Client_RefreshOpenMissionUiWindow
// Address:   0x008e5350  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Client_RefreshOpenMissionUiWindow: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~51 non-empty decompiler lines.
//  - Control keywords: if×4, while×2, return×1.
//  - Notable callees: FUN_004022a0×4, FUN_004294f0×2, FUN_008e3c40×2, LeaveCriticalSection×2, FUN_0040ed60, FUN_0040f0c0, FUN_008e5350.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Client_RefreshOpenMissionUiWindow
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RefreshOpen_008e5350(int param_1)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ local_10;

  uint32_t /* width from decompiler */ local_c;

  uint8_t local_8 [8];

  

  iVar3 = param_1;

  piVar1 = (int *)(param_1 + 0x7f8);

  local_14 = 0;

  param_1 = 0;

  FUN_0040f0c0(*(uint32_t /* width from decompiler */ *)(*piVar1 + 4));

  *(int *)(*(int *)(iVar3 + 0x7f8) + 4) = *(int *)(iVar3 + 0x7f8);

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0x7fc) = 0;

  *(uint32_t /* width from decompiler */ *)*(uint32_t /* width from decompiler */ *)(iVar3 + 0x7f8) = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x7f8);

  *(int *)(*(int *)(iVar3 + 0x7f8) + 8) = *(int *)(iVar3 + 0x7f8);

  local_10 = 0xffffffff;

  local_c = 0;

  FUN_0040ed60(local_8,&local_10);

  iVar2 = *(int *)(*(int *)(DAT_00d1b6d8 + 0x250) + 0x2b0);

  if (iVar2 != -0x2c) {

    FUN_004294f0();

    iVar4 = FUN_004022a0(&local_14,&param_1);

    while (iVar4 == 0) {

      FUN_008e3c40();

      iVar4 = FUN_004022a0(&local_14,&param_1);

    }

    if (*(char *)(iVar2 + 0x54) != '\0') {

      *(uint8_t *)(iVar2 + 0x54) = 0;

      LeaveCriticalSection((LPCRITICAL_SECTION)(iVar2 + 0x30));

    }

  }

  if ((*(char *)(DAT_00d1b644 + 0xf5) != '\0') &&

     (iVar2 = *(int *)(DAT_00d1b6d8 + 0xcbc), iVar2 != -0x2c)) {

    FUN_004294f0();

    iVar4 = FUN_004022a0(&local_14,&param_1);

    while (iVar4 == 0) {

      FUN_008e3c40();

      iVar4 = FUN_004022a0(&local_14,&param_1);

    }

    if (*(char *)(iVar2 + 0x54) != '\0') {

      *(uint8_t *)(iVar2 + 0x54) = 0;

      LeaveCriticalSection((LPCRITICAL_SECTION)(iVar2 + 0x30));

    }

  }

  *(uint8_t *)(iVar3 + 0x7d9) = 1;

  return;

}
