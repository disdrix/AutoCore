// =============================================================================
// Named_CalleeOf_Named_VOGClient_00933370
// -----------------------------------------------------------------------------
// Stable ID: aa_00933370
// Callee of Named_VOGClient (+1 other named callers)
// Address:   0x00933370  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOGClient: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_VOGClient (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~58 non-empty decompiler lines.
//  - Control keywords: if×4, return×3, do×1, while×1.
//  - Notable callees: FUN_00406040, FUN_0040fb90, FUN_00933370.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_VOGClient (+1 other named callers)
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

void __fastcall Named_CalleeOf_Named_VOGClient_00933370(int *param_1)



{

  int iVar1;

  int *piVar2;

  int *piVar3;

  int *piVar4;

  int *local_34;

  uint32_t /* width from decompiler */ local_30;

  uint32_t /* width from decompiler */ local_2c;

  int aiStack_28 [2];

  uint32_t /* width from decompiler */ uStack_20;

  int *piStack_1c;

  uint32_t /* width from decompiler */ uStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ad3cd;

  local_c = ExceptionList;

  if (param_1 == (int *)0x0) {

    return;

  }

  ExceptionList = &local_c;

  local_30 = FUN_0040fb90();

  local_2c = 0;

  local_4 = 0;

  (**(code **)(*param_1 + 0x2b0))(&local_34);

  piVar2 = local_34;

  piVar4 = (int *)*local_34;

  piVar3 = local_34;

  if (piVar4 != local_34) {

    do {

      iVar1 = piVar4[2];

      if (iVar1 != 0) {

        uStack_14 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x164);

        uStack_18 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x160);

        uStack_20 = *(uint32_t /* width from decompiler */ *)(*(int *)(iVar1 + 0xa8) + 0x34);

        piStack_1c = piVar2;

        aiStack_28[0] = iVar1;

        FUN_00406040(&stack0xffffffc0,aiStack_28);

        piVar3 = local_34;

      }

      piVar4 = (int *)*piVar4;

    } while (piVar4 != piVar3);

  }

  puStack_8 = (uint8_t *)0xffffffff;

  piVar4 = (int *)*local_34;

  *local_34 = (int)local_34;

  local_34[1] = (int)local_34;

  local_30 = 0;

  if (piVar4 == local_34) {

                    /* WARNING: Subroutine does not return */

    operator_delete(local_34);

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(piVar4);

}
