# Review B (skeptical / adversarial): `aa_00411e40` CNDHash_TraverseToNext_RegEdiEsi

| Field | Value |
|---|---|
| **Stable ID** | `aa_00411e40` |
| **VA** | `0x00411e40` |
| **Canonical name** | `CNDHash_TraverseToNext_RegEdiEsi` |
| **Review date** | `2026-08-05` (MEGA-114 OWN dual) |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_00411e40_CNDHash_TraverseToNext_RegEdiEsi.md` |
| **Live tools** | Independent `force_decompile` + `disassemble_function` + `read_memory` + callers/xrefs + parent call-site bytes |
| **Verdict** | **accept-with-gaps** — accept A's CF/ABI; reject overclaims |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Unlocked traverse is fatal / aborts | **Falsified** — dual log only; fall-through continues (`JNZ` over logs only) |
| 2 | Returns the **node** pointer | **Falsified** — `MOV EAX,[EAX+8]` then `RET` |
| 3 | Same as thiscall twin `00411900` (merge VAs) | **Falsified** — distinct body; EDI/ESI vs ECX/stack; bare RET vs RET 4 |
| 4 | `__thiscall` / `mov esi,ecx` / `RET 4` | **Falsified** — no prologue; no stack arg load; bare `C3` |
| 5 | Sets / clears traversal lock | **Falsified** — read-only `CMP [EDI+0x1d]`; unlock is caller's job |
| 6 | Free function with stack `(hash, cursor*)` | **Falsified** — call sites load EDI/ESI, no pushes before `CALL` |
| 7 | Only `Client_UpdateNpcInteractIcons` consumer | **Falsified** — 11 CALL xrefs across ≥6 functions |
| 8 | Scaffold name `Named_VOG_DEBUG_STOP` is product role | **Falsified** — log string only; HashError seals TraverseToNext |
| 9 | Inventory-u64 node layout (+0x20 next) | **Falsified** — body uses **+0x14** next |
| 10 | Identical byte clone of `00411900` | **Falsified** — different prologue/epilogue; shared only CF/offsets/strings |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Iterate step under lock (log if not) | **High** | Infinite loop / skip if next offset wrong |
| Payload at `node+8` (this family) | **High** | Wrong interact/object handle |
| EDI=hash, ESI=cursor | **High** | Register clobber / wrong hash walked |
| No membership mutation | **High** | Accidental remove ports |
| Node layout portability to 0x28 inv nodes | **None** — do not mix | Crash / corrupt |
| Product English "CNDHash" | **High** (HashError strings) | — |
| Per-host payload struct English | **Low–Med** | Wrong field use at consumer |

---

## 3. Caller challenge

| Caller | Must not claim |
|---|---|
| `Client_UpdateNpcInteractIcons` | That this VA **is** the full interact system — it only steps `client+0x6f0` hash |
| `FUN_00411e10` (lock companion) | That lock/unlock live inside TraverseToNext — companion is separate VA |
| Unlabeled `0078a39e` / `0078a422` | Owning function English without further RE |
| Dualed twin `00411900` | That all TraverseToNext sites call **this** body (many use thiscall twin) |

---

## 4. CF challenge of Review A

- Dual force/non-force identity: **agree**
- Head `+0x14`, next `node+0x14`, value `node+8`: **agree**
- Lock log non-fatal: **agree**
- Register ABI EDI/ESI + bare RET: **agree** (A sealed via call sites + bytes)
- Residual on payload type / unlabeled sites: **add** (A already notes gaps)

---

## 5. Surviving contract

```
value = CNDHash_TraverseToNext_RegEdiEsi():   // EDI=hash, ESI=&cursor
  if !hash.lockedForTraversal: log HashError:TraverseToNext…; // continue
  if cursor==0: cursor = hash.listHead (+0x14)
  else:         cursor = cursor->listNext (+0x14)   // 0x1c-node family
  return cursor ? cursor->value (+8) : 0
  // bare RET
```

**Distinct from** thiscall twin:

```
value = CNDHash_TraverseToNext(hash /*ECX*/, &cursor /*stack*/); // RET 4
```

**Verdict:** **accept-with-gaps.** Accept A.
