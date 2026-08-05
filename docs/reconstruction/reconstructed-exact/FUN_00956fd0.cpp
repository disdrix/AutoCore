// =============================================================================
// FUN_00956fd0
// -----------------------------------------------------------------------------
// Stable ID: aa_00956fd0
// Address:   0x00956fd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00956fd0 @ 0x00956fd0
// Stable ID: aa_00956fd0
// Embedded strings (evidence for future rename):
//   - "MapName: %s, Map Global FX: %s, Daytime Effect:%s, Weather Effect:%s, Music: %s, Environme"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~59 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_00402bf0×2, FUN_00720d40×2, CVOGTerrain_SampleExploredAreaId, FUN_00553ce0, FUN_00555660, FUN_0071fcf0, FUN_0071fda0, FUN_007fe5b0.
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

uint32_t /* width from decompiler */ __fastcall FUN_00956fd0(int param_1)



{

  int iVar1;

  int iVar2;

  float *pfVar3;

  int *piVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint8_t auStack_434 [4];

  int iStack_430;

  int local_42c;

  uint32_t /* width from decompiler */ local_428;

  uint32_t /* width from decompiler */ local_424;

  float fStack_420;

  float fStack_418;

  uint8_t auStack_410 [255];

  uint8_t local_311;

  uint8_t auStack_310 [255];

  uint8_t local_211;

  char acStack_210 [524];

  

  iVar1 = *(int *)(param_1 + 0xe98);

  iVar2 = *(int *)(*(int *)(iVar1 + 4) + 4);

  local_428 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x164 + iVar1);

  local_424 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x168 + iVar1);

  local_42c = param_1;

  FUN_007fe5b0(param_1,local_428,local_424);

  if (*(int *)(param_1 + 0xe98) != 0) {

    iVar1 = *(int *)(param_1 + 0xe98);

    iVar2 = *(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 0xa8 + iVar1);

    if (iVar2 != 0) {

      local_311 = 0;

      local_211 = 0;

      pfVar3 = (float *)(**(code **)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1) + 0x1a0

                                    ))();

      fStack_418 = pfVar3[2];

      fStack_420 = *pfVar3;

      CVOGTerrain_SampleExploredAreaId(*(void **)(iVar2 + 0xe4f8),fStack_420,fStack_418);

      iStack_430 = *(int *)(*(int *)(iVar2 + 0x78) + 0x174);

      piVar4 = (int *)FUN_00402bf0(auStack_434);

      if (*piVar4 != iStack_430) {

        piVar4 = (int *)FUN_00402bf0(auStack_434);

        iVar1 = *piVar4;

        if (iVar1 != -0x10) {

          FUN_00553ce0(*(uint32_t /* width from decompiler */ *)(*(int *)(iVar2 + 0x78) + 0x150),auStack_410);

          FUN_00555660(*(uint32_t /* width from decompiler */ *)(iVar1 + 0x568),auStack_310);

        }

      }

      iVar1 = *(int *)(iVar2 + 0x78);

      uVar5 = FUN_00720d40();

      uVar5 = FUN_0071fcf0(uVar5);

      uVar5 = FUN_00720d40(uVar5);

      uVar5 = FUN_0071fda0(uVar5);

      sprintf(acStack_210,

              "MapName: %s, Map Global FX: %s, Daytime Effect:%s, Weather Effect:%s, Music: %s, Environment: %s"

              ,iVar2 + 0xb4,iVar1 + 0x44,auStack_410,auStack_310,uVar5);

      FUN_00800af0(local_42c,local_428,local_424,acStack_210,&DAT_00afdf0c);

    }

  }

  return 1;

}
