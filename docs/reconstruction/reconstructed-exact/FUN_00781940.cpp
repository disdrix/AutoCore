// =============================================================================
// FUN_00781940
// -----------------------------------------------------------------------------
// Stable ID: aa_00781940
// Address:   0x00781940  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00781940 @ 0x00781940
// Stable ID: aa_00781940
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: if×7, return×2.
//  - Notable callees: FUN_00429c30, FUN_00781940, FUN_00975450.
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

void __thiscall FUN_00781940(int param_1,int param_2)



{

  uint *puVar1;

  void *pvVar2;

  int iVar3;

  

  FUN_00975450(param_2);

  pvVar2 = *(void **)(param_2 + 0x18);

  if (pvVar2 != (void *)0x0) {

    if (*(void **)(*(int *)((int)pvVar2 + 0xc) + 0x10) == pvVar2) {

      *(uint32_t /* width from decompiler */ *)(*(int *)((int)pvVar2 + 0xc) + 0x10) = 0;

    }

    if ((*(uint *)((int)pvVar2 + 8) & 8) == 0) {

      if ((*(uint *)((int)pvVar2 + 8) & 0x20) != 0) {

        iVar3 = *(int *)((int)pvVar2 + 0xc);

        if (*(int *)(iVar3 + 0x34) < *(int *)(param_1 + 0x20c)) {

          *(uint32_t /* width from decompiler */ *)(iVar3 + 8) = 0;

          *(uint32_t /* width from decompiler */ *)(iVar3 + 0xc) = 0;

          FUN_00429c30();

        }

        *(int *)(param_1 + 0x210) = *(int *)(param_1 + 0x210) + -1;

        if (*(int *)(iVar3 + 0x34) != *(int *)(param_1 + 0x210)) {

          *(int *)(*(int *)(*(int *)(param_1 + 0x208) + *(int *)(param_1 + 0x210) * 4) + 0x34) =

               *(int *)(iVar3 + 0x34);

          *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x208) + *(int *)(iVar3 + 0x34) * 4) =

               *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x208) + *(int *)(param_1 + 0x210) * 4);

          *(int *)(*(int *)(param_1 + 0x208) + *(int *)(param_1 + 0x210) * 4) = iVar3;

          *(uint32_t /* width from decompiler */ *)(iVar3 + 0x34) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x210);

        }

      }

    }

    else {

      puVar1 = (uint *)(*(int *)((int)pvVar2 + 0xc) + 0x28);

      *puVar1 = *puVar1 & 0xfffffff7;

      if (**(int **)((int)pvVar2 + 0xc) != 0) {

        (**(code **)(*(int *)**(int **)((int)pvVar2 + 0xc) + 0x14))(param_1);

      }

    }

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar2);

  }

  return;

}
