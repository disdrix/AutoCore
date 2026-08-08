# Function record: Object_ApplyPrimaryAndLocalMaterialBanks_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c5510` |
| **Canonical name** | `Object_ApplyPrimaryAndLocalMaterialBanks_Inferred` |
| **Ghidra name** | `FUN_004c5510` |
| **Address** | `0x004c5510`–`0x004c555d` (**78 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | object / gfx material bank |
| **Completion status** | **Dual sealed** (A+B 2026-08-05 R10-029) — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Parent dual** | `0x005194f0` `Gfx_BindMatDiffuseAmbientEmissive_Inferred` |
| **Wave** | R10-029 residual dual |

## Purpose

Apply **primary** object material bank (after MI base adjust from `this-0x4FC`) and, when present, bind a **local** MatDiffuse/Ambient/Emissive color bank at `this-0x20C` through host `this-0x27C`.

## Signature (sealed)

```c
void __thiscall Object_ApplyPrimaryAndLocalMaterialBanks_Inferred(void *subThis /* ECX */);
```

## Control flow (summary)

```
primary = (subThis - 0x4FC) + *(int*)(*(subThis-0x4FC)+4)
Object_ApplyMaterialBank_Inferred(primary)
if host@-0x27C && begin@-0x208 && count((end-begin)>>4):
  Gfx_BindMatDiffuseAmbientEmissive_Inferred(host, subThis-0x20C)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004c5510_FUN_004c5510.md` (R10 re-verify append)
- Annotated: `docs/reconstruction/raw/aa_004c5510_FUN_004c5510.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Object_ApplyPrimaryAndLocalMaterialBanks_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_004c5510.cpp`
- FUN record: `docs/reconstruction/functions/aa_004c5510_FUN_004c5510.md`
- Review A: `docs/reconstruction/reviews/A_aa_004c5510_Object_ApplyPrimaryAndLocalMaterialBanks_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_004c5510_Object_ApplyPrimaryAndLocalMaterialBanks_Inferred.md`
- Report: `docs/agents/task-dual-ab-004c5510-r10-report.md`

## Callers / callees

| Direction | Targets |
|---|---|
| Callee | `Object_ApplyMaterialBank_Inferred` (`0x0051b310`); `Gfx_BindMatDiffuseAmbientEmissive_Inferred` (`0x005194f0`) |
| Entry | JMP MI adjustors `0x004cc9f3`, `0x0053bcf9` |

## Confidence

| Claim | Level |
|---|---|
| ABI / dual-path CF / offsets | **High** |
| Not skill-cast | **High** |
| Product class name | Open (`_Inferred`) |
