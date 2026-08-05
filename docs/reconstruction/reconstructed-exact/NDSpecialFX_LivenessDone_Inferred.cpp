// =============================================================================
// NDSpecialFX_LivenessDone_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004b7330
// Address:   0x004b7330 – 0x004b73bc  (autoassault.exe, image base 0x400000)
// System:    client-fx / NDSpecialFX lifecycle
// Generated: 2026-07-29 W26-H dual seal (decompile + read_memory)
// Exactness: Behavior-preserving CF reconstruction. Twin FUN_004b7330.cpp is the
//            line-faithful decompiler mirror.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Liveness / completion probe for an NDSpecialFX host object.
//   HostTick (FUN_004b8ed0) treats non-zero as "done" → DeactivateClear + return 1.
//
// ABI:
//   ECX = fx host (this). No stack formals. Plain RET (C3). Return AL 0|1.
//   Leaf: 0 callees, 0 globals.
//
// SEALED GATES:
//   1. Host residual: +9, +0xA chars; +0x1E4, +0x214 ints — any active → 0.
//   2. Owned circular list +0x204: every payload (node[2]) must have +0x795 != 0.
//   3. If +0x1F0 != 0 and +6/+7/+8 all 0: secondary list +0x1EC — any payload
//      with +0x10B != 0 → result 0; else keep 1.
//
// RELATED:
//   FUN_004b8ed0 = NDSpecialFX_HostTick_Inferred (W24-C) — sole caller
//   FUN_004b7150 = NDSpecialFX_DeactivateClear_Inferred (W23-H) — HostTick path
// =============================================================================

#include <cstdint>

// Contract sketch (matches sealed CF):
//
// uint8_t NDSpecialFX_LivenessDone_Inferred(void* fx) {
//   if (fx.flag_A || fx.flag_9 || fx.i_1e4 || fx.i_214) return 0;
//   for (node : circular_list(fx+0x204))
//     if (payload(node)[+0x795] == 0) return 0;
//   done = 1;
//   if (fx.i_1f0 && !fx.f6 && !fx.f7 && !fx.f8) {
//     for (node : circular_list(fx+0x1ec))
//       if (payload(node)[+0x10b] != 0) { done = 0; break; }
//   }
//   return done;
// }

uint8_t __fastcall NDSpecialFX_LivenessDone_Inferred(int this_fx)
{
  uint32_t *node;
  int *listHead;
  uint8_t done;
  int *it;

  if ((((*(char *)(this_fx + 10) == '\0') && (*(char *)(this_fx + 9) == '\0')) &&
      (*(int *)(this_fx + 0x1e4) == 0)) && (*(int *)(this_fx + 0x214) == 0)) {
    for (node = (uint32_t *)**(uint32_t **)(this_fx + 0x204);
        node != *(uint32_t **)(this_fx + 0x204); node = (uint32_t *)*node) {
      if (*(char *)(node[2] + 0x795) == '\0') {
        return 0;
      }
    }
    done = 1;
    if (((*(int *)(this_fx + 0x1f0) != 0) && (*(char *)(this_fx + 6) == '\0')) &&
       ((*(char *)(this_fx + 7) == '\0' && (*(char *)(this_fx + 8) == '\0')))) {
      listHead = *(int **)(this_fx + 0x1ec);
      it = (int *)*listHead;
      if (it != listHead) {
        while (*(char *)(it[2] + 0x10b) == '\0') {
          it = (int *)*it;
          if (it == listHead) {
            return done;
          }
        }
        done = 0;
      }
    }
    return done;
  }
  return 0;
}
