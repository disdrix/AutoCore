// =============================================================================
// FUN_006cb4b0
// -----------------------------------------------------------------------------
// Stable ID: aa_006cb4b0
// Address:   0x006cb4b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006cb4b0 @ 0x006cb4b0
// Stable ID: aa_006cb4b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~55 non-empty decompiler lines.
//  - Control keywords: if×6, do×3, while×3, return×1.
//  - Notable callees: FUN_005b3370, FUN_006cafd0, FUN_006cb320, FUN_006cb390, FUN_006cb4b0.
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

void __thiscall FUN_006cb4b0(int param_1,int param_2,int param_3)



{

  int *piVar1;

  uint8_t uVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  

  if (*(char *)(param_1 + 0x4d8c) != '\0') {

    FUN_006cafd0();

    uVar2 = *(uint8_t *)(param_1 + 0x4d8d);

    iVar6 = 0;

    if (0 < *(int *)(param_1 + 0x4da0)) {

      iVar5 = 0;

      do {

        puVar3 = (uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x4d9c) + iVar5);

        *(uint8_t *)(param_1 + 0x4d8d) = *(uint8_t *)(*(int *)(param_1 + 0x4d9c) + 8 + iVar5);

        FUN_006cb390(puVar3 + 3,*puVar3,puVar3[1]);

        iVar6 = iVar6 + 1;

        iVar5 = iVar5 + 0x1c;

      } while (iVar6 < *(int *)(param_1 + 0x4da0));

    }

    *(uint8_t *)(param_1 + 0x4d8d) = uVar2;

  }

  iVar6 = 0;

  if (0 < *(int *)(param_1 + 0x4d94)) {

    do {

      if ((*(int *)(*(int *)(param_1 + 0x4d90) + iVar6 * 8) == param_2) &&

         (*(int *)(*(int *)(param_1 + 0x4d90) + iVar6 * 8 + 4) == param_3)) {

        iVar4 = *(int *)(param_1 + 0x4d94) + -1;

        *(int *)(param_1 + 0x4d94) = iVar4;

        iVar5 = iVar6;

        if (iVar6 < iVar4) {

          do {

            puVar3 = (uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x4d90) + iVar5 * 8);

            *puVar3 = *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x4d90) + 8 + iVar5 * 8);

            puVar3[1] = puVar3[3];

            iVar5 = iVar5 + 1;

          } while (iVar5 < *(int *)(param_1 + 0x4d94));

        }

        iVar6 = iVar6 + -1;

      }

      iVar6 = iVar6 + 1;

    } while (iVar6 < *(int *)(param_1 + 0x4d94));

  }

  FUN_006cb320(param_2,param_3,0);

  if (*(uint *)(param_1 + 0x4d94) == (*(uint *)(param_1 + 0x4d98) & 0x7fffffff)) {

    FUN_005b3370((int *)(param_1 + 0x4d90),8);

  }

  piVar1 = (int *)(*(int *)(param_1 + 0x4d90) + *(int *)(param_1 + 0x4d94) * 8);

  *(int *)(param_1 + 0x4d94) = *(int *)(param_1 + 0x4d94) + 1;

  *piVar1 = param_2;

  piVar1[1] = param_3;

  return;

}
