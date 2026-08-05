// =============================================================================
// FUN_005fc620
// -----------------------------------------------------------------------------
// Stable ID: aa_005fc620
// Address:   0x005fc620  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005fc620 @ 0x005fc620
// Stable ID: aa_005fc620
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_005fc620.
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

void FUN_005fc620(int param_1,uint32_t /* width from decompiler */ param_2,int param_3)



{

  uint32_t /* width from decompiler */ uVar1;

  uint32_t /* width from decompiler */ uVar2;

  

  *(uint32_t /* width from decompiler */ *)(param_3 + 0x28) =

       *(uint32_t /* width from decompiler */ *)

        (*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c) + 0x5c4);

  *(uint32_t /* width from decompiler */ *)(param_3 + 0x2c) =

       *(uint32_t /* width from decompiler */ *)

        (*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c) + 0x5c8);

  *(uint32_t /* width from decompiler */ *)(param_3 + 0x30) =

       *(uint32_t /* width from decompiler */ *)

        (*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c) + 0x5cc);

  uVar2 = DAT_00af4618;

  *(uint32_t /* width from decompiler */ *)(param_3 + 0x34) =

       *(uint32_t /* width from decompiler */ *)

        (*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c) + 0x5d0);

  uVar1 = *(uint32_t /* width from decompiler */ *)

           (*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c) + 0x5d8)

  ;

  *(uint32_t /* width from decompiler */ *)(param_3 + 0x3c) = uVar2;

  uVar2 = DAT_00af4614;

  *(uint32_t /* width from decompiler */ *)(param_3 + 0x38) = uVar1;

  *(uint32_t /* width from decompiler */ *)(param_3 + 0x40) = uVar2;

  *(uint32_t /* width from decompiler */ *)(param_3 + 0x44) =

       *(uint32_t /* width from decompiler */ *)

        (*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c) + 0x5e4);

  *(uint32_t /* width from decompiler */ *)(param_3 + 0x48) =

       *(uint32_t /* width from decompiler */ *)

        (*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c) + 0x5dc);

  *(uint32_t /* width from decompiler */ *)(param_3 + 0x4c) =

       *(uint32_t /* width from decompiler */ *)

        (*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c) + 0x5e0);

  return;

}
