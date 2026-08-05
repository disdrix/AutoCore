# Review B (skeptical / adversarial): `aa_0073d940` MatRegistry_FindCompatibleMaterial_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0073d940` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (OWN-ONLY W37-X) |
| **Counterpart** | `reviews/A_aa_0073d940_MatRegistry_FindCompatibleMaterial_Inferred.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Body **is** the material refcount swap | **Falsified** — no `+1`/`-1` on `+4`; no vfunc+4/+8; returns pointer only. Callers (e.g. `0099e84f`) do the swap |
| 2 | cdecl / no this | **Falsified** — ECX host; stack probe; **`RET 4`** |
| 3 | Stride is 0x10 / 4 dwords | **Falsified** — `ADD EAX,0x14`; decompile `piVar3 + 5` |
| 4 | Returns status code not pointer | **Falsified** — callers `TEST` then treat EAX as object (`ADD [EDI+4],1`) |
| 5 | Always finds something / always replaces | **Falsified** — many zero returns; callers null-check |
| 6 | Host is ECX = probe material | **Falsified** — call sites load `DAT_00d1f61c` into ECX, push material |
| 7 | Name claims product demangle | **Careful** — `_Inferred` structural only; no PDB |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX host + stack probe + RET 4 | **High** | Wrong ABI |
| Lookup-only semantics | **High** | Double free / missing ref if port invents swap here |
| Stride 0x14 + key at +8 | **High** | Wrong table walk |
| Compatible gate via `FUN_00752590` | **High** (call present) | Wrong alternate pick if predicate mis-ported |
| Product English | **Low** | Naming only |

---

## 3. Cross-check against raw + bytes + xrefs

- Full 108 B hex ends `8B C7 5F 5E 5D 5B C2 04 00`.
- Prologue: `PUSH EBX; PUSH EBP; MOV EBP,[ESP+0xC]` = stack arg after two pushes.
- 14 callers / 17 xrefs — all material/FX init family; consistent post-call swap pattern.
- Prior wave text that called this "refcount swap" is **caller-side misattribution** — corrected under W37-X ownership.

---

## 4. Surviving contract for AutoCore

```
// Port as pure lookup on global material registry:
Material* MatRegistry_FindCompatibleMaterial(MatRegistry* host /*ECX*/, Material* probe);
// host usually *DAT_00d1f61c
// if non-null: caller AddRef(found), Release(old), slot = found
// DO NOT implement refcount inside this function
```

---

## 5. Verdict

Adversarial pass confirms A: lookup-only, ECX+stack+RET4, 0x14 buckets, compatibility callee, caller-owned swap. Residual product English only → **accept**.
