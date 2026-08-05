# Review A (reconstruction fidelity): `aa_0054b2c0` SkillDefMap_EnsureInitialized

| Field | Value |
|---|---|
| **Stable ID** | `aa_0054b2c0` |
| **VA** | `0x0054b2c0`–`0x0054b475` |
| **Canonical name** | `SkillDefMap_EnsureInitialized` (INFERRED; Ghidra `FUN_0054b2c0`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (one-shot skill-def table init) |
| **Counterpart** | `reviews/B_aa_0054b2c0_SkillDefMap_EnsureInitialized.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**One-shot skill definition table / map initializer** for the global skill-def store around `DAT_00b04734` / `DAT_00b04738`.

Called when **`DAT_00b04724 == 0`** from:

- `CVOGReaction_ResolveSkillTargets` (`0x0054c570`)
- `FUN_0054b480` (returns `&DAT_00b04734` after ensure)
- `Skill_EvaluateRankedElements` (named caller list)

Body always stamps **`DAT_00b04724 = 1`** early (re-entrancy / once flag), runs sub-inits `FUN_0054a1a0` + `FUN_0054a640`, then branches on **`DAT_00b04694`**:

| Branch | Behavior (sealed CF) |
|---|---|
| `DAT_00b04694 == 0` | Clear tree head `DAT_00b04738` (self-links + size `DAT_00b0473c=0`); load blob via `FUN_007e34b0`; on fail → `VOG_DEBUG_STOP`; else walk records **stride `0x934`**, process each with `FUN_0054a290`, free per-record heap at **`record+0x930`** |
| `DAT_00b04694 != 0` | Alternate teardown of vector-like range `DAT_00b0435c..DAT_00b04360` (delete first element + container) |

SEH frame present (`ExceptionList`, filter `LAB_009a4622`). Ends with `FUN_007989b0` + restore ExceptionList; epilogue **`add esp,0x30; ret`** (no stack args).

**Not** a cast-time per-skill helper — it is **global skill table bootstrap / reload path**.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0054b2c0_FUN_0054b2c0.md` |
| Annotated | `docs/reconstruction/raw/aa_0054b2c0_FUN_0054b2c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_0054b2c0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0054b2c0_FUN_0054b2c0.md` |
| Live Ghidra | `batch_decompile` / `analyze_function_complete` / `audit_globals_in_function` |
| Bytes | `read_memory` end @ `0x0054b460` → `83 C4 30 C3` |
| String | `"VOG_DEBUG_STOP"` on load failure (`FUN_007a4480`) |
| Parent dual | `A_aa_0054c570_*` — lazy gate `DAT_00b04724` |
| Related | `FUN_0054b480` = ensure + return `&DAT_00b04734`; `FUN_0054a290` installs skill rows (string `"Skill %d had no skill elements..."`) |

---

## 3. Signature (sealed)

```c
void SkillDefMap_EnsureInitialized(void);  // no args; ret (C3) after local frame cleanup
```

| Global | Role (sealed / high) |
|---|---|
| `DAT_00b04724` | once/init flag (set **1** at entry of this fn) |
| `DAT_00b04734` | map header (returned by `0054b480`; `this` for finds) |
| `DAT_00b04738` | map end / head node pointer |
| `DAT_00b0473c` | cleared to 0 on tree reset (size-like) |
| `DAT_00b04694` | mode flag selecting load path vs vector teardown |
| `DAT_00b0435c/60/64` | alternate container begin/end/cap |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| SEH setup | **Yes** |
| `DAT_00b04724 = 1` | **Yes** |
| Sub-inits `0054a1a0` / `0054a640` | **Yes** |
| Mode branch `DAT_00b04694` | **Yes** |
| Tree clear + stride-`0x934` install loop | **Yes** |
| `VOG_DEBUG_STOP` on load fail | **Yes** |
| Alternate vector free path | **Yes** |
| `FUN_007989b0` + ExceptionList restore | **Yes** |

**Note:** decompiler marks some `operator_delete` paths “does not return” — treat as SEH/noreturn annotation noise unless proven; clean mirrors raw.

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Lazy skill-map bootstrap | **High** | callers + flag |
| Sets `DAT_00b04724=1` | **Confirmed** | body |
| Clears/rebuilds map at `DAT_00b04738` when mode 0 | **Confirmed** | body |
| Record stride `0x934`; free at `+0x930` | **Confirmed** | loop math |
| Install worker `FUN_0054a290` | **High** | string skill-elements; also uses `00418890` |
| Mode-1 path frees `DAT_00b0435c` range | **Confirmed** CF | product meaning open |
| Full wad/load format of `007e34b0` | **Open** | not owned here |
| Product name | **Open** | structural |

---

## 6. Gaps

1. What `DAT_00b04694` means in product (editor vs game vs reload).
2. Exact file/table source loaded by `FUN_007e34b0(local_30)`.
3. Roles of `FUN_0054a1a0` / `FUN_0054a640` (owned elsewhere).
4. Whether delete “does not return” paths are real noreturn or decompiler artifacts.
5. Runtime / bit-exact open.

**Verdict:** **accept-with-gaps**
