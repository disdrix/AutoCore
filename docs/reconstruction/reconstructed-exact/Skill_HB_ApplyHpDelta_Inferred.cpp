// =============================================================================
// Skill_HB_ApplyHpDelta_Inferred  (FUN_00589c70)
// -----------------------------------------------------------------------------
// Stable ID: aa_00589c70
// Address:   0x00589c70–0x00589d80 inclusive (273 B / 0x111)
// Module:    autoassault.exe (image base 0x400000)
// System:    skills-abilities / Skill HB combat pools
// Generated: 2026-08-05 MEGA-006 dual seal (body ≡ 2026-07-23 raw)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Behavioral notes (MEGA-006 sealed):
 * - Skill HB helper: resolve target combat entity, convert signed float amount
 *   into integer HP delta, optional leave-1-HP floor, apply via FUN_004d7e30.
 * - Amount sign: positive float → heal; negative float → damage.
 *   Callers that deal damage often multiply magnitude by DAT_00aaa668 (-1.0f).
 * - |amount| <= 1.0 → percent of max HP (vtbl+0x244); else absolute trunc.
 * - apply pipeline (FUN_004d78e0): HP' = HP - deltaInt  (positive deltaInt = damage).
 * - ABI: __cdecl, 4 stack args, bare RET; callers ADD ESP,0x10.
 * - Sole callee: FUN_004d7e30 with this = entity+0xA4.
 * - Parents: FUN_0061b6f0 (skill HB tick), FUN_00618270, plus switch sites.
 * - Sibling family: ApplyHeatDelta 00589bc0, ApplyShieldPool 00589d90, …
 * - Name is _Inferred: role sealed by parent HB dispatcher + HP vtbl/apply path;
 *   no product demangle string on this VA.
 */

#include <cstdint>

// Globals (image)
extern "C" float DAT_00aaa668; // -1.0f
extern "C" float g_flOne;      // 1.0f @ 0x00a0f2a0
extern "C" std::uint32_t DAT_009d4d28;
extern "C" std::uint32_t DAT_009d4d2c;
extern "C" std::uint32_t DAT_009d4d30;
extern "C" std::uint32_t DAT_009d4d34;

// Combat apply + floater path (thiscall; ECX = combat controller)
// Decompiler signature is noisy; call site pushes mode/delta/src/tgt/flags/color.
extern "C" char __thiscall FUN_004d7e30(
    void *this_ctrl,
    int mode0,
    int hpDeltaInt,
    void *sourceOrNull,
    void *targetEntity,
    int flagA,
    int flagB,
    int flagC,
    std::uint32_t color0,
    std::uint32_t color1,
    std::uint32_t color2,
    std::uint32_t color3,
    void *extraOrNull);

using VMethod = void *(__thiscall *)(void *self);
using VMethod_I = int (__thiscall *)(void *self);

static inline void *VtblCall_0x19c(void *obj)
{
  auto **vt = *reinterpret_cast<VMethod **>(obj);
  return vt[0x19C / 4](obj);
}

static inline int VtblCall_GetCurrentHp(void *obj)
{
  auto **vt = *reinterpret_cast<VMethod_I **>(obj);
  return vt[0x23C / 4](obj);
}

static inline int VtblCall_GetMaxHp(void *obj)
{
  auto **vt = *reinterpret_cast<VMethod_I **>(obj);
  return vt[0x244 / 4](obj);
}

// MSVC complete-object style adjust used at both resolve sites:
//   ESI = *( *(ret+4) + 4 ) + ret + 4
static inline void *AdjustCompleteObject(void *iface)
{
  if (iface == nullptr)
    return nullptr;
  auto *p1 = *reinterpret_cast<std::uint8_t **>(reinterpret_cast<std::uint8_t *>(iface) + 4);
  auto off = *reinterpret_cast<std::int32_t *>(p1 + 4);
  return reinterpret_cast<std::uint8_t *>(iface) + off + 4;
}

// __cdecl
extern "C" int Skill_HB_ApplyHpDelta_Inferred(
    void *sourceOrNull,
    void *targetObj,
    float amount,
    char allowKill)
{
  void *entity = sourceOrNull;

  if (targetObj != nullptr) {
    void *iface = VtblCall_0x19c(targetObj);
    if (iface != nullptr) {
      entity = AdjustCompleteObject(iface);
      if (entity != nullptr)
        goto apply;
    }
    entity = *reinterpret_cast<void **>(reinterpret_cast<std::uint8_t *>(targetObj) + 0xAC);
  }

  if (entity == nullptr)
    return 0;

  {
    void *iface = VtblCall_0x19c(entity);
    if (iface == nullptr)
      return 0;
    entity = AdjustCompleteObject(iface);
    if (entity == nullptr)
      return 0;
  }

apply:
  // deltaInt = -trunc(amount); percent path when amount in [-1, 1]
  int deltaInt = -static_cast<int>(amount);
  if (DAT_00aaa668 <= amount && amount <= g_flOne) {
    int maxHp = VtblCall_GetMaxHp(entity);
    deltaInt = -static_cast<int>(static_cast<float>(maxHp) * amount);
  }

  int curHp = VtblCall_GetCurrentHp(entity);
  int projected = curHp - deltaInt;

  // leave-at-least-1 when allowKill==0 (return still uses unclamped projected)
  if (allowKill == 0 && projected < 1)
    deltaInt = curHp - 1;

  void *combatCtrl = *reinterpret_cast<void **>(reinterpret_cast<std::uint8_t *>(entity) + 0xA4);
  FUN_004d7e30(
      combatCtrl,
      0,
      deltaInt,
      sourceOrNull,
      entity,
      1,
      1,
      0,
      DAT_009d4d28,
      DAT_009d4d2c,
      DAT_009d4d30,
      DAT_009d4d34,
      nullptr);

  if (curHp == projected)
    return 0;
  return projected - curHp;
}

// Ghidra export alias
extern "C" int FUN_00589c70(void *a, void *b, float c, char d)
{
  return Skill_HB_ApplyHpDelta_Inferred(a, b, c, d);
}
