# Review A (reconstruction fidelity): `aa_005b13f0` VehicleNet_PackSkillHBEntry_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b13f0` |
| **VA** | `0x005b13f0` |
| **Canonical name** | `VehicleNet_PackSkillHBEntry_Inferred` (was `FUN_005b13f0`) |
| **Ghidra symbol** | `FUN_005b13f0` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — nested residual of PackUpdate) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005b13f0_VehicleNet_PackSkillHBEntry_Inferred.md` |
| **System** | input-drive-control / GhostVehicle SkillsMask pack |
| **Parent** | `VehicleNet_PackOwnerSkillsHB` `0x005b2830` ← `VehicleNet_PackUpdate` `0x005f5de0` |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Serialize one owner skill/HB payload record** into a BitStream after PackOwnerSkillsHB has selected active entries.

Wire order (live decompile):

1. `writeInt(rec+0x0c, 14)` — 14-bit field A
2. `writeInt(rec+0x0e as s16, 8)` — 8-bit field B
3. `writeInt(rec+0x21 as u8, 8)` — 8-bit field C
4. `writeFlag(param_5-derived)` — presence of extended block (decomp mixes high/low bytes of `param_5`; **flag source residual**)
5. If flag:
   - `writeBits(32, rec+4)` + `writeBits(32, rec+8)` — two dwords
   - Compare `(rec+0x10/0x14/0x18)` vs ghost-parent `this+0x50` fields `+0x160/+0x164/+0x168`
   - `writeFlag(differs)` → if set: `writeBits(64, rec+0x10)` + `writeFlag(rec+0x18)`
   - `writeFlag(rec+0x20)`
   - `writeInt(rec+0x22 as s16, 10)`
   - Same identity-diff pattern for `rec+0x28/0x2c/0x30` vs same parent triple
6. Tail bulk: `writeBits(param_4*8 - 0x1c0, rec+0x38)` — remaining payload bytes after fixed header

**Not** identity pack `0x005b1290`. **Not** the collector walk (`0x005b2830`).

**Caller:** only `FUN_005b2830` / `VehicleNet_PackOwnerSkillsHB`.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` @ `0x005b13f0` |
| Callers | `get_function_callers` → `FUN_005b2830` only |
| Raw / clean | `raw/aa_005b13f0_*`, `reconstructed-exact/FUN_005b13f0.cpp` |
| Parent dual | `A_aa_005b2830_VehicleNet_PackOwnerSkillsHB.md` |

---

## 3. Signature (decompiler-shaped)

```c
// this = ghost / connection context (uses this+0x50 for identity baseline)
void __thiscall PackSkillHBEntry(
  void *this, undefined4 unused_or_stream_ctx,
  SkillHbRec *rec, int totalSizeBytes, undefined4 flagCtx);
```

| Formal | Role | Conf |
|---|---|---|
| `this+0x50` | parent identity baseline for optional TFID-like triples | **High CF** |
| `rec` | packed skill/HB blob | **High** |
| `totalSizeBytes` (`param_4`) | scales tail bit count `size*8 - 0x1c0` | **High** |
| `param_5` | contributes first extended-block flag | **Medium** residual |

---

## 4. Control flow: live sealed

| Stage | Match |
|---|---|
| Fixed 14/8/8 head ints | **Yes** |
| Optional extended + dual identity-diff triples | **Yes** |
| Tail bulk from `+0x38` | **Yes** |
| No equip / no pose | **Yes** |

---

## 5. Confidence

| Claim | Confidence |
|---|---|
| Role = single HB entry pack for SkillsMask path | **High** |
| Head widths 14 / 8 / 8 | **High** |
| Parent identity compare offsets 0x160/164/168 | **High CF** |
| Tail formula `param_4*8 - 0x1c0` | **High** |
| English field names for rec layout | **Low–Medium** residual |
| Exact `param_5` flag ABI | **Medium** residual |

**Verdict:** **accept-with-gaps**
