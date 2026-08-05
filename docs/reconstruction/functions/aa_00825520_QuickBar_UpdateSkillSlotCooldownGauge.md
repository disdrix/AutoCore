# Function record: QuickBar_UpdateSkillSlotCooldownGauge

| Field | Value |
|---|---|
| **Stable ID** | `aa_00825520` |
| **Canonical name** | `QuickBar_UpdateSkillSlotCooldownGauge` |
| **Address** | `0x00825520` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities |
| **Completion status** | **Human-refined** — annotated + clean upgraded; dual review still open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Updates quickbar skill button cooldown gauge. Prefers charge/CD fields on skill when skill+0x628 set; else Skill_GetCategoryCooldownRemaining(skill+0x5e8). Drives i_d_qb_2d_btn_quickbar_cooldown.xml.

## Signature (refined)

```c
void __fastcall QuickBar_UpdateSkillSlotCooldownGauge(void *pButton);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00825520_QuickBar_UpdateSkillSlotCooldownGauge.md`
- Annotated: `docs/reconstruction/raw/aa_00825520_QuickBar_UpdateSkillSlotCooldownGauge.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/QuickBar_UpdateSkillSlotCooldownGauge.cpp`

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Packet / UI offsets in notes | Probable–High |
| Types / names | Probable |
