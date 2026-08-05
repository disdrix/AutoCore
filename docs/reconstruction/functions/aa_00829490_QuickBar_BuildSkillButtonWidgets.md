# Function record: QuickBar_BuildSkillButtonWidgets

| Field | Value |
|---|---|
| **Stable ID** | `aa_00829490` |
| **Canonical name** | `QuickBar_BuildSkillButtonWidgets` |
| **Address** | `0x00829490` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities |
| **Completion status** | **Human-refined** — annotated + clean upgraded; dual review still open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Constructs skill quickbar button child widgets: background, icon, name, value, keynum, cooldown gauge (i_d_qb_2d_btn_quickbar_cooldown.xml), activate FX.

## Signature (refined)

```c
void __fastcall QuickBar_BuildSkillButtonWidgets(void *pButton);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00829490_QuickBar_BuildSkillButtonWidgets.md`
- Annotated: `docs/reconstruction/raw/aa_00829490_QuickBar_BuildSkillButtonWidgets.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/QuickBar_BuildSkillButtonWidgets.cpp`

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Packet / UI offsets in notes | Probable–High |
| Types / names | Probable |
