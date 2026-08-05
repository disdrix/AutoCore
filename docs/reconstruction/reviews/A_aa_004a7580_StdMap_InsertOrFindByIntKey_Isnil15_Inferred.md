# Review A (reconstruction fidelity): `aa_004a7580` StdMap_InsertOrFindByIntKey_Isnil15_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004a7580` |
| **VA** | `0x004a7580`–`0x004a7638` |
| **Canonical name** | `StdMap_InsertOrFindByIntKey_Isnil15_Inferred` (**Inferred**) |
| **Ghidra name** | `FUN_004a7580` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — W23-F) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004a7580_StdMap_InsertOrFindByIntKey_Isnil15_Inferred.md` |
| **System** | container / MSVC map insert-or-find |
| **Dual status** | **Present** |
| **Verdict** | **accept** |

---

## 1. Purpose

MSVC-style **ordered map insert-or-find by int key**: lower-bound walk, predecessor when the search last stepped left (non-leftmost), RB insert via `FUN_004a6d80`, or return existing equal-key iterator. Writes **`{iterator, inserted}`**. Equal key does **not** rewrite mapped value.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ W23-F append) | `raw/aa_004a7580_FUN_004a7580.md` |
| Annotated | `raw/aa_004a7580_FUN_004a7580.annotated.md` |
| Clean | `reconstructed-exact/StdMap_InsertOrFindByIntKey_Isnil15_Inferred.cpp` |
| Alias clean | `reconstructed-exact/FUN_004a7580.cpp` |
| Function record | `functions/aa_004a7580_FUN_004a7580.md` |
| Twin dual | `aa_00569320` StdMap_InsertOrFindByIntKey_Inferred (isnil `+0x49`) |

**This pass (live, OWN VA):**

- Ghidra `decompile_function` @ `0x004a7580` — CF ≡ raw
- Ghidra `read_memory` entry + exit — three **`ret 8`** paths; `CC` pad
- Ghidra `analyze_function_complete` / `get_function_by_address` bounds `004a7580`–`004a7638`
- Context decompile `FUN_004a6d80` — **`"map/set<T> too long"`**
- Context decompile `FUN_005a2850` — predecessor isnil `+0x15`
- **Not performed:** Launcher, `disassemble_bytes`, runtime golden, bit-exact image diff

---

## 3. Calling convention (assembly-sealed)

| Slot | Role | Evidence |
|---|---|---|
| **ECX** | map shell `this` | `mov edi,ecx`; head `[edi+4]` |
| **`[esp+4]`** | out pair* | writes iterator + inserted byte |
| **`[esp+8]`** | `int *pKey` | compare vs `node[3]` |
| **Return** | void (pair via out) | `ret 8` |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body span + `ret 8` thiscall | **High** | bytes |
| Insert-or-find CF | **High** | plate + callees |
| Key at `node+0x0C`, isnil `+0x15` | **High** | decompile + pred helper |
| map/set family | **High** | throw string in insert |
| 3 FX-path callers | **High** | xrefs |
| Value payload size / domain | **Open** | not in this body (isnil15 implies small T) |
| Product English symbol | **Inferred** | |
| Bit-for-bit / runtime / differential | **Open** | deferred |

---

## 5. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Root walk left/right on `*key < node.key` | Yes |
| Leftmost insert vs predecessor | Yes |
| Insert when `node.key < *key` | Yes |
| Equal → inserted=0 | Yes |

### Recovered contract

```c
void StdMap_InsertOrFindByIntKey_Isnil15(Map* map, Pair* out, int* pKey);
// out->it = node*; out->inserted = 0|1
```

---

## 6. Callers

| Caller | Site | Role |
|---|---|---|
| `FUN_004a0b90` | `0x004a0c94` | NDSpecialFX instantiate map insert |
| `FUN_004a6390` | `0x004a65a4` | FxMaster LoadMasterFromXML |
| `FUN_004a4fa0` | `0x004a6081` | FX / Drive_driver path |

---

## 7. Gaps

1. Product English / RTTI for this map specialization.
2. Exact mapped-value typedef (size implied by isnil `+0x15`).
3. Runtime golden / bit-exact.

**Verdict:** **accept** — CF/ABI/insert-or-find fully sealed; residual is product naming only.
