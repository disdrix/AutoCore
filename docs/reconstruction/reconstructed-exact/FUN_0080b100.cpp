// =============================================================================
// FUN_0080b100
// -----------------------------------------------------------------------------
// Stable ID: aa_0080b100
// Address:   0x0080b100  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0080b100 @ 0x0080b100
// Stable ID: aa_0080b100
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×5, return×2.
//  - Notable callees: CNDHash_LookupByKey, CVOGReaction_FailMission, FUN_005307e0, FUN_0080b100, FUN_0092fd00.
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

void __fastcall FUN_0080b100(int param_1)



{

  char cVar1;

  int in_EAX;

  void *pvVar2;

  

  if (*(int *)(param_1 + 0xe98) != 0) {

    CVOGReaction_FailMission(*(uint32_t /* width from decompiler */ *)(in_EAX + 0x10));

    FUN_005307e0();

    if (*(int *)(param_1 + 0xe98) != 0) {

      pvVar2 = CNDHash_LookupByKey(*(void **)(*(int *)(param_1 + 0xe98) + 0x548),

                                   *(uint *)(DAT_00d1ad10 + 0x10));

      if (pvVar2 == (void *)0x0) {

        FUN_0092fd00();

      }

    }

    if (*(int *)(param_1 + 0x107c) != 0) {

      cVar1 = (**(code **)(**(int **)(param_1 + 0x107c) + 0x3d8))();

      if (cVar1 != '\0') {

                    /* WARNING: Could not recover jumptable at 0x0080b16d. Too many branches */

                    /* WARNING: Treating indirect jump as call */

        (**(code **)(**(int **)(param_1 + 0x107c) + 0x448))();

        return;

      }

    }

  }

  return;

}
