// =============================================================================
// FUN_004f26e0
// -----------------------------------------------------------------------------
// Stable ID: aa_004f26e0
// Address:   0x004f26e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004f26e0 @ 0x004f26e0
// Stable ID: aa_004f26e0
// Embedded strings (evidence for future rename):
//   - ".geo"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~55 non-empty decompiler lines.
//  - Control keywords: if×5, for×1, return×1.
//  - Notable callees: FUN_004eb0f0×2, FUN_004eb1c0, FUN_004f1ff0, FUN_004f26e0, FUN_005b2ba0, FUN_0099c160, _stricmp, strrchr.
//  - Strings: ".geo".
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

void FUN_004f26e0(uint32_t /* width from decompiler */ param_1)



{

  char cVar1;

  uint uVar2;

  char *pcVar3;

  int iVar4;

  uint uVar5;

  uint uVar6;

  uint8_t local_24 [4];

  uint8_t local_20 [4];

  int local_1c;

  uint local_18;

  uint local_14;

  int local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a2bd0;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_004eb1c0(local_24);

  cVar1 = FUN_004eb0f0(param_1);

  if (cVar1 != '\0') {

    local_1c = 0;

    local_18 = 0;

    local_14 = 0;

    local_10 = 0;

    local_4 = 0;

    FUN_004f1ff0(local_20);

    for (uVar5 = local_14; uVar5 != local_14 + local_10; uVar5 = uVar5 + 1) {

      uVar6 = uVar5 >> 2;

      uVar2 = uVar6;

      if (local_18 <= uVar6) {

        uVar2 = uVar6 - local_18;

      }

      pcVar3 = *(char **)(*(int *)(local_1c + uVar2 * 4) + (uVar5 + uVar6 * -4) * 4);

      if (pcVar3 == (char *)0x0) {

        pcVar3 = PTR_DAT_00afa2bc;

      }

      pcVar3 = strrchr(pcVar3,0x2e);

      if (((pcVar3 == (char *)0x0) || (iVar4 = _stricmp(pcVar3,".geo"), iVar4 != 0)) ||

         (cVar1 = FUN_004eb0f0(param_1), cVar1 != '\0')) {

        iVar4 = uVar6 * -4;

        if (local_18 <= uVar6) {

          uVar6 = uVar6 - local_18;

        }

        FUN_0099c160(local_24,*(int *)(local_1c + uVar6 * 4) + (uVar5 + iVar4) * 4);

      }

    }

    FUN_005b2ba0();

  }

  ExceptionList = local_c;

  return;

}
