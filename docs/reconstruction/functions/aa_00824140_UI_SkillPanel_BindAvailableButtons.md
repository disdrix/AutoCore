# Function record: UI_SkillPanel_BindAvailableButtons

| Field | Value |
|---|---|
| **Stable ID** | `aa_00824140` |
| **Canonical name** | `UI_SkillPanel_BindAvailableButtons` |
| **Address** | `0x00824140` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities |
| **Completion status** | **String-renamed scaffold** - clean named twin + FUN_ retained; refine + dual review still open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Original / decompiler: `FUN_00824140`
- Prior auto-slug names (if any): leave on disk; canonical is `UI_SkillPanel_BindAvailableButtons`

## Purpose

Binds skill-panel widgets from i_d_s_2d_btn_skill_available/btn.xml templates.

## String evidence

`"i_d_s_2d_btn_skill_available.xml" / "i_d_s_2d_btn_skill_btn.xml"`

## Signature (decompiler-derived)

```c
void __fastcall UI_SkillPanel_BindAvailableButtons(int *param_1)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00824140_FUN_00824140.md`
- Annotated: `docs/reconstruction/raw/aa_00824140_FUN_00824140.annotated.md`
- Clean (canonical): `docs/reconstruction/reconstructed-exact/UI_SkillPanel_BindAvailableButtons.cpp`
- Clean (FUN scaffold retained): `docs/reconstruction/reconstructed-exact/FUN_00824140.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Naming from string literals | High |
| Parameter semantic names | Probable / Tentative |
| Types | Tentative |
