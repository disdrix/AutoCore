# Review B (skeptical / adversarial): `aa_00413920` CNDHash_Insert_u64

| Field | Value |
|---|---|
| **Stable ID** | `aa_00413920` |
| **VA** | `0x00413920` |
| **Canonical name** | `CNDHash_Insert_u64` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_00413920_CNDHash_Insert_u64.md` |
| **Live tools** | Independent `force_decompile` + callee bodies + caller |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Same node layout as mission `CNDHash_Insert` `0x0053c360` | **Falsified** — 0x28 + u64 key vs 0x1c + u32 |
| 2 | Soft flag means "allow true duplicates" | **Falsified** — soft hit returns 1 **without** inserting |
| 3 | Lock error aborts insert | **Falsified** — log only |
| 4 | `__thiscall` ECX=hash | **Falsified** — first stack arg; `ret 0x14` (5 dwords) |
| 5 | `FUN_00419bd0` is FailMissionNotify | **Falsified** — freelist slab alloc; Ghidra name collision |
| 6 | Lookup compares only keyLo | **Falsified** — both keyLo@+0x18 and keyHi@+0x1c |
| 7 | Dead/empty node (value@+0xc==0) blocks reinsert | **Falsified** — live payload required for hit |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Insert CF + HRESULT map | **High** | Wrong sheet add failure path |
| Key is 64-bit | **High** | COID half-key collisions |
| Freelist at hash+0x20 | **High** | Leak / double free |
| Value ownership transferred into node | **High** | Widget lifetime |
| Product rename permanent | **Probable** | Registry noise |
| Allocator chunk constants (0x18×0x28) | **High** (body) | — |

---

## 3. Caller challenge

| Caller | Must not claim |
|---|---|
| `FUN_008605b0` AddItemWidget | That insert failure destroys only on `iVar4 < 0` path — **yes it does** destroy widget if insert fails; success wires page coords |
| softIfExists=0 at AddItem | That soft path is unused in product — only this site sealed; other callers may differ |

---

## 4. CF challenge of Review A

- Dual identity: **agree**
- E_POINTER / soft-1 / E_FAIL / success-0: **agree**
- Layout table: **agree**
- Residual: freelist EDI plumbing not in decompiler surface — **document**, not CF error

---

## 5. Surviving contract

```
hr = CNDHash_Insert_u64(hash, keyLo, keyHi, value, soft):
  if !value: return E_POINTER
  if locked: log; // continue
  if soft && live_hit: return 1
  if live_hit: log Duplicate; return E_FAIL
  node = freelist_pop(hash+0x20)  // 0x28 nodes, vtbl 00a64758
  node.value = value; node.key = {keyLo,keyHi}
  bucket_head_insert(keyLo & mask); list_append; count++
  return 0
```

**Verdict:** **accept-with-gaps.** Accept A.
