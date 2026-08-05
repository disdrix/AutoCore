# Annotated low-level: NestedHash_Ctor_Sentinel0x14_Inferred (FUN_0043bdf0)

| Field | Value |
|---|---|
| Stable ID | `aa_0043bdf0` |
| VA | `0x0043bdf0`–`0x0043be51` (**98 B**) |
| System | containers / nested hash bag (NDResourceCache head + embeds) |
| Date | 2026-07-23 scaffold; W34-E seal 2026-07-29 |

## Machine-level notes

- **ABI:** stack placement ctor `self*`; **`RET 4`**; returns `self` in EAX. **Not** ECX-thiscall.
- **SEH:** `LAB_009bc89b` (shared with twin `00457ac0` / AssResolverCore HeadBag).
- **Layout (span 0x28):**
  - `+0x00/+0x04` unwritten
  - `+0x08` circular sentinel* (`FUN_0043c460` → `new(0x14)` + next/prev)
  - `+0x0c` size = 0
  - `+0x10` PtrVecShell base → 9-bucket pointer table via `FUN_004646e0`
  - `+0x20` flag = 1; `+0x24` flag = 1
- **Family:** identical CF to W32-D `AssResolverA_NestedHash_Ctor` / W32-E `AssResolverCore_HeadBag_Ctor` with node size **0x14** (vs 0x28).
- Prefer bytes when decompiler omits RET 4 / stack formal.

## Pseudocode (annotated)

```c
// NestedHash_Ctor_Sentinel0x14_Inferred — stack(self*); RET 4
NestedHash14* FUN_0043bdf0(NestedHash14* self /*stack*/)
{
  // SEH LAB_009bc89b
  void* node = FUN_0043c460();          // new(0x14) circular sentinel
  self->sentinel = node;                // +0x08
  self->size = 0;                       // +0x0c
  void* fill = node;
  FUN_004646e0(&self->shell, 9, &fill); // +0x10, cap 9, fill sentinel*
  self->flag20 = 1;                     // +0x20
  self->flag24 = 1;                     // +0x24
  return self;
}
```

## Callers

1. `FUN_0075d470` — installs bag at host+0; publishes `DAT_00d1f050` (NDResourceCache).
2. `FUN_0074d750` — nested at `host+0x34` after sibling 0x28-node bag `FUN_0044a0d0(host+0x0c)`.

## Open questions

- Product/PDB English for bag type and flag fields.
- Unwritten `+0x00/+0x04` product role.
- Runtime / bit-exact / differential.
