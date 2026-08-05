# Function record: AssManager_EnsureAssPreloader_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0075d3c0` |
| **Canonical name** | `AssManager_EnsureAssPreloader_Inferred` |
| **Ghidra name** | `FUN_0075d3c0` |
| **Address** | `0x0075d3c0`–`0x0075d466` (**166 B** / `0xA6`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | assets / assManager + assPreloader |
| **Completion status** | Dual A/B sealed W33-O 2026-07-29 — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Ensure the AssManager host (`DAT_00d1f050` / NDResourceCache) owns an AssPreloader at `+0x6c`. On first create, construct with `FUN_00970cf0` and seed the preloader's locked PodU32U8 ring at `+0xAC` from every key currently on the host tracked-asset circular list (`host+8`).

## Signature

```c
// stack host*; RET 4; void
void AssManager_EnsureAssPreloader_Inferred(void* host /*stack*/);
```

## Host / preloader offsets (sealed)

| Off | Object | Role |
|-----|--------|------|
| `host+0x08` | AssManager | circular list sentinel (keys at `node+0x08`) |
| `host+0x6c` | AssManager | AssPreloader* (null → allocate) |
| `pre+0xAC` | AssPreloader | GuardedVector locked stride-2 U32U8 ring (CS `+0xC0`, enable `+0xD8`) |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0075d3c0_FUN_0075d3c0.md`
- Annotated: `docs/reconstruction/raw/aa_0075d3c0_FUN_0075d3c0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/AssManager_EnsureAssPreloader_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_0075d3c0.cpp`
- FUN record: `docs/reconstruction/functions/aa_0075d3c0_FUN_0075d3c0.md`
- Review A/B: `docs/reconstruction/reviews/A_aa_0075d3c0_AssManager_EnsureAssPreloader_Inferred.md`, `B_…`
- Agent report: `docs/agents/task-dual-ab-0075d3c0-00970e50-w33o-report.md`

## Confidence

| Claim | Level |
|---|---|
| CF + ABI (RET 4, stack host) + offsets | **High** |
| AssPreloader family (ctor +0x6c secondary host pattern) | **High** |
| Product method English | **Inferred** |
| Nested ctor / pack formal product types | **Open** |
| Runtime / bit-exact | **Open** |
