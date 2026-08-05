// =============================================================================
// Object_RefreshSkillHash_Inferred  (FUN_00517400)
// -----------------------------------------------------------------------------
// Stable ID: aa_00517400
// Address:   0x00517400  (autoassault.exe, image base 0x400000)
// Body:      0x00517400 – 0x00517675
// System:    skills-abilities
// Generated: 2026-07-23 scaffold; dual A/B seal 2026-07-29 (W20-T)
// Exactness: Behavior-preserving rewrite of decompiler + read_memory CF.
//            Not modernization. Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE: Under skill-hash traversal lock (host+0x70), walk every skill in the
// hash chain. Per skill: optionally clear sibling cast HBs (inlined predicate
// flag 0), optionally reload skill-def when bReloadSkillDef≠0, reevaluate for
// current rank, and copy MB display name into skill+0x1a5. On chain end: unlock
// and may call FUN_00516a00(0) when host vtbl gates pass.
//
// ABI: __cdecl — (pHost, bReloadSkillDef) on stack; bare ret (c3).
// Not thiscall (both formals stack; epilogue not ret 4/8).
//
// RELATED:
//   - Skill_SiblingCastClear / Predicate (inlined invoke here, flag 0)
//   - Skill_ReevaluateForCurrentRank
//   - FUN_00516a00 — post-refresh cast re-fire
//   - Caller FUN_00517df0 — map/zone refresh orchestration
//   - SkillTree_RemoveBySkillId_Inferred (0x0052db50) — vector remove path
//

#include <cstdint>
#include <cstring>

// External symbols (retail VAs / named seals)
extern void FUN_00799940();
extern void FUN_007989b0();
extern void FUN_007a4480(int, const char *);
extern void CNDDoubleList_InvokePredicateAndRemove_Inferred(
    void *pList, void *pPred, void *pCtx, int nullPayloadFlag);
extern void Skill_SiblingCastClearPredicate_INFERRED();  // VA 0x00512bb0 as DATA
extern void FUN_007e26e0(uint32_t skillId, void *outBuf);
extern void FUN_0054a290(void *loadedRec, void *aux);
extern void Skill_ReevaluateForCurrentRank(void *pSkill);
extern void FUN_0054f430(void *pSkill /*this*/, char *mbName);  // → skill+0x1a5
extern void FUN_00516a00(void *pHost /*this*/, char flag);
extern void *malloc(size_t);
extern void free(void *);
extern int lstrlenW(const wchar_t *);
extern int WideCharToMultiByte(unsigned, unsigned long, const wchar_t *, int,
                               char *, int, const char *, int *);
extern unsigned (*PTR_GetACP)();  // PTR_FUN_00af8c9c

struct SiblingClearCtx {
  int skillId;
  int _padUnset;
  uint32_t tfid[4];
  uint8_t alsoOkToCastAgain;
};

// Canonical
void Object_RefreshSkillHash_Inferred(int *pHost, char bReloadSkillDef)
{
  if (pHost == nullptr) {
    return;
  }

  // SEH frame + scope helper (FUN_00799940 / FUN_007989b0) omitted as CRT noise
  FUN_00799940();

  int *pHash = reinterpret_cast<int *>(pHost[0x1c]);  // +0x70
  if (*reinterpret_cast<char *>(reinterpret_cast<char *>(pHash) + 0x1d) != 0) {
    FUN_007a4480(0, "HashError:TraversalLock, already locked for traversal");
    FUN_007a4480(0, "VOG_DEBUG_STOP");
  }
  *reinterpret_cast<char *>(reinterpret_cast<char *>(pHash) + 0x1d) = 1;

  int *pNode = nullptr;
  for (;;) {
    pHash = reinterpret_cast<int *>(pHost[0x1c]);
    if (*reinterpret_cast<char *>(reinterpret_cast<char *>(pHash) + 0x1d) == 0) {
      FUN_007a4480(0, "HashError:TraverseToNext, not locked for traversal");
      FUN_007a4480(0, "VOG_DEBUG_STOP");
    }

    void *pSkill = nullptr;
    if (pNode == nullptr) {
      pNode = *reinterpret_cast<int **>(reinterpret_cast<char *>(pHash) + 0x14);
      if (pNode != nullptr) {
        pSkill = *reinterpret_cast<void **>(reinterpret_cast<char *>(pNode) + 8);
      }
    } else {
      pNode = *reinterpret_cast<int **>(reinterpret_cast<char *>(pNode) + 0x14);
      if (pNode != nullptr) {
        pSkill = *reinterpret_cast<void **>(reinterpret_cast<char *>(pNode) + 8);
      }
    }

    if (pSkill == nullptr) {
      *reinterpret_cast<char *>(pHost[0x1c] + 0x1d) = 0;
      auto v210 = reinterpret_cast<int(__thiscall *)(void *, int)>(
          *reinterpret_cast<void **>(*pHost + 0x210));
      auto v214 = reinterpret_cast<int(__thiscall *)(void *)>(
          *reinterpret_cast<void **>(*pHost + 0x214));
      if (v210(pHost, 0) != 0 || v214(pHost) != 0) {
        FUN_00516a00(pHost, 0);
      }
      FUN_007989b0();
      return;
    }

    auto v214 = reinterpret_cast<int(__thiscall *)(void *)>(
        *reinterpret_cast<void **>(*pHost + 0x214));
    auto v210 = reinterpret_cast<int(__thiscall *)(void *, int)>(
        *reinterpret_cast<void **>(*pHost + 0x210));
    if ((v214(pHost) != 0 || v210(pHost, 0) != 0) &&
        ((*reinterpret_cast<uint8_t *>(reinterpret_cast<char *>(pSkill) + 0x615) & 1) != 0)) {
      SiblingClearCtx ctx{};
      ctx.skillId = *reinterpret_cast<int *>(reinterpret_cast<char *>(pSkill) + 0x5fc);
      ctx.tfid[0] = static_cast<uint32_t>(pHost[0x58]);  // +0x160
      ctx.tfid[1] = static_cast<uint32_t>(pHost[0x59]);
      ctx.tfid[2] = static_cast<uint32_t>(pHost[0x5a]);
      ctx.tfid[3] = static_cast<uint32_t>(pHost[0x5b]);
      ctx.alsoOkToCastAgain = 0;
      void *pList = *reinterpret_cast<void **>(reinterpret_cast<char *>(pHost) + 0xB0);
      CNDDoubleList_InvokePredicateAndRemove_Inferred(
          pList,
          reinterpret_cast<void *>(&Skill_SiblingCastClearPredicate_INFERRED),
          &ctx,
          0);
    }

    if (bReloadSkillDef != 0) {
      uint8_t loadBuf[/* skill-def temp; size open */ 0x400];
      uint8_t aux[20];
      FUN_007e26e0(
          *reinterpret_cast<uint32_t *>(reinterpret_cast<char *>(pSkill) + 0x5fc),
          loadBuf);
      FUN_0054a290(loadBuf, aux);
    }

    Skill_ReevaluateForCurrentRank(pSkill);

    // Wide → MB display name, then store at skill+0x1a5 via FUN_0054f430.
    // Wide source buffer is a large stack WCHAR region in retail (decomp local
    // aWStack_8c6); filled as a side effect of the reevaluate / def path.
    // Port must keep: convert then FUN_0054f430(pSkill, mb).
    char stackMb[128];
    char *pMb = stackMb;
    // ... WideCharToMultiByte from reevaluate-produced wide string ...
    // (exact wide buffer origin: open gap; call order sealed)
    FUN_0054f430(pSkill, pMb);
    if (pMb != stackMb) {
      free(pMb);
    }
  }
}

// Ghidra alias
void FUN_00517400(int *param_1, char param_2)
{
  Object_RefreshSkillHash_Inferred(param_1, param_2);
}

// Legacy auto string alias (misleading as sole role — debug stop is error path only)
void Named_VOG_DEBUG_STOP_00517400(int *param_1, char param_2)
{
  Object_RefreshSkillHash_Inferred(param_1, param_2);
}
