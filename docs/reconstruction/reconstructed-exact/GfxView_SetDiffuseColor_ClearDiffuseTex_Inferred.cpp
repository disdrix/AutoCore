// =============================================================================
// GfxView_SetDiffuseColor_ClearDiffuseTex_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0075bf40
// Address:   0x0075bf40  (autoassault.exe, image base 0x400000)
// Body:      0x0075bf40 – 0x0075bf95 exclusive (85 B / 0x55)
// System:    GfxView / material color worker
// Generated: 2026-08-04 W37-L dual seal (decompile_function + read_memory)
// Exactness: Behavior-preserving; bytes seal ret 4, offsets, string, return 0.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: On a GfxView-like object, optionally resolve the effect parameter
// named "DiffuseTexture" and clear its bind (FUN_00970060(index, 0)), then
// store a packed color at this+0x148 and set dirty flag this+0x129 = 1.
// Always returns 0. Call sites pass 0x808080 (init gray) or 0.

#include <cstdint>

// thiscall on effect object at *(view+0x134); writes *out_index (-1 if miss).
extern "C" void __thiscall Effect_FindParamIndexByName_Inferred(
    void *effect, int *out_index, const char *name); // FUN_00752370

// Clear/release texture bind for param index; uses ESI = view+0x134 in retail.
extern "C" int FUN_00970060(int param_index, int slot_or_flags);

// Retail: thiscall, one stack arg, ret 4, always EAX=0
extern "C" int __thiscall GfxView_SetDiffuseColor_ClearDiffuseTex_Inferred(
    void *self, uint32_t color)
{
  auto *base = static_cast<uint8_t *>(self);
  int index = -1;
  void *effect = *reinterpret_cast<void **>(base + 0x134);

  if (effect != nullptr) {
    Effect_FindParamIndexByName_Inferred(effect, &index, "DiffuseTexture");
  }

  if (index >= 0) {
    FUN_00970060(index, 0);
  }

  *reinterpret_cast<uint32_t *>(base + 0x148) = color;
  base[0x129] = 1;
  return 0;
}

// Scaffold alias
extern "C" int __thiscall FUN_0075bf40(void *self, uint32_t color)
{
  return GfxView_SetDiffuseColor_ClearDiffuseTex_Inferred(self, color);
}
