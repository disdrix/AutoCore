# Review A (reconstruction fidelity): `aa_0051ba40` CNDHash_AllocBucketTable_009ce090

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051ba40` |
| **VA** | `0x0051ba40`–`0x0051bad0` |
| **Canonical name** | `CNDHash_AllocBucketTable_009ce090` (Ghidra `FUN_0051ba40`; **Inferred**) |
| **Prior alias** | `Named_VOG_DEBUG_STOP_0051ba40` (**reject** product id) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction fidelity (OWN-ONLY dual W25-F Path A) |
| **Counterpart** | `reviews/B_aa_0051ba40_CNDHash_AllocBucketTable_009ce090.md` |
| **System** | container / CNDHash (medal family; sentinel stamp `009ce090`) |
| **Live tools** | `decompile_function`, `read_memory`, `get_function_by_address`, xrefs/callees |
| **Verdict** | **accept-with-gaps** |
| **Dual status** | **Present (first full dual)** — closes Recreate/FreeBuckets residual “alloc twin FUN_0051ba40” |

**Tools note:** No `disassemble_bytes`. No Launcher. No parent ledgers.

---

## 1. Purpose

Allocate a fresh bucket table for medal-family CNDHash (ESI/ECX = hash*):

```text
// Requires: 1 <= *(char*)(hash+0x1c) <= 16   // log2
// Pre: *(hash+8) = N = 1<<log2  (count)

table = operator_new[](N * 4)
*(hash+0x10) = table
slab = malloc(N * 0xC)
for i in 0..N-1:
  table[i] = slab + i*0xC
  *bucket = &PTR_LAB_009ce090
  bucket[1] = 0   // head
  bucket[2] = 0
*(hash+8) = N - 1   // COUNT → MASK
```

If log2 out of range: log `"VOG_DEBUG_STOP"` then throw **`0x80004003`** (`E_POINTER`).

**Callers:** `CNDHash_Recreate` (`0051d230` @ `0051d27c`), ctor `FUN_0051db60` @ `0051dbba`.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | ≡ raw 2026-07-23 |
| Live bytes | success path + throw path |
| Sentinel stamp | `C7 00 90 E0 9C 00` → `0x009ce090` |
| malloc IAT | `FF 15 28 65 9C 00` → `0x009c6528` |
| Free twin | sealed `CNDHash_FreeBuckets` — `free(*buckets)` matches slab base |
| Reclaim twin | `CNDHash_ReclaimAll_ValueOwning_009ce0a8` (same dual) |
| Parallel | `CNDHash_AllocBucketTable_Inferred` `0x00413d80` (other stamp) |
| Raw / clean | `raw/aa_0051ba40_*`, `reconstructed-exact/CNDHash_AllocBucketTable_009ce090.cpp`, `FUN_0051ba40.cpp` |

---

## 3. Authoritative body (sealed CF)

```c
void __thiscall CNDHash_AllocBucketTable_009ce090(CNDHash *this)
{
  char log2 = *(char *)(this + 0x1c);
  if (!(log2 >= 1 && log2 <= 16)) {
    FUN_007a4480(0, "VOG_DEBUG_STOP");
    // throw 0x80004003 / ThrowInfo 0xacc430
    _CxxThrowException(...);
  }
  int N = *(int *)(this + 8);
  void **table = operator_new[](N * 4);
  *(void ***)(this + 0x10) = table;
  void *slab = malloc(N * 0xC);
  for (uint i = 0; i < (uint)N; ++i) {
    table[i] = (char *)slab + i * 0xC;
    uint32_t *s = (uint32_t *)table[i];
    *s = (uint32_t)&PTR_LAB_009ce090;
    s[1] = 0;
    s[2] = 0;
  }
  *(int *)(this + 8) = N - 1;
}
```

---

## 4. Machine seal (`read_memory` @ `0x0051ba40`)

| Claim | Evidence | Conf |
|---|---|---|
| thiscall ECX→ESI | `56 8B F1` | **High** |
| log2 `CMP 1 / JL; CMP 10h / JG` | bytes at entry | **High** |
| `N*4` via double ADD | `03 C0 03 C0` | **High** |
| `N*0xC` via lea*3 + double ADD | `8D 0C 40 03 C9 03 C9` | **High** |
| Stamp `009ce090` | `C7 00 90 E0 9C 00` | **High** |
| mask `ADD [ESI+8],-1` | `83 46 08 FF` | **High** |
| bare success `ret` | `5F 5E 59 C3` | **High** |
| throw `0x80004003` | `C7 44 24 0C 03 40 00 80` | **High** |
| Live ≡ raw | surface match | **High** |

---

## 5. Naming

| Candidate | Decision |
|---|---|
| `CNDHash_AllocBucketTable_009ce090` | **Accept** — role + sentinel stamp; parallel to `AllocBucketTable_Inferred` |
| `CNDHash_AllocBuckets_009ce090` | Acceptable shorter alias |
| `FUN_0051ba40` | scaffold |
| Named_VOG_DEBUG_STOP | **Reject** product identity |

---

## 6. Confidence

| Claim | Level |
|---|---|
| CF dual A ≡ raw ≡ live | **Confirmed** |
| Dual alloc ptr-array + 0xC slab | **Confirmed** |
| Post-condition mask = N−1 | **Confirmed** |
| log2 gate 1..16 | **Confirmed** |
| Callers Recreate + ctor | **Confirmed** (2 xrefs) |
| Role AllocBucketTable | **High** |
| Product/PDB symbol | **Open** |
| Full `009ce090` vtbl methods | **Open** (not needed for alloc CF) |
| Runtime / bit-exact / diff | **Open** |

**Verdict:** **accept-with-gaps.**
