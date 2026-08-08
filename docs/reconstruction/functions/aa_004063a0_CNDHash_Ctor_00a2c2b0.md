# Function record: CNDHash_Ctor_00a2c2b0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004063a0` |
| **Canonical name** | `CNDHash_Ctor_00a2c2b0` |
| **Ghidra name** | `FUN_004063a0` |
| **Address** | `0x004063a0`–`0x0040641c` (**125 B** / `0x7D`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | container / CNDHash |
| **Completion status** | **partial** — dual A/B **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |
| **Dual A/B** | `A_aa_004063a0_CNDHash_Ctor_00a2c2b0.md`, `B_aa_004063a0_CNDHash_Ctor_00a2c2b0.md` |
| **Last reviewed** | `2026-08-04` (WQ9H-D OWN-ONLY) |

## Alias

- `FUN_004063a0`
- Rejected scaffold: `Named_CalleeOf_Named_CalleeOf_Mission_createNDUIDialogs_004063a0`

## Purpose

Host-family CNDHash (**vtbl `00a2c2b0`**) constructor for a **0x34**-byte block. Installs vtbl, writes provisional bucket count `N=1<<log2` at `+0x08` and log2 at `+0x1c`, clears lock/lists/freelist pointers (skips `+0x24`), then hands off to `CNDHash_AllocBucketTable_00a2c2e4` (ESI custom) which stamps sentinels **`00a2c2e4`** and converts `+0x08` to mask `N-1`. Sole create site always uses **log2=2**.

## Signature (sealed)

```c
// custom: CL = log2; stack CNDHash* self; ret 4; EAX = self
// NOT MSVC thiscall (this is not in ECX — contrast SkillCNDHash_Ctor_Inferred)
void *CNDHash_Ctor_00a2c2b0(uint8_t log2 /*CL*/, void *self /*stack*/);
```

## Algorithm

1. SEH frame.
2. `*self = PTR_FUN_00a2c2b0`.
3. Seed `*(+8)=1<<log2`, zeros fields, `*(+0x1c)=log2`, lock=0.
4. `CNDHash_AllocBucketTable_00a2c2e4` with ESI=self.
5. `EAX=self; ret 4`.

## Related

- Twin dtor: `aa_00406420` `CNDHash_Dtor_00a2c2b0`
- Alloc: `aa_00406f20` `CNDHash_AllocBucketTable_00a2c2e4` (WQ9G-J)
- Destroy: `aa_00406fc0` `CNDHash_DestroyBucketTable_00a2c2e4` (WQ9G-J)
- Parallel thiscall ctors: `CNDHash_Ctor_009cb450`, `SkillCNDHash_Ctor_Inferred` (different ABI/stamp)

## Artifacts

- Raw / annotated / clean / dual A/B — see FUN twin record + agent report
