// =============================================================================
// LinkPair_SortedDiffWalk_Inferred  (Ghidra: FUN_006caaa0)
// -----------------------------------------------------------------------------
// Stable ID: aa_006caaa0
// Address:   0x006caaa0 – 0x006cac19  (autoassault.exe, image base 0x400000)
// Size:      378 bytes (0x17A); epilogue ret 0x14
// System:    world-object / spatial-link merge
// Dual:      W27-N 2026-07-29 (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
//            Not modernization. Not bit-exact certified.
// =============================================================================
//
// PURPOSE:
//   Two-pointer merge of two sorted ranges of 8-byte link pairs.
//   Equal keys: advance both. Right-only: handler vcall +8.
//   Left-only: optional predicate then handler vcall +4.
//   Drain tails similarly. Used by WorldObj bind/unbind complex paths
//   when *(obj+0x40) != 0.
//
// ABI (machine):
//   thiscall; ECX = handler_table; 5 stack formals; ret 0x14; void
// =============================================================================

#include <cstdint>

// Indirect only — no direct FUN_* callees sealed here.

// Ghidra name: FUN_006caaa0
void __thiscall LinkPair_SortedDiffWalk_Inferred(
    int handler_table /*ECX*/,
    int *left_pairs,
    int *left_count_or_end,   // count on entry; rewritten to end pointer
    int *right_pairs,
    int right_count,
    std::uint32_t *predicate_obj)
{
  int *piVar1;
  std::uint32_t uVar2;
  std::uint32_t uVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  std::uint32_t *puVar7;
  int *piVar8;
  int *piVar9;

  // Promote counts → exclusive end pointers (pair stride = 2 ints = 8 bytes)
  left_count_or_end = left_pairs + (int)left_count_or_end * 2;
  piVar1 = right_pairs + right_count * 2;
  puVar7 = predicate_obj;
  piVar8 = left_pairs;
  piVar9 = right_pairs;
  right_pairs = piVar1; // right_end

  if (left_pairs != left_count_or_end) {
    do {
      if (piVar9 == right_pairs) break;
      uVar2 = *reinterpret_cast<std::uint32_t *>(*piVar8 + 4);
      uVar3 = *reinterpret_cast<std::uint32_t *>(*piVar9 + 4);
      if ((uVar3 == uVar2) &&
          (puVar7 = predicate_obj,
           *reinterpret_cast<int *>(piVar9[1] + 4) ==
               *reinterpret_cast<int *>(piVar8[1] + 4))) {
        piVar8 = piVar8 + 2;
        piVar9 = piVar9 + 2;
      } else if ((uVar3 < uVar2) ||
                 ((uVar3 == uVar2 &&
                   (*reinterpret_cast<std::uint32_t *>(piVar9[1] + 4) <
                    *reinterpret_cast<std::uint32_t *>(piVar8[1] + 4))))) {
        // right-only: vtable +8
        (**(void (***)(int *))(
            **reinterpret_cast<int **>(
                handler_table +
                (*reinterpret_cast<int *>(piVar9[1] + 8) +
                 *reinterpret_cast<int *>(*piVar9 + 8) * 8) *
                    4) +
            8))(piVar9);
        piVar9 = piVar9 + 2;
      } else {
        // left-only: predicate then optional vtable +4
        if (*piVar8 == 0) {
          iVar6 = 0;
        } else {
          iVar6 = *piVar8 + -0x10;
        }
        if (piVar8[1] == 0) {
          iVar4 = 0;
        } else {
          iVar4 = piVar8[1] + -0x10;
        }
        pcVar5 = reinterpret_cast<char *>(
            (**(void ***)(*puVar7))(&left_pairs, iVar6, iVar4));
        if (*pcVar5 != '\0') {
          (**(void (***)(int *))(
              **reinterpret_cast<int **>(
                  handler_table +
                  (*reinterpret_cast<int *>(piVar8[1] + 8) +
                   *reinterpret_cast<int *>(*piVar8 + 8) * 8) *
                      4) +
              4))(piVar8);
        }
        piVar8 = piVar8 + 2;
      }
    } while (piVar8 != left_count_or_end);
  }

  if (piVar8 < left_count_or_end) {
    do {
      if (*piVar8 == 0) {
        iVar6 = 0;
      } else {
        iVar6 = *piVar8 + -0x10;
      }
      if (piVar8[1] == 0) {
        iVar4 = 0;
      } else {
        iVar4 = piVar8[1] + -0x10;
      }
      pcVar5 = reinterpret_cast<char *>(
          (**(void ***)(*puVar7))(&predicate_obj, iVar6, iVar4));
      if (*pcVar5 != '\0') {
        (**(void (***)(int *))(
            **reinterpret_cast<int **>(
                handler_table +
                (*reinterpret_cast<int *>(piVar8[1] + 8) +
                 *reinterpret_cast<int *>(*piVar8 + 8) * 8) *
                    4) +
            4))(piVar8);
      }
      piVar8 = piVar8 + 2;
    } while (piVar8 < left_count_or_end);
  }

  if (piVar9 < right_pairs) {
    do {
      (**(void (***)(int *))(
          **reinterpret_cast<int **>(
              handler_table +
              (*reinterpret_cast<int *>(piVar9[1] + 8) +
               *reinterpret_cast<int *>(*piVar9 + 8) * 8) *
                  4) +
          8))(piVar9);
      piVar9 = piVar9 + 2;
    } while (piVar9 < right_pairs);
  }
}

// Scaffold twin entry (Ghidra name)
extern "C" void __thiscall FUN_006caaa0(
    int handler_table,
    int *left_pairs,
    int *left_count_or_end,
    int *right_pairs,
    int right_count,
    std::uint32_t *predicate_obj)
{
  LinkPair_SortedDiffWalk_Inferred(
      handler_table, left_pairs, left_count_or_end, right_pairs, right_count,
      predicate_obj);
}
