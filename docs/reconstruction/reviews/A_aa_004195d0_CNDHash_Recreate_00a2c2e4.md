# Review A (reconstruction fidelity): `aa_004195d0` CNDHash_Recreate_00a2c2e4

| Field | Value |
|---|---|
| **Stable ID** | `aa_004195d0` |
| **VA** | `0x004195d0` |
| **Canonical name** | `CNDHash_Recreate_00a2c2e4` |
| **Prior alias** | `FUN_004195d0`, `Named_VOG_DEBUG_STOP_004195d0` |
| **Review date** | `2026-08-04` (OWN-ONLY dual A/B — WQ9H-E) |
| **Reviewer role** | Independent reconstruction review (Path A fidelity) |
| **Counterpart** | `reviews/B_aa_004195d0_CNDHash_Recreate_00a2c2e4.md` |
| **System** | container / CNDHash (stamp `00a2c2e4`) |
| **Live tools** | Ghidra `batch_decompile`, `analyze_function_complete`, `read_memory`, callers/xrefs, `get_assembly_context` |
| **Partition** | `WAVE_2026-08-04_wq009_depth5_partition_map.md` → **WQ9H-E** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Host-family **CNDHash recreate** (stamp **`00a2c2e4`** helpers):

```text
// custom EAX = hash*; BL = log2; bare ret
if lock@+0x1d: log HashError:Recreate + VOG_DEBUG_STOP; continue
CNDHash_DestroyBucketTable_00a2c2e4(hash)   // EAX
hash+0x1c = log2
hash+8    = 1 << (log2 & 0x1f)              // provisional COUNT
hash+0x18 = 0; hash+0x14 = 0
CNDHash_AllocBucketTable_00a2c2e4(hash)     // ESI; mask post-cond
```

**Not** skill thiscall recreate (`0x004cbdc0`). **Not** invent identity with inventory helpers (`0x004138d0` CF-peer, different destroy/alloc VAs).

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | `batch_decompile(0x004195d0)` ≡ 2026-07-23 raw |
| Entry / body bytes | `read_memory` — `56 8B F0` … bare `5E C3`; destroy `8B C6 E8…`; seed SHL |
| Body range | `0x004195d0`–`0x00419618` (**73 B**) |
| Strings | Recreate @ `0x00a64c48`; `VOG_DEBUG_STOP` @ `0x00a15844` |
| Callers | `FUN_007fe640` @ `0x007fe707` — `MOV BL,2` |
| Nested duals | WQ9G-J alloc/destroy stamp `00a2c2e4` |
| Clean | `reconstructed-exact/CNDHash_Recreate_00a2c2e4.cpp` |

---

## 3. ABI (SEALED)

| Slot | Role | Evidence |
|------|------|----------|
| **EAX** | hash* | entry `mov esi,eax` |
| **BL** | log2 | seed `mov [esi+0x1c],bl`; caller `mov bl,2` |
| stack | none | bare `ret` |
| return | void | no EAX produce |

---

## 4. Control flow: clean ≡ live

| Stage | Match |
|---|---|
| Lock log-only (continue) | **Yes** |
| Destroy via `00406fc0` | **Yes** |
| Store log2 + power-of-two count | **Yes** |
| Clear ordered head/tail | **Yes** |
| Alloc via `00406f20` | **Yes** |

### Post-condition on `hash+8`

After full Recreate with valid log2: `*(hash+8) = (1 << log2) - 1` via alloc mask convert — **High** (dualed alloc).

---

## 5. Confidence

| Claim | Confidence |
|---|---|
| Role = CNDHash recreate / rebucket | **High** (string + CF + sole caller after traverse) |
| EAX/BL custom ABI / bare ret | **High** |
| Stamp family via `00406f20`/`00406fc0` | **High** (nested duals) |
| Distinct from skill thiscall recreate | **High** |
| Product host class English | **Open** (stamp suffix) |
| Runtime / bit-exact | **Open** |

**Verdict:** **accept-with-gaps**
