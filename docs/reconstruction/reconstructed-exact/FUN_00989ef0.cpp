// =============================================================================
// FUN_00989ef0  (clean twin of ResourceCache_SetField10AndConfigure_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00989ef0
// Address:   0x00989ef0–0x00989f58  (autoassault.exe, image base 0x400000)
// Dual:      W31-F 2026-07-29
// Exactness: Behavior-preserving. Not modernization.
// =============================================================================

#include <cstdint>
#include <windows.h>

extern void FUN_00996d70(uint32_t configureFlag /*stack; EAX=subobject*/);

// Retail: EDI=object; ECX=field10; stack arg; RET 4; void
void FUN_00989ef0(void* obj /*EDI*/, uint32_t field10 /*ECX*/,
                  uint32_t configureFlag /*stack*/)
{
  auto* base = static_cast<uint8_t*>(obj);
  auto* cs = reinterpret_cast<LPCRITICAL_SECTION>(base + 0x68);

  if (*(base + 0x80) != 0) {
    EnterCriticalSection(cs);
  }

  *reinterpret_cast<uint32_t*>(base + 0x10) = field10;

  // EAX = base + 0x14
  FUN_00996d70(configureFlag);

  if (*(base + 0x80) != 0) {
    LeaveCriticalSection(cs);
  }
}
