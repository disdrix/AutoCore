# Function record: Ui_NameColorLevelBand_CopyFloat4_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0092d580` |
| **Canonical name** | `Ui_NameColorLevelBand_CopyFloat4_Inferred` |
| **Ghidra name** | `FUN_0092d580` |
| **Address** | `0x0092d580`–`0x0092d5fb` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client UI / entity name-label color |
| **Name confidence** | **High** role (level-band float4 copy); product English **Inferred** |
| **Completion status** | **Dual residual sealed 2026-08-04 WQ9E-C** — accept |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Leaf helper: map signed **levelDiff** onto one of **eight** 16-byte slots on a host object (`+0xBE4` … `+0xC54`, stride `0x10`) and copy that float4 to the caller out buffer. Used by name-color level packing and mission dialog/journal UI tinting.

## Signature

```c
float* Ui_NameColorLevelBand_CopyFloat4_Inferred(
    void* host /*ECX*/, int levelDiff /*EDX*/, float out[4] /*EAX*/);
// bare ret; EAX = out
```

## Sealed facts

| Claim | Confidence |
|---|---|
| Eight band offsets / signed thresholds | **High** |
| 16 B dword×4 copy | **High** |
| ABI ECX/EDX/EAX leaf | **High** |
| UI color consumer (not combat accuracy) | **High** |
| Host RTTI / float table values | **Open** |
| Product symbol | **Open** |

### Band map

| levelDiff | offset |
|---|---|
| ≤−5 | +0xBE4 |
| −4..−3 | +0xBF4 |
| −2..−1 | +0xC04 |
| 0 | +0xC14 |
| 1..2 | +0xC24 |
| 3..4 | +0xC34 |
| 5..6 | +0xC44 |
| ≥7 | +0xC54 |

## Callers

- `Ui_ResolveEntityNameColor_Inferred` (`0x00930fc0`)
- `Client_NpcDialog_PrepareResponseOpcode` (`0x008abd70`)
- `FUN_00829b20`, `FUN_0082a050` (mission journal UI family)

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0092d580_FUN_0092d580.md`
- Annotated: `docs/reconstruction/raw/aa_0092d580_FUN_0092d580.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Ui_NameColorLevelBand_CopyFloat4_Inferred.cpp`
- Scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_0092d580.cpp`
- Prior alias clean: `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Client_NpcDialog_PrepareResponseOpcode_0092d580.cpp`
- Review A/B: `docs/reconstruction/reviews/A_aa_0092d580_Ui_NameColorLevelBand_CopyFloat4_Inferred.md`, `B_aa_0092d580_Ui_NameColorLevelBand_CopyFloat4_Inferred.md`
- Scaffold record: `docs/reconstruction/functions/aa_0092d580_FUN_0092d580.md`

## Prior alias

`Named_CalleeOf_Client_NpcDialog_PrepareResponseOpcode_0092d580` — superseded by role name.
