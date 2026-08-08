# Function record: UI_ArenaTournamentSchedule_CreateChildWidgets_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0086b9b0` |
| **Canonical name** | `UI_ArenaTournamentSchedule_CreateChildWidgets_Inferred` (**INFERRED**) |
| **Address** | `0x0086b9b0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory-transfer (UI arena tournament-schedule chrome builder) |
| **Completion status** | **Partial** — three-rep + dual A/B sealed **R13-009 2026-08-05**; runtime/diff open |
| **Bit-for-bit / runtime / diff** | Open (not run; no Launcher) |

## Alias

| Name | Notes |
|---|---|
| `FUN_0086b9b0` | Ghidra default / scaffold synonym |
| `UI_arena_tournament_schedule_mini_label` | Prior plate auto-alias from one mini string — **superseded** |

## Purpose

Virtual method on the Arena Tournament Schedule dialog: build the full child widget tree from `i_d_arena/i_d_arena_tournament_schedule_*.xml` plates, apply default tab chrome policy (tournament selected; console/advanced collapsed + move-to-front), construct mini status cluster, then run residual finalize helpers. Not an inventory grab/drop/equip packet path.

## Signature

```c
// __thiscall ECX = host*; no stack args; plain RET
void UI_ArenaTournamentSchedule_CreateChildWidgets_Inferred(void* host_ecx);
```

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0086b9b0_FUN_0086b9b0.md` |
| Annotated | `docs/reconstruction/raw/aa_0086b9b0_FUN_0086b9b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UI_ArenaTournamentSchedule_CreateChildWidgets_Inferred.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_0086b9b0.cpp` |
| Review A | `docs/reconstruction/reviews/A_aa_0086b9b0_UI_ArenaTournamentSchedule_CreateChildWidgets_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0086b9b0_UI_ArenaTournamentSchedule_CreateChildWidgets_Inferred.md` |
| Scaffold record | `docs/reconstruction/functions/aa_0086b9b0_FUN_0086b9b0.md` |
| Agent report | `docs/agents/task-dual-ab-0086b9b0-r13-report.md` |

## Callers / callees

| Direction | Detail |
|---|---|
| Callers | **0** direct CALL; **1** DATA xref `0x00a5ed20` (vtbl `+0x43C`) |
| Callees | `operator_new`, `FUN_007b5dd0`×many, `FUN_0079c860`, `FUN_00864f20`, `FUN_0078b6e0`, `FUN_0078f890`, `FUN_008230b0`×3, `FUN_00822cb0`×3, `FUN_00756c90`×2, `FUN_00792600`, `FUN_0086b370`, `FUN_0086a900`, `FUN_0086b3c0` (cond), host/child vcalls |

## Confidence

| Claim | Level |
|---|---|
| Role = schedule dialog create-child-widgets virtual | **High** |
| ABI ECX thiscall + plain RET | **High** |
| Tab default policy | **High** |
| Product English name | **Open** (`_Inferred`) |
| Runtime | **Open** |
