# Raw capture: FUN_0098fef0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0098fef0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0098fef0` |
| **Canonical name** | `FUN_0098fef0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 FUN_0098fef0(int param_1,int *param_2)

{
  int *piVar1;
  ushort *puVar2;
  uint uVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  FILE *_File;
  uint uVar7;
  uint *puVar8;
  int iVar9;
  void *pvVar10;
  uint unaff_ESI;
  int *piVar11;
  ushort *local_8c;
  ushort *local_88;
  ushort *local_84;
  int *local_80;
  int *local_7c;
  uint local_78;
  int local_74;
  uint local_70;
  uint local_6c;
  uint local_68 [2];
  undefined1 local_60 [4];
  void *local_5c;
  uint *local_58;
  int local_54;
  uint local_50 [4];
  undefined1 local_40 [8];
  int *local_38;
  undefined4 local_34;
  void *local_2c;
  undefined4 local_28;
  undefined4 local_24;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_009b1f0e;
  local_14 = ExceptionList;
  if ((param_2 == (int *)0x0) ||
     (((iVar9 = param_2[0x2b], iVar9 != 4 && (iVar9 != 5)) && (iVar9 != 6)))) {
    return 0;
  }
  ExceptionList = &local_14;
  FUN_00457ac0(local_40);
  local_c = 0;
  FUN_0044b610();
  iVar9 = param_2[3];
  if (*(int *)(iVar9 + 0x10) == 0) {
    local_8c = (ushort *)0x0;
  }
  else {
    local_8c = (ushort *)
               FUN_00743be0(*(undefined4 *)(iVar9 + 0x18),*(undefined4 *)(iVar9 + 0x1c),0x810);
  }
  local_78 = 0;
  if (0 < param_2[0x2a]) {
    local_74 = (int)local_7c * 2;
    local_6c = (int)local_80 * 2;
    local_70 = (int)local_84 * 2;
    local_84 = local_8c + 2;
    local_88 = local_8c + 1;
    do {
      local_50[1] = (uint)*local_88;
      local_50[0] = (uint)*local_8c;
      local_50[2] = (uint)*local_84;
      local_50[3] = (uint)*local_8c;
      iVar9 = 0;
      do {
        uVar7 = local_50[iVar9 + 1];
        uVar3 = local_50[iVar9];
        if ((int)uVar3 < (int)uVar7) {
          uVar7 = uVar3 << 0x10 | uVar7;
        }
        else {
          uVar7 = uVar7 << 0x10 | uVar3;
        }
        local_80 = (int *)uVar7;
        FUN_0046c1b0();
        if (local_7c == local_38) {
          local_68[1] = 0;
          local_68[0] = uVar7;
          puVar5 = (undefined4 *)FUN_0046bf90(local_60,local_68);
          local_7c = (int *)*puVar5;
        }
        local_7c[3] = local_7c[3] + 1;
        iVar9 = iVar9 + 1;
      } while (iVar9 < 3);
      local_88 = (ushort *)((int)local_88 + local_70);
      local_8c = (ushort *)((int)local_8c + local_74);
      local_84 = (ushort *)((int)local_84 + local_6c);
      local_78 = local_78 + 1;
    } while ((int)local_78 < param_2[0x2a]);
  }
  piVar11 = *(int **)(param_2[3] + 0x10);
  pvVar10 = (void *)0x0;
  if ((piVar11 != (int *)0x0) && (piVar4 = (int *)*piVar11, piVar4 != (int *)0x0)) {
    piVar1 = piVar11 + 3;
    *piVar1 = *piVar1 + -1;
    if (*piVar1 < 0) {
      vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDeviceIB.cpp",0xca,1,
                     "Call to gfxDeviceIB::Unlock more times than locked! Bad mojo...");
      piVar11[3] = 0;
    }
    else {
      (**(code **)(*piVar4 + 0x30))(piVar4);
    }
  }
  puVar8 = (uint *)0x0;
  local_5c = (void *)0x0;
  local_58 = (uint *)0x0;
  local_54 = 0;
  local_c = CONCAT31(local_c._1_3_,1);
  piVar11 = (int *)*local_38;
  if (piVar11 != local_38) {
    do {
      if (piVar11[3] != 2) {
        local_6c = (uint)piVar11[2] >> 0x10;
        local_78 = piVar11[2] & 0xffff;
        if ((pvVar10 == (void *)0x0) ||
           ((uint)(local_54 - (int)pvVar10 >> 2) <= (uint)((int)puVar8 - (int)pvVar10 >> 2))) {
          FUN_004073a0(puVar8,1,&local_6c);
          pvVar10 = local_5c;
        }
        else {
          *puVar8 = local_6c;
          local_58 = puVar8 + 1;
        }
        if ((pvVar10 == (void *)0x0) ||
           ((uint)(local_54 - (int)pvVar10 >> 2) <= (uint)((int)local_58 - (int)pvVar10 >> 2))) {
          FUN_004073a0(local_58,1,&local_78);
          puVar8 = local_58;
          pvVar10 = local_5c;
        }
        else {
          *local_58 = local_78;
          local_58 = local_58 + 1;
          puVar8 = local_58;
        }
      }
      piVar11 = (int *)*piVar11;
    } while (piVar11 != local_38);
    if (pvVar10 != (void *)0x0) {
      local_7c = (int *)((int)puVar8 - (int)pvVar10 >> 2);
      if (local_7c == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
        operator_delete(pvVar10);
      }
      puVar8 = (uint *)(**(code **)(*param_2 + 0x7c))();
      local_6c = *puVar8;
      uVar6 = (**(code **)(*param_2 + 0x28))();
      (**(code **)(local_6c + 0x24))(uVar6);
      if (((param_2[0x16] != 0) && (param_2[0x17] != 0)) &&
         (*(int *)(param_2[0x17] + 0x1c) != param_2[0x18])) {
        (**(code **)(*param_2 + 0x80))();
      }
      puVar8[0x19] = param_2[0x19];
      local_70 = *puVar8;
      uVar6 = (**(code **)(*param_2 + 0x2c))();
      (**(code **)(local_70 + 0x34))(uVar6);
      local_80 = *(int **)(param_1 + 0x28);
      if ((local_80 != (int *)0x0) && (local_80[1] = local_80[1] + 1, local_80[1] == 1)) {
        (**(code **)(*local_80 + 4))();
      }
      piVar11 = (int *)puVar8[8];
      if (piVar11 != (int *)0x0) {
        piVar4 = piVar11 + 1;
        *piVar4 = *piVar4 + -1;
        if (*piVar4 == 0) {
          (**(code **)(*piVar11 + 8))();
        }
      }
      puVar8[8] = (uint)local_80;
      *(undefined1 *)(puVar8 + 9) = *(undefined1 *)(param_1 + 0x2c);
      *(undefined1 *)((int)puVar8 + 0x25) = *(undefined1 *)(param_1 + 0x2d);
      *(undefined1 *)((int)puVar8 + 0x26) = *(undefined1 *)(param_1 + 0x2e);
      (**(code **)(*puVar8 + 0x74))();
      puVar8[0x2b] = 2;
      puVar8[0x2f] = puVar8[0x2f] | 0x20;
      puVar8[0x2a] = (int)local_84 / 2;
      FUN_0044b9c0(local_84,0x20,0,0);
      uVar7 = puVar8[3];
      piVar11 = *(int **)(uVar7 + 0x10);
      if (piVar11 == (int *)0x0) {
        local_84 = (ushort *)0x0;
      }
      else {
        local_84 = (ushort *)0x0;
        if ((int *)*piVar11 != (int *)0x0) {
          local_84 = *(ushort **)(uVar7 + 0x18);
          iVar9 = (**(code **)(*(int *)*piVar11 + 0x2c))
                            (*piVar11,(int)*(ushort **)(uVar7 + 0x18) * piVar11[4],
                             *(int *)(uVar7 + 0x1c) * piVar11[4],&local_84,0x800);
          if (iVar9 < 0) {
            local_84 = (ushort *)0x0;
          }
          else {
            piVar11[3] = piVar11[3] + 1;
          }
        }
      }
      for (uVar7 = 0; uVar7 < unaff_ESI; uVar7 = uVar7 + 1) {
        *local_84 = *(ushort *)((int)pvVar10 + uVar7 * 4);
        local_84 = local_84 + 1;
      }
      local_84 = *(ushort **)(puVar8[3] + 0x10);
      if ((local_84 != (ushort *)0x0) && (piVar11 = *(int **)local_84, piVar11 != (int *)0x0)) {
        puVar2 = local_84 + 6;
        *(int *)puVar2 = *(int *)puVar2 + -1;
        if (*(int *)puVar2 < 0) {
          iVar9 = FUN_0076d1b0("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDeviceIB.cpp",0xca
                               ,"Call to gfxDeviceIB::Unlock more times than locked! Bad mojo...");
          if (iVar9 == 3) {
            _File = fopen("c:\\VOGCRASH.txt","w");
            if (_File != (FILE *)0x0) {
              fprintf(_File,"errReport::Massive failure EH_Abort: F:%s l:%d s:%d d:%s\n",
                      "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDeviceIB.cpp",0xca,1,
                      "Call to gfxDeviceIB::Unlock more times than locked! Bad mojo...");
              fclose(_File);
            }
            raise(0x16);
                    /* WARNING: Subroutine does not return */
            ExitProcess(3);
          }
          local_84[6] = 0;
          local_84[7] = 0;
        }
        else {
          (**(code **)(*piVar11 + 0x30))(piVar11);
        }
      }
                    /* WARNING: Subroutine does not return */
      operator_delete(pvVar10);
    }
  }
  if (local_2c != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    operator_delete(local_2c);
  }
  local_2c = (void *)0x0;
  local_28 = 0;
  local_24 = 0;
  piVar11 = (int *)*local_38;
  *local_38 = (int)local_38;
  local_38[1] = (int)local_38;
  local_34 = 0;
  if (piVar11 == local_38) {
                    /* WARNING: Subroutine does not return */
    operator_delete(local_38);
  }
                    /* WARNING: Subroutine does not return */
  operator_delete(piVar11);
}
```

## W35-F re-verify (2026-07-29 OWN-ONLY dual)

**Tools:** live `decompile_function` / `batch_decompile` + `read_memory` + `analyze_function_complete` + callee decompile. **No** `disassemble_bytes`.

### Body / ABI (bytes win)

| Item | Fact |
|---|---|
| Ghidra body | `0x0098fef0`–`0x0099042a` (catalog) |
| Byte-confirmed epilogue | success path ends `MOV EAX,ESI; ...; RET 8` then `CC` near `0x0099049c`–`0x0099049e` (Ghidra body range truncates tail of success cleanup) |
| Prologue | `PUSH EBP; MOV EBP,ESP; AND ESP,-8; SEH push LAB_009b1f0e; SUB ESP,0x78; PUSH EBX/ESI/EDI; MOV EDI,[EBP+0xC]` |
| Fail epilogue @ `0x0099020f` | `XOR EAX,EAX; restore FS:[0]; POP EDI/ESI/EBX; MOV ESP,EBP; POP EBP; RET 8` |
| Success epilogue | `MOV EAX,ESI` (clone mesh*) then same frame teardown + **RET 8** |
| Args | stack `param_1` @ `[EBP+8]`, `param_2` @ `[EBP+0xC]` — **stdcall-ish RET 8** (two dwords). Not ECX-thiscall. |

### Semantics (sealed structural)

1. Gate: `param_2==0` OR face type `param_2[0x2b]` not in `{4,5,6}` → return **0**.
2. Placement-ctor NestedHash bag: `FUN_00457ac0(local)` = W34-E `NestedHash_Ctor_Sentinel0x10_Inferred`.
3. `FUN_0044b610` = `GetTriangleVertexSteps` (gfxFirst.h string) → three per-vertex index strides for face type.
4. Lock source IB: `FUN_00743be0` / gfxDeviceIB::Lock flags **0x810** using device wrapper at `param_2[3]`.
5. For each face `0..param_2[0x2a)`: read 3 u16 indices; for each of 3 undirected edges pack `min<<16|max` (or swapped); NestedHash find (`FUN_0046c1b0`) / insert (`FUN_0046bf90`); **refcount++** at node+0x0c.
6. Unlock source IB (gfxDeviceIB.cpp:0xca unlock string path).
7. Walk NestedHash nodes; for nodes with **refcount != 2**, push both u16 halves into a growable `uint32` vector (`FUN_004073a0`).
8. If vector empty: tidy NestedHash / temps, return **0**.
9. Else: `param_2->vtbl+0x7c` clone mesh into ESI; copy material/stream fields via vtbl+0x28/+0x2c/+0x80; attach `param_1+0x28` refcounted slot to clone+0x20; copy 3 bytes from `param_1+0x2c..+0x2e`; vtbl+0x74; set clone face-type **2**, flags `\|0x20`, face count = index count; `FUN_0044b9c0` device IB setup; lock dest IB flags **0x800**; write u16 indices from vector; unlock (full EH_Abort path on over-unlock); free vector; tidy NestedHash; **return clone (ESI)**.

### Callers / callees

- **Static xrefs:** **0** (likely vtable / indirect only).
- **Callees:** `FUN_00457ac0`, `FUN_0044b610`, `FUN_00743be0`, `FUN_0046c1b0`, `FUN_0046bf90`, `FUN_004073a0`, `FUN_0044b9c0`, `vog_LogMessage` / `FUN_0076d1b0`, CRT I/O abort path, `operator_delete`.

### Name

`GfxMesh_BuildNonInteriorEdgeIB_Inferred` — **reject** scaffold `Named_gfxDeviceIB_0098fef0` (string is unlock path, not product name).

### Decompile caveats

- Decompiler marks `operator_delete` as noreturn and invents `unaff_ESI` on write loop — **bytes win**: write loop count is vector element count; success returns ESI clone; both exits use **RET 8**.
- Mid-function fail epilogue at `0x0099020f` sits before success clone path at `0x00990228` (jnz over empty-return).

