// =============================================================================
// FUN_004cd240
// -----------------------------------------------------------------------------
// Stable ID: aa_004cd240
// Address:   0x004cd240  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004cd240 @ 0x004cd240
// Stable ID: aa_004cd240
// Embedded strings (evidence for future rename):
//   - "Arena Info incomplete! Players:%d sizeincoming:%d required:%d... Reseting players"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~39 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, for×1, do×1, while×1.
//  - Notable callees: FUN_004cd240, FUN_007a4480.
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

int FUN_004cd240(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2,int param_3)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  

  puVar2 = param_1;

  puVar4 = param_2;

  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar4 = *puVar2;

    puVar2 = puVar2 + 1;

    puVar4 = puVar4 + 1;

  }

  *(uint8_t *)(param_2 + 0x10) = *(uint8_t *)(param_1 + 0x10);

  *(uint8_t *)((int)param_2 + 0x41) = *(uint8_t *)((int)param_1 + 0x41);

  iVar1 = (*(byte *)((int)param_1 + 0x41) + 3) * 0x18;

  if (((param_3 < 0) || (iVar1 <= param_3)) && (*(byte *)((int)param_2 + 0x41) < 0x100)) {

    iVar3 = 0;

    if (*(byte *)((int)param_2 + 0x41) != 0) {

      puVar2 = param_2 + 0x12;

      do {

        puVar4 = (uint32_t /* width from decompiler */ *)(((int)param_1 - (int)param_2) + (int)puVar2);

        *puVar2 = *puVar4;

        puVar2[1] = puVar4[1];

        puVar2[2] = puVar4[2];

        puVar2[3] = puVar4[3];

        puVar2[4] = puVar4[4];

        puVar2[5] = puVar4[5];

        iVar3 = iVar3 + 1;

        puVar2 = puVar2 + 6;

      } while (iVar3 < (int)(uint)*(byte *)((int)param_2 + 0x41));

    }

    return iVar1;

  }

  FUN_007a4480(1,"Arena Info incomplete! Players:%d sizeincoming:%d required:%d... Reseting players"

               ,*(uint8_t *)((int)param_1 + 0x41),param_3,iVar1);

  *(uint8_t *)((int)param_2 + 0x41) = 0;

  return 0x48;

}
