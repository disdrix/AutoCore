# Annotated low-level: operator_delete

| Field | Value |
|---|---|
| Stable ID | `aa_00489822` |
| VA | `0x00489822` |
| Body | `0x00489822`–`0x00489827` (**6 B**) |
| System | shared CRT import thunk (`client::crt`) |
| Date | 2026-08-05 (R10-001 OWN dual refresh) |
| Ghidra name | `operator_delete` |
| Classification | IAT thunk (`JMP [0x009C6694]`) |

## Machine-level notes

- Source: raw capture + R10-001 re-verify for `aa_00489822`.
- Prefer **bytes** over decompiler: body is a single `FF 25` IAT jump; decompiler invents recursive call + noreturn.
- Sibling: `operator_delete[]` @ `0x0048981c` (IAT `0x009C6698`) — array form; do not merge.
- Parent dual seed `0x005725a0` is inventory-transfer only for residual ranking; this leaf is CRT-wide.

## Pseudocode (annotated)

```c
/* 0x00489822 — MSVC import thunk for scalar operator delete.
 * Bytes: FF 25 94 66 9C 00  =>  JMP dword ptr [0x009C6694]
 * Ghidra decompile false: recursive call, jumptable, noreturn.
 * True CF: tail-jump through IAT to CRT operator delete; returns.
 */
void __cdecl operator_delete(void *block)
{
  /* indirect: (*IAT_operator_delete)(block);  // cdecl, returns */
  __iat_jmp_operator_delete(block);
}
```

### Byte map

| VA | Bytes | Meaning |
|---|---|---|
| `00489822` | `FF 25 94 66 9C 00` | `JMP [0x009C6694]` IAT |
| `009C6694` | dword (live `24 A8 6E 00` → `0x006EA824`) | resolved CRT entry (image-dependent) |

### ABI

| Slot | Role |
|---|---|
| `[ESP+4]` at entry via CALL | `void *block` |
| Convention | **cdecl** (caller pops 4) |
| Return | void; **does return** |
| Cleanup in thunk | none (JMP, not CALL) |

### Call surface

- **~5k** Ghidra callers (FUN + Unwind SEH) — primary image-wide free entry.
- Used by stdlist destroy, scalar-deleting dtors, inventory frees, etc.

## Open questions

- Exact MSVCRT module/export ordinal for IAT bind (out of OWN; runtime-dependent).
- Runtime / bit-exact / differential of CRT free internals — **not** this thunk's job.

## Dual

- A: `docs/reconstruction/reviews/A_aa_00489822_operator_delete.md`
- B: `docs/reconstruction/reviews/B_aa_00489822_operator_delete.md`
- Report: `docs/agents/task-dual-ab-00489822-r10-report.md`
