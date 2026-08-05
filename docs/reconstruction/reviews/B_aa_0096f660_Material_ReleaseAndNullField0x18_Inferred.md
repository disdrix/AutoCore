# Review B (skeptical / adversarial): `aa_0096f660` Material_ReleaseAndNullField0x18_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0096f660` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W26-M) |
| **Counterpart** | `reviews/A_aa_0096f660_Material_ReleaseAndNullField0x18_Inferred.md` |
| **Scratch** | `tmp/a_0096f660.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This **sets** material colors | **Falsified** — no Mat* strings; only release/null; callers set colors first |
| 2 | ECX is the resource itself | **Falsified** — `MOV ESI,[ECX]` then `[ESI+0x18]` |
| 3 | Refcount is at resource+0 | **Falsified** — `ADD dword [ECX+4], -1` after ECX=resource |
| 4 | Always calls destructor | **Falsified** — only when refcount hits 0 (`75 05` skip) |
| 5 | Leaves dangling `+0x18` | **Falsified** — `MOV dword [ESI+0x18], 0` always after object path |
| 6 | cdecl / stack formals | **Falsified** — plain `RET`, ECX-only |
| 7 | Leaf with zero side effects | **Partial** — no FUN_* but **indirect** vtbl[+8]; classification “near-leaf” |
| 8 | Product name retail | **Overstated** — `_Inferred`; CF sealed regardless |
| 9 | Live ≠ raw | **Falsified** — identical 34 B body |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| 34 B hex / CF | **High** | Wrong release timing |
| Holder / +0x18 / refcount+4 | **High** | Leak or double-free port |
| vtbl[+8] on zero only | **High** | Premature destroy |
| Callers only paint paths (2) | **High** | Missed use-sites (xrefs sealed) |
| Product type English | **Medium** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  obj=*holder; if !obj ret
  res=obj+0x18; if res: --ref; if 0: vtbl+8()
  obj+0x18=0

bytes:
  56 8B 31 85 F6 74 19 8B 4E 18 85 C9 74 0B
  83 41 04 FF 75 05 8B 01 FF 50 08
  C7 46 18 00 00 00 00 5E C3
```

**No conflict.**

---

## 4. Surviving contract for AutoCore

```
// After writing MatAmbient/Diffuse/Emissive (or equivalent material constants):
Material_ReleaseAndNullField0x18_Inferred(holder);
// Must: null field +0x18; only destroy when refcount hits 0.
// Do not skip — callers always invoke after Mat* trio when material present.
```

---

## 5. Verdict

Adversarial pass **confirms** A: CF/ABI/hex sealed; product English residual only → **accept**.
