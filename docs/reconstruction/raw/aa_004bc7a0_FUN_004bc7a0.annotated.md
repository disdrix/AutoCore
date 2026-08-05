# Annotated low-level: FUN_004bc7a0 → CNDHash_AllocBucketTable_009cb348

| Field | Value |
|---|---|
| Stable ID | `aa_004bc7a0` |
| VA | `0x004bc7a0`–`0x004bc830` |
| System | container / CNDHash (COList tableC family; sentinel stamp `009cb348`) |
| Date | 2026-07-29 (W29-K dual seal; prior scaffold 2026-07-23) |
| Canonical | `CNDHash_AllocBucketTable_009cb348` (**Inferred**) |

## Machine-level notes

- Source: raw capture + live `decompile_function` / `read_memory` (no `disassemble_bytes`).
- **ECX = this** (`__thiscall` / decompiler `__fastcall`); plain `ret` on success.
- Preconditions: `log2` byte at `this+0x1C` in **`[1,16]`**; `this+0x08` holds provisional **bucket count N = 1<<log2** (set by Recreate/ctor before call).
- Alloc:
  1. `operator_new[](N * 4)` → pointer table at `this+0x10`
  2. `malloc(N * 0xC)` → contiguous sentinel slab
  3. For `i = 0 .. N-1`: `table[i] = slab + i*0xC`; stamp sentinel vtbl **`0x009cb348`**; head `+4=0`; `+8=0`
  4. `this+0x08 = N - 1` (**count → mask**)
- Fail path: `VOG_DEBUG_STOP` + `_CxxThrowException` with code **`0x80004003`** (`E_POINTER`), `ThrowInfo @ 0x00acc430`.
- Explains FreeBuckets `free(*buckets)`: first table entry points at slab base.
- Object-vtbl family: host CNDHash uses **`009cb450`** (ctor `CNDHash_Ctor_009cb450` / W28-J). Sentinel stamp is **distinct** (`009cb348`).
- Twin of `FUN_004bc840`: same body template; only stamp imm + call relocs differ.

## Layout (this body)

| Off | Field | Mutation |
|---|---|---|
| `+0x08` | count → **mask** | read N; write N−1 |
| `+0x10` | buckets* | ← new[] pointer table |
| `+0x1C` | log2 | read-only gate |

### Sentinel (0xC)

| Off | Init |
|---|---|
| `+0x00` | `&PTR_LAB_009cb348` |
| `+0x04` | 0 (chain head) |
| `+0x08` | 0 |

## Pseudocode (annotated)

```c
// void __thiscall CNDHash_AllocBucketTable_009cb348(CNDHash *this)
// plain ret; or noreturn throw
void __thiscall FUN_004bc7a0(int thisHash)
{
  char log2 = *(char *)(thisHash + 0x1c);
  if (!(log2 >= 1 && log2 <= 16)) {
    FUN_007a4480(0, "VOG_DEBUG_STOP");
    // throw 0x80004003 / E_POINTER
    _CxxThrowException(...);
  }
  int N = *(int *)(thisHash + 8);              // power-of-two count
  void **table = operator_new[](N * 4);
  *(void **)(thisHash + 0x10) = table;
  void *slab = malloc(N * 0xC);
  for (uint i = 0; i < (uint)N; i++) {
    table[i] = (char *)slab + i * 0xC;
    undefined4 *sent = (undefined4 *)table[i];
    *sent = &PTR_LAB_009cb348;
    sent[1] = 0;
    sent[2] = 0;
  }
  *(int *)(thisHash + 8) = N - 1;              // MASK for key & mask
}
```

## Call graph (owned VA only)

| Dir | Symbol | VA / note |
|---|---|---|
| Caller | ctor `CNDHash_Ctor_009cb450` (`FUN_004bce90`) | `0x004bceea` (W28-J sealed) |
| Caller | Recreate `FUN_004bcce0` | `0x004bcd2c` (`HashError:Recreate,...`) |
| Callee | `operator_new[]` | pointer table |
| Callee | `malloc` | sentinel slab (IAT `0x009c6528`) |
| Callee | `FUN_007a4480` / `_CxxThrowException` | fail path |

## Twin / family

| Sibling | Role |
|---|---|
| `FUN_004bc840` / `CNDHash_AllocBucketTable_009cb350` | twin Alloc (hashA/B family; stamp `009cb350`) — same dual W29-K |
| `CNDHash_Ctor_009cb450` `0x004bce90` | installs object vtbl; sets N then calls this |
| `CNDHash_AllocBucketTable_009ce090` `0x0051ba40` | parallel medal-family Alloc (other stamp) |
| `CNDHash_AllocBucketTable_Inferred` `0x00413d80` | same pattern other stamp |
