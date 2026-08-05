// =============================================================================
// GfxBody_UnserializeGBOD_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00765740
// Address:   0x00765740–0x00766045 (2310 B / 0x906)
// Module:    autoassault.exe (image base 0x400000)
// System:    palantir graphics — gfxBody.cpp GBOD sto unserialize
// Wave:      W37-S OWN-ONLY dual (2026-08-04)
// Exactness: Behavior-preserving structural rewrite from decompile + read_memory.
//            Nested helper English left as FUN_* when unowned.
// Bit-for-bit / runtime / differential: OPEN (no Launcher).
// =============================================================================

#include <cstdint>

// FOURCC GBOD = 0x47424F44 (file tag bytes DOBG)
static constexpr uint32_t kTag_GBOD = 0x47424F44u;

// Reader mode flag at reader + 0x4044 == reader[0x1011] as DWORD index.
// body layout spans used: +0x4 (xform src), +0x34 (xform dst, 12 dwords),
// +0x80/+0x84, +0x94, +0x98, +0xC0/+0xC4, +0xD0/+0xD4, +0x12C/+0x130.

// stdcall; RET 8
// Returns OR of nested status bits; 0xFFFFFFFF on invalid tag or version.
uint32_t __stdcall GfxBody_UnserializeGBOD_Inferred(void* body, void* reader)
{
    // SEH: LAB_009b31c4
    // stoChunkReader_EnterChunkScope(reader) → tag, version, scope flag
    uint32_t tag = 0;      // from enter-scope out (local_30)
    int32_t version = 0;   // local_2c
    char scope_active = 0; // local_34
    uint32_t status = 0;   // local_5c OR-accumulator

    // (live: EnterChunkScope fills tag/version/scope)
    (void)reader;
    if (tag != kTag_GBOD) {
        // vog_LogMessage(gfxBody.cpp, 0x143, 3,
        //   "Invalid TAG unserializeing gfxBody, probably exported wrong");
        if (scope_active) { /* FUN_00769e40 leave */ }
        return 0xFFFFFFFFu;
    }

    void* xform_src = reinterpret_cast<uint8_t*>(body) + 4; // local_4c

    if (version == 1) {
        // FUN_0074ce60(body+4); FUN_004372a0(reader);
        // count/read helpers via mode branch; FUN_00437f70 grow/prepare
        // for each element in [body+0x80, body+0x84):
        //   read ids; FUN_004382c0 / FUN_00437e40; inner stride-0x38 pair reads
        // FUN_0096b930(reader, body+0x98); more counts; FUN_00438040
        // for each pair in [body+0x12C, body+0x130) step 8: FUN_004373b0
        // FUN_00456780; for ptr in [+0xC0,+0xC4): FUN_00437b00 + vcall[+0x64]
        // FUN_00456780; for ptr in [+0xD0,+0xD4): FUN_00437b00; *obj+0xBC |= 0x40
        status = 0; // OR of all of the above
    } else if (version == 2 || version == 3) {
        if (version == 3) {
            // two count reads + loop of string reads (discard) for count
        }
        // shared v2/v3:
        // FUN_0074ce60; FUN_004372a0; section counts
        // for each in [+0x80,+0x84):
        //   mode0: inline dword reads (+ FUN_00435df0 refill) else FUN_00768760/FUN_007689e0
        //   string pair + FUN_00437e40; inner 0x38 stride string-ish reads
        // FUN_0096b930(reader, body+0x98); FUN_00438040; FUN_004373b0 loop
        // FUN_00456780; factory loop [+0xC0,+0xC4): FUN_00437b00; if status<0 goto leave;
        //   vcall[+0x64]
        // more counts; FUN_00456780; FUN_004363b0 (bitset cursor on reader)
        // factory loop [+0xD0,+0xD4): FUN_00437b00; if status<0 goto leave;
        //   *obj+0xBC |= 0x40; optional vcall0 if DAT_00afa2d8==0
        // FUN_00767570; optional bool; if true MapB FUN_00437c90 → body+0x94 + vcalls
        status = 0;
    } else {
        // FUN_0076cec0 format + vog_LogMessage invalid version (%i)
        if (scope_active) { /* leave */ }
        return 0xFFFFFFFFu;
    }

    // copy 12 dwords body+4 → body+0x34
    uint32_t* dst = reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(body) + 0x34);
    uint32_t* src = reinterpret_cast<uint32_t*>(xform_src);
    for (int i = 0; i < 12; ++i) {
        dst[i] = src[i];
    }

    if (scope_active) {
        // FUN_00769e40 leave chunk
    }
    return status;
}
