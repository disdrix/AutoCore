# Function record: Client_SelectNearestHostileInRange_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00943520` |
| **Canonical name** | `Client_SelectNearestHostileInRange_Inferred` |
| **Ghidra name** | `FUN_00943520` |
| **Address** | `0x00943520`–`0x009436bb` |
| **Size** | `0x19B` (411 B) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities / client target pick (WQ-009 residual) |
| **Classification** | nearest-hostile gather → resolve → select |
| **Completion status** | **Sealed** — dual A/B 2026-08-04 WQ9R-D |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual verdict** | **accept-with-gaps** |

## Purpose

Bound-action **nearest hostile** target select within a caller-supplied range. Seeds invalid TFID, runs `Skill_GatherTargetsInArea` with **mode 2** / **maxTargets 1** (distance-sorted first, unsorted retry), then `Object_ResolveFromTFID` + `Client_SelectTargetObject_Inferred`. Busy gate shares `char+0x4f1` with select applicator.

Primary poll path uses range **110.0f** (`0x42dc0000`). When cycle state `DAT_00d1d888` is set, sibling `FUN_00943340` cycles the hostile list instead.

## Signature (sealed)

```c
// EAX = client this (not ECX)
// stack float rangeArg; RET 4
void Client_SelectNearestHostileInRange_Inferred(void *client /*EAX*/, float rangeArg);
```

| Param | Location | Meaning |
|---|---|---|
| `client` | `EAX` | client host (`DAT_00d1a840` at PollBound sites) |
| `rangeArg` | `[esp+4]` | gather range (float); poll literal **110.0f** |
| return | — | void (`RET 4`) |

## Gather contract (literals sealed)

| Arg | Pass 1 | Pass 2 (retry if invalid) |
|---|---|---|
| maxTargets | `1` | `1` |
| gatherMode | `2` (hostile) | `2` |
| filterA | `0` | `0` |
| chainRefresh | `0` | `0` |
| allowSelfMode1 | `1` | `1` |
| filterB | `0` | `0` |
| filterC | `1` | `1` |
| sortByDistance | **`1`** | **`0`** |
| scoreArg | `0xbf800000` (−1.0f) | same |

Invalid TFID: `(lo & hi) == 0xffffffff && bGlobal == 0` after seed from `g_abTfidInvalid_A15870` (`0x00a15870` = `FF×8,00×8`).

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00943520_FUN_00943520.md`
- Annotated: `docs/reconstruction/raw/aa_00943520_FUN_00943520.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Client_SelectNearestHostileInRange_Inferred.cpp`
- Scaffold alias: `docs/reconstruction/reconstructed-exact/FUN_00943520.cpp`
- Prior Named plate: `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Client_Input_PollBoundActions_00943520.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00943520_Client_SelectNearestHostileInRange_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_00943520_Client_SelectNearestHostileInRange_Inferred.md`
- Report: `docs/agents/task-dual-ab-00943520-004bb0d0-wq9rd-report.md`

## Callers / callees

**Callees:** `Skill_GatherTargetsInArea` (`0x0058d330`); `Object_ResolveFromTFID` (`0x004bb950`); `Client_SelectTargetObject_Inferred` (`0x0093e120`); virtual `vtbl+0x1a0` (position).

**Callers:**

| Site | Function | Notes |
|---|---|---|
| `0x00927c50` | `Client_Input_PollBoundActions` | range 110; if `DAT_00d1d888==0` else cycle `00943340(...,0)` |
| `0x00927cb9` | same | range 110; else cycle `00943340(...,1)` |
| `0x00927d19` | same | range 110; always nearest |
| `0x00925467` | (no containing fn in Ghidra) | same `push 0x42dc0000` / `MOV EAX, DAT_00d1a840` pattern |

## Confidence

| Claim | Level |
|---|---|
| EAX-this + `RET 4` + range stack | **High** |
| Busy gate `char+0x4f1` | **High** |
| Mode 2 / maxTargets 1 / dual gather sort 1→0 | **High** |
| Invalid TFID test + bank | **High** |
| Resolve ECX from `*(query+0xe4e8)` | **High** (body bytes) |
| Select via `0x0093e120` | **High** |
| Product keybind English | **Open** |
| `*(char_comp+0xa8)` product type | **Probable** (query / host handle) |
| Runtime | **Open** |
