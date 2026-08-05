# Review B (skeptical / adversarial): `aa_00521310` CVOGCharacter_CreateApply_AttachVehicleAddToMap_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00521310` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00521310_CVOGCharacter_CreateApply_AttachVehicleAddToMap_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This is a callee of `CVOGSectorMap_AddCharacter` | scaffold alias | **Falsified** — body **calls** AddCharacter; xrefs from CreateFromPacket |
| 2 | Only adds to map, no vehicle link | | **Falsified** — `SetVehicle` via `004c49d0` after resolve |
| 3 | Uses packet vehicle TFID at arbitrary offset | | **Falsified for this unit** — uses character fields `-0xb90/-0xb8c` |
| 4 | Always runs LOD boost | | **Falsified** — requires `*param_2==0x2016` + RTTI cast success |
| 5 | Skips AddCharacter when no vehicle | | **Falsified** — AddCharacter is unconditional after SetVehicle attempt |
| 6 | `0x4479c000` is a pointer | | **Falsified** — float **999.0f** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| SetVehicle on create | **High** | Player vehicle HP/owner bugs if omitted server-side |
| AddCharacter always | **High** | Character missing from sector list |
| this_adj − 0xda0 base | **High** | Wrong object passed to map |
| param_3..6 meanings | **Low** | Only matter when flag set |

---

## 3. Surviving contract for AutoCore

```
on CharacterCreateApply(this_adj, pkt, ..., flag):
  if flag: optional_pre(pkt, ...)
  vehicle = Resolve(CurrentVehicleCoid on character)
  SetVehicle(character, vehicle)
  if vehicle: post(vehicle); vehicle.flag101 = !character.flag_a94
  SectorMap.AddCharacter(characterBase)
  if pkt.type == 0x2016 and AutoAssault LOD handler: LOD_helper(0, 999.0)
  if equipGfxHost.list: ClearListIfFlag()
```

**Port tests:**

* Create with CurrentVehicleCoid set → SetVehicle called before map add.
* Create with null vehicle → still AddCharacter; no crash on vehicle+0x101.
* Non-0x2016 packet → no LOD helper call.

---

## 4. Open questions

1. Second xref `0x0053bed3` owner function.
2. Whether `FUN_0053d970(0)` requires ECX=vehicle (decompiler shows bare call; likely fastcall residual).

**Verdict:** **accept-with-gaps**
