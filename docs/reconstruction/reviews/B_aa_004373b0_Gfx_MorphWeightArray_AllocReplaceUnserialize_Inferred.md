# Review B (skeptical / adversarial): `aa_004373b0` Gfx_MorphWeightArray_AllocReplaceUnserialize_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004373b0` |
| **VA** | `0x004373b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` |
| **Counterpart** | `reviews/A_aa_004373b0_Gfx_MorphWeightArray_AllocReplaceUnserialize_Inferred.md` |
| **Evidence** | Live decompile + full-body `read_memory` 105 B + 5 xrefs + unserialize decomp + vtbl |
| **Agent** | W38-E OWN-ONLY |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Decompiler `void (void)` is complete | `C2 04 00`; callers push reader; EBX host+4 | **Falsified complete** |
| 2 | Slot is `*EBX` (like phy EDI) | All ops use `[EBX+4]` | **Falsified *EBX** |
| 3 | Same OOM policy as `004372a0` | Always stores ESI (may be 0) and calls unserialize | **Falsified shared OOM** |
| 4 | Return void / ignore EAX | Callers `OR EDI/ESI,EAX` | **Falsified void** |
| 5 | Product is physics CPDG | Callee gfxMorphWeightArrayImpl.cpp / MWGT | **Rejected phy merge** |
| 6 | Size ≠ 0x1c | `PUSH 0x1C` | **Falsified** |
| 7 | SEH present like phy twin | No FS:0 frame in body | **Sealed no-SEH** |
| 8 | Product method name sealed | No plate on VA | **Accepted gap** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Alloc-replace-unserialize role | **Confirmed** | Wrong morph load port |
| EBX host+4 + stack reader + RET 4 | **Confirmed** | Caller contract break |
| Replace-null-on-OOM | **Confirmed** | Null-deref vs leak tradeoff wrong |
| MWGT / morph weight class | **Confirmed** | Wrong domain |
| Host stride-8 English type | **Open** | Doc-only |
| Runtime | **Open** | — |

---

## 3. Cross-check vs callers

gfxBody loop (`0x00765b31`):

```text
; EBX = node in [begin, end) range from ESI+0x12c / +0x130
PUSH EBP
CALL 0x004373b0
ADD EBX, 8
CMP EBX, ESI
JNZ loop
```

Host-local (`0x00739d6d`): `LEA EBX,[EBP+0xc0]; PUSH ESI; CALL` then `OR EDI,EAX`.

Stack host (`0x0095f678`): `LEA EBX,[ESP+0x20]; PUSH EBP; CALL`.

---

## 4. Byte anchors

```text
0x004373b0: 56 57 6A 1C E8 … C7 00 48 2F AA 00
            83 46 04 01 … FF 50 04
            8B 4B 04 … FF 52 08
            8B 4C 24 0C 50 89 73 04 E8 … C2 04 00
```

---

## 5. What would reverse the seal?

- Proof host slot is at `*EBX` — contradicted by every load/store at `[EBX+4]`.
- Proof OOM preserves old pointer — contradicted by unconditional `MOV [EBX+4],ESI` after release.
- Proof void return — contradicted by `OR reg,EAX` at every profiled site.

None observed.
