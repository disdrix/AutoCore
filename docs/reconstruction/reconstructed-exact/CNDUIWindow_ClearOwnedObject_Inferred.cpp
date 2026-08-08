// =============================================================================
// CNDUIWindow_ClearOwnedObject_Inferred  (aa_007a8580)
// -----------------------------------------------------------------------------
// Address:   0x007a8580–0x007a85df inclusive (96 B / 0x60)
// Wave:      WQ9L-E OWN-ONLY dual 2026-08-05
// System:    CNDUIWindow / UI owned-object clear
// Exactness: Behavior-preserving rewrite from decompile + disassemble_function
//            + read_memory. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Virtual clear of the owned/hosted object slot at this+0x298.
//   If slot non-null: release child iface at +0x2B4 with scalar dtor flags=0
//   (no free), invoke vtbl[+0x4C], clear string via vtbl[+0x288](""), and if
//   ownership flag +0xBC set scalar-delete the owned object (flags=1) and clear
//   the flag. Always nulls +0x298 on exit.
//
// ABI:
//   ECX = this. Bare RET (C3). void.
//   Installed at CNDUIWindow primary vtbl PTR_FUN_00a960ac slot +0x44.
//
// PAIR:
//   Set: FUN_007a85e0 (vtbl +0x40) — calls this first, then stores object+flag.
//
// CALLERS:
//   CNDUIWindow_CompleteDtor (0x007b5be0), CNDUIWndBuffered complete (0x0078ca80),
//   many derived UI vtbl DATA installs.
// =============================================================================

#include <cstdint>

extern "C" char DAT_00a1419b; // empty C-string ""

// Clear owned object at +0x298. Does not free this.
extern "C" void __fastcall CNDUIWindow_ClearOwnedObject_Inferred(uint32_t* self)
{
  // ESI=this; EBX=0  (disasm)
  if (self[0xA6] == 0) { // +0x298
    self[0xA6] = 0;
    return;
  }

  // +0x2B4 child/iface: scalar dtor flags=0 (release, no free)
  if (uint32_t* child = reinterpret_cast<uint32_t*>(self[0xAD])) {
    void** cvtbl = *reinterpret_cast<void***>(child);
    reinterpret_cast<void(__thiscall*)(void*, int)>(cvtbl[0])(child, 0);
  }

  // vtbl[+0x4C]
  {
    void** vtbl = *reinterpret_cast<void***>(self);
    reinterpret_cast<void(__thiscall*)(void*)>(vtbl[0x4C / 4])(self);
  }

  // vtbl[+0x288]("")
  {
    void** vtbl = *reinterpret_cast<void***>(self);
    reinterpret_cast<void(__thiscall*)(void*, char*)>(vtbl[0x288 / 4])(
        self, &DAT_00a1419b);
  }

  // +0xBC ownership → scalar-delete owned object
  auto* b = reinterpret_cast<uint8_t*>(self);
  if (b[0xBC] != 0) {
    if (uint32_t* owned = reinterpret_cast<uint32_t*>(self[0xA6])) {
      void** ovtbl = *reinterpret_cast<void***>(owned);
      reinterpret_cast<void(__thiscall*)(void*, int)>(ovtbl[0])(owned, 1);
    }
    self[0xA6] = 0;
    b[0xBC] = 0;
  }

  self[0xA6] = 0;
}

// Ghidra twin name
extern "C" void __fastcall FUN_007a8580(uint32_t* self)
{
  CNDUIWindow_ClearOwnedObject_Inferred(self);
}
