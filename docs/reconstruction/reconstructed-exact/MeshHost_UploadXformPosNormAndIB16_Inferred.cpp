// =============================================================================
// MeshHost_UploadXformPosNormAndIB16_Inferred  (FUN_00634c50)
// -----------------------------------------------------------------------------
// Stable ID: aa_00634c50
// Address:   0x00634c50–0x00634df8 exclusive (424 B / 0x1A8)
// Module:    autoassault.exe @ 0x400000
// Dual:      WQ9J-D 2026-08-05 — accept-with-gaps
// Exactness: Behavior-preserving from live decompile + read_memory + call sites.
// Runtime Confirmed: not claimed (no Launcher).
// =============================================================================
//
// PURPOSE: Transform host source pos/nrm by owner xform into locked VB, then pack
// u32 indices → u16 IB. Sole caller CVOGObject_Tick multi-host loop (+0x1c4).
//
// ABI: void __fastcall(ECX = MeshUploadHost*); RET.

#include <cstdint>

// Callees (not OWN)
void*  __thiscall FUN_00414ae0(void* self, int start, int count, int flags);
uint32_t __fastcall FUN_0044bcc0(void* self);
void*  __fastcall FUN_00437960(void* owner);
void*  __thiscall FUN_00416240(void* dest, const void* src); // FieldBlock_CopyFrom_ClearFlags0xBC
void*  __thiscall FUN_007468e0(void* decl, char usage, char usage_index);
void*  __thiscall FUN_009732d0(void* xform, const void* src_vec3);
void*  __thiscall FUN_00973240(void* xform, const void* src_vec3);
void   __fastcall FUN_007464e0(void* vb_device);
void*  __thiscall FUN_0044ba40(void* self, int start, int count, int flags);
void   __fastcall FUN_00743ba0(void* ib_device);

void __fastcall MeshHost_UploadXformPosNormAndIB16_Inferred(int host)
{
  // Gate: +0x18,+0x20,+0x10,+0x14,+0x1c all non-zero
  if (*(int*)(host + 0x18) == 0) return;
  if (*(int*)(host + 0x20) == 0) return;
  if (*(int*)(host + 0x10) == 0) return;
  if (*(int*)(host + 0x14) == 0) return;
  if (*(int*)(host + 0x1c) == 0) return;

  int owner = *(int*)(host + 0x0c);
  *(unsigned*)(owner + 0xbc) |= 1u;

  int owner_saved = owner; // iVar2 / iVar9 split in decompile
  // VB lock this = owner+0x10; decl ESI = *(owner+0x14)+0x24; IB this later = owner+8
  int decl = *(int*)(owner + 0x14) + 0x24;
  int ib_this = owner + 8;

  void* locked = FUN_00414ae0((void*)(owner + 0x10), 0, *(int*)(host + 0x18), 0);
  if (locked) {
    // stride: FUN_0044bcc0 on path established at call site
    unsigned stride = FUN_0044bcc0(/*ECX from live site*/ (void*)*(int*)(host + 0x0c));
    (void)stride;

    // Live: MOV ECX,[ESP+14]; CALL 0044bcc0 — store stride; then:
    // MOV ECX,[EDI+0xC]; CALL 00437960; PUSH EAX; LEA ECX,temp; CALL 00416240
    alignas(16) unsigned char temp[0xC0];
    void* xsrc = FUN_00437960((void*)owner_saved);
    FUN_00416240(temp, xsrc);

    void* pos_el = FUN_007468e0((void*)decl, 0, 0);
    void* nrm_el = FUN_007468e0((void*)decl, 3, 0);
    unsigned pos_off = pos_el ? *(unsigned short*)((char*)pos_el + 2) : 0;
    unsigned nrm_off = nrm_el ? *(unsigned short*)((char*)nrm_el + 2) : 0;

    unsigned char* vb = (unsigned char*)locked;
    int src_off = 0;
    unsigned i = 0;
    unsigned nvert = *(unsigned*)(host + 0x18);
    // Re-fetch stride from live (iVar4)
    int stride_i = (int)FUN_0044bcc0((void*)owner_saved);
    for (; i < nvert; ++i) {
      void* rp = FUN_009732d0(temp, (void*)(*(int*)(host + 0x10) + src_off));
      int* dp = (int*)(vb + pos_off);
      dp[0] = ((int*)rp)[0]; dp[1] = ((int*)rp)[1]; dp[2] = ((int*)rp)[2];

      void* rn = FUN_00973240(temp, (void*)(*(int*)(host + 0x14) + src_off));
      int* dn = (int*)(vb + nrm_off);
      dn[0] = ((int*)rn)[0]; dn[1] = ((int*)rn)[1]; dn[2] = ((int*)rn)[2];

      vb += stride_i;
      src_off += 0x0c;
    }

    // Unlock VB if *( *(owner+0x14) + 0x10 ) != 0
    int vb_dev = *(int*)(*(int*)(owner_saved + 0x14) + 0x10);
    if (vb_dev != 0) {
      FUN_007464e0((void*)*(int*)(owner_saved + 0x14) /* device object path */);
    }
  }

  void* ib = FUN_0044ba40((void*)ib_this, 0, *(int*)(host + 0x20), 0x800);
  if (ib) {
    unsigned ni = *(unsigned*)(host + 0x20);
    for (unsigned u = 0; u < ni; ++u) {
      ((unsigned short*)ib)[u] =
          (unsigned short)((unsigned*)(*(int*)(host + 0x1c)))[u];
    }
    // Unlock IB if device at *( *(owner+0xc)+0x10 ) path non-null
    // Live uses saved owner (iVar2) +0xc then +0x10
    int ib_side = *(int*)(owner_saved + 0x0c);
    if (ib_side && *(int*)(ib_side + 0x10) != 0) {
      FUN_00743ba0((void*)ib_side);
    }
  }
}

// Ghidra export name
void __fastcall FUN_00634c50(int param_1)
{
  MeshHost_UploadXformPosNormAndIB16_Inferred(param_1);
}
