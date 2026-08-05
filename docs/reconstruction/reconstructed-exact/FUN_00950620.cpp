// =============================================================================
// FUN_00950620
// -----------------------------------------------------------------------------
// Stable ID: aa_00950620
// Address:   0x00950620  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00950620 @ 0x00950620
// Stable ID: aa_00950620
// Embedded strings (evidence for future rename):
//   - "switch"
//   - "special"
//   - "override"
//   - "reload"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~65 non-empty decompiler lines.
//  - Control keywords: if×10, return×7, switch×1.
//  - Notable callees: strstr×6, strtok×4, atof×3, CONCAT31, FUN_00555050, FUN_00555bf0, FUN_00556450, FUN_00556880.
//  - Strings: "wea"; "switch"; "special"; "override".
//  - Return sites: 7.

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

uint32_t /* width from decompiler */ __thiscall FUN_00950620(int param_1,uint32_t /* width from decompiler */ param_2,char *param_3)



{

  uchar uVar1;

  char *pcVar2;

  char *pcVar3;

  float *pfVar4;

  double dVar5;

  float local_2c;

  float local_24;

  

  local_24 = 0.0;

  local_2c = 0.0;

  pcVar2 = strtok((char *)0x0,param_3);

  if (pcVar2 == (char *)0x0) {

    return 1;

  }

  pcVar3 = strtok((char *)0x0,param_3);

  if (pcVar3 != (char *)0x0) {

    dVar5 = atof(pcVar3);

    local_2c = (float)dVar5;

  }

  pcVar3 = strtok((char *)0x0,param_3);

  if (pcVar3 != (char *)0x0) {

    dVar5 = atof(pcVar3);

    local_24 = (float)dVar5;

  }

  pcVar3 = strtok((char *)0x0,param_3);

  if (pcVar3 != (char *)0x0) {

    atof(pcVar3);

  }

  pcVar3 = strstr(pcVar2,"ti");

  if (pcVar3 != (char *)0x0) {

    FUN_00556880((int)local_2c,local_24);

    return 0;

  }

  pcVar3 = strstr(pcVar2,"wea");

  if (pcVar3 != (char *)0x0) {

    FUN_00555bf0((int)local_2c,local_24,0);

    return 0;

  }

  pcVar3 = strstr(pcVar2,"switch");

  if (pcVar3 != (char *)0x0) {

    *(int *)(*(int *)(*(int *)(param_1 + 0xe04) + 0x78) + 0x3c) = (int)ROUND(local_2c);

    return 0;

  }

  pcVar3 = strstr(pcVar2,"special");

  if (pcVar3 != (char *)0x0) {

    pfVar4 = (float *)(**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0xe98) + 4) + 4) +

                                            4 + *(int *)(param_1 + 0xe98)) + 0x1a0))();

    uVar1 = CVOGTerrain_SampleExploredAreaId

                      (*(void **)(*(int *)(param_1 + 0xe04) + 0xe4f8),*pfVar4,pfVar4[2]);

    local_24 = (float)CONCAT31(local_24._1_3_,uVar1);

    FUN_00556450(local_24);

    return 0;

  }

  pcVar3 = strstr(pcVar2,"override");

  if (pcVar3 != (char *)0x0) {

    *(float *)(*(int *)(*(int *)(param_1 + 0xe04) + 0x78) + 0x24) = local_2c;

    return 0;

  }

  pcVar2 = strstr(pcVar2,"reload");

  if (pcVar2 != (char *)0x0) {

    FUN_00555050();

  }

  return 0;

}
