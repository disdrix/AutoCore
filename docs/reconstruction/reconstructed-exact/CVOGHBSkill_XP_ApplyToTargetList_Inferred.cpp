// =============================================================================
// CVOGHBSkill_XP_ApplyToTargetList_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0061c590
// Address:   0x0061c590–0x0061c6af  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_0061c590
// System:    skills-abilities
// Class:     CVOGHBSkill_XP  (RTTI Confirmed ".?AVCVOGHBSkill_XP@@")
// Generated: 2026-08-05 R11-015 dual (clean named)
// Exactness: Behavior-preserving rewrite of decompiler + byte-sealed resolve this.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE:
//   Walk a sentinel-terminated 0x10-byte TFID row table. For each row that
//   resolves to a live object, construct a CVOGHBSkill_XP heartbeat (0x6c0),
//   install subclass vtbl, force always-ready period (-1000), and either
//   Enqueue+Start on the world HB list or virtual-delete if ValidateTarget
//   left pOwner null.
//
// ABI: six stack formals; ret 0x18; EAX = 1 on sentinel exit.
// Vtbl: PTR_FUN_009d119c slot +0x2C (sole DATA xref).

#include <cstdint>

// External symbols (Ghidra / prior duals) — not redefined here.
struct CVOGHBBase;
extern "C" {
void *operator_new(unsigned size);
void *CVOGReaction_ResolveObjectTarget(void *ctx, unsigned char bGlobal,
                                       unsigned coidLo, unsigned coidHi);
CVOGHBBase *CVOGHBSkillBase_ctor(CVOGHBBase *self, void *pSourceObj,
                                 void *pSkillBlob, void *pWorld, void *pTarget,
                                 void *pTfid16, unsigned arg7);
void CVOGHBBase_SetPeriodAndCounter(CVOGHBBase *self, int nPeriodSentinel,
                                    bool bAlsoSetCounter);
void CVOGHBList_Enqueue(void *list, CVOGHBBase *action);
void CVOGHBBase_Start(CVOGHBBase *action);
}

// Vtbl for CVOGHBSkill_XP (RTTI COL 0x00aade00 → type_info 0x00af29ec).
extern "C" void *PTR_FUN_009d119c[];

struct CVOGHBBase {
  void **pVTable;       // +0x00
  // ...
  // int nPulsePeriodMs; // +0x08  (written from skillBlob+0x1c)
  // void *pOwnerObject; // +0x18
};

using ScalarDtorFn = void(__thiscall *)(CVOGHBBase *self, int flags);

std::uint32_t CVOGHBSkill_XP_ApplyToTargetList_Inferred(
    void *pSourceObj, void *pSkillBlob, void *pWorld, std::uint8_t *pRows,
    void *pTfid16, std::uint32_t arg7) {
  char index = 0;
  // SEH frame: LAB_009a879b — omitted in clean port shape

  for (;;) {
    std::uint8_t *row = pRows + (static_cast<int>(index) * 0x10);
    auto *asDword = reinterpret_cast<std::int32_t *>(row);

    // Sentinel: {-1, -1, mode byte 0}
    if (asDword[0] == -1 && asDword[1] == -1 && row[8] == 0) {
      return 1;
    }

    // Byte-sealed: ResolveObjectTarget is __thiscall; ECX = *(world+0xe4e8).
    void *resolveCtx = *reinterpret_cast<void **>(static_cast<char *>(pWorld) + 0xe4e8);
    void *target = CVOGReaction_ResolveObjectTarget(
        resolveCtx, row[8], static_cast<unsigned>(asDword[0]),
        static_cast<unsigned>(asDword[1]));

    if (target != nullptr) {
      auto *hb = static_cast<CVOGHBBase *>(operator_new(0x6c0));
      if (hb != nullptr) {
        CVOGHBSkillBase_ctor(hb, pSourceObj, pSkillBlob, pWorld, target, pTfid16,
                             arg7);
        hb->pVTable = PTR_FUN_009d119c;
        *reinterpret_cast<std::int32_t *>(reinterpret_cast<char *>(hb) + 0x08) =
            *reinterpret_cast<std::int32_t *>(static_cast<char *>(pSkillBlob) + 0x1c);
        CVOGHBBase_SetPeriodAndCounter(hb, -1000, true);
      }
      // Retail falls through even if operator_new failed (UB) — preserved.
      void *owner =
          *reinterpret_cast<void **>(reinterpret_cast<char *>(hb) + 0x18);
      if (owner != nullptr) {
        void *hbList =
            *reinterpret_cast<void **>(static_cast<char *>(pWorld) + 0xe4ec);
        CVOGHBList_Enqueue(hbList, hb);
        CVOGHBBase_Start(hb);
      } else {
        auto dtor = reinterpret_cast<ScalarDtorFn>(hb->pVTable[0]);
        dtor(hb, 1);
      }
    }
    index = static_cast<char>(index + 1);
  }
}
