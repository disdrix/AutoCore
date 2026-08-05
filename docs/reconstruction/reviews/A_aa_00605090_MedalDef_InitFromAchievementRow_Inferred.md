# Review A (reconstruction fidelity): `aa_00605090` MedalDef_InitFromAchievementRow_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00605090` |
| **VA** | `0x00605090`–`0x00605241` (**~0x1b2** bytes; `ret 0x20`) |
| **Canonical name** | `MedalDef_InitFromAchievementRow_Inferred` |
| **Ghidra name** | `FUN_00605090` |
| **Prior alias** | `Named_CalleeOf_Named_VOG_DEBUG_STOP_00605090` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_00605090_MedalDef_InitFromAchievementRow_Inferred.md` |
| **System** | missions-progression (medal / tAchievement row → def) |
| **Live tools** | `batch_decompile`, full listing, parent arg map, string-setter callees |
| **Verdict** | **accept-with-gaps** |
| **Dual status** | **Present (first full dual)** |

---

## 1. Purpose

**Populate a 0x1c MedalDef** from one **tAchievement** row (element stride **0x3d4**):

```c
// __thiscall  ret 0x20  (8 stack dwords)
// returns true (AL=1)
bool MedalDef_InitFromAchievementRow(
  MedalDef *this,
  uint32_t id,                 // param_2  row+0x00
  const wchar_t *wstr0,        // param_3  row+0x04
  const wchar_t *wstr1,        // param_4  row+0x46
  /*unused*/ void *pad,        // param_5  parent passes 0 — never read
  const wchar_t *wstr3,        // param_6  row+0x34a  → slot +0x10
  const wchar_t *wstr2,        // param_7  row+0x248  → slot +0x0c
  uint32_t fieldA,             // param_8  row+0x3cc  → +0x14
  uint32_t fieldB);            // param_9  row+0x3d0  → +0x18
```

Control flow:

1. `*this = id`.
2. For each of four wide strings: `GetACP`-style via `PTR_FUN_00af8c9c` → `FUN_00403450` (WideCharToMultiByte into temp buffer ≤0x80 stack / else heap) → dedicated setter:
   - wstr0 → `FUN_00604e90` → `this+0x04`
   - wstr1 → `FUN_00604f10` → `this+0x08`
   - wstr2 (param_7) → `FUN_00604f90` → `this+0x0c`
   - wstr3 (param_6) → `FUN_00605010` → `this+0x10`
3. Free any heap temp buffers (SEH-aware).
4. `this+0x14 = fieldA`; `this+0x18 = fieldB`.
5. Return **1**.

**param_5 is unused** in the body (parent pushes 0).

Sole static caller: `FUN_00519660` loop over loaded rows.

---

## 2. Parent arg map (sealed listing)

From `0x0051972c`–`0x00519765` (row base = `local_18 + index*0x3d4`):

| Push order (RTL) | Row off | Stack param | Def off |
|---|---|---|---|
| fieldB | `+0x3d0` | param_9 | `+0x18` |
| fieldA | `+0x3cc` | param_8 | `+0x14` |
| &row+0x248 | wstr | param_7 | → `+0x0c` mbcs |
| &row+0x34a | wstr | param_6 | → `+0x10` mbcs |
| 0 | — | param_5 | **unused** |
| &row+0x46 | wstr | param_4 | → `+0x08` |
| &row+0x04 | wstr | param_3 | → `+0x04` |
| row dword | `+0` | param_2 | `+0x00` id |
| ECX | — | this | MedalDef* |

---

## 3. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | ≡ raw (unreachable free blocks = SEH cleanup edges) |
| Live listing | ends `MOV AL,1` / `RET 0x20` |
| W→A helper | `FUN_00403450` + `PTR_FUN_00af8c9c` |
| Slot setters | `00604e90`/`00604f10`/`00604f90`/`00605010` (free-old + copy) |
| Zero precursor | `FUN_00604e10` |
| Row loader | `FUN_007cea40` (`//tAchievement/row`) |

---

## 4. Confidence

| Claim | Level |
|---|---|
| CF A≡B ≡ raw; `ret 0x20` | **Confirmed** |
| id + 4 mbcs strings + 2 dwords | **Confirmed** |
| param_5 unused | **Confirmed** |
| Row stride 0x3d4 field map | **Confirmed** (parent) |
| String semantic labels (name/desc/…) | **Open** |
| fieldA/fieldB product meaning | **Open** |
| Exception-path free exactness | **High** structural; SEH residual |

**Verdict:** **accept-with-gaps.**
