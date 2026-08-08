# Function record: SkillCNDHash_Recreate_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cbdc0` |
| **Canonical name** | `SkillCNDHash_Recreate_Inferred` |
| **Ghidra name** | `FUN_004cbdc0` |
| **Address** | `0x004cbdc0`–`0x004cbe14` (**85 B** / `0x55`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `skills-abilities` |
| **Completion status** | **partial** — dual A/B **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |
| **Dual A/B** | `A_aa_004cbdc0_SkillCNDHash_Recreate_Inferred.md`, `B_aa_004cbdc0_SkillCNDHash_Recreate_Inferred.md` |
| **Last reviewed** | `2026-08-04` (WQ9D-A OWN-ONLY) |

## Alias

- `FUN_004cbdc0`
- `Named_VOG_DEBUG_STOP_004cbdc0` (scaffold; reject as product identity)

## Purpose

Skill-family CNDHash **recreate** (destroy old buckets, set log2, alloc empty table). String-sealed role via `"HashError:Recreate, already locked for traversal"`. Lock at `+0x1d` is **non-fatal**. Peer ctor installs vtbl `PTR_FUN_009ce1b8`. Distinct from inventory `CNDHash_Recreate` `0x004138d0` (custom EAX/BL ABI).

## Signature (sealed)

```c
void __thiscall SkillCNDHash_Recreate_Inferred(void *hash, unsigned char log2);
// ret 4
```

## Algorithm

1. If `*(hash+0x1d) != 0`: log recreate-locked + `VOG_DEBUG_STOP` (continue).
2. `FUN_004cba60(hash)` — destroy old table.
3. `*(hash+0x1c) = log2`; clear `+0x18`/`+0x14`; `*(hash+8) = 1 << (log2 & 0x1f)`.
4. `FUN_004cb410(hash)` — alloc buckets; `+8` becomes mask.
5. `ret 4`.

## Related

- `aa_0051dd60` `SkillCNDHash_Ctor_Inferred` (create path peer)
- `aa_00518e30` `Object_CreateOrRecreateSkillHash_Inferred` (primary caller)
- `aa_004138d0` inventory `CNDHash_Recreate` (analogous pattern only)

## Artifacts

- Raw / annotated / clean / dual A/B — see FUN twin record + agent report
