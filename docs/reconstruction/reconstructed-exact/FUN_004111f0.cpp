// =============================================================================
// FUN_004111f0 / MissionRuntimeStateBlob_Init
// -----------------------------------------------------------------------------
// Stable ID: aa_004111f0
// Address:   0x004111f0  (autoassault.exe, image base 0x400000)
// System:    missions-progression (GiveMission path)
// Generated: 2026-07-23 scaffold; refined 2026-07-29 dual A/B
// Exactness: Behavior-preserving rewrite of decompiler control flow + bytes.
//            Not modernization. Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   In-place init of the 0x30-byte mission runtime state blob used by
//   CVOGReaction_GiveMission after operator_new(0x30):
//     - dwords at +0x00 .. +0x28  = 0xFFFFFFFF  (11 dwords)
//     - byte   at +0x2C          = 0
//   Does not allocate, free, or insert into character hashes.
//
// CALLING CONVENTION:
//   ECX = pBlob. Plain RET. EAX at return = pBlob (MOV EAX,ECX at entry;
//   never overwritten). Ghidra often types this as void; sole caller assigns
//   the return value — treat as constructor-style "return this".
//
// SOLE CALLER (this image): CVOGReaction_GiveMission @ call site 0x00532988.
//
// EVIDENCE: Ghidra decompile_function + read_memory body @ 0x004111f0;
//           dual reviews A/B_aa_004111f0_MissionRuntimeStateBlob_Init.md
// =============================================================================

#include <cstdint>

// Human alias: MissionRuntimeStateBlob_Init
std::uint32_t* __fastcall FUN_004111f0(std::uint32_t* pBlob)
{
  // Byte clear first (asm order); product meaning of +0x2C is Tentative.
  *reinterpret_cast<std::uint8_t*>(reinterpret_cast<std::uint8_t*>(pBlob) + 0x2c) = 0;

  pBlob[8]  = 0xffffffffu; // +0x20
  pBlob[9]  = 0xffffffffu; // +0x24
  pBlob[10] = 0xffffffffu; // +0x28

  pBlob[0] = 0xffffffffu;
  pBlob[1] = 0xffffffffu;
  pBlob[2] = 0xffffffffu;
  pBlob[3] = 0xffffffffu;
  pBlob[4] = 0xffffffffu;
  pBlob[5] = 0xffffffffu;
  pBlob[6] = 0xffffffffu;
  pBlob[7] = 0xffffffffu;

  // Bytes +0x2D..+0x2F of the 0x30 allocation are not written here.
  return pBlob; // EAX
}
