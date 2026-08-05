# Review B (skeptical / adversarial): `aa_004646e0` PtrVecShell_InitFill_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004646e0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W33-B) |
| **Counterpart** | `reviews/A_aa_004646e0_PtrVecShell_InitFill_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Decompiler 2-arg signature is full ABI | **Falsified** — `RET 0xC`; `[ebp+0x10]` load into EDX for fill |
| 2 | count is byte length | **Falsified** — `lea ebx,[eax*4]`; fill loop steps dword count |
| 3 | Writes standard `std::vector` at shell+0 | **Partial** — writes begin/end/cap at **+4/+8/+0xc**; **+0 unwritten** (custom shell or pad) |
| 4 | Frees prior allocation | **Falsified** — pure init; no delete |
| 5 | Always allocates | **Falsified** — count==0 zeros only |
| 6 | Scaffold `Named_CalleeOf_*gfxDeviceIB*` is product | **Rejected** — parent-seed alias only |
| 7 | Fill ignores 3rd arg (decompiler `FUN_00436ef0(param_2)` only) | **Falsified** — callee uses EDX=`[ebp+0x10]` source; EAX dest |
| 8 | Name claims full `std::vector` ctor product | **Careful** — structural ptr-shell init/fill; `_Inferred` only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| stdcall 3-arg / RET 12 | **High** | Wrong CC in port (stack imbalance) |
| count*4 + fill *src | **High** | Wrong table size / contents |
| +4/+8/+0xc layout | **High** | Member misaligned vs bag +0x10 |
| shell+0 meaning | **Low** | Naming / offset only |
| Non-Ass caller product | **Open** | Over-fit Ass-only story |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + xrefs

```
// Ass bag ctor (00423cf0 @ 0x00423d2e):
//   push &local_fill   // sentinel*
//   push 9
//   push this+0x10
//   call FUN_004646e0  // RET 12 cleans 12 B
//
// FUN_004540b0: basic_string("vector<T> too long"); throw
// FUN_00436ef0: for (;ecx;--ecx) { if (eax) *eax=*edx; eax+=4; }
```

10 xrefs — not Ass-exclusive; three known bag twins use count **9**.

Live decompile ≡ scaffold CF for alloc path; **bytes win** on third formal and epilog.

---

## 4. Surviving contract for AutoCore

```
// Port as stdcall 3-arg (not cdecl 2-arg):
struct PtrVecShell { uint32_t unk0; void** begin; void** end; void** end_cap; };
void PtrVecShell_InitFill(PtrVecShell* s, uint32_t n, void** fill_src) {
  s->begin = s->end = s->end_cap = nullptr;
  if (!n) return;
  if (n > 0x3fffffff) throw_vector_too_long();
  void** p = (void**)operator_new(n * 4);
  s->begin = p; s->end_cap = p + n;
  for (uint32_t i = 0; i < n; ++i) p[i] = *fill_src;
  s->end = p + n;
}
// Pair with CircularSentinel_Alloc0x28; bag ctors use n=9.
```

---

## 5. Verdict

Adversarial pass confirms A on 3-arg ABI, layout, fill, and max-size path. Residual shell+0 product + non-Ass caller English + runtime → **accept-with-gaps**.
