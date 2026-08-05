// =============================================================================
// SkillTree_RemoveBySkillId_Inferred  (FUN_0052db50)
// -----------------------------------------------------------------------------
// Stable ID: aa_0052db50
// Address:   0x0052db50  (autoassault.exe, image base 0x400000)
// Body:      0x0052db50 – 0x0052dc15
// System:    skills-abilities
// Generated: 2026-07-23 scaffold; dual A/B seal 2026-07-29 (W20-T)
// Exactness: Behavior-preserving rewrite of decompiler + read_memory CF.
//            Decompiler omitted vector erase after delete — restored from bytes.
//            Not modernization. Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE: Walk the 12-byte skill-tree vector at this+0x550..+0x554. On first
// (and any subsequent) element whose skill* has skillId at +0x5fc matching the
// argument: MI-adjust to cast-list host, Skill_SiblingCastClear(..., flag=1),
// operator_delete the skill, erase the vector element (slide + end-=0xC), and
// continue without advancing (next entry now at same index).
//
// ABI: __thiscall — ECX=this; stack int nSkillId; ret 4 (c2 04 00).
//
// RELATED:
//   - Skill_SiblingCastClear (0x00514e20) — sole domain callee; flag=1
//   - Caller FUN_00623a20 — skillIds at ctx+0x178/17c/180; this from vtbl+0x210
//   - Object_RefreshSkillHash_Inferred (0x00517400) — hash refresh path
//

#include <cstdint>

extern void Skill_SiblingCastClear(
    void *pHost /*this*/,
    int nSkillId,
    uint32_t t0, uint32_t t1, uint32_t t2, uint32_t t3,
    uint8_t bAlsoOkToCastAgain);
extern void operator_delete(void *p);

// Canonical
void __thiscall SkillTree_RemoveBySkillId_Inferred(void *pThis, int nSkillId)
{
  auto *pBase = reinterpret_cast<uint8_t *>(pThis);
  auto **ppBegin = reinterpret_cast<void ***>(pBase + 0x550);
  auto **ppEnd   = reinterpret_cast<void ***>(pBase + 0x554);

  // element = 3 pointers / 12 bytes; first dword is skill*
  auto *pIt = reinterpret_cast<uint32_t *>(*ppBegin);
  auto *pEnd = reinterpret_cast<uint32_t *>(*ppEnd);

  if (pIt == pEnd) {
    return;
  }

  do {
    void *pSkill = reinterpret_cast<void *>(pIt[0]);
    if (*reinterpret_cast<int *>(reinterpret_cast<char *>(pSkill) + 0x5fc) == nSkillId) {
      // adj = this + *(*(this+4)+4)
      int delta = *reinterpret_cast<int *>(
          *reinterpret_cast<int *>(pBase + 4) + 4);
      uint8_t *pAdj = pBase + delta;
      void *pHost = pAdj + 4;  // SiblingCastClear this

      Skill_SiblingCastClear(
          pHost,
          nSkillId,
          *reinterpret_cast<uint32_t *>(pAdj + 0x164),
          *reinterpret_cast<uint32_t *>(pAdj + 0x168),
          *reinterpret_cast<uint32_t *>(pAdj + 0x16c),
          *reinterpret_cast<uint32_t *>(pAdj + 0x170),
          /*bAlsoOkToCastAgain=*/1);

      operator_delete(pSkill);

      // erase current 12-byte slot
      uint32_t *pNext = pIt + 3;
      uint32_t *pCurEnd = reinterpret_cast<uint32_t *>(*ppEnd);
      if (pNext != pCurEnd) {
        uint32_t *dst = pIt;
        uint32_t *src = pNext;
        do {
          dst[0] = src[0];
          dst[1] = src[1];
          dst[2] = src[2];
          dst += 3;
          src += 3;
        } while (src != pCurEnd);
      }
      *ppEnd = reinterpret_cast<void **>(
          reinterpret_cast<uint8_t *>(*ppEnd) - 0xC);
      // keep pIt — element at this index is the former next
    } else {
      pIt += 3;
    }
  } while (pIt != reinterpret_cast<uint32_t *>(*ppEnd));
}

// Ghidra alias
void __thiscall FUN_0052db50(int param_1, int param_2)
{
  SkillTree_RemoveBySkillId_Inferred(reinterpret_cast<void *>(param_1), param_2);
}
