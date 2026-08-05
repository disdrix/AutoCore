// =============================================================================
// FUN_00963890
// -----------------------------------------------------------------------------
// Stable ID: aa_00963890
// Address:   0x00963890  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00963890 @ 0x00963890
// Stable ID: aa_00963890
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: if×5, do×1, while×1, return×1.
//  - Notable callees: FUN_0044a860, FUN_00456780, FUN_0046eda0, FUN_00963890.
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

void FUN_00963890(int param_1)



{

  int iVar1;

  int iVar2;

  uint local_14;

  uint local_10;

  uint32_t /* width from decompiler */ local_c;

  int local_8;

  int local_4;

  

  local_4 = param_1 + 8;

  if (*(int *)(param_1 + 0xc) == 0) {

    local_14 = 0;

  }

  else {

    local_14 = *(int *)(param_1 + 0x10) - *(int *)(param_1 + 0xc) >> 2;

  }

  local_10 = 0;

  iVar2 = DAT_00d1f650;

  if (local_14 != 0) {

    do {

      if (iVar2 != 0) {

        local_c = *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xc) + local_10 * 4);

        FUN_0044a860();

        iVar1 = local_8;

        if ((local_8 != *(int *)(iVar2 + 0x14)) &&

           (*(int *)(local_8 + 0x10) = *(int *)(local_8 + 0x10) + -1, *(int *)(local_8 + 0x10) < 1))

        {

          if (*(uint32_t /* width from decompiler */ **)(local_8 + 0xc) != (uint32_t /* width from decompiler */ *)0x0) {

            (**(code **)**(uint32_t /* width from decompiler */ **)(local_8 + 0xc))(1);

          }

          FUN_0046eda0(iVar2 + 0x10,&local_c,iVar1);

          iVar2 = DAT_00d1f650;

        }

      }

      local_10 = local_10 + 1;

    } while (local_10 < local_14);

  }

  FUN_00456780(0);

  return;

}
