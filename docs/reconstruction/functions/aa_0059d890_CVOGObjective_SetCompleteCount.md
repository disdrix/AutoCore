# Function record: CVOGObjective_SetCompleteCount

| Field | Value |
|---|---|
| **Stable ID** | `aa_0059d890` |
| **Canonical name** | `CVOGObjective_SetCompleteCount` |
| **Ghidra name** | `FUN_0059d890` |
| **Address** | `0x0059d890` |
| **Body range** | `0x0059d890`–`0x0059d89c` (13 B; exclusive end `0x0059d89d`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression |
| **Completion status** | **partial** — dual A/B **accept**; CF + bytes + CompleteCount field sealed; load-parent residual |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_0059d890_CVOGObjective_SetCompleteCount.md`, `reviews/B_aa_0059d890_CVOGObjective_SetCompleteCount.md` |
| **Last reviewed** | `2026-07-29` (W21-J) |

## Alias

- `FUN_0059d890` (Ghidra)
- Setter sibling of `CVOGObjective_GetCompleteCount` (`aa_0059d880`)

## Purpose

**Write objective template field CompleteCount** at **`this+0x164`**. Pure store; no side effects beyond that dword.

Product name sealed by getter dual + XML serializer `FUN_005468c0` → `<CompleteCount>`.

## Signature

```c
void __thiscall CVOGObjective_SetCompleteCount(void* objective /* ECX */, std::uint32_t completeCount);
// ret 4
```

## Algorithm

1. `*(uint32_t*)(objective + 0x164) = completeCount;`
2. return (callee cleans 4 stack bytes).

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0059d890_FUN_0059d890.md`
- Annotated: `docs/reconstruction/raw/aa_0059d890_FUN_0059d890.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGObjective_SetCompleteCount.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_0059d890.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-0074e910-0059d890-w21j-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | none |
| **Callers** | `FUN_00547050` only — site `0x005478a9` (`push eax; call`) |
| **Sibling getter** | `aa_0059d880` @ `0x0059d880` — `mov eax,[ecx+0x164]; ret` |

## Confidence

| Claim | Level |
|---|---|
| Body is store `+0x164` + `ret 4` | **High** |
| ECX = objective this | **High** |
| Field = CompleteCount | **High** (sibling + XML) |
| Sole static caller | **High** (1 xref) |
| Product setter spelling | Open |
| Full parse path in parent | Open (parent residual) |
| Runtime / bit-exact | Open |

## Related

- `aa_0059d880` CVOGObjective_GetCompleteCount
- `aa_00533f90` CVOGReaction_CompleteObjective (uses getter)
- `aa_00534920` CVOGCharacter_EvaluatePendingObjectives (uses getter)
- `FUN_005468c0` objective XML dump
- `FUN_00547050` load/parse writer parent
