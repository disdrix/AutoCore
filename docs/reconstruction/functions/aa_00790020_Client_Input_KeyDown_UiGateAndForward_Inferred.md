# Function record: Client_Input_KeyDown_UiGateAndForward_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00790020` |
| **Canonical name** | `Client_Input_KeyDown_UiGateAndForward_Inferred` |
| **Ghidra name** | `FUN_00790020` |
| **Address** | `0x00790020`–`0x00790098` (**121 B** / `0x79`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `input-drive-control` |
| **Partition** | MEGA-094 (hint: key normalize / UI gate) |
| **Completion status** | **Dual sealed** — Path A/B **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |
| **Terminal** | **false** |

## Alias

- Ghidra: `FUN_00790020`
- Retired scaffold: `Named_CalleeOf_Client_Input_OnKeyDown_MatchAction_00790020`

## Purpose

Client/UI-host virtual **OnKeyDown**-style method:

1. If `this->vtbl+0x3D8()` is false → return **0** (input blocked).
2. If `this+0x4BC` (focused UI) non-null → `focused->vtbl+0x358(key, lParam)`.
3. If `key == 0x1B` (ESC):
   - UI present → `this->vtbl+0x3BC(0)`; return **1**.
   - Else if `this+0x49C >= 0` (secondary modal code) → return `this->vtbl+0x338(8, code)`.
4. Else return **1**.

Does **not** rewrite the key code; parent `Client_Input_OnKeyDown_MatchAction` uses the return as a gate/continue byte.

## Signature (sealed)

```c
uint32_t __thiscall Client_Input_KeyDown_UiGateAndForward_Inferred(
    int *self, int key, uint32_t lParam);
// ECX=self; RET 8
```

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00790020_FUN_00790020.md` |
| Annotated | `docs/reconstruction/raw/aa_00790020_FUN_00790020.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_Input_KeyDown_UiGateAndForward_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00790020.cpp` |
| Review A | `docs/reconstruction/reviews/A_aa_00790020_Client_Input_KeyDown_UiGateAndForward_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00790020_Client_Input_KeyDown_UiGateAndForward_Inferred.md` |
| FUN record | `docs/reconstruction/functions/aa_00790020_FUN_00790020.md` |
| Report | `docs/agents/task-dual-ab-00790020-mega-094-report.md` |

## Call graph (owned unit only)

```text
Client_Input_OnKeyDown_MatchAction  [dualed parent]
FUN_00866220                        [residual]
FUN_008cc420                        [residual]
  └─► Client_Input_KeyDown_UiGateAndForward_Inferred  [OWN MEGA-094]
        ├─ vtbl+0x3D8() gate
        ├─ (+0x4BC)->vtbl+0x358(key,lParam)  optional forward
        ├─ ESC: vtbl+0x3BC(0)                if UI
        └─ ESC: vtbl+0x338(8, +0x49C)        if secondary modal
```

## Confidence

| Claim | Level |
|---|---|
| CF / ABI / RET 8 | **High** |
| ESC + modal action-8 path | **High** |
| Multi-caller + virtual install | **High** |
| Product slot English | Open → `_Inferred` |

## Dual verdict

| Path | Verdict |
|---|---|
| A fidelity | **accept-with-gaps** |
| B adversarial | **accept-with-gaps** |
