# Raw capture: TFID_EqualsObjectId

| Field | Value |
|---|---|
| **Stable ID** | `aa_00404aa0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00404aa0` |
| **Canonical name** | `TFID_EqualsObjectId` |
| **System** | identity / TFID |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
int __cdecl TFID_EqualsObjectId(void *pA,void *pB)

{
  if (((*(int *)pA == *(int *)pB) && (*(int *)((int)pA + 4) == *(int *)((int)pB + 4))) &&
     (*(char *)((int)pA + 8) == *(char *)((int)pB + 8))) {
    return 1;
  }
  return 0;
}
```

---

## v2026-07-29 re-decompile + bytes (append)

**Tool:** Ghidra MCP `decompile_function` `0x00404aa0`; `analyze_function_complete`; `read_memory` length 40.

**Signature / range:** `int __cdecl TFID_EqualsObjectId(void *pA, void *pB)`; body `00404aa0`–`00404ac6`; leaf; 38 xrefs.

**Decompile (reconfirm, identical CF):**

```c
int __cdecl TFID_EqualsObjectId(void *pA,void *pB)

{
  if (((*(int *)pA == *(int *)pB) && (*(int *)((int)pA + 4) == *(int *)((int)pB + 4))) &&
     (*(char *)((int)pA + 8) == *(char *)((int)pB + 8))) {
    return 1;
  }
  return 0;
}
```

**Body bytes (hex):**

```
8b4424048b108b4c24083b1175168b50043b5104750e8a40083a41087506b801000000c333c0c3cc
```

**Decoded (for seal; not a substitute for decompile):**

| VA | Bytes | Meaning |
|---|---|---|
| `00404aa0` | `8B 44 24 04` | `MOV EAX,[ESP+4]` pA |
| `00404aa4` | `8B 10` | `MOV EDX,[EAX]` |
| `00404aa6` | `8B 4C 24 08` | `MOV ECX,[ESP+8]` pB |
| `00404aaa` | `3B 11` | `CMP EDX,[ECX]` |
| `00404aac` | `75 16` | `JNZ fail` |
| `00404aae` | `8B 50 04` | `MOV EDX,[EAX+4]` |
| `00404ab1` | `3B 51 04` | `CMP EDX,[ECX+4]` |
| `00404ab4` | `75 0E` | `JNZ fail` |
| `00404ab6` | `8A 40 08` | `MOV AL,[EAX+8]` |
| `00404ab9` | `3A 41 08` | `CMP AL,[ECX+8]` |
| `00404abc` | `75 06` | `JNZ fail` |
| `00404abe` | `B8 01 00 00 00` | `MOV EAX,1` |
| `00404ac3` | `C3` | `RET` |
| `00404ac4` | `33 C0` | `XOR EAX,EAX` fail |
| `00404ac6` | `C3` | `RET` |
| `00404ac7` | `CC` | pad |

**Invalid sentinel `read_memory` `0x00a15870` len 16:**

```
ff ff ff ff ff ff ff ff 00 00 00 00 00 00 00 00
```
