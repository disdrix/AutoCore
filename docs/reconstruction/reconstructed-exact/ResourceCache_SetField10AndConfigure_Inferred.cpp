// =============================================================================
// ResourceCache_SetField10AndConfigure_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00989ef0
// Address:   0x00989ef0–0x00989f58  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_00989ef0
// System:    ResourceCache / guarded resource host
// Dual:      W31-F 2026-07-29
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// Retail ABI: EDI = object; ECX = field10; stack 1 formal; RET 4; void.
// Optional CS (flag +0x80 → Enter/Leave +0x68), write +0x10, configure
// subobject at +0x14 via FUN_00996d70. Same lock layout as ResourceCache_LookupByName.
// Name Inferred structural (ResourceCache family).
// =============================================================================

#include <cstdint>
#include <windows.h>

// Nested configure residual (not OWN). Retail: EAX = subobject at obj+0x14.
extern void FUN_00996d70(uint32_t configureFlag /*stack; EAX=subobject*/);

struct ResourceCacheHeader {
  uint32_t _pad00[4];     // +0x00 .. +0x0c
  uint32_t field10;       // +0x10  written from ECX
  // +0x14: subobject for FUN_00996d70
  // +0x68: CRITICAL_SECTION
  // +0x80: char csEnable
};

// Clean signature: object/field explicit (retail: EDI / ECX / stack).
void ResourceCache_SetField10AndConfigure_Inferred(
    ResourceCacheHeader* obj /*EDI*/,
    uint32_t field10 /*ECX*/,
    uint32_t configureFlag /*stack*/)
{
  auto* base = reinterpret_cast<uint8_t*>(obj);
  auto* cs = reinterpret_cast<LPCRITICAL_SECTION>(base + 0x68);
  const bool locked = (*(base + 0x80) != 0);

  if (locked) {
    EnterCriticalSection(cs);
  }

  obj->field10 = field10;

  // EAX = obj + 0x14
  FUN_00996d70(configureFlag);

  if (locked) {
    // Retail re-reads flag at +0x80 before Leave (via [ESI+0x18]).
    if (*(base + 0x80) != 0) {
      LeaveCriticalSection(cs);
    }
  }
}
