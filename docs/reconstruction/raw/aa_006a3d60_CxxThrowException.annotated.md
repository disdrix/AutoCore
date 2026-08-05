# Annotated low-level: _CxxThrowException

| Field | Value |
|---|---|
| Stable ID | `aa_006a3d60` |
| VA | `0x006a3d60`–`0x006a3d65` |
| System | CRT / MSVC C++ EH |
| Date | `2026-07-29` |
| Tools | Ghidra `decompile_function` + `read_memory` (no `disassemble_bytes`) |

---

## Machine-level notes

- **Form:** classic PE import thunk: `jmp dword ptr [IAT]`.
- **IAT:** `0x009c64d8` holds pointer to CRT `_CxxThrowException` implementation (`0x006ebcee` in this dump).
- **ABI (CRT contract):** `__stdcall`, args `(void *pExceptionObject, ThrowInfo *pThrowInfo)`, **noreturn**.
- Body has **no** local stack frame, **no** game object access, **no** AutoAssault-specific logic.
- Prefer treating this unit as a **named external** rather than reverse-engineering MSVC EH internals unless a port needs custom exception bridging.

---

## Byte map

| VA | Bytes | Meaning |
|---|---|---|
| `006a3d60` | `FF 25 D8 64 9C 00` | `jmp [0x009c64d8]` |
| `006a3d66` | `CC`… | padding (outside body) |

---

## Pseudocode (annotated)

```c
/* Import thunk — does not return */
__declspec(noreturn)
void __stdcall _CxxThrowException(void *pExceptionObject, ThrowInfo *pThrowInfo)
{
  /* jmp dword ptr [_imp__CxxThrowException] @ IAT 0x009c64d8 */
  ((void (__stdcall *)(void *, ThrowInfo *)) * (void **)0x009c64d8)
      (pExceptionObject, pThrowInfo);
}
```

---

## Open questions

- Live import bind address may differ under different CRT loads; static IAT content is analysis-image specific.
- Full MSVC `ThrowInfo` / catchable-type tables are **out of scope** for this dual (CRT).
- Exhaustive caller catalog not required for seal of this thunk.
