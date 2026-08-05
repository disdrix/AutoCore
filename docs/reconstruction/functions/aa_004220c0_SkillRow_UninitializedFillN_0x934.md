# Function record: SkillRow_UninitializedFillN_0x934

| Field | Value |
|---|---|
| **Stable ID** | `aa_004220c0` |
| **Canonical name** | `SkillRow_UninitializedFillN_0x934` |
| **Ghidra name** | `FUN_004220c0` |
| **Address** | `0x004220c0` |
| **Body range** | `0x004220c0`–`0x004220e3` (36 bytes) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities / vector helpers (stride 0x934) |
| **Completion status** | **partial** — dual A/B **accept**; leaf CF + ABI + constants sealed; runtime/diff open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_004220c0_SkillRow_UninitializedFillN_0x934.md`, `reviews/B_aa_004220c0_SkillRow_UninitializedFillN_0x934.md` (2026-07-29 W22-M) |
| **Last reviewed** | `2026-07-29` |

## Alias

- `FUN_004220c0`
- Prior scaffold: `Named_CalleeOf_Named_CalleeOf_Skill_DbLoadSkillsCharacters_004220c0`
- Family twin pattern: `UiToast_UninitializedFillN_0x98` (different stride/ABI)

## Purpose

Leaf **uninitialized_fill_n** for **0x934-byte** skill-row POD elements: copy the EBX prototype into `count` consecutive destination slots via **`rep movsd` of `0x24d` dwords** each.

## Signature

```c
/* Register ABI — not stack formals */
void SkillRow_UninitializedFillN_0x934(
    uint32_t count /*ECX*/,
    uint32_t *dst  /*EAX*/,
    const uint32_t *src /*EBX*/);
/* bare ret; EAX advanced by count*0x934 but not a documented return value */
```

## Algorithm

```
if count == 0: return
for i in 0..count-1:
  if dst != null: memcpy(dst, src, 0x934)   // rep movsd 0x24d
  dst += 0x934 / 4
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004220c0_FUN_004220c0.md`
- Annotated: `docs/reconstruction/raw/aa_004220c0_FUN_004220c0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/SkillRow_UninitializedFillN_0x934.cpp`
- Scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_004220c0.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_004220c0_FUN_004220c0.md`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-0041a8e0-004220c0-w22m-report.md`

## Callers / callees

| Direction | VA | Name / role |
|---|---|---|
| Caller | `0x0041aef0` | `SkillRowVec_EmplaceBack_Stride934_Inferred` (count=1) |
| Caller | `0x0041c9a0` | fill-N + `base + n*0x934` |
| Caller | `0x0041f740` | vector grow/insert fill |
| Callee | — | leaf |

## Confidence

| Claim | Level |
|---|---|
| Stride `0x934` / dword count `0x24d` | **Confirmed** (immediates in body) |
| ECX=count, EAX=dst, EBX=src | **High** (body + call sites) |
| Leaf POD copy (no ctor) | **Confirmed** |
| Element = skill-character row | **Medium** (parent DbLoad path) |
