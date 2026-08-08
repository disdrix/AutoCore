# Raw capture: FUN_005ebf00

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ebf00` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005ebf00` |
| **Canonical name** | `FUN_005ebf00` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_005ebf00(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = param_1[0x31];
  *param_1 = &PTR_FUN_009dce90;
  while (iVar1 = iVar1 + -1, -1 < iVar1) {
    (**(code **)(**(int **)(param_1[0x30] + iVar1 * 8) + 0x14))();
  }
  param_1[0x31] = 0;
  if (-1 < (int)param_1[0x32]) {
    (**(code **)(*DAT_00b05060 + 0x14))(param_1[0x30],param_1[0x32] * 8,0x12);
  }
  FUN_006343d0();
  return;
}
```

---

## R12-038 re-verify append (2026-08-05) — APPEND ONLY

**Agent:** OWN-ONLY dual **R12-038**  
**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + `get_function_callers` / `get_function_xrefs` / `get_xrefs_to` + `get_function_by_address`. **No** `disassemble_bytes`. **No** Launcher / runtime Confirmed.  
**Partition:** `WAVE_2026-08-05_r12_residual_partition_map.md` row R12-038; parent dual `0x005eb210`.  
**System:** interaction-activation.

### Live decompile (unchanged CF vs 2026-07-23 raw)

```c
void __fastcall FUN_005ebf00(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = param_1[0x31];
  *param_1 = &PTR_FUN_009dce90;
  while (iVar1 = iVar1 + -1, -1 < iVar1) {
    (**(code **)(**(int **)(param_1[0x30] + iVar1 * 8) + 0x14))();
  }
  param_1[0x31] = 0;
  if (-1 < (int)param_1[0x32]) {
    (**(code **)(*DAT_00b05060 + 0x14))(param_1[0x30],param_1[0x32] * 8,0x12);
  }
  FUN_006343d0();
  return;
}
```

### Body / bytes

| Item | Value |
|---|---|
| Entry | `0x005ebf00` |
| Last insn | `JMP 0x006343d0` @ `0x005ebf63` (bytes through `0x005ebf67`) |
| Inclusive range | `0x005ebf00`–`0x005ebf67` (**104 B** / `0x68`) |
| Pad | `CC` from `0x005ebf68` |
| Hex | `56 57 8B F9 8B B7 C4 00 00 00 83 EE 01 C7 07 90 CE 9D 00 78 16 8B 87 C0 00 00 00 8B 0C F0 8B 11 8D 04 F0 FF 52 14 83 EE 01 79 EA C7 87 C4 00 00 00 00 00 00 00 8B 87 C8 00 00 00 85 C0 78 20 8B 0D 60 50 B0 00 8B 11 25 FF FF FF 7F 03 C0 03 C0 6A 12 03 C0 50 8B 87 C0 00 00 00 50 FF 52 14 8B CF 5F 5E E9 68 84 04 00` |

### Assembly (disassemble_function — not disassemble_bytes)

```text
005ebf00  PUSH ESI
005ebf01  PUSH EDI
005ebf02  MOV  EDI,ECX                      ; this = sphere-query collect object*
005ebf04  MOV  ESI,dword ptr [EDI+0xc4]     ; count @ +0xC4
005ebf0a  SUB  ESI,0x1                      ; i = count-1
005ebf0d  MOV  dword ptr [EDI],0x9dce90     ; reinstall derived vtbl PTR_FUN_009dce90
005ebf13  JS   0x005ebf2b                   ; if i < 0, skip element loop
005ebf15  MOV  EAX,dword ptr [EDI+0xc0]     ; begin @ +0xC0
005ebf1b  MOV  ECX,dword ptr [EAX+ESI*0x8]  ; element[i].obj* (stride 8)
005ebf1e  MOV  EDX,dword ptr [ECX]          ; obj vtbl
005ebf20  LEA  EAX,[EAX+ESI*0x8]
005ebf23  CALL dword ptr [EDX+0x14]         ; vcall release slot +0x14
005ebf26  SUB  ESI,0x1
005ebf29  JNS  0x005ebf15                   ; loop while i >= 0
005ebf2b  MOV  dword ptr [EDI+0xc4],0x0     ; count = 0
005ebf35  MOV  EAX,dword ptr [EDI+0xc8]     ; capacity @ +0xC8
005ebf3b  TEST EAX,EAX
005ebf3d  JS   0x005ebf5f                   ; if capacity < 0 (empty sentinel 0x80000000), skip free
005ebf3f  MOV  ECX,dword ptr [0x00b05060]   ; allocator singleton
005ebf45  MOV  EDX,dword ptr [ECX]
005ebf47  AND  EAX,0x7fffffff               ; strip sign bit
005ebf4c  ADD  EAX,EAX                      ; *2
005ebf4e  ADD  EAX,EAX                      ; *4
005ebf50  PUSH 0x12                         ; pool tag 0x12
005ebf52  ADD  EAX,EAX                      ; *8 → size = (cap&0x7fffffff)*8
005ebf54  PUSH EAX
005ebf55  MOV  EAX,dword ptr [EDI+0xc0]
005ebf5b  PUSH EAX                          ; buffer begin
005ebf5c  CALL dword ptr [EDX+0x14]         ; allocator free
005ebf5f  MOV  ECX,EDI                      ; thiscall this for base dtor
005ebf61  POP  EDI
005ebf62  POP  ESI
005ebf63  JMP  0x006343d0                   ; tail to base dtor FUN_006343d0
```

### ABI seal

| Item | Evidence |
|---|---|
| Convention | **thiscall**: **ECX** = self (0xD0 sphere-query collect object*) |
| Stack args | **none** (no RET N; ends in JMP) |
| Return | via tail-jump into `FUN_006343d0` (base dtor returns to original caller) |
| Layout | collect triad **+0xC0 begin / +0xC4 count / +0xC8 capacity**; element stride **8** |
| Vtbl | reinstall derived `PTR_FUN_009dce90` (same as ctor `FUN_005ebec0`) |
| Free tag | buffer free tag **0x12**; whole-object free (scalar dtor peer) uses tag **0x2C** |

### Callees

| VA / target | Role |
|---|---|
| vcall `[obj->vtbl+0x14]` | per-element release on each collect entry |
| `(*DAT_00b05060)->vtbl[+0x14]` | allocator free for collect buffer |
| `0x006343d0` `FUN_006343d0` | base query-object dtor (tail JMP; residual) |

### Callers / xrefs (1 UNCONDITIONAL_CALL)

| Site | Enclosing | Role |
|---|---|---|
| `0x005ebf73` | `FUN_005ebf70` | scalar-deleting dtor: call this complete dtor, then if `(flags&1)` free object size `*(uint16*)(self+4)` tag `0x2C` |

### Vtbl / DATA xrefs for `009dce90`

| Site | Kind |
|---|---|
| `0x005ebecd` in `FUN_005ebec0` | DATA write (ctor installs) |
| `0x005ebf0d` in `FUN_005ebf00` | DATA write (dtor reinstalls) |

Vtbl slot 0 at `0x009dce90` = `0x005ebf70` (scalar-deleting dtor; evidence only, not OWN).

### Peers (evidence only; not dualled)

| VA | Role |
|---|---|
| `0x005ebec0` | dualed `VOGPhysics_SphereQueryCollect_Ctor_Inferred` (MEGA-070) |
| `0x005eb210` | dualed `VOGPhysics_QueryObject_BaseCtor_Inferred` (R11-008; partition parent) |
| `0x005ebf70` | scalar-deleting dtor residual |
| `0x006343d0` | base dtor residual |
| `0x005eb790` | sibling collect ctor (vtbl `009dce20`) residual |

### Proposed name

`VOGPhysics_SphereQueryCollect_Dtor_Inferred` — complete-object destructor for the dualed sphere-query collect type (vtbl `009dce90`, collect triad `+0xC0`). Product/PDB class English open → `_Inferred`.
