// =============================================================================
// Skill_HB_ApplyShortAndFloater_Inferred  (FUN_0058cc40)
// -----------------------------------------------------------------------------
// Stable ID: aa_0058cc40
// Address:   0x0058cc40–0x0058cd54 inclusive (277 B / 0x115)
// Module:    autoassault.exe (image base 0x400000)
// System:    skills-abilities / Skill HB combat pools
// Generated: 2026-08-05 MEGA-008 dual seal (body ≡ 2026-07-23 raw + assembly seal)
// Exactness: Behavior-preserving rewrite of decompiler control flow + assembly ABI.
// Bit-for-bit vs retail EXE: DEFERRED.
// Runtime:   not Confirmed (Terminal false; no Launcher).
// =============================================================================

/*
 * Behavioral notes (MEGA-008 sealed):
 * - Skill HB helper: resolve a short-pool host via vtbl+0x214, apply signed float
 *   as absolute or percent-of-max short (+0x12e), write via vtbl+0xAC, then enqueue
 *   a combat floater (type 2) with source/target colors.
 * - Amount sign: positive float → increase short; negative → decrease.
 *   Damage-style parents multiply magnitude by DAT_00aaa668 (-1.0f).
 * - |amount| <= 1.0 → percent of max short @+0x12e; else absolute trunc add.
 * - ABI: __cdecl, 3 stack args, bare RET; callers ADD ESP,0xC.
 * - Sole non-virtual callee: Client_EnqueueCombatFloater_INFERRED @ 0x00402620
 *   thiscall with ECX = *(target+0xA4) + 0xE8A4.
 * - Parents: FUN_0061b6f0 (skill HB tick, flag bit 0x80 @ skill+0x649),
 *   FUN_00618270, plus switch/multi-apply sites.
 * - Sibling family: ApplyHeat 00589bc0, ApplyHp 00589c70, ApplyShield 00589d90,
 *   ApplyMultiArg 0058d8e0.
 * - Name is _Inferred: role sealed by parent HB dispatcher + short-field mutate +
 *   floater enqueue; no product demangle string on this VA.
 * - Odd preserved: floater path always loads target+0x160 / target+0xA4 with no
 *   null check (null target after short-miss is UB/crash).
 */

#include <cstdint>

// Globals (image)
extern "C" float DAT_00aaa668; // -1.0f @ 0x00aaa668
extern "C" float g_flOne;      //  1.0f @ 0x00a0f2a0
extern "C" std::uint32_t DAT_009d4d28;
extern "C" std::uint32_t DAT_009d4d2c;
extern "C" std::uint32_t DAT_009d4d30;
extern "C" std::uint32_t DAT_009d4d34;

// Combat floater queue push (thiscall; ECX = queue owner)
// Element stride 0x38; dualed elsewhere as Client_EnqueueCombatFloater_INFERRED.
extern "C" void __thiscall Client_EnqueueCombatFloater_INFERRED(
    void *this_queue,
    void *floaterBlob);

using VMethod_P = void *(__thiscall *)(void *self);
using VMethod_SetI = void (__thiscall *)(void *self, int value);

static inline void *VtblCall_0x214(void *obj)
{
  auto **vt = *reinterpret_cast<VMethod_P **>(obj);
  return vt[0x214 / 4](obj);
}

static inline void VtblCall_SetShort_0xac(void *obj, int newValue)
{
  auto **vt = *reinterpret_cast<VMethod_SetI **>(obj);
  vt[0xAC / 4](obj, newValue);
}

// Floater stack blob layout (matches locals + assembly stores)
struct CombatFloaterBlob_ShortType2 {
  std::uint32_t srcColor[4]; // +0x00 from source+0x160 or DAT_009d4d28
  std::uint32_t tgtColor[4]; // +0x10 from target+0x160
  int delta;                 // +0x20 applied short delta
  std::uint8_t pad_24[0xc];  // +0x24..+0x2f (untouched / zeroed flags region)
  std::uint8_t flag0;        // +0x2c area: assembly writes three zero bytes near end
  std::uint8_t flag1;
  std::uint8_t flag2;
  std::uint8_t pad_2f;
  // Assembly: [ESP+0x34]=delta already at +0x20 relative blob start ESP+0x10
  //           [ESP+0x3c..0x3e]=0 flags; [ESP+0x44]=type 2
  // Represent type at end of 0x38 blob:
  std::uint32_t type;        // = 2
};

// __cdecl
extern "C" int Skill_HB_ApplyShortAndFloater_Inferred(
    void *sourceOrNull,
    void *targetObj,
    float amount)
{
  void *host;
  if (targetObj == nullptr && sourceOrNull != nullptr)
    host = VtblCall_0x214(sourceOrNull);
  else
    host = VtblCall_0x214(targetObj);

  int applied = 0;
  if (host != nullptr) {
    int deltaInt = static_cast<int>(amount); // CVTTSS2SI toward zero
    if (DAT_00aaa668 <= amount && amount <= g_flOne) {
      auto maxShort = *reinterpret_cast<std::int16_t *>(
          reinterpret_cast<std::uint8_t *>(host) + 0x12e);
      deltaInt = static_cast<int>(static_cast<float>(static_cast<int>(maxShort)) * amount);
    }

    auto oldShort = *reinterpret_cast<std::int16_t *>(
        reinterpret_cast<std::uint8_t *>(host) + 0x12c);
    VtblCall_SetShort_0xac(host, static_cast<int>(oldShort) + deltaInt);

    auto newShort = *reinterpret_cast<std::int16_t *>(
        reinterpret_cast<std::uint8_t *>(host) + 0x12c);
    applied = static_cast<int>(newShort) - static_cast<int>(oldShort);
  }

  // Build floater blob at [ESP+0x10] family (assembly SUB ESP,0x38 frame)
  alignas(4) std::uint8_t blob[0x38];
  for (int i = 0; i < 0x38; ++i)
    blob[i] = 0;

  std::uint32_t *srcColor;
  if (sourceOrNull != nullptr)
    srcColor = reinterpret_cast<std::uint32_t *>(
        reinterpret_cast<std::uint8_t *>(sourceOrNull) + 0x160);
  else
    srcColor = &DAT_009d4d28;

  auto *dst = reinterpret_cast<std::uint32_t *>(blob);
  dst[0] = srcColor[0];
  dst[1] = srcColor[1];
  dst[2] = srcColor[2];
  dst[3] = srcColor[3];

  // target colors — no null check (retail)
  auto *tgtColor = reinterpret_cast<std::uint32_t *>(
      reinterpret_cast<std::uint8_t *>(targetObj) + 0x160);
  dst[4] = tgtColor[0];
  dst[5] = tgtColor[1];
  dst[6] = tgtColor[2];
  dst[7] = tgtColor[3];

  *reinterpret_cast<int *>(blob + 0x20) = applied; // [ESP+0x30] relative ESP+0x10
  blob[0x2c] = 0; // flag bytes near end of blob (assembly ESP+0x3c family)
  blob[0x2d] = 0;
  blob[0x2e] = 0;
  *reinterpret_cast<std::uint32_t *>(blob + 0x34) = 2; // floater type

  void *combatCtrl = *reinterpret_cast<void **>(
      reinterpret_cast<std::uint8_t *>(targetObj) + 0xA4);
  void *queueThis = reinterpret_cast<std::uint8_t *>(combatCtrl) + 0xE8A4;
  Client_EnqueueCombatFloater_INFERRED(queueThis, blob);

  return applied;
}

// Ghidra export alias
extern "C" int FUN_0058cc40(void *a, void *b, float c)
{
  return Skill_HB_ApplyShortAndFloater_Inferred(a, b, c);
}
