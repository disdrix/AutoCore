# Annotated low-level: FUN_004cba60 → SkillCNDHash_DestroyBucketTable_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_004cba60` |
| VA | `0x004cba60`–`0x004cba93` (**52 B** / `0x34`) |
| System | skills-abilities / skill-family CNDHash |
| Date | 2026-07-23 scaffold; **2026-08-04 WQ9E-A dual seal** |
| Canonical | `SkillCNDHash_DestroyBucketTable_Inferred` |

## Machine-level notes

- **ABI:** MSVC **`__thiscall`**; `ECX` = skill CNDHash*; **void**; **bare `ret`** (`C3`). Entry `56 8B F1`.
- **Zeros live count `@+0x0c` first** — not the mask at `+0x08`. Inventory twin `CNDHash_DestroyBucketTable_Inferred` (`0x00413e20`) same field role under different ABI (EAX).
- **Freelist release:** `FUN_004cb680` (ECX=hash) walks every bucket chain while `+8` is still the **old mask**; nodes pushed to freelist `@+0x20`. Nested residual (not dualled this partition).
- **Dual free:** `free(*table)` releases the **contiguous 0xc sentinel slab** (bucket[0] = slab base from alloc); `operator_delete[](table)` frees the pointer array at `+0x10`; then zero `+0x10`.
- **Does not clear:** mask `+0x08`, ordered head/tail `+0x14`/`+0x18`, freelist head `+0x20`, lock `+0x1d`. Recreate caller rewrites size fields after return; dtor continues to nested freelist host teardown.
- **Callers:**
  1. `SkillCNDHash_Recreate_Inferred` (`0x004cbdc0`) @ `0x004cbde6` — `mov ecx,esi` then call.
  2. Skill hash dtor body `FUN_0051de80` @ `0x0051dece` — after optional lock log (`HashError:Destructor…`).

## Pseudocode (annotated)

```c
// void __thiscall SkillCNDHash_DestroyBucketTable_Inferred(SkillCNDHash *hash)
void __thiscall FUN_004cba60(int hash)
{
  *(uint32_t *)(hash + 0x0c) = 0;           // live entry count → 0

  FUN_004cb680();                           // ECX=hash: release chains → freelist @+0x20

  void **table = *(void ***)(hash + 0x10);
  if (table != NULL) {
    free(*table);                           // slab base == *bucket[0]
    operator_delete[](table);               // pointer array
    *(uint32_t *)(hash + 0x10) = 0;
  }
  // bare ret
}
```

## Field map (skill CNDHash; shared with recreate/ctor)

| Off | Role |
|-----|------|
| +0x00 | vtbl (`PTR_FUN_009ce1b8` after ctor) |
| +0x08 | mask (or provisional count before alloc) — **not written here** |
| +0x0c | live entry count — **zeroed** |
| +0x10 | bucket pointer table — freed + nulled |
| +0x14 / +0x18 | ordered head/tail — caller-managed |
| +0x1c | log2 (byte) |
| +0x1d | traversal lock (byte) |
| +0x20 | freelist head (`_Inferred`) |

## Open / residual

- Product English class name for skill CNDHash.
- Full dual of freelist helper `FUN_004cb680` (not OWN).
- Bit-identity of node layout vs inventory DestroyBucketTable family.
- Runtime / bit-exact open. Terminal false.
