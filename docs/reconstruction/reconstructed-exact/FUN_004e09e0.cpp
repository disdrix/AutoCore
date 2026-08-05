// =============================================================================
// FUN_004e09e0
// -----------------------------------------------------------------------------
// Stable ID: aa_004e09e0
// Address:   0x004e09e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004e09e0 @ 0x004e09e0
// Stable ID: aa_004e09e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00491220, FUN_004ce860, FUN_004ce8d0, FUN_004d5110, FUN_004dd940, FUN_004e09e0, FUN_004e88e0, FUN_0075de80.
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

void __fastcall FUN_004e09e0(int param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ local_3c;

  uint32_t /* width from decompiler */ local_38;

  uint32_t /* width from decompiler */ local_34;

  uint8_t local_30 [16];

  uint8_t local_20 [28];

  

  FUN_004ce8d0();

  FUN_004ce860();

  FUN_004dd940();

  if (*(char *)(param_1 + 0x7e) == '\0') {

    FUN_00797150(&local_3c);

  }

  else {

    FUN_004d5110(0xffffffff,0xffffffff,0xffffffff,local_20,local_30,0);

    puVar1 = (uint32_t /* width from decompiler */ *)FUN_004e88e0(local_30,local_20);

    local_3c = *puVar1;

    local_38 = puVar1[1];

    local_34 = puVar1[2];

  }

  FUN_00491220(local_3c,local_38,local_34);

  (**(code **)(**(int **)(*(int *)(param_1 + 0xe4a4) + 0xc4) + 0x18))();

  if (*(char *)(param_1 + 0xe8b4) == '\0') {

    FUN_0075de80(0,0x41200000);

    uVar2 = 1;

    FUN_007b6a20(1);

    FUN_007b7000(uVar2);

  }

  FUN_007ae100();

  return;

}
