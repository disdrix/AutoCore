# Raw capture: FUN_004b0bd0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004b0bd0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004b0bd0` |
| **Canonical name** | `FUN_004b0bd0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_004b0bd0(void)

{
  return;
}
```

---

## W30-R dual seal append (2026-07-29)

| Field | Value |
|---|---|
| **Body** | `0x004b0bd0`–`0x004b0bd1` exclusive (**1** B / `0x1`) |
| **Epilogue** | **`c3`** (`ret`) only |
| **Pad** | `CC` from `0x004b0bd1` (next code `0x004b0be0`) |
| **Callees** | none |
| **Callers (1)** | `ObjectMotion_SlotReleaseToFreelist_Inferred` (`FUN_005be2b0`) @ `0x005be2bf` (child) and `0x005be2da` (node) — both thiscall with ECX set; body ignores ECX |
| **Role** | empty dtor stub before freelist-push of motion slot (+ optional child@+0x8) |
| **Name** | `ObjectMotion_SlotEmptyDtor_Inferred` |
| **Tools** | `decompile_function` + `read_memory` + callers/xrefs. **No** `disassemble_bytes` |
| **Live decompile** | ≡ raw 2026-07-23 body |

### Byte body (1 B)

```
C3
```

### Algorithm (sealed)

```
// thiscall shape at call sites; body is bare ret — no work, no stack cleanup
return;
```
