// =============================================================================
// FUN_0072b540
// -----------------------------------------------------------------------------
// Stable ID: aa_0072b540
// Address:   0x0072b540  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0072b540 @ 0x0072b540
// Stable ID: aa_0072b540
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~47 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, while×1, return×1.
//  - Notable callees: FUN_00456960, FUN_0046d070, FUN_0072b310, FUN_0072b380, FUN_0072b540.
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

int FUN_0072b540(int param_1,int param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  void *pvVar3;

  uint32_t /* width from decompiler */ uVar4;

  int iVar5;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009abebd;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0072b380(param_2);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x40) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x44) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x48) = 0;

  local_4 = 1;

  iVar5 = *(int *)(param_2 + 0x40);

  if (iVar5 != *(int *)(param_2 + 0x44)) {

    do {

      pvVar3 = operator_new(0x50);

      if (pvVar3 == (void *)0x0) {

        uVar4 = 0;

      }

      else {

        uVar4 = FUN_0046d070();

      }

      iVar1 = *(int *)(param_1 + 0x40);

      if ((iVar1 == 0) ||

         ((uint)(*(int *)(param_1 + 0x48) - iVar1 >> 2) <=

          (uint)(*(int *)(param_1 + 0x44) - iVar1 >> 2))) {

        FUN_00456960(*(uint32_t /* width from decompiler */ *)(param_1 + 0x44));

      }

      else {

        puVar2 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x44);

        *puVar2 = uVar4;

        *(uint32_t /* width from decompiler */ **)(param_1 + 0x44) = puVar2 + 1;

      }

      FUN_0072b310(uVar4,DAT_00afa624);

      iVar5 = iVar5 + 4;

    } while (iVar5 != *(int *)(param_2 + 0x44));

  }

  ExceptionList = local_c;

  return param_1;

}
