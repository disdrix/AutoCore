# Function record: CVOGHBAI_ProfileType4_DoLogic_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d7ca0` |
| **Canonical name** | `CVOGHBAI_ProfileType4_DoLogic_Inferred` |
| **Ghidra name** | `FUN_005d7ca0` |
| **Address** | `0x005d7ca0` |
| **Body range** | `0x005d7ca0`–`0x005d7dd0` (**305 B** inclusive last `RET`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | npc-ai / HBAI / profile-type-4 |
| **Completion status** | **partial** — dual A/B **accept-with-gaps**; CF/ABI/vtbl sealed; product class English open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_005d7ca0_CVOGHBAI_ProfileType4_DoLogic_Inferred.md`, `reviews/B_aa_005d7ca0_CVOGHBAI_ProfileType4_DoLogic_Inferred.md` |
| **Last reviewed** | `2026-07-29` (W27-I) |

## Alias

- `FUN_005d7ca0` (Ghidra)
- Prior scaffold: `aa_005d7ca0_FUN_005d7ca0`

## Purpose

Main tick for HBAI subclass installed by factory profile type **4** (`FUN_005d7de0` → `PTR_FUN_009db08c`). Resolve AI profile row; clear `owner+0x278`; branch on `owner+0x26c` with skill sets 0/2, aim-offset update, busy/path gates, pursue (`FUN_005cf560`), and vtbl method tails. Structural twin of sealed Driver/CreatureBase DoLogic (binary state only).

## Signature

```c
// Machine: __thiscall ECX=this; void; bare RET
void __thiscall CVOGHBAI_ProfileType4_DoLogic_Inferred(int *self);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005d7ca0_FUN_005d7ca0.md` (+ W27-I append)
- Annotated: `docs/reconstruction/raw/aa_005d7ca0_FUN_005d7ca0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGHBAI_ProfileType4_DoLogic_Inferred.cpp`
- Scaffold twin: `docs/reconstruction/reconstructed-exact/FUN_005d7ca0.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-004c9430-005d7ca0-w27i-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Xrefs** | DATA `0x009db0dc` only (vtbl slot; virtual dispatch) |
| **Callees** | `Host_AIProfileMap_GetOrReset` ×2, `Map_LowerBoundFindByIntKey_Isnil65`, `FUN_004c3c80`, `NPC_TryCastSkillFromSet` ×2, `CVOGHBAI_UpdateAimOffset_Inferred` ×2, `FUN_005cc980` ×2, `FUN_005cebd0`, `FUN_005cf560`, `FUN_005cc450`, owner/self vtbls |

## Key offsets

| Off | Role |
|---|---|
| `this+0x64` (`[0x19]`) | owner object |
| `this+0x60` (`[0x18]` low) | path/mode byte gate |
| `this[6]+0xa0` | selected target present |
| `owner+0x26c` | combat state (0 vs non-0 here) |
| `owner+0x278` | cleared via `FUN_004c3c80(0)` |
| def `+0x4dc` | profile map key |

## Confidence

| Claim | Level |
|---|---|
| thiscall void bare ret | **High** |
| Profile lower_bound early-out | **High** |
| Binary owner+0x26c SM + skill sets 0/2 | **High** |
| Vtbl membership type-4 | **High** |
| Method name DoLogic | **Probable** (structural; no plate) |
| Product class English | **Open** |
| Runtime / bit-exact | Open |
