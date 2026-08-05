# Review A (reconstruction fidelity): `aa_006078e0` Outpost_UpdateBeaconShareRatio

| Field | Value |
|---|---|
| **Stable ID** | `aa_006078e0` |
| **VA** | `0x006078e0` |
| **Body** | `0x006078e0`–`0x006079e2` |
| **Canonical name** | `Outpost_UpdateBeaconShareRatio` |
| **Former name** | `FUN_006078e0` |
| **Review date** | `2026-07-29` (W19-O) |
| **Reviewer role** | Reconstruction fidelity (outpost beacon-share ratio update) |
| **Counterpart** | `reviews/B_aa_006078e0_Outpost_UpdateBeaconShareRatio.md` |
| **System** | `skills-abilities` / outpost |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Recompute the outpost's **beacon-share ratio** (`factionBeacons / totalBeacons`) into `this+0x24c`. When the ratio **changes**, run pre-recast bank walk `FUN_00606ff0` then `Outpost_CastSkillsForBeaconShare` for the current faction. When total beacons ≤ 0, **log** and leave ratio untouched.

This is the **sole producer** of the ratio gate consumed by `Outpost_CastSkillsForBeaconShare` (`aa_006070e0`).

---

## 2. Inspected evidence

| Source | Detail |
|---|---|
| Live Ghidra | `decompile_function` `0x006078e0`; callees `0x005b05f0`, `0x00606ff0`, `0x006070e0`, `0x007a4480`; caller `0x006082e0` |
| `read_memory` | body @ `0x006078e0` (256); constants `0x00a0f2a0` / `0x00a0f518`; thunk `0x006079f0` |
| Raw | `docs/reconstruction/raw/aa_006078e0_FUN_006078e0.md` (+ 2026-07-29 re-verify) |
| Annotated | `docs/reconstruction/raw/aa_006078e0_FUN_006078e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Outpost_UpdateBeaconShareRatio.cpp` |
| Sibling dual | `Outpost_CastSkillsForBeaconShare` (ratio consumer) |
| String | `"Total beacons was %f on map %s"` @ `0x009de88c` |

**Tools:** decompile + read_memory (+ callers/callees/analyze). **No** `disassemble_bytes`. **No** Launcher.

---

## 3. Signature

```c
// MSVC __thiscall: ECX = outpost object
void __thiscall Outpost_UpdateBeaconShareRatio(void *thisOutpost);
```

| Claim | Evidence | Conf |
|---|---|---|
| ECX = this | `8B F1` | **High** |
| No stack args | epilogue `C3` not `C2 xx 00` | **High** |
| Decompiler `__fastcall` | label only | noise |

---

## 4. Control flow (sealed)

```
total     = g_flOne;  factionB = 0;  old = *(float*)(this+0x24c)
LookupVariable(id=*(this+0x1d0),               &total, 0)
LookupVariable(id=*(this+0xf0+faction*0x48),  &factionB, 0)
  where faction = *(int*)(this+0x234)

if total <= 0:
  log(0, "Total beacons was %f on map %s", total, mapName)
  return                                    // +0x24c NOT written

new = factionB / total
*(float*)(this+0x24c) = new                 // always when total > 0
if old != new:
  FUN_00606ff0(faction)                     // thiscall ECX=this
  Outpost_CastSkillsForBeaconShare(faction)
return
```

### Offsets

| Off | Role |
|---:|---|
| `+0x1d0` | total-beacons map-var id |
| `+0x234` | faction index |
| `+0xf0+f*0x48` | faction-beacons map-var id |
| `+0x24c` | ratio float (out) |

### Constants

| Symbol | Address | Value |
|---|---|---|
| `g_flOne` | `0x00a0f2a0` | 1.0f |
| `g_flZero` | `0x00a0f518` | 0.0f |

---

## 5. Call graph

| Address | Name | Role |
|---|---|---|
| `0x005b05f0` | `CVOGMap_LookupVariable` | total + faction counts |
| `0x00606ff0` | `FUN_00606ff0` | change path only — flag==0 bank side-effects |
| `0x006070e0` | `Outpost_CastSkillsForBeaconShare` | change path only |
| `0x007a4480` | log | total ≤ 0 |
| Caller `0x006082e0` | CaptureOutpost | after `*(+0x234)=newFaction` |
| Thunk `0x006079f0` | MI adjust `-0x260` | not owned |

---

## 6. Side effects

- Writes `this+0x24c` when total > 0.
- May trigger skill bank recast path (callees).
- Log only on invalid total.
- **No** direct network in this unit.

---

## 7. Confidence

| Area | Level |
|---|---|
| CF + ratio math + store | **High** |
| String / total≤0 path | **High** |
| Change → 00606ff0 + BeaconShare | **High** |
| Faction stride 0x48 | **High** |
| Map-var product English | **Medium** (role sealed; field names residual) |
| `FUN_00606ff0` full semantics | **Medium** (sibling residual) |
| Product method name | **Inferred** |

---

## 8. Gaps

1. PDB / product English for method and map-var slots.
2. Dual of `FUN_00606ff0`.
3. Runtime live capture; binary diff; bit-exact.
4. Thunk vtbl slot / secondary interface identity (`-0x260`).
