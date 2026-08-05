# Review B (skeptical / adversarial): `aa_0044b440` Xform_SetScaleXYZ_DetectUniform_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0044b440` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (W37-R) |
| **Counterpart** | `reviews/A_aa_0044b440_Xform_SetScaleXYZ_DetectUniform_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` on **own VA** (+ caller context). No ledger edits. No `disassemble_bytes`.

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | cdecl / 4 stack args including this | ECX this; `RET 0x0C` | **Falsified** — thiscall |
| 2 | Always bumps revision | Equality early-out skips all stores | **Falsified** — no-op on exact match |
| 3 | Uniform flag means “equal to 1.0” | Flag from pairwise |x−y|, |x−z| ≤ eps | **Falsified** — isotropic among components |
| 4 | eps is 0.0 / integer compare | `DAT_00aaa620` float ~1e-5 | **Falsified** |
| 5 | Is a full matrix multiply | Only three floats + flags | **Over-narrow** — scale write helper |
| 6 | Scaffold Drive_NDRiver product role | Callers are env-reflect / xform paths | **Over-narrow** — reject scaffold |
| 7 | Name “Scale” is product plate | No RTTI/string; inferred from offsets + caller stamps | **Clarify** — **Inferred**; CF sealed regardless of English |
| 8 | Decompiler void return wrong | Leaf void; no EAX result used | **OK** — void is correct |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall + 3 floats + RET 0x0C | **High** | Wrong cleanup / args |
| Offsets 0x9C/A0/A4/B4/B8/BC | **High** | Corrupt neighbor fields |
| Change-detect before write | **High** | Spurious dirties |
| Uniform test uses x as reference | **High** | Port comparing y−z only |
| “Scale” English | **Medium** | Doc naming only |
| Product class name | **None claimed** | — |

---

## 3. Cross-check against raw / bytes

```
raw:
  if any of x,y,z differ from stored:
    store triple; +0xBC = -1
    if |x-y|<=eps && |x-z|<=eps: +0xB8=0; +0xB4++; else +0xB4++; +0xB8=1

bytes:
  UCOMISS chain → early RET 0x0C
  stores; MOV dword [ECX+0xBC], -1
  FPU fabs compares vs [00aaa620]
  two paths both RET 0x0C
```

Caller `CVOGEnvironmentReflect_ctor`: `(1, −1, 1)` → non-uniform (`|1−(−1)|=2 > eps`) → `+0xB8=1`. Consistent with reflection flip scale, not isotropic.

Clean must **not** invent:

- Matrix multiply / quaternion ops
- Always-dirty without equality check
- Stack this pointer
- Hard-coded eps other than `DAT_00aaa620`

---

## 4. Surviving contract for AutoCore

```csharp
// Behavior-exact port of 0x0044b440
static void Xform_SetScaleXYZ_DetectUniform(XformSub* self, float x, float y, float z)
{
    if (x == self->sx && y == self->sy && z == self->sz) return;
    self->sx = x; self->sy = y; self->sz = z;
    self->cacheToken = unchecked((int)0xFFFFFFFF);
    const float eps = 1e-5f; // DAT_00aaa620
    if (MathF.Abs(x - y) <= eps && MathF.Abs(x - z) <= eps)
    {
        self->nonUniform = 0;
        self->revision++;
        return;
    }
    self->revision++;
    self->nonUniform = 1;
}
```

---

## 5. Verdict

**accept-with-gaps** — adversarial pass confirms leaf contract; only product English / consumer wiring remain open.
