# Function record: MissionDef_ParseObjectiveXml

| Field | Value |
|---|---|
| **Stable ID** | `aa_00547050` |
| **Canonical name** | `MissionDef_ParseObjectiveXml` |
| **Address** | `0x00547050` |
| **Module** | `autoassault.exe` |
| **System** | `missions-progression` |
| **Completion status** | **Dual A/B accept-with-gaps** (2026-07-29 OWN-ONLY nested residual) |
| **Bit-for-bit / runtime / diff** | Open |
| **Clean fidelity** | Scaffold truncated — use dual + asm, not clean alone |

## Purpose

EnsureXml **`Objective`** tag parser: sequence gate vs mission `+0x130`, bind slots at `+0x13c`, factory-construct requirement types by wide type string (`collect`/`deliver`/…).

## Signature (role)

```c
// Exact formals partial in decompiler; ECX/stack framing from EnsureXml + SEH body
void MissionDef_ParseObjectiveXml(/* mission def + objective XML node context */);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00547050_FUN_00547050.md`
- Annotated: `docs/reconstruction/raw/aa_00547050_FUN_00547050.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FUN_00547050.cpp` (**truncated**)
- Dual A: `docs/reconstruction/reviews/A_aa_00547050_MissionDef_ParseObjectiveXml.md`
- Dual B: `docs/reconstruction/reviews/B_aa_00547050_MissionDef_ParseObjectiveXml.md`

## Callers / callees

- Sole caller: `FUN_00547920` MissionDef_EnsureXmlLoaded
- Notable callees: Collect ctor `0x00611690`, Deliver ctor `0x00610bc0`, other requirement ctors, `_wcsicmp`, `operator_new`

## Confidence

| Claim | Level |
|---|---|
| Objective XML factory role | **High** |
| Collect/Deliver factory arms | **High** |
| Exhaustive type matrix | **Probable** |
| Decompiler body completeness | **Low** (Ghidra unreachable noise) |
