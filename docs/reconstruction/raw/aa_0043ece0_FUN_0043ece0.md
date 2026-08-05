# Raw capture: FUN_0043ece0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043ece0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0043ece0` |
| **Canonical name** | `FUN_0043ece0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_0043ece0(undefined4 *param_1)

{
  undefined4 *in_EAX;
  
  if (in_EAX != (undefined4 *)0x0) {
    *in_EAX = *param_1;
    in_EAX[1] = param_1[1];
  }
  return;
}
```

---

## Dual A/B re-verify (W32-M, 2026-07-29)

**Tools:** Ghidra `decompile_function` + `read_memory` + `get_function_by_address` + `analyze_function_complete` + callers/xrefs. **No** `disassemble_bytes`. No Launcher.

### Live decompile (re-confirm)

```c
void __fastcall FUN_0043ece0(undefined4 *param_1)

{
  undefined4 *in_EAX;
  
  if (in_EAX != (undefined4 *)0x0) {
    *in_EAX = *param_1;
    in_EAX[1] = param_1[1];
  }
  return;
}
```

### Function bounds

| Field | Value |
|---|---|
| Entry | `0x0043ece0` |
| Body | `0x0043ece0`–`0x0043ecee` (**15 B** / `0xF`) |
| Ghidra name | `FUN_0043ece0` |
| Classification | **leaf** |
| Pad | `CC` @ `0x0043ecef` then sibling `FUN_0043ecf0` (W32-N) |

### Byte seal (`read_memory` @ `0x0043ece0`, 16 B)

```
hex: 85c0740a8b1189108b4904894804c3 cc

85 C0           TEST EAX, EAX
74 0A           JZ   +0x0A          ; skip stores → RET
8B 11           MOV  EDX, [ECX]     ; src[0]
89 10           MOV  [EAX], EDX     ; dst[0]
8B 49 04        MOV  ECX, [ECX+4]   ; src[1]
89 48 04        MOV  [EAX+4], ECX   ; dst[1]
C3              RET                 ; bare (0 cleanup)
CC              INT3 pad
```

### Sealed ABI / algorithm

| Claim | Evidence |
|---|---|
| **EAX = dst** (nullable) | `TEST EAX` + `JZ`; stores via `[EAX]`/`[EAX+4]` |
| **ECX = src** (`const PodU32x2*`) | loads `[ECX]` / `[ECX+4]`; decompiler `__fastcall param_1` |
| Bare **`RET`** (not `RET n`) | trailing `C3` |
| Copies **two dwords** (8 B) | offsets 0 and +4 only |
| Null-safe: null dst → no write | `TEST`/`JZ` skip |
| Leaf | no callees |

### Callers / xrefs

| Kind | Value |
|---|---|
| Callers (1) | `FUN_0043e970` (`GuardedVector_PushBack_Stride2_U32x2`) |
| Xref | `0x0043e9cf` UNCONDITIONAL_CALL |
| Call-site setup | parent sets **EAX=slot**, **ECX=value*** then `CALL` |

### Named role (sealed)

**`Pod8_CopyIfNonNull`** / **`PodU32x2_CopyIfNonNull`** — null-safe 8-byte (two-u32) store. Twin null-safe 5-byte path is `FUN_0043ecf0` (owned W32-N).
