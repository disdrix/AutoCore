// =============================================================================
// CVOGEnvironmentReflect_InitBufferedViewChild_Inferred  (was FUN_005b3420)
// -----------------------------------------------------------------------------
// Stable ID: aa_005b3420
// Address:   0x005b3420  (autoassault.exe, image base 0x400000)
// Body:      0x005b3420–0x005b3519 exclusive (249 bytes / 0xF9)
// System:    client / CVOGEnvironmentReflect / gfxBufferedView child
// Generated: 2026-08-04 W37-M dual seal
// Exactness: Behavior-preserving rewrite of decompiler + read_memory CF.
// Bit-for-bit vs retail EXE: DEFERRED
//
// Child RTTI Confirmed: FUN_00968a50 vtbl PTR_FUN_00aa22a8
//   COL@0x00aba3bc → type_info@0x00b025e8 ".?AVgfxBufferedView@@"
// Host RTTI (W32-T): CVOGEnvironmentReflect
// Dual: reviews/A|B_aa_005b3420_CVOGEnvironmentReflect_InitBufferedViewChild_Inferred.md
// =============================================================================

#include <cstdint>

extern void* __cdecl operator_new(std::uint32_t size);

// gfxBufferedView ctor (size 0x198). Product English residual beyond RTTI.
extern void* __fastcall gfxBufferedView_ctor_Inferred(void* self); // FUN_00968a50

// W31-O: GfxView_SetNear_Inferred
extern void __thiscall GfxView_SetNear_Inferred(void* view, std::uint32_t near_bits);

// SetFar-style scalar @ view+0xF4 + dirty flags (product residual).
extern void __thiscall FUN_0075b390(void* view, std::uint32_t far_bits);

// DiffuseTexture / resource bind path (product residual).
extern std::uint32_t __thiscall FUN_0075bf40(void* view, std::uint32_t resource);

// Clear/release path on view (product residual).
extern void __fastcall FUN_0075b450(void* view);

// DAT_00afdf08 live dword = 0xFFFF0000 (texture/resource handle residual).
extern std::uint32_t DAT_00afdf08;

// Sole factory path:
//   PalantirEnv_InitPhases → Reflect ctor → Enable (W33-T)
//     → HostBase_EnsureAuxPtrs + FUN_005b3520 + this
void __fastcall CVOGEnvironmentReflect_InitBufferedViewChild_Inferred(void* self)
{
  std::uint32_t local_pair[2];
  local_pair[0] = 0x100;
  local_pair[1] = 0x100;

  void* mem = operator_new(0x198);
  void* child = mem ? gfxBufferedView_ctor_Inferred(mem) : nullptr;

  *reinterpret_cast<void**>(reinterpret_cast<char*>(self) + 0x158) = child;
  *reinterpret_cast<void**>(reinterpret_cast<char*>(child) + 4) = self;

  GfxView_SetNear_Inferred(child, 0x3f000000u); // 0.5f
  FUN_0075bf40(child, DAT_00afdf08);
  *reinterpret_cast<std::uint32_t*>(reinterpret_cast<char*>(child) + 0x180) = 0;
  FUN_0075b450(child);
  FUN_0075b390(child, 0x47c35000u); // 100000.0f

  *reinterpret_cast<std::uint32_t*>(reinterpret_cast<char*>(child) + 0xec) = 0;
  *(reinterpret_cast<std::uint8_t*>(child) + 0x48) = 1;
  *(reinterpret_cast<std::uint8_t*>(child) + 0xcc) = 1;

  // child->vtbl[0x18/4](&local_pair) — 256x256 bring-up
  auto** vtbl = *reinterpret_cast<void***>(child);
  using Vtbl18 = void(__thiscall*)(void*, void*);
  reinterpret_cast<Vtbl18>(vtbl[6])(child, local_pair);

  *reinterpret_cast<std::uint32_t*>(reinterpret_cast<char*>(child) + 0x108) = 0;
  *(reinterpret_cast<std::uint8_t*>(child) + 0x190) = 1;
}
