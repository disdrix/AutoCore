# Review A (reconstruction fidelity): `aa_00722b80` CSoundManager_HasActiveMatchingTfidType_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00722b80` |
| **VA** | `0x00722b80` |
| **Canonical name** | `CSoundManager_HasActiveMatchingTfidType_Inferred` |
| **Ghidra symbol** | `FUN_00722b80` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual A/B) |
| **Counterpart** | `reviews/B_aa_00722b80_CSoundManager_HasActiveMatchingTfidType_Inferred.md` |
| **System** | client audio / `CSoundManager` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Busy / conflict probe** over the manager’s **active play table**: returns **1** if any live entry matches **(tfidLo, tfidHi, type)** with an activity flag set; else **0**.

Authoritative CF (live ≡ raw):

1. **`EAX = CSoundManager* this`** (decompiler `in_EAX`).
2. If **`(param_1 & param_2) == 0xFFFFFFFF`** → return **0** (invalid TFID sentinel; both halves all-ones under AND).
3. `count = *(this + 0x210)`; walk `i = 0 .. count-1`.
4. Entry pointer array base **`this + 0x31C`** (dword slots).
5. For each non-null `entry`:
   - `entry+0x2C == param_3` (type)
   - `entry+0x40 == param_1` (tfid lo)
   - `entry+0x44 == param_2` (tfid hi)
   - **and** (`*(char*)(entry+0x1C5) != 0` **OR** `*(char*)(entry+0x3A) != 0`) — active flags
   - → return **1**
6. Exhaust → return **0** (`EAX & 0xFFFFFF00` / clear low byte).

**Callers:**

- `FUN_007258a0` — only when descriptor type is **0xC or 0xD**; non-zero → suppress queue.
- `Client_PlayNamedInterfaceSound` — types **0xC / 0xD / 0x28** gate (busy → skip special path).

---

## 2. Inspected artifacts

| Artifact | Path / source | This pass |
|---|---|---|
| Raw / annotated / clean | `aa_00722b80_*` | CF ≡ live |
| Live decompile | Ghidra `0x00722b80` | sealed |
| Complete analysis | leaf; 2 xrefs | |
| Parent duals | `A_aa_007258a0`, `Client_PlayNamedInterfaceSound` | busy gate |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Leaf (no callees) | **Confirmed** | analyze |
| `this` in EAX; stack (tfidLo, tfidHi, type) | **Confirmed** | body + parents |
| Count `@+0x210`, ptr table `@+0x31C` | **Confirmed** | body |
| Match offsets `+0x2C` type, `+0x40/+0x44` TFID | **Confirmed** | body |
| Active OR flags `+0x1C5` / `+0x3A` | **Confirmed** | body |
| Sentinel `(lo & hi) == -1` → false | **Confirmed** | early out |
| Returns bool 0/1 | **Confirmed** | CONCAT31 / mask |
| Types 0xC/0xD special in parents | **High** | parent gates |
| Full entry schema | **Open** | only matched fields sealed |
| Product name | **Probable** | inferred |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Sentinel early false | Yes |
| Counted walk of `+0x31C` | Yes |
| Type + TFID + active flags | Yes |
| Return 1 / 0 | Yes |

```c
// bool HasActiveMatching(CSoundManager *eax_this, uint lo, uint hi, int type)
uint FUN_00722b80(uint lo, uint hi, int type)
{
  if ((lo & hi) == 0xFFFFFFFFu) return 0;
  int n = *(int *)(this + 0x210);
  uint *slots = (uint *)(this + 0x31C);
  for (int i = 0; i < n; ++i) {
    uint e = slots[i];
    if (e && *(int *)(e + 0x2C) == type
        && *(uint *)(e + 0x40) == lo
        && *(uint *)(e + 0x44) == hi
        && (*(char *)(e + 0x1C5) || *(char *)(e + 0x3A)))
      return 1;
  }
  return 0;
}
```

---

## 5. Callers / callees

**Callees:** none.

**Callers:** `FUN_007258a0` (`0x007258d8`), `Client_PlayNamedInterfaceSound` (`0x00726d6b`).

---

## 6. Gaps / open

1. Meaning of types 0xC / 0xD / 0x28 (voice / 3D / UI?).
2. Who fills `+0x31C` table and what drains it.
3. Whether `+0x1C5` vs `+0x3A` are distinct lifecycle flags.
4. Runtime not run.

**Verdict:** **accept-with-gaps** — match layout and busy-bool role sealed.
