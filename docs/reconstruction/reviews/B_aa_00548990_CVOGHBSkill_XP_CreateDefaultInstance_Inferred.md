# Review B (skeptical / adversarial): `aa_00548990` CVOGHBSkill_XP_CreateDefaultInstance_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00548990` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (R12-022; dual start 2646) |
| **Counterpart** | `reviews/A_aa_00548990_CVOGHBSkill_XP_CreateDefaultInstance_Inferred.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `disassemble_function` + `read_memory` + xrefs/callers. No `disassemble_bytes`. No Launcher.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Still anonymous / unknown class | **Falsified** — type_info **`.?AVCVOGHBSkill_XP@@`** via COL on vtbl `009d119c` |
| 2 | This **is** the full cast / Apply path | **Falsified** — no TFID loop, no Resolve, no SetPeriod, no Enqueue; base is **DefaultCtor `00578830`** not full ctor **`005788d0`** |
| 3 | Function is OnHeartBeat / tick | **Falsified** — pure alloc+ctor+vtbl; sibling roles live on other vtbl slots (e.g. +0x2C Apply) |
| 4 | In-place ctor on inbound `this` | **Falsified** — always `operator_new`; no ECX object on entry used as construct target |
| 5 | Size is 0x6d0 / 0x6e0 catalog variants | **Falsified** — sole size imm **`0x6c0`** |
| 6 | Multiple direct CALL sites | **Falsified** — callers empty; sole xref **DATA** vtbl+0x48 |
| 7 | Base is full `CVOGHBSkillBase_ctor` | **Falsified** — call target **`0x00578830`** DefaultCtor (dualed empty shell) |
| 8 | Always non-null / never checks new | **Falsified** — `CMP ESI,EAX` / `JZ` skip; returns null on OOM |
| 9 | Invented product method English is Confirmed | **Survives as Inferred only** — class Confirmed; CreateDefaultInstance role Inferred |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| RTTI class identity | **High / Confirmed** | Wrong skill-type port |
| Factory CF (new→default→vtbl) | **High** | Mis-merge with cast-start path |
| Distinct from ApplyToTargetList | **High** | Port applies period/Enqueue on empty shells |
| Method English | Medium | Naming only |
| Virtual this usage | Low / open | ABI when hooked from C++ vtbl dispatch |

---

## 3. Cross-check against raw + bytes

```
push -1 / push LAB_009a43fb / SEH
push 0x6c0
call operator_new          ; 00489892
mov esi, eax
jz skip
mov ecx, esi
call 00578830              ; CVOGHBSkillBase_DefaultCtor — NOT 005788d0
mov dword [esi], 009d119c  ; XP vtbl
mov eax, esi
skip:
restore FS:[0] / add esp,10 / ret
```

DATA @ `009d11e4`: `90 89 54 00` = **this VA**.

Clean must **not**:
- treat unit as ApplyToTargetList / OnHeartBeat,
- substitute full ctor `005788d0`,
- invent CALL-graph parents beyond vtbl DATA,
- claim Runtime Confirmed without Launcher.

---

## 4. Surviving contract for AutoCore

```csharp
// Client skill residual — XP default factory (vtbl+0x48)
CVOGHBSkill_XP CreateDefaultInstance() {
  var p = Alloc(0x6c0);          // operator_new
  if (p == null) return null;
  CVOGHBSkillBase_DefaultCtor(p); // empty shell; Attach(null)
  p.Vtbl = CVOGHBSkill_XP_Vtbl;   // 009d119c
  return p;
}
// Does NOT: resolve targets, set period -1000, Enqueue/Start
```

Server ports that need a bare XP HB shell can mirror this; cast/apply paths must continue to use the full ctor + arm sequence from `0061c590`.

---

## 5. Open questions

1. PDB method name for vtbl+0x48.
2. Who dispatches this slot (vtable call vs table of creators).
3. Null-`operator_new` path is retail-defined (returns null) — ports should preserve.
4. Runtime / bit-exact / differential.

**Verdict:** **accept**
