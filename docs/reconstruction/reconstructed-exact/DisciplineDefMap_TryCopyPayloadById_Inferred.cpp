// =============================================================================
// DisciplineDefMap_TryCopyPayloadById_Inferred  (aka FUN_0052b040)
// -----------------------------------------------------------------------------
// Stable ID: aa_0052b040
// Address:   0x0052b040  (autoassault.exe, image base 0x400000)
// System:    skills-abilities
// Dual:      R12-020 OWN-ONLY 2026-08-05 (dual start 2646)
// Exactness: Behavior-preserving rewrite of decompiler + asm-sealed CF.
// Bit-for-bit vs retail EXE: DEFERRED.
// Runtime Confirmed: NOT claimed.
// =============================================================================
//
// PURPOSE:
//   Exact-find int key in the process-global DisciplineDef ordered map
//   (header @ 0x00b045b0, end sentinel DAT_00b045b4) via FUN_00538ab0.
//   On hit: copy 0x1FC (0x7f dwords) from node+0x10 into caller out-buffer.
//   On miss: return false without writing.
//
// ABI (asm-sealed):
//   bool __cdecl DisciplineDefMap_TryCopyPayloadById_Inferred(int key, void *outPayload0x1FC);
//   - two stack args; bare RET; callers ADD ESP,8
//   - return bool in AL (0 miss / 1 hit)
//
// DISTINCT FROM:
//   SkillDefMap_* @ DAT_00b04734 (nil +0x641, larger payload) — different table.
//   CVOGCharacter_GetResourceBalanceByType @ character+0x584 — per-char balances.
//
// PARENT EVIDENCE (not dualled here):
//   FUN_00846820 @ 0x00846c34 — operator_new(0x1fc); key from item+0x4ac;
//   UI "Discipline: "; name FUN_00403450(out+0x2a).
// =============================================================================

#include <stdint.h>

// Map exact-find: thiscall(map, Node **out, int *key); ret 8.
// Nil @ node+0x20d; key @ node+0x0C.
extern "C" void *__thiscall FUN_00538ab0(void *mapHeader, void *outNodeSlot, int *pKey);

// Globals (image)
// DAT_00b045b0 — map header (ECX hardcode)
// DAT_00b045b4 — end / head sentinel (same as *(header+4) at runtime when inited)

extern "C" void *DAT_00b045b4;
static void *const g_DisciplineDefMapHeader = (void *)0x00b045b0;

extern "C" uint8_t __cdecl DisciplineDefMap_TryCopyPayloadById_Inferred(
    int disciplineId,
    uint32_t *outPayload /* 0x7f dwords / 0x1FC bytes */)
{
  void *outItSlot; /* stack local matching PUSH ECX */
  void *nodeSlot = &outItSlot;
  int key = disciplineId;
  void **pNode;

  pNode = (void **)FUN_00538ab0(g_DisciplineDefMapHeader, nodeSlot, &key);
  {
    uint8_t *node = (uint8_t *)*pNode;
    if (node == (uint8_t *)DAT_00b045b4) {
      return 0;
    }
    {
      uint32_t *src = (uint32_t *)(node + 0x10);
      uint32_t *dst = outPayload;
      int n = 0x7f;
      while (n != 0) {
        *dst = *src;
        ++src;
        ++dst;
        --n;
      }
    }
    return 1;
  }
}

// Ghidra twin export name
extern "C" uint8_t __cdecl FUN_0052b040(int param_1, uint32_t *param_2)
{
  return DisciplineDefMap_TryCopyPayloadById_Inferred(param_1, param_2);
}
