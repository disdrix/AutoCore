# Raw capture: FUN_004be2a0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004be2a0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004be2a0` |
| **Canonical name** | `FUN_004be2a0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_004be2a0(int *param_1)

{
  void *pvVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009a1833;
  local_c = ExceptionList;
  local_4 = 9;
  ExceptionList = &local_c;
  if ((char)param_1[0x174] != '\0') {
    ExceptionList = &local_c;
    param_1[6] = param_1[5];
    if (param_1[6] != 0) {
      pvVar1 = *(void **)(param_1[6] + 0xc);
      if ((*(int *)((int)pvVar1 + 4) != 0) &&
         (*(int *)(*(int *)(*(int *)(*(int *)(*(int *)((int)pvVar1 + 4) + 4) + 4) + 0xac +
                           *(int *)((int)pvVar1 + 4)) + 0x38) == 1)) {
        (**(code **)(**(int **)((int)pvVar1 + 4) + 8))();
      }
                    /* WARNING: Subroutine does not return */
      operator_delete(pvVar1);
    }
    FUN_004bf740();
  }
  DAT_00b03734 = DAT_00b03734 + -1;
  *(int *)(*param_1 + 4) = param_1[1];
  *(int *)param_1[1] = *param_1;
  pvVar1 = DAT_00b03730;
  DAT_00b0373c = DAT_00b0373c + -1;
  if (DAT_00b0373c == 0) {
    if (DAT_00b03730 != (void *)0x0) {
      FUN_004be2a0();
                    /* WARNING: Subroutine does not return */
      operator_delete(pvVar1);
    }
    DAT_00b03730 = (void *)0x0;
  }
  else if (DAT_00b0373c < 0) {
    DAT_00b0373c = 0;
  }
  if ((void *)param_1[0x163] != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    operator_delete((void *)param_1[0x163]);
  }
  param_1[0x163] = 0;
  param_1[0x164] = 0;
  param_1[0x165] = 0;
  if ((void *)param_1[0x15f] != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    operator_delete((void *)param_1[0x15f]);
  }
  param_1[0x15f] = 0;
  param_1[0x160] = 0;
  param_1[0x161] = 0;
  local_4._0_1_ = 6;
  FUN_0074b580();
  local_4._0_1_ = 5;
  FUN_0074b580();
  local_4._0_1_ = 4;
  FUN_0074b580();
  local_4._0_1_ = 3;
  FUN_00763f60();
  local_4._0_1_ = 2;
  FUN_00763f60();
  local_4 = CONCAT31(local_4._1_3_,1);
  FUN_00763f60();
  param_1[8] = (int)&PTR_LAB_009cb5cc;
  param_1[4] = (int)&PTR_LAB_009cb5cc;
  ExceptionList = local_c;
  return;
}
```

---

## W30-P re-verify (2026-07-29) — append only

| Field | Value |
|---|---|
| **Tools** | `decompile_function` + `analyze_function_complete` + `read_memory` + xrefs. **No** `disassemble_bytes` |
| **Live decompile** | ≡ raw CF for high-level stages; Ghidra false-noreturn on `operator_delete` does **not** cut epilogue (bytes reach SEH restore + `C3`) |
| **Body** | `0x004be2a0`–`0x004be43c` exclusive end (**412 B** / `0x19C`); pad `CC`; next fn starts `83 EC 2C` |
| **ABI** | ECX=`this` (`__thiscall` / Ghidra `__fastcall`); SEH `LAB_009a1833`; EH state starts **9**; epilogue `ADD ESP,0x10; RET` (bare `C3`); void complete dtor (does **not** free `this`) |
| **Callees** | `operator_delete`, `FUN_004bf740`, self, `FUN_0074b580`×3, `FUN_00763f60`×3 |
| **Callers** | `FUN_00494700`, `FUN_00494530`, `FUN_00497a30`, `FUN_005b8000` (Elem0x28 owned@+0x24), self (global singleton teardown) |
| **Classification** | worker (complete dtor body) |

### Full body hex (412 B)

```
6aff6833189a0064a10000000050648925000000005153568bf1578974240c33db389ed0050000c74424180900000074568b4614558d6e108945088b46183bc3743d8b780c395f04741e8b47048b48048b51048b8402ac0000008378380175088b4f048b11ff520857e814b5fcff8b450883c4043bc374078b40043bc375b98bcde81a1400005db80100000029053437b0008b0e8b56048951048b4e048b16891129053c37b00075228b0d3037b0003bcb74108bf9e846ffffff57e8c2b4fcff83c404891d3037b000eb0e391d3c37b0007d06891d3c37b0008b868c0500003bc3740950e899b4fcff83c404899e8c050000899e90050000899e940500008b867c0500003bc3740950e874b4fcff83c4048d8e74040000899e7c050000899e80050000899e84050000c644241806e8add128008d8e44040000c644241805e89dd128008d8e14040000c644241804e88dd128008d8ec8020000c644241803e85d5b2a008d8e7c010000c644241802e84d5b2a008d4e30c644241801e8405b2a008b4c2410b8ccb59c005f8946208946105e5b64890d0000000083c410c3
```

### Byte-sealed stages

1. **SEH prolog** + EH state **9**; `ESI=this`; `EBX=0`.
2. **If flag** `*(char*)(this+0x5D0)` (`param_1[0x174]`): walk/cleanup list region around `this+0x10`/`+0x14`/`+0x18` (optional vtbl[+8] call + `operator_delete` on nested blobs), then `FUN_004bf740(this+0x10)`.
3. **`DAT_00b03734--`**; **intrusive DLL unlink** via `this+0` / `this+4` (prev/next).
4. **`DAT_00b0373c--`**; if zero and `DAT_00b03730 != 0`: recursive `FUN_004be2a0(DAT_00b03730)` + `operator_delete` + null global; if count &lt; 0 clamp to 0.
5. **Free vector storage** begin@`+0x58C` (zero begin/end/cap `+0x58C/+0x590/+0x594`).
6. **Free vector storage** begin@`+0x57C` (zero `+0x57C/+0x580/+0x584`).
7. **Member dtors** (EH states 6→1):  
   - `FUN_0074b580` @ `+0x474`, `+0x444`, `+0x414` (callee body is empty RET — no-op dtor stub)  
   - `FUN_00763f60` @ `+0x2C8`, `+0x17C`, `+0x30`
8. **Install base vtbl** `PTR_LAB_009cb5cc` at `this+0x20` and `this+0x10`.
9. SEH restore; `ADD ESP,0x10; RET`.

### Layout (sealed offsets)

| Offset | Role |
|---|---|
| `+0x00` / `+0x04` | intrusive list prev/next |
| `+0x10` / `+0x20` | dual subobject vptrs → set to `PTR_LAB_009cb5cc` at end |
| `+0x30`, `+0x17C`, `+0x2C8` | members destroyed via `FUN_00763f60` |
| `+0x414`, `+0x444`, `+0x474` | members via `FUN_0074b580` (no-op) |
| `+0x57C..+0x584` | buffer triple (begin/end/cap) |
| `+0x58C..+0x594` | buffer triple (begin/end/cap) |
| `+0x5D0` | char flag gating list cleanup |

### Globals

| VA | Role |
|---|---|
| `DAT_00b03734` | live-count style counter (`--`) |
| `DAT_00b0373c` | peer count; 0 → tear down `DAT_00b03730` |
| `DAT_00b03730` | optional global instance of same type |

### Decompile gaps

1. False noreturn on all `operator_delete` — bytes fall through.
2. Flag-gated list walk has more structure than single-delete decompiler view (loop back `75 B9`).
3. Product class English open; nearby rdata `"BuildGlom"` at `0x009cb5d8` is **not** sealed as class plate without further chain proof.
