// =============================================================================
// FUN_009654b0
// -----------------------------------------------------------------------------
// Stable ID: aa_009654b0
// Address:   0x009654b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009654b0 @ 0x009654b0
// Stable ID: aa_009654b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, do×1, while×1.
//  - Notable callees: FUN_0043f5e0, FUN_009654b0, FUN_00972fa0.
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

int __thiscall FUN_009654b0(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ *param_3)



{

  int *piVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ *puVar4;

  int local_14;

  uint8_t auStack_c [12];

  

  puVar4 = *(uint32_t /* width from decompiler */ **)(param_1 + 8);

  local_14 = 0;

  iVar2 = 0;

  if (puVar4 != *(uint32_t /* width from decompiler */ **)(param_1 + 0xc)) {

    do {

      piVar1 = (int *)*puVar4;

      iVar2 = (**(code **)(*piVar1 + 0x48))();

      if (*(char *)(iVar2 + 0x2c) == '\0') {

        uVar3 = (**(code **)(*piVar1 + 0x48))();

        (**(code **)(*piVar1 + 0xc))(uVar3);

        FUN_00972fa0(uVar3);

        (**(code **)(*piVar1 + 0x48))();

        (**(code **)(*piVar1 + 0xc))();

        iVar2 = FUN_0043f5e0(auStack_c);

        if (iVar2 != -1) {

          local_14 = local_14 + 1;

          iVar2 = (**(code **)*param_3)(piVar1);

          if (iVar2 == 1) {

            return local_14;

          }

        }

      }

      puVar4 = puVar4 + 1;

      iVar2 = local_14;

    } while (puVar4 != *(uint32_t /* width from decompiler */ **)(param_1 + 0xc));

  }

  return iVar2;

}
