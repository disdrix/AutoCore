# Function record: Client_CastFirstHardpointSkillFlag200_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008c4fc0` |
| **Canonical name** | `Client_CastFirstHardpointSkillFlag200_Inferred` (**INFERRED**) |
| **Address** | `0x008c4fc0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities / host hardpoint cast |
| **Completion status** | **Partial** — three-rep + dual A/B sealed **WQ8R-F 2026-08-04**; runtime/diff open |
| **Bit-for-bit / runtime / diff** | Open (not run; no Launcher) |

## Alias

| Name | Notes |
|---|---|
| `FUN_008c4fc0` | Ghidra default / scaffold |
| “QB skill path” | Parent dual shorthand (`TryUseModChip` B review) — body is **hardpoint HB**, not quick-bar slot walk |

## Purpose

Host-mode leaf: if local character `+0x6b8` is set, walk the locked hardpoint/HB list (player or vehicle `MI+0xb4`), take the first enabled `CVOGHBSkillBase`, and when skill flags `+0x614` include **bit 0x200**, cast `skillId` at `+0x5fc` via `Client_CastSkillFromQuickBarSlot`.

## Signature

```c
// no stack formals; RET after ADD ESP,8
void Client_CastFirstHardpointSkillFlag200_Inferred(void);
```

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_008c4fc0_FUN_008c4fc0.md` |
| Annotated | `docs/reconstruction/raw/aa_008c4fc0_FUN_008c4fc0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_CastFirstHardpointSkillFlag200_Inferred.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_008c4fc0.cpp` |
| Review A | `docs/reconstruction/reviews/A_aa_008c4fc0_Client_CastFirstHardpointSkillFlag200_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_008c4fc0_Client_CastFirstHardpointSkillFlag200_Inferred.md` |
| Agent report | `docs/agents/task-dual-ab-008c4fc0-0082f510-wq8rf-report.md` |

Scaffold record: `functions/aa_008c4fc0_FUN_008c4fc0.md`.

## Callers

| CALL VA | Parent | Notes |
|---|---|---|
| `0x008c510f` | `FUN_008c50f4` | Only when `player+0x6b8 && !player+0x6b9` |

## Callees

| VA | Name | Role |
|---|---|---|
| `0x004294f0` | `List_TraversalLock` | Enter list CS; set `+0x28` |
| `0x004022a0` | `List_IterateNext` | Cursor walk; `0` = more |
| RTTI | `__RTDynamicCast` | `CVOGHBBase` → `CVOGHBSkillBase` |
| Win32 | `LeaveCriticalSection` | Unlock list `+4` |
| `0x009418e0` | `Client_CastSkillFromQuickBarSlot` | Cast with ESI=client, skillId stack |

## Key layouts / constants

| Symbol | Role |
|---|---|
| `DAT_00d1b6d8` | Local character |
| `player+0x6b8` | Host-mode gate (must be set) |
| `player+0x30c` | Host-link byte; 0 → use player list |
| `player+0x250` | Vehicle ptr; with `+0x30c` selects vehicle list |
| `MI+0xb4` | HB/hardpoint list host pointer |
| HB `+0x1c` | Type tag; **1** = skill family |
| SkillHB `+0x140` | Enable / armed byte |
| SkillHB `+0x24` | Skill runtime object base |
| skill `+0x614` bit **0x200** | Cast gate for this leaf |
| skill `+0x5fc` | Skill id pushed to cast |
| `DAT_00d1a840` | Global client (ESI at cast) |

## Confidence

| Claim | Level |
|---|---|
| Control flow from live decompile ≡ raw | **High** |
| Sole caller `FUN_008c50f4` | **High** |
| List helpers TraversalLock / IterateNext | **High** (registry + strings) |
| RTTI skill-HB filter | **High** |
| Flag mask `0x200` + skillId `+0x5fc` | **High** (`read_memory`) |
| Client ESI = `&DAT_00d1a840` | **High** |
| Product English for `+0x6b8` / bit 0x200 | **Tentative** / **Open** |
| Product / PDB symbol | **Open** |
| Runtime / bit-exact | **Open** |
