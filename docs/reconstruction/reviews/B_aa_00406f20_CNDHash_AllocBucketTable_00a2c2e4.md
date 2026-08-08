# Review B (skeptical / adversarial): `aa_00406f20` CNDHash_AllocBucketTable_00a2c2e4

| Field | Value |
|---|---|
| **Stable ID** | `aa_00406f20` |
| **VA** | `0x00406f20` |
| **Canonical name** | `CNDHash_AllocBucketTable_00a2c2e4` |
| **Review date** | `2026-08-04` (WQ9G-J dual) |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_00406f20_CNDHash_AllocBucketTable_00a2c2e4.md` |
| **Live tools** | Independent `batch_decompile` + `read_memory` + caller `get_assembly_context` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Soft-fail / return error on bad log2 | **Falsified** — log + `_CxxThrowException` noreturn |
| 2 | log2 domain 0..15 or includes 0 | **Falsified** — rejects 0 and >16 |
| 3 | `+8` remains bucket **count** after return | **Falsified** — `add dword [esi+8], -1` → **mask** |
| 4 | Single allocation for table+slab | **Falsified** — `new[]` then `malloc` |
| 5 | Type-merge with skill `0x004cb410` / inventory `0x00413d80` | **Falsified** — different VA; stamp `00a2c2e4` |
| 6 | Thiscall ECX / stack arg / ret 4 | **Falsified** — ESI custom; bare ret |
| 7 | Tree insert / RB rebalance (partition neighborhood) | **Falsified** — pure hash bucket alloc CF |
| 8 | Product class English sealed | **Fails** — stamp suffix only |
| 9 | Runtime Confirmed / bit-exact | **Fails** — open; no Launcher |

---

## 2. Decisive machine dataflow

```text
// entry
// ESI = hash (caller-held)
AL = [ESI+0x1c]
if AL < 1 or AL > 0x10: VOG_DEBUG_STOP; throw 0x80004003
EAX = [ESI+8]                 // N
new[](N*4) → [ESI+0x10]
malloc(N*0xc) → slab
for i=0..N-1:
  table[i] = slab+i*0xc
  *sent = 0x00a2c2e4; sent+4=0; sent+8=0
[ESI+8] = N - 1
pop edi; pop ecx; ret
```

Caller Recreate (`00419612`) seeds before call:

```text
// after destroy:
[ESI+0x1c] = log2 (BL)
[ESI+8]    = 1 << log2
[ESI+0x18]=0; [ESI+0x14]=0
// ESI preserved
CALL 0x00406f20
```

Ctor path (`004063fc`) same after field zeros + provisional count.

A ≡ B on live decompile + gate/mask/stamp bytes.

---

## 3. Confidence (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Alloc CF + mask | **High** | Insert bucket wrong (`key & mask`) |
| log2 throw domain | **High** | Silent corrupt table |
| Stamp identity family | **High** (imm) | Cross-family type merge |
| ESI vs thiscall | **High** | Wrong port ABI |
| OOM path | **Open** | Crash vs undefined if null |
| Product English | **Open** | Naming only |

---

## 4. Surviving contract

```text
CNDHash_AllocBucketTable_00a2c2e4:
  ESI = hash*
  require log2@+0x1c in [1,16] else throw 0x80004003
  allocate table+slab; stamp 00a2c2e4; count→mask at +8
  bare ret
```

**Verdict:** **accept-with-gaps**
