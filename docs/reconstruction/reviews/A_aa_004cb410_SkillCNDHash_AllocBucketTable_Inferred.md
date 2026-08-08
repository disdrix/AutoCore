# Review A (reconstruction fidelity): `aa_004cb410` SkillCNDHash_AllocBucketTable_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cb410` |
| **VA** | `0x004cb410` |
| **Canonical name** | `SkillCNDHash_AllocBucketTable_Inferred` |
| **Prior alias** | `FUN_004cb410` |
| **Review date** | `2026-08-04` (OWN-ONLY dual A/B — WQ9E-A) |
| **Reviewer role** | Independent reconstruction review (Path A fidelity) |
| **Counterpart** | `reviews/B_aa_004cb410_SkillCNDHash_AllocBucketTable_Inferred.md` |
| **System** | skills-abilities / skill-family CNDHash |
| **Live tools** | Ghidra `decompile_function`, `analyze_function_complete`, `read_memory`, callers/xrefs, assembly_context |
| **Partition** | `WAVE_2026-08-04_wq009_depth2_partition_map.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Allocate skill-family **CNDHash** bucket pointer table + contiguous **0xc** sentinel slab; convert provisional count at `+0x08` into **mask**:

```text
// __thiscall; bare ret on success; noreturn throw on bad log2
log2 = *(char*)(hash+0x1c)
require 1 ≤ log2 ≤ 16
N = *(hash+8)                     // provisional COUNT (caller: 1<<log2)
table = new void*[N]              // store @+0x10
slab  = malloc(N * 0xc)
for i in 0..N-1:
  table[i] = slab + i*0xc
  *table[i] = PTR_LAB_009cb970    // sentinel stamp
  table[i][1] = table[i][2] = 0
*(hash+8) = N - 1                 // COUNT → MASK
```

**Not** inventory/medal alloc twins (different VA + sentinel stamps). **Not** insert/ensure-loaded.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | `batch_decompile(0x004cb410)` ≡ 2026-07-23 raw |
| Entry / body bytes | `read_memory` — `51 56 8B F1` … success `5F 5E 59 C3`; fail throw `0x80004003` |
| Body range | `0x004cb410`–`0x004cb4a0` (**145 B**); Ghidra end `004cb4a0` |
| Sentinel | imm `0x009cb970` written per bucket head |
| Callers | recreate `004cbdc0` @ `004cbe0c`; ctor `0051dd60` @ `0051ddba` |
| Parent duals | `SkillCNDHash_Recreate_Inferred`, `SkillCNDHash_Ctor_Inferred` |
| Parallel clean | `CNDHash_AllocBucketTable_009ce090.cpp` (medal stamp family) |
| Clean | `reconstructed-exact/SkillCNDHash_AllocBucketTable_Inferred.cpp` |

---

## 3. ABI (SEALED)

| Slot | Role | Evidence |
|------|------|----------|
| **ECX** | hash* | entry `mov esi,ecx`; callers `mov ecx,esi` |
| stack | none | bare `ret` |
| success return | void | no EAX produce |
| fail | noreturn throw | `_CxxThrowException` after log |

---

## 4. Control flow: clean ≡ live

| Stage | Match |
|---|---|
| Log2 gate 1..16 | **Yes** (`cmp 1 / jl`; `cmp 0x10 / jg`) |
| `new[]` table N*4 @ `+0x10` | **Yes** |
| `malloc` slab N*0xc | **Yes** |
| Init sentinels `009cb970` + zeros | **Yes** |
| `*(+8)--` mask post-condition | **Yes** |
| Fail: `VOG_DEBUG_STOP` + throw `0x80004003` | **Yes** |

### Post-condition on `hash+8`

After success: `*(hash+8) = (1 << log2) - 1` when caller seeded count as `1<<log2` — **High** (parent recreate dual depends on this).

---

## 5. Confidence

| Claim | Confidence |
|---|---|
| Role = alloc bucket table / mask convert | **High** (CF + sole skill recreate/ctor callers) |
| thiscall / bare ret | **High** |
| Sentinel stamp `009cb970` | **High** (imm in bytes) |
| log2 domain 1..16 hard throw | **High** |
| Distinct from inventory alloc VAs | **High** |
| Product English / RTTI for stamp | **Open** (`_Inferred`) |
| malloc/new null handling | **Open** (no checks — preserve) |
| Runtime / bit-exact | **Open** |

**Verdict:** **accept-with-gaps**
