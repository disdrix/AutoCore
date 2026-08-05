# Annotated low-level: FUN_0051bfb0 → CNDHash_ReclaimAll_ValueOwning_009ce0a8

| Field | Value |
|---|---|
| Stable ID | `aa_0051bfb0` |
| VA | `0x0051bfb0`–`0x0051c021` (**0x72** B) |
| System | container / CNDHash (medal family; node stamp `009ce0a8`) |
| Date | 2026-07-29 (W25-F dual seal; prior scaffold 2026-07-23) |
| Canonical | `CNDHash_ReclaimAll_ValueOwning_009ce0a8` (**Inferred**) |

## Machine-level notes

- Source: raw capture + live `decompile_function` / `read_memory` (no `disassemble_bytes`).
- **ECX = this** (`__thiscall` / decompiler `__fastcall`); plain `ret`.
- Outer loop `i = 0 .. mask(+0x08)` **inclusive** (`JBE`).
- Per bucket: walk chain at `*(table[i] + 4)` (sentinel head).
- Per node: stamp `PTR_FUN_009ce0a8`; if value at `+0x08` ≠ 0 → **`FUN_00604e30(value)` thiscall** then **`operator_delete(value)`** (returns — decompiler noreturn is false); clear value; push freelist via `this+0x20` (overwrites stamp slot).
- Clear each bucket head to 0.
- Does **not** zero `count(+0x0C)`, free table `+0x10`, or free freelist storage.
- Sole caller: `CNDHash_FreeBuckets` (`FUN_0051d150` / sealed dual W24-H) after `count=0`.
- Distinguisher vs plain owning reclaim (`009cefec`/`009cefe4`): nested teardown helper before delete.

## Layout (this body)

| Off | Field | Role here |
|---|---|---|
| `+0x08` | mask | loop upper bound (inclusive) |
| `+0x10` | buckets* | pointer table; `table[i]+4` = chain head |
| `+0x20` | freelist | push-reclaimed nodes (next in dword0) |

### Node (inferred)

| Off | Field |
|---|---|
| `+0x00` | vtbl / freelist next |
| `+0x08` | owned value* |
| `+0x0C` | bucket next |

### Value (nested; via `FUN_00604e30` residual)

Owned sub-pointers at `+4`, `+8`, `+0xC`, `+0x10` freed then zeroed before value object delete.

## Pseudocode (annotated)

```c
// void __thiscall CNDHash_ReclaimAll_ValueOwning_009ce0a8(CNDHash *this)
// plain ret; ECX=this
void __thiscall FUN_0051bfb0(int thisHash)
{
  uint i = 0;
  do {
    // node = table[i]->head  (+4 on 0xC sentinel)
    undefined4 *node = *(undefined4 **)(*(int *)(*(int *)(thisHash + 0x10) + i * 4) + 4);
    while (node != 0) {
      void *value = (void *)node[2];          // +0x08
      undefined4 *next = (undefined4 *)node[3]; // +0x0C
      *node = &PTR_FUN_009ce0a8;              // stamp
      if (value != 0) {
        FUN_00604e30(value);                  // thiscall nested teardown
        operator_delete(value);               // RETURNS
      }
      node[2] = 0;
      *node = *(undefined4 *)(thisHash + 0x20); // freelist push
      *(undefined4 **)(thisHash + 0x20) = node;
      node = next;
    }
    *(undefined4 *)(*(int *)(*(int *)(thisHash + 0x10) + i * 4) + 4) = 0;
    i++;
  } while (i <= *(uint *)(thisHash + 8));
}
```

## Call graph (owned VA only)

| Dir | Symbol | VA |
|---|---|---|
| Caller | `CNDHash_FreeBuckets` | `0x0051d15a` |
| Callee | `FUN_00604e30` | nested value clear (not owned) |
| Callee | `operator_delete` | value free |

## Open questions

- Product/PDB English for reclaim.
- Exact product type of value object (medal payload?) — nested fields only via residual.
- Whether every insert path always heap-allocates value at `+0x08`.
- Runtime / bit-exact / differential.
