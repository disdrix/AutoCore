# Function record: FUN_005d7de0 / CVOGHBAI_ProfileType4_ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d7de0` |
| **Canonical name** | `CVOGHBAI_ProfileType4_ctor_Inferred` |
| **Ghidra name** | `FUN_005d7de0` |
| **Address** | `0x005d7de0` |
| **Body range** | `0x005d7de0`–`0x005d7df8` (**25 B** / `0x19`; `RET 4`; pad `CC`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | npc-ai / HBAI / profile-type-4 |
| **Completion status** | **partial** — dual A/B **accept-with-gaps**; CF/ABI/vtbl/factory sealed; product class English + base mid-ctor residual |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_005d7de0_CVOGHBAI_ProfileType4_ctor_Inferred.md`, `reviews/B_aa_005d7de0_CVOGHBAI_ProfileType4_ctor_Inferred.md` |
| **Last reviewed** | `2026-07-29` (W28-K) |

## Alias

- `FUN_005d7de0` (Ghidra)
- Prior scaffold: `aa_005d7de0_FUN_005d7de0`

## Purpose

Thin leaf ctor for the HBAI subclass selected by AI-profile map type word **4**: chain mid-base `FUN_005d1990(this, owner)`, then install vtbl `PTR_FUN_009db08c` (owns sealed DoLogic `0x005d7ca0` at +0x50).

## Signature

```c
// Machine: __thiscall; RET 4; returns this
void * __thiscall CVOGHBAI_ProfileType4_ctor_Inferred(void *self, void *pOwner);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005d7de0_FUN_005d7de0.md` (+ W28-K append)
- Annotated: `docs/reconstruction/raw/aa_005d7de0_FUN_005d7de0.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/CVOGHBAI_ProfileType4_ctor_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_005d7de0.cpp`
- Function named: `docs/reconstruction/functions/aa_005d7de0_CVOGHBAI_ProfileType4_ctor_Inferred.md`
- Report: `docs/agents/task-dual-ab-005d6b80-005d7de0-w28k-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Caller** | `Object_EnsurePrimaryHBAI_FromAIProfile` @ `0x004c9556` (factory case 4; sole code xref) |
| **Callees** | `FUN_005d1990` only (not OWN) |
| **DoLogic sibling** | `CVOGHBAI_ProfileType4_DoLogic_Inferred` @ `0x005d7ca0` (vtbl+0x50) |

## Offsets / factory

| Item | Value |
|---|---|
| Object size | **0xC0** (`operator_new` case 4) |
| Vtbl | `0x009db08c` |
| DoLogic DATA | `0x009db0dc` → `0x005d7ca0` |

## Confidence

| Claim | Level |
|---|---|
| thiscall + RET 4 thin chain | **High** |
| vtbl install `009db08c` | **High** |
| Factory type-4 / size 0xC0 linkage | **High** (parent W27-I) |
| Name ProfileType4 (structural) | **Probable** |
| Product class English | **Open** |
| Base mid-ctor field map | **Open** (separate VA) |
| Runtime / bit-exact | Open |
