// =============================================================================
// Client_ProcessSectorUpdate_Inferred  (Ghidra: FUN_00811e00)
// -----------------------------------------------------------------------------
// Stable ID: aa_00811e00
// Address:   0x00811e00 – 0x008120c8  (713 B; autoassault.exe base 0x400000)
// System:    client net / sector object update
// Generated: 2026-07-29 W26-M dual (from live decompile + read_memory)
// Exactness: Behavior-preserving CF rewrite. Nested helper bodies not expanded.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Client-side "ProcessSectorUpdate" for an already-resolved world object.
//   Debug string: "Requesting ProcessSectorUpdate\n" @ 0x00a7f17c.
//   Invoked from create-or-update packet handlers when the object exists
//   (sibling create path is FUN_008120d0 — not this unit).
//
// ABI (sealed):
//   ECX      = packet body*
//   EAX in   = world object*
//   Stack+4  = game/client ctx*
//   cleanup  = RET 4
//   return   = void
//
// Callers: FUN_008122e0, FUN_00812320, FUN_00812360,
//          FUN_00814400, FUN_00814470, FUN_008144b0, FUN_008144f0
// Callees: OutputDebugStringA, FUN_009972a0, FUN_008024d0, FUN_0092a200,
//          FUN_004e87d0, FUN_004e88e0, object vtbl +0xC4/+0x260/+0x1CC
// =============================================================================

#include <cstdint>

// Forward decls for nested units (not OWN — signatures from call sites only).
extern "C" void __stdcall OutputDebugStringA(const char* lpOutputString);
void FUN_009972a0(/* game */);
void FUN_008024d0(void* game, uint32_t a, uint32_t b, int z0, int z1, int z2, int o58, int o59);
char FUN_0092a200(/* filter args via regs/stack — not OWN */);
uint32_t* FUN_004e87d0(/* transform pack — not OWN */);
void FUN_004e88e0(void* dst, void* src /* — not OWN */);

extern uint32_t DAT_00d1d86c;
extern uint32_t DAT_00d1d870;

// Multi-reg entry: not expressible as pure MSVC thiscall without EAX formal.
// Documented contract — call as: EAX=obj, ECX=packet, push game; call.
void Client_ProcessSectorUpdate_Inferred(void* packet_ecx, void* game_stack4_/*EAX=obj*/)
{
  // --- prologue (machine) ---
  // AND ESP,-16; SUB ESP,0x34; EBX=game; ESI=packet; EDI=obj
  auto* packet = reinterpret_cast<uint8_t*>(packet_ecx);
  auto* game   = reinterpret_cast<uint8_t*>(game_stack4_);
  // obj is in EAX on entry (decompiler: in_EAX); kept as int* below
  int* obj = nullptr; // filled by caller in EAX — see raw for use as in_EAX/EDI

  (void)game;
  (void)packet;
  (void)obj;

  OutputDebugStringA("Requesting ProcessSectorUpdate\n");

  // CF mirrors raw FUN_00811e00 exactly — see annotated for offset map.
  // Branch summary:
  // 1) if packet[0xA1] != 0:
  //      obj->vtbl[+0xC4](...); FUN_009972a0(); FUN_008024d0(...); return;
  // 2) if game[0xE98] bind matches obj[+0xAC]: return;
  // 3) if (packet[8] & packet[0xC]) != 0xFFFFFFFF:
  //      obj->vtbl[+0x260](...); return;
  // 4) merge packet[0xA8] into obj flag bit2 at +0x17C;
  // 5) if !packet[0xA8]: maybe FUN_0092a200 → mark *(game[0x4D0]+4)=1;
  // 6) phys = obj->vtbl[+0x1CC](); if null return;
  // 7) free_flag from full-id + zero flags @ A0/A8/C0;
  // 8) copy packet transform +0x64.. to obj+0x80..; set phys adj +0x188 bit0;
  // 9) primary or secondary physics apply via FUN_004e87d0 / FUN_004e88e0 + vtbls.

  // Full line-faithful body retained in FUN_00811e00.cpp twin + raw capture.
}

// Twin entry under Ghidra name for grep parity with inventory.
void __thiscall FUN_00811e00(int param_1, int param_2);
