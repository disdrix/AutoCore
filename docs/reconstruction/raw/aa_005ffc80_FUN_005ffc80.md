# Raw capture: FUN_005ffc80

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ffc80` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005ffc80` |
| **Canonical name** | `FUN_005ffc80` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_005ffc80(void)

{
  return;
}
```

---

## Re-verify 2026-08-05 R11-009 (append only)

| Field | Value |
|---|---|
| **Tool** | Ghidra MCP `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + `get_function_xrefs` + `get_function_callers` (no `disassemble_bytes`) |
| **Address** | `0x005ffc80` |
| **Body** | 3 B `c2 04 00` (`RET 0x4`); exclusive end `0x005ffc83`; `cc` pad to neighbor `FUN_005ffc90` @ `0x005ffc90` |
| **Classification** | **stub** (analyze_function_complete); callees: none |
| **Canonical name (sealed)** | `EmptyStub_Ret4` (prior scaffold `FUN_005ffc80`) |
| **System** | shared / multi-domain nop leaf (partition residual host: skills-abilities / parent `0x00416110`) |

### Live decompile

```c
void FUN_005ffc80(void)

{
  return;
}
```

≡ original raw CF (empty return). **Decompiler ABI incomplete:** displays `void(void)` / bare return; machine is **`RET 0x4`**.

### `disassemble_function` @ `0x005ffc80`

```
005ffc80: RET 0x4
```

### `read_memory` @ `0x005ffc80` (32 B)

```
c2 04 00 cc cc cc cc cc cc cc cc cc cc cc cc cc
8b 44 24 04 56 57 8d 71 08 50 8b ce e8 ef 05 05
```

| Bytes | Instruction | Note |
|---|---|---|
| `c2 04 00` | `ret 4` | sole body — cleans **1** stack dword |
| `cc…` | int3 pad | not in function body |
| `8b 44…` | start of `FUN_005ffc90` | distinct neighbor |

### Sole code caller (UNCONDITIONAL_CALL)

`FUN_0064d9f0` @ `0x0064d9f9`:

```
PUSH EDI          ; dest*
MOV ESI, ECX      ; this
CALL 0x005ffc80   ; ECX still this; stack arg cleaned by ret 4
; then 8× dword copy this+0x30..+0x4c → dest
RET 0x4
```

Body ignores dest / this; no stores. Call is a **nop before copy**.

### Xref roles (sample; not exhaustive)

| Role | Evidence |
|---|---|
| Default empty **vtable** methods | 100+ DATA xrefs (Ghidra cap); LE `80 fc 5f 00` |
| Class `0x00a9bbe8` vtbl +8 | parent dual `FUN_00416110` / `read_memory` `0x00a9bbf0` = this |
| VehicleAction primary vtbl +0x10 | physics verified `fn_00597e90` (docs say "empty ret" — machine is **ret 4**) |
| VehicleAction secondary +0x04 / +0x0c | same VA shared |
| Other physics builders | susp/brake/trans/tankSteering/wheelCollideComp cite shared empty stub |

**Not** the same VA as bare-`c3` `EmptyRet` @ `0x0056f570`.