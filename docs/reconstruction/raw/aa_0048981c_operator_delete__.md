# Raw capture: operator_delete__

| Field | Value |
|---|---|
| **Stable ID** | `aa_0048981c` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0048981c` |
| **Canonical name** | `operator_delete__` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __cdecl operator_delete__(void *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x0048981c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  operator_delete__(param_1);
  return;
}
```

---

## R10-010 live re-verify (2026-08-05) — append only

| Field | Value |
|---|---|
| **Wave** | R10 residual dual OWN-ONLY **R10-010** |
| **Tool** | Ghidra MCP `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs |
| **Integrity** | Original 2026-07-23 body preserved above; this section appends only |

### Live decompile (`decompile_function` @ `0x0048981c`)

```c
void __cdecl operator_delete__(void *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x0048981c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  operator_delete__(param_1);
  return;
}
```

### Classification (`analyze_function_complete`)

| Field | Value |
|---|---|
| **Ghidra name** | `operator_delete[]` |
| **Decompiler symbol** | `operator_delete__` (Ghidra encoding of `operator delete[]`) |
| **Signature** | `void __cdecl operator_delete[](void * param_1)` |
| **Classification** | **thunk** (`is_thunk: true`) |
| **Callees** | none (tail-JMP via IAT; not a CALL) |
| **Xrefs** | ≥100 (cap); universal CRT array-delete sites + Unwind helpers |
| **Parent dual seed** | `InventoryGrid_CompleteDtor` `0x005725a0` (calls this for cells `@+0x28`) |

### Bytes (`read_memory` @ `0x0048981c`, 12 B)

```
ff 25 98 66 9c 00   ; 0x0048981c  JMP dword ptr [0x009c6698]   ← THIS (operator delete[])
ff 25 94 66 9c 00   ; 0x00489822  JMP dword ptr [0x009c6694]   ← sibling operator_delete (scalar)
```

Body exclusive: **6 B** (`0x0048981c`–`0x00489821`). Next function `operator_delete` @ `0x00489822`.

### IAT slot (`read_memory` @ `0x009c6698`, 4 B)

```
14 a8 6e 00   ; dword 0x006ea814  (process-resolved MSVC CRT operator delete[] entry)
```

Xref to IAT slot: sole **INDIRECTION** from `0x0048981c`.

### Assembly (`disassemble_function`)

```
0048981c: JMP dword ptr [0x009c6698]
```

### Caller ABI sample (`get_assembly_context` @ `0x0057072d` InventoryGrid_AllocateCellArray)

```
MOV EAX, [ESI+0x28]
TEST EAX, EAX
JZ  ...
PUSH EAX
CALL 0x0048981c          ; operator_delete[]
ADD ESP, 0x4             ; cdecl cleanup — proves returns
```

### Decompiler artifacts (do not treat as CF)

1. "Could not recover jumptable" — false; single `FF 25` IAT JMP.
2. Recursive `operator_delete__(param_1)` — decompiler models IAT JMP as self-call.
3. Phantom `return` after tail-JMP — not in bytes.

### Sealed contract

```
operator_delete_array / operator delete[]  @ 0x0048981c:
  JMP [IAT 0x009c6698]     ; MSVC CRT operator delete[]
  ABI: __cdecl; arg0 = void* block (array cookie-aware free in CRT)
  size: 6 bytes; no local body
```
