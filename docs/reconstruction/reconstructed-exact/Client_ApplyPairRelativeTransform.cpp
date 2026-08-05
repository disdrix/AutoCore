// =============================================================================
// Client_ApplyPairRelativeTransform  (FUN_00439a80)
// -----------------------------------------------------------------------------
// Stable ID: aa_00439a80
// Address:   0x00439a80  (autoassault.exe, image base 0x400000)
// Body:      0x00439a80–0x00439da3
// System:    client gfx / special-event pair attach
// Generated: 2026-07-29 W19-S dual A/B seal
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE: Apply a relative transform between a pair of client objects described
// by an EDI-held 4-pointer context. Multi-caller (TeleportIn, Respawn Update,
// attach helpers) — not exclusive to any one special-event.
//
// ABI: EDI = PairXformCtx*; bare ret (c3). No stack args.
//   ctx+0  objA*
//   ctx+4  optional A-side helper* (null → vtbl+8 with id -1)
//   ctx+8  objB*  (primary apply target)
//   ctx+0xc optional B-side helper*
//
// Notable callees (sibling VAs; names partial):
//   FUN_00972cc0 / FUN_00972e50 / FUN_00973030 — gfx node ensure/rebuild/compose
//   FUN_0040cf90 / FUN_0040d1a0 — float block copy helpers
//   FUN_0076f6e0 — Math_Mat4TransformPoint3_Project
//
// Quaternion inverse uses eps 1e-6f @ 0x00a240ec and -1e-6f @ 0x00aaa640.
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

extern float g_flOne;
extern float _DAT_00a240ec;  // 1e-6f
extern float DAT_00aaa640;   // -1e-6f

void FUN_00972cc0(void);
void FUN_00972e50(void);
void FUN_00973030(void *p);
void FUN_0040cf90(void *p /* decomp thiscall residual */);
void FUN_0040d1a0(void *p);
void FUN_0076f6e0(void);  // Math_Mat4TransformPoint3_Project

void Client_ApplyPairRelativeTransform(void)
{
  int iVar1;
  int iVar2;
  unsigned int *unaff_EDI;
  float fVar3;
  unsigned int uVar4;
  unsigned int uStack_338;
  unsigned int uStack_334;
  unsigned int uStack_330;
  unsigned int uStack_328;
  unsigned int uStack_324;
  unsigned int uStack_320;
  float fStack_31c;
  float fStack_2a8;
  float fStack_2a4;
  float fStack_2a0;
  float fStack_29c;
  unsigned int uStack_298;
  unsigned int uStack_294;
  unsigned int uStack_290;
  int iStack_274;
  unsigned int uStack_26c;
  unsigned char auStack_260[120];
  float fStack_1e8;
  float fStack_1e4;
  float fStack_1e0;
  float fStack_1dc;
  unsigned char auStack_1a8[16];
  unsigned char auStack_198[200];
  unsigned char local_d0[100];
  unsigned char auStack_6c[20];
  unsigned char auStack_58[84];

  iVar1 = (int)unaff_EDI[3];
  iVar2 = (int)unaff_EDI[1];
  FUN_00972cc0();
  if (iVar2 == 0) {
    (**(void (**)(int, void *))(*(int *)*unaff_EDI + 8))(-1, local_d0);
  } else {
    (**(void (**)(unsigned int, void *))(*(int *)*unaff_EDI + 8))(
        *(unsigned int *)(iVar2 + 0xc), local_d0);
    FUN_00972cc0();
    FUN_0040cf90((void *)(iVar2 + 0x20));
    FUN_0040d1a0((void *)(iVar2 + 0x10));
    FUN_00973030(auStack_198);
  }
  uStack_328 = 0;
  uStack_324 = 0;
  uStack_320 = 0;
  fStack_31c = g_flOne;
  (**(void (**)(void *))(*(int *)unaff_EDI[2] + 0x14))(&uStack_328);
  uStack_338 = 0;
  uStack_334 = 0;
  uStack_330 = 0;
  (**(void (**)(void *))(*(int *)unaff_EDI[2] + 0x18))(&uStack_338);
  (**(void (**)(void))(*(int *)unaff_EDI[2] + 0x34))();
  FUN_00972cc0();
  if (iVar1 == 0) {
    (**(void (**)(int, void *))(*(int *)unaff_EDI[2] + 8))(-1, auStack_260);
  } else {
    (**(void (**)(unsigned int, void *))(*(int *)unaff_EDI[2] + 8))(
        *(unsigned int *)(iVar1 + 0xc), auStack_260);
    FUN_00972cc0();
    FUN_0040cf90((void *)(iVar1 + 0x20));
    FUN_0040d1a0((void *)(iVar1 + 0x10));
    FUN_00973030(auStack_1a8);
  }
  FUN_00972cc0();
  iStack_274 = iStack_274 + 1;
  fVar3 = fStack_1e8 * fStack_1e8 + fStack_1e4 * fStack_1e4 + fStack_1e0 * fStack_1e0 +
          fStack_1dc * fStack_1dc;
  uStack_26c = 0xffffffff;
  if ((_DAT_00a240ec <= fVar3) || (fVar3 <= DAT_00aaa640)) {
    fVar3 = g_flOne / fVar3;
    fStack_2a8 = (0.0f - fStack_1e8) * fVar3;
    fStack_2a4 = (0.0f - fStack_1e4) * fVar3;
    fStack_2a0 = (0.0f - fStack_1e0) * fVar3;
    fStack_29c = fStack_1dc * fVar3;
  }
  FUN_00972e50();
  iStack_274 = iStack_274 + 1;
  uStack_26c = 0xffffffff;
  FUN_0076f6e0();
  uStack_298 = uStack_338;
  uStack_294 = uStack_334;
  uStack_290 = uStack_330;
  FUN_00973030(&uStack_328);
  uVar4 = 3;
  (**(void (**)(int, void *))(*(int *)unaff_EDI[2] + 0x10))(3, auStack_58);
  FUN_0040cf90((void *)(uintptr_t)uVar4);
  uVar4 = 3;
  (**(void (**)(int, void *))(*(int *)unaff_EDI[2] + 0x10))(3, auStack_6c);
  FUN_0040d1a0((void *)(uintptr_t)uVar4);
  (**(void (**)(void))(*(int *)unaff_EDI[2] + 0x34))();
  return;
}

// Ghidra alias
void FUN_00439a80(void)
{
  Client_ApplyPairRelativeTransform();
}
