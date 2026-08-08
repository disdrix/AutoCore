// =============================================================================
// FUN_00589c70  — twin of Skill_HB_ApplyHpDelta_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00589c70
// Address:   0x00589c70–0x00589d80 inclusive (273 B / 0x111)
// Module:    autoassault.exe (image base 0x400000)
// System:    skills-abilities / Skill HB combat pools
// Generated: 2026-08-05 MEGA-006 dual seal
// Canonical: docs/reconstruction/reconstructed-exact/Skill_HB_ApplyHpDelta_Inferred.cpp
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Scaffold twin kept under Ghidra name for path compatibility.
 * Prefer Skill_HB_ApplyHpDelta_Inferred as the meaningful export.
 *
 * Sealed facts (MEGA-006):
 * - __cdecl 4 args; bare RET; callers ADD ESP,0x10
 * - amount + → heal, amount − → damage; |amount|<=1 → % max HP
 * - allowKill==0 clamps applied delta to leave 1 HP (return unclamped)
 * - sole callee FUN_004d7e30 (this = entity+0xA4)
 */

#include <cstdint>

extern "C" float DAT_00aaa668;
extern "C" float g_flOne;
extern "C" std::uint32_t DAT_009d4d28;
extern "C" std::uint32_t DAT_009d4d2c;
extern "C" std::uint32_t DAT_009d4d30;
extern "C" std::uint32_t DAT_009d4d34;

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

static inline void *AdjustCompleteObject(void *iface)
{
  if (iface == nullptr)
    return nullptr;
  auto *p1 = *reinterpret_cast<std::uint8_t **>(reinterpret_cast<std::uint8_t *>(iface) + 4);
  auto off = *reinterpret_cast<std::int32_t *>(p1 + 4);
  return reinterpret_cast<std::uint8_t *>(iface) + off + 4;
}

extern "C" int FUN_00589c70(
    void *param_1,
    void *param_2,
    float param_3,
    char param_4)
{
  void *piVar3 = param_1;

  if (param_2 != nullptr) {
    void *iVar1 = VtblCall_0x19c(param_2);
    if (iVar1 != nullptr) {
      piVar3 = AdjustCompleteObject(iVar1);
      if (piVar3 != nullptr)
        goto LAB_00589cce;
    }
    piVar3 = *reinterpret_cast<void **>(reinterpret_cast<std::uint8_t *>(param_2) + 0xAC);
  }

  if (piVar3 == nullptr)
    return 0;

  {
    void *iVar1 = VtblCall_0x19c(piVar3);
    if (iVar1 == nullptr)
      return 0;
    piVar3 = AdjustCompleteObject(iVar1);
    if (piVar3 == nullptr)
      return 0;
  }

LAB_00589cce:
  int iVar1 = -static_cast<int>(param_3);
  if (DAT_00aaa668 <= param_3 && param_3 <= g_flOne) {
    int maxHp = VtblCall_GetMaxHp(piVar3);
    iVar1 = -static_cast<int>(static_cast<float>(maxHp) * param_3);
  }

  int iVar2 = VtblCall_GetCurrentHp(piVar3);
  int iVar4 = iVar2 - iVar1;

  if (param_4 == '\0' && iVar4 < 1)
    iVar1 = iVar2 - 1;

  void *ctrl = *reinterpret_cast<void **>(reinterpret_cast<std::uint8_t *>(piVar3) + 0xA4);
  FUN_004d7e30(
      ctrl, 0, iVar1, param_1, piVar3, 1, 1, 0,
      DAT_009d4d28, DAT_009d4d2c, DAT_009d4d30, DAT_009d4d34, nullptr);

  if (iVar2 == iVar4)
    return 0;
  return iVar4 - iVar2;
}
