// =============================================================================
// AssManager_ResolverA_Ctor_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00423be0
// Address:   0x00423be0–0x00423c35  (autoassault.exe, image base 0x400000)
// System:    assets / assManager / resolver A
// Generated: 2026-07-23 scaffold as FUN_00423be0; dual A/B seal 2026-07-29 (W31-G)
// Exactness: Behavior-preserving rewrite of decompiler + full-body bytes.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE:
//   Placement constructor for AssManager **resolver A** object (alloc size 0x4c).
//   Installs vtbl PTR_FUN_00a95acc, constructs nested member at +0x08, initializes
//   CRITICAL_SECTION at +0x30, sets ready flag at +0x48.
//
// ABI (bytes):
//   stdcall 1 formal (self*); RET 4; returns self in EAX.
//   Body 86 B; SEH LAB_009bd3c8.
//
// CALLER:
//   AssManager_InitPrecompileAndResolvers (0x007b75b0) flag bit0:
//     new(0x4c) → this → store self+0x08 → GuardedVector_PushBackLocked on host+0x58
//

#include <cstdint>
#include <windows.h>

// Nested member ctor (unowned) — twin shape of FUN_00469db0
extern "C" void* FUN_00423cf0(void* member /* stack */);

// Retail IAT: InitializeCriticalSection

struct AssResolverA {
  void* vtbl;                 // +0x00  PTR_FUN_00a95acc
  uint32_t pad04;             // +0x04  set 0
  uint8_t member_at_08[0x28]; // +0x08  FUN_00423cf0 span to +0x30
  CRITICAL_SECTION cs;        // +0x30  (0x18)
  uint8_t ready;              // +0x48  set 1
  // pad to 0x4c
};

// Retail: stack(self*); RET 4; return self
extern "C" AssResolverA* AssManager_ResolverA_Ctor_Inferred(AssResolverA* self /*stack*/)
{
  // SEH frame LAB_009bd3c8; EH state = 0 after pad04 clear
  self->pad04 = 0;
  self->vtbl = reinterpret_cast<void*>(0x00a95acc); // PTR_FUN_00a95acc
  FUN_00423cf0(&self->member_at_08);
  InitializeCriticalSection(&self->cs);
  self->ready = 1;
  return self;
}

// Ghidra twin symbol
extern "C" AssResolverA* FUN_00423be0(AssResolverA* self)
{
  return AssManager_ResolverA_Ctor_Inferred(self);
}
