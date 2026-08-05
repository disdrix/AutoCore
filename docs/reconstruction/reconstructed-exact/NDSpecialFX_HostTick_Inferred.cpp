// =============================================================================
// NDSpecialFX_HostTick_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004b8ed0
// Address:   0x004b8ed0 – 0x004b9240  (autoassault.exe, image base 0x400000)
// System:    client-fx / NDSpecialFX lifecycle
// Generated: 2026-07-29 W24-C dual seal (decompile + read_memory)
// Exactness: Behavior-preserving CF reconstruction. Twin FUN_004b8ed0.cpp is the
//            line-faithful decompiler mirror (includes operator_delete residual edges).
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Host tick for an NDSpecialFX session:
//     - rate / event-type gate (5s stamp at +0xd0; switch on +0x28)
//     - liveness probe FUN_004b7330 → else DeactivateClear + return 1
//     - update param-map transforms; cull by camera distance
//     - walk owned CVOG children: Tick live ones; free destroy-pending ("Destroy")
//     - maintain residual lists +0x1e0 / +0x210 / +0x21c
//     - optional host notify FUN_004b6910; return 0 while live
//
// ABI:
//   __thiscall (ECX = fx host); 1 stack arg (ctx*); ret 4 (C2 04 00).
//   Return: 0 = still active, 1 = deactivated this call.
//
// RELATED (sealed peers):
//   FUN_004b7150 = NDSpecialFX_DeactivateClear_Inferred (W23-H)
//   FUN_004b75d0 = NDSpecialFX_UpdateParamMapTransforms_Inferred
//   FUN_00595230 = CVOGObject_Tick (W23-H)
// =============================================================================

#include <cstdint>

extern "C" {
uint8_t __fastcall FUN_004b7330(void* fx);
void __thiscall FUN_004b75d0(void* fx);
void __thiscall FUN_004b7150(void* fx); // NDSpecialFX_DeactivateClear_Inferred
void __thiscall FUN_004b6910(void* fx);
uint8_t __thiscall FUN_004b6a80(void* fx);
void __thiscall FUN_00595230(void* obj, void* ctx, float clock);
float FUN_0079a110(void);
uint8_t FUN_0058e1a0(void* a, uint32_t b);
void FUN_0076cf00(const char* name);
void FUN_0076cef0(void);
void FUN_00590c20(void* obj);
void FUN_005be2f0(void* obj);
uint8_t FUN_005bc3c0(void* a, void* b, int cam);
void FUN_005be310(void* p);
void FUN_005bb5e0(void* a, void* b);
uint8_t FUN_005ba440(void* ctx);
void FUN_005b85e0(void);
uint8_t FUN_00498a50(void* ctx);
void FUN_00498ab0(int z);
void operator_delete(void* p);

extern uint32_t g_dwClientTickMs;
extern int DAT_00d17958;
extern int DAT_00b04c70;
extern char DAT_00b03e64;
extern float DAT_009cb2b0;
extern float g_flZero;
}

// Contract sketch (happy path). Residual list-delete noreturn edges:
// see FUN_004b8ed0.cpp for decompiler-faithful residual.
//
// uint8_t NDSpecialFX_HostTick_Inferred(void* fx, void** ctx) {
//   counter(DAT_00d17958+0x154)++;
//   uint32_t now = g_dwClientTickMs;
//   bool active;
//   if (now - stamp(fx+0xd0) < 0x1389) active = true;
//   else switch (type(fx+0x28)) {
//     case 4: if (FUN_004b6a80()) active = true; else active = false; break;
//     case 2,3,5,6,0xC,0xD,0xE,0x13,0x14,0x15,0x17: active = false; break;
//     default: active = true; break;
//   }
//   if (!active) { DeactivateClear(fx); return 1; }
//   stamp = now;
//   if (FUN_004b7330(fx)) { DeactivateClear(fx); return 1; }
//   UpdateParamMapTransforms(fx);
//   if (cull_ok) {
//     for child in list(+0x204):
//       if destroy_pending: profile("Destroy"); unlink; free child; else Tick(child);
//     ... residual lists ...
//     FUN_004b6910(fx);
//   }
//   return 0;
// }

// Prefer linking against the decompiler mirror for bit-level residual CF:
//   docs/reconstruction/reconstructed-exact/FUN_004b8ed0.cpp
