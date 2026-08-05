# Raw capture: FUN_009c3de0

| Field | Value |
|---|---|
| **Stable ID** | `aa_009c3de0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x009c3de0` |
| **Canonical name** | `FUN_009c3de0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_009c3de0(void)

{
  FUN_005a2470();
  return;
}
```

---

## W25-I live seal append — 2026-07-29

| Field | Value |
|---|---|
| **Agent** | OWN-ONLY dual W25-I |
| **Tools** | Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` + xrefs (**no** `disassemble_bytes`) |
| **Live decompile** | Identical CF shape to raw (tail-call shown as call+return) |
| **Body span** | `0x009c3de0`–`0x009c3de9` (10 B) |
| **Classification** | stub / atexit thunk |
| **Proposed name** | `atexit_NetClassRep_rpcMsgGuaranteedOrdered` (**Inferred**) |

### Live decompile (2026-07-29)

```c
void FUN_009c3de0(void)

{
  FUN_005a2470();
  return;
}
```

### Byte seal (`read_memory` 16 B @ `0x009c3de0`)

```
b9 40 4f b0 00       mov  ecx, 0x00b04f40   ; this = static ClassRep storage
e9 86 e6 bd ff       jmp  FUN_005a2470      ; tail → 0x005a2470 (ClassRep dtor)
cc cc cc cc cc cc    int3 pad
```

Full body hex (10 B, excl. `cc` pad):
```
b9404fb000e986e6bdff
```

| Claim | Evidence | Conf |
|---|---|---|
| Bakes `this = 0x00b04f40` | imm32 `40 4f b0 00` LE in `mov ecx` | **High** |
| Tail-call (not call+ret) | `e9` near jmp; no `e8`/`c3` in body | **High** |
| Target `FUN_005a2470` | next_ip `0x009c3dea` + rel32 `0xFFBDE686` = `0x005a2470` | **High** |
| No stack args / bare atexit entry | no push; no ret n | **High** |
| Sole xref | DATA from CRT static init @ `0x009c0ec5` (`push 0x009c3de0; call atexit`) | **High** |

### CRT registration context (not owned; identity only)

Bytes @ `0x009c0eb0` (read_memory):
```
6a 00 6a 02 6a 01 68 cc 80 9d 00   ; version=0, type=2 (Event), group=1, name*
b9 40 4f b0 00                     ; ECX = &DAT_00b04f40
e8 …                               ; call FUN_005a2410 (ClassRep ctor)
68 e0 3d 9c 00                     ; push FUN_009c3de0
e8 … 59 c3                         ; call _atexit; pop; ret
```

Name string @ `0x009d80cc`: `RPC_TNLConnection_rpcMsgGuaranteedOrdered` (sealed via sibling dual `aa_0059e1c0`).

### Callee shape (context only — not dual-owned)

`FUN_005a2470` (`__thiscall` on ClassRep*):
```
*this = &PTR_FUN_009d7bf4;   // instance vtbl
free(this[8]);               // free strdup'd class name
*this = &PTR_LAB_009d7af4;   // restore base vtbl
return;
```

### Live ≡ raw

**Yes** for CF. Bytes refine decompiler: **mov ecx + jmp** (tail thunk), not a free-standing call that would leave ECX unset.
