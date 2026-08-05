// =============================================================================
// FUN_00434dd0  (scaffold twin of NDAssetImage_DecodeUncompressedTgaRow)
// -----------------------------------------------------------------------------
// Stable ID: aa_00434dd0
// Address:   0x00434dd0  (autoassault.exe, image base 0x400000)
// System:    gfx-asset / NDAssetImage / TGA
// Generated: 2026-07-23 scaffold; dual seal refine 2026-07-29 W22-O
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Canonical named twin: reconstructed-exact/NDAssetImage_DecodeUncompressedTgaRow.cpp
//
// ABI sealed (bytes): ECX=stream*, EDX=dest*, ret 0x14 with 5 stack formals
//   [ebp+8]=image, [ebp+0xc]=header (bpp@+0x10), [ebp+0x10]=count,
//   [ebp+0x14]=y, [ebp+0x18]=x0
// 16-bit R channel: bytes force (pix&0x1f)<<3 — decompiler understates mask.
// =============================================================================

void FUN_00433280(unsigned /* alpha residual */);

void __fastcall FUN_00434dd0(int *param_1 /*ECX stream*/, char *param_2 /*EDX dest*/,
                             unsigned /*stack image etc. understated by decompiler*/,
                             int param_4 /* header in live ABI is stack */,
                             int param_5 /* count */)
{
  // NOTE: Decompiler formals understate the true 5-stack ABI (ret 0x14).
  // Named clean has full sealed signature. Body CF below matches live decompile.

  int iVar1;
  char local_30;
  char local_2f;
  char local_2e;
  unsigned local_2d;
  int local_28;
  int local_24;
  char *local_20;
  char *local_1c;
  unsigned local_18;
  unsigned char *local_14;
  void *local_10;
  unsigned char *puStack_c;
  unsigned local_8;

  puStack_c = (unsigned char *)0; // &LAB_009bccb0
  local_10 = 0;                   // ExceptionList
  local_14 = 0;
  local_8 = 0;
  switch (*(unsigned char *)(param_4 + 0x10)) {
  case 8:
    iVar1 = *param_1;
    goto LAB_00434e20;
  case 0xf:
  case 0x10:
    for (iVar1 = 0; iVar1 < param_5; iVar1 = iVar1 + 1) {
      local_28 = iVar1;
      local_1c = param_2;
      (**(int (**)(int *, unsigned *, int, int))(*param_1 + 8))(param_1, &local_18, 2, 1);
      // Sealed: (local_18 & 0x1f) << 3  (decomp shows unmasked char*8)
      *param_2 = (char)((local_18 & 0x1f) * 8);
      param_2[1] = (char)((local_18 >> 2) & 0xf8);
      param_2[2] = (char)((local_18 >> 7) & 0xf8);
      param_2 = param_2 + 3;
    }
    break;
  case 0x18:
    iVar1 = *param_1;
    param_5 = param_5 * 3;
  LAB_00434e20:
    (**(int (**)(int *, char *, int, int))(iVar1 + 8))(param_1, param_2, param_5, 1);
    break;
  case 0x20:
    local_20 = param_2;
    for (local_24 = 0; local_24 < param_5; local_24 = local_24 + 1) {
      (**(int (**)(int *, char *, int, int))(*param_1 + 8))(param_1, &local_30, 4, 1);
      *param_2 = local_30;
      param_2[1] = local_2f;
      param_2[2] = local_2e;
      param_2 = param_2 + 3;
      local_20 = param_2;
      FUN_00433280(local_2d);
    }
  }
  return;
}
