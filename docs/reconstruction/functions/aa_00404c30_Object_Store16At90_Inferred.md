# Function record: Object_Store16At90_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00404c30` |
| **Canonical name** | `Object_Store16At90_Inferred` |
| **Ghidra name** | `FUN_00404c30` |
| **Address** | `0x00404c30`–`0x00404c59` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities (partition owner); body = generic object field store |
| **Name confidence** | **High** role (16 B store @ +0x90); product field English **Inferred** |
| **Completion status** | **Dual residual sealed 2026-08-05 R10-022** — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Leaf helper: copy **16 bytes** from caller `src` into **`this+0x90..+0x9c`**. Paired in many callers with twin store `FUN_00404c60` / `Object_Store16At80_Inferred` (`+0x80..+0x8c`). Partition parent dual is `0x00404c60` (MEGA-053 sealed).

## Signature

```c
void __thiscall Object_Store16At90_Inferred(void *thisObj, const uint32_t *src16);
// ret 4
```

## Sealed facts

| Claim | Confidence |
|---|---|
| Offset **+0x90**, size **16** (4 dwords) | **High** |
| `__thiscall` + `ret 4` | **High** |
| Leaf | **High** |
| Direction = **store into this** (not out-copy) | **High** |
| Twin shape @ +0x80 (`00404c60`) | **High** (peer dual MEGA-053) |
| Product field English (pos/quat/…) | **Open** |
| Skill-string body identity | **Falsified** |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00404c30_FUN_00404c30.md`
- Annotated: `docs/reconstruction/raw/aa_00404c30_FUN_00404c30.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Object_Store16At90_Inferred.cpp`
- Scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_00404c30.cpp`
- Review A/B: `docs/reconstruction/reviews/A_aa_00404c30_Object_Store16At90_Inferred.md`, `B_aa_00404c30_Object_Store16At90_Inferred.md`
- Scaffold record: `docs/reconstruction/functions/aa_00404c30_FUN_00404c30.md`
- Report: `docs/agents/task-dual-ab-00404c30-r10-report.md`

## Prior aliases (retired)

- `Named_CalleeOf_Named_CalleeOf_Client_PacketDispatch_00404c30`

## Peers (not OWN)

| VA | Role |
|---|---|
| `0x00404c60` | Twin store 16 B @ `this+0x80` (`Object_Store16At80_Inferred`, MEGA-053) |
| `0x0040aff0` | `Object_CopyTfid16At228_Inferred` — **out-copy** shape (read from this) |
| `0x0061b960` | `Skill_HB_CopyTfid16At668_Inferred` — **out-copy** shape |
