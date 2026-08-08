# Review A (reconstruction fidelity): `aa_00406f20` CNDHash_AllocBucketTable_00a2c2e4

| Field | Value |
|---|---|
| **Stable ID** | `aa_00406f20` |
| **VA** | `0x00406f20` |
| **Canonical name** | `CNDHash_AllocBucketTable_00a2c2e4` |
| **Prior alias** | `FUN_00406f20` |
| **Review date** | `2026-08-04` (OWN-ONLY dual A/B — WQ9G-J) |
| **Reviewer role** | Independent reconstruction review (Path A fidelity) |
| **Counterpart** | `reviews/B_aa_00406f20_CNDHash_AllocBucketTable_00a2c2e4.md` |
| **System** | container / CNDHash (host vtbl `00a2c2b0`) |
| **Live tools** | Ghidra `batch_decompile`, `analyze_function_complete`, `read_memory`, callers/xrefs, `get_assembly_context` |
| **Partition** | `WAVE_2026-08-04_wq009_depth4_partition_map.md` → **WQ9G-J** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Allocate host-family **CNDHash** bucket pointer table + contiguous **0xc** sentinel slab; convert provisional count at `+0x08` into **mask**:

```text
// custom ESI = hash*; bare ret on success; noreturn throw on bad log2
log2 = *(char*)(hash+0x1c)
require 1 ≤ log2 ≤ 16
N = *(hash+8)                     // provisional COUNT (caller: 1<<log2)
table = new void*[N]              // store @+0x10
slab  = malloc(N * 0xc)
for i in 0..N-1:
  table[i] = slab + i*0xc
  *table[i] = PTR_LAB_00a2c2e4    // sentinel stamp
  table[i][1] = table[i][2] = 0
*(hash+8) = N - 1                 // COUNT → MASK
```

**Not** skill/medal alloc twins (different VA + stamp + ABI). **Not** tree insert (address-neighborhood only).

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | `batch_decompile(0x00406f20)` ≡ 2026-07-23 raw |
| Entry / body bytes | `read_memory` — `51 8A 46 1C` … success `5F 59 C3`; stamp imm `e4 c2 a2 00`; fail throw `0x80004003` |
| Body range | `0x00406f20`–`0x00406faf` (**144 B**); CC pad to `00406fc0` |
| Callers | ctor `004063a0` @ `004063fc`; Recreate `004195d0` @ `00419612` |
| Parallel clean | `CNDHash_AllocBucketTable_009cb348.cpp`, `SkillCNDHash_AllocBucketTable_Inferred.cpp` |
| Clean | `reconstructed-exact/CNDHash_AllocBucketTable_00a2c2e4.cpp` |

---

## 3. ABI (SEALED)

| Slot | Role | Evidence |
|------|------|----------|
| **ESI** | hash* | entry uses `[esi+0x1c]`; no `mov esi,ecx`; callers keep ESI |
| stack | none | bare `ret` |
| success return | void | no EAX produce |
| fail | noreturn throw | `_CxxThrowException` after log |

---

## 4. Control flow: clean ≡ live

| Stage | Match |
|---|---|
| Log2 gate 1..16 | **Yes** |
| `new[]` table N*4 @ `+0x10` | **Yes** |
| `malloc` slab N*0xc | **Yes** |
| Init sentinels `00a2c2e4` + zeros | **Yes** |
| `*(+8)--` mask post-condition | **Yes** |
| Fail: `VOG_DEBUG_STOP` + throw `0x80004003` | **Yes** |

### Post-condition on `hash+8`

After success: `*(hash+8) = (1 << log2) - 1` when caller seeded count as `1<<log2` — **High** (Recreate seeds then calls).

---

## 5. Confidence

| Claim | Confidence |
|---|---|
| Role = alloc bucket table / mask convert | **High** (CF + sole ctor/Recreate callers) |
| ESI custom ABI / bare ret | **High** |
| Sentinel stamp `00a2c2e4` | **High** (imm in bytes) |
| log2 domain 1..16 hard throw | **High** |
| Distinct from skill/inventory alloc VAs | **High** |
| Product English / RTTI for stamp | **Open** (stamp suffix, not soft `_Inferred` alone) |
| malloc/new null handling | **Open** (no checks — preserve) |
| Runtime / bit-exact | **Open** |

**Verdict:** **accept-with-gaps**
