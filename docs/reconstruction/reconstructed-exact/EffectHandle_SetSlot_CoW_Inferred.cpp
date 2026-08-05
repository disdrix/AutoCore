// =============================================================================
// EffectHandle_SetSlot_CoW_Inferred  (FUN_00970060)
// -----------------------------------------------------------------------------
// Stable ID: aa_00970060
// Address:   0x00970060–0x009700a8  (autoassault.exe, image base 0x400000)
// Body size: 73 bytes (0x49); pad CC×7; next @ 0x009700b0
// System:    graphics / device-effect parameter slot bind (client)
// Generated: 2026-07-23 scaffold as FUN_00970060; dual A/B seal 2026-08-04 (W38-P)
// Exactness: Behavior-preserving rewrite of decompiler + full-body bytes.
//            Not modernization. Bit-for-bit vs retail: DEFERRED.
// =============================================================================
//
// PURPOSE
//   On an effect handle (ESI):
//     1) CoW / ensure-unique if the binder is shared (FUN_0096fdf0)
//     2) Bind or clear a parameter slot (FUN_007528f0(effect, index, resource))
//     3) If set returned -1 AND CoW ran, optionally rebind handle to parent@+0x18
//        via FUN_00448fc0 (COM-style refcount at binder+4)
//
// ABI (retail)
//   ESI = EffectHandle*   (pointer to slot holding effect object*)
//   stack (slotIndex:int32, resource*:void*)
//   ret 8
//   returns EAX = status from 007528f0 (0 ok, -1 index < 0)
//
// CALLERS (8 funcs / 11 sites)
//   GfxView_SetDiffuseColor_ClearDiffuseTex_Inferred (0x0075bf40) — clear DiffuseTexture
//   FUN_00970140 (name→index wrapper), FUN_007a2580, FUN_009521c0,
//   FUN_00988860 / FUN_009887a0, FUN_0073cb70 / FUN_0073cd70
//
// UNOwned callees
//   FUN_0096fdf0  EffectHandle_EnsureUnique_CoW (context)
//   FUN_007528f0  Effect_SetParamSlot
//   FUN_00448fc0  RcBinder_Assign (rc@+4)
//

#include <cstdint>

// Callee stand-ins (not owned by W38-P)
extern "C" int8_t __fastcall FUN_0096fdf0(void* handle /*ECX*/);
extern "C" int32_t __thiscall FUN_007528f0(void* effect /*ECX*/, int32_t slotIndex, void* resource);
extern "C" void __thiscall FUN_00448fc0(void* handle /*ECX*/, void* newBinder /*stack*/);

// ESI-this: callers set ESI = &effect_field before the call.
int32_t EffectHandle_SetSlot_CoW_Inferred(void* handle /*ESI*/,
                                          int32_t slotIndex,
                                          void* resource)
{
  const int8_t cowed = FUN_0096fdf0(handle);

  void* effect = *reinterpret_cast<void**>(handle);
  const int32_t status = FUN_007528f0(effect, slotIndex, resource);

  if (status == -1 && cowed != 0) {
    void* obj = *reinterpret_cast<void**>(handle);
    if (obj != nullptr) {
      void* parent = *reinterpret_cast<void**>(reinterpret_cast<char*>(obj) + 0x18);
      if (parent == nullptr) {
        parent = obj;
      }
      if (parent != obj) {
        FUN_00448fc0(handle, parent);
      }
    }
  }
  return status;
}

// Legacy Ghidra name — see FUN_00970060.cpp
// int FUN_00970060(undefined4, undefined4); // understates ESI this
