// =============================================================================
// PalToolHost_ChannelGeomUpload_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00730b50
// Address:   0x00730b50–0x00731123 (1492 B)  autoassault.exe base 0x400000
// System:    palantir graphics / PalTool host channel geometry upload
// Generated: 2026-08-04 W37-U dual seal
// Exactness: Structural CF from Ghidra decompile. SEH locals simplified.
// Bit-for-bit vs retail EXE: DEFERRED. Prefer raw decompile for full SEH order.
// =============================================================================
//
// ABI: stdcall host*, channelIndex; RET 8 (C2 08 00); status EAX.
// Sole caller: PalToolNoMap_Host0x44_DualChannelInit_Inferred (ch=0 then ch=1).
// Product plate: gfxDeviceVB.cpp unlock log (line 0xD3).

#include <cstdint>

extern float g_flOne;
extern uint32_t DAT_00a10e78, DAT_00a0f718, DAT_00d1a6c0, DAT_00d1a6c4, DAT_00d1a6c8;
extern uint32_t DAT_00aaa8f4, DAT_00aaa7b8;
extern void* PTR_FUN_00a9db18;

extern "C" void __stdcall _eh_vector_constructor_iterator_(void*, uint32_t, int, void*, void*);
extern "C" void __stdcall _eh_vector_destructor_iterator_(void*, uint32_t, int, void*);
void FUN_00982040(/* stream element ctor */);
void FUN_004579d0(/* stream element dtor */);
void FUN_00982100(int);
void FUN_007478c0(int fmt /* 0x152 */);
int  FUN_00414c20(int, void*, int, int);
void FUN_00414b60();
uint64_t FUN_007467b0();
void FUN_004451c0(void*, void*);
void FUN_00747390();
uint32_t FUN_0044bbc0(void*, void*, int);
void vog_LogMessage(const char* file, int line, int level, const char* msg);

uint32_t __stdcall PalToolHost_ChannelGeomUpload_Inferred(int host, int channelIndex)
{
  // Local: 3×0x44 stream objects at local_f0 family (raw SEH).
  uint8_t streams[0x44 * 3];
  _eh_vector_constructor_iterator_(streams, 0x44, 3,
                                   reinterpret_cast<void*>(FUN_00982040),
                                   reinterpret_cast<void*>(FUN_004579d0));

  // Three fill passes: color/position defaults from DAT_* + g_flOne,
  // ARGB sentinels 0xff800000 / 0xff008000 / 0xff000080, FUN_00982100(3)×3.
  // (Exact field stores: see raw decompile; DAT values read_memory sealed.)
  (void)g_flOne;
  (void)DAT_00a10e78;
  (void)DAT_00a0f718;
  (void)DAT_00d1a6c0;
  (void)DAT_00d1a6c4;
  (void)DAT_00d1a6c8;
  (void)DAT_00aaa8f4;
  (void)DAT_00aaa7b8;
  FUN_00982100(3);
  FUN_00982100(3);
  FUN_00982100(3);

  // Stream0 begin/end at local_e8 / local_e4 in decompile:
  int* begin = nullptr; // local_e8 after fills
  int* end = nullptr;   // local_e4
  int n = 0;
  if (begin != nullptr) {
    n = static_cast<int>((reinterpret_cast<uint8_t*>(end) -
                          reinterpret_cast<uint8_t*>(begin)) / 0x24);
  }
  uint32_t n_aligned = (static_cast<uint32_t>(n) / 3u) * 3u;
  *reinterpret_cast<uint32_t*>(host + 4 + channelIndex * 4) = n_aligned;
  *reinterpret_cast<uint32_t*>(host + 0xc + channelIndex * 4) = 4;

  int triVerts = n * 3;
  FUN_007478c0(0x152);

  // VB wrapper local_120/local_11c (vtbl PTR_FUN_00a9db18); FUN_00414c20
  void* vbDesc = nullptr;
  (void)PTR_FUN_00a9db18;
  int st = FUN_00414c20(triVerts, &vbDesc, 8, 0);
  if (st < 0) {
    _eh_vector_destructor_iterator_(streams, 0x44, 3,
                                    reinterpret_cast<void*>(FUN_004579d0));
    return 0xFFFFFFFFu;
  }

  // Lock device vtbl+0x2c with flag 0x800; memcpy 3 streams of 0x24 verts;
  // advance dest by FUN_007467b0 stride when vertex-decl present;
  // Unlock vtbl+0x30 or vog_LogMessage gfxDeviceVB over-unlock plate.

  int matHolder = *reinterpret_cast<int*>(host + 0x34 + channelIndex * 8);
  int child = 0;
  if (matHolder != 0) {
    child = *reinterpret_cast<int*>(matHolder + 0x14);
  }
  uint32_t stride = 0x20;
  if (child != 0 && *reinterpret_cast<char*>(child + 0x10) != 0) {
    stride = 0x10;
  }

  uint8_t ibLocal[24];
  FUN_004451c0(ibLocal, &vbDesc);
  FUN_00747390();
  FUN_00414c20(triVerts, ibLocal, static_cast<int>(stride), 0);
  uint32_t status = FUN_0044bbc0(/*src*/ nullptr,
                                 reinterpret_cast<void*>(host + 0x24 + channelIndex * 8),
                                 0);
  FUN_00414b60();
  // refcount release on VB wrapper; FUN_00414b60; stream dtors
  _eh_vector_destructor_iterator_(streams, 0x44, 3,
                                  reinterpret_cast<void*>(FUN_004579d0));
  return status;
}
