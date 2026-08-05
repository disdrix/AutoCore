// =============================================================================
// phyBoundingBox_Unserialize  (Ghidra: FUN_0074ce60)
// -----------------------------------------------------------------------------
// Stable ID: aa_0074ce60
// Address:   0x0074ce60  (autoassault.exe, image base 0x400000)
// System:    palantir physics / sto-chunk (phyBoundingBox.cpp)
// Generated: 2026-08-04 W38-H dual A/B
// Exactness: Behavior-preserving rewrite of decompiler CF + byte ABI.
//            Not modernization. Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Unserialize a phyBoundingBox from a stoChunkReader:
//     ECX = phyBoundingBox*
//     EBX = stoChunkReader*   (chunk-reader calling convention)
//     return 0 on success, -1 on bad tag/version/stream
//
//   Tag 'BBOX' (0x42424F58). Versions 1 and 2.
//   v1: three float3 arrays (stream order +0x14, +0x20, +0x00 — B,C,A) + f32, then derive bool from f32<=0.
//   v2: bool first, then same three float3 order + f32 (bool not re-derived).
//   Always recompute horizontal extent at +0x10 from xz of A and C.
//   ADV 2026-08-04: dual initially listed A→B→C offsets; live LEAs are B→C→A.
//
// BODY: 0x0074ce60–0x0074d0b4 exclusive (596 B). Dual: accept.
// =============================================================================

#include <cmath>
#include <cstdint>

struct StoChunkReader;  // opaque; +0x402c status, +0x4044 binary/text mode

struct PhyBoundingBox {
  float a[3];       // +0x00
  float scalar;     // +0x0C
  float extent_xz;  // +0x10 computed
  float b[3];       // +0x14
  float c[3];       // +0x20
  bool flag;        // +0x2C
};

// Unowned callees — declarations only.
extern "C" void stoChunkReader_EnterChunkScope(StoChunkReader* r /*EBX*/, void* scope_locals /*ECX*/);
extern "C" void FUN_00769e40();  // leave scope (thiscall on scope)
extern "C" void vog_LogMessage(const char* file, int line, int level, const char* msg);
extern "C" uint32_t stoChunkReader_readF32Array(float* dest /*ECX*/,
                                                StoChunkReader* reader /*stack*/,
                                                int count /*EAX*/);
extern "C" int FUN_00435fe0(StoChunkReader* r /*this*/, float* out);   // binary f32
extern "C" int FUN_00767fd0(StoChunkReader* r /*this*/, float* out);   // text f32
extern "C" int FUN_00437000(StoChunkReader* r /*EAX*/, uint8_t* out /*EDI*/);  // binary u8/bool
extern "C" int FUN_00769660(uint8_t* out /*arg*/, StoChunkReader* r /*EDI*/);  // text bool

static constexpr uint32_t kBboxTag = 0x42424F58u;  // 'BBOX'

// Documentary port — retail keeps reader in EBX across the call.
extern "C" int phyBoundingBox_Unserialize(PhyBoundingBox* self /*ECX*/,
                                          StoChunkReader* reader /*EBX*/)
{
  // SEH / EnterChunkScope omitted in documentary form — retail installs LAB_009b1ab3.
  // Scope locals produce: tag, version, leave-flag (decompiler local_14/10/18).

  uint32_t tag = 0;
  int version = 0;
  char leave_flag = 0;
  // ... EnterChunkScope fills tag/version/leave_flag from reader ...

  if (tag != kBboxTag) {
    vog_LogMessage(
        "C:\\vog\\1_code\\palantir\\palantir\\physics\\phyBoundingBox.cpp",
        0x7e, 3, "Invalid TAG unserializing phyBoundingBox");
    // leave scope if needed
    return -1;
  }

  auto read_f32 = [&](float* out) {
    // reader+0x4044 == 0 → binary else text (bytes)
    // FUN_00435fe0(reader, out) or FUN_00767fd0(reader, out)
    (void)out;
  };
  auto read_bool = [&](bool* out) {
    // v2: FUN_00437000 / FUN_00769660
    (void)out;
  };

  if (version == 1) {
    // Stream order sealed by LEAs: +0x14 → +0x20 → +0x00 (B, C, A) — not A,B,C.
    stoChunkReader_readF32Array(self->b, reader, 3);
    stoChunkReader_readF32Array(self->c, reader, 3);
    stoChunkReader_readF32Array(self->a, reader, 3);
    read_f32(&self->scalar);
    {
      float dx = self->c[0] - self->a[0];
      float dz = self->c[2] - self->a[2];
      self->extent_xz = std::fabs(std::sqrt(dx * dx + dz * dz));
    }
    self->flag = (self->scalar <= 0.0f);
  } else if (version == 2) {
    read_bool(&self->flag);
    stoChunkReader_readF32Array(self->b, reader, 3);
    stoChunkReader_readF32Array(self->c, reader, 3);
    stoChunkReader_readF32Array(self->a, reader, 3);
    read_f32(&self->scalar);
    {
      float dx = self->c[0] - self->a[0];
      float dz = self->c[2] - self->a[2];
      self->extent_xz = std::fabs(std::sqrt(dx * dx + dz * dz));
    }
  } else {
    vog_LogMessage(
        "C:\\vog\\1_code\\palantir\\palantir\\physics\\phyBoundingBox.cpp",
        0x9c, 3, "Invalid chunk version unserializing phyBoundingBox");
    return -1;
  }

  // leave scope if leave_flag
  // status = *(int*)(reader + 0x402c);
  // return (status >= 0) ? 0 : -1;
  return 0;
}
