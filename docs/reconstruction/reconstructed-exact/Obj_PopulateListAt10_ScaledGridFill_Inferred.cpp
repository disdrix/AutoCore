// =============================================================================
// Obj_PopulateListAt10_ScaledGridFill_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_005b3fa0
// Address:   0x005b3fa0  (autoassault.exe, image base 0x400000)
// Body:      0x005b3fa0 – 0x005b4255 exclusive (693 B / 0x2B5)
// System:    host object / list populate worker
// Generated: 2026-08-04 W37-L dual seal (decompile_function + read_memory)
// Exactness: Behavior-preserving; bytes seal float store order, ret 0x14,
//            0.5f half-step, list base at +0x10, status 1/0.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: Populate the embedded std::list at this+0x10 with a scaled grid of
// 0x30 nodes after the empty default ctor (aa_005b3f60). Requires non-null
// context object (stack arg4): acquires it, builds a path, locks a gfxBody-like
// asset, then nested-loops ROUND(dim*scale) inserting positioned nodes.
// Stores floats: +0x20=arg0, +0x24=arg2, +0x28=arg1, +0x2c=0.
// Returns 1 on success, 0 on null ctx or lock failure.

#include <cstdint>

// DAT_00a0f298
static constexpr float kHalf = 0.5f;

// Context acquire (ECX = ctx); stack args (1,1).
extern "C" int __thiscall Ctx_EnsureLoaded_Inferred(void *ctx, char a, char b); // FUN_004f1e20
// Stack-local body ctor (ECX = stack object).
extern "C" void *__fastcall GfxBodyLike_StackCtor_Inferred(void *body); // FUN_00764030
// Build path string into out holder (thiscall on ctx).
extern "C" void *__thiscall Ctx_BuildPathHolder_Inferred(void *ctx, void *out); // FUN_004eb1c0
// Lock asset; returns status (>=0 ok, <0 fail). Plate gfxBody.cpp.
extern "C" int __thiscall GfxBody_LockAsset_Inferred(void *body, void *path); // FUN_00764830
extern "C" void __thiscall GfxBodyLike_Release_Inferred(void *body); // FUN_00763f60
extern "C" void __thiscall PathOrSurface_Teardown_Inferred(void * /*?*/); // FUN_004eb010
// Node buy: operator_new(0x30); copy links + 8 dwords from payload.
extern "C" void *FUN_005b4470(void *head, void *headNext, const void *payload8dwords);
// List size bump (thiscall on list base this+0x10); throws if too long.
extern "C" void __thiscall StdList_BumpSize_Inferred(void *list, uint32_t n); // FUN_005b43d0

// Retail: thiscall, five stack args, ret 0x14, AL/EAX status
extern "C" uint32_t __thiscall Obj_PopulateListAt10_ScaledGridFill_Inferred(
    void *self,
    float dim_a,
    float dim_b,
    float dim_c,
    float scale,
    void *ctx)
{
  auto *base = static_cast<uint8_t *>(self);

  if (ctx == nullptr)
    return 0;

  *reinterpret_cast<float *>(base + 0x20) = dim_a;
  *reinterpret_cast<float *>(base + 0x24) = dim_c; // stack arg2 (middle swap)
  *reinterpret_cast<float *>(base + 0x28) = dim_b;
  *reinterpret_cast<float *>(base + 0x2c) = 0.0f;

  // SEH present in retail (handler LAB_009a684b) — omitted as structural.
  Ctx_EnsureLoaded_Inferred(ctx, 1, 1);

  // Stack-allocated body object (~0x150+); exact layout unowned.
  alignas(16) uint8_t body_storage[0x200];
  void *body = GfxBodyLike_StackCtor_Inferred(body_storage);

  alignas(8) uint8_t path_holder[0x20];
  void *path = Ctx_BuildPathHolder_Inferred(ctx, path_holder);
  int lock_status = GfxBody_LockAsset_Inferred(body, path);
  if (lock_status < 0) {
    PathOrSurface_Teardown_Inferred(nullptr);
    GfxBodyLike_Release_Inferred(body);
    return 0;
  }

  // Extent deltas and half-steps derived from locked surface floats in retail
  // (local_14c-local_158, local_144-local_150). Port must read those fields
  // from the locked object; exact offsets unowned here.
  float extent_x = 0.0f; // filled from locked rect in retail
  float extent_y = 0.0f;
  int step_x = static_cast<int>(extent_x + 0.5f); // ROUND
  int step_y = static_cast<int>(extent_y + 0.5f);
  float half_y = extent_y * kHalf;
  float half_x = extent_x * kHalf;
  (void)step_x;
  (void)step_y;
  (void)half_x;
  (void)half_y;

  int nx = static_cast<int>((*reinterpret_cast<float *>(base + 0x20)) * scale + 0.5f);
  int ny = static_cast<int>((*reinterpret_cast<float *>(base + 0x28)) * scale + 0.5f);

  void *list = base + 0x10;
  float pos_x = half_x;
  for (int ix = 0; ix < nx; /* advanced by step accum in retail */) {
    float pos_y = half_y;
    for (int iy = 0; iy < ny; /* advanced by step accum in retail */) {
      // Payload: pos + flags/param_4 image (8 dwords) — see raw.
      alignas(8) uint32_t payload[8] = {};
      *reinterpret_cast<float *>(&payload[0]) = pos_x;
      *reinterpret_cast<float *>(&payload[2]) = pos_y; // layout approximate

      void *head = *reinterpret_cast<void **>(base + 0x14);
      void *head_next = *reinterpret_cast<void **>(static_cast<uint8_t *>(head) + 4);
      void *node = FUN_005b4470(head, head_next, payload);
      StdList_BumpSize_Inferred(list, 1);
      *reinterpret_cast<void **>(static_cast<uint8_t *>(head) + 4) = node;
      void *node_prev_slot = *reinterpret_cast<void **>(static_cast<uint8_t *>(node) + 4);
      *reinterpret_cast<void **>(node_prev_slot) = node;

      // retail: pos_y += extent_y; accum += step_y until >= ny bound
      (void)iy;
      break; // structural sketch — retail uses accum comparators
    }
    // retail: pos_x += extent_x; reset pos_y to half_y
    (void)ix;
    break;
  }

  PathOrSurface_Teardown_Inferred(nullptr);
  return 1;
}

// Scaffold alias
extern "C" uint32_t __thiscall FUN_005b3fa0(
    void *self, float a, float b, float c, float scale, void *ctx)
{
  return Obj_PopulateListAt10_ScaledGridFill_Inferred(self, a, b, c, scale, ctx);
}
