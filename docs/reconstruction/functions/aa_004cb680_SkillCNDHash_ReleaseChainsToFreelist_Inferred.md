# Function record: SkillCNDHash_ReleaseChainsToFreelist_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cb680` |
| **Canonical name** | `SkillCNDHash_ReleaseChainsToFreelist_Inferred` |
| **Ghidra name** | `FUN_004cb680` |
| **Address** | `0x004cb680`–`0x004cb6e1` (**98 B** / `0x62`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `skills-abilities` |
| **Completion status** | **partial** — dual A/B **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |
| **Dual A/B** | `A_aa_004cb680_SkillCNDHash_ReleaseChainsToFreelist_Inferred.md`, `B_aa_004cb680_SkillCNDHash_ReleaseChainsToFreelist_Inferred.md` |
| **Last reviewed** | `2026-08-04` (WQ9F-A OWN-ONLY) |

## Alias

- `FUN_004cb680`
- Scaffold VOG path name (**narrow / reject as product**)

## Purpose

Skill-family CNDHash helper: move all **live bucket-chain nodes** onto freelist `@+0x20` and delete owned payloads, as the first nested step of bucket-table destroy (before slab/`delete[]`).

## Signature (sealed)

```c
void __thiscall SkillCNDHash_ReleaseChainsToFreelist_Inferred(void *hash);
// bare ret
```

## Algorithm

1. `for i = 0 .. mask(@+0x08) inclusive`.
2. Drain `table[i]->head(+4)`.
3. Per node: temp stamp `PTR_FUN_009cb968`; `operator_delete` if `payload@+8`; freelist push; follow `next@+0xc`.
4. Clear head; bare ret.

## Related

- `aa_004cba60` destroy parent (sole caller)
- `aa_004cb410` alloc twin
- `aa_004cbdc0` recreate chain

## Artifacts

- Raw / annotated / clean / dual A/B — see FUN twin record + agent report WQ9F-A
