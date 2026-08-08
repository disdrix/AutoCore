# Function record: Skill_HB_CopyTfid16At668_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0061b960` |
| **Canonical name** | `Skill_HB_CopyTfid16At668_Inferred` |
| **Ghidra name** | `FUN_0061b960` |
| **Address** | `0x0061b960`–`0x0061b986` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities |
| **Name confidence** | **High** role (TFID_16 copy @ skill-HB +0x668); product English **Inferred** |
| **Completion status** | **Dual residual sealed 2026-08-05 MEGA-016** — accept |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Leaf helper: copy **16-byte TFID** from **`this+0x668..+0x677`** on a skill-HB object into caller out buffer. Used by shared pulse `FUN_0061b6f0` before target-directed `vtbl+0x88` apply (after `vtbl+0x214` resolve).

## Signature

```c
TFID_16* __thiscall Skill_HB_CopyTfid16At668_Inferred(void* thisSkillHb, TFID_16* out);
// ret 4; EAX = out
```

## Sealed facts

| Claim | Confidence |
|---|---|
| Offset **+0x668**, size **16** | **High** (`add ecx,0x668` + 4 dwords) |
| `__thiscall` + `ret 4` | **High** |
| Leaf | **High** |
| Role = TFID extract (not position / heat / float) | **High** (parent + twin shape) |
| Product symbol | **Open** |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0061b960_FUN_0061b960.md`
- Annotated: `docs/reconstruction/raw/aa_0061b960_FUN_0061b960.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Skill_HB_CopyTfid16At668_Inferred.cpp`
- Scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_0061b960.cpp`
- Review A/B: `docs/reconstruction/reviews/A_aa_0061b960_Skill_HB_CopyTfid16At668_Inferred.md`, `B_aa_0061b960_Skill_HB_CopyTfid16At668_Inferred.md`
- Scaffold record: `docs/reconstruction/functions/aa_0061b960_FUN_0061b960.md`

## Prior alias

No `Named_CalleeOf_*` scaffold existed for this VA. Scaffold machine name `FUN_0061b960` retained as twin clean/record only.

## Peer

`Object_CopyTfid16At228_Inferred` (`aa_0040aff0`) — identical body shape, object TFID @ `+0x228`.
