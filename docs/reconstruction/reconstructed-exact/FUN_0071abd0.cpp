// =============================================================================
// FUN_0071abd0
// -----------------------------------------------------------------------------
// Stable ID: aa_0071abd0
// Address:   0x0071abd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0071abd0 @ 0x0071abd0
// Stable ID: aa_0071abd0
// Embedded strings (evidence for future rename):
//   - "Error: uncompress buffer not large enough.\n"
//   - "Error: Not enough memory.\n"
//   - "Error: compressed data is bad!.\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~89 non-empty decompiler lines.
//  - Control keywords: return×7, if×6, for×2, switch×1.
//  - Notable callees: printf×3, FUN_00483250×2, FUN_0047f700, FUN_00481db0, FUN_004830e0, FUN_0071abd0.
//  - Strings: "Error: uncompress buffer not large enough.\n"; "Error: Not enough memory.\n"; "Error: compressed data is bad!.\n".
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

uint32_t /* width from decompiler */ __thiscall

FUN_0071abd0(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2,uint *param_3,uint param_4)



{

  uint32_t /* width from decompiler */ in_EAX;

  int iVar1;

  uint uVar2;

  uint32_t /* width from decompiler */ *local_30;

  uint local_2c;

  uint32_t /* width from decompiler */ local_28;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ *local_20;

  uint local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  int *local_10;

  code *local_c;

  code *local_8;

  uint32_t /* width from decompiler */ local_4;

  

  switch(in_EAX) {

  case 0:

    for (uVar2 = param_4 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {

      *param_2 = *param_1;

      param_1 = param_1 + 1;

      param_2 = param_2 + 1;

    }

    for (uVar2 = param_4 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {

      *(uint8_t *)param_2 = *(uint8_t *)param_1;

      param_1 = (uint32_t /* width from decompiler */ *)((int)param_1 + 1);

      param_2 = (uint32_t /* width from decompiler */ *)((int)param_2 + 1);

    }

    *param_3 = param_4;

    break;

  case 1:

    iVar1 = FUN_00481db0();

    if (iVar1 == -5) {

      printf("Error: uncompress buffer not large enough.\n");

      return 0xffffffff;

    }

    if (iVar1 == -4) {

      printf("Error: Not enough memory.\n");

      return 0xffffffff;

    }

    if (iVar1 == -3) {

      printf("Error: compressed data is bad!.\n");

      return 0xffffffff;

    }

    break;

  case 2:

    if (((param_2 != (uint32_t /* width from decompiler */ *)0x0) && (param_3 != (uint *)0x0)) &&

       (param_1 != (uint32_t /* width from decompiler */ *)0x0)) {

      local_4 = 0;

      local_c = FUN_0047f700;

      local_8 = FUN_00481e90;

      local_10 = (int *)FUN_0047f700(0,0xfa74,1);

      if (local_10 != (int *)0x0) {

        *local_10 = (int)&local_30;

        local_10[1] = 10;

        local_10[8] = 0;

        local_10[7] = 0;

        local_10[0x319] = 0;

        local_28 = 0;

        local_24 = 0;

        local_18 = 0;

        local_14 = 0;

        *(uint8_t *)(local_10 + 10) = 0;

        local_10[0x315] = 0;

        local_10[0x314] = 0;

        local_10[0x313] = 0;

        local_10[0xb] = 0;

        local_10[0xc] = 0;

        local_1c = *param_3;

        local_20 = param_2;

        local_2c = param_4;

        local_30 = param_1;

        iVar1 = FUN_004830e0();

        if ((iVar1 != 0) && (iVar1 == 4)) {

          *param_3 = *param_3 - local_1c;

          FUN_00483250();

          return 0;

        }

        FUN_00483250();

        return 0xffffffff;

      }

    }

  case 3:

    return 0xffffffff;

  }

  return 0;

}
