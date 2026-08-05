// =============================================================================
// NDAssetImage_DecodeUncompressedTgaRow
// -----------------------------------------------------------------------------
// Stable ID: aa_00434dd0
// Address:   0x00434dd0  (autoassault.exe, image base 0x400000)
// System:    gfx-asset / NDAssetImage / TGA
// Generated: 2026-07-29 W22-O dual seal (from raw + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Runtime / differential: OPEN.
//
// Purpose:  Decode one uncompressed TGA span into RGB8 dest.
//           bpp from header+0x10: 8 bulk, 15/16 RGB555 expand, 24 bulk*3,
//           32 per-pixel BGRA→RGB + FUN_00433280 alpha store.
//
// Convention:
//   ECX = stream* (vtbl+8 Read)
//   EDX = dest RGB*
//   stack (ret 0x14): image*, header*, count, y, x0
//
// Callers:
//   NDAssetImage_LoadTGA (0x004347d0)
//   FUN_00434b30 RLE raw-packet path
//
// Related:
//   FUN_00433280  alpha/plane store (32bpp only)
//   reviews/A|B_aa_00434dd0_NDAssetImage_DecodeUncompressedTgaRow.md
// =============================================================================

// Stream vtable Read at +8: int Read(void *buf, int size, int count=1)

void FUN_00433280(/* image in EAX, y in ESI, x in EDX/stack, a on stack — callee residual */);

void NDAssetImage_DecodeUncompressedTgaRow(
    int *stream /*ECX*/,
    char *dest /*EDX*/,
    int image /*[ebp+8]*/,
    int header /*[ebp+0xc]*/,
    int count /*[ebp+0x10]*/,
    int y /*[ebp+0x14]*/,
    int x0 /*[ebp+0x18]*/)
{
  // SEH frame LAB_009bccb0 omitted (exception path identity only)

  switch (*(unsigned char *)(header + 0x10)) {
  case 8: {
    int *vtbl = (int *)*stream;
    ((int (*)(int *, char *, int, int))vtbl[2])(stream, dest, count, 1);
    break;
  }
  case 0x0f:
  case 0x10: {
    for (int i = 0; i < count; ++i) {
      unsigned local_18 = 0;
      int *vtbl = (int *)*stream;
      ((int (*)(int *, unsigned *, int, int))vtbl[2])(stream, &local_18, 2, 1);
      // Bytes: R = (pix & 0x1f) << 3  (decompiler dropped &0x1f)
      *dest = (char)((local_18 & 0x1f) * 8);
      dest[1] = (char)((local_18 >> 2) & 0xf8);
      dest[2] = (char)((local_18 >> 7) & 0xf8);
      dest = dest + 3;
    }
    break;
  }
  case 0x18: {
    int *vtbl = (int *)*stream;
    ((int (*)(int *, char *, int, int))vtbl[2])(stream, dest, count * 3, 1);
    break;
  }
  case 0x20: {
    for (int i = 0; i < count; ++i) {
      char b, g, r;
      unsigned a;
      // stack-local 4-byte read (local_30..local_2d in decomp)
      char local_30, local_2f, local_2e;
      unsigned local_2d;
      int *vtbl = (int *)*stream;
      ((int (*)(int *, char *, int, int))vtbl[2])(stream, &local_30, 4, 1);
      b = local_30;
      g = local_2f;
      r = local_2e;
      a = local_2d;
      *dest = b;
      dest[1] = g;
      dest[2] = r;
      dest = dest + 3;
      // FUN_00433280(alpha); image/y/x passed in regs per call site
      (void)image;
      (void)y;
      (void)x0;
      (void)i;
      FUN_00433280(/* sealed call with a, image, x0+i, y */);
      (void)a;
    }
    break;
  }
  default:
    break;
  }
}
