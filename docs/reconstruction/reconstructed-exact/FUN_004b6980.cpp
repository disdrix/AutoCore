// =============================================================================
// FUN_004b6980
// -----------------------------------------------------------------------------
// Stable ID: aa_004b6980
// Address:   0x004b6980  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004b6980 @ 0x004b6980
// Stable ID: aa_004b6980
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_004b6980, FUN_004da2e0, Object_ResolveFromTFID.
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

void __fastcall FUN_004b6980(int param_1)



{

  void *pvVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint32_t /* width from decompiler */ uVar7;

  uint32_t /* width from decompiler */ uVar8;

  uint32_t /* width from decompiler */ uVar9;

  

  if (*(int *)(param_1 + 0x3c) != 0) {

    uVar9 = 0;

    uVar4 = 0;

    uVar3 = 1;

    uVar2 = 1;

    uVar5 = DAT_009cb2a0;

    uVar6 = DAT_009cb2a4;

    uVar7 = DAT_009cb2a8;

    uVar8 = DAT_009cb2ac;

    pvVar1 = Object_ResolveFromTFID((TFID_16 *)(param_1 + 0x48));

    FUN_004da2e0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x3c),*(uint32_t /* width from decompiler */ *)(param_1 + 0x40),pvVar1,uVar2,uVar3,

                 uVar4,uVar5,uVar6,uVar7,uVar8,uVar9);

    if (*(void **)(param_1 + 0x3c) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete(*(void **)(param_1 + 0x3c));

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x3c) = 0;

  }

  return;

}
