// =============================================================================
// FUN_00539cb0 — MissionStagingMap_Insert (inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00539cb0
// Address:   0x00539cb0  (autoassault.exe, image base 0x400000)
// System:    missions-progression
// Generated: 2026-07-23 scaffold; dual-refined 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler control flow + byte seals.
//            Not modernization. Not bit-for-bit vs retail EXE (deferred).
// Dual:      reviews/A_aa_00539cb0_MissionStagingMap_Insert.md
//            reviews/B_aa_00539cb0_MissionStagingMap_Insert.md
// =============================================================================
//
// PURPOSE:
//   MSVC-like std::map insert-or-find on the character mission-staging tree
//   (MapShell at Character+0x508 when called from FUN_0052c700).
//   - Walk by int key at node+0x10; isnil at +0x49.
//   - Miss: FUN_00538ea0 (this=map) → FUN_005380d0 new(0x50), copy 14 dwords
//     @ +0x10, color +0x48, isnil +0x49; rebalance; out.inserted = 1.
//   - Equal: out.it = existing; out.inserted = 0; payload NOT rewritten.
//   - goLeft && not leftmost: FUN_00537770 predecessor before compare.
//
// ABI: __thiscall; RET 8; ECX = map; args: InsertOutPair*, valuePair*.
// Sole static caller: FUN_0052c700 (staging store miss path).
//
// Layout (sealed dual 2026-07-29):
//   MapShell: +4 head*, +8 size
//   Node 0x50: left/parent/right @0/4/8; key@0x10; pad@0x14; payload[12]@0x18;
//              color@0x48; isnil@0x49
//   Value pair: key, pad, payload[12]  (14 dwords)
//   Out pair:   node* @0, uint8 inserted @4
// =============================================================================

#include <cstdint>

// Callees (Ghidra names retained):
//   FUN_00538ea0 — __thiscall insert + rebalance (ECX=map)
//   FUN_00537770 — __fastcall predecessor (ECX = iterator*)

extern "C" uint32_t* __thiscall FUN_00538ea0(int mapThis, uint32_t* outIt,
                                             char addLeft, uint32_t* where,
                                             int* valuePair);
extern "C" void __fastcall FUN_00537770(int** pIt);

void __thiscall FUN_00539cb0(int param_1 /* map */,
                             uint32_t* param_2 /* out pair */,
                             int* param_3 /* value pair */)
{
  uint32_t uVar1;
  bool bVar2;
  int* piVar3;
  uint32_t* puVar4;
  uint32_t* puVar5;

  piVar3 = param_3;
  puVar5 = *(uint32_t**)(param_1 + 4);          // head
  bVar2 = true;
  if (*(char*)((int)puVar5[1] + 0x49) == '\0') {
    puVar4 = (uint32_t*)puVar5[1];              // root
    do {
      puVar5 = puVar4;
      bVar2 = *param_3 < (int)puVar5[4];        // key < node[4] (+0x10)
      if (bVar2) {
        puVar4 = (uint32_t*)*puVar5;            // left
      } else {
        puVar4 = (uint32_t*)puVar5[2];          // right
      }
    } while (*(char*)((int)puVar4 + 0x49) == '\0');
  }
  param_3 = (int*)puVar5;                       // parent (iterator storage)
  if (bVar2) {
    if (puVar5 == (uint32_t*)**(int**)(param_1 + 4)) {
      // leftmost: insert with addLeft=1 (ECX=map in real call)
      puVar5 = FUN_00538ea0(param_1, (uint32_t*)&param_3, 1, puVar5, piVar3);
      uVar1 = *puVar5;
      *(uint8_t*)(param_2 + 1) = 1;
      *param_2 = uVar1;
      return;
    }
    // predecessor(&param_3) — decompiler drops ECX; bytes pass &parent
    FUN_00537770(&param_3);
  }
  if (param_3[4] < *piVar3) {
    puVar5 = FUN_00538ea0(param_1, (uint32_t*)&param_3, (char)bVar2, puVar5,
                          piVar3);
    *param_2 = *puVar5;
    *(uint8_t*)(param_2 + 1) = 1;
    return;
  }
  // equal key — find only
  *(uint8_t*)(param_2 + 1) = 0;
  *param_2 = (uint32_t)param_3;
  return;
}
