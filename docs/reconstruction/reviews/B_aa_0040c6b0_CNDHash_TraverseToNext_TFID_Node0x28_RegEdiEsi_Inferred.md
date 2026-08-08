# Review B (skeptical / adversarial): `aa_0040c6b0` CNDHash_TraverseToNext_TFID_Node0x28_RegEdiEsi_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040c6b0` |
| **VA** | `0x0040c6b0` |
| **Canonical name** | `CNDHash_TraverseToNext_TFID_Node0x28_RegEdiEsi_Inferred` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_0040c6b0_CNDHash_TraverseToNext_TFID_Node0x28_RegEdiEsi_Inferred.md` |
| **Live tools** | Independent `force_decompile` + callers/xrefs + `disassemble_function` + `read_memory` + parent call-site disasm + family contrast (`00411900`, `00411e40`) |
| **Work item** | MEGA-112 OWN-ONLY dual |
| **Verdict** | **accept-with-gaps** — accept A's CF/ABI; reject overclaims |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Unlocked traverse is fatal / aborts / throws | **Falsified** — dual log only; fall-through continues to walk |
| 2 | Returns the **node** pointer | **Falsified** — returns `*(node+0xc)` payload |
| 3 | Same list-next offset as dualed `CNDHash_TraverseToNext` `0x00411900` | **Falsified** — here **+0x20**; twin uses **+0x14** |
| 4 | Same payload offset as `00411900` | **Falsified** — here **+0xc**; twin uses **+8** |
| 5 | `__thiscall` / `RET 4` like `00411900` | **Falsified** — no `MOV ESI,ECX`; no stack arg; plain `c3` |
| 6 | Free function with stack args only | **Falsified** — register EDI/ESI ABI sealed by parent |
| 7 | Sets / clears traversal lock | **Falsified** — read-only lock check; parent clears +0x1d after loop |
| 8 | Method name is `VOG_DEBUG_STOP` | **Falsified** — secondary log tag; primary string is TraverseToNext |
| 9 | Broad multi-system helper | **Falsified for this VA** — only 2 xrefs, both in `Client_UpdateNpcInteractIcons` |
| 10 | Alias / merge with `FUN_00411e40` | **Falsified** — sibling reg-ABI but next+0x14 / value+8 |
| 11 | Product hash class name sealed | **Open** — accept `_Inferred`; do not invent stamp |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Iterate step under lock | **High** | Infinite loop / skip if next offset wrong |
| Payload at `node+0xc` (this family) | **High** | Wrong object id / crash on resolve |
| EDI=hash / ESI=cursor\*\* | **High** | Silent corruption if ported as thiscall |
| No membership mutation | **High** | Accidental remove ports |
| Node layout portability to 0x1c skill nodes | **None** — do not mix | Crash / corrupt |
| TFID\* as universal value_type for all CNDHash | **None** — consumer-local only | Wrong type at other hashes |
| Product English "CNDHash" | **High** (HashError strings) | — |

---

## 3. Caller challenge

| Caller | Must not claim |
|---|---|
| `Client_UpdateNpcInteractIcons` | That this VA **is** the full interact pipeline — it only walks `*[host+0xe8f4]` hash for TFID\* values |
| Parent uses of `00411900` / `00411e40` | That those share this node layout or this VA |
| `FUN_00411e10` TraversalLock | That lock lives inside TraverseToNext (it does not) |

---

## 4. CF challenge of Review A

- Dual force/non-force identity: **agree**
- Head `+0x14`, next `node+0x20`, value `node+0xc`: **agree**
- Lock log non-fatal: **agree**
- Register ABI EDI/ESI plain RET: **agree** (parent seal critical — decompiler alone under-specifies)
- Residual on product hash RTTI + `_Inferred`: **agree / reinforce**
- Body end inclusive `0040c6f0`: **agree** (second RET; pad CC to `0040c700`)

---

## 5. Surviving contract

```
value = CNDHash_TraverseToNext_TFID_Node0x28_RegEdiEsi(hash, &cursor):
  // retail: EDI=hash, ESI=&cursor, EAX=value, plain RET
  if !hash.lockedForTraversal: log HashError:TraverseToNext…; // continue
  if cursor==0: cursor = hash.listHead (+0x14)
  else:         cursor = cursor->listNext (+0x20)   // 0x28-node family
  return cursor ? cursor->value (+0xc) : 0          // TFID* at sole parent
```

**Verdict:** **accept-with-gaps.** Accept A. Reject thiscall-merge, 0x1c-node-merge, VOG_DEBUG_STOP-as-name, fatal-unlock, and universal-TFID overclaims.
