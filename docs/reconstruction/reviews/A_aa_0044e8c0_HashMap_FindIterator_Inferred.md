# Review A (reconstruction fidelity): `aa_0044e8c0` HashMap_FindIterator_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0044e8c0` |
| **VA** | `0x0044e8c0`–`0x0044e945` |
| **Canonical name** | `HashMap_FindIterator_Inferred` |
| **Prior scaffold** | `FUN_0044e8c0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_0044e8c0_HashMap_FindIterator_Inferred.md` |
| **System** | hash map / ND resource cache container |
| **Agent** | W21-N OWN-ONLY |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Hash-map find by key → write iterator**:

1. Hash key via `FUN_0043b870` (string content of `*(char**)key`).
2. Bucket index = `hash & mask(+0x20)`; fold if `index >= bucket_count(+0x24)`.
3. Walk chain from `table[+0x14][idx]` to adjacent end slot; keys at **`node+8`**.
4. On equal key dword: `*out = node`. On miss / ordered greater: `*out = map[+0x08]` end.
5. Return `out` pointer; **`ret 4`**.

Used by **`NDResourceCache_LookupOrCreate`** and ~19 other name/resource table sites.

**Not** insert, erase, or rehash — find only.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0044e8c0_FUN_0044e8c0.md` (+ v2026-07-29) |
| Annotated | `docs/reconstruction/raw/aa_0044e8c0_FUN_0044e8c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/HashMap_FindIterator_Inferred.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_0044e8c0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0044e8c0_FUN_0044e8c0.md` |
| Live decompile | Ghidra `0x0044e8c0` (2026-07-29) — ≡ 2026-07-23 raw |
| Machine | `read_memory` 140 B full body; 3× `C2 04 00` |
| Hash leaf | `decompile_function` `0x0043b870` (context) |
| Caller dual | `A_aa_0075dba0_NDResourceCache_LookupOrCreate` |

**Not performed:** `disassemble_bytes`, Launcher, runtime, parent ledgers.

---

## 3. Signature / layout

```c
// EDI=map*, EBX=key*, stack out_it*, ret 4
void **HashMap_FindIterator_Inferred(void **out_it);
```

| Object | Offset | Role |
|---|---|---|
| map | `+0x08` | end sentinel |
| map | `+0x14` | bucket table |
| map | `+0x20` | mask |
| map | `+0x24` | bucket count |
| node | `+0` | next |
| node | `+8` | key dword |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Find-iterator role | **Confirmed** | CF + cache caller |
| ABI EDI/EBX + `ret 4` | **Confirmed** | bytes; decompiler unaff_* |
| Offsets map/node | **Confirmed** | body |
| Ordered chain early-exit | **Confirmed** | `jae` pair on key cmp |
| Hash = string ELF-style | **High** | leaf decompile |
| Clean CF ≡ bytes | **Confirmed** | |
| Product type name | **Open** | `_Inferred` |
| Key domain (string ptr vs id) | **Open** | dword eq sealed |
| Runtime / bit-exact | **Open** | |

---

## 5. Control flow: clean ≡ decompile ≡ bytes

| Stage | Match |
|---|---|
| Load mask `EDI+0x20` | **Yes** |
| `FUN_0043b870` with EAX=EBX | **Yes** |
| `hash & mask`; fold vs `+0x24` | **Yes** |
| Bucket `table+idx*4` start/end | **Yes** |
| Walk next `@+0`; cmp key `@+8` | **Yes** |
| Hit → `*out=node` | **Yes** |
| Miss → `*out=map+8` | **Yes** (empty / exhaust / greater) |
| `ret 4` all paths | **Yes** |

### Decompiler noise — sealed as artifact

| Noise | Reality |
|---|---|
| `unaff_EDI` / `unaff_EBX` | **Live register formals** (map / key) |
| Signature shows only `param_1` | Missing EDI/EBX in Ghidra prototype |
| Clean `asm("edi")` annotations | Documentation of machine ABI; not claiming compiler output |

---

## 6. Gaps

- Product container / method name.
- Whether all callers intern string keys (equality is dword, not strcmp).
- Runtime golden / differential.
