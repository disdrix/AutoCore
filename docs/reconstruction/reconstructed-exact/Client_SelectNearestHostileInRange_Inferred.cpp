// =============================================================================
// Client_SelectNearestHostileInRange_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00943520
// Address:   0x00943520–0x009436bb  (autoassault.exe, image base 0x400000)
// System:    skills-abilities / client target pick (WQ-009 residual)
// Generated: 2026-07-23 scaffold as FUN_00943520; **sealed 2026-08-04** dual A/B WQ9R-D
// Exactness: Behavior-preserving. EAX-this client host; stack range float; RET 4.
// Bit-for-bit vs retail EXE: DEFERRED
// Dual:      accept-with-gaps (A+B 2026-08-04)
// =============================================================================

/*
 * Behavioral notes (2026-08-04 seal):
 * - Nearest hostile select within rangeArg (bound-action poll / target key).
 * - ABI: this in EAX (client; PollBoundActions uses DAT_00d1a840);
 *   stack float rangeArg; RET 4. Prologue: MOV ESI,EAX.
 * - Gate: char = *(this+0xe98); if *(u8*)(char+0x4f1) != 0 → return.
 * - Origin: MI(char) → vtbl+0x1a0() float4 position copy to stack.
 * - Seed out TFID from g_abTfidInvalid_A15870 (ffffffff×2, zeros).
 * - Gather ×1–2 via Skill_GatherTargetsInArea:
 *     maxTargets=1, mode=2 (hostile), filterA=0, chainRefresh=0,
 *     allowSelfMode1=1, filterB=0, filterC=1, scoreArg=-1.0f;
 *     pass1 sortByDistance=1, pass2 (only if still invalid) sort=0.
 * - Invalid TFID: (lo & hi) == 0xffffffff && bGlobal == 0.
 * - On hit: ECX = *(*(char_comp+0xa8)+0xe4e8); Object_ResolveFromTFID(&tfid);
 *   if non-null → Client_SelectTargetObject_Inferred(obj).
 * - Callers: Client_Input_PollBoundActions ×3 with range 110.0f (0x42dc0000);
 *   when DAT_00d1d888 non-null, sibling FUN_00943340 cycles instead.
 * - Related: Client_SelectHostileUnderScreenPick (screen ray, dynamic range).
 */

#include <cstdint>

struct TFID_16 {
  std::uint32_t dwCoidLo;  // +0
  std::uint32_t dwCoidHi;  // +4
  std::uint8_t  bGlobal;   // +8
  std::uint8_t  pad[7];    // +9..+15
};

// aa_0058d330 — dualed; 15 stack args; caller ADD ESP,0x3c.
extern "C" void Skill_GatherTargetsInArea(
    TFID_16 *outTfidList, int startIndex, std::uint32_t queryArg, void *pSource,
    float *pOrigin, float rangeArg, int maxTargets, int gatherMode,
    std::uint32_t filterA, char chainRefresh, char allowSelfMode1,
    std::uint32_t filterB, std::uint32_t filterC, char sortByDistance,
    std::uint32_t scoreArg);

// aa_004bb950 — resolve-only; ECX = resolve ctx.
extern "C" void * __thiscall Object_ResolveFromTFID(void *ctx, TFID_16 *pTfid);

// aa_0093e120 — dualed select applicator.
extern "C" void Client_SelectTargetObject_Inferred(void *obj);

// Invalid TFID bank @ 0x00a15870 — 8×0xFF + 8×0x00.
extern "C" const std::uint8_t g_abTfidInvalid_A15870[16];

// MI interior: *( *(obj+4) + 4 ) + 4 + obj
static inline void *Object_MiInterior(void *obj)
{
  if (obj == nullptr) {
    return nullptr;
  }
  auto *b = reinterpret_cast<std::uint8_t *>(obj);
  auto *p1 = *reinterpret_cast<std::uint8_t **>(b + 4);
  auto *p2 = *reinterpret_cast<std::uint8_t **>(p1 + 4);
  return p2 + 4 + reinterpret_cast<std::uintptr_t>(b);
}

static inline bool Tfid_IsInvalid(const TFID_16 &t)
{
  return ((t.dwCoidLo & t.dwCoidHi) == 0xffffffffu) && (t.bGlobal == 0);
}

// Image: EAX = client this; [esp+4] = rangeArg (float bits); RET 4.
extern "C" void Client_SelectNearestHostileInRange_Inferred(
    void *client /*EAX*/,
    float rangeArg /*stack*/)
{
  auto *clientB = reinterpret_cast<std::uint8_t *>(client);
  void *character = *reinterpret_cast<void **>(clientB + 0xe98);

  if (*reinterpret_cast<std::uint8_t *>(
          reinterpret_cast<std::uint8_t *>(character) + 0x4f1) != 0) {
    return;
  }

  void *charComp = Object_MiInterior(character);

  // vtbl+0x1a0 → float4* position
  using GetPosFn = float *(__thiscall *)(void *self);
  auto *vtbl = *reinterpret_cast<std::uint8_t **>(charComp);
  auto getPos = *reinterpret_cast<GetPosFn *>(vtbl + 0x1a0);
  float *posSrc = getPos(charComp);

  float origin[4];
  origin[0] = posSrc[0];
  origin[1] = posSrc[1];
  origin[2] = posSrc[2];
  origin[3] = posSrc[3];

  TFID_16 out;
  // 16-byte copy of invalid bank (image byte-wise from g_abTfidInvalid_A15870).
  for (int i = 0; i < 16; ++i) {
    reinterpret_cast<std::uint8_t *>(&out)[i] = g_abTfidInvalid_A15870[i];
  }

  void *pSource = Object_MiInterior(
      *reinterpret_cast<void **>(clientB + 0xe98));
  auto *charAgain = *reinterpret_cast<std::uint8_t **>(clientB + 0xe98);
  auto *charComp2 = reinterpret_cast<std::uint8_t *>(Object_MiInterior(charAgain));
  std::uint32_t queryArg = *reinterpret_cast<std::uint32_t *>(charComp2 + 0xa8);

  constexpr std::uint32_t kScoreNegOne = 0xbf800000u;  // -1.0f

  Skill_GatherTargetsInArea(
      &out, 0, queryArg, pSource, origin, rangeArg,
      /*maxTargets*/ 1, /*mode*/ 2, /*filterA*/ 0, /*chain*/ 0, /*allowSelf*/ 1,
      /*filterB*/ 0, /*filterC*/ 1, /*sort*/ 1, kScoreNegOne);

  if (Tfid_IsInvalid(out)) {
    pSource = Object_MiInterior(
        *reinterpret_cast<void **>(clientB + 0xe98));
    charAgain = *reinterpret_cast<std::uint8_t **>(clientB + 0xe98);
    charComp2 = reinterpret_cast<std::uint8_t *>(Object_MiInterior(charAgain));
    queryArg = *reinterpret_cast<std::uint32_t *>(charComp2 + 0xa8);

    Skill_GatherTargetsInArea(
        &out, 0, queryArg, pSource, origin, rangeArg,
        1, 2, 0, 0, 1, 0, 1, /*sort*/ 0, kScoreNegOne);

    if (Tfid_IsInvalid(out)) {
      return;
    }
  }

  // Resolve ctx: *(*(char_comp+0xa8) + 0xe4e8)
  charAgain = *reinterpret_cast<std::uint8_t **>(clientB + 0xe98);
  charComp2 = reinterpret_cast<std::uint8_t *>(Object_MiInterior(charAgain));
  auto *hostOrQuery = *reinterpret_cast<std::uint8_t **>(charComp2 + 0xa8);
  void *resolveCtx = *reinterpret_cast<void **>(hostOrQuery + 0xe4e8);

  void *obj = Object_ResolveFromTFID(resolveCtx, &out);
  if (obj != nullptr) {
    Client_SelectTargetObject_Inferred(obj);
  }
}
