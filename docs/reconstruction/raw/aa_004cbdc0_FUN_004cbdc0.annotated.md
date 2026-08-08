# Annotated low-level: FUN_004cbdc0 → SkillCNDHash_Recreate_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_004cbdc0` |
| VA | `0x004cbdc0`–`0x004cbe14` (**85 B**) |
| System | skills-abilities / skill-family CNDHash |
| Date | 2026-07-23 scaffold; **2026-08-04 WQ9D-A dual seal** |
| Canonical | `SkillCNDHash_Recreate_Inferred` |

## Machine-level notes

- **ABI:** `__thiscall`; `ECX` = skill CNDHash*; stack `uint8_t log2`; **void**; **`ret 4`**.
- **Entry:** `push esi; mov esi, ecx` — sealed thiscall (contrast inventory `CNDHash_Recreate` `0x004138d0` which uses **EAX**/BL custom regs).
- **Traversal lock `@+0x1d`:** if non-zero, log `"HashError:Recreate, already locked for traversal"` + `"VOG_DEBUG_STOP"` then **continue** (does **not** abort recreate). Odd but intentional family pattern.
- **Teardown:** `FUN_004cba60` (ECX=hash) — free/destroy existing bucket table + freelist nodes (peer of inventory DestroyBucketTable).
- **Resize fields:** store `log2` at `@+0x1c`; clear ordered-list tail `@+0x18` and head `@+0x14`; provisional bucket **count** `@+8 = 1 << (log2 & 0x1f)`.
- **Rebuild:** `FUN_004cb410` allocates buckets when `0 < log2 < 0x11`, then decrements `@+8` to **mask**. Out-of-range log2 → log + throw (callee).
- **Callers:**
  1. `Object_CreateOrRecreateSkillHash_Inferred` (`0x00518e30`) — existing path; `mov ecx,[esi+0x70]; push log2`.
  2. `FUN_004c8f00` @ `0x004c902c` — creature skill path; MI load to hash, **imm log2=2**.

## Pseudocode (annotated)

```c
// void __thiscall SkillCNDHash_Recreate_Inferred(SkillCNDHash *hash, uint8_t log2)
void __thiscall FUN_004cbdc0(int hash, byte log2)
{
  // +0x1d = traversal lock flag (byte)
  if (*(char *)(hash + 0x1d) != '\0') {
    FUN_007a4480(0, "HashError:Recreate, already locked for traversal");
    FUN_007a4480(0, "VOG_DEBUG_STOP");
    // NOTE: fall through — recreate still runs
  }

  FUN_004cba60(); // destroy old buckets/table (ECX=hash)

  *(byte *)(hash + 0x1c) = log2;                    // size exponent
  *(undefined4 *)(hash + 0x18) = 0;                 // ordered-list tail
  *(int *)(hash + 8) = 1 << (log2 & 0x1f);          // provisional COUNT
  *(undefined4 *)(hash + 0x14) = 0;                 // ordered-list head

  FUN_004cb410(); // alloc buckets; *(hash+8) becomes MASK
  return; // ret 4
}
```

## Field map (shared with ctor `0x0051dd60`)

| Off | Role |
|-----|------|
| +0x00 | vtbl (`PTR_FUN_009ce1b8` after ctor) |
| +0x08 | bucket count → mask after alloc |
| +0x10 | bucket table ptr |
| +0x14 | ordered-list head |
| +0x18 | ordered-list tail |
| +0x1c | log2 (byte) |
| +0x1d | traversal lock (byte) |

## Open / residual

- Product English class name beyond skill-family CNDHash.
- Nested dual of `FUN_004cba60` / `FUN_004cb410` (not OWN this partition).
- Whether freelist/node layout is bit-identical to inventory CNDHash.
- Runtime / bit-exact open. Terminal false.
