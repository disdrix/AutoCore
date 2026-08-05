// =============================================================================
// MeshWeightDebugOverlay_Update  (aa_00965ab0)
// -----------------------------------------------------------------------------
// Address:   0x00965ab0  (autoassault.exe, image base 0x400000)
// Body:      0x00965ab0 – 0x0096650A exclusive (2650 B / 0xA5A)
// Wave:      W36-N OWN-ONLY dual 2026-07-29
// Exactness: Structural rewrite of sealed CF + domain. Not a line-for-line port
//            of the full 2.6 KB body (draw/layout callees residual).
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

// Partial overlay object — only fields proven by this function's uses.
struct MeshWeightDebugOverlay {
  uint8_t  pad00[0x30];
  uint32_t last_time;          // +0x30
  void*    ui_ctx;             // +0x34  vtbl draw context
  void*    parent_metrics;     // +0x38
  void*    font_resource;      // +0x3c  RC shared
  uint8_t  rate_mode;          // +0x40  0 → fade-out rate; else fade-in
  uint8_t  dirty;              // +0x41
  uint8_t  pad42[0x06];
  float    progress;           // +0x48  clamped [0,1]
  int32_t  offset_x;           // +0x4c
  int32_t  offset_y;           // +0x50
  uint32_t align_flags;        // +0x54  bit0/bit1
  uint8_t  pad58[0x04];
  void*    mesh_begin;         // +0x5c  elem stride 0x0C
  void*    mesh_end;           // +0x60
};

// Retail globals (sealed via read_memory / XP.md)
// 0x00AAA5DC : 4294967296.0f   unsigned dt fixup
// 0x00AAA9F4 : -0.005f         fade-out rate when rate_mode==0
// 0x00AAA6A4 :  0.005f         g_flHardKillInterpolate fade-in rate
// 0x00AAA6F8 : 255.0f          alpha scale
// 0x00A27C24 : 80.0f           layout scale

extern "C" uint32_t FUN_0076c3c0(void); // time
// Sealed W35-Q: EDI=vec, ECX=n, stack T by-value 0x1c, RET 0x1C
extern "C" void FUN_004611e0(/* StdVector_Resize_RcElem28 */);
// push_back RC-elem28 (unowned)
extern "C" void FUN_00460f90(void);

// stdcall RET 4 — sole parent pushes object* and does not clean stack.
extern "C" void MeshWeightDebugOverlay_Update(MeshWeightDebugOverlay* self)
{
  // 1) dt from timebase - last_time; optional 2^32 fixup; × rate by rate_mode
  // 2) progress = clamp(progress + delta, 0.f, 1.f)
  // 3) if progress == 0: ui_ctx->vtbl[1](); return;   // vtbl+4
  // 4) if dirty || progress != 1:
  //      begin UI nest on ui_ctx
  //      alpha = round(progress * 255)
  //      if mesh range empty: draw placeholder path
  //      else:
  //        build zero-resource RcElem28 fill value on stack
  //        StdVector_Resize_RcElem28(line_vec, /*n*/…, fill)  // @ 0x004611e0
  //        for each mesh entry (stride 0xC):
  //          sprintf mesh name / "Max Weights Per Vertex: %d"
  //          for TM/RM modes (Normal/Static tables):
  //            format "  TM: %s, RM: %s" and per-id lines
  //            push UI line elems via FUN_00460f90 (RC font AddRef/Release)
  //      end nest; layout; apply align_flags; dirty = 0
  // 5) return
  (void)self;
  (void)FUN_0076c3c0;
  (void)FUN_004611e0;
  (void)FUN_00460f90;
}
