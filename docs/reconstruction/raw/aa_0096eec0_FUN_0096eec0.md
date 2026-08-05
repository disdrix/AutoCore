# Raw capture: FUN_0096eec0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0096eec0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0096eec0` |
| **Canonical name** | `FUN_0096eec0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0096eec0(int param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009b1316;
  local_c = ExceptionList;
  DAT_00d1f04c = param_1;
  local_4 = 0;
  ExceptionList = &local_c;
  FUN_0043fdf0(param_1);
  local_4 = CONCAT31(local_4._1_3_,1);
  uVar1 = _DAT_00d1f7e8 & 1;
  *(undefined1 *)(param_1 + 0x28) = 1;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  if (uVar1 == 0) {
    _DAT_00d1f7e8 = _DAT_00d1f7e8 | 1;
    _DAT_00d1f7e4 = &PTR_FUN_00a9ef54;
    _atexit((_func_4879 *)&LAB_009c3370);
  }
  puVar2 = (undefined4 *)FUN_0043bd40();
  *puVar2 = &LAB_0096ed30;
  puVar2[1] = 0;
  ExceptionList = local_c;
  return param_1;
}
```
---

## W35-S append (2026-07-29) — dual seal

| Field | Value |
|---|---|
| **Wave** | W35-S OWN-ONLY dual |
| **Tools** | `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + xrefs + caller/callee decompile. **No** `disassemble_bytes` |
| **Body** | `0x0096eec0`–`0x0096ef6a` exclusive (**170 B** / `0xAA`); pad `CC` |
| **ABI** | stack `self*`; **`RET 4`** (`C2 04 00`); returns **self in EAX**. Not ECX-thiscall |
| **Size** | sole caller `operator_new(0x34)` then this → host object **0x34** |
| **Classification** | worker |
| **Caller (1)** | `FUN_0075f7f0` @ `0x0075fa2f` — `param_2[0x1d5] = FUN_0096eec0(new(0x34))` |
| **Callees** | `FUN_0043fdf0` (`NestedHash_Ctor_Sentinel0xC_Inferred`, W34-F); `_atexit`; `FUN_0043bd40` (map find/insert value slot) |
| **Name** | `Host34_NestedHash0xC_Singleton_Ctor_Inferred` — **reject** scaffold `Named_CalleeOf_*` |
| **Verdict** | **accept-with-gaps** |

### Full body hex (170 B)

```
6aff6816139b0064a1000000005064892500000000515355568b74242089354cf0d10033db56895c241ce8010fadffb801000000884424188405e8f7d100884628895e2c895e308b2d50f0d100751d0905e8f7d1006870339c00c705e4f7d10054efa900e8ada9b1ff83c404b830ed960085c0c744240ce4f7d1007418578d4d588d442410bf30ed9600e8f1cdacff89388958045f8b4c24108bc65e5d5b64890d0000000083c410c20400
```

### Byte-sealed layout / CF

1. SEH frame `LAB_009b1316`.
2. **`DAT_00d1f04c = self`** (global singleton publish).
3. **`FUN_0043fdf0(self)`** — NestedHash span **0x28** at object base (sentinel **0x0C** family, W34-F).
4. **`self+0x28 = 1`** (byte); **`self+0x2c = 0`**; **`self+0x30 = 0`**.
5. Once-init guard **`DAT_00d1f7e8 & 1`**:
   - set bit; **`DAT_00d1f7e4 = &PTR_FUN_00a9ef54`** (static type object / NDResource type-token vtbl);
   - **`_atexit(LAB_009c3370)`** — static dtor thunk (`MOV EAX,&DAT_00d1f7e4; JMP …`).
6. Map register (bytes; decompile incomplete on tree/key):
   - `EBP = *[DAT_00d1f050]` (NDResourceCache global);
   - `ECX = EBP+0x58` tree;
   - stack key dword **`0x00d1f7e4`**;
   - `FUN_0043bd40` → value slot;
   - `*slot = LAB_0096ed30`, `slot[1] = 0`.
7. Restore SEH; **`MOV EAX,ESI`**; `ADD ESP,0x10`; **`RET 4`**.

### Decompile caveats

- Ghidra signature `undefined FUN_0096eec0(void)` incomplete — stack this* / RET 4 from bytes.
- Decompile drops `DAT_00d1f050` tree + key setup for `FUN_0043bd40` — **bytes win**.
- `LAB_0096ed30` is code (SEH prologue at site) but not a defined function symbol.

### Related

| Symbol | Role |
|---|---|
| `NestedHash_Ctor_Sentinel0xC_Inferred` @ `0x0043fdf0` | nested shell at +0 |
| `DAT_00d1f04c` | singleton self (readers: `FUN_0096bc80`, `FUN_0096c2c0`, `FUN_0096d100`, `0x0094f14c`) |
| `DAT_00d1f7e4` / `PTR_FUN_00a9ef54` | static type token also used by `FUN_0096ea60` → `NDResourceCache_LookupOrCreate` |
| `DAT_00d1f050` | NDResourceCache* |
| Twin host | `FUN_00996bc0` (W35-S) — NestedHash0xC at **+0x28**, span **0x54** |
