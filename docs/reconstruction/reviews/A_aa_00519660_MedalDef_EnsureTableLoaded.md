# Review A (reconstruction fidelity): `aa_00519660` MedalDef_EnsureTableLoaded

| Field | Value |
|---|---|
| **Stable ID** | `aa_00519660` |
| **VA** | `0x00519660`–`0x005197a2` |
| **Canonical name** | `FUN_00519660` (proposed: `MedalDef_EnsureTableLoaded`) |
| **Prior names** | `Named_VOG_DEBUG_STOP_00519660` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00519660_MedalDef_EnsureTableLoaded.md` |
| **System** | `missions-progression` (medal / achievement def table) |
| **Evidence pass** | Live Ghidra `batch_decompile` + `disassemble_function` + callees `0051d230`/`0051e4d0`/`00605090`/`007cea40` (2026-07-29) |
| **Verdict** | **accept-with-gaps** (CF/ABI/globals sealed; table English Medal vs Achievement residual) |

---

## 1. Purpose

Global **lazy loader** for the medal/achievement definition hash at **`DAT_00b042e0`**:

1. SEH frame setup.
2. **`FUN_0051d230(4)` with `ECX = 0x00b042e0`** — CNDHash-family **Recreate** (`HashError:Recreate…`); bucket exponent **4** → mask `1<<4` (16 buckets). Clears list heads; occupancy `DAT_00b042ec` (`hash+0xc`) resets via recreate path.
3. Prepare empty growable buffer locals (`begin/end/cap` style triple zeroed).
4. On DB reader object **`DAT_00b0469c`**: `FUN_007e1d80()` (prepare connection), then **`FUN_007cea40(&local_countish, &vector)`** load rows, then `FUN_007b7df0()` teardown-ish.
5. If load HRESULT `< 0`: log **`VOG_DEBUG_STOP`** via `FUN_007a4480` (does **not** early-return — falls into empty loop).
6. For each record in loaded vector, stride **`0x3d4`**:
   - `operator_new(0x1c)` + `FUN_00604e10` zero tail fields → **runtime def object** (`0x1c` bytes).
   - `FUN_00605090(def, id, str@+4, str@+0x46, 0, str@+0x34a, str@+0x248, dword@+0x3cc, dword@+0x3d0)` — fill def (id + string fields + two dwords at def `+0x14/+0x18`).
   - **`FUN_0051e4d0` this=`0x00b042e0`, key=`*def`, value=`def`, soft=`0`** — CNDHash **insert** (`Duplicate hash insert %u…` family).
7. After loop: `operator_delete` vector base (empty-vector early return restores ExceptionList first).

Callers treat this as **ensure-loaded** for `MedalDef_LookupById` (`FUN_0051a0e0`) and CompleteObjective medal toast path when `DAT_00b042ec < 1`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00519660_FUN_00519660.md` |
| Annotated | `docs/reconstruction/raw/aa_00519660_FUN_00519660.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00519660.cpp` |
| Function record | `docs/reconstruction/functions/aa_00519660_FUN_00519660.md` |
| Live listing | `disassemble_function` `0x00519660` (seals `MOV ECX,0xb042e0`) |
| Callers | `FUN_0051a0e0` (lookup lazy); `CVOGReaction_CompleteObjective` (double-call ensure); `FUN_0094a6a0` |
| Sibling duals | `A/B_aa_0051a0e0_MedalDef_LookupById`; `A/B_aa_00530550_CVOGCharacter_AwardMedalById` |

**Not performed:** `disassemble_bytes`, live DB load, full row schema dual of `0x3d4` record.

---

## 3. Signature / ABI (assembly-sealed)

```c
// free function, 0 args, bare RET
void MedalDef_EnsureTableLoaded(void);
```

Critical immediates:

```text
0051967e  PUSH 4
00519680  MOV ECX, 0x00b042e0
00519689  CALL FUN_0051d230          ; Recreate(bucketBits=4)

0051976a  MOV EAX, [EDI]             ; def id
0051976c  PUSH 0                     ; soft flag
0051976d  PUSH EDI                   ; value = def*
0051976e  PUSH EAX                   ; key = id
0051976f  MOV ECX, 0x00b042e0
00519774  CALL FUN_0051e4d0          ; Insert

0051977c  ADD ESI, 0x3d4             ; record stride
005197a2  RET
```

Record stride sealed by both listing add and decompiler `(end-begin)/0x3d4`.

---

## 4. Runtime def object (`0x1c`) after `FUN_00605090`

| Off | Filled from record | Notes |
|---|---|---|
| +0x00 | record+0 | **id** (hash key; lookup arg) |
| +0x04.. | strings via helpers | name / text fields (toast uses def+4 family) |
| +0x14 | record+0x3cc | chain / secondary (AwardMedal uses def+0x14) |
| +0x18 | record+0x3d0 | chain secondary (AwardMedal uses def+0x18) |

Exact string field map open beyond “multiple wide/char copies inside 00605090”.

---

## 5. Data source residual

`FUN_007cea40` (this = `DAT_00b0469c`) contains an XML path branch with literal **`//tAchievement/row`** when `DAT_00d1793c != 0`. That strengthens product **Achievement** table naming even though client toast English is **“Medal”** (`CompleteObjective` / `MedalDef_LookupById` duals).

Loader still targets hash **`DAT_00b042e0`** used exclusively by medal lookup/award/toast paths audited here.

---

## 6. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Free function, 0 args | **High** | listing RET |
| Recreate + insert on `0x00b042e0` | **High** | ECX immediates |
| Bucket bits = 4 | **High** | PUSH 4 |
| Record stride 0x3d4 | **High** | ADD ESI + count formula |
| Def size 0x1c | **High** | operator_new 0x1c |
| Insert key = first dword of def | **High** | PUSH [EDI] |
| Soft insert flag 0 | **High** | PUSH 0 |
| Occupancy at `DAT_00b042ec` | **High** | hash+0xc; lookup gate |
| Table English **medal** | **Probable** | toast/award |
| Table product **tAchievement** | **Probable** | XPath in loader callee |
| Full row schema | **Open** | 0x3d4 layout partial |
| Idempotent if already loaded | **Open** | recreate always runs when called |

---

## 7. Surviving contract

```
MedalDef_EnsureTableLoaded():
  CNDHash_Recreate(&g_MedalHash /*0x00b042e0*/, bucketBits=4)
  rows = DBLoadAchievementOrMedalRows(stride=0x3d4)  // via DAT_00b0469c
  for each row:
    def = new MedalDef(0x1c); fill from row
    CNDHash_Insert(&g_MedalHash, def->id, def, soft=0)
  free(rows buffer)
```

Callers: if `g_MedalHash.count < 1` → call ensure (CompleteObjective may call **twice** if still empty).

---

## 8. Gaps / open

1. Whether calling ensure when table non-empty **wipes** existing inserts (recreate first — **yes** destructive if re-entered).
2. Full 0x3d4 column map and string encodings.
3. PDB name (Medal vs Achievement vs Reward).
4. `FUN_0094a6a0` caller role.

**Verdict:** **accept-with-gaps**
