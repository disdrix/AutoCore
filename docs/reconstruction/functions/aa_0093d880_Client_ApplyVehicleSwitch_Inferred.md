# Function record: Client_ApplyVehicleSwitch_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0093d880` |
| **Canonical name** | `Client_ApplyVehicleSwitch_Inferred` |
| **Ghidra name** | `FUN_0093d880` |
| **Address** | `0x0093d880`–`0x0093da25` (422 B; exclusive end `0x0093da26`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | vehicle / client chassis switch apply |
| **Calling convention** | Custom: **EAX**=client*; stack `Vehicle* newVehicle`; AL=1; **`ret 4`** |
| **Completion status** | **Sealed** — dual A/B W26-S 2026-07-29 accept-with-gaps (CF/ABI/Switch call High; invoker + product English open) |
| **Bit-for-bit / runtime / diff** | Open |

## Alias

- `FUN_0093d880`

## Purpose

Client **apply vehicle chassis switch** onto `newVehicle`: tear down related UI, call `Character_SwitchVehicle_Inferred` with allocate-id sentinels, rebind garage UI, open dialog **0x12**, refresh combat pools and mission windows. Always returns 1.

## Signature

```c
uint8_t Client_ApplyVehicleSwitch_Inferred(
    void* client /*EAX*/,
    void* newVehicle /*stack*/);
// RET 4
```

## Behavioral summary (sealed)

1. Vehicle host vfunc `+0x1c8`; prep flags `+0x30b4/+0x30b5`; optional UI teardown.
2. Clear `client+0xf38` slots `+0xc70/+0xc74` via vtbl`+0x18`(1,1).
3. `Character_SwitchVehicle(character, newVehicle, &outOld, 0xFFFFFFFF, 0xFFFFFFFF)`.
4. Post helpers: `FUN_009147a0`, garage `FUN_008801b0`, optional `FUN_0085e970`.
5. `FUN_007fef20(0x12,1,0)`; copy `+0x9c4` → vehicle `+0x105/+0x106`.
6. `Vehicle_EnsureRegenerationHeartbeat` + `Vehicle_RecalcCombatPools`; `Client_RefreshOpenMissionUiWindows`.
7. Return 1 (HRESULT ignored).

## Callers / callees

| Direction | Address / name | Role |
|---|---|---|
| Caller | **none recovered** | 0 CODE/data xrefs in Ghidra |
| Callee | `Character_SwitchVehicle_Inferred` | chassis switch (W25-E) @ `0x0093d95b` |
| Callee | `FUN_007fca10` / `FUN_007fef20` / `FUN_008801b0` / `FUN_0085e970` / `FUN_009147a0` | UI helpers |
| Callee | `Vehicle_EnsureRegenerationHeartbeat` / `Vehicle_RecalcCombatPools` | combat pools |
| Callee | `Client_RefreshOpenMissionUiWindows` | mission UI |

## Confidence by dimension

| Dimension | Level | Rationale |
|---|---|---|
| Function boundary | **High** | Ghidra body `…da25` + pad |
| EAX client + ret 4 | **High** | prologue/epilogue bytes |
| Switch call args −1/−1 | **High** | call-site `read_memory` |
| Stage CF order | **High** | live ≡ raw decompile |
| Static invoker | **Open** | 0 xrefs |
| Product English | **Probable** | `_Inferred` |
| Overall static CF | **High** | dual W26-S |

## Related artifacts

| Kind | Path |
|---|---|
| Raw | `raw/aa_0093d880_FUN_0093d880.md` |
| Annotated | `raw/aa_0093d880_FUN_0093d880.annotated.md` |
| Clean | `reconstructed-exact/Client_ApplyVehicleSwitch_Inferred.cpp` |
| Clean twin | `reconstructed-exact/FUN_0093d880.cpp` |
| Dual A | `reviews/A_aa_0093d880_Client_ApplyVehicleSwitch_Inferred.md` |
| Dual B | `reviews/B_aa_0093d880_Client_ApplyVehicleSwitch_Inferred.md` |
| Nested switch | `A/B_aa_005252f0_Character_SwitchVehicle_Inferred.md` |

## Open questions

- Static invoker (vtable/dispatch).
- Dialog index 0x12 product name.
- Nested helper duals not owned.
