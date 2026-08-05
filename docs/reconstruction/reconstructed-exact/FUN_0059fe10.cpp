// =============================================================================
// FUN_0059fe10
// -----------------------------------------------------------------------------
// Stable ID: aa_0059fe10
// Address:   0x0059fe10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0059fe10 @ 0x0059fe10
// Stable ID: aa_0059fe10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×4, return×4.
//  - Notable callees: BitStream_readBits×2, FUN_0042be50, FUN_0059fe10, FUN_00974ee0.
//  - Return sites: 4.

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

uint32_t /* width from decompiler */ __thiscall FUN_0059fe10(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ *param_3)



{

  uint32_t /* width from decompiler */ *puVar1;

  char cVar2;

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  puVar1 = param_3;

  cVar2 = FUN_00974ee0(param_2,param_3);

  if (cVar2 != '\0') {

    cVar2 = BitStream_readBits(0x20,&param_3);

    if ((cVar2 == '\0') || (param_3 != *(uint32_t /* width from decompiler */ **)(*(int *)(param_1 + 0x1a8) + 0xa8))) {

      *puVar1 = PTR_DAT_00af3de0;

      return 0;

    }

    cVar2 = BitStream_readBits(0x20,&param_3);

    if (cVar2 == '\0') {

      *puVar1 = PTR_DAT_00af3de8;

      return 0;

    }

    *(uint32_t /* width from decompiler */ **)(param_1 + 0x250) = param_3;

    cVar2 = FUN_0042be50(&local_8);

    if (cVar2 != '\0') {

      *(uint32_t /* width from decompiler */ *)(param_1 + 600) = local_8;

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x25c) = local_4;

      return 1;

    }

    *puVar1 = PTR_DAT_00af3de4;

  }

  return 0;

}
