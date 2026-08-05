# Raw capture: FUN_005cc7c0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005cc7c0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005cc7c0` |
| **Canonical name** | `FUN_005cc7c0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_005cc7c0(int param_1,undefined4 param_2)

{
  FUN_0053d970(0);
  *(undefined1 *)(*(int *)(param_1 + 100) + 0x304) = 1;
  FUN_004c3a40(param_2);
  return;
}
```

---

## W23-J live re-verify (2026-07-29)

| Field | Value |
|---|---|
| Agent | W23-J OWN-ONLY dual A/B |
| Tools | Ghidra `decompile_function` + `read_memory` + `get_function_by_address` / callees / xrefs / callers |
| Program | `autoassault.exe` base `0x400000` |
| Body span | `005cc7c0` – `005cc7e7` (**40 B**) |
| Live decompile | **=** authoritative raw CF (prep ? dirty ? gated set-pos) |
| Not performed | `disassemble_bytes`, Launcher, runtime golden, parent ledger edits |

### Entry / body / epilogue (`read_memory` 64 B @ `0x005cc7c0`)

```
005cc7c0: 56                push esi
005cc7c1: 8b f1             mov esi, ecx          ; host = this
005cc7c3: 8b 4e 64          mov ecx, [esi+0x64]   ; nested object
005cc7c6: 6a 00             push 0                ; stack arg to FUN_0053d970
005cc7c8: e8 a3 11 f7 ff    call FUN_0053d970     ; target 0x0053d970; callee ret 4
005cc7cd: 8b 46 64          mov eax, [esi+0x64]
005cc7d0: 8b 4c 24 08       mov ecx, [esp+0x8]    ; stack arg1 (float* vec) after push esi
005cc7d4: c6 80 04 03 00 00 01
                            mov byte ptr [eax+0x304], 1
005cc7db: 51                push ecx              ; vec for FUN_004c3a40
005cc7dc: 8b 4e 64          mov ecx, [esi+0x64]
005cc7df: e8 5c 72 ef ff    call FUN_004c3a40     ; CVOGObject_SetLocalPosition4_Gated
005cc7e4: 5e                pop esi
005cc7e5: c2 08 00          ret 8                 ; cleans **2** stack dwords
005cc7e8: cc…               int3 pad
```

| Fact | Bytes | Meaning |
|---|---|---|
| Host in **ECX?ESI** | `mov esi,ecx` | MSVC **thiscall** host |
| Nested object | `[esi+0x64]` thrice | all work targets nested object, not host |
| Prep call | `push 0` + `call 0053d970` + callee **`ret 4`** | stack formal **0** forced; ECX=nested |
| Dirty flag | `mov byte [eax+0x304],1` | **byte** write (not dword) |
| Position apply | `push vec; mov ecx,[esi+0x64]; call 004c3a40` | sealed sibling gated float4 store |
| Stack cleanup | `ret 8` | **two** stack dwords at API; body **uses only arg1** as vec |
| Arg2 | never loaded | interface width sealed; payload **open** |

### Callee `FUN_0053d970` (context; not OWN rewrite)

- Body `0053d970`–`0053d9ac`; epilogue **`c2 04 00`** (`ret 4`).
- Uses ECX object: `mov ecx,[ecx+8]` phys/body; if body present and (flag@+0x40==0 or body+8==0), consults **stack arg** (`cmp byte [esp+4],0`): writes slot **1** if arg was 0, else **6**, then **tail-jumps** `FUN_005d4440`.
- Live decompile of `0053d970` **omits** stack-arg rewrite (hazard) — sealed from `read_memory` of callee only as **caller contract**: this unit always pushes **0**.

### Xrefs

| Kind | Sites |
|---|---|
| DATA (vtable slots) | `0x009da9d0`, `0x009daf58`, `0x009db0d8`, `0x009db138`, `0x009db198` — each dword `0x005cc7c0` |
| UNCONDITIONAL_CALL | **none** recovered (`get_function_callers` empty) |

### Decompiler hazards

| Decomp | Bytes / reality |
|---|---|
| Single stack formal `param_2` | **`ret 8`** ? **two** stack dwords; only first used as vec |
| `FUN_0053d970(0)` as free call | **thiscall** on `*(host+0x64)` + stack `0` |
| `FUN_004c3a40(param_2)` free | **thiscall** on `*(host+0x64)` |
| `*(…+100)+0x304` as undefined1 | **byte** store of **1** at nested `+0x304` (same dirty as DriveControlTick post-set) |
