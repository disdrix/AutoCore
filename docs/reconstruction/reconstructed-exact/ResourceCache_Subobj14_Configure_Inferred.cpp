// =============================================================================
// ResourceCache_Subobj14_Configure_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00996d70
// Address:   0x00996d70  (autoassault.exe, image base 0x400000)
// System:    ResourceCache / embedded configure subobject
// Generated: 2026-08-04 W37-V dual seal (live decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler CF + byte register formals.
// Bit-for-bit vs retail EXE: DEFERRED (no Launcher).
// =============================================================================

// PURPOSE: Reconfigure ResourceCache embedded subobject (typically host+0x14):
//   clear list @+0x2C, reset vector @+0x38 with arg 9, set +0x48/+0x4C = 1,
//   free aligned buffer state, store flag @+0x50, realloc buffer (align 4).
// ABI: EAX=subobj, EBX=size (implicit), stack flag byte, RET 4, void.
// Parents: ResourceCache_SetField10AndConfigure (W31-F), FUN_00989d50 reset.

#include <cstdint>

// Unowned callees — register formals as sealed by their own duals/bytes.
extern "C" void FUN_00415e90(void);               // ESI = list shell*
extern "C" void __thiscall FUN_00449a90(void *vec /*ECX*/, uint32_t arg /*stack*/);
extern "C" void FUN_009899a0(void);               // EDI = buffer host*
extern "C" bool __thiscall FUN_00989b00(void *this_ /*ECX*/, uint8_t flag /*stack*/);
// FUN_00989b00 also: EAX=alignment, EBX=size

extern "C" void ResourceCache_Subobj14_Configure_Inferred(
    void *subobj /*EAX*/,
    uint32_t /*size_EBX*/,
    uint8_t flag /*stack*/)
{
  // Retail: MOV EDI,EAX; LEA ESI,[EDI+0x2C]
  // FUN_00415e90();
  // save *(EDI+0x30); PUSH 9; LEA ECX,[EDI+0x38]; FUN_00449a90(9);
  // *(EDI+0x48)=1; *(EDI+0x4C)=1;
  // FUN_009899a0();  // EDI formal
  // *(uint8_t*)(EDI+0x50) = flag;
  // PUSH 1; EAX=4; ECX=EDI; FUN_00989b00(1); // EBX size, EAX align
  // RET 4

  // Control-flow-faithful skeleton (register setup omitted as C locals):
  char *base = (char *)subobj;
  // ClearList at base+0x2C via FUN_00415e90 (ESI)
  FUN_00415e90();
  FUN_00449a90(base + 0x38, 9);
  *(uint32_t *)(base + 0x48) = 1;
  *(uint32_t *)(base + 0x4c) = 1;
  FUN_009899a0();
  *(uint8_t *)(base + 0x50) = flag;
  // Align 4 + size in EBX applied inside FUN_00989b00 (bytes)
  (void)FUN_00989b00(subobj, 1);
}

extern "C" void FUN_00996d70(uint8_t flag)
{
  // Ghidra surface: stack flag only; EAX/EBX are live register formals.
  // Callers must set EAX=subobj and EBX=size before entry.
  ResourceCache_Subobj14_Configure_Inferred(/*EAX*/ nullptr, /*EBX*/ 0, flag);
}
