// =============================================================================
// FUN_0048ef60
// -----------------------------------------------------------------------------
// Stable ID: aa_0048ef60
// Address:   0x0048ef60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0048ef60 @ 0x0048ef60
// Stable ID: aa_0048ef60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×5, return×1.
//  - Notable callees: CONCAT31, FUN_0048ef60, FUN_004bc180.
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

void __thiscall FUN_0048ef60(int param_1,int *param_2)



{

  char cVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int *piVar3;

  

  if (param_2 != (int *)0x0) {

    if (((uint)param_2[0x5f] >> 5 & 1) != 0) {

      puVar2 = (uint32_t /* width from decompiler */ *)(**(code **)(*param_2 + 0x1c8))();

      (**(code **)*puVar2)

                (*(uint32_t /* width from decompiler */ *)(param_1 + 0xb8),&DAT_00b03520,&DAT_00b03540,

                 CONCAT31((int3)((uint)*(int *)(param_2[0x2a] + 0x38) >> 8),

                          *(int *)(param_2[0x2a] + 0x38) == 0xe));

    }

    if (((uint)param_2[0x5f] >> 6 & 1) != 0) {

      piVar3 = (int *)(**(code **)(*param_2 + 0x1cc))();

      (**(code **)(*(int *)(*(int *)(piVar3[1] + 4) + 4 + (int)piVar3) + 0x218))

                (*(uint32_t /* width from decompiler */ *)(param_1 + 0xb8));

      cVar1 = (**(code **)*piVar3)(param_2,0,0,0,0,0,0,g_flOne,0);

      if ((cVar1 != '\0') && (piVar3[2] != 0)) {

        (**(code **)(*(int *)((int)piVar3 + *(int *)(piVar3[1] + 4) + 4) + 0xb8))

                  (*(uint32_t /* width from decompiler */ *)((int)piVar3 + *(int *)(piVar3[1] + 4) + 0xbc));

        (**(code **)(*piVar3 + 0x20))();

        if ((char)param_2 != '\0') {

          (**(code **)(*(int *)(*(int *)(piVar3[1] + 4) + 4 + (int)piVar3) + 0x100))();

        }

      }

    }

    FUN_004bc180(param_2);

  }

  return;

}
