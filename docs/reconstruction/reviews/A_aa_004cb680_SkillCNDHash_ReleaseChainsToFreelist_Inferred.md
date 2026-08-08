# Review A (reconstruction fidelity): `aa_004cb680` SkillCNDHash_ReleaseChainsToFreelist_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cb680` |
| **VA** | `0x004cb680` |
| **Canonical name** | `SkillCNDHash_ReleaseChainsToFreelist_Inferred` |
| **Prior alias** | `FUN_004cb680`; scaffold `Named_CalleeOf_…_VOG_DEBUG_STOP_004cb680` |
| **Review date** | `2026-08-04` (OWN-ONLY dual A/B — WQ9F-A) |
| **Reviewer role** | Independent reconstruction review (Path A fidelity) |
| **Counterpart** | `reviews/B_aa_004cb680_SkillCNDHash_ReleaseChainsToFreelist_Inferred.md` |
| **System** | skills-abilities / skill-family CNDHash |
| **Live tools** | Ghidra `batch_decompile`, `analyze_function_complete`, `read_memory`, callers/xrefs |
| **Partition** | `WAVE_2026-08-04_wq009_depth3_partition_map.md` → WQ9F-A |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Release every **bucket chain node** of a skill-family CNDHash onto the hash **freelist** (`+0x20`), deleting owned payloads, before the parent destroy frees the bucket table:

```text
// __thiscall; ECX=hash; bare ret
for i = 0 .. mask(@+0x08) inclusive:
  node = table[i]->chain_head (+4)
  while node:
    next = node[+0xc]
    *node = PTR_FUN_009cb968          // temp stamp
    if payload = node[+0x08]: operator_delete(payload)
    node[+0x08] = 0
    *node = freelist; freelist = node // push @ hash+0x20
    node = next
  table[i]->chain_head = 0
```

**Not** table free (parent `004cba60`). **Not** full hash dtor. **Not** live-count zero (parent zeros `+0x0c` first).

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | `batch_decompile(0x004cb680)` ≡ 2026-07-23 raw CF |
| Entry / body bytes | `read_memory` — `53 55 56 8B D9` … `5F 5E 5D 5B C3` + `CC` |
| Body range | `0x004cb680`–`0x004cb6e1` (**98 B** / `0x62`); Ghidra end `004cb6e1` |
| Callers | sole: `SkillCNDHash_DestroyBucketTable_Inferred` (`0x004cba60`) @ `0x004cba6a` |
| Callees | `operator_delete` only |
| Parent dual | WQ9E-A destroy (`aa_004cba60`) — freelist residual closed here |
| Clean | `reconstructed-exact/SkillCNDHash_ReleaseChainsToFreelist_Inferred.cpp` |

---

## 3. ABI (SEALED)

| Slot | Role | Evidence |
|------|------|----------|
| **ECX** | hash* | entry `mov ebx,ecx`; destroy caller thiscall chain |
| stack | none | bare `ret` (`C3`) |
| return | void | no EAX produce |

---

## 4. Control flow: clean ≡ live

| Stage | Match |
|---|---|
| Bucket loop `0..mask` inclusive (`jbe [hash+8]`) | **Yes** |
| Chain from `bucket[+4]` | **Yes** |
| Next via `node[+0xc]` | **Yes** |
| Temp stamp `009cb968` then freelist overwrite of `*node` | **Yes** |
| Conditional `operator_delete(payload@+8)` + zero | **Yes** |
| Freelist push `@+0x20` | **Yes** |
| Clear bucket head | **Yes** |
| Decomp false-noreturn on delete | **Yes** (bytes continue) |

---

## 5. Confidence

| Claim | Confidence |
|---|---|
| Role = release chains → freelist under destroy | **High** (sole caller destroy + freelist shape) |
| thiscall ECX / bare ret | **High** (entry+exit bytes) |
| mask-inclusive bucket walk | **High** (`uVar4 <= *(hash+8)`) |
| payload delete @ +8 / link @ +0xc | **High** (decomp ≡ algorithm) |
| Product English class / node type | **Open** (`_Inferred`) |
| Freelist pop / slab reuse dual | **Open** (not OWN) |
| Runtime / bit-exact | **Open** |

**Verdict:** **accept-with-gaps**
