# Annotated low-level: FUN_0043cec0 / GuardedVector_GrowAssignRange

| Field | Value |
|---|---|
| Stable ID | `aa_0043cec0` |
| VA | `0x0043cec0`–`0x0043ceef` (**48 B**) |
| System | STL / guarded ring-vector container |
| Date | 2026-07-23 scaffold; **W27-C seal 2026-07-29** |
| Ghidra name | `FUN_0043cec0` |
| Inferred name | `GuardedVector_GrowAssignRange` (**Inferred**; sole grow-path callee of `GuardedVector_CopyAssign`) |

## Machine-level notes

- **Thin stdcall trampoline**: seven stack formals → eight-arg call to `FUN_0043cf40` by duplicating `param_1` as the final argument; `RET 0x1c`.
- **No** register this/container contract of its own; all work is in unowned `FUN_0043cf40` (construct/`FUN_0043c830`, destroy/`FUN_0043ce10`, move/`FUN_0043d300`/`FUN_0043d390`).
- Sole caller: `FUN_0043c730` grow branch when `source.size > dest.size` (after `FUN_0043ce90` prep).
- Parent call (from sealed `GuardedVector_CopyAssign`):

```
FUN_0043cec0(dest, dest, dest.size + dest.begin,
             source, source.begin + dest.size,
             source, source.size + source.begin);
```

## Pseudocode (annotated; live ≡ raw)

```c
// Retail: stdcall 7 args; RET 0x1c
// Forwards to FUN_0043cf40 with param_1 repeated as 8th formal.
void FUN_0043cec0(uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4,
                  uint32_t param_5, uint32_t param_6, uint32_t param_7)
{
  FUN_0043cf40(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_1);
  return;
}
```

## Open residual

- Full grow/insert arithmetic inside unowned `FUN_0043cf40`.
- Element construct/destroy semantics (`FUN_0043c830` / `FUN_0043ce10`).
- Product/PDB class English.
- Runtime golden / bit-exact.
