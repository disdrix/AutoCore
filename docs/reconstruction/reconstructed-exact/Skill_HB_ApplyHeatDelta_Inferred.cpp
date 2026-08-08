// =============================================================================
// Skill_HB_ApplyHeatDelta_Inferred  (FUN_00589bc0)
// -----------------------------------------------------------------------------
// Stable ID: aa_00589bc0
// Address:   0x00589bc0–0x00589c69 inclusive (170 B / 0xAA)
// Module:    autoassault.exe (image base 0x400000)
// System:    skills-abilities / Skill HB combat pools
// Generated: 2026-08-05 MEGA-005 dual seal
// Exactness: Behavior-preserving rewrite from sealed assembly (decompiler wrong).
// Bit-for-bit vs retail EXE: DEFERRED.
// Runtime:   not Confirmed (Terminal false; no Launcher).
// =============================================================================

/*
 * Behavioral notes (MEGA-005 sealed):
 * - Skill HB helper: RTTI-resolve target to vehicle combat pools, convert signed
 *   float amount into integer heat delta, optional percent-of-max when |amount|<=1,
 *   apply via Vehicle_AddHeat when netobj+0x7E gate passes.
 * - Amount sign: positive → heat up; negative → cool.
 * - |amount| <= 1.0 → fraction of nMaxHeat (+0x244); else absolute trunc (CVTTSS2SI).
 * - ABI: __cdecl, 3 stack args, bare RET; callers ADD ESP,0xC.
 * - param_1 (source) is pushed by parents but NEVER read in the body.
 * - param_2 (target) is RTTI-cast: CVOGVehicle, else CVOGCreature→vehicle*@+0x250.
 * - Return: actual nCurrentHeat change (+0x150), or 0 if unresolved / gate skip.
 * - Callees: __RTDynamicCast, Vehicle_AddHeat (0x004f7210 thiscall).
 * - Parents: FUN_0061b6f0 (skill[+0x114] heat channel), FUN_00618270, + 3 sites.
 * - Sibling family: ApplyHpDelta 00589c70, ApplyShieldPool 00589d90, …
 * - Name is _Inferred: role sealed by HB parent heat float@+0x114 + Vehicle_AddHeat;
 *   no product demangle string on this VA.
 *
 * DECOMPILER WARNING:
 *   Live Ghidra decompile shows only 2 args and feeds the MI adjustor dword into
 *   Vehicle_AddHeat. That is FALSE. Assembly uses float amount → ECX delta and
 *   percent path against [vehicle+0x244]. Clean body follows assembly.
 */

#include <cstdint>

// Globals (image)
extern "C" float DAT_00aaa668; // -1.0f @ 0x00aaa668
extern "C" float g_flOne;      //  1.0f @ 0x00a0f2a0

// MSVC RTTI dynamic_cast
extern "C" void *__cdecl __RTDynamicCast(
    void *in,
    long vfDelta,
    void *srcType,
    void *targetType,
    int isReference);

// Image RTTI TypeDescriptors (addresses from PUSH immediates)
extern "C" void CVOGClonedObjectBase_RTTI_Type_Descriptor; // 0x00af8e10
extern "C" void CVOGVehicle_RTTI_Type_Descriptor;          // 0x00aff68c
extern "C" void CVOGCreature_RTTI_Type_Descriptor;         // 0x00af8d0c

// Vehicle_AddHeat — thiscall; ECX = vehicle pools; stack int delta
// positive heats, negative cools; clamps [0, 2*MaxHeat]; may dirty HeatMask.
extern "C" void __thiscall Vehicle_AddHeat(void *pVehicle, int nHeatDelta);

// Layout (sealed offsets used by this VA + Vehicle_AddHeat)
//   +0x004  opaque header / MI
//   +0x150  nCurrentHeat
//   +0x244  nMaxHeat
// creature+0x250 → vehicle pools*

// __cdecl
extern "C" int Skill_HB_ApplyHeatDelta_Inferred(
    void *sourceUnused, // [ESP+4]  parents push; body does not read
    void *targetObj,    // [ESP+8]  RTTI cast target
    float amount)       // [ESP+C]  signed heat delta / fraction
{
  (void)sourceUnused;

  void *pVehicle = __RTDynamicCast(
      targetObj,
      0,
      &CVOGClonedObjectBase_RTTI_Type_Descriptor,
      &CVOGVehicle_RTTI_Type_Descriptor,
      0);

  if (pVehicle == nullptr) {
    void *creature = __RTDynamicCast(
        targetObj,
        0,
        &CVOGClonedObjectBase_RTTI_Type_Descriptor,
        &CVOGCreature_RTTI_Type_Descriptor,
        0);
    if (creature == nullptr)
      return 0;
    pVehicle = *reinterpret_cast<void **>(
        reinterpret_cast<std::uint8_t *>(creature) + 0x250);
  }

  if (pVehicle == nullptr)
    return 0;

  auto *base = reinterpret_cast<std::uint8_t *>(pVehicle);

  int delta;
  if (DAT_00aaa668 <= amount && amount <= g_flOne) {
    int maxHeat = *reinterpret_cast<int *>(base + 0x244);
    delta = static_cast<int>(static_cast<float>(maxHeat) * amount); // CVTTSS2SI
  } else {
    delta = static_cast<int>(amount); // CVTTSS2SI
  }

  // net/ghost object at MI-adjusted +0xA8
  auto *hdr = *reinterpret_cast<std::uint8_t **>(base + 4);
  auto off = *reinterpret_cast<std::int32_t *>(hdr + 4);
  void *net = *reinterpret_cast<void **>(base + off + 0xA8);

  int cur = *reinterpret_cast<int *>(base + 0x150);
  if (net != nullptr &&
      *reinterpret_cast<char *>(reinterpret_cast<std::uint8_t *>(net) + 0x7E) != 0) {
    Vehicle_AddHeat(pVehicle, delta);
  }
  int after = *reinterpret_cast<int *>(base + 0x150);
  return after - cur;
}

// Ghidra export alias
extern "C" int FUN_00589bc0(void *a, void *b, float c)
{
  return Skill_HB_ApplyHeatDelta_Inferred(a, b, c);
}
