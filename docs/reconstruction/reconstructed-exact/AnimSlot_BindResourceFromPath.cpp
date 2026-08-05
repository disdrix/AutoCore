// =============================================================================
// AnimSlot_BindResourceFromPath
// -----------------------------------------------------------------------------
// Stable ID: aa_0074ee40
// Address:   0x0074ee40  (autoassault.exe, image base 0x400000)
// Body:      0x0074ee40 – 0x0074eea9  (ret 4 both paths)
// System:    client::anim / ND resource bind
// Generated: 2026-07-29 W24-S dual A/B seal (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// Ghidra:    FUN_0074ee40
// =============================================================================
//
// PURPOSE:
//   On a 0x78 AnimSlot (ctor FUN_0074ed90), resolve pathKey through the global
//   ND resource cache, store the resource at +0x70, acquire the inner object at
//   +0x74, extract channels into the slot, run weight/duration init, and return
//   0/1 (resource ready flag) or 0xFFFFFFFF on any failure.
//
// ABI: __thiscall — ECX = AnimSlot*; stack (pathKey); ret 4.
//
// CALLEES:
//   FUN_00449070                  — ND type-descriptor singleton
//   NDResourceCache_LookupOrCreate(DAT_00d1f050, path, type, 0, 0)
//   resource vtbl +4              — ready/validate (char)
//   NDResource_AcquireInnerObject — ECX = resource
//   FUN_00963950                  — channel extract (EAX=slot, arg=inner)
//   FUN_0074eaa0                  — weight/duration init (ESI=slot)
//
// CALLERS (sample): Object_LoadOrReplaceAnimSlot (0x005828b0),
//   CVOGGraphicsBase_LoadNextChildAsset (0x00581e20), FUN_005866d0, …
//
// SEALED: ret 4; +0x70/+0x74 stores; fail=-1; success returns (ready!=0).
// =============================================================================

#include <cstdint>

struct NDResourceVtbl {
  void* m0;
  char(__thiscall* ReadyOrValidate)(void* self);  // +4
};

struct NDResource {
  NDResourceVtbl* vtbl;
  // ...
};

// 0x78-byte anim slot (fields beyond +0x74 not owned by this unit).
struct AnimSlot {
  uint8_t pad0[0x70];
  NDResource* resource_70;  // +0x70
  void* inner_74;           // +0x74
};

extern "C" void* DAT_00d1f050;  // global ND resource cache root

extern "C" void* __cdecl FUN_00449070(void);
extern "C" NDResource* /*__cdecl/custom*/ NDResourceCache_LookupOrCreate(
    void* cache, void* pathKey, void* typeDesc, int a4, int a5);
extern "C" void* __fastcall NDResource_AcquireInnerObject(NDResource* res /*ECX*/);
extern "C" int /*EAX slot*/ FUN_00963950(void* inner);
extern "C" void __fastcall FUN_0074eaa0(AnimSlot* self /*ESI*/);

// Clean plate — control flow matches FUN_0074ee40 raw.
uint32_t __thiscall AnimSlot_BindResourceFromPath(AnimSlot* self, void* pathKey)
{
  void* typeDesc = FUN_00449070();
  NDResource* res = NDResourceCache_LookupOrCreate(
      DAT_00d1f050, pathKey, typeDesc, 0, 0);
  self->resource_70 = res;
  if (res == nullptr) {
    return 0xFFFFFFFFu;
  }

  char ready = res->vtbl->ReadyOrValidate(res);
  void* inner = NDResource_AcquireInnerObject(res);
  self->inner_74 = inner;
  if (inner == nullptr) {
    return 0xFFFFFFFFu;
  }

  // Retail: EAX = self, stack arg = inner; reject on -1.
  if (FUN_00963950(inner) == -1) {
    return 0xFFFFFFFFu;
  }

  FUN_0074eaa0(self);
  return static_cast<uint32_t>(ready != 0);
}

// Ghidra twin symbol kept for xref search.
uint32_t __thiscall FUN_0074ee40(AnimSlot* self, void* pathKey)
{
  return AnimSlot_BindResourceFromPath(self, pathKey);
}
