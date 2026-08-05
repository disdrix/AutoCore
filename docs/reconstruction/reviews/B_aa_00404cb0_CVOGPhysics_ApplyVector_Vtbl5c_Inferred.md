# Review B (skeptical / adversarial): `aa_00404cb0` CVOGPhysics_ApplyVector_Vtbl5c_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00404cb0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00404cb0_CVOGPhysics_ApplyVector_Vtbl5c_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | This **is** `ApplyImpulseVector` (same unit) | Compare final CALL imm | **Falsified as identity** — slot **`+0x5c`** vs sibling **`+0x50`**; otherwise twin |
| 2 | Body applies **angular** impulse | Callers build world-axis float vectors including pure **+Y 550**; upright notes use **`+0x64`** for ang impulse | **Not sealed** — could still be ang; **must not claim angular** without implementer dual |
| 3 | Body applies **linear impulse** (product) | Sibling plate already hedges “impulse vs setLinearVel” for `+0x50` | **Overclaim if sealed** — only dispatch proven |
| 4 | `__stdcall` / `__cdecl` | Epilogue `RET 4` + ECX this | **Falsified** — **`__thiscall`** |
| 5 | Null-safe on body | No TEST before `MOV EDX,[ECX]` / vcall | **Falsified if claimed safe** — null body faults |
| 6 | `FUN_005070b0` returns a global flag pointer | Bytes: writes `*out`, returns `out` in EAX | **Clarify** — out-param; decompiler presentation misleading |
| 7 | Always calls prepare `FUN_005070d0` | Gate: flag byte **and** `this+0x44 != 0` | **Falsified** — prepare is conditional |
| 8 | Skips vfunc when not ready | Fall-through always reaches `CALL [EDX+0x5c]` | **Falsified** — prepare is optional; apply is **unconditional** after gate |
| 9 | DriveControlTick owns this unit’s meaning | Parent only supplies vec + phys this | **Clarify** — OWN body is generic forwarder; parent brake-edge is consumer context only |
| 10 | Stack arg is float / scalar | Callers LEA a **16-byte** stack block; body passes pointer through | **Falsified as scalar** — **pointer** to vector block |
| 11 | Incomplete decompiler (missed stores) | 50 B body matches decompile stages | **No missed store** in this unit |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Unconditional vtbl+0x5c after optional prepare | **High** | Dropped or double-applied motion |
| Twin of `0x0040d260` except slot | **High** | Wrong sibling merge in ports |
| `__thiscall` + one pointer arg | **High** | ABI breakage |
| Product English of +0x5c | **Low–Med** | Wrong physics integration (impulse vs force vs set) |
| Ready-flag field `host+0x29` meaning | **Low** | Wrong activate/dirty semantics |
| Vec float3 vs float4 payload width consumed by implementer | **Open** | Stack smash / ignored W if wrong |

---

## 3. Cross-check against raw / bytes

```
raw / live decompile:
  probe FUN_005070b0 → if (!flag && this+0x44) FUN_005070d0
  (*(*(*(this+0x3c))+0x5c))(param_2)

bytes:
  CALL 005070b0
  CMP [EAX],0 / JNZ apply
  CMP [ESI+0x44],0 / JZ apply
  CALL 005070d0
apply:
  MOV ECX,[ESI+0x3c]; MOV EDX,[ECX]; PUSH pVec; CALL [EDX+0x5c]
  RET 4
```

Sibling `0x0040d260`: identical except `CALL [EDX+0x50]`.

Clean scaffold must **not**:

- invent clamps/math on the vector
- skip the vcall when “not ready”
- rename this unit as `ApplyImpulseVector` without the slot distinction
- claim angular vs linear product identity without implementer evidence

---

## 4. Surviving contract for AutoCore

```csharp
// Behavior-exact twin of ApplyImpulseVector with body vtbl slot 0x5c
void CVOGPhysics_ApplyVector_Vtbl5c(CVOGPhysics phys, ref /*or ptr*/ Vector4like v)
{
    // retail: out-byte on stack (high byte of a this copy); helper writes flag
    byte readyFlag;
    ReadyProbe(phys, out readyFlag);          // FUN_005070b0
    if (readyFlag == 0 && phys.hostAt44 != null)
        ReadyPrepare(phys);                   // FUN_005070d0

    var body = phys.bodyAt3c;                 // unchecked null
    // thiscall: ECX = body, stack = &v
    body.VtblSlot_0x5c(ref v);                // NOT slot 0x50
}
```

**Port traps to reject:**

- Merging with `ApplyImpulseVector` into one function with a slot parameter **unless** both call sites are re-verified (retail ships two separate leaves).
- Treating decompiler `char *pcVar1 = FUN_005070b0(...)` as returning a process-wide flag address.
- Adding null guards that change fault behavior if matching retail.
- Assuming DriveControlTick’s `(0, 550, 0)` is the only producer (three other call sites).

---

## 5. Residual gaps (do not block seal)

1. Implementer of body vtbl `+0x5c` (Havok method / wrapper).
2. Ready-flag / prepare English (`+0x29`, `FUN_0055e490`, `FUN_0055eb80`).
3. Parent function for xref `0x0095846c`.
4. Runtime / differential / bit-exact.

---

## Verdict

**accept-with-gaps** — adversarial review cannot break the twin-forwarder CF or the **`+0x5c` vs `+0x50`** split. Main overclaim risk is inventing product physics for the virtual slot; main decompiler trap is the `FUN_005070b0` return presentation.
