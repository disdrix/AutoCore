# Review B (skeptical / adversarial): `aa_00520dc0` CVOGCharacter_CleanupDraggingObject

| Field | Value |
|---|---|
| **Stable ID** | `aa_00520dc0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY MEGA-001) |
| **Counterpart** | `reviews/A_aa_00520dc0_CVOGCharacter_CleanupDraggingObject.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Name is scaffold / `_Inferred` only | **Falsified** — plate `"CVOGCharacter::CleanupDraggingObject"` @ `0x009cf0b0` exact Class::Method |
| 2 | Decompiler `__fastcall` sole-ECX / no stack cleanup | **Falsified** — both exits `RET 4` (`C2 04 00`); stack dword present |
| 3 | `FUN_005714e0(drag,…)` item-as-this | **Falsified** — asm `MOV ECX, cargo/locker grid` before call; item is `PUSH ESI` |
| 4 | Both place paths use the same grid | **Falsified** — Path A `*(*(this+0x250)+0x2B0)`; Path B `[this+0xCBC]` |
| 5 | `FUN_004fabc0` / `00502e90` take drag as ECX | **Falsified** — ECX=`[EDI+0x250]` host; drag on stack |
| 6 | Returns `undefined4` / full EAX semantic | **Falsified** — `XOR AL,AL` / `MOV AL,1` only; bool |
| 7 | Clears `+0xCD0` even when drag was null | **Falsified** — early-out returns before clear |
| 8 | Always calls equip switch | **Falsified** — equip only if both place paths fail and status gate holds |
| 9 | This is vehicle paint / SetLocalVehicle (`+0xCD0` vehicle claim) | **Falsified for this unit** — plate CleanupDragging + place/equip item flow; field used as drag pointer here |
| 10 | Function is dead (0 xrefs ⇒ unused) | **Not sealed** — 0 Ghidra xrefs is a **gap**, not proof of dead code (indirect call residual) |
| 11 | `Named_CalleeOf_*` scaffold is product | **Falsified** — product plate present; retire scaffold naming |
| 12 | Place uses page≠-1 or allowStack=0 | **Falsified** — both sites `PUSH -1` / `PUSH 1` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ABI ECX-this / RET 4 / AL bool | **High** | Wrong call convention / stack imbalance |
| Plate product name | **High** | Naming only if string reused (it is not) |
| Cargo vs locker grid split | **High** | Wrong inventory target on port |
| FindFree/Place this=grid | **High** | Crash / wrong object ops |
| Host `+0x250` for equip | **High** | Equip on wrong object |
| Status-code English | **Low** | Wrong equip fallback policy |
| Direct callers | **Open** | Missing integration edges |
| Unread stack arg meaning | **Open** | Harmless if ignored by callee cleanup |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

Live 2026-08-05 decompile **shape-matches** 2026-07-23 raw (null early-out, dual FindFree/Place, equip fallback, clear, returns 0/1) but **mis-binds ECX** for callees.  
`disassemble_function` + `read_memory` seal:

- `8B F9` this→EDI  
- `8B B7 D0 0C 00 00` drag←`+0xCD0`  
- Path A: `8B 87 50 02 00 00` / `8B 80 B0 02 00 00` cargo  
- Path B: `8B 8F BC 0C 00 00` locker  
- Equip: `8B 8F 50 02 00 00` host  
- Clear: `89 9F D0 0C 00 00`  
- `C2 04 00` ×2  

Callee duals (`005714e0` thiscall grid + `ret 0x14`; `00571620` place; `004fabc0` try-equip `ret 8`) consistent with push counts at call sites.

---

## 4. Surviving contract for AutoCore

```text
// On drag cancel / cleanup:
if (!CVOGCharacter_CleanupDraggingObject(character)) {
  // no drag object was held
} else {
  // drag slot +0xCD0 is null; item was placed into cargo or locker,
  // or equip fallback ran under status gate
}
// ABI: thiscall, RET 4 (pass a dummy stack dword if calling from asm), AL bool
// Do NOT trust raw Ghidra decompile for FindFree/Place/TryEquip this-pointers.
```

---

## 5. Verdict

Adversarial attacks on decompiler this-binding, false vehicle-only `+0xCD0` reading for this method, always-equip, and scaffold naming **fail**. Residual: callers, stack-arg English, equip status English, runtime → **accept-with-gaps**. Terminal **false**.
