// =============================================================================
// FUN_0049a120
// -----------------------------------------------------------------------------
// Stable ID: aa_0049a120
// Address:   0x0049a120  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0049a120 @ 0x0049a120
// Stable ID: aa_0049a120
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~45 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, while×1, return×1.
//  - Notable callees: FUN_00498b00, FUN_00499580, FUN_00499ee0, FUN_0049a120, FUN_0049c560, FUN_0049c6b0.
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

int __fastcall FUN_0049a120(int param_1)



{

  void *pvVar1;

  int iVar2;

  int iVar3;

  int *piVar4;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a0eae;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  pvVar1 = operator_new(0x1e0);

  iVar3 = 0;

  local_4 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar3 = FUN_00499580();

  }

  local_4 = 0xffffffff;

  FUN_0049c6b0(param_1 + 0x48);

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0x170) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x170);

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0x174) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x174);

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0x178) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x178);

  *(int *)(iVar3 + 0x19c) = param_1;

  piVar4 = *(int **)(param_1 + 0x1d0);

  if (piVar4 != *(int **)(param_1 + 0x1d4)) {

    do {

      pvVar1 = operator_new(0x84);

      if (pvVar1 == (void *)0x0) {

        iVar2 = 0;

      }

      else {

        iVar2 = FUN_00498b00(iVar3);

      }

      FUN_0049c560(*piVar4);

      *(uint8_t *)(iVar2 + 0x7c) = *(uint8_t *)(*piVar4 + 0x7c);

      *(uint32_t /* width from decompiler */ *)(iVar2 + 0x78) = *(uint32_t /* width from decompiler */ *)(*piVar4 + 0x78);

      FUN_00499ee0(iVar2);

      piVar4 = piVar4 + 1;

    } while (piVar4 != *(int **)(param_1 + 0x1d4));

  }

  ExceptionList = local_c;

  return iVar3;

}
