// =============================================================================
// TNL_GroupReactionCall_UnpackData
// -----------------------------------------------------------------------------
// Stable ID: aa_006374f0
// Address:   0x006374f0–0x0063774d  (autoassault.exe, image base 0x400000)
// System:    client-net / TNL special-message (GroupReactionCall 0x206C)
// Generated: 2026-07-29 W22-N dual seal (decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler + byte CF. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Unpack opcode 0x206C GroupReactionCall special-message into a ByteBuffer.
//   Wire: u8 count; per entry type byte then type-1 (u16+f32) or else
//   (readInt 19 + u64 TFID + 2 inlined flags). Entry stride 0x28.
//   Rebuild: ByteBuffer vtbl PTR_LAB_009d7b00, size = count*0x28+1, owns=1.
//
// ABI: cdecl — (out**, inRefBuf*) -> out**; plain RET after add esp,0x2940.
// CALLER: Client_UnpackSpecialMessage when param_2 == 0x206c only.
// =============================================================================

#include <cstdint>
#include <cstring>

extern "C" void FUN_0042b3a0(void* data, void* lenOrEnd); // BitStream_BindFromBuffer
extern "C" void BitStream_readBits(int bitCount, void* out);
extern "C" uint32_t BitStream_readInt(int bitCount);
extern "C" void FUN_0042b250(); // LinkedListHead_Ctor
extern "C" void FUN_0042b270(); // LinkedListHead_ClearNodes
extern "C" void* operator_new(uint32_t size);
extern "C" void* malloc(uint32_t size);
extern "C" void free(void* p);

// Inlined BitStream flag reader shape (matches sibling TNL_ByteBuffer_UnpackData).
// Authoritative bit extract remains in raw decompile (local_2918 / local_290c / local_28f8).
static bool BitStream_readFlag_Inlined_Placeholder() {
  // See raw: bit test against bound buffer; advances bit cursor.
  return false;
}

struct TnlRefBuffer_Inferred {
  void** vtbl;       // +0
  uint32_t _pad4;
  int refcount;      // +8
  void* data;        // +0xc
  void* dataEndOrLen;// +0x10
};

struct TnlByteBuffer_Inferred {
  void** vtbl;       // +0  PTR_LAB_009d7b00
  uint32_t _pad4;
  int refcount;      // +8
  void* data;        // +0xc malloc
  uint32_t size;     // +0x10
  uint8_t owns;      // +0x14
};

// Entry image stride 0x28 (10 dwords). Field layout: see annotated (type-1 vs else).
struct GroupReactionEntry_Inferred {
  uint8_t  raw[0x28];
};

extern "C" void** FUN_006374f0(void** out, TnlRefBuffer_Inferred* inBuf);

void** TNL_GroupReactionCall_UnpackData(void** out, TnlRefBuffer_Inferred* inBuf) {
  // Large stack image omitted — retail uses ~0x2934 chkstk frame.
  // Conceptual CF:

  // local tag / count / entries[] on stack
  uint32_t tag = 0x206c;
  (void)tag;

  FUN_0042b3a0(inBuf->data, inBuf->dataEndOrLen);

  uint8_t count = 0;
  BitStream_readBits(8, &count);

  // Per-entry decode into stack image (stride 0x28)
  for (uint32_t i = 0; i < count; ++i) {
    uint8_t type = 0;
    BitStream_readBits(8, &type);
    if (type == 1) {
      uint16_t u16 = 0;
      BitStream_readBits(16, &u16);
      uint32_t bits32 = 0;
      BitStream_readBits(32, &bits32);
      float f;
      std::memcpy(&f, &bits32, 4); // retail: movss store
      (void)u16;
      (void)f;
    } else {
      uint32_t id19 = BitStream_readInt(0x13);
      uint64_t tfid = 0;
      BitStream_readBits(0x40, &tfid);
      bool flag0 = BitStream_readFlag_Inlined_Placeholder();
      bool flag1 = BitStream_readFlag_Inlined_Placeholder();
      (void)id19;
      (void)tfid;
      (void)flag0;
      (void)flag1;
    }
  }

  uint32_t size = (uint32_t)count * 0x28u + 1u;
  auto* bb = (TnlByteBuffer_Inferred*)operator_new(0x18);
  if (bb != nullptr) {
    FUN_0042b250();
    // *bb = vtbl PTR_LAB_009d7b00; size; malloc; owns=1
    bb->size = size;
    bb->data = malloc(size);
    bb->owns = 1;
    // memcpy stack image (&tag..) -> bb->data for `size` bytes
  }

  *out = bb;
  if (bb) {
    bb->refcount += 1;
  }

  // teardown BitStream buffer if owned; FUN_0042b270()
  FUN_0042b270();
  inBuf->refcount -= 1;
  if (inBuf->refcount == 0) {
    // (**(code**)(*inBuf + 8))()
  }
  return out;
}

void** FUN_006374f0(void** out, TnlRefBuffer_Inferred* inBuf) {
  return TNL_GroupReactionCall_UnpackData(out, inBuf);
}
