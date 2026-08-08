# Review B (skeptical / adversarial): `aa_00416590` PtrVecShell0x14_DefaultCtor_ZeroSkip4_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00416590` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (WQ9I-J) |
| **Counterpart** | `reviews/A_aa_00416590_PtrVecShell0x14_DefaultCtor_ZeroSkip4_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` + `analyze_function_complete` + `read_memory` + callers/xrefs. **No** `disassemble_bytes`.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Decompiler shows full truth (no SEH) | **Partially true** — field zeros match; SEH frame **is** present in bytes (`LAB_009bcfab`) |
| 2 | This zeroes the entire 0x14 object | **Falsified** — **+4 never written** |
| 3 | ABI is cdecl / stack this | **Falsified** — callers `MOV ECX,imm` / eh_vector ECX this; plain `C3` |
| 4 | Element size is 0x10 or 0x18 | **Falsified** — eh_vector pack size **0x14**; BSS stride **0x14** |
| 5 | Mission/NDUI product name from scaffold | **Falsified** — multi-site util (audio array + BSS); reject auto alias |
| 6 | Same class as neighbor `004165f0` | **Falsified** — leaf shell ctor vs vtbl scalar dtor; unrelated CF |
| 7 | +8 is not an owning pointer triad | **Falsified** — peer dtor `00417ee0` deletes +8; static path walks begin→end |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX this / ret 0 / leaf | **High** | Wrong call-site ABI |
| Zero map (+0,+8,+0xC,+0x10 skip +4) | **High** | Uninit field port bug |
| Elem stride 0x14 | **High** | Array layout wrong |
| Ptr-vec triad at +8 | **High** | Wrong free/teardown |
| Product type / +0,+4 English | Medium | Naming only |
| Runtime | Open | — |

---

## 3. Cross-check against raw + bytes

```
push -1 / push LAB_009bcfab / install FS:[0]
mov eax, ecx
xor ecx, ecx
mov [eax], ecx        ; +0
mov [eax+8], ecx      ; +8
mov [eax+0xc], ecx    ; +0xC
mov [eax+0x10], ecx   ; +0x10
; no [eax+4]
restore FS:[0]; add esp,0x10; ret
```

Call sites set **ECX** only. Do **not** invent stores to +4. Do **not** merge with `004165f0`.

---

## 4. Surviving contract for AutoCore

```csharp
// void PtrVecShell0x14.DefaultCtor()
// ECX=this, ret 0
// zero +0,+8,+0xC,+0x10; leave +4
```

Shared util; pair peer dtor `00417ee0` when dualed. Port as **thiscall leaf**, not mission logic.

---

## 5. Verdict

**accept-with-gaps** — adversarial checks confirm partial-zero 0x14 shell default ctor with sealed ABI/size. Residual: product fields, +4 rationale, runtime. Not reject.
