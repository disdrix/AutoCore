# Raw capture: FUN_0043ecf0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043ecf0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0043ecf0` |
| **Canonical name** | `FUN_0043ecf0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_0043ecf0(undefined4 *param_1)

{
  undefined4 *in_EAX;
  
  if (in_EAX != (undefined4 *)0x0) {
    *in_EAX = *param_1;
    *(undefined1 *)(in_EAX + 1) = *(undefined1 *)(param_1 + 1);
  }
  return;
}
```

---

## W32-N live seal — 2026-07-29

| Field | Value |
|---|---|
| Tools | Ghidra `batch_decompile` + `read_memory` + `get_function_by_address` + `analyze_function_complete` + xrefs. **No** `disassemble_bytes` |
| Live decompile | ≡ raw 2026-07-23 CF |
| Body | `0x0043ecf0`–`0x0043ecfe` inclusive (**15 B** / `0x0F`); pad `CC` then next unit |
| Classification | **leaf** |
| Callers (1) | `FUN_0043e9e0` @ `0x0043ea3f` (`GuardedVector_PushBack_Stride2_U32U8`, W31-J) |
| Callees | none |
| Twin | `FUN_0043ece0` (`PodU32x2_CopyIfNonNull` / Pod8 store) — bit-twin with dword second field |

### Full body hex (`read_memory` 15 B)

```
85c0740a8b1189108a4904884804c3
```

### ABI (bytes win)

- **EAX** = dest slot (null-checked)
- **ECX** = `const PodU32U8* src` (decompiler `param_1`)
- **`RET`** (no stack cleanup) — pure register dual
- Void

### Semantics (bytes + decompile)

```
TEST EAX,EAX / JZ skip
MOV EDX,[ECX]; MOV [EAX],EDX      ; copy u32
MOV CL,[ECX+4]; MOV [EAX+4],CL    ; copy u8
RET
```

- Null dest → no write (caller still advances size).
- Write width **5 B** into 8-byte slots (trailing 3 B unwritten).
- Twin `0043ece0` differs only: `8B 49 04 89 48 04` (second **dword**) vs `8A 49 04 88 48 04` (second **byte**).

### Twin hex (`0043ece0` / `0043ecf0`)

```
0043ece0: 85c0740a8b1189108b4904894804c3  ; u32 + u32
0043ecf0: 85c0740a8b1189108a4904884804c3  ; u32 + u8
```

### Canonical name (inferred)

`PodU32U8_CopyIfNonNull` — null-safe dword+byte POD store used by stride-2 U32U8 push_back (W31-J).
