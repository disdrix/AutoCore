// =============================================================================
// MedalUI_PrepClearButtonSlots_Inferred  (aa_0090c700)
// -----------------------------------------------------------------------------
// Address:   0x0090c700–0x0090c74c inclusive (77 B / 0x4D)
// Wave:      MEGA-102 OWN-ONLY dual 2026-08-05
// System:    missions-progression / Medal UI prep
// Exactness: Behavior-preserving rewrite from decompile + disassemble_function
//            + read_memory + caller context. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Prep step for medal / achievement button grid rebuild: walk the 24 widget
//   slots at host+0x540. For each non-null slot, optionally detach via host
//   vtbl[+0xb0] when host vtbl[+0x3d8] reports active/visible, then scalar-
//   delete the widget (flags=1) and null the slot.
//
// ABI:
//   EDI = medal UI host. No stack formals. void. Bare RET (C3).
//   Caller FUN_0090cbc0 seeds EDI from ESI immediately before CALL.
//
// CALLERS:
//   FUN_0090cbc0 @ 0x0090cbef (sole UNCONDITIONAL_CALL).
//
// RETIRED SCAFFOLD:
//   Named_CalleeOf_Named_VOG_DEBUG_STOP_0090c700 (parent logs VOG_DEBUG_STOP
//   on hash traversal; this unit has no strings).
// =============================================================================

#include <cstdint>

// Host layout fragments used here (not a full class def):
//   +0x000  vtbl*
//   +0x540  buttonSlots[24]  // dword* widgets; XML peer: i_d_a_2d_btn_achievement.xml

using VFunc0_RetChar = char(__thiscall*)(void* self);
using VFunc1_Ptr     = void(__thiscall*)(void* self, void* child);
using ScalarDtor     = void(__thiscall*)(void* self, int flags);

// EDI-this custom convention (not MSVC thiscall ECX).
extern "C" void MedalUI_PrepClearButtonSlots_Inferred(void /* EDI = host */)
{
  // Disasm: PUSH EBX; PUSH ESI; LEA ESI,[EDI+0x540]; MOV EBX,0x18
  void* host;
  uint32_t* slot;
  int remaining;

#if defined(_MSC_VER) && defined(_M_IX86)
  __asm {
    mov host, edi
  }
#else
  // Non-MSVC rebuilds must pass host explicitly; retail ABI is EDI.
  host = nullptr;
#endif

  slot = reinterpret_cast<uint32_t*>(
      reinterpret_cast<uint8_t*>(host) + 0x540);
  remaining = 0x18;

  do {
    if (*slot != 0) {
      void** hostVtbl = *reinterpret_cast<void***>(host);

      // CALL [vtbl+0x3d8]; TEST AL,AL
      char active = reinterpret_cast<VFunc0_RetChar>(hostVtbl[0x3d8 / 4])(host);
      if (active != 0) {
        // PUSH slot; CALL [vtbl+0xb0]
        reinterpret_cast<VFunc1_Ptr>(hostVtbl[0xb0 / 4])(
            host, reinterpret_cast<void*>(*slot));
      }

      // Re-load slot; may still be non-null after detach
      if (*slot != 0) {
        void* widget = reinterpret_cast<void*>(*slot);
        void** wVtbl = *reinterpret_cast<void***>(widget);
        // PUSH 1; CALL [vtbl+0]  — scalar deleting destructor
        reinterpret_cast<ScalarDtor>(wVtbl[0])(widget, 1);
      }

      *slot = 0;
    }

    slot += 1;       // ADD ESI,4
    remaining -= 1;  // SUB EBX,1
  } while (remaining != 0);
}

// Ghidra twin name
extern "C" void FUN_0090c700(void)
{
  MedalUI_PrepClearButtonSlots_Inferred();
}
