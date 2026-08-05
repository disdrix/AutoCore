# Review B (skeptical / adversarial): `aa_0093d880` Client_ApplyVehicleSwitch_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0093d880` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0093d880_Client_ApplyVehicleSwitch_Inferred.md` |
| **Agent** | W26-S OWN-ONLY |
| **Verdict** | **accept** on CF/ABI/Switch call; **needs-more-evidence** on static invoker + dialog 0x12 English |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Same as `Client_OnVehicleSwitchFailure` | Failure unit is `00810360`; different strings/CF | **Falsified** |
| 2 | thiscall ECX=client | Prologue `mov ebx,eax`; client offsets from EBX | **Falsified** thiscall |
| 3 | Only calls SwitchVehicle | Many UI/pool stages before/after | **Falsified** only |
| 4 | argA/argB from packet | Both pushed as `0xFFFFFFFF` immediates | **Falsified** packet claim |
| 5 | Branches on HRESULT | `B0 01` unconditional success return | **Falsified** branch |
| 6 | Dead code (0 xrefs) | Real body + exclusive nested switch caller role | **Survives** as invoker-open, not dead |
| 7 | Cleans invent inventory fit | Fit lives inside SwitchVehicle, not here | **Falsified** invent |
| 8 | Dialog index unknown | `push 0x12` sealed; English open | **Survives** as 0x12 |
| 9 | Character in EAX | Character from `client+0xe98` into ECX for switch | **Falsified** char-in-EAX |
| 10 | Two stack formals | Single `ret 4` + `[ebp+8]` only | **Falsified** two-formals |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| SwitchVehicle call-site | **High** | Wrong chassis switch entry |
| −1/−1 allocate-id path | **High** | Wrong phys id bump path |
| EAX client ABI | **High** | Wrong this pointer |
| Stage order | **High** | UI/pool desync |
| Static invoker | **Open** | Unknown trigger |
| Dialog 0x12 English | **Tentative** | Wrong UI surface |
| Product English | **Tentative** | Docs only |

---

## 3. Cross-check against raw / image

### Spine

```
client=EAX; newV=[ebp+8]
teardown UI / clear f38 slots
SwitchVehicle(client.char, newV, &out, -1, -1)
garage rebind + dialog 0x12 + pools + mission refresh
return 1
```

### Image seals

| Fact | Pattern |
|---|---|
| Prologue | `55 8B EC 83 E4 F0 51 53 8B D8` |
| newVehicle | `8B 4D 08` |
| Dual sentinel | `6A FF` … `6A FF` |
| Switch | `E8 …` → `005252f0` @ `0093d95b` |
| Dialog | `6A 00 6A 01 6A 12 8B CB E8 …` → `007fef20` |
| Epilogue | `B0 01 … C2 04 00` |

### Contrast `Client_OnVehicleSwitchFailure`

Failure path owns inventory-fit error strings and a **different** call into SwitchVehicle with packet args. This unit is apply-side with fixed −1/−1. Do **not** alias.

Clean preserves spine. **No invented CODE callers. No HRESULT branch invented.**

---

## 4. Surviving contract for AutoCore

```
// Client apply vehicle chassis switch
u8 ApplyVehicleSwitch(Client c, Vehicle* newV):
  // teardown UI slots on c
  Character_SwitchVehicle(c.character, newV, &old, 0xFFFFFFFF, 0xFFFFFFFF)
  // ignore HRESULT
  // rebind garage UI; open dialog index 0x12
  // EnsureRegenerationHeartbeat + RecalcCombatPools(new vehicle)
  // RefreshOpenMissionUiWindows(c)
  return 1
```

Port must preserve UI teardown before switch and the −1/−1 allocate-id pair; do not treat as the failure dialog path.
