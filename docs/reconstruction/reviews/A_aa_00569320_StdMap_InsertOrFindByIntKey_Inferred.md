# Review A (reconstruction fidelity): `aa_00569320` StdMap_InsertOrFindByIntKey_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00569320` |
| **VA** | `0x00569320` |
| **Body span** | `00569320` – `005693d8` |
| **Canonical name** | `StdMap_InsertOrFindByIntKey_Inferred` (**Inferred**) |
| **Ghidra name** | `FUN_00569320` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — W19-J) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00569320_StdMap_InsertOrFindByIntKey_Inferred.md` |
| **System** | container / MSVC map insert-or-find |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

MSVC-style **ordered map/set insert-or-find by int key**: lower-bound walk, predecessor when the search last stepped left (non-leftmost), RB insert via `FUN_005690a0`, or return existing equal-key iterator. Writes **`{iterator, inserted}`**.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (authoritative + W19-J re-verify) | `raw/aa_00569320_FUN_00569320.md` |
| Annotated | `raw/aa_00569320_FUN_00569320.annotated.md` |
| Clean | `reconstructed-exact/StdMap_InsertOrFindByIntKey_Inferred.cpp` |
| Alias clean | `reconstructed-exact/FUN_00569320.cpp` |
| Function record | `functions/aa_00569320_FUN_00569320.md` |

**This pass (live, OWN VA):**

- Ghidra `decompile_function` @ `0x00569320` — CF ≡ raw
- Ghidra `read_memory` entry + exit — multiple **`ret 8`** paths; `cc` pad at end
- Ghidra `get_function_by_address` bounds `00569320`–`005693d8`
- Ghidra `get_function_xrefs` / callers — sole `FUN_00569560` @ `005696ad`
- Context decompile `FUN_005690a0` — **`"map/set<T> too long"`** throw
- Sibling dual `aa_00537770` Map_Predecessor (isnil `+0x49`)
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
| Insert-or-find CF | **High** | plate + callee |
| Key at `node+0x0C`, isnil `+0x49` | **High** | matches predecessor dual |
| map/set family | **High** | throw string in insert |
| Sole caller hinted-insert wrapper | **High** | 1 xref |
| Value payload size / domain | **Open** | not in this body |
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
// pair-out form
void StdMap_InsertOrFindByIntKey(Map* map, Pair* out, int* pKey);
// out->it = node*; out->inserted = 0|1
```

---

## 6. Callers

| Caller | Site | Role |
|---|---|---|
| `FUN_00569560` | `0x005696ad` | insert-with-hint fallback |

**1 xref only.**

---

## 7. Gaps

1. Owning map value type / node total size.
2. Full call-chain domain (who owns `FUN_00569560` maps).
3. Runtime / bit-exact / differential — open.

**Verdict:** **accept-with-gaps**
