// =============================================================================
// Anm_KestChunk_ReadF32Array_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0045dd60
// Address:   0x0045dd60–0x0045de07 inclusive (168 B / 0xA8); pad CC
// Module:    autoassault.exe (image base 0x400000)
// Ghidra:    FUN_0045dd60
// System:    sto-chunk / animation track-master element load
// Dual:      2026-08-04 W37-P OWN-ONLY
// =============================================================================
//
// Retail ABI (bytes):
//   ECX     = elem_count
//   EDI     = stoChunkReader*   (register formal; parent loads EDI before CALL)
//   stack   = float* dest
//   bare RET; caller ADD ESP,4
//   returns readF32Array status, or 0xFFFFFFFF on wrong tag
//
// Portable reconstruction below surfaces reader as an explicit argument for
// documentation; retail keeps it in EDI (not a stack formal).
//
// CF:
//   EnterChunkScope → require tag KEST (0x4B455354) →
//   readF32Array(dest, reader, elem_count * 7) → Leave if ok.
//   7 f32 == one Pod28 element (matches parent vector stride 0x1c).
//
// Sole caller: AnmTrackMaster_Unserialize_Inferred (0x00459750) after
// StdVector_Resize_Pod28; pushes begin at this+0x20 (vec @ this+0x1C).
// Reject scaffold Named_CalleeOf_Named_anmTrackMaster_inl_0045dd60.

#include <stdint.h>

struct ChunkScope {
  void *reader;     // +0x00
  uint32_t absPos;  // +0x04
  uint8_t okFlag;   // +0x08
  uint8_t pad[3];
  uint32_t tag;     // +0x0C
  uint32_t version; // +0x10
};

extern "C" ChunkScope *__thiscall stoChunkReader_EnterChunkScope(
    ChunkScope *scope /*ECX*/, void *reader /*stack, RET 4*/);
// count in EAX, dest in ECX, reader stack RET 4 (sealed aa_00436090)
extern "C" uint32_t stoChunkReader_readF32Array(float *dest, void *reader, int count);
extern "C" void FUN_00769e40(void);

enum { kFourCC_KEST = 0x4B455354 };

// Portable doc signature. Retail: ECX=elem_count, EDI=reader, stack=dest.
extern "C" uint32_t Anm_KestChunk_ReadF32Array_Inferred(
    int elem_count,
    void *reader,
    float *dest)
{
  ChunkScope scope;
  // retail: MOV ESI,ECX; PUSH EDI; LEA ECX,scope; CALL Enter
  stoChunkReader_EnterChunkScope(&scope, reader);

  if (scope.tag == (uint32_t)kFourCC_KEST) {
    // retail: EAX = elem_count * 7 via (esi*8 - esi)*4 / 4
    uint32_t status = stoChunkReader_readF32Array(dest, reader, elem_count * 7);
    if (scope.okFlag)
      FUN_00769e40();
    return status;
  }

  if (scope.okFlag)
    FUN_00769e40();
  return 0xFFFFFFFFu;
}
