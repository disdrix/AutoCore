// =============================================================================
// TNL_ByteBuffer_UnpackData
// -----------------------------------------------------------------------------
// Stable ID: aa_00637750
// Address:   0x00637750  (autoassault.exe, image base 0x400000)
// Body:      0x00637750 – 0x00637982
// System:    client-net / TNL special-message (MapInstanceListResponse 0x804D)
// Generated: 2026-07-23 scaffold; refined 2026-07-29 dual A/B seal
// Exactness: Behavior-preserving rewrite of decompiler control flow + byte check.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes (dual A/B sealed 2026-07-29):
 * - cdecl(out**, inRefBuf*); RET; returns out**.
 * - Sole caller: Client_UnpackSpecialMessage when opcode == 0x804D
 *   (AutoCore GameOpcode.MapInstanceListResponse).
 * - Wire: BitStream over in->data(+0xc), size(+0x10):
 *     u8 count;
 *     repeat count: u64, u16, u16, flag, flag.
 * - Rebuild Entry stride 0x18; heap array via operator_new[].
 * - Output TNL ByteBuffer (vtable PTR_LAB_009d7b00, object size 0x18):
 *     data prefix { u32 0x804D, u32 count, Entry* };
 *     size field = count*0x18+8; ownsMemory=1; refcount++.
 * - Releases input ref object (+0x08); vtbl+8 when zero.
 * - Inlined flag reads ≡ BitStream_readFlag (buffer/bitPos/endBits).
 * - Cross-check (not owned): FUN_0080a810 reads count@+4, entries*@+8.
 * - Runtime / differential verification: OPEN.
 */

#include <cstdint>
#include <cstring>

// Opaque helpers (named where Ghidra already resolved)
extern "C" {
void __thiscall FUN_0042b3a0(void* bitStream, void* data, int sizeBytes);
void __fastcall FUN_0042b250(void* obj);
void __fastcall FUN_0042b270(void* obj);
int  __thiscall BitStream_readBits(void* bitStream, int bitCount, void* dst);
void* operator_new(unsigned size);
void* operator_new__(unsigned size); // operator new[]
void* malloc(unsigned size);
void  free(void* p);
}

struct RefCountedBuffer {
    void**   vtbl;       // +0x00; release at vtbl[2] (+0x08)
    uint32_t pad04;      // +0x04
    int32_t  refcount;   // +0x08
    uint8_t* data;       // +0x0c
    int32_t  sizeBytes;  // +0x10
};

struct MapInstanceEntry {
    uint32_t idLo;       // +0x00  (u64 low)
    uint32_t idHi;       // +0x04  (u64 high)
    uint32_t fieldA;     // +0x08  (from u16)
    uint32_t fieldB;     // +0x0c  (from u16)
    uint8_t  flag0;      // +0x10
    uint8_t  flag1;      // +0x11
    uint8_t  pad12[6];   // +0x12 .. +0x17
};

struct ByteBuffer {
    void**   vtbl;       // +0x00 PTR_LAB_009d7b00
    uint32_t field04;    // +0x04
    int32_t  refcount;   // +0x08
    void*    data;       // +0x0c
    uint32_t size;       // +0x10
    uint8_t  ownsMemory; // +0x14
};

struct RebuiltPrefix {
    uint32_t          tag;     // 0x804D
    uint32_t          count;
    MapInstanceEntry* entries;
};

// Stack BitStream field offsets (from FUN_0042b3a0 / BitStream_writeFlag).
// +0x0c buffer, +0x18 bitPos, +0x2c endBits, +0x14 error sticky (byte).
static bool BitStream_ReadFlag_Inlined(uint8_t* bs)
{
    uint32_t bitPos  = *reinterpret_cast<uint32_t*>(bs + 0x18);
    uint32_t endBits = *reinterpret_cast<uint32_t*>(bs + 0x2c);
    if (endBits < bitPos + 1) {
        bs[0x1c] = 1; // sticky error (raw local_128 family)
        return false;
    }
    uint8_t* buf = *reinterpret_cast<uint8_t**>(bs + 0x0c);
    bool bit = (buf[bitPos >> 3] & static_cast<uint8_t>(1u << (bitPos & 7))) != 0;
    *reinterpret_cast<uint32_t*>(bs + 0x18) = bitPos + 1;
    return bit;
}

// TNL ByteBuffer unpack for special-message opcode 0x804D (MapInstanceListResponse).

void** TNL_ByteBuffer_UnpackData(void** outByteBuffer, RefCountedBuffer* inBuf)
{
    // SEH omitted (LAB_009a8d9e) — present in retail.

    RebuiltPrefix header;
    header.tag = 0x804D;
    header.count = 0;
    header.entries = nullptr;

    // Stack BitStream constructed over the inbound buffer payload.
    alignas(void*) unsigned char bitStreamStorage[0x40];
    std::memset(bitStreamStorage, 0, sizeof(bitStreamStorage));
    void* bs = bitStreamStorage;
    FUN_0042b3a0(bs, inBuf->data, inBuf->sizeBytes);

    uint8_t countU8 = 0;
    BitStream_readBits(bs, 8, &countU8);
    uint32_t count = countU8;
    uint32_t entryBytes = count * 0x18;
    header.count = count;
    header.entries = static_cast<MapInstanceEntry*>(operator_new__(entryBytes));

    if (countU8 != 0) {
        MapInstanceEntry* e = header.entries;
        uint32_t remaining = count;
        do {
            uint32_t idWords[2] = {0, 0};
            BitStream_readBits(bs, 0x40, idWords);
            e->idLo = idWords[0];
            e->idHi = idWords[1];

            uint16_t a = 0, b = 0;
            BitStream_readBits(bs, 0x10, &a);
            e->fieldA = a;
            BitStream_readBits(bs, 0x10, &b);
            e->fieldB = static_cast<uint32_t>(b) & 0xffffu;

            e->flag0 = BitStream_ReadFlag_Inlined(static_cast<uint8_t*>(bs)) ? 1 : 0;
            e->flag1 = BitStream_ReadFlag_Inlined(static_cast<uint8_t*>(bs)) ? 1 : 0;
            e->pad12[0] = e->pad12[1] = e->pad12[2] = e->pad12[3] = e->pad12[4] = e->pad12[5] = 0;

            e = reinterpret_cast<MapInstanceEntry*>(
                reinterpret_cast<char*>(e) + 0x18);
            remaining -= 1;
        } while (remaining != 0);
    }

    uint32_t totalSize = entryBytes + 8;
    ByteBuffer* bb = static_cast<ByteBuffer*>(operator_new(0x18));
    if (bb != nullptr) {
        FUN_0042b250(bb);
        bb->vtbl = reinterpret_cast<void**>(0x009d7b00); // PTR_LAB_009d7b00
        bb->size = totalSize;
        bb->data = malloc(totalSize);
        bb->ownsMemory = 1;
    }

    // Retail: dword/byte copy from stack header region of length totalSize.
    // Prefix consumed as {tag, count, entries*}; bytes beyond 12 unused by consumer.
    if (bb != nullptr && bb->data != nullptr) {
        auto* dst = static_cast<uint32_t*>(bb->data);
        dst[0] = header.tag;
        dst[1] = header.count;
        dst[2] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(header.entries));
        if (totalSize > 12) {
            std::memset(reinterpret_cast<uint8_t*>(bb->data) + 12, 0, totalSize - 12);
        }
    }

    *outByteBuffer = bb;
    if (bb != nullptr) {
        bb->refcount += 1;
    }

    // BitStream dtor path: free buffer if owns; FUN_0042b270 related list.
    // Raw: if (local_130) free(local_138); FUN_0042b270();
    FUN_0042b270(bs);

    inBuf->refcount -= 1;
    if (inBuf->refcount == 0) {
        auto release = reinterpret_cast<void(__thiscall*)(RefCountedBuffer*)>(
            inBuf->vtbl[2]);
        release(inBuf);
    }

    return outByteBuffer;
}
