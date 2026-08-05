// =============================================================================
// Mem_Move200B_Blocks_Inferred  (was FUN_00480970)
// -----------------------------------------------------------------------------
// Stable ID: aa_00480970
// Address:   0x00480970  (autoassault.exe, image base 0x400000)
// Body:      0x00480970–0x004809a0 (49 bytes)
// System:    container / mem / 200-byte record range move
//
// cdecl leaf (call-site Confirmed):
//   Stack: src begin, src end (exclusive), dest
//   Bare RET. Some callers push a 4th dummy and ADD ESP,0x10.
//
// Each iteration: REP MOVSD ECX=0x32 → 200 (0xC8) bytes; advance src/dest by 0xC8.
// Name INFERRED — structural; no product string in body.
// Dual: reviews/A|B_aa_00480970_Mem_Move200B_Blocks_Inferred.md (W21-M 2026-07-29)
// Exactness: CF mirrors bytes + decompile; not modernization.
// Bit-for-bit / runtime / diff: DEFERRED.
// =============================================================================

#include <cstdint>
#include <cstring>

// Retail: ESI=src, EDI=dest, ECX=0x32, REP MOVSD; outer while src!=end.
void Mem_Move200B_Blocks_Inferred(void* src, void* src_end, void* dest)
{
    auto* s = static_cast<std::uint8_t*>(src);
    auto* e = static_cast<std::uint8_t*>(src_end);
    auto* d = static_cast<std::uint8_t*>(dest);

    while (s != e) {
        // asm: mov ecx, 0x32; rep movsd  (== 0xC8 bytes)
        std::memcpy(d, s, 0xC8);
        s += 0xC8;
        d += 0xC8;
    }
}
