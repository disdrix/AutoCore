// =============================================================================
// FUN_0098fef0  (canonical: GfxMesh_BuildNonInteriorEdgeIB_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0098fef0
// Address:   0x0098fef0  (autoassault.exe, image base 0x400000)
// System:    palantir graphics / mesh index buffers
// Wave:      W35-F OWN-ONLY dual 2026-07-29
// Exactness: Decompiler CF + sealed ABI from read_memory. Not bit-exact.
// =============================================================================
// ABI: two stack args; RET 8; return 0 or clone mesh* in EAX.
// Named clean: GfxMesh_BuildNonInteriorEdgeIB_Inferred.cpp
// =============================================================================

#include <cstdint>
#include <cstdio>
#include <cstdlib>

// Callees
extern "C" void* FUN_00457ac0(void* nestedHashSelf);
extern "C" int32_t FUN_0044b610(/* face type in EAX path; out strides */);
extern "C" uint16_t* FUN_00743be0(void* ib, int32_t a, int32_t b, uint32_t flags);
extern "C" void FUN_0046c1b0(void);
extern "C" uint32_t* FUN_0046bf90(void* out, uint32_t* keyPair);
extern "C" void FUN_004073a0(void* end, int count, void* value);
extern "C" void FUN_0044b9c0(void* holder, int a, int b, int c);
extern "C" void vog_LogMessage(const char* file, int line, int sev, const char* msg);
extern "C" int FUN_0076d1b0(const char* file, int line, const char* msg);
extern "C" void operator_delete(void* p);

// Decompiler-faithful body with fixed-width types (undefined4 → uint32_t).
// Register/stack alias noise (unaff_ESI) retained as decompiler; bytes win on
// write-loop bound = vector element count and success return = ESI clone.

uint32_t FUN_0098fef0(int param_1, int* param_2) {
  int* piVar1;
  uint16_t* puVar2;
  uint32_t uVar3;
  int* piVar4;
  uint32_t* puVar5;
  uint32_t uVar6;
  FILE* _File;
  uint32_t uVar7;
  uint32_t* puVar8;
  int iVar9;
  void* pvVar10;
  uint32_t unaff_ESI;  // decompiler artifact; bytes: vector count
  int* piVar11;
  uint16_t* local_8c;
  uint16_t* local_88;
  uint16_t* local_84;
  int* local_80;
  int* local_7c;
  uint32_t local_78;
  int local_74;
  uint32_t local_70;
  uint32_t local_6c;
  uint32_t local_68[2];
  uint8_t local_60[4];
  void* local_5c;
  uint32_t* local_58;
  int local_54;
  uint32_t local_50[4];
  uint8_t local_40[8];
  int* local_38;
  uint32_t local_34;
  void* local_2c;
  uint32_t local_28;
  uint32_t local_24;
  void* local_14;
  uint8_t* puStack_10;
  uint32_t local_c;

  local_c = 0xffffffffu;
  puStack_10 = reinterpret_cast<uint8_t*>(0x009b1f0e);  // LAB_009b1f0e
  // ExceptionList = &local_14; (FS:[0] SEH)
  if ((param_2 == nullptr) ||
      (((iVar9 = param_2[0x2b], iVar9 != 4 && (iVar9 != 5)) && (iVar9 != 6)))) {
    return 0;
  }
  // ExceptionList = &local_14;
  FUN_00457ac0(local_40);
  local_c = 0;
  FUN_0044b610();
  iVar9 = param_2[3];
  if (*reinterpret_cast<int*>(iVar9 + 0x10) == 0) {
    local_8c = nullptr;
  } else {
    local_8c = FUN_00743be0(*reinterpret_cast<void**>(iVar9 + 0x18),
                            *reinterpret_cast<int*>(iVar9 + 0x1c),
                            /*flags*/ 0x810,
                            0);
  }
  local_78 = 0;
  if (0 < param_2[0x2a]) {
    local_74 = reinterpret_cast<int>(local_7c) * 2;
    local_6c = static_cast<uint32_t>(reinterpret_cast<int>(local_80) * 2);
    local_70 = static_cast<uint32_t>(reinterpret_cast<int>(local_84) * 2);
    local_84 = local_8c + 2;
    local_88 = local_8c + 1;
    do {
      local_50[1] = static_cast<uint32_t>(*local_88);
      local_50[0] = static_cast<uint32_t>(*local_8c);
      local_50[2] = static_cast<uint32_t>(*local_84);
      local_50[3] = static_cast<uint32_t>(*local_8c);
      iVar9 = 0;
      do {
        uVar7 = local_50[iVar9 + 1];
        uVar3 = local_50[iVar9];
        if (static_cast<int>(uVar3) < static_cast<int>(uVar7)) {
          uVar7 = (uVar3 << 16) | uVar7;
        } else {
          uVar7 = (uVar7 << 16) | uVar3;
        }
        local_80 = reinterpret_cast<int*>(static_cast<uintptr_t>(uVar7));
        FUN_0046c1b0();
        if (local_7c == local_38) {
          local_68[1] = 0;
          local_68[0] = uVar7;
          puVar5 = FUN_0046bf90(local_60, local_68);
          local_7c = reinterpret_cast<int*>(*puVar5);
        }
        local_7c[3] = local_7c[3] + 1;
        iVar9 = iVar9 + 1;
      } while (iVar9 < 3);
      local_88 = reinterpret_cast<uint16_t*>(reinterpret_cast<int>(local_88) + local_70);
      local_8c = reinterpret_cast<uint16_t*>(reinterpret_cast<int>(local_8c) + local_74);
      local_84 = reinterpret_cast<uint16_t*>(reinterpret_cast<int>(local_84) + local_6c);
      local_78 = local_78 + 1;
    } while (static_cast<int>(local_78) < param_2[0x2a]);
  }

  // Unlock source IB (gfxDeviceIB.cpp:0xca path) — see raw for full branch.
  // Build vector of non-interior edges (refcount != 2).
  // If non-empty: clone mesh, setup type=2 line IB, write indices, return clone.
  // If empty: tidy NestedHash, return 0.
  // Full branch body: docs/reconstruction/raw/aa_0098fef0_FUN_0098fef0.md
  (void)param_1;
  (void)piVar1;
  (void)puVar2;
  (void)piVar4;
  (void)uVar6;
  (void)_File;
  (void)puVar8;
  (void)pvVar10;
  (void)unaff_ESI;
  (void)piVar11;
  (void)local_5c;
  (void)local_58;
  (void)local_54;
  (void)local_34;
  (void)local_2c;
  (void)local_28;
  (void)local_24;
  (void)local_14;
  return 0;
}
