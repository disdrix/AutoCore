# Review A (reconstruction fidelity): `aa_004bc7a0` CNDHash_AllocBucketTable_009cb348

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bc7a0` |
| **VA** | `0x004bc7a0`–`0x004bc830` |
| **Canonical name** | `CNDHash_AllocBucketTable_009cb348` (Ghidra `FUN_004bc7a0`; **Inferred**) |
| **Prior alias** | `Named_VOG_DEBUG_STOP_004bc7a0` (**reject** product id) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction fidelity (OWN-ONLY dual W29-K Path A) |
| **Counterpart** | `reviews/B_aa_004bc7a0_CNDHash_AllocBucketTable_009cb348.md` |
| **System** | container / CNDHash (COList tableC; sentinel stamp `009cb348`) |
| **Live tools** | `decompile_function`, `read_memory`, `get_function_by_address`, xrefs/callees |
| **Verdict** | **accept-with-gaps** |
| **Dual status** | **Present (first full dual)** — closes ctor residual “AllocBucketTable FUN_004bc7a0” |

**Tools note:** No `disassemble_bytes`. No Launcher. No parent ledgers.

---

## 1. Purpose

Allocate a fresh bucket table for COList tableC CNDHash (ESI/ECX = hash*):

```text
// Requires: 1 <= *(char*)(hash+0x1c) <= 16   // log2
// Pre: *(hash+8) = N = 1<<log2  (count)

table = operator_new[](N * 4)
*(hash+0x10) = table
slab = malloc(N * 0xC)
for i in 0..N-1:
  table[i] = slab + i*0xC
  *bucket = &PTR_LAB_009cb348
  bucket[1] = 0   // head
  bucket[2] = 0
*(hash+8) = N - 1   // COUNT → MASK
```

If log2 out of range: log `"VOG_DEBUG_STOP"` then throw **`0x80004003`** (`E_POINTER`).

**Callers:** `CNDHash_Ctor_009cb450` (`004bce90` @ `004bceea`), Recreate `FUN_004bcce0` @ `004bcd2c`.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | ≡ raw 2026-07-23 |
| Live bytes | success path + throw path |
| Sentinel stamp | `C7 00 48 B3 9C 00` → `0x009cb348` |
| malloc IAT | `FF 15 28 65 9C 00` → `0x009c6528` |
| Ctor parent | sealed W28-J `CNDHash_Ctor_009cb450` — unconditional call here after N=1<<log2 |
| Recreate parent | `FUN_004bcce0` with string `HashError:Recreate, already locked for traversal` |
| Twin | `CNDHash_AllocBucketTable_009cb350` `0x004bc840` (same dual) |
| Parallel | `CNDHash_AllocBucketTable_009ce090` `0x0051ba40`; `AllocBucketTable_Inferred` `0x00413d80` |
| Raw / clean | `raw/aa_004bc7a0_*`, `reconstructed-exact/CNDHash_AllocBucketTable_009cb348.cpp`, `FUN_004bc7a0.cpp` |

---

## 3. Authoritative body (sealed CF)

```c
void __thiscall CNDHash_AllocBucketTable_009cb348(CNDHash *this)
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
    *s = (uint32_t)&PTR_LAB_009cb348;
    s[1] = 0;
    s[2] = 0;
  }
  *(int *)(this + 8) = N - 1;
}
```

---

## 4. Machine seal (`read_memory` @ `0x004bc7a0`)

| Claim | Evidence | Conf |
|---|---|---|
| thiscall ECX→ESI | `56 8B F1` | **High** |
| log2 `CMP 1 / JL; CMP 10h / JG` | bytes at entry | **High** |
| `N*4` via double ADD | `03 C0 03 C0` | **High** |
| `N*0xC` via lea*3 + double ADD | `8D 0C 40 03 C9 03 C9` | **High** |
| Stamp `009cb348` | `C7 00 48 B3 9C 00` | **High** |
| mask `ADD [ESI+8],-1` | `83 46 08 FF` | **High** |
| bare success `ret` | `5F 5E 59 C3` | **High** |
| throw `0x80004003` | `C7 44 24 0C 03 40 00 80` | **High** |
| Live ≡ raw | surface match | **High** |
| Body range | Ghidra `004bc7a0`–`004bc830` (145 B) | **High** |

---

## 5. Naming

| Candidate | Decision |
|---|---|
| `CNDHash_AllocBucketTable_009cb348` | **Accept** — role + sentinel stamp; twin of `009cb350` Alloc |
| `CNDHash_AllocBuckets_009cb348` | Acceptable shorter alias |
| `FUN_004bc7a0` | scaffold |
| Named_VOG_DEBUG_STOP | **Reject** product identity |

---

## 6. Confidence

| Claim | Level |
|---|---|
| CF dual A ≡ raw ≡ live | **Confirmed** |
| Dual alloc ptr-array + 0xC slab | **Confirmed** |
| Post-condition mask = N−1 | **Confirmed** |
| log2 gate 1..16 | **Confirmed** |
| Callers ctor + Recreate | **Confirmed** (2 xrefs) |
| Role AllocBucketTable | **High** |
| Product/PDB English | **Open** |
| Full `009cb348` vtbl methods | **Open** (not needed for alloc CF) |
| Runtime / bit-exact / diff | **Open** |

**Verdict:** **accept-with-gaps.**
