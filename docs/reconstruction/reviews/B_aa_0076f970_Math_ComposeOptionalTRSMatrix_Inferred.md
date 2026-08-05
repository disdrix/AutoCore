# Review B (skeptical / adversarial): `aa_0076f970` Math_ComposeOptionalTRSMatrix_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0076f970` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0076f970_Math_ComposeOptionalTRSMatrix_Inferred.md` |
| **Verdict** | **accept-with-gaps** on CF/ABI; product English **Probable** only |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Ghidra `__thiscall` means C++ method on dest | ECX is optional T_B; dest is stack `[ebp+8]`; return reloads dest | **Falsified** as method-on-dest |
| 2 | GfxNode decompile `FUN_0076f970(node,&local,…)` this=node | Caller sets **ECX=0x00D1A6C0**, pushes node as stack dest | **Falsified** (sibling B already) |
| 3 | Local `(0,0,0,1)` is the dest matrix | Only 16 bytes; composer writes 64 to dest formal | **Falsified** — local is **outer quat** |
| 4 | `+0x9C` is quaternion | Consumed as **3-float scale** diagonal | **Falsified** old tentative |
| 5 | `+0x80` is scale | Consumed via `FUN_0076eb00` → **quat** | **Falsified** old tentative |
| 6 | Always full 9-stage sandwich | Null pointer slots skip stages | **Falsified** as always-full |
| 7 | T_A/T_B always identity | Only when pointed memory is zero; other callers may pass real vectors | **Partial** — GfxNode sealed zeros; general path open |
| 8 | Product name sealed | No PDB/RTTI on unit | **Agree open** |
| 9 | Bit-exact port ready without mul helper dual | `00412d80` has aligned/unaligned paths | **Open residual** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| cdecl 5 stack args + ret dest | **Confirmed** | ABI break |
| Stage order when all non-null | **Confirmed** | Wrong world matrices |
| GfxNode field → formal map | **Confirmed** | Wire scale/quat swapped |
| S·R·T reduction under zero T / I quat | **Confirmed** | |
| Outer R + Rinv pairing | **Confirmed** | Nested transform wrong if inverted order |
| English product name | **Medium** | Docs only |
| All 4 callers use node+0 dest | **Medium** | One site may pass other buffer |
| Numerical identity of eb00/e6b0 | **High structural / Open numeric** | |

---

## 3. Cross-check against raw / callers / bytes

```text
// GfxNode push order (00972e50):
//   +0x90, +0x80, +0x9C, &localI, node
//   ECX=EAX=0x00D1A6C0
// maps to: T, R_inner, scale, R_outer, dest

// decompile mul tail (order):
//   tB, rInner, -tB, tA, rOuter, scale, rOuterInv, -tA
```

Identity `DAT_00afdf70`: `3f800000` on diagonal dwords 0,5,10,15.

Global `0x00D1A6C0` image zeros → T builders write zero translation.

Sibling dual `aa_00972e50` already warned dest mapping is **callee-owned** — this dual seals dest = first stack formal = **node** for that path.

---

## 4. Surviving contract for AutoCore

```
Math_ComposeOptionalTRSMatrix (cdecl-ish registers+stack):
  in  EAX = float3* tA or null-ish non-null global zeros
  in  ECX = float3* tB (same)
  stk dest, rOuter, scale, rInner, translation
  out EAX = dest

GfxNode rebuild:
  M = S(+0x9C) * R(+0x80) * T(+0x90)  → store at node+0
  then flags@+0xBC &= ~1   // in caller 00972e50, not here
```

**Port tests:**

* All optional null except dest → dest becomes I (if translation null).
* Only translation → dest = T.
* GfxNode triple → S*R*T vs naive T*R*S must fail (order sealed).
* Identity outer quat + zero T_A/T_B must not change S*R*T.

---

## 5. Residual after dual

| Item | Status |
|------|--------|
| Stage CF / GfxNode map | **Sealed Confirmed** |
| Product name | Open |
| Non-zero T_A/T_B caller audit | Open |
| Runtime samples | Open |
| `00412d80` bit-exact | Open (separate) |

**Verdict:** **accept-with-gaps** — adversarial checks kill thiscall-on-node and field mislabels; do not port as T*R*S without re-checking mul side.
