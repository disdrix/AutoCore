// =============================================================================
// FUN_0066c620
// -----------------------------------------------------------------------------
// Stable ID: aa_0066c620
// Address:   0x0066c620  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0066c620 @ 0x0066c620
// Stable ID: aa_0066c620
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~39 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_005d6ae0×2, FUN_005070b0, FUN_005070d0, FUN_005d6a40, FUN_0066c620.
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

void __fastcall FUN_0066c620(int param_1)



{

  int iVar1;

  int iVar2;

  char *pcVar3;

  uint8_t uStack_65;

  uint8_t auStack_64 [4];

  float local_60;

  float local_5c;

  float local_58;

  float local_54;

  float local_50;

  float local_4c;

  float local_48;

  uint8_t auStack_44 [4];

  uint8_t local_40 [60];

  

  if (*(char *)(param_1 + 0x38) != '\0') {

    iVar2 = *(int *)(*(int *)(param_1 + 0x18) + 0x3c);

    iVar1 = iVar2 + 0x80;

    FUN_005d6a40(iVar1,iVar2 + 0x50);

    local_54 = (*(float *)(param_1 + 0x30) -

               (*(float *)(param_1 + 0x28) * local_48 + *(float *)(param_1 + 0x24) * local_4c +

               *(float *)(param_1 + 0x20) * local_50)) * *(float *)(param_1 + 0x34);

    local_60 = *(float *)(param_1 + 0x20) * local_54;

    local_5c = *(float *)(param_1 + 0x24) * local_54;

    local_58 = *(float *)(param_1 + 0x28) * local_54;

    local_54 = *(float *)(param_1 + 0x2c) * local_54;

    (**(code **)(**(int **)(*(int *)(param_1 + 0x18) + 0x3c) + 0x24))(local_40);

    FUN_005d6ae0(auStack_44,auStack_64);

    FUN_005d6ae0(iVar1,auStack_64);

    iVar1 = *(int *)(param_1 + 0x18);

    pcVar3 = (char *)FUN_005070b0(&uStack_65);

    if ((*pcVar3 == '\0') && (*(int *)(iVar1 + 0x44) != 0)) {

      FUN_005070d0();

    }

    (**(code **)(**(int **)(iVar1 + 0x3c) + 0x70))(auStack_64);

  }

  return;

}
