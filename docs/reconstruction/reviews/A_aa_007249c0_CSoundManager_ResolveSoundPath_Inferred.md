# Review A (reconstruction fidelity): `aa_007249c0` CSoundManager_ResolveSoundPath_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_007249c0` |
| **VA** | `0x007249c0` |
| **Canonical name** | `CSoundManager_ResolveSoundPath_Inferred` |
| **Ghidra symbol** | `FUN_007249c0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual A/B) |
| **Counterpart** | `reviews/B_aa_007249c0_CSoundManager_ResolveSoundPath_Inferred.md` |
| **System** | client audio / `CSoundManager` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Resolve a playable sound file path** from a candidate string, supporting **pipe-separated alternates** (`|`). Returns pointer to a **static buffer** (`DAT_00d20d98`) holding the chosen path, or **null** if none exist.

Authoritative stages (live ≡ raw):

1. **Copy** `param_2` (path / alternates) into global **`DAT_00d20d98`** (byte loop until NUL).
2. **`strchr(buf, '|')`** (0x7C):
   - **No pipe:** existence probe **`FUN_00724870(param_1, 0, 0)`** with path in buffer/`EAX`.
     - Fail: optional log `FUN_007a4480(0, "Sound file doesn't exist: %s", buf)` if `param_3 != 0`; return **null**.
     - Success: return **`&DAT_00d20d98`**.
   - **Has pipe:**
     - Init local `vector<char*>` (`local_18/14/10`), scope guard `FUN_00480390`.
     - `strtok(buf, "|")` loop:
       - Existence check each token via `FUN_00724870`.
       - Missing: optional same log for that token.
       - Present: push token pointer into vector (`FUN_00419880` grow or in-place).
       - Early break if `*(char*)(param_1+0x308) != 0` **and** vector size **> 2**.
     - Empty vector → null.
     - Size 0 after filter → `operator_delete` (decompiler “does not return” noise on some edges).
     - **`CVOGReaction_RandomUnitScalar`** + **`FUN_00424830`** pick one entry; free vector; return chosen path (via static buffer / selected token).

**String evidence:** `"Sound file doesn't exist: %s"` — seals audio-resolve role.

**Callers:** `FUN_007258a0`, `Client_PlayNamedInterfaceSound`, `FUN_007252d0`, `FUN_00725a70`, `FUN_00725bd0`, `FUN_004a4fa0` (drive).

Typical parent: `path = FUN_007249c0(descOrCtx, DAT_00d1a614)` — second arg is locale/base path blob from global.

---

## 2. Inspected artifacts

| Artifact | Path / source | This pass |
|---|---|---|
| Raw / annotated / clean | `aa_007249c0_*` | CF ≡ live |
| Live decompile | Ghidra `0x007249c0` | sealed |
| Existence helper | `FUN_00724870` (`PathFileExistsA` + search roots) | High |
| Complete analysis | 6 xrefs; multi-callee worker | |
| Parent duals | proximity / UI / drive | |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Static work buffer `DAT_00d20d98` | **Confirmed** | copy target + return |
| `|` alternate list | **Confirmed** | `strchr`/`strtok` 0x7C / `"\|"` |
| Existence via `FUN_00724870` | **Confirmed** | both arms |
| Log string on miss when `param_3` | **Confirmed** | plate string |
| Return null on total miss | **Confirmed** | |
| Random pick among existing alternates | **High** | RandomUnitScalar + pick helper |
| `param_1+0x308` caps multi-hit collect (>2) | **High** | early break |
| `thiscall` / exact `param_1` type (manager vs descriptor) | **Medium** | parents pass entry or manager-ish |
| `DAT_00d1a614` exact role | **Medium** | path/locale input residual |
| Decompiler “does not return” on delete paths | **Medium** | likely EH/tail false positive |
| Product name | **Probable** | `Snd_Sound_file_doesn_exist` plate alias |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Copy into static buf | Yes |
| No-`|` single resolve | Yes |
| Pipe split / collect hits | Yes |
| Random select among hits | Yes |
| Log + null on miss | Yes |

```text
ResolveSoundPath(ctx, pathOrList, logMissing):
  copy pathOrList → DAT_00d20d98
  if no '|':
    if FileExists(ctx, buf): return buf
    if logMissing: log("Sound file doesn't exist: %s", buf)
    return null
  hits = []
  for token in split(buf, '|'):
    if FileExists(ctx, token): hits.push(token)
    elif logMissing: log(... token)
    if ctx.flag(+0x308) && hits.size > 2: break
  if hits.empty: return null
  return random_choice(hits)  // via RandomUnitScalar + 00424830; buffer/static
```

---

## 5. Callers / callees

**Callees:** `strchr`, `strtok`, `FUN_00724870`, `FUN_007a4480`, `FUN_00480390`, `FUN_00419880`, `CVOGReaction_RandomUnitScalar`, `FUN_00424830`, `operator_delete`.

**Callers (6):** `FUN_007252d0`, `FUN_007258a0`, `FUN_00725a70`, `FUN_00725bd0`, `Client_PlayNamedInterfaceSound`, `FUN_004a4fa0`.

---

## 6. Gaps / open

1. Exact identity of `param_1` (CSoundManager vs FX descriptor) across call sites.
2. Whether random pick rewrites `DAT_00d20d98` or returns interior token pointers into it (strtok mutates).
3. Full semantics of `+0x308` flag (debug / quality / voice limit).
4. Runtime not run.

**Verdict:** **accept-with-gaps** — path resolve + `|` random alternate sealed by string + CF.
