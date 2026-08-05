// =============================================================================
// AllocateNewObjectFromCbid
// -----------------------------------------------------------------------------
// Stable ID: aa_004cf120
// Address:   0x004cf120–0x004cf296  (autoassault.exe, image base 0x400000)
// System:    sector-map / object-spawn (client)
// Generated: 2026-07-23 scaffold as FUN_004cf120; **sealed 2026-07-29** dual A/B W18-T
// Exactness: Behavior-preserving. Corrects decompiler traps (unaff_EDI flag,
//            vtbl+8 this arg, EDI host for counters) from read_memory seal.
// Bit-for-bit vs retail EXE: DEFERRED
// Dual:      accept-with-gaps (A+B 2026-07-29)
// Product:   plate "allocatenewobjectfromcbid failed %d" @ 0x00a7f228
// =============================================================================

/*
 * Behavioral notes (2026-07-29 seal):
 * - thiscall: ECX = CVOGSectorMap-like host (fields +0xe4e8, +0xe6e0).
 * - stack: cbid, templateId (-1 = no template); RET 8.
 * - Optional template lookup FUN_00508e20 overrides cbid from template+0x84
 *   and enables post-init template apply (slots +0x90 / +0xa4, etc.).
 * - Factory: CVOGReaction_GiveItemByCbid; init virtual vtbl+8(cbid, host, 1).
 * - Success: flag |= 0x10 at obj+0x17c; bump host 64-bit counter; vtbl+0x218(host);
 *   vtbl+0x2a4(host->resolveCtx@+0xe4e8); return obj*.
 */

#include <cstdint>

struct SectorMapHost {
  // only sealed offsets used by this unit:
  // +0xe4e8 resolve / reaction ctx
  // +0xe6e0 / +0xe6e4 64-bit allocation counter
  std::uint8_t _pad0[0xe4e8];
  void *resolveCtx;              // +0xe4e8
  std::uint8_t _pad1[0xe6e0 - 0xe4ec];
  std::uint32_t allocCounterLo;  // +0xe6e0
  std::uint32_t allocCounterHi;  // +0xe6e4
};

struct TemplateRecord {
  std::uint8_t _pad0[4];
  // +4 region passed to FUN_00516720
  std::uint8_t _pad1[0x80];
  std::int32_t cbid;             // +0x84
  std::uint32_t field_88;        // +0x88
  std::int32_t slots78[5];       // +0x90
  std::int32_t slots54[5];       // +0xa4
};

// Nested callees — not dual-owned by this unit.
extern "C" TemplateRecord *FUN_00508e20(int templateId);
extern "C" void *CVOGReaction_GiveItemByCbid(int cbid /*, trailing 0 in image */);
extern "C" void FUN_007a4480(int a, const char *fmt, ...);
extern "C" void __thiscall FUN_00516720(void *obj, void *templatePlus4);
extern "C" void FUN_00509c70(void *obj, int, int, int, std::uint32_t field88);
extern "C" void __thiscall FUN_00512670(void *obj);
extern "C" void __thiscall FUN_00512160(void *obj, std::uint32_t lo, std::uint32_t hi, int one);

using VInit = int(__thiscall *)(void *self, int cbid, void *host, int one);
using VShort = void(__thiscall *)(void *self, short slot);
using VVoid = void(__thiscall *)(void *self);
using VArg = void(__thiscall *)(void *self, std::uint32_t arg);
using VHost = void(__thiscall *)(void *self, void *host);

extern "C" void *__thiscall AllocateNewObjectFromCbid(
    SectorMapHost *self,
    int cbid,
    int templateId)
{
  TemplateRecord *tmpl = nullptr;
  // Local starts as copy of this; high byte forced to 0, or 1 if template path.
  std::uint32_t packedLocal =
      static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(self)) & 0x00FFFFFFu;

  if (templateId != -1) {
    tmpl = FUN_00508e20(templateId);
    if (tmpl == nullptr) {
      return nullptr;
    }
    cbid = tmpl->cbid;
    packedLocal |= 0x01000000u;
  }

  if (cbid == -1) {
    return nullptr;
  }

  void *obj = CVOGReaction_GiveItemByCbid(cbid);
  if (obj == nullptr) {
    FUN_007a4480(0, "allocatenewobjectfromcbid failed %d", cbid);
    return nullptr;
  }

  auto *vtbl = *reinterpret_cast<std::uint8_t **>(obj);
  auto init = *reinterpret_cast<VInit *>(vtbl + 8);
  int rc = init(obj, cbid, self, 1);
  if (rc < 0) {
    return nullptr;
  }

  if ((packedLocal >> 24) != 0) {
    // Template apply block (flag path).
    FUN_00516720(obj, reinterpret_cast<std::uint8_t *>(tmpl) + 4);
    FUN_00509c70(obj, 0, static_cast<int>(0x80000000u), 0, tmpl->field_88);

    for (int i = 0; i < 5; ++i) {
      if (tmpl->slots78[i] != -1) {
        auto fn = *reinterpret_cast<VShort *>(vtbl + 0x78);
        fn(obj, static_cast<short>(tmpl->slots78[i]));
      }
    }
    for (int i = 0; i < 5; ++i) {
      if (tmpl->slots54[i] != -1) {
        auto fn = *reinterpret_cast<VShort *>(vtbl + 0x54);
        fn(obj, static_cast<short>(tmpl->slots54[i]));
      }
    }
    auto v64 = *reinterpret_cast<VVoid *>(vtbl + 0x64);
    v64(obj);
    auto v9c = *reinterpret_cast<VArg *>(vtbl + 0x9c);
    v9c(obj, packedLocal);
  }

  // obj+0x17c |= 0x10  (piVar2[0x5f] in decompiler)
  *reinterpret_cast<std::uint32_t *>(reinterpret_cast<std::uint8_t *>(obj) + 0x17c) |= 0x10u;

  FUN_00512670(obj);

  std::uint32_t lo = self->allocCounterLo;
  std::uint32_t hi = self->allocCounterHi;
  self->allocCounterHi = hi + static_cast<std::uint32_t>(lo > 0xFFFFFFFEu);
  self->allocCounterLo = lo + 1u;

  FUN_00512160(obj, lo, hi, 1);

  auto v218 = *reinterpret_cast<VHost *>(vtbl + 0x218);
  v218(obj, self);

  auto v2a4 = *reinterpret_cast<VArg *>(vtbl + 0x2a4);
  v2a4(obj, static_cast<std::uint32_t>(
           reinterpret_cast<std::uintptr_t>(self->resolveCtx)));

  return obj;
}
