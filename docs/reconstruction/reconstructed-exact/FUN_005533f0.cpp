// =============================================================================
// FUN_005533f0
// -----------------------------------------------------------------------------
// Stable ID: aa_005533f0
// Address:   0x005533f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005533f0 @ 0x005533f0
// Stable ID: aa_005533f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: CONCAT22×2, NAN×2, CONCAT11, CONCAT31, FUN_00552f50, FUN_005533f0.
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

uint __thiscall FUN_005533f0(int param_1,int param_2)



{

  float fVar1;

  short sVar2;

  byte bVar6;

  int iVar3;

  int iVar4;

  uint16_t uVar7;

  uint uVar5;

  

  iVar3 = (**(code **)(*(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + 4 + param_2) + 0x27c))();

  iVar4 = FUN_00552f50(param_2);

  uVar7 = (uint16_t)((uint)iVar4 >> 0x10);

  uVar5 = CONCAT22(uVar7,*(short *)(param_1 + 2));

  if (*(short *)(param_1 + 2) <= *(short *)(param_2 + 0x6cc)) {

    sVar2 = *(short *)(param_1 + 0x5f6);

    uVar5 = CONCAT22(uVar7,sVar2);

    if (((int)sVar2 < (int)(uint)*(byte *)(param_1 + 0x5f4)) && (sVar2 < 0x32)) {

      uVar5 = (uint)*(byte *)(param_1 + 0x5fb);

      if ((int)uVar5 <= iVar3) {

        fVar1 = *(float *)(param_1 + 4);

        bVar6 = (fVar1 == g_flZero) << 6 | (NAN(fVar1) || NAN(g_flZero)) << 2 | 2U |

                fVar1 < g_flZero;

        uVar5 = (uint)CONCAT11(bVar6,*(byte *)(param_1 + 0x5fb));

        if ((fVar1 == g_flZero) || (sVar2 < iVar4)) {

          return CONCAT31((uint3)bVar6,1);

        }

      }

    }

  }

  return uVar5 & 0xffffff00;

}
