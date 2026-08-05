// =============================================================================
// FUN_009653f0
// -----------------------------------------------------------------------------
// Stable ID: aa_009653f0
// Address:   0x009653f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009653f0 @ 0x009653f0
// Stable ID: aa_009653f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, do×1, while×1.
//  - Notable callees: FUN_0043f5e0, FUN_009653f0, FUN_00972fa0.
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

int __thiscall FUN_009653f0(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ *param_3,uint32_t /* width from decompiler */ *param_4)



{

  int *piVar1;

  char cVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ *puVar5;

  int local_14;

  uint8_t auStack_c [12];

  

  puVar5 = *(uint32_t /* width from decompiler */ **)(param_1 + 8);

  local_14 = 0;

  iVar3 = 0;

  if (puVar5 != *(uint32_t /* width from decompiler */ **)(param_1 + 0xc)) {

    do {

      piVar1 = (int *)*puVar5;

      iVar3 = (**(code **)(*piVar1 + 0x48))();

      if ((*(char *)(iVar3 + 0x2c) == '\0') &&

         (cVar2 = (**(code **)*param_4)(piVar1), cVar2 != '\0')) {

        uVar4 = (**(code **)(*piVar1 + 0x48))();

        (**(code **)(*piVar1 + 0xc))(uVar4);

        FUN_00972fa0(uVar4);

        (**(code **)(*piVar1 + 0x48))();

        (**(code **)(*piVar1 + 0xc))();

        iVar3 = FUN_0043f5e0(auStack_c);

        if (iVar3 != -1) {

          local_14 = local_14 + 1;

          iVar3 = (**(code **)*param_3)(piVar1);

          if (iVar3 == 1) {

            return local_14;

          }

        }

      }

      puVar5 = puVar5 + 1;

      iVar3 = local_14;

    } while (puVar5 != *(uint32_t /* width from decompiler */ **)(param_1 + 0xc));

  }

  return iVar3;

}
