# Function record: Object_Store16At80_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00404c60` |
| **Canonical name** | `Object_Store16At80_Inferred` |
| **Ghidra name** | `FUN_00404c60` |
| **Address** | `0x00404c60`–`0x00404c88` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities (partition owner); body = generic object field store |
| **Name confidence** | **High** role (16 B store @ +0x80); product field English **Inferred** |
| **Completion status** | **Dual residual sealed 2026-08-05 MEGA-053** — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Leaf helper: copy **16 bytes** from caller `src` into **`this+0x80..+0x8c`**. Paired in many callers with twin store `FUN_00404c30` (`+0x90..+0x9c`). Partition hint tied this VA to skill invalid creature/template strings — those strings belong to **parent consumers**, not this body.

## Signature

```c
void __thiscall Object_Store16At80_Inferred(void *thisObj, const uint32_t *src16);
// ret 4
```

## Sealed facts

| Claim | Confidence |
|---|---|
| Offset **+0x80**, size **16** (4 dwords) | **High** |
| `__thiscall` + `ret 4` | **High** |
| Leaf | **High** |
| Direction = **store into this** (not out-copy) | **High** |
| Twin shape @ +0x90 (`00404c30`) | **High** (peer evidence) |
| Product field English (pos/quat/…) | **Open** |
| Skill-string body identity | **Falsified** |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00404c60_FUN_00404c60.md`
- Annotated: `docs/reconstruction/raw/aa_00404c60_FUN_00404c60.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Object_Store16At80_Inferred.cpp`
- Scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_00404c60.cpp`
- Review A/B: `docs/reconstruction/reviews/A_aa_00404c60_Object_Store16At80_Inferred.md`, `B_aa_00404c60_Object_Store16At80_Inferred.md`
- Scaffold record: `docs/reconstruction/functions/aa_00404c60_FUN_00404c60.md`

## Prior aliases (retired)

- `Named_CalleeOf_Skill_Skill_d_had_invalid_template_d_00404c60`
- `Named_CalleeOf_Named_CalleeOf_Skill_Skill_d_had_invalid_creatur_00404c60`

## Peers (not OWN)

| VA | Role |
|---|---|
| `0x00404c30` | Twin store 16 B @ `this+0x90` |
| `0x0040aff0` | `Object_CopyTfid16At228_Inferred` — **out-copy** shape (read from this) |
| `0x0061b960` | `Skill_HB_CopyTfid16At668_Inferred` — **out-copy** shape |
