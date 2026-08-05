# Review A (reconstruction fidelity): `aa_007cea40` DbReader_LoadTAchievementRows_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_007cea40` |
| **VA** | `0x007cea40` (large body; many SEH/COM cleanup edges) |
| **Canonical name** | `DbReader_LoadTAchievementRows_Inferred` |
| **Ghidra name** | `FUN_007cea40` |
| **Prior alias** | `Named_tAchievement` (plate `//tAchievement/row`); `Named_CalleeOf_Named_VOG_DEBUG_STOP_007cea40` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_007cea40_DbReader_LoadTAchievementRows_Inferred.md` |
| **System** | missions-progression / DB table load (medal defs) |
| **Live tools** | `batch_decompile`, parent listing, related `DAT_00b0469c` duals |
| **Verdict** | **accept-with-gaps** |
| **Dual status** | **Present (first full dual)** |

---

## 1. Purpose

**Load all `//tAchievement/row` records** into a caller-supplied vector of **0x3d4-byte** row pods; write out row count.

```c
// __thiscall
// ECX = DbReader / RM context*  (parent: *[DAT_00b0469c])
HRESULT LoadTAchievementRows(
  DbReaderCtx *this,
  int *outCount,          // stack
  RowVector *outRows);    // std-like vector; elem size 0x3d4
```

High-level CF:

1. If `*this == 0` (context invalid/flag) → **`0x80004004`**.
2. Branch on **`DAT_00d1793c`**:
   - **`== 0`** (primary path used by medal ensure): open/query via `FUN_0041a810(this+0x28 path…)`, bind columns with repeated `FUN_004231d0`, iterate `FUN_0041c000` / `FUN_0041afe0` copying wchar fields into vector elements; on failure log via `FUN_007a4480` + cleanup.
   - **`!= 0`**: COM/XML path — `SysAllocString(L"//tAchievement/row")`, node walk, BSTR free (same xpath identity).
3. On success path: `*outCount = (end-begin)/0x3d4` (0 if empty begin); return **0**.

Sole static caller of interest: `FUN_00519660` (medal table ensure):

```
CALL FUN_007e1d80              ; DB enter on *[00b0469c]
LEA outCount / LEA vector
MOV ECX, *[00b0469c]
CALL FUN_007cea40
CALL FUN_007b7df0              ; DB leave
if (hr < 0) log VOG_DEBUG_STOP
```

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | ≡ raw (many “unreachable” = SEH) |
| String | `L"//tAchievement/row"` (COM branch) |
| Parent | full listing `0x0051969a`–`0x005196da` |
| Ctx global | `DAT_00b0469c` = `g_pDbReaderCtx*` (peer duals `aa_00512830` / `aa_00512870`) |
| Mode flag | `DAT_00d1793c` (0 → SQL-ish path; else COM) |
| Consumer | loop builds MedalDef 0x1c + `CNDHash_Insert_009ce0a8` |

---

## 3. Row / vector contract (parent-sealed)

| Item | Value | Conf |
|---|---|---|
| Element size | **0x3d4** | **Confirmed** (`IMUL` magic `0x42df9bb1` ÷ 0x3d4) |
| id | `+0x00` dword | **Confirmed** |
| wide fields | `+0x04`, `+0x46`, `+0x248`, `+0x34a` | **Confirmed** (fill map) |
| trailing dwords | `+0x3cc`, `+0x3d0` | **Confirmed** |
| outCount | vector length | **High** |

---

## 4. Confidence

| Claim | Level |
|---|---|
| Role = load tAchievement rows for medal table | **High** |
| `*this==0` → `0x80004004` | **Confirmed** |
| Dual backend via `DAT_00d1793c` | **High** |
| XPath / table id `//tAchievement/row` | **Confirmed** (COM string; primary path same table) |
| Elem size 0x3d4 | **Confirmed** |
| Full column-bind order / field names | **Open** (structural only) |
| COM branch field materialization into vector | **Open** (decompiler residual / unaff_EBX) |
| Bit-exact clean of entire SEH graph | **Open** |
| Product English name | **Probable** Inferred |

**Verdict:** **accept-with-gaps** — structural dual of load role + parent contract sealed; deep column/COM residual remains.
