// =============================================================================
// FUN_00553240
// -----------------------------------------------------------------------------
// Stable ID: aa_00553240
// Address:   0x00553240  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00553240 @ 0x00553240
// Stable ID: aa_00553240
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, for×1.
//  - Notable callees: NAN×2, CONCAT31, FUN_005531d0, FUN_00553240.
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

uint __thiscall

FUN_00553240(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,ushort param_4,uint8_t *param_5)



{

  float fVar1;

  uint uVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  float10 fVar5;

  uint16_t local_408;

  uint32_t /* width from decompiler */ local_406 [255];

  uint8_t local_9;

  

  fVar1 = *(float *)(param_1 + 0x24);

  local_408 = 0;

  puVar4 = local_406;

  for (iVar3 = 0xff; iVar3 != 0; iVar3 = iVar3 + -1) {

    *puVar4 = 0;

    puVar4 = puVar4 + 1;

  }

  *(uint16_t *)puVar4 = 0;

  uVar2 = (uint)(byte)((fVar1 == DAT_00aaa668) << 6 | (NAN(fVar1) || NAN(DAT_00aaa668)) << 2 | 2U |

                      fVar1 < DAT_00aaa668) << 8;

  local_9 = 0;

  if (fVar1 != DAT_00aaa668) {

    fVar5 = (float10)FUN_005531d0(param_2,param_3,&local_408);

    uVar2 = param_4 / 100;

    if (fVar5 <= (float10)((uint)param_4 % 100) * (float10)DAT_00a0f718) {

      if (param_5 != (uint8_t *)0x0) {

        *param_5 = 1;

      }

      return (uint)param_5 & 0xffffff00;

    }

  }

  return CONCAT31((int3)(uVar2 >> 8),1);

}
