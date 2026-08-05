# Review B (skeptical / adversarial): `aa_0046c1b0` NestedHash0x10_FindIterator_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0046c1b0` |
| **VA** | `0x0046c1b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0046c1b0_NestedHash0x10_FindIterator_Inferred.md` |
| **Evidence** | Live decompile + full-body `read_memory` + 13 callers + sibling insert + NestedHash0x10 ctor |
| **Agent** | W36-B OWN-ONLY |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | `unaff_ESI` / `in_EAX` are decompiler junk | All map fields via ESI; out writes via EAX; callers set both | **Falsified junk** — sealed formals |
| 2 | Pure `__fastcall` with only ECX key | No stack args; bare RET; ESI+EAX live | **Register ABI** sealed (not MSVC thiscall plate) |
| 3 | Same as `HashMap_FindIterator` `0x0044e8c0` | No `FUN_0043b870`; different register map (ESI/ECX/EAX vs EDI/EBX/stack); bare RET vs RET4 | **Falsified conflation** |
| 4 | Unordered full-bucket scan | Greater-key path returns end without scanning rest | **Falsified unordered-only** |
| 5 | Equality is `strcmp` | Body compares dwords `*key` vs `node+8` only | **Falsified strcmp-in-body** |
| 6 | This inserts or creates on miss | Only writes end sentinel; no alloc | **Falsified insert** |
| 7 | Scaffold gfxDeviceIB name is product | Only nested callee of many maps including sto factory | **Rejected scaffold name** |
| 8 | Product name sealed | Role-inferred from CF + NestedHash0x10 family | **Accepted gap** (`_Inferred`) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Find CF + miss/hit writes | **Confirmed** | Wrong table lookup |
| ESI/ECX/EAX + bare RET | **Confirmed** | Caller contract break |
| Identity hash (no string leaf) | **Confirmed** | Wrong key prep |
| Offsets map/node | **Confirmed** | Layout ports |
| NestedHash0x10 family | **High** | Sibling insert node 0x10 + ctor W34-E |
| Product class name | **Open** | Doc-only |
| Runtime | **Open** | — |

---

## 3. Cross-check vs callers

- `FUN_004449b0` / `FUN_00444a40`: get NestedHash0x10 static via once-get, call find, compare vs `map+8`, then insert sibling on miss — **find-only** contract.
- `FUN_0046bf40`: find then insert-on-miss → return `node+0xc` (value) — operator[] shape.
- `FUN_0098fef0`: edge bag NestedHash0x10 (W35-F sealed).

Do **not** merge insert (`0x0046bf90`) into this dual.

---

## 4. Byte anchors

```text
0x0046c1b0: 8B 56 20          ; mask from [ESI+0x20]
            83 EC 08 57
            8B 39             ; key = *[ECX]
            8B CF 23 CA       ; idx = key & mask  (NO CALL)
            39 4E 24 77 0B    ; fold vs [ESI+0x24]
            8B 56 14 8D 14 8A ; table + idx*4
            8B 0A 3B 4A 04    ; start vs end
            39 79 08 …        ; node+8 vs key
            … 5F 83 C4 08 C3  ; bare RET ×3
```

---

## 5. What would reverse the seal?

- Proof a hash leaf is called (would reclassify as string-hash twin) — **no CALL in body**.
- Proof map/key on stack instead of ESI/ECX — contradicted by `MOV EDX,[ESI+0x20]` / `MOV EDI,[ECX]`.
- Proof this allocates — no `operator_new` / callees.

None observed.

**Verdict:** **accept**
