# Function record: UI_CraftHost_RefreshCraftEnableAndStatus_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008e55e0` |
| **Canonical name** | `UI_CraftHost_RefreshCraftEnableAndStatus_Inferred` |
| **Ghidra symbol** | `FUN_008e55e0` |
| **Address** | `0x008e55e0`–`0x008e598d` inclusive (**942 B** / `0x3AE`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `inventory-transfer` |
| **Completion status** | **Dual sealed** R13-015 (accept-with-gaps); terminal **false** |
| **Bit-for-bit / runtime / diff** | Open (not run) |

## Alias / retired

| Name | Status |
|---|---|
| `FUN_008e55e0` | Ghidra default |
| `Named_CalleeOf_Client_RefreshOpenMissionUiWindows_008e55e0` | **Retired scaffold** — also called from craft bind + tick |

## Purpose

Craft/RE host **refresh of craft-button enable state and status/cost/chance text**. Gates on station range, residual readiness (`FUN_0052d450`), `host+0x7d8`, and credits affordability for memory-craft cost `ceil(sellPrice × 0.85)`.

## Signature

```c
// EAX = craft host*; no stack args; void; plain RET
void UI_CraftHost_RefreshCraftEnableAndStatus_Inferred(void* host /*EAX*/);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_008e55e0_FUN_008e55e0.md`
- Annotated: `docs/reconstruction/raw/aa_008e55e0_FUN_008e55e0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/UI_CraftHost_RefreshCraftEnableAndStatus_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_008e55e0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_008e55e0_UI_CraftHost_RefreshCraftEnableAndStatus_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_008e55e0_UI_CraftHost_RefreshCraftEnableAndStatus_Inferred.md`
- Report: `docs/agents/task-dual-ab-008e55e0-r13-report.md`

## Callers / callees

| Direction | Targets |
|---|---|
| Callers (3) | `UI_CraftHost_BindResolvedObject_Inferred` `0x008e5990` @ `0x008e5caa`; `Client_RefreshOpenMissionUiWindows` @ `0x0093a9c1`; craft tick site @ `0x008e63e3` |
| Notable callees | `008e54a0`, dualed `00520340`, dualed `0052eb90`, `005202d0`, dualed `005142a0`, ceil, `0052d450`, `008e3820`, `008e3940`, localize, sprintf, `008e41b0`, widget vtbls |

## Confidence

| Claim | Level |
|---|---|
| Control flow + ABI from disasm | **High** |
| Product demangle English | **Open** (`_Inferred`) |
| Runtime | **Open** |
