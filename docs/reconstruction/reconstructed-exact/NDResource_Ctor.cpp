// =============================================================================
// NDResource_Ctor
// -----------------------------------------------------------------------------
// Stable ID: aa_00745d70
// Address:   0x00745d70–0x00745dec  (autoassault.exe, image base 0x400000)
// System:    ndresource / ND resource object base
// Generated: 2026-07-23 scaffold as FUN_00745d70; **sealed 2026-07-29** dual A/B W19-R
// Exactness: Behavior-preserving. Decompiler shows __fastcall with phantom param_1;
//            image uses EDX=typeToken, 3 stack args, RET 0xC, returns this.
// Bit-for-bit vs retail EXE: DEFERRED
// Dual:      accept-with-gaps (A+B 2026-07-29)
// =============================================================================

/*
 * Behavioral notes (2026-07-29 seal):
 * - Construct a 0x3c-byte NDResource-family object in-place.
 * - Install base vtbl PTR_FUN_00aa1d40; many callers immediately overwrite with
 *   PTR_FUN_00a9e850 (default resource) after return.
 * - Copy name key dword, store type token from EDX, zero slots, sentinel -1,
 *   InitializeCriticalSection at +0x20, set ready byte at +0x38 = 1.
 * - If optionalSrc != null, this+0x14 = optionalSrc->vtbl[+4]().
 * - Sibling dtor FUN_00745ff0 (not owned) tears down same layout.
 */

#include <cstdint>
#include <windows.h>

// Image vtbl symbols (addresses in autoassault.exe).
extern "C" void *PTR_FUN_00aa1d40;

// aa_00745d70
// EDX = typeToken; stack this, nameKey*, optionalSrc*; RET 0xC; returns this.
extern "C" void * __fastcall NDResource_Ctor(
    void * /*ecx_unused*/,
    std::uint32_t typeToken,
    void *self,
    std::uint32_t *nameKey,
    void *optionalSrc)
{
  auto *obj = reinterpret_cast<std::uint32_t *>(self);

  // SEH frame omitted (LAB_009ab7f8) — same side effects as image EH.

  obj[0] = reinterpret_cast<std::uint32_t>(&PTR_FUN_00aa1d40); // +0x00 vtbl
  obj[1] = *nameKey;                                           // +0x04
  obj[2] = 0;                                                  // +0x08
  obj[3] = typeToken;                                          // +0x0c EDX
  obj[4] = 0;                                                  // +0x10
  obj[5] = 0;                                                  // +0x14 payload
  obj[6] = 0xffffffffu;                                        // +0x18

  InitializeCriticalSection(
      reinterpret_cast<LPCRITICAL_SECTION>(obj + 8));          // +0x20
  *reinterpret_cast<std::uint8_t *>(obj + 0xe) = 1;            // +0x38

  if (optionalSrc != nullptr) {
    auto **vtbl = *reinterpret_cast<void ***>(optionalSrc);
    using VFn = std::uint32_t(__thiscall *)(void *);
    auto fn = reinterpret_cast<VFn>(vtbl[1]); // +4
    obj[5] = fn(optionalSrc);
  }

  return self;
}
