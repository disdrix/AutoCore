// =============================================================================
// FUN_0067ca70
// -----------------------------------------------------------------------------
// Stable ID: aa_0067ca70
// Address:   0x0067ca70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0067ca70 @ 0x0067ca70
// Stable ID: aa_0067ca70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, while×1.
//  - Notable callees: FUN_0067ca70.
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

void __fastcall FUN_0067ca70(int param_1)



{

  int *piVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int iVar4;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009a96c3;

  pvStack_c = ExceptionList;

  local_4 = 0;

  ExceptionList = &pvStack_c;

  while (*(int *)(param_1 + 4) != 0) {

    iVar2 = *(int *)(param_1 + 8);

    iVar4 = iVar2 - *(int *)(param_1 + 4) >> 2;

    if (iVar4 == 0) break;

    puVar3 = *(uint32_t /* width from decompiler */ **)(iVar2 + -4);

    if (iVar4 != 0) {

      *(int *)(param_1 + 8) = iVar2 + -4;

    }

    piVar1 = puVar3 + 5;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)*puVar3)(1);

    }

  }

  if (*(void **)(param_1 + 4) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 4));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 0;

  ExceptionList = pvStack_c;

  return;

}
