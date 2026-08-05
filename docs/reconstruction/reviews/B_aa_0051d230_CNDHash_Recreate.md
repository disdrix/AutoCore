# Review B (skeptical / adversarial): `aa_0051d230` CNDHash_Recreate

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051d230` |
| **VA** | `0x0051d230` |
| **Canonical name** | `CNDHash_Recreate` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0051d230_CNDHash_Recreate.md` |
| **System** | container / medal hash |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Is insert / lookup | Body only clear+alloc; no key/value args | **Falsified** insert role |
| 2 | Locked traversal aborts | Logs then falls through to clear | **Falsified** hard abort |
| 3 | `+0x08` remains `1<<bits` after return | `FUN_0051ba40` ends with `mask = N-1` | **Falsified** as permanent size — becomes mask |
| 4 | Rehashes existing entries | Clear frees all; no reinsert loop | **Falsified** preserve |
| 5 | Global-only / no `this` | `MOV ESI,ECX`; parent sets `ECX=0xb042e0` | **Falsified** static-only |
| 6 | `Named_VOG_DEBUG_STOP` is product id | String only on lock-warn path | **Falsified** identity from that string |
| 7 | Bits arg unrestricted | AllocBuckets throws if bits ∉ [1,16]; parent uses 4 | **Survives** with callee gate |
| 8 | Multiple static callers | Sole xref `00519689` | **Agree** |

---

## 2. Live ≡ raw

```
Live disasm 0x0051d230–0x0051d282 ≡ raw decompile:
  lock check → dual log
  call FUN_0051d150
  store bits; N=1<<bits; head=tail=0
  call FUN_0051ba40
  ret 4
```

Parent seal (`FUN_00519660`):

```
PUSH 4 / MOV ECX,0xb042e0 / CALL 0051d230
```

---

## 3. Surviving contract

```
// void __thiscall CNDHash_Recreate(hash*, byte log2Bits)
// Destroy contents + rebuild empty bucket table sized 1<<log2Bits (mask 2^n-1).
// Lock byte +0x1d: warn only.
```

**Verdict:** **accept-with-gaps.**
