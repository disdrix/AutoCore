// =============================================================================
// Client_DismissProgressBar_Inferred  (FUN_007fb640)
// -----------------------------------------------------------------------------
// Stable ID: aa_007fb640
// Address:   0x007fb640  (autoassault.exe, image base 0x400000)
// System:    skills-abilities / client-ui (shared progress chrome)
// Generated: 2026-07-23 scaffold; 2026-07-29 dual A/B asm-correct
// Exactness: Behavior-preserving rewrite of decompiler + live asm CF.
//            Not modernization. Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Dismiss/hide client progress-bar widget at client+0x1120.
//   Optional detach via client+0xf38 when bar+0x2b0 != 0, then tail-call
//   bar.vtbl+0x440. No-op if bar null or vtbl+0x3d8 probe false.
//
// ABI:
//   ESI = Client* (decompiler: unaff_ESI)
//   No stack formals; plain RET on early exits.
//   Success path ends in JMP [bar.vtbl+0x440] (tail call).
//
// SIBLING:
//   Client_ShowTimedProgressBar_Inferred (0x007fb690) always calls this first.
//
// CALLERS (5):
//   0x007fb690 show, 0x00811170 RecvSkillStatusEffect, 0x007fe8d0 UseItem path,
//   0x0080be70 case 3, 0x0091edd0 "Contact Interrupted!"
//

typedef unsigned char undefined1;
typedef unsigned int undefined4;
typedef int (*code)();

// ESI = Client* for entire body
void Client_DismissProgressBar_Inferred(void)
{
  char cVar1;
  int unaff_ESI; /* Client* in ESI */

  if (*(int *)(unaff_ESI + 0x1120) != 0) {
    cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x1120) + 0x3d8))();
    if (cVar1 != '\0') {
      if (*(int *)(*(int *)(unaff_ESI + 0x1120) + 0x2b0) != 0) {
        /* host detach: (client+0xf38).vtbl+0xb0(bar) */
        (**(code **)(**(int **)(unaff_ESI + 0xf38) + 0xb0))(*(int *)(unaff_ESI + 0x1120));
      }
      /* tail JMP bar.vtbl+0x440 (decompiler may emit CALL; image is JMP) */
      (**(code **)(**(int **)(unaff_ESI + 0x1120) + 0x440))();
      return;
    }
  }
  return;
}

// Ghidra symbol alias
void FUN_007fb640(void)
{
  Client_DismissProgressBar_Inferred();
}
