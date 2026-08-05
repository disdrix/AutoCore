// =============================================================================
// FUN_00674a70
// -----------------------------------------------------------------------------
// Stable ID: aa_00674a70
// Address:   0x00674a70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00674a70 @ 0x00674a70
// Stable ID: aa_00674a70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, do×1, while×1.
//  - Notable callees: CONCAT31, FUN_00674a70, FUN_00676730, FUN_006793f0.
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

void __fastcall FUN_00674a70(uint32_t /* width from decompiler */ *param_1)



{

  void *pvVar1;

  int *piVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint8_t local_10 [4];

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009a9458;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  *param_1 = &PTR_FUN_009e8488;

  puVar3 = (uint32_t /* width from decompiler */ *)param_1[0x4a];

  local_4 = 6;

  if (puVar3 != (uint32_t /* width from decompiler */ *)param_1[0x4b]) {

    do {

      pvVar1 = (void *)*puVar3;

      if (pvVar1 != (void *)0x0) {

        FUN_006793f0();

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar1);

      }

      puVar3 = puVar3 + 1;

    } while (puVar3 != (uint32_t /* width from decompiler */ *)param_1[0x4b]);

  }

  piVar2 = (int *)param_1[0x57];

  if (piVar2 != (int *)0x0) {

    (**(code **)(*piVar2 + 8))(piVar2);

    param_1[0x57] = 0;

  }

  local_4 = CONCAT31(local_4._1_3_,5);

  FUN_00676730(local_10,*(uint32_t /* width from decompiler */ *)param_1[0x59],(uint32_t /* width from decompiler */ *)param_1[0x59]);

                    /* WARNING: Subroutine does not return */

  operator_delete((void *)param_1[0x59]);

}
