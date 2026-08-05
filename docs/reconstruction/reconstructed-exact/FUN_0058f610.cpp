// =============================================================================
// FUN_0058f610
// -----------------------------------------------------------------------------
// Stable ID: aa_0058f610
// Address:   0x0058f610  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0058f610 @ 0x0058f610
// Stable ID: aa_0058f610
// Embedded strings (evidence for future rename):
//   - "Couldn\'t find parent geo for delayed volume emission"
//   - "Parent geo was null for delayed volume emission"
//   - "Couldn\'t find source child geo for delayed volume emission"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: if×6, return×4, for×3, do×1, while×1.
//  - Notable callees: FUN_007a4480×3, FUN_0058f610, FUN_005b0990, FUN_00673070, FUN_00787260, FUN_00787310.
//  - Strings: "Couldn\'t find parent geo for delayed volume emission"; "Parent geo was null for delayed volume emission"; "Couldn\'t find source child geo for delayed volume emission".
//  - Return sites: 4.

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

void __thiscall FUN_0058f610(int param_1,int *param_2)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  int local_4;

  

  iVar2 = (int)param_2;

  if ((*(int *)(param_1 + 0xdc) != 0) && (g_flZero < *(float *)(param_1 + 0xbc))) {

    piVar1 = *(int **)((int)param_2 + 4);

    param_2 = (int *)*piVar1;

    iVar3 = 0;

    local_4 = param_1;

    if (param_2 != piVar1) {

      do {

        if (param_2[4] == param_1) {

          iVar3 = param_2[3];

        }

        FUN_00673070();

      } while (param_2 != piVar1);

      if ((iVar3 != 0) && (*(int *)(iVar3 + 0xdc) != 0)) {

        param_2 = (int *)FUN_00787260();

        FUN_005b0990(&local_4,&param_2);

        if (local_4 == *(int *)(iVar2 + 4)) {

          FUN_007a4480(0,"Couldn\'t find parent geo for delayed volume emission");

          return;

        }

        if (*(int *)(local_4 + 0x10) == 0) {

          FUN_007a4480(0,"Parent geo was null for delayed volume emission");

          return;

        }

        FUN_00787310(*(uint32_t /* width from decompiler */ *)(param_1 + 0xdc));

        return;

      }

    }

    FUN_007a4480(0,"Couldn\'t find source child geo for delayed volume emission");

  }

  return;

}
