# Function record: SkillCNDHash_CompleteDtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051de80` |
| **Canonical name** | `SkillCNDHash_CompleteDtor_Inferred` |
| **Ghidra name** | `FUN_0051de80` |
| **Address** | `0x0051de80`–`0x0051deea` inclusive (**107 bytes** / exclusive end `0x0051deeb`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities / skill-family CNDHash |
| **Completion status** | **accept-with-gaps** — dual A/B sealed 2026-08-04 (WQ9G-A OWN) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

MSVC complete object destructor for skill CNDHash: reinstall vtbl `PTR_FUN_009ce1b8`, soft-log if traversal-locked (`HashError:Destructor…`), destroy bucket table, tear down freelist/slab host at `+0x20`. Does not free the host (scalar deleting dtor does). Sole code callee of dualed `SkillCNDHash_ScalarDeletingDtor_Inferred`.

## Signature (byte-sealed)

```c
void __thiscall SkillCNDHash_CompleteDtor_Inferred(void* self);
// ECX=this; no stack args; bare RET; void
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0051de80_FUN_0051de80.md`
- Annotated: `docs/reconstruction/raw/aa_0051de80_FUN_0051de80.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/SkillCNDHash_CompleteDtor_Inferred.cpp`
- Clean FUN_*: `docs/reconstruction/reconstructed-exact/FUN_0051de80.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_0051de80_SkillCNDHash_CompleteDtor_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_0051de80_SkillCNDHash_CompleteDtor_Inferred.md`
- Alias record: `docs/reconstruction/functions/aa_0051de80_FUN_0051de80.md`

## Callers / callees

| Direction | Target | Notes |
|---|---|---|
| Caller | `SkillCNDHash_ScalarDeletingDtor_Inferred` (`0x0051de60`) | sole code CALL @ `0x0051de63` |
| Callee | `SkillCNDHash_DestroyBucketTable_Inferred` (`0x004cba60`) | thiscall |
| Callee | `FUN_0059c8a0` | `LEA ECX,[this+0x20]` freelist/slab host |
| Callee | `FUN_007a4480` | HashError + VOG_DEBUG_STOP soft logs |
| DATA peer | `PTR_FUN_009ce1b8[0]` = scalar dtor | not this VA |

## Confidence

| Claim | Level |
|---|---|
| Complete dtor CF (vtbl + soft lock + destroy + freelist host) | **Confirmed** (bytes) |
| Soft-lock continue (no abort) | **Confirmed** |
| Same vtbl family as ctor/scalar | **Confirmed** |
| Product English class name | Open |
| Freelist host dual (`0059c8a0`) | Open (not OWN) |
| Runtime / image diff | Open |
