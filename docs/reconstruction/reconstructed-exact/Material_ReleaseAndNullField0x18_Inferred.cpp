// =============================================================================
// Material_ReleaseAndNullField0x18_Inferred  (Ghidra: FUN_0096f660)
// -----------------------------------------------------------------------------
// Stable ID: aa_0096f660
// Address:   0x0096f660 – 0x0096f681  (34 B; autoassault.exe base 0x400000)
// System:    gfx / material resource
// Generated: 2026-07-29 W26-M dual (live decompile + full-body read_memory)
// Exactness: Byte-faithful CF. No modernization.
// Bit-for-bit vs retail EXE: DEFERRED (body hex sealed in raw/review).
// =============================================================================
//
// PURPOSE:
//   Given holder ECX (int* whose first dword is a material/gfx object*):
//     resource = object+0x18
//     if resource: refcount at resource+4 --; if 0 call resource->vtbl[+8]
//     object+0x18 = 0  (always when object non-null)
//
// Callers (2): FUN_0051aed0, FUN_005dbca0 — after MatAmbient/Diffuse/Emissive sets.
// =============================================================================

#include <cstdint>

void __fastcall Material_ReleaseAndNullField0x18_Inferred(int* holder)
{
  int* obj = reinterpret_cast<int*>(*holder);
  if (obj == nullptr) {
    return;
  }

  int* resource = *reinterpret_cast<int**>(reinterpret_cast<uint8_t*>(obj) + 0x18);
  if (resource != nullptr) {
    int* refcount = resource + 1; // resource+4
    *refcount = *refcount - 1;
    if (*refcount == 0) {
      // vtbl[+8] — Release/Destroy (product name open)
      auto** vtbl = reinterpret_cast<void***>(resource);
      auto fn = reinterpret_cast<void(__fastcall*)(int*)>((*vtbl)[2]);
      fn(resource);
    }
  }

  *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(obj) + 0x18) = 0;
}
