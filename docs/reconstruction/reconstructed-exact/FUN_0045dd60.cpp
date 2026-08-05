// =============================================================================
// FUN_0045dd60  (twin of Anm_KestChunk_ReadF32Array_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0045dd60
// Address:   0x0045dd60–0x0045de07 (168 B / 0xA8)
// Dual:      2026-08-04 W37-P OWN-ONLY
// =============================================================================
// Retail: ECX=elem_count, EDI=reader, stack=dest*, bare RET, caller ADD ESP,4.
// Prefer named clean Anm_KestChunk_ReadF32Array_Inferred.cpp for portable form.

#include <stdint.h>

struct ChunkScope {
  void *reader;
  uint32_t absPos;
  uint8_t okFlag;
  uint8_t pad[3];
  uint32_t tag;
  uint32_t version;
};

extern "C" ChunkScope *__thiscall stoChunkReader_EnterChunkScope(ChunkScope *scope, void *reader);
extern "C" uint32_t stoChunkReader_readF32Array(float *dest, void *reader, int count);
extern "C" void FUN_00769e40(void);

enum { kFourCC_KEST = 0x4B455354 };

// Doc twin: surfaces EDI as explicit reader (retail register formal).
extern "C" uint32_t FUN_0045dd60(int elem_count /*ECX*/, void *reader /*EDI*/, float *dest /*stack*/)
{
  ChunkScope scope;
  stoChunkReader_EnterChunkScope(&scope, reader);

  if (scope.tag == (uint32_t)kFourCC_KEST) {
    uint32_t status = stoChunkReader_readF32Array(dest, reader, elem_count * 7);
    if (scope.okFlag)
      FUN_00769e40();
    return status;
  }

  if (scope.okFlag)
    FUN_00769e40();
  return 0xFFFFFFFFu;
}
