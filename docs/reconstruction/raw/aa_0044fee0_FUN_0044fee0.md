# Raw capture: FUN_0044fee0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0044fee0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0044fee0` |
| **Canonical name** | `FUN_0044fee0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined * FUN_0044fee0(void)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009bca1d;
  local_c = ExceptionList;
  if ((DAT_00d1fce8 & 1) == 0) {
    DAT_00d1fce8 = DAT_00d1fce8 | 1;
    local_4 = 0;
    ExceptionList = &local_c;
    FUN_00457ac0(&DAT_00d1fcc0);
    _atexit((_func_4879 *)&LAB_009c34b0);
  }
  ExceptionList = local_c;
  return &DAT_00d1fcc0;
}
```

---

## W35-E re-verify append (2026-07-29)

| Field | Value |
|---|---|
| **Agent** | OWN-ONLY dual W35-E |
| **Tools** | `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + bulk xrefs. **No** `disassemble_bytes`. |
| **Live decompile** | ≡ raw CF above |
| **Body** | `0x0044fee0`–`0x0044ff39` (**90 B** / `0x5A`; pad `CC` then next) |
| **ABI** | No stack formals; **`RET`** (cdecl); returns **`&DAT_00d1fcc0` in EAX** |
| **Once-flag** | `DAT_00d1fce8` bit 0 (`TEST`/`OR` with imm 1) |
| **Ctor** | `FUN_00457ac0` = W34-E `NestedHash_Ctor_Sentinel0x10_Inferred` on static `DAT_00d1fcc0` (span 0x28 NestedHash shell) |
| **atexit** | `LAB_009c34b0` (DATA xref to `DAT_00d1fcc0` — dtor thunk for static) |
| **Callers (1 fn, 2 sites)** | `FUN_0044fe10` @ `0x0044fe1f`, `0x0044fe33` |
| **Callees** | `FUN_00457ac0`, `_atexit` |
| **Classification** | wrapper / once-get factory |
| **Named (Inferred)** | `NestedHash0x10_StaticOnceGet_d1fcc0_Inferred` |
| **Reject** | scaffold `Named_CalleeOf_Named_CalleeOf_Named_anmTrackEvents_0044fee0` |
| **Family** | Twin of static once-gets `FUN_00438c40` (`DAT_00d1fd18`/`DAT_00d1fd40`) and `FUN_00438ca0` (`DAT_00d1fcec`/`DAT_00d1fd14`) — same NestedHash0x10 ctor |

### Full body hex (90 B)

```
64a1000000006aff681dca9b0050b8010000008405e8fcd1006489250000000075250905e8fcd10068c0fcd100c744240c00000000e8a67b000068b0349c00e8b299030083c4048b0c24b8c0fcd10064890d0000000083c40cc3
```

### Byte notes (no disassemble_bytes)

- FS ExceptionList save/restore; SEH frame `LAB_009bca1d`.
- `B8 01 00 00 00` / `84 05 E8 FC D1 00` — TEST bit0 of `DAT_00d1fce8`.
- `JNZ +0x25` skip init when already once.
- `OR [DAT_00d1fce8],EAX`; `PUSH &DAT_00d1fcc0`; `CALL FUN_00457ac0` (rel `e8a67b0000`).
- `PUSH LAB_009c34b0`; `CALL _atexit`; `ADD ESP,4`.
- `MOV EAX, 00d1fcc0`; restore FS; `ADD ESP,0xC`; **`C3` RET**.
