# Function record: Host_AIProfileMap_GetOrReset

| Field | Value |
|---|---|
| **Stable ID** | `aa_00540890` |
| **Canonical name** | `Host_AIProfileMap_GetOrReset` |
| **Ghidra name** | `FUN_00540890` |
| **Address** | `0x00540890` |
| **Body range** | `0x00540890`–`0x005408e9` (**90 B** inclusive last RET) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | npc-ai / host tables / profile map |
| **Completion status** | **partial** — dual A/B **accept-with-gaps**; ABI+CF+layout sealed; product English Probable |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_00540890_Host_AIProfileMap_GetOrReset.md`, `reviews/B_aa_00540890_Host_AIProfileMap_GetOrReset.md` |
| **Last reviewed** | `2026-07-29` (W26-N) |

## Alias

- `FUN_00540890` (Ghidra)
- Prior scaffold: `Named_CalleeOf_CVOGHBAIDriver_DoLogic_00540890`

## Purpose

Return host AI-profile map at `+0xF00`, optionally clearing the MSVC-like RB tree when size is 0 or `forceReset!=0`. Paired with `FUN_004cbd50` lower_bound by HBAI DoLogic callers.

## Signature

```c
// Machine: __thiscall, ECX=host, stack char, RET 4; EAX = host+0xF00
uint32_t __thiscall Host_AIProfileMap_GetOrReset(void *host, char forceReset);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00540890_FUN_00540890.md`
- Annotated: `docs/reconstruction/raw/aa_00540890_FUN_00540890.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Host_AIProfileMap_GetOrReset.cpp`
- Scaffold twin: `docs/reconstruction/reconstructed-exact/FUN_00540890.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-00585e00-00540890-w26n-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callers** | `CVOGHBAIDriver_DoLogic`, `CVOGHBAICreatureBase_DoLogic` (`FUN_005d7f70`), `FUN_004c9430`, `FUN_004c9120`, `FUN_005d7ca0` (each typically ×2: before/after lower_bound) |
| **Callees** | `FUN_005436c0`, `FUN_007c3b80` |

## Confidence

| Claim | Level |
|---|---|
| thiscall + RET 4 + EAX map | **High** |
| MSVC map clear at +0xF00/+4/+8 | **High** |
| Role: AI profile map for HBAI | **High** (caller duals) |
| Product English host/map type | **Probable / Open** |
| Runtime / bit-exact | Open |
