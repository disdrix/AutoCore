# Review B (skeptical / adversarial): `aa_00983940` AssResolverCore_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00983940` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W31-G) |
| **Counterpart** | `reviews/A_aa_00983940_AssResolverCore_Ctor_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | ECX-thiscall | **Falsified** — stack arg; `RET 4` |
| 2 | Installs outer resolver vtbl | **Falsified** — no store of `00aa1f1c` in body; parent does that at mem+0 |
| 3 | Decompiler DWORD write to DAT_00d1ef58 | **Falsified** — `66 89 3D` is **WORD** store |
| 4 | AssManager-only helper | **Falsified** — also `FUN_00985010` ×2 (effect probe path) |
| 5 | Same object as resolver A (00423be0) | **Falsified** — different size/layout; no vtbl here; global side-effects |
| 6 | Scalar-deleting dtor | **Falsified** — returns this; no free |
| 7 | Product PDB name sealed | **Careful** — `_Inferred` only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Placement ctor ABI | **High** | Wrong CC |
| Offsets +0x2c..+0x50 | **High** | CS misaligned |
| WORD global 00d1ef58 | **High** | Wrong store width if ported as DWORD |
| Nested FUN_00469db0 | **Med** | Member residual |
| Global product meaning | **Low** | Wrong subsystem label |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + xrefs

```
// AssManager B path @ ~0x007b77f0:
test esi, esi; jz null
mov [esi+4], 0
lea eax, [esi+8]
mov [esi], PTR_FUN_00aa1f1c
push eax; call FUN_00983940   // @ 0x007b780f
// FUN_00985010: FUN_00983940(stack_a); FUN_00984ee0(1); FUN_00983940(stack_b)
```

Nested `FUN_00469db0` decompile ≡ twin of `FUN_00423cf0` (both `FUN_00423d60` + `FUN_004646e0(...,9,...)`).

---

## 4. Surviving contract for AutoCore

```
// Port as placement ctor with global side-effects:
AssResolverCore* ctor(AssResolverCore* self) {
  NestedMember_Ctor(self);          // FUN_00469db0
  self->tri[0..2] = 0;              // +0x2c/+0x30/+0x34
  InitializeCriticalSection(self+0x38);
  *(u8*)(self+0x50) = 1;
  clear DAT_00d1ef44/48/50/5c (u32);
  *(u16*)DAT_00d1ef58 = 0;          // WORD — do not invent DWORD store
  return self;
}
// AssManager outer: new(0x5c); *p=vtbl_00aa1f1c; *(p+4)=0; ctor(p+8).
// Do not call this as ECX-thiscall. Do not claim PDB English.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/layout/globals/callers. Residual nested member + global product meaning → **accept-with-gaps**.
