// =============================================================================
// stoChunkReader_ReadU32_ModeDispatch  (FUN_00436900)
// -----------------------------------------------------------------------------
// Stable ID: aa_00436900
// Address:   0x00436900–0x0043691a  (autoassault.exe, image base 0x400000)
// Body size: 27 bytes
// System:    storage / arda2 stoChunk
// Generated: 2026-07-23 scaffold as FUN_00436900; dual A/B seal 2026-07-29 (W22-R)
// Exactness: Behavior-preserving rewrite of decompiler + entry-byte CF.
//            Not modernization. Bit-for-bit vs retail: DEFERRED.
// =============================================================================
//
// PURPOSE
//   Dispatch a single uint32 read on a stoChunkReader by mode at reader+0x4044:
//     0  → binary LE dword via stoChunkReader_ReadU32 (FUN_00437050)
//     ≠0 → text token path FUN_007689e0 (stoChunk.cpp plate)
//
// ABI (retail)
//   EAX = StoChunkReader*
//   ECX = uint32_t* out   (pushed as stack formal to both callees)
//   plain ret; EAX = 0 / 0xffffffff (decompiler void understates)
//
// READABILITY CF:
//   cmp [eax+0x4044],0 → jz binary else text
//   binary: push ecx; call 00437050; ret
//   text:   push edi; push ecx; mov edi,eax; call 007689e0; pop edi; ret
//

#include <cstdint>

struct StoChunkReader {
  // +0x4044: mode (0 = binary, non-zero = text)
};

// Sealed binary peer (W18-N): EAX=reader, stack=out, RET 4
extern "C" int32_t stoChunkReader_ReadU32(StoChunkReader* reader /*EAX*/, uint32_t* out /*stack*/);

// Text-mode peer: out on stack; reader in EDI; returns 0 / -1
extern "C" int32_t FUN_007689e0(uint32_t* out /*stack*/ /* + reader in EDI */);

// Clean plate: explicit args. Retail uses EAX/ECX + plain ret.
int32_t stoChunkReader_ReadU32_ModeDispatch(StoChunkReader* reader /*EAX*/, uint32_t* out /*ECX*/)
{
  if (*(int32_t*)(reinterpret_cast<uint8_t*>(reader) + 0x4044) == 0) {
    return stoChunkReader_ReadU32(reader, out);
  }
  // Retail also moves reader into EDI for FUN_007689e0.
  return FUN_007689e0(out);
}

// Legacy Ghidra name — see FUN_00436900.cpp
// void __fastcall FUN_00436900(undefined4 param_1); // in_EAX = reader
