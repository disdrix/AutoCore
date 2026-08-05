# Function record: Client_RefreshInteractPromptTarget_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_009210e0` |
| **Canonical name** | `Client_RefreshInteractPromptTarget_Inferred` |
| **Ghidra name** | `FUN_009210e0` |
| **Address** | `0x009210e0`–`0x00921355` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `interaction-activation` |
| **Classification** | periodic proximity pick + interact prompt update |
| **Completion status** | **Sealed** — dual A/B 2026-07-29 W18-L; CF/radii/modes/ABI sealed |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual verdict** | **accept-with-gaps** |

## Purpose

On a timer tick from `FUN_009216e0`, refresh the client's proximity interact target and update the on-screen "Press … to interact/talk/pick up/trade" prompt (`FUN_008a81a0`). Selection cascade mirrors Activate-path geometry (15f / 225 dist²) but **does not** send C2S UseObject.

## Signature (sealed)

```c
// RET 4 cleans one stack dword (caller pushes client this; body does not read it)
void Client_RefreshInteractPromptTarget_Inferred(void *client_unused);
// Side effect: ESI = selected object* (or null) into FUN_008a81a0
```

## Selection algorithm (sealed)

1. Gate: `DAT_00d1b8c8` non-null and `vtbl+0x3d8()` true.
2. Player origin: adj-this(`DAT_00d1b6d8`) `vtbl+0x1a0` float4.
3. Prefer `DAT_00d1d888` if non-null, identity ≠ local char, dist² ≤ **225.0f**.
4. Else `FUN_0058cd60` mode **6**, r=**15**, resolve TFID.
5. On candidate: `Client_MaybeShowFirstTimeTip(3)`; if non-null → prompt update.
6. Else `Skill_GatherTargetsInArea` mode **3**, r=15; resolve.
7. Else if `*(DAT_00d1b644+0xf5)`: mode **7**, filterA **0x14**; resolve.
8. Else `Client_FindFirstObjectInRadius(15.0f)`.
9. Always (if gate passed): `FUN_008a81a0(DAT_00d1b8c8)`.

## Constants

| Name | Value | Role |
|---|---|---|
| gather radius | **15.0f** (`0x41700000`) | all gather / FindFirst sites |
| max select dist² | **225.0f** (`DAT_00aaaca4`) | keep `DAT_00d1d888` |
| tip id | **3** | first-time tip on candidate path |
| mode 6 / 3 / 7 | sealed literals | gather family (see `Skill_GatherTargets*` duals) |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_009210e0_FUN_009210e0.md`
- Annotated: `docs/reconstruction/raw/aa_009210e0_FUN_009210e0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Client_RefreshInteractPromptTarget_Inferred.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_009210e0.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_009210e0_FUN_009210e0.md`
- Review A/B: `docs/reconstruction/reviews/A|B_aa_009210e0_Client_RefreshInteractPromptTarget_Inferred.md`
- Report: `docs/agents/task-dual-ab-009210e0-006173a0-w18l-report.md`

## Callers / callees

**Callees:** `FUN_0058cd60`, `Skill_GatherTargetsInArea`, `Object_ResolveFromTFID`, `Client_MaybeShowFirstTimeTip`, `Client_FindFirstObjectInRadius` (`FUN_009197a0`), `FUN_008a81a0`.

**Callers (1):** `FUN_009216e0` (timer; after `vtbl+0x478`).

## Confidence

| Claim | Level |
|---|---|
| CF from decompiler ≡ raw ≡ live | **High** |
| 15f / 225 dist² constants | **High** (bytes + read_memory) |
| Not a UseObject sender | **High** (no send callees) |
| Modes 6 / 3 / 7+0x14 | **High** (push immediates) |
| Product name | **Tentative** (`_Inferred`) |
| `DAT_00d1b8c8` product type | **Tentative** |
