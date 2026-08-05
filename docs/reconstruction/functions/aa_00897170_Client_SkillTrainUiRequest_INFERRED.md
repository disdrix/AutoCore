# Function record: Client_SkillTrainUiRequest_INFERRED

| Field | Value |
|---|---|
| **Stable ID** | `aa_00897170` |
| **Canonical name** | `Client_SkillTrainUiRequest_INFERRED` |
| **Address** | `0x00897170` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities |
| **Completion status** | **Human-refined** — annotated + clean upgraded; dual review still open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Skill-train UI request. On first-rank train of active skill, auto-maps into first empty QuickBar slot, CVOGCharacter_SetQuickBarSkill, sends QuickBarUpdate 0x2062 + SkillIncrement 0x2059.

## Signature (refined)

```c
void Client_SkillTrainUiRequest_INFERRED(int *pUi, unsigned skillId);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00897170_Client_SkillTrainUiRequest_INFERRED.md`
- Annotated: `docs/reconstruction/raw/aa_00897170_Client_SkillTrainUiRequest_INFERRED.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Client_SkillTrainUiRequest_INFERRED.cpp`

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Packet / UI offsets in notes | Probable–High |
| Types / names | Probable |
