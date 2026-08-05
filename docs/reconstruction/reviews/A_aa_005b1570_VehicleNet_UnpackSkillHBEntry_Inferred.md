# Review A (reconstruction fidelity): `aa_005b1570` VehicleNet_UnpackSkillHBEntry_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b1570` |
| **VA** | `0x005b1570` |
| **Canonical name** | `VehicleNet_UnpackSkillHBEntry_Inferred` (was `FUN_005b1570`) |
| **Ghidra symbol** | `FUN_005b1570` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — nested residual of UnpackGhost) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005b1570_VehicleNet_UnpackSkillHBEntry_Inferred.md` |
| **System** | input-drive-control / GhostVehicle SkillsMask unpack |
| **Parent** | `VehicleNet_UnpackOwnerSkillsHB` `0x005b2690` ← `VehicleNet_UnpackGhostVehicle` `0x005f7720` |
| **Pack twin** | `VehicleNet_PackSkillHBEntry` `0x005b13f0` |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Deserialize one skill/HB payload** into a buffer — **structured** mirror of `0x005b13f0`, **not** a naive bulk bit-copy (parent dual wording corrected here).

Live CF:

1. `readInt(14)` → `out+0x0c` (u16)
2. `readInt(8)` → `out+0x0e`
3. `readInt(8)` → `out+0x21`
4. Stamp `*out = 0x2014` (skill/HB message family opcode)
5. Read **flag bit** from stream cursor (`stream+0x18` bit index vs max `+0x2c`; oversize sets `stream+0x1c = 1` fail sticky)
6. If flag **clear** → fill defaults from `this+0x40..+0x4c` into out slots; clear mid fields
7. If flag **set**:
   - `readBits(32)` → `out+4`; `readBits(32)` → `out+8`
   - Optional 64-bit + flag via `FUN_00424e50` into identity A (`out+0x10..`)
   - Flag → `out+0x20` bool
   - `readInt(10)` → `out+0x22`
   - Optional identity B (`out+0x28..`) same pattern
8. Tail: if `param_4 > 0x38`: `readBits((param_4-0x38)*8, out+0x38)`

**Caller:** only `FUN_005b2690` / `VehicleNet_UnpackOwnerSkillsHB`.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` @ `0x005b1570` |
| Callers | `get_function_callers` → `FUN_005b2690` |
| Raw / clean | `raw/aa_005b1570_*`, `FUN_005b1570.cpp` |
| Pack twin | `A_aa_005b13f0_*` (this batch) |
| Parent dual | `A_aa_005b2690_VehicleNet_UnpackOwnerSkillsHB.md` |

---

## 3. Signature

```c
// this = baseline identity context (ghost/owner fields +0x40..)
// stream = BitStream* (param_2; may also be thiscall stream)
// out = allocated entry buffer
// size = total byte size from wire u16
void __thiscall UnpackSkillHBEntry(
  void *this, BitStream *stream, void *out, int size);
```

---

## 4. Confidence

| Claim | Confidence |
|---|---|
| Structured pack/unpack twin of `0x005b13f0` | **High** |
| Opcode stamp **0x2014** | **High** |
| Head widths 14/8/8 + optional extended | **High** |
| Tail `(size-0x38)*8` from `out+0x38` | **High** |
| Oversize bit cursor → sticky fail `stream+0x1c` | **High** |
| Field English names | **Low–Medium** residual |
| Parent "bulk bit-copy" description | **Superseded** by this dual |

**Verdict:** **accept-with-gaps**
