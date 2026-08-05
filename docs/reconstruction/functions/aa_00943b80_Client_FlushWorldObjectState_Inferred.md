# Function record: Client_FlushWorldObjectState_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00943b80` |
| **Canonical name** | `Client_FlushWorldObjectState_Inferred` |
| **Ghidra name** | `FUN_00943b80` |
| **Address** | `0x00943b80`–`0x00943dae` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client-session / world-object containers |
| **Completion status** | **Dual sealed** (W23-E 2026-07-29) — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Alias

- Ghidra: `FUN_00943b80`
- Prior scaffold: `Named_CalleeOf_Named_Server_needs_an_update_00943b80` (caller-seeded; incomplete)

## Purpose

**Flush client world-object / container state** during session teardown, sector reconnect, and related leave paths:

1. Clear host interaction flag; optional equip-gfx host list clear.
2. Drain container at `client+0xd28` (Release payloads, re-ring empty).
3. Two-pass TFID export via `FUN_004bae00` + `ObjectList_ExportTfidsToMap`.
4. `flag!=0` adds UI vtbl close/open and a list insert at `+0xf00`.

## Signature

```c
// this in EDI; stack char flag; RET 4
void Client_FlushWorldObjectState_Inferred(void *self /*EDI*/, char flag);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00943b80_FUN_00943b80.md` (+ W23-E live seal)
- Annotated: `docs/reconstruction/raw/aa_00943b80_FUN_00943b80.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Client_FlushWorldObjectState_Inferred.cpp`
- Alias clean: `docs/reconstruction/reconstructed-exact/FUN_00943b80.cpp`
- Reviews: `reviews/A_aa_00943b80_Client_FlushWorldObjectState_Inferred.md`, `reviews/B_aa_00943b80_Client_FlushWorldObjectState_Inferred.md`

## Callers / callees

**Callers (6):** `FUN_008153b0`, `FUN_00943fb0`, `FUN_00944b20` (TeardownGameplaySession, flag=0), `FUN_009466f0` (flag=1), `FUN_009492d0`, `FUN_009493c0` (Net_InitNetworking_sector).

**Callees (17):** see review A table / live `get_function_callees`.

## Confidence

| Claim | Level |
|---|---|
| Control flow structure from decompiler ≡ raw | **High** |
| EDI this + stack flag + RET 4 | **High** |
| Role = world/container flush on leave/reconnect | **High** |
| Product English name | **Probable** (`_Inferred`) |
| Nested helper product names / +0xd28 exact type | **Tentative** / open |
| Free-loop completeness when isnil==0 | **Open** (decompiler gap) |
| Runtime / bit-exact | **Open** |
