# Review B (skeptical / adversarial): `aa_0044a380` StdVector_DwordResize_EaxCount_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0044a380` |
| **VA** | `0x0044a380` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` |
| **Counterpart** | `reviews/A_aa_0044a380_StdVector_DwordResize_EaxCount_Inferred.md` |
| **Evidence** | Live decompile + full-body `read_memory` 105 B + 13 xrefs + callee decomps + NestedHash call site |
| **Agent** | W37-Z OWN-ONLY |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Decompiler `__fastcall (int)` is complete ABI | Bytes: `MOV ESI,EAX`; `C2 04 00` | **Falsified complete** — EAX=n + fill + RET4 |
| 2 | Same as `FUN_004367f0` | Twin uses stack n + `RET 8`; different grow/shrink callees | **Falsified merge** |
| 3 | Element size ≠ 4 | `SAR 2` / `LEA [reg+reg*4]` throughout | **Falsified** |
| 4 | Only NestedHash uses this | 12 callers across hash-map family | **Falsified sole-use** (still NestedHash-critical) |
| 5 | Grow path is pure alloc without fill | InsertN gets `&fill` from stack | **Falsified no-fill** |
| 6 | Shrink destroys non-POD | Shrink is pointer/dword memmove publish (`FUN_00469f10`) | **Sealed POD dword** |
| 7 | Scaffold effVertexDecl name is product | Multi-domain container helper | **Rejected scaffold** |
| 8 | Product name sealed | Structural `_Inferred` only | **Accepted gap** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Resize role + dword stride | **Confirmed** | Wrong container port |
| ECX + EAX + fill + RET 4 | **Confirmed** | Caller contract break |
| Grow/shrink split | **Confirmed** | Capacity bugs |
| Distinction from `004367f0` | **Confirmed** | Wrong RET / arg count |
| Product name | **Open** | Doc-only |
| Runtime | **Open** | — |

---

## 3. Cross-check vs callers

NestedHash insert rehash (`0x0046bfe3`):

```text
; ECX = bucket vec (begin@+4)
; compute new mask → [map+0x20]
PUSH fill          ; often map end-sentinel @map+8
ADD EAX, 2         ; newCount = mask+2
CALL FUN_0044a380
```

Matches EAX-count + one stack fill. Other hash-map insert twins (`0044e650`, `004638c0`, …) same pattern.

---

## 4. Byte anchors

```text
0x0044a380: 56 8B F0 8B 41 04 …   ; ESI=n; begin
            3B D6 73 26 …         ; size < n → grow
            … C2 04 00            ; RET 4 grow
            85 C0 74 20 …         ; begin null → done
            3B F2 73 12 …         ; n >= size → done
            8B D9 E8 … C2 04 00   ; EBX=this; shrink; RET 4
```

---

## 5. What would reverse the seal?

- Proof newCount is a stack formal and EAX is scratch — contradicted by `MOV ESI,EAX` before any stack load of count, and callers setting EAX then `PUSH fill` only.
- Proof `RET 8` — contradicted by two `C2 04 00`.
- Proof non-dword element — contradicted by `>>2` / `*4`.

None observed.

**Verdict:** **accept**
