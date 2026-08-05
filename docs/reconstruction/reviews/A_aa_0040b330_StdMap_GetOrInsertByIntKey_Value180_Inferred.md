# Review A (reconstruction fidelity): `aa_0040b330` StdMap_GetOrInsertByIntKey_Value180_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040b330` |
| **VA** | `0x0040b330` |
| **Body** | `0x0040b330`–`0x0040b3ab` |
| **Canonical name** | `StdMap_GetOrInsertByIntKey_Value180_Inferred` |
| **Ghidra name** | `FUN_0040b330` |
| **Prior alias** | `Named_CalleeOf_Named_CalleeOf_CVOGCombat_OnDeathAwardKillXp_0040b330` (chain-only) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_0040b330_StdMap_GetOrInsertByIntKey_Value180_Inferred.md` |
| **System** | container / object def map (global `DAT_00b047a0`) |
| **Live tools** | Ghidra `batch_decompile`, `read_memory`, callees, callers (wrapper `005001f0`, `Vehicle_CalcMaxHitPoints`, …) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

MSVC-style **map get-or-insert by int key**, returning a pointer to the **value blob at `node+0x10`**. On miss, zero-fills a **0x180-byte** (0x60 dword) value and inserts.

```c
// __thiscall map*; one stack formal (int* pKey); ret 4
void * __thiscall StdMap_GetOrInsertByIntKey_Value180_Inferred(Map *this, int *pKey);
// returns node + 0x10
```

1. `it = FUN_0040bbe0(pKey)` — lower_bound-style walk; nil flag at **`node+0x191`** (large node); key at **`node+0xC`** (`[3]`).
2. If `it != end_header` **and** `it->key <= *pKey` (with proper lower_bound ⇒ **equal**) → **return `it + 0x10`**.
3. Else:
   - Zero `local_188[0x60]` dwords.
   - Copy zero block into insert payload staging `local_308[0x60]`.
   - `FUN_0040b720(outIt, hint, &key)` insert path.
   - **return `*outIt + 0x10`**.

### Map host (sealed at wrapper)

`Object_LookupMapNodeByField14c` `0x005001f0` bytes:

```
mov eax, [ecx+0x14c]     ; key from object
lea ecx, [esp]
push ecx
mov ecx, 0x00b047a0      ; *** GLOBAL MAP DAT_00b047a0 ***
mov [esp+4], eax
call FUN_0040b330
```

So this map is a **process-global** int-key table at **`DAT_00b047a0`**, not the caller's object.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Function record / raw / clean | `aa_0040b330_*` |
| Live decompile | ≡ raw CF |
| Body | `read_memory 0x0040b330` length 128; **`ret 4`**, stack align, `0x30c` frame |
| Lower-bound | `FUN_0040bbe0` — walk, key `[3]`, nil `+0x191` |
| Insert | `FUN_0040b720` → ultimately `FUN_0040ba20` node link |
| Wrapper | `FUN_005001f0` — key `object+0x14c`, map **`0x00b047a0`** |
| Callers | `Vehicle_CalcMaxHitPoints`, `Vehicle_applyCreatePacket`, OnDeath path wrappers, `00503780`, `00565640`, `00565950`, `0092b2a0`, … |

### OnDeath / HP use

- Wrapper returns value ptr; OnDeath reads **`*(float*)(value + 0x178)`** loot/credit scalar.
- NPC HP path in `Vehicle_CalcMaxHitPoints` uses **`*(int*)(value + 0x17c)`** as base pool term.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Get-or-insert int key | **Confirmed** | |
| Return `node+0x10` | **Confirmed** | both paths |
| Miss zero-fills **0x180** bytes | **Confirmed** | `0x60` dwords × 4 |
| Nil flag `+0x191` (large node) | **Confirmed** | lower_bound helper |
| Key at `node+0xC` | **Confirmed** | |
| ABI thiscall + `ret 4` | **Confirmed** | bytes |
| Global map `DAT_00b047a0` | **Confirmed** | wrapper imm ECX |
| Clean ≡ raw ≡ live | **Confirmed** | |
| Key English (`+0x14c` clonebase?) | **Tentative** | caller-side |
| Full 0x180 value field map | **Open** | only +0x178/+0x17c used in sample callers |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| lower_bound `0040bbe0` | **Yes** |
| Equal → return value | **Yes** |
| Miss → zero 0x180 → insert `0040b720` → return value | **Yes** |
| No domain math in body | **Yes** |

### Recovered CF

```c
void *Map_GetOrInsert(Map *m, int *pKey) {
  Node *it = lower_bound(m, pKey);           // FUN_0040bbe0
  if (it != header(m) && it->key <= *pKey)   // equal under LB
    return (char *)it + 0x10;
  uint32_t zeros[0x60] = {0};
  // stage copy + insert via FUN_0040b720
  Node *n = insert(m, it, pKey, zeros);
  return (char *)n + 0x10;
}
```

---

## 5. Node layout (this map family)

| Offset | Role |
|---|---|
| `+0` / `+4` / `+8` | left / parent / right (typical) |
| `+0xC` | int key |
| `+0x10` … `+0x18F` | value blob (0x180 bytes) |
| `+0x191` | nil / header flag |

Value samples:

| Value off | Use |
|---|---|
| `+0x178` | float scalar (OnDeath loot/credit) |
| `+0x17c` | int base for NPC vehicle HP |

---

## 6. Gaps

1. Full product schema of the 0x180 blob.
2. Authoritative name for key `object+0x14c` (clonebase / cbid?).
3. Whether insert path can fail / throw (not observed here).
4. Runtime deferred.

**Verdict:** **accept-with-gaps** — get-or-insert CF, global map host, return value ptr sealed; value field atlas residual.
