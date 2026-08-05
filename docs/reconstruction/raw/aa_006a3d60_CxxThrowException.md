# Raw capture: _CxxThrowException

| Field | Value |
|---|---|
| **Stable ID** | `aa_006a3d60` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006a3d60` |
| **Canonical name** | `_CxxThrowException` |
| **System** | CRT / MSVC C++ EH |
| **Capture timestamp** | `2026-07-29` |
| **Tool** | Ghidra MCP `decompile_function` + `read_memory` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Function bounds

| Field | Value |
|---|---|
| Entry | `0x006a3d60` |
| Body | `0x006a3d60`–`0x006a3d65` (6 bytes) |
| Signature (Ghidra) | `noreturn void __stdcall _CxxThrowException(void * pExceptionObject, ThrowInfo * pThrowInfo)` |

---

## Raw pseudocode (authoritative decompile)

```c
void _CxxThrowException(void *pExceptionObject,ThrowInfo *pThrowInfo)

{
                    /* WARNING: Could not recover jumptable at 0x006a3d60. Too many branches */
                    /* WARNING: Subroutine does not return */
                    /* WARNING: Treating indirect jump as call */
  _CxxThrowException(pExceptionObject,pThrowInfo);
  return;
}
```

---

## `read_memory` @ `0x006a3d60` (16 B body + pad)

```
FF 25 D8 64 9C 00 CC CC CC CC CC CC CC CC CC CC
```

### Decode

| Bytes | Instruction | Note |
|---|---|---|
| `FF 25 D8 64 9C 00` | `jmp dword ptr [0x009c64d8]` | IAT thunk for `_CxxThrowException` |
| `CC`… | int3 pad | |

### IAT slot (`read_memory` @ `0x009c64d8`, 4 B)

```
EE BC 6E 00
```

→ dword **`0x006ebcee`** (imported CRT implementation target as resolved in this image / analysis state).

---

## Capture notes

- This VA is a **6-byte import trampoline**, not inlined throw logic.
- Decompiler “jumptable” / recursive call warnings are **noise** for `jmp [IAT]`.
- Symbol already product/CRT: `_CxxThrowException`.
- Call sites: thousands of C++ throw edges (Ghidra lists many `Catch@…` / throw sites); not owned exhaustively here.
- **Not** game business logic; required only as callee identity for exception paths in other units.
