# Raw capture: FUN_0045efe0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0045efe0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0045efe0` |
| **Canonical name** | `FUN_0045efe0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_0045efe0(undefined4 param_1,undefined4 *param_2)

{
  undefined4 *in_EAX;
  undefined4 *puVar1;
  int iVar2;
  undefined4 *unaff_EBX;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  while (in_EAX != param_2) {
    puVar1 = in_EAX + 7;
    puVar3 = unaff_EBX;
    puVar4 = in_EAX;
    for (iVar2 = 7; in_EAX = puVar1, iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
  }
  return;
}
```

---

## W35-M re-verify (2026-07-29) — append only

**Tools:** `batch_decompile` / `analyze_function_complete` + `read_memory`. **No** `disassemble_bytes`.  
**Body (bytes win):** `0x0045efe0`–`0x0045effb` exclusive (**27 B** / `0x1B`). Ghidra body end `0045effa` is last byte of `C3`. Pad `CC` then sibling.

### Full hex (27 B)

```
3bc2741656578bf883c01c3bc2b9070000008bf3f3a575ee5f5ec3
```

### Byte-level control flow

| Bytes | Role |
|---|---|
| `3B C2` `74 16` | if EAX==EDX early ret |
| `56 57` | push ESI/EDI |
| loop: `8B F8` `83 C0 1C` | EDI=cursor; EAX+=0x1c |
| `3B C2` | flags for loop end (EAX vs end) |
| `B9 07 00 00 00` `8B F3` `F3 A5` | ECX=7; ESI=EBX; `rep movsd` (copy 0x1c) |
| `75 EE` | continue while EAX!=EDX |
| `5F 5E` `C3` | pop; **RET 0** |

### Sealed ABI (bytes win over decompiler)

| Formal | Register | Role |
|---|---|---|
| dst_begin / cursor | **EAX** | first element to fill (advanced by 0x1c each iter) |
| dst_end | **EDX** (`param_2`) | exclusive end |
| value* | **EBX** (`unaff_EBX`) | single POD source (re-read every slot) |
| (phantom) | decompiler `param_1` | **unused** — ignore |

- **No stack args.** **RET 0** (`C3`). Leaf (no callees).
- Element stride **0x1c** (7 dwords via `rep movsd`).
- Semantics: **forward fill-assign** of half-open range `[EAX, EDX)` from one `*EBX` template (MSVC-style assign fill for POD T size 28).

### Callers (3)

| Caller | Site |
|---|---|
| `FUN_0045cd30` (`StdVector_InsertN_Pod28`) | `0x0045d004` |
| `FUN_00466ea0` (`StdVector_InsertN_Elem28_CountEcx`) | `0x0046715d` |
| `FUN_00469f50` (`StdVector_InsertN_Elem28_ValueEdx`) | `0x0046a1ec` |

### Name

**`Pod28_FillAssign_Forward`** (Inferred structural). Reject scaffold `Named_CalleeOf_*anmTrackMast*`.

### Classification

**leaf**.
