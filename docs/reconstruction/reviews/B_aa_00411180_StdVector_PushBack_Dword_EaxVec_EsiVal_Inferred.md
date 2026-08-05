# Review B (skeptical / adversarial): `aa_00411180` StdVector_PushBack_Dword_EaxVec_EsiVal_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00411180` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` |
| **Counterpart** | `reviews/A_aa_00411180_StdVector_PushBack_Dword_EaxVec_EsiVal_Inferred.md` |
| **Dual status** | WQ7R-D present |
| **Verdict** | **accept-with-gaps** on pure push CF; **reject** mission-only / thiscall-identical claims |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | This is mission-fail / journal-only API | **Falsified** — 9 xrefs across unrelated parents (`008071c0`, `0092a440`, `00800d80`, …) |
| 2 | Same as `Vector_PushDword` @ `0x004149d0` | **Falsified** — that unit is **thiscall ECX** + stack value + `RET 4` + grow `FUN_0040dbf0`; this is **EAX/ESI** + bare `RET` + grow `FUN_0040b6d0` |
| 3 | Decompiler `void FUN_00411180(void)` is the ABI | **Falsified** — phantom `in_EAX` / `unaff_ESI`; bytes + call sites seal registers |
| 4 | Always grows | **Falsified** — fast path when `size < cap` |
| 5 | Element is always mission id | **Falsified** as universal claim — only site-dependent (journal uses mission ids) |
| 6 | Mutates mission state / dirty bits | **Falsified** — only triad + buffer store |
| 7 | Thread-safe | **Unfounded** — no locks |
| 8 | Clean invents mission logic | **Falsified** — clean is pure push |

---

## 2. Decisive dataflow (image-backed)

```
// EAX = vec; ESI = uint32_t* pValue
// triad: begin@+4, end@+8, cap@+0xc; stride 4

size = (begin == 0) ? 0 : (end - begin) >> 2
if (begin != 0 && size < ((cap - begin) >> 2)):
  *end = *pValue
  end += 4
  return                 // bare RET
else:
  FUN_0040b6d0(end, pValue)  // EDI=vec threaded via prior MOV
  return
```

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Vector push CF | **High** | Mis-documented container API |
| EAX/ESI ABI | **High** | Port uses wrong registers |
| Distinct from `004149d0` | **High** | Wrong grow/cleanup |
| Multi-caller generic | **High** | Mission-only over-specialization |
| `FUN_0040b6d0` product English | **Open** | Naming only (WQ7R-E) |
| Runtime | **Open** | Unobserved |

---

## 4. Offset / formula attack checklist

| Item | Attack | Result |
|------|--------|--------|
| begin at +0 | triad starts at 0? | **No** — `MOV EDX,[EDI+4]` |
| word/byte vector | stride? | **No** — all `SAR 2`; dword store |
| Stack arg present | `RET 4`? | **No** — bare `C3`; callers do not push value |
| Journal LEA destinations are body offsets | hardcode +0x728 in unit? | **No** — body receives vec in EAX only |

---

## Verdict

**accept-with-gaps** — pure register-ABI dword push sealed; reject mission-exclusive and thiscall-twin claims.
