// =============================================================================
// FUN_007fca10
// -----------------------------------------------------------------------------
// Stable ID: aa_007fca10
// Address:   0x007fca10  (autoassault.exe, image base 0x400000)
// System:    missions-progression (generic UI close host; mission Flush invoker)
// Generated: 2026-07-23 scaffold; strengthened 2026-07-29 (wave3 UF-010)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Leave-FUN: no string/RTTI product name — keep FUN_007fca10.
//
// PURPOSE:
//   Generic "close visible dialog" host. If the dialog object in EAX reports live
//   via vtbl+0x3d8, call dialog.vtbl+0x440, then detach/restore bookkeeping on the
//   client host in EBX.
//
// UF-010 (C2S 0x206E invoker — static sealed):
//   For NPC mission dialog at client+0x1058 (vtable base 0x00a4a51c):
//     vtbl+0x440 → Client_MissionDialog_FlushPreparedResponse @ 0x008ab8f0
//     (DATA slot 0x00a4a95c; read_memory dword = 0x008ab8f0)
//   Mission dispatch chain:
//     FUN_008aec40 / FUN_008af020 → this → vtbl+0x440 (Flush)
//   NOT Client_HideMissionDialogIfOpen (+0x107c).
//
// UF-011:
//   This function does not read/clear dialog+0x650. Cancel-close that reaches here
//   still invokes +0x440; stale 0x206E risk is owned by Flush/Prepare residual.
//
// Registers (decompiler):
//   EAX = dialog/UI object*
//   EBX = client host*
//
// Dual reviews: reviews/A_aa_007fca10_FUN_007fca10.md
//               reviews/B_aa_007fca10_FUN_007fca10.md
// =============================================================================

#include <cstdint>

// Decompiler signature: void FUN_007fca10(void)
// Live inputs: EAX dialog, EBX client (unaffiliated / custom register convention).
void FUN_007fca10(void)
{
  int *piVar1;
  char cVar2;
  int *in_EAX;
  int unaff_EBX;
  int *piVar3;
  int iVar4;
  uint8_t uVar5;

  if ((*(int *)(unaff_EBX + 0xf40) != 0) && (in_EAX != (int *)0x0)) {
    cVar2 = (**(code **)(*in_EAX + 0x3d8))();
    if (cVar2 != '\0') {
      // Virtual slot +0x440: mission dialog class → FlushPreparedResponse
      (**(code **)(*in_EAX + 0x440))();
      if (**(int **)(unaff_EBX + 0xf40) != 0) {
        (**(code **)(*(int *)**(int **)(unaff_EBX + 0xf40) + 0xb0))();
      }
      iVar4 = 0;
      piVar3 = (int *)(unaff_EBX + 0x1030);
      do {
        if ((iVar4 != 0x16) && (piVar1 = (int *)*piVar3, piVar1 != (int *)0x0)) {
          cVar2 = (**(code **)(*piVar1 + 0x3d8))();
          if ((cVar2 != '\0') && (piVar1[0x140] == 1)) goto LAB_007fcac1;
        }
        iVar4 = iVar4 + 1;
        piVar3 = piVar3 + 1;
      } while (iVar4 < 0x3a);
      if (*(int **)(unaff_EBX + 0xf38) != (int *)0x0) {
        if (*(char *)(unaff_EBX + 0x31d9) == '\0') {
          *(uint8_t *)(unaff_EBX + 0x31d8) = 1;
          uVar5 = 1;
        }
        else {
          uVar5 = *(uint8_t *)(unaff_EBX + 0x31d8);
        }
        (**(code **)(**(int **)(unaff_EBX + 0xf38) + 0x3c4))(uVar5);
      }
LAB_007fcac1:
      iVar4 = *(int *)(unaff_EBX + 0x10b0);
      if ((iVar4 != 0) && (*(int *)(iVar4 + 0x664) != 0)) {
                    /* WARNING: Could not recover jumptable at 0x007fcae1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(**(int **)(iVar4 + 0x664) + 0x47c))();
        return;
      }
    }
  }
  return;
}
