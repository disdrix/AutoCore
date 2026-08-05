# Review B (skeptical / adversarial): `aa_007a26c0` Palantir_ExtendedHost_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_007a26c0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (W37-R) |
| **Counterpart** | `reviews/A_aa_007a26c0_Palantir_ExtendedHost_Ctor_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` on **own VA** (+ base-ctor context W35-I). No ledger edits. No `disassemble_bytes`.

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | ECX-thiscall ctor | Prologue loads self from `[esp+0x18]`; `RET 4` | **Falsified** — stack self |
| 2 | Is the whole Client WinMain | Only placement init; callers allocate elsewhere | **Over-narrow** — ctor only |
| 3 | Replaces base ctor entirely | Always calls `FUN_007543b0` first | **Falsified** — extends base |
| 4 | Same singleton as base (`DAT_00d1f058`) | Bytes store `DAT_00d17958` | **Falsified** — distinct global |
| 5 | Keeps base vtbl | `MOV [ESI], PTR_FUN_00a97170` after base | **Falsified** — overwrites |
| 6 | Scaffold Client_InitInstance product role | No plate strings; role = extended host ctor | **Over-narrow** — reject scaffold |
| 7 | `operator_new` failure still links list | Null path zeros EAX; stores null then writes through | **Risk** — null deref if new fails (retail may assume success); seal documents bytes as-is |
| 8 | Ghidra body size is exact | End `007a297c` drops final `00` of `RET 4` | **Clarify** — exclusive end `007a297D` / **701 B** |
| 9 | Decompiler void signature | Returns self in EAX | **Clarify** — return self |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Stack-self + RET 4 + EAX=self | **High** | Ports use thiscall → stack smash |
| Base then derived vtbl | **High** | Missing base → uninit COM/cache |
| `DAT_00d17958` publish | **High** | Profiler/host consumers null |
| 800×600 defaults | **High** | Doc only if display path overrides later |
| Nested callee product types | **Low** | Wrong subobject layout if invented |
| Derived class product name | **None claimed** | Naming only |

---

## 3. Cross-check against raw / bytes

```
raw decompile:
  base_ctor(self)
  *self = PTR_FUN_00a97170
  FUN_00424bf0()
  stamp fields…
  DAT_00d17958 = self
  new(0xA8) list head
  return self

bytes:
  MOV ESI,[esp+18]; PUSH ESI; CALL 007543b0
  MOV [ESI], 00a97170
  LEA EAX,[ESI+0xD8]; CALL 00424bf0
  MOV [00d17958], ESI
  … RET 4
```

Clean must **not** invent:

- Win32 window creation (callers / other units)
- ECX thiscall
- Skipping `Palantir_BaseCtor`
- Writing `DAT_00d1f058` instead of `DAT_00d17958`

---

## 4. Surviving contract for AutoCore

```csharp
// Behavior-exact port of 0x007a26c0
// self on stack (stdcall-like RET 4); returns self
static unsafe Host* Palantir_ExtendedHost_Ctor(Host* self)
{
    Palantir_BaseCtor(self);           // FUN_007543b0
    self->vtbl = DerivedHostVtbl;      // PTR_FUN_00a97170
    InitSubobjectAt_D8(self + 0xD8);   // FUN_00424bf0
    // stamp defaults: 800x600, flags, floats 1/0.1/64/15/0.01 …
    self->slot_2D4 = FUN_004933f0();
    g_Host_d17958 = self;
    var node = AllocListNode_A8();
    self->list_2DC = node;
    // zero aux dwords +0x13C..
    return self;
}
```

---

## 5. Verdict

**accept-with-gaps** — adversarial pass does not break sealed ABI/CF/singleton; product demangle and nested types remain open.
