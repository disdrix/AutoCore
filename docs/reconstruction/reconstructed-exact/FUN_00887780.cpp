// =============================================================================
// FUN_00887780  — scaffold twin of UI_TabsSo_SetActiveTab_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00887780
// Address:   0x00887780–0x00887a63  (autoassault.exe, image base 0x400000)
// Body:      740 B (0x2E4); terminal RET 8 (C2 08 00)
// System:    inventory-transfer
// Generated: 2026-07-23 scaffold; R13-012 dual seal 2026-08-05
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// CANONICAL NAME: UI_TabsSo_SetActiveTab_Inferred
// Prefer: docs/reconstruction/reconstructed-exact/UI_TabsSo_SetActiveTab_Inferred.cpp
//
// ABI (machine — decompiler signature incomplete):
//   hybrid __usercall: EAX=tabIndex; stack dialog* + force; RET 8; void
//   NOT thiscall. Phantom in_EAX is load-bearing tabIndex.
//
// PURPOSE: i_d_tabs_so active-tab setter (friends/clan/enemies) on DAT_00d1b878.
// Dual A/B: A_aa_00887780_* / B_aa_00887780_*  Report: task-dual-ab-00887780-r13-report.md
// =============================================================================

// PURPOSE (auto + R13-012):
// Stable ID: aa_00887780
// Active-tab switch for social dialog i_d_tabs_so_*.
//
// READABILITY (auto CF + machine seal):
//  - Body size: ~81 non-empty decompiler lines; 740 B image.
//  - Control keywords: if×13, return×3.
//  - Notable callees: FUN_00822cb0×8 (ESI/BL), FUN_00756c90×5 (EDI).
//  - Tabs: 0 friends, 1 clan, 2 enemies (linear panes +0x50c/+0x510/+0x514).
//  - Active slot: dialog+0x534. Host: DAT_00d1b878.
//  - Return sites: 3 (incl. mode-2 early RET 8).

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; hybrid ABI sealed via disasm + call sites.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN. Never Runtime Confirmed this pass.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 * - Machine corrections (not shown in decompiler arity): tabIndex@EAX; ESI/EDI/BL helpers.
 */

// Documentary C signature only — image places tabIndex in EAX.
void FUN_00887780(int *param_1, uint32_t /* force */ param_2 /* , int tabIndex@EAX */)
{
  char cVar1;
  int in_EAX;  // tabIndex — hybrid usercall

  cVar1 = (**(code **)(*param_1 + 0x3d8))();
  if ((cVar1 != '\0') && (((char)param_2 != '\0' || (in_EAX != param_1[0x14d])))) {
    param_1[0x14d] = in_EAX;
    if (in_EAX == 0) {
      // friends: show [0x143]; hide [0x144],[0x145]; select [0x146]; deselect [0x147],[0x148]
      cVar1 = (**(code **)(*(int *)param_1[0x143] + 0x3d8))();
      if (cVar1 == '\0') {
        (**(code **)(*(int *)param_1[0x143] + 0x43c))();
        (**(code **)(*(int *)param_1[0x143] + 4))(1);
      }
      cVar1 = (**(code **)(*(int *)param_1[0x144] + 0x3d8))();
      if (cVar1 != '\0') {
        (**(code **)(*(int *)param_1[0x144] + 4))(0);
        (**(code **)(*(int *)param_1[0x144] + 0x440))();
      }
      cVar1 = (**(code **)(*(int *)param_1[0x145] + 0x3d8))();
      if (cVar1 != '\0') {
        (**(code **)(*(int *)param_1[0x145] + 4))(0);
        (**(code **)(*(int *)param_1[0x145] + 0x440))();
      }
      // machine: ESI=param_1[0x146]; BL=1; PUSH force; CALL 00822cb0; vtbl+0x94
      FUN_00822cb0(param_2);
      (**(code **)(*(int *)param_1[0x146] + 0x94))();
      // machine: ESI=[0x147]; BL=0; CALL 00822cb0; EDI=[0x147]; CALL 00756c90
      FUN_00822cb0(param_2);
      FUN_00756c90();
    }
    else {
      if (in_EAX != 1) {
        if (in_EAX != 2) {
          return;  // store-only; RET 8
        }
        // enemies: early RET after select [0x148]
        cVar1 = (**(code **)(*(int *)param_1[0x143] + 0x3d8))();
        if (cVar1 != '\0') {
          (**(code **)(*(int *)param_1[0x143] + 4))(0);
          (**(code **)(*(int *)param_1[0x143] + 0x440))();
        }
        cVar1 = (**(code **)(*(int *)param_1[0x144] + 0x3d8))();
        if (cVar1 != '\0') {
          (**(code **)(*(int *)param_1[0x144] + 4))(0);
          (**(code **)(*(int *)param_1[0x144] + 0x440))();
        }
        cVar1 = (**(code **)(*(int *)param_1[0x145] + 0x3d8))();
        if (cVar1 == '\0') {
          (**(code **)(*(int *)param_1[0x145] + 0x43c))();
          (**(code **)(*(int *)param_1[0x145] + 4))(1);
        }
        FUN_00822cb0(param_2);
        FUN_00756c90();
        FUN_00822cb0(param_2);
        FUN_00756c90();
        FUN_00822cb0(param_2);
        (**(code **)(*(int *)param_1[0x148] + 0x94))();
        return;  // RET 8 @ 0x008878b3
      }
      // clan
      cVar1 = (**(code **)(*(int *)param_1[0x143] + 0x3d8))();
      if (cVar1 != '\0') {
        (**(code **)(*(int *)param_1[0x143] + 4))(0);
        (**(code **)(*(int *)param_1[0x143] + 0x440))();
      }
      cVar1 = (**(code **)(*(int *)param_1[0x144] + 0x3d8))();
      if (cVar1 == '\0') {
        (**(code **)(*(int *)param_1[0x144] + 0x43c))();
        (**(code **)(*(int *)param_1[0x144] + 4))(1);
      }
      cVar1 = (**(code **)(*(int *)param_1[0x145] + 0x3d8))();
      if (cVar1 != '\0') {
        (**(code **)(*(int *)param_1[0x145] + 4))(0);
        (**(code **)(*(int *)param_1[0x145] + 0x440))();
      }
      FUN_00822cb0(param_2);
      FUN_00756c90();
      FUN_00822cb0(param_2);
      (**(code **)(*(int *)param_1[0x147] + 0x94))();
    }
    // shared deselect-enemies tail for modes 0/1
    FUN_00822cb0(param_2);
    FUN_00756c90();
  }
  return;  // RET 8
}
