# Function record: FUN_005be2b0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005be2b0` |
| **Canonical name** | `ObjectMotion_SlotReleaseToFreelist_Inferred` (preferred) |
| **Ghidra name** | `FUN_005be2b0` |
| **Address** | `0x005be2b0`–`0x005be2e9` exclusive (**57** B / `0x39`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client object motion / reaction slot freelist |
| **Completion status** | **Sealed** — dual A/B W28-I 2026-07-29; **accept** |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

Preferred: `ObjectMotion_SlotReleaseToFreelist_Inferred`.  
Legacy scaffold human name: `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_missileExplo_005be2b0` — **reject** as product claim.

## Purpose

Release a motion-slot payload (and optional nested child at `+0x8`) onto the global freelist headed at `DAT_00b036c0`. Invoked when `ObjectMotion_SlotTick` returns 0 (remove) and when the motion host tears down list `+0xA24`.

## Signature (decompiler-derived, W28-I sealed)

```c
void __thiscall FUN_005be2b0(int *freelist_head /* ECX */, int *slot_node /* stack */);
// ret 4
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005be2b0_FUN_005be2b0.md`
- Annotated: `docs/reconstruction/raw/aa_005be2b0_FUN_005be2b0.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/ObjectMotion_SlotReleaseToFreelist_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_005be2b0.cpp`
- Named record: `docs/reconstruction/functions/aa_005be2b0_ObjectMotion_SlotReleaseToFreelist_Inferred.md`

## Callers / callees

| Direction | Target | Notes |
|---|---|---|
| Caller | `FUN_005bb5e0` @ `0x005bb624` | SlotListTick remove; ECX=`DAT_00b036c0` |
| Caller | `FUN_005bbc50` @ `0x005bbd0e` | Teardown walk; ECX=`DAT_00b036c0` |
| Callee | `FUN_004b0bd0` | Empty thiscall stub (×2) |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | **High** |
| Freelist ABI + global head | **High** (caller bytes) |
| Parameter semantic names | **Probable** (`_Inferred`) |
| Types | **Tentative** (SlotNode structural) |
