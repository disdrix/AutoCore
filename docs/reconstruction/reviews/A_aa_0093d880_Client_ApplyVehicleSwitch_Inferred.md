# Review A (reconstruction fidelity): `aa_0093d880` Client_ApplyVehicleSwitch_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0093d880` |
| **VA** | `0x0093d880`–`0x0093da25` (422 B) |
| **Canonical name (proposed)** | `Client_ApplyVehicleSwitch_Inferred` |
| **Ghidra name** | `FUN_0093d880` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (Path A) |
| **Counterpart** | `reviews/B_aa_0093d880_Client_ApplyVehicleSwitch_Inferred.md` |
| **System tag** | vehicle / client chassis switch |
| **Agent** | W26-S OWN-ONLY |
| **Verdict** | **accept** on CF / ABI / SwitchVehicle call-site; **accept-with-gaps** on invoker + product English + nested helper duals |

**Tools:** Ghidra `decompile_function` + `read_memory` + `analyze_function_complete` + xrefs. No `disassemble_bytes`. No Launcher. No parent ledger edits.

---

## 1. Purpose

Client **apply path** for switching the local character onto a new vehicle chassis: UI teardown → `Character_SwitchVehicle_Inferred(..., 0xFFFFFFFF, 0xFFFFFFFF)` → garage/dialog/pools/mission refresh. Always returns 1.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Live Ghidra decompile | `FUN_0093d880` @ `0x0093d880` (≡ raw CF) |
| Body | `0x0093d880`–`0x0093da25` |
| Prologue | `55 8B EC 83 E4 F0 51 53 8B D8` (EAX→EBX client) |
| Epilogue | `B0 01 … C2 04 00` |
| Switch site | `0x0093d95b` dual push `-1`, outOld, newVehicle, ECX=`[client+0xe98]` |
| Nested dual | W25-E `Character_SwitchVehicle_Inferred` |
| Xrefs | **0** CODE/data |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body end `0x0093da25` | **High** | `get_function_by_address` |
| EAX=client + ret 4 | **High** | prologue/epilogue |
| Stack newVehicle | **High** | `8B 4D 08` before switch |
| argA/argB = −1/−1 | **High** | two `6A FF` at call site |
| Stage order (UI→switch→refresh) | **High** | live ≡ raw |
| Always return 1 | **High** | `B0 01`; no HRESULT branch |
| Static invoker | **Open** | 0 xrefs |
| Product English | **Probable** | `_Inferred` role from SwitchVehicle + UI |

---

## 4. Sealed control flow

```
ApplyVehicleSwitch(client, newVehicle) -> 1
  vehicle = character(+0xe98).vehicle(+0x250)
  vehicle.vbase.vfunc(+0x1c8)()
  flags +0x30b4=1, +0x30b5=0; optional UI teardown
  clear f38 slots +0xc70/+0xc74 via vtbl+0x18(1,1)
  Character_SwitchVehicle(character, newVehicle, &outOld, -1, -1)
  FUN_009147a0(); rebind garage; optional FUN_0085e970
  FUN_007fef20(dialog=0x12, 1, 0)
  copy client+0x9c4 → vehicle +0x105/+0x106
  EnsureRegenerationHeartbeat; RecalcCombatPools
  RefreshOpenMissionUiWindows(client)
  return 1
```

---

## 5. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Client/EAX ABI | **Yes** |
| UI slot clear | **Yes** |
| SwitchVehicle −1/−1 | **Yes** |
| Dialog 0x12 | **Yes** |
| Pools + mission UI | **Yes** |
| Invented CODE callers | **None** — xrefs listed as open |

---

## 6. Gaps / open questions

1. Static invoker (vtable / packet dispatch) not recovered.
2. Dialog index **0x12** product English.
3. Nested helpers `009147a0`, `008801b0`, `0085e970` residual.
4. Intentional ignore of SwitchVehicle HRESULT.
5. Runtime / bit-diff.
