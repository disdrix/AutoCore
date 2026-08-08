# Function record: Client_UI_CreateNDUIDialogs_InstallHost_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0093e7e0` |
| **Canonical name** | `Client_UI_CreateNDUIDialogs_InstallHost_Inferred` |
| **Ghidra name** | `FUN_0093e7e0` |
| **Address** | `0x0093e7e0`–`0x0093ffa3` (**6084 B** / `0x17C4`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression / client UI init (NDUI dialog host install) |
| **Completion status** | **partial** — dual A/B **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (no Launcher; not claimed Confirmed) |
| **Dual A/B** | `docs/reconstruction/reviews/A_aa_0093e7e0_Client_UI_CreateNDUIDialogs_InstallHost_Inferred.md`, `B_aa_0093e7e0_Client_UI_CreateNDUIDialogs_InstallHost_Inferred.md` |
| **Last reviewed** | `2026-08-05` (MEGA-133 OWN-ONLY) |
| **Partition** | `WAVE_2026-08-05_mega_residual_partition_map.md` → MEGA-133 |

## Alias

- Ghidra: `FUN_0093e7e0`
- Machine twin clean: `FUN_0093e7e0.cpp`

## Alias_prev / rejected

| Name | Status |
|---|---|
| `Named_CalleeOf_Mission_createNDUIDialogs_0093e7e0` | **Retired** scaffold |
| `Combat_DeathRespawnButton` | **Rejected** — `i_g_2d_btn_death_respawn.xml` is one of many widgets |

## Purpose

Implements the body of client **createNDUIDialogs**: phase-timed construction of NDUI dialogs and related UI objects onto a client host object, followed by post-install virtual calls, dialog flags, `winpos.ini` layout (`FUN_00931570`), and debug timing print.

## Signature (sealed)

```c
// ECX not this on entry; stack host*; void; RET 4
void __stdcall Client_UI_CreateNDUIDialogs_InstallHost_Inferred(ClientUiHost* host);
```

| ABI detail | Value | Conf |
|---|---|---|
| Convention | `__stdcall` | **Confirmed** |
| Arg0 | `ClientUiHost* host` (EBP in body) | **Confirmed** |
| Return | void | **Confirmed** |
| Cleanup | `RET 4` | **Confirmed** |

## Evidence highlights

| Item | Detail |
|---|---|
| Plate | `@@CreateNDUIDialogs` @ `0x00a2d610` |
| Parent | `FUN_0094a580` logs `"createNDUIDialogs"` then calls this @ `0x0094a649` |
| Cursor | `i_g_2d_cursor.xml` → `host+0x1168` |
| Death suite | death_bg/fx/msg XML + `i_g_2d_btn_death_respawn.xml` id `0x4e5d` |
| Layout | `"winpos.ini"` → `FUN_00931570` |
| Timing | `(%f) %s\n` + `OutputDebugStringA` |
| Meta | 1506 insns; cyclomatic 97; ~200 calls |

## Artifacts

| Kind | Path |
|---|---|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0093e7e0_FUN_0093e7e0.md` |
| Annotated | `docs/reconstruction/raw/aa_0093e7e0_FUN_0093e7e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_UI_CreateNDUIDialogs_InstallHost_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0093e7e0.cpp` |
| Review A | `docs/reconstruction/reviews/A_aa_0093e7e0_Client_UI_CreateNDUIDialogs_InstallHost_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0093e7e0_Client_UI_CreateNDUIDialogs_InstallHost_Inferred.md` |
| Report | `docs/agents/task-dual-ab-0093e7e0-mega-133-report.md` |

## Callers / callees

| Kind | Value |
|---|---|
| Callers (1) | `FUN_0094a580` (`Mission_createNDUIDialogs` / InitUserInterface wrapper) |
| Callees | See raw re-verify + `tmp/mega133_callees.txt` — dialog ctors, CNDHash, timing, winpos |

## Gaps

1. Per-dialog product class / host-field English catalog.
2. NDUI vtbl slot dictionary.
3. Runtime Confirmed / bit-exact / differential.
4. Parent wrapper dual (out of OWN VA scope).

## Confidence

| Claim | Level |
|---|---|
| CF / body bounds / RET 4 | **Confirmed** |
| Install-role naming | **High** (`_Inferred` for product symbol) |
| Dialog catalog completeness | **Low** (gap) |
