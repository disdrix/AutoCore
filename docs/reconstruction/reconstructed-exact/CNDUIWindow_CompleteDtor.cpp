// =============================================================================
// CNDUIWindow_CompleteDtor  (aa_007b5be0)
// -----------------------------------------------------------------------------
// Address:   0x007b5be0  (autoassault.exe, image base 0x400000)
// Body:      0x007b5be0–0x007b5dcc inclusive (493 B / 0x1ED)
// Wave:      WQ9K-F OWN-ONLY dual 2026-08-05
// System:    CNDUIWindow / MSVC complete destructor
// Exactness: Behavior-preserving rewrite from decompile + disassemble_function
//            + multi-span read_memory + RTTI COL. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   MSVC complete-object destructor for CNDUIWindow (RTTI .?AVCNDUIWindow@@).
//   Installs primary vtbl PTR_FUN_00a960ac, logs owner-debug when +0x2B0 set,
//   decrements live window counter, releases owned child/strings/buffers,
//   tears nested CS object at +0x1E8, then super-base FUN_00759de0.
//   Does NOT free this.
//
// ABI:
//   ECX = this. SEH LAB_009b325c. Bare RET (C3). void.
//
// STRINGS (debug path):
//   "VOG_DEBUG_STOP"
//   "Deleting an unknown window with an owner!"
//   "Deleting a window with an owner! (filename: %s)"
//
// PEERS:
//   Scalar: FUN_00423e50 (vtbl[0] of PTR_FUN_00a960ac)
//   Ctor:   FUN_007b5dd0 / NDUIWindow_BaseCtor_Inferred (same vtbl)
//   Callers: CNDUIWndBuffered complete, CWndWaypointIcon complete, many UI
// =============================================================================

#include <cstdint>
#include <windows.h>

extern uint32_t PTR_FUN_00a960ac; // CNDUIWindow primary vtbl
extern uint32_t PTR_FUN_00a964b8; // nested intermediate vtbl @ +0x1E8
extern uint32_t PTR_FUN_00a964ac; // nested final vtbl @ +0x1E8
extern int32_t  _DAT_00d17954;    // live window counter

extern "C" void FUN_007a4480(int level, const char* fmt, ...);
extern "C" void __fastcall FUN_007a8580(void* self);
extern "C" void __fastcall FUN_007aec70(void* self);
extern "C" void __fastcall FUN_007aff00(void* self);
extern "C" void __cdecl FUN_00797d70(void* p);
extern "C" void __cdecl operator_delete(void* p);
extern "C" void __cdecl operator_delete__(void* p); // operator delete[]
extern "C" void __fastcall FUN_00424060(void* nested);
extern "C" void __fastcall FUN_00759de0(void* self);

// Complete dtor only — does not free self.
extern "C" void __fastcall CNDUIWindow_CompleteDtor(uint32_t* self)
{
  // SEH: LAB_009b325c; ESI=this; EDI=1; EBX=0
  auto* b = reinterpret_cast<uint8_t*>(self);

  self[0] = reinterpret_cast<uint32_t>(&PTR_FUN_00a960ac); // *this = vtbl
  // EH state = 1

  if (self[0xAC] != 0) { // +0x2B0 owner cookie
    FUN_007a4480(0, "VOG_DEBUG_STOP");
    if (self[0xA1] == 0) { // +0x284 filename
      FUN_007a4480(1, "Deleting an unknown window with an owner!");
    } else {
      FUN_007a4480(1, "Deleting a window with an owner! (filename: %s)",
                   reinterpret_cast<const char*>(self[0xA1]));
    }
  }

  _DAT_00d17954 -= 1;

  if (self[0xAD] != 0 && b[0xBD] != 0) { // +0x2B4 child iface, +0xBD flag
    void* child = reinterpret_cast<void*>(self[0xAD]);
    void** cvtbl = *reinterpret_cast<void***>(child);
    reinterpret_cast<void(__thiscall*)(void*, int)>(cvtbl[0xC / 4])(child, 1);
    self[0xAD] = 0;
    b[0xBD] = 0;
  }

  FUN_007a8580(self);
  FUN_007aec70(self);
  FUN_007aff00(self);

  // +0x28C: release helper then operator_delete
  if (void* p = reinterpret_cast<void*>(self[0xA3])) {
    FUN_00797d70(p);
    operator_delete(p);
  }
  self[0xA3] = 0;

  // +0x2B8 timer/helper
  if (void* p = reinterpret_cast<void*>(self[0xAE])) {
    operator_delete(p);
  }
  self[0xAE] = 0;

  // String/buffer slots via operator delete[]
  auto free_arr = [&](uint32_t idx) {
    if (void* p = reinterpret_cast<void*>(self[idx])) {
      operator_delete__(p);
    }
    self[idx] = 0;
  };
  free_arr(0x9D); // +0x274
  free_arr(0xA0); // +0x280
  free_arr(0x9F); // +0x27C
  free_arr(0x9E); // +0x278
  free_arr(0xA1); // +0x284
  free_arr(0xA2); // +0x288

  // 11× owned ptrs at +0x45C (self[0x117] .. self[0x121])
  for (int i = 0; i < 11; ++i) {
    free_arr(0x117 + i);
  }

  // Nested @ +0x1E8 (self[0x7A]): dual vtbl complete + DeleteCriticalSection
  uint32_t* nested = self + 0x7A;
  nested[0] = reinterpret_cast<uint32_t>(&PTR_FUN_00a964b8);
  FUN_00424060(nested);
  nested[0] = reinterpret_cast<uint32_t>(&PTR_FUN_00a964ac);
  FUN_00424060(nested);
  DeleteCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(self + 0x7B));

  // EH state = -1
  FUN_00759de0(self); // super-base complete
}

// Ghidra twin name
extern "C" void __fastcall FUN_007b5be0(uint32_t* self)
{
  CNDUIWindow_CompleteDtor(self);
}
