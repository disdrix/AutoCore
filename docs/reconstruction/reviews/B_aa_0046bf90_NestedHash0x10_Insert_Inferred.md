# Review B (skeptical / adversarial): `aa_0046bf90` NestedHash0x10_Insert_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0046bf90` |
| **VA** | `0x0046bf90` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0046bf90_NestedHash0x10_Insert_Inferred.md` |
| **Evidence** | Live decompile + full-body `read_memory` 543 B + 4 callers + 3 callee decomps |
| **Agent** | W36-B OWN-ONLY |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | `unaff_EDI` is junk | All fields via EDI from prologue | **Falsified junk** — map formal |
| 2 | This is find-only | Calls `operator_new` via buynode; sets inserted=1 | **Falsified find-only** |
| 3 | ECX-thiscall map | Map in EDI; 2 stack args; RET 8 | **Falsified thiscall** |
| 4 | Node size ≠ 0x10 | `FUN_0046c2a0` → `operator_new(0x10)` | **Falsified** |
| 5 | Always inserts (no existing path) | Existing key path writes inserted=0 and RET 8 | **Falsified always-insert** |
| 6 | Unreachable block is live logic | Bytes show dead fallthrough after first RET 8 | **Sealed as artifact** |
| 7 | Same as string-key HashMap insert | Identity hash; NestedHash0x10 layout; no string leaf | **Falsified conflation** |
| 8 | Scaffold gfxDeviceIB name is product | Multi-caller NestedHash helper | **Rejected scaffold** |
| 9 | Product name sealed | Structural `_Inferred` only | **Accepted gap** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Insert-or-find role + pair out | **Confirmed** | Wrong factory insert |
| EDI + RET 8 ABI | **Confirmed** | Caller contract break |
| Node 0x10 key/value | **Confirmed** | Wrong element size |
| Load/rehash presence | **Confirmed** | Capacity bugs |
| Full redistribute bit-exact in clean | **Medium** | Doc residual — raw is authority |
| Product name | **Open** | Doc-only |
| Runtime | **Open** | — |

---

## 3. Cross-check vs callers

- `FUN_004449b0` / `FUN_00444a40`: after find miss, push kv with tag key + 0 value, call insert, then store creator at `node+0xc` — matches pair-out + value slot.
- `FUN_0046bf40`: operator[] — find then insert default pair, return `node+0xc`.
- `FUN_0098fef0`: edge refcount bag (W35-F).

Sibling find `0x0046c1b0` must stay separate (no rehash/alloc).

---

## 4. Byte anchors

```text
0x0046bf90: 51 8B 47 0C 8B 57 24   ; [EDI+0xc] size; [EDI+0x24] maxidx
            C1 E8 02 3B D0 …       ; size>>2 vs maxidx load gate
            … E8 …                 ; FUN_0044a380 rehash path
            … E8 63 01 00 00       ; FUN_0046c2a0 buynode
            B9 01 00 00 00
            8D 57 04 … E8 …        ; FUN_0046c230(1, EDI+4)
            C6 40 04 01 … C2 08 00 ; inserted=1 RET8
            C6 40 04 00 … C2 08 00 ; inserted=0 RET8
```

---

## 5. What would reverse the seal?

- Proof map is ECX-thiscall with different cleanup — contradicted by EDI uses + `C2 08 00`.
- Proof node size ≠ 0x10 — contradicted by buynode `operator_new(0x10)`.
- Proof no rehash path — contradicted by load gate + `FUN_0044a380` call site.

None observed.

**Verdict:** **accept**
