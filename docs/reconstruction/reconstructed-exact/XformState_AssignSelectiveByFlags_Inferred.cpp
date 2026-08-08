// =============================================================================
// XformState_AssignSelectiveByFlags_Inferred  (aa_00416160)
// -----------------------------------------------------------------------------
// Address:   0x00416160 – 0x00416239 inclusive (218 B / 0xDA)
//            autoassault.exe, image base 0x400000
// Wave:      WQ9I-G OWN-ONLY dual 2026-08-05
// Exactness: Behavior-preserving rewrite from live decompile + full-body
//            read_memory + disassemble_function. Selective transform-state
//            assign: always-copy mid payload; flag-gated matrix/tail blocks;
//            bump dest generation at +0xB4.
// Bit-for-bit vs retail EXE: DEFERRED.
// ABI:       __thiscall ECX=dest, stack src*; RET 4
// =============================================================================

#include <cstdint>
#include <cstring>

// Fixed-layout transform / matrix state (≥ 0xC0). Product English open.
struct XformState_Inferred {
  uint32_t matrix0[16];   // +0x00 — skip if flags bit0
  uint32_t matrix1[16];   // +0x40 — skip if flags bit1
  uint32_t mid[10];       // +0x80 — always (0x28 bytes)
  uint32_t tail[3];       // +0xA8 — skip if flags bit2
  uint32_t generation;    // +0xB4 — dest++ on every assign
  uint8_t  flagByte;      // +0xB8 — always
  uint8_t  _pad[3];
  uint32_t skipFlags;     // +0xBC — from src; bit set = skip block
};

// thiscall: ECX = dest, [esp+4] = src. ret 4. Leaf.
extern "C" void __thiscall XformState_AssignSelectiveByFlags_Inferred(
    XformState_Inferred* dest,
    const XformState_Inferred* src)
{
  // Always-copy mid @+0x80..+0xA7 (10 dwords) — matches dword stores in body.
  std::memcpy(dest->mid, src->mid, sizeof(dest->mid));

  dest->flagByte = src->flagByte;
  uint32_t flags = src->skipFlags;
  dest->skipFlags = flags;

  if ((flags & 1u) == 0u) {
    std::memcpy(dest->matrix0, src->matrix0, sizeof(dest->matrix0)); // rep movsd ×16
  }
  if (((flags >> 1) & 1u) == 0u) {
    std::memcpy(dest->matrix1, src->matrix1, sizeof(dest->matrix1));
  }
  if (((flags >> 2) & 1u) == 0u) {
    dest->tail[0] = src->tail[0];
    dest->tail[1] = src->tail[1];
    dest->tail[2] = src->tail[2];
  }

  dest->generation = dest->generation + 1u;
}

// Scaffold / Ghidra alias
extern "C" void __thiscall FUN_00416160(
    XformState_Inferred* dest,
    const XformState_Inferred* src)
{
  XformState_AssignSelectiveByFlags_Inferred(dest, src);
}

// Related (not OWN): FUN_00416240 zeros skipFlags then calls this (full assign).
