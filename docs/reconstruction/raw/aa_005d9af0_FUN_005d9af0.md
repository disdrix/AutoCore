# Raw capture: FUN_005d9af0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d9af0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005d9af0` |
| **Canonical name** | `FUN_005d9af0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_005d9af0(int param_1)



{

  int iVar1;

  void *pvVar2;

  undefined4 uVar3;

  int *in_stack_00000010;

  char in_stack_00000014;

  void *local_1c;

  undefined1 *puStack_18;

  int local_14;

  

  local_14 = 0xffffffff;

  puStack_18 = &LAB_009a71fa;

  local_1c = ExceptionList;

  if (in_stack_00000010 == (int *)0x0) {

    return;

  }

  ExceptionList = &local_1c;

  FUN_0076cf00();

  iVar1 = in_stack_00000010[0x2a];

  local_14 = 0;

  FUN_004eb3b0();

  if (*(int *)(iVar1 + 0x88) == 0) {

LAB_005d9b75:

    if (in_stack_00000014 == '\0') goto LAB_005d9e70;

    if (*(int *)(param_1 + 4) == 0) {

      pvVar2 = operator_new(8);

      local_14._0_1_ = 1;

      if (pvVar2 == (void *)0x0) {

        uVar3 = 0;

      }

      else {

        uVar3 = FUN_004a1620();

      }

      local_14 = (uint)local_14._1_3_ << 8;

      *(undefined4 *)(param_1 + 4) = uVar3;

      FUN_004a6390();

    }

    if ((*(int *)(param_1 + 4) == 0) || (iVar1 = FUN_004a16d0(), iVar1 == 0)) goto LAB_005d9e70;

  }

  else {

    FUN_004eb3b0();

    iVar1 = FUN_004a16d0();

    if (iVar1 == 0) goto LAB_005d9b75;

  }

  (**(code **)(*in_stack_00000010 + 0x1c8))();

  (**(code **)(*in_stack_00000010 + 0x1c8))();

  FUN_004b7550();

  FUN_004b7550();

  FUN_004b7550();

  (**(code **)(*in_stack_00000010 + 0xf8))();

  FUN_004b7e50(0,0,0);

LAB_005d9e70:

  local_14 = 0xffffffff;

  FUN_0076cef0();

  ExceptionList = local_1c;

  return;

}
```


---

## Live re-decompile (2026-07-29 W23-G)

| Field | Value |
|---|---|
| **Tool** | Ghidra MCP `decompile_function` + `analyze_function_complete` + `read_memory` |
| **Program** | `autoassault.exe` base `0x400000` |
| **Body** | `0x005d9af0`–`0x005d9e94` (**932 B** / `0x3A4`) |
| **Epilogue** | `C2 14 00` (`RET 0x14`) — **5** stack formals + ECX this |
| **Profiler string** | `"CollisionListener::PlayCollisionEffect"` @ `0x009db524` (`read_memory`) |
| **Callers (2)** | `FUN_005da0a0` (`Drive_CollisionListener_Contact`) site `0x005da895`; `FUN_005d9ea0` site `0x005da060` |
| **Integrity** | Live decompile ≡ 2026-07-23 raw body (identical CF); ABI residuals filled from bytes |

### Prologue (thiscall + SEH + null-check arg3)

```
55 8B EC 83 E4 F0 6A FF 68 FA 71 9A 00 64 A1 00 00 00 00 50 64 89 25 00 00 00 00
83 EC 48 53 56 57
8B 7D 14          ; edi = [ebp+0x14] = stack3 game object*
85 FF             ; test edi,edi
8B D9             ; ebx = ecx = this
0F 84 63 03 00 00 ; jz → early return (null go)
8B 0D 40 F0 D1 00
68 24 B5 9D 00    ; push "CollisionListener::PlayCollisionEffect"
89 4C 24 24
E8 ...            ; FUN_0076cf00 profiler enter
8B B7 A8 00 00 00 ; esi = [edi+0xa8]  (decompiler: go[0x2a] as int*)
```

### Epilogue

```
8B 4C 24 20
C7 44 24 5C FF FF FF FF
E8 ...            ; FUN_0076cef0 profiler leave
8B 4C 24 54
5F 5E 64 89 0D 00 00 00 00
5B 8B E5 5D
C2 14 00          ; RET 0x14
```

### Sealed ABI

```
// __thiscall RET 0x14
// ECX = CollisionListener* this  (lazy FxMaster* slot @ this+4)
// stack0 [ebp+8]  = float* vec3 source (movss ×3 from [arg0+0/+4/+8])
// stack1 [ebp+c]  = opaque intermediate (caller-supplied; residual name)
// stack2 [ebp+10] = opaque / float-capable slot (read as float in body math)
// stack3 [ebp+14] = game object* (NULL → early return, no profiler)
// stack4 [ebp+18] = char allowLazyFxMasterCreate (0 → skip create path)
// void return
void Drive_CollisionListener_PlayCollisionEffect(
    CollisionListener* this,
    float* vec3_a,
    uint32_t arg1,
    uint32_t arg2,
    int* gameObject,
    int8_t allowCreate);
```

### Sealed CF

```
if gameObject == null: return
scope("CollisionListener::PlayCollisionEffect")
clonebase = *(gameObject + 0xA8)          // int* index 0x2a
FUN_004eb3b0(clonebase-context)
if *(clonebase + 0x88) == 0:              // no prebound FX event
  LAB_create:
    if allowCreate == 0: goto leave
    if this->fxMaster(+4) == null:
      p = operator_new(8)
      this->fxMaster = p ? FxMasterCatalog_Ctor(p) : null
      FxMaster_LoadMasterFromXML(this->fxMaster)   // FUN_004a6390
    if !this->fxMaster || !FxMaster_LoadEventVariant(...): goto leave
else:
  FUN_004eb3b0 again
  if !FxMaster_LoadEventVariant(...): goto LAB_create
// Apply effect transforms:
go.vtbl+0x1C8() ×2                          // world/frame queries
// float pipeline using stack0 vec3, constants 2.0f @ a10e74, 1.0f @ a0f2a0
NDSpecialFX_SetParamFloat3ByKey ×3           // FUN_004b7550 keys 1,2,3
go.vtbl+0xF8(0, 1, fxCtx)                    // attach/play hook
FUN_004b7e50(0, 0, 0)                        // finalize/play
leave: profiler exit; return
```

### Sealed constants (`read_memory`)

| Symbol | VA | Bytes | Value |
|---|---|---|---|
| profiler name | `0x009db524` | ASCII | `CollisionListener::PlayCollisionEffect` |
| `_DAT_00a10e74` | `0x00a10e74` | `00 00 00 40` | **2.0f** (effect math scale) |
| `_DAT_00a0f2a0` | `0x00a0f2a0` | `00 00 80 3F` | **1.0f** |
| FxMaster blob | imm | — | `operator_new(8)` |
| SetParam keys | imm | — | **1, 2, 3** (push before FUN_004b7550) |

### Call-site contracts

**From `Drive_CollisionListener_Contact` @ `0x005da895`** (flag=1 create allowed):
```
// 5 stack pushes + ECX=listener (assembly); decompiler may under-count by 1
PlayCollisionEffect(listener, /*vec*/, /*…*/, gameObjectOrHost, 1)
```

**From `FUN_005d9ea0` @ `0x005da060`** (flag=0 no lazy create):
```
PlayCollisionEffect(listener, uVar1, *impact, hostAdj, 0)
```

### Decompiler residuals (filled)

| Residual | Seal |
|---|---|
| Ghidra sig `void __thiscall(int)` only | 5 stack formals + RET 0x14 |
| `FUN_0076cf00()` no string | push `0x009db524` → PlayCollisionEffect |
| `in_stack_00000010[0x2a]` | byte offset `go+0xA8` (clonebase*) |
| unused stack0/1/2 in old raw | stack0 is float[3]* used after FX resolve |
