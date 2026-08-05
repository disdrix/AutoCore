// =============================================================================
// FUN_00435350
// -----------------------------------------------------------------------------
// Stable ID: aa_00435350
// Address:   0x00435350  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00435350 @ 0x00435350
// Stable ID: aa_00435350
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: for×2, if×1, return×1.
//  - Notable callees: FUN_00435350.
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

void __fastcall FUN_00435350(uint param_1,uint32_t /* width from decompiler */ *param_2)



{

  int in_EAX;

  uint uVar1;

  uint32_t /* width from decompiler */ *puVar2;

  

  if (((*(uint32_t /* width from decompiler */ **)(in_EAX + 0x10) != (uint32_t /* width from decompiler */ *)0x0) && (param_2 != (uint32_t /* width from decompiler */ *)0x0)) &&

     (0 < (int)param_1)) {

    puVar2 = *(uint32_t /* width from decompiler */ **)(in_EAX + 0x10);

    for (uVar1 = param_1 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {

      *param_2 = *puVar2;

      puVar2 = puVar2 + 1;

      param_2 = param_2 + 1;

    }

    for (param_1 = param_1 & 3; param_1 != 0; param_1 = param_1 - 1) {

      *(uint8_t *)param_2 = *(uint8_t *)puVar2;

      puVar2 = (uint32_t /* width from decompiler */ *)((int)puVar2 + 1);

      param_2 = (uint32_t /* width from decompiler */ *)((int)param_2 + 1);

    }

  }

  return;

}
